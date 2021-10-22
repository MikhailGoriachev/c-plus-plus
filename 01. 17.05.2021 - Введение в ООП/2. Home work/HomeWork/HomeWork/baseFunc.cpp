#include "head.h"
#include "menu.h"

static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// ���� �������
void setColor(WORD wColor)
{
	SetConsoleTextAttribute(h, wColor);
}

// �������� ���� �������
void tittleOut()
{
	SetConsoleTitle(L"�������� ������ �� 19.05.2021");
}

// �������� ������
void cls()
{
	// ��������� ����������
	COORD cord;

	cord.X = 0;
	cord.Y = 0;

	// ���������� ����������� ��������
	DWORD fillCount;

	// ���������� � ������� �������
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	// ��������� ���������� � �������
	GetConsoleScreenBufferInfo(h, &consoleInfo);

	// ������ ������� 
	DWORD sizeConsole = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;

	// ���������� ������� ���������
	FillConsoleOutputCharacter(h, (TCHAR)' ', sizeConsole, cord, &fillCount);

	// ��������� ��������� ������ �������
	FillConsoleOutputAttribute(h, consoleInfo.wAttributes, sizeConsole, cord, &fillCount);

	SetConsoleCursorPosition(h, cord);
}

// ����� ������ 
void outText(WORD wColor, wchar_t* str)
{
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(h, &info);

	WORD oldColor = info.wAttributes;

	setColor(wColor);

	cout << "������" << endl;

	wcout << str;

	setColor(oldColor);
}

// ��������� �������
void Cursor(SHORT X, SHORT Y)
{
	SetConsoleCursorPosition(h, COORD{ X, Y });
}

// ����� ���� ������ ����
void outBackgr()
{
	setColor(infoColor);

	for (size_t i = 0; i < Y_MENU_SIZE; i++)
	{
		Cursor(i, 0);

		cout << setw(40) << " ";
	}

	setColor(mainColor);
}

void sizeWindow()
{
	CONSOLE_SCREEN_BUFFER_INFO console;

	GetConsoleScreenBufferInfo(h, &console);

	console.dwSize.X = 80;
	console.dwSize.Y = 100;

	SetConsoleScreenBufferSize(h, console.dwSize);
}

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
