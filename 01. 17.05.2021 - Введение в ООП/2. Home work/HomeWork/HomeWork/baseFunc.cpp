#include "head.h"
#include "menu.h"

static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// цвет консоли
void setColor(WORD wColor)
{
	SetConsoleTextAttribute(h, wColor);
}

// название окна консоли
void tittleOut()
{
	SetConsoleTitle(L"ДОМАШНЯЯ РАБОТА НА 19.05.2021");
}

// отчистка экрана
void cls()
{
	// начальные координаты
	COORD cord;

	cord.X = 0;
	cord.Y = 0;

	// количество заполненных символов
	DWORD fillCount;

	// информация о текущей консоли
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

	// получение информации о консоли
	GetConsoleScreenBufferInfo(h, &consoleInfo);

	// размер консоли 
	DWORD sizeConsole = consoleInfo.dwSize.X * consoleInfo.dwSize.Y;

	// заполнение консоли пробелами
	FillConsoleOutputCharacter(h, (TCHAR)' ', sizeConsole, cord, &fillCount);

	// изменение атрибутов буфера консоли
	FillConsoleOutputAttribute(h, consoleInfo.wAttributes, sizeConsole, cord, &fillCount);

	SetConsoleCursorPosition(h, cord);
}

// вывод текста 
void outText(WORD wColor, wchar_t* str)
{
	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(h, &info);

	WORD oldColor = info.wAttributes;

	setColor(wColor);

	cout << "Привет" << endl;

	wcout << str;

	setColor(oldColor);
}

// установка курсора
void Cursor(SHORT X, SHORT Y)
{
	SetConsoleCursorPosition(h, COORD{ X, Y });
}

// вывод фона экрана меню
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

// включение или выключение курсора консоли
// mode: true  - включить курсор
//       false - выключить курсор
void setCursorVisible(bool mode)
{
	// еще одна структура winAPI
	CONSOLE_CURSOR_INFO info;

	// получение данных в эту структуру
	GetConsoleCursorInfo(h, &info);

	info.bVisible = mode;
	SetConsoleCursorInfo(h, &info);
} // void setCursorVisible
