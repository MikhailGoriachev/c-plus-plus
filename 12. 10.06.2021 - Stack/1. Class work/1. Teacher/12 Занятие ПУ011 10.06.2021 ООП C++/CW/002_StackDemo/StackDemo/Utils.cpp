// ����� �������� �������
#include "pch.h"
#include "Utils.h"
#include "Colors.h"
#include "Palette.h"

// ����������� ���������� - ��������-���������� ����������
// ���������� ����������, ��������� ������ � ������� �����
// ��������� ���� - ������������ ����������
// ����� ����� ���������� == ����� ����� (������) ���������
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void init(const wchar_t *title)
{
	SetConsoleTitle(title);
	SetConsoleOutputCP(CODE_PAGE);
	SetConsoleCP(CODE_PAGE);
	srand(GetTickCount());
	cout << fixed << setprecision(5) << boolalpha;
	
	setColor(mainColor);
	cls();
} // init

// ��������� ���� ������� �������
int getKey(const char *message)
{
	cout << message;
	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

    return key;
} // getKey

// ��������� ���������� �����
int getRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // getRand

// ���������������� ���������, ����������� 0 
double getRand(double low, double high)
{
	double temp = low + (high - low) * rand() / RAND_MAX;
	return abs(temp) <= 1.5?0:temp;
} // getRand

// ������� ����� �������
void setColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // setColor


// ����� ��������� � ������� ������ ���� - ������ ��������� ��� ���������� �����
void showNavBarMessage(short hintColor, const char *message)
{
	// ��������� ���� �������
	short oldColor = getColor();

	// ����� ���� � ������� ������ ���������
	setColor(hintColor);
	gotoXY(0, 0);
	
	// ����� ��������� � ����������� �������������
	cout << setw(115) << left << message << right;
	
	// �������������� ����� 
	setColor(oldColor);
} // showNavBarMessage


// ����� ��������� "������� � ����������"
void showUnderConstruction(short width, short infoColor)
{
	const char* msg[] = {
		"�", // ��� ������ � ����� 255, ��� ���� ����� ������������ ������� �� ������ �����������...
		"    [����������]",
		"    ������� � ����������",
		"�", // ��� ������ � ����� 255, ��� ���� ����� ������������ ������� �� ������ �����������...
		"    ������� ����� ������� ��� �����������...",
		"�", // ��� ������ � ����� 255, ��� ���� ����� ������������ ������� �� ������ �����������...
		"�", // ��� ������ � ����� 255, ��� ���� ����� ������������ ������� �� ������ �����������...
		nullptr // ������� ����� ������
	};
	showMessage(8, 4, width, msg, infoColor);
	gotoXY(8, 30);
} // showUnderConstruction



// ����� ��������� msg � ������� ������, ������� � ������� x, y
// ������ ���� ������ width, ���� ���������� ������ - msgColor
// ����� ����� �� ������, ������ nullptr
void showMessage(short x, short y, short width, const char* msg[], short msgColor) 
{
	// ��������� ������� ���� �������
	short oldColor = getColor();
	setColor(msgColor);
	
	// ������� ������ ��������� � ���� ������� width ��������
	// ������ ��������� �� ����������� ������, ������ nullptr 
	// ������ ��������� ����� ��� ��������������� ���������� �������������� ������
	cout << left;  
	for (short i = 0, row = y; msg[i] != nullptr; i++, row++) {
		gotoXY(x, row);
		cout << setw(width) << msg[i];
	} // for i

	// ������������ ������������ ������ �� ���������, ���� ����� �
	cout << right;
	setColor(oldColor);
} // showMessage

// ����� ����������� �� �����, ������������� ������ �����, ���� �������������
// � �������� color
// n - ������ ���� �����
void showInputLine(const char *prompt, int n, short color)
{
	cout << prompt;
	setColor(color);

	// ������� ������ ���������� ������, ����������
	// ������ � ������ ������, �� 1 ������ �� ������
	for (int i = 0; i < n; ++i) cout << " ";
	for (int i = 0; i < n-1; ++i) cout << "\b";
} // showInputLine

// c ����������� �������� WinAPI -----------------------------------------

// ���������������� ������� � �������� ������� �������
void gotoXY(short x, short y) {
	// TODO: �������� ��������� ����������
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

	if (!GetConsoleScreenBufferInfo(h, &csbi)) return;

	// ������ ���� ������� � ��������
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// �������� ��������� ����� ��������� - ��� � ���� �������
	// cCharsWritten - ������� ���������� ��������
	if (!FillConsoleOutputCharacter(h, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten))
		return;

	// ��������� ��������������� �������� ������ �� ������� ���������.
	if (!FillConsoleOutputAttribute(h, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten))
		return;

	// �������� ������ � ��������� ������� ����� ������� ������ - ������� ����� ����
	SetConsoleCursorPosition(h, coordScreen);
} // cls



// ����� ������ � �������� �����
void cputs(const char* str, short color)
{
	// ��������� ������� ���� ������ 
	short oldColor = getColor();

	// ���������� �������� ���� ������ � ������� ������
	setColor(color);
	cout << str;

	// ������������ ���� ������
	setColor(oldColor);
} // cputs

// ����� ������ � �������� ����������� ���� ������� �������� ������
void writeXY(short x, short y, const char* str, short color)
{
	// ���������� �������� ���� ������ � ������� ������
	// � �������� ������� ������
	gotoXY(x, y);
	cputs(str, color);
} // writeXY
// 
// �������� ������� ���� ������ � �������
short getColor()
{
	// ��������� ��������� - ���������� � ������ �������, � �.�. ���� 
	// ���������� ������
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	// ������� �������� ������ � �������, ���� �� ���������� - ������
	// ����������� ��������� ������ (����� �� ������)
	if (!GetConsoleScreenBufferInfo(h, &csbi)) return GRAY_ON_BLACK;

	// ������� ������� �����, ���������� �� ���������� ������ �������
	return csbi.wAttributes;
} // getColor
