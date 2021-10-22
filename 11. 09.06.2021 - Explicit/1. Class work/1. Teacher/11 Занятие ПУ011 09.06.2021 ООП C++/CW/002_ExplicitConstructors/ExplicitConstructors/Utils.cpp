#include "pch.h"
#include "Utils.h"
#include "Colors.h"

// ����� ������� - ���������� ��� ���������� �������� 
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// ���������� ���������� � ������, ��������� ��������� ���� �������
void Init(const wchar_t *title)
{
	// ����� ��������� �������
	SetConsoleTitle(title);

	// ��������� ������� ������� ��� ������, �����
	SetConsoleOutputCP(CODE_PAGE);
	SetConsoleCP(CODE_PAGE);

	// ��������� ���������� ��������� �����
	srand(GetTickCount());

	// ��������� ������� ������ ��� ������������ �����
	cout << fixed << setprecision(5);

	// ��������� ����� �������
	SetColor(GRAY_ON_LTBLACK);
	system(CLEAR);
} // Init

// ��������� ���� ������� �������
int GetKey(const char *prompt)
{
	cout << prompt;

	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

    return key;
} // GetKey

// ��������� ���������� �����
int GetRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // GetRand

// ����������� ���������� ��������� ����� ���, ����� ���
// ��������� �����, �������� 0.9 �� ������ ����������� 0
double GetRand(double low, double high)
{
	double value = low + (high - low) * rand() / RAND_MAX;
    // �������� � ������� � ������� ����
	// if (abs(value) < 0.9) value = 0.;
	return value;
} // GetRand

// ������� ����� �������
void SetColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // SetColor

// ���� ������ �����, ��������� propmt[],
// �������� ���������� �������� from � to
int GetInt(const char *prompt, int from, int to)
{
	int value;
	do {
		// ���������� ����
		cout << prompt;
		cin >> value;

		// ���� ����� �� ����� - ����� ��������� ������,
		// ������� ������ ����� 
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			value = from - 1; // ����� �������� � �����
		} // if
	} while(value < from || value > to);

	return value;
} // GetInt

// ���� ������������� �����, ��������� propmt[],
// �������� ���������� �������� from � to
double GetDouble(const char *prompt, double from, double to)
{
	double value;
	do {
		// ���������� ����
		cout << prompt;
		cin >> value;

		// ���� ����� �� ����� - ����� ��������� ������,
		// ������� ������ ����� 
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			value = from - 1; // ����� �������� � �����
		} // if
	} while(value < from || value > to);

	return value;
} // GetDouble

// ����� ��������� text �������� ������ panelColor, ����� ������ ���� ����������������� � basicColor
void OutText(const char *text, short panelColor, short basicColor)
{
	cout << color(panelColor) << text << color(basicColor);
} // OutText

// ����� ��������� text �������� ������ panelColor, ����� ������ ���� ����������������� � basicColor
// ��������� ������� �� �������, ������������ ��� ���� �������
int OutTextModal(const char *text, short panelColor, short basicColor)
{
	SetColor(panelColor);
	int key = GetKey(text);
	SetColor(basicColor);

	return key;
} // OutTextModal

// ���������������� ������� � �������� ������� �������
void GotoXY(short x, short y) {
	SetConsoleCursorPosition(h, COORD{ x, y });
} // GotoXY


void CreateIntFile(const char *fileName, int n, int lo, int hi)
{
    char str[1024];

    FILE *f = fopen(fileName, "wb");
	if (!f) {
		sprintf(str, "������ ��� �������� ����� %s ��� ������",fileName);
		throw exception(str);
	} // if

	// ������ ��������� ����� � ����
	for (int i = 0; i < n; i++) {
		int x = GetRand(lo, hi);
		fwrite(&x, sizeof(x), 1, f);
	} // for i

	fclose(f);
} // CreateIntFile


void ViewIntFile(const char *fileName, const char *title)
{
    char str[1024];
    cout << title;
    
	FILE *f = fopen(fileName, "rb");
	if (!f) {
		sprintf(str, "������ ��� �������� ����� %s ��� ������",fileName);
		throw exception(str);
	} // if

    // ����������� ������� �����
	fseek(f, 0, SEEK_END);
	int byteSize = ftell(f);
    fseek(f, 0, SEEK_SET);

	// ������ ������� ���������� ����� �� ����� � ������ �������
    //             ����������� / �����������������
	int nRecords = byteSize    / sizeof(int);
	for (int i = 0; i < nRecords; i++) {
        int x;
		fread(&x, sizeof(int), 1, f);
		cout << setw(7) << x;

        if ((i+1) % 10 == 0) cout << "\n";
	} // for 
	if (nRecords % 10 != 0) cout << "\n";
    fclose(f);
}

// ��������� ��� ���������� ������� �������
// mode: true  - �������� ������
//       false - ��������� ������
void SetCursorVisible(bool mode)
{
	// ��� ���� ��������� winAPI
	CONSOLE_CURSOR_INFO info;

	// ��������� ������ � ��� ���������
	GetConsoleCursorInfo(h, &info);

	info.bVisible = mode;
	SetConsoleCursorInfo(h, &info);
} // void SetCursorVisible

// ���������� ���������� ������������ ��� ����������
ostream &tab(ostream &os)
{
	os << "\t";
	return os;
} // tab

// ���������� ������������ ��� �������� ������
ostream &cls(ostream &os)
{
    Cls();
    return os;
} // cls

// ���������� ������������ ��� ���������� �������
ostream &cursor_off(ostream &os)
{
    SetCursorVisible(false);
    return os;
} // cursor_off

// ���������� ������������ ��� ��������� �������
ostream &cursor_on(ostream &os)
{
    SetCursorVisible(true);
    return os;
} // cursor_on


// ���������� ���������� ������������ � ���������� endlm(n)
ostream &operator<<(ostream &os, const endlm &object)
{
	for (int i=0 ; i < object.n; ++i)
		os << endl;
	return os;
} // operator<<

// ���������� ���������� ������������ � ���������� color(c)
ostream &operator<<(ostream &os, const color &color)
{
    SetColor(color.color_);
    return os;
} // operator<<

// ���������� ���������� ������������ � ���������� pos(x, y)
ostream &operator<<(ostream &os, const pos &position) {
	GotoXY(position.x, position.y);
	return os;
} // operator<<

// ������� ������ �������
void Cls()
{
	COORD coordScreen = { 0, 0 }; // �������� ������� ��� �������
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
	// ������� ����� ���������� ����� � ������� ������.

    if( !GetConsoleScreenBufferInfo( h, &csbi )) return;

    // ������ ���� ������� � ��������
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   
	// �������� ��������� ����� ��������� - ��� � ���� �������
	// cCharsWritten - ������� ���������� ��������
    if ( !FillConsoleOutputCharacter( h, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten ))
       return;

    // ��������� ��������������� �������� ������ �� ������� ���������.
    if ( !FillConsoleOutputAttribute( h, csbi.wAttributes,
       dwConSize, coordScreen, &cCharsWritten ))
       return;
    
    // �������� ������ � ��������� ������� ����� ������� ������ - ������� ����� ����
    SetConsoleCursorPosition( h, coordScreen );
} // Cls
