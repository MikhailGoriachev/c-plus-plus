// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "Palette.h"

int main()
{
    init(L"Домашнее задание на 28.06.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	// константы для swith меню
	enum Commands {
		// Задача 1. Итератор
		CMD_TASK_ONE,
		// Задача 2. Проверка строки на корректность
		CMD_TASK_TWO,
		// Задача 3. Очередь нуждающихся в улучшении жилищных условий
		CMD_TASK_THREE

	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Задача 1. Итератор", CMD_TASK_ONE),
		MenuItem("Задача 2. Проверка строки на корректность", CMD_TASK_TWO),
		MenuItem("Задача 3. Очередь нуждающихся в улучшении жилищных условий", CMD_TASK_THREE),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{ 5, 5 });
	
	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return 0;

			switch (cmd)
			{
				// Задача 1. Итератор
			case CMD_TASK_ONE:
				app.task1();
				break;
				// Задача 2. Проверка строки на корректность
			case CMD_TASK_TWO:
				app.task2();
				break;
				// Задача 3. Очередь нуждающихся в улучшении жилищных условий
			case CMD_TASK_THREE:
				app.task3();
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
} // main
