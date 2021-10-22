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
    init(L"Экзаменационна работа. Вариант 1");

	App::preview();

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	// константы для swith меню
	enum Commands {
		// Задание 1. Вектор
		CMD_POINT_ONE,
		// Задание 2. Библиотека
		CMD_POINT_TWO,
		// Задание 3. Телефонная станция
		CMD_POINT_THREE
	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Задание 1. Вектор", CMD_POINT_ONE),
		MenuItem("Задание 2. Библиотека", CMD_POINT_TWO),
		MenuItem("Задание 3. Телефонная станция", CMD_POINT_THREE),

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
			// Задание 1. Вектор
			case CMD_POINT_ONE:
				app.task1();
				break;
			// Задание 2. Библиотека
			case CMD_POINT_TWO:
				app.task2();
				break;
			// Задание 3. Телефонная станция
			case CMD_POINT_THREE:
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
		} // try-catch
	}
} // main