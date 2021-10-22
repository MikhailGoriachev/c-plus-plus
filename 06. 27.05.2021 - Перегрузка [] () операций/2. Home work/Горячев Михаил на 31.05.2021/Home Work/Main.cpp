// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"

int main()
{
    init(L"Домашнее задание на 31.05.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	char num;

	setColor(headerColor);

	while (true)
	{
		try {

			cls();

			setCursorVisible(false);

			cout << "\n\n\t\t\t\t\tМеню\n" << endl << endl;

			cout << "\t\t1. Задание 1" << endl << endl;

			cout << "\t\t2. Задание 2" << endl << endl;

			cout << "\t\tESC Выход" << endl;

			while (true)
			{
				num = _getch();

				switch (num)
				{
				case '1':
					app.task1();
					break;
				case '2':
					app.task2();
					break;
				case 27:
					return 0;
				}	

				break;
			}


		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();

			// что на самом деле происходит
			// string temp = oss.str();
			// cputs(temp.c_str(), errColor);
		} // try-catch
	}

	getKey();
} // main
