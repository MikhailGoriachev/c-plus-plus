#include "pch.h"
#include "Utils.h"
#include "head.h"

void menu()
{
	char c;

	while (true)
	{
		cls();

		setCursorVisible(false);

		gotoXY(5, 3);

		cout << "������� 1" << endl;

		gotoXY(5, 5);

		cout << "������� 2" << endl;

		gotoXY(5, 7);

		cout << "����� [ESC]" << endl;

		while (true)
		{
			c = _getch();

			if (c == '1')
			{
				task1();

				break;
			}
			
			else if (c == '2')
			{
				task2();

				break;
			} 
			
			else if (c == 27)
			{
				return;
			}
		}

	}
	
}