#include "pch.h"
#include "app.h"

using namespace std;

void main()
{
	// ����������� �������� ����� ��� ����� � ������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		// ��������� ����������
		try
		{
			// �������� ������� 1
			task1();

			return;
		}
		catch (const std::exception& b)
		{
			cls();

			setColor(errColor);

			gotoXY(10, 5);

			// ����� ��������� 
			cout << b.what();

			setColor(mainColor);

			Sleep(2000);

			cls();
		}
	}
}