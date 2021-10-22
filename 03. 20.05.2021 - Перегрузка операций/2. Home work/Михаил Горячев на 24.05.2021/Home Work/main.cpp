#include "pch.h"
#include "app.h"

using namespace std;

void main()
{
	// подключение русского языка для ввода и вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		// обработка исключений
		try
		{
			// загрузка задания 1
			task1();

			return;
		}
		catch (const std::exception& b)
		{
			cls();

			setColor(errColor);

			gotoXY(10, 5);

			// вывод сообщения 
			cout << b.what();

			setColor(mainColor);

			Sleep(2000);

			cls();
		}
	}
}