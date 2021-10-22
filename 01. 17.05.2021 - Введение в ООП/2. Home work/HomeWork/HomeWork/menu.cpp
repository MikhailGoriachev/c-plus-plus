#include "head.h"

// пользовательское меню
int menu()
{
	setColor(mainColor);

	cls();

	//outBackgr();

	Cursor(5,1);

	outText(mainColor, (wchar_t*)L"МЕНЮ\n");
	
	Cursor(5, 3);

	outText(mainColor, (wchar_t*)L"1. Задание 1\n");

	Cursor(5, 5);

	outText(mainColor, (wchar_t*)L"2. Задание 2\n");
	

	return 0;
}