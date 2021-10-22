#include "pch.h"
#include "Utils.h"
#include "Colors.h"

// ��������� ���������� ���������� - ����������� ����������
// ��������� � ������������ ���������� (�������� - singleton),
// ������� ��������� - ������ ���� ��������� ����
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// �������� �����
// typedef ������ �������� ����� ��������;
// typedef unsigned char Byte;
// Byte x;

void init(const wchar_t title[])
{
	SetConsoleTitle(title);

	SetConsoleOutputCP(CODE_PAGE);
	SetConsoleCP(CODE_PAGE);
	srand(GetTickCount());
	cout << fixed << setprecision(5);
	
	setColor(GRAY_ON_LTBLACK);
	cls();
} // init

// ��������� ���� ������� �������
int getKey(const char *prompt)
{
	cout << prompt;

	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

    return key;
} // getKey

// ��������� ���������� �����
int getRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // getRand

// ��������� ���������� ������������� ����� � 
// ������������� ������� ��������
double getRand(double low, double high)
{
    double x = low + (high - low) * rand() / RAND_MAX;
	return abs(x) < 0.8?0:x;
} // getRand

// ������� ����� �������
void setColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // setColor

// ���� ������ �����, ��������� propmt[],
// �������� ���������� �������� from � to
int getInt(const char prompt[], int from, int to)
{
	int value;
	do {
		// ���������� ����
		cout << prompt;
		cin >> value;

		// ���� ����� �����, ����� �� ����� � �� �������
		if (!cin.fail()) break;

		// ���� ��� �� ����� - ����� ��������� ������,
		// ������ ������ �����
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '\n');
	} while(value < from || value > to);

	return value;
} // getInt

// ���� ������������� �����, ��������� propmt[],
// �������� ���������� �������� from � to
double getDouble(const char *prompt, double from, double to)
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
} // getDouble

// ����� ��������� text �������� ������ panelColor, ����� ������ ���� ����������������� � basicColor
void outText(const char text[], short panelColor, short basicColor)
{
	setColor(panelColor);
	cout << text;
	setColor(basicColor);
} // outText

// ����� ��������� text �������� ������ panelColor, ����� ������ ���� ����������������� � basicColor
// ��������� ������� �� �������, ������������ ��� ���� �������
int outTextModal(const char text[], short panelColor, short basicColor)
{
	int key;
	setColor(panelColor);
	key = getKey(text);
	setColor(basicColor);

	return key;
} // outTextModal

// c ����������� �������� WinAPI -----------------------------------------

// ���������������� ������� � �������� ������� �������
void gotoXY(short x, short y) {
	SetConsoleCursorPosition(h, COORD{ x, y });
} // gotoXY

// ��������� ��� ���������� ������� �������
// mode: true  - �������� ������
//       false - ��������� ������
void setCursorVisible(bool mode)
{
	// ��� ���� ��������� winAPI
	CONSOLE_CURSOR_INFO info;

	// ��������� ������ � ��� ���������
	GetConsoleCursorInfo(h, &info);

	info.bVisible = mode;
	SetConsoleCursorInfo(h, &info);
} // void setCursorVisible


// ������� ������ �������
void cls()
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
} // cls