#include "head.h"

// ���������������� ����
int menu()
{
	setColor(mainColor);

	cls();

	//outBackgr();

	Cursor(5,1);

	outText(mainColor, (wchar_t*)L"����\n");
	
	Cursor(5, 3);

	outText(mainColor, (wchar_t*)L"1. ������� 1\n");

	Cursor(5, 5);

	outText(mainColor, (wchar_t*)L"2. ������� 2\n");
	

	return 0;
}