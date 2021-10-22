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
    init(L"Домашнее задание на 15.06.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	// константы для swith меню
	enum Commands {
		// Задача 1. Перемещение элементов из одной очереди во вторую
		CMD_TASK_ONE, 
		// Задача 2. Перемещение до отрицательного элемента
		CMD_TASK_TWO, 
		// Задача 3. Разделение очереди на отрицателньую и положительную
		CMD_TASK_THREE,
		// Задача 4. Перемещение самолётов по диапазону расхода горючего
		CMD_TASK_FOUR
	};

	// количество пунктов меню
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("Задача 1. Перемещение элементов из одной очереди во вторую", CMD_TASK_ONE),
		MenuItem("Задача 2. Перемещение до отрицательного элемента", CMD_TASK_TWO),
		MenuItem("Задача 3. Разделение очереди на отрицателньую и положительную", CMD_TASK_THREE),
		MenuItem("Задача 4. Перемещение самолётов по диапазону расхода горючего", CMD_TASK_FOUR),

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
				// Задача 1. Перемещение элементов из одной очереди во вторую
			case CMD_TASK_ONE:
				app.task1();
				break;
				// Задача 2. Перемещение до отрицательного элемента
			case CMD_TASK_TWO:
				app.task2();
				break;
				// Задача 3. Разделение очереди на отрицателньую и положительную
			case CMD_TASK_THREE:
				app.task3();
				break;
				// Задача 4. Перемещение самолётов по диапазону расхода горючего
			case CMD_TASK_FOUR:
				app.task4();
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
