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
    init(L"Заголовок окна консоли приложения");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	// константы для swith меню
	enum Commands {
		// Тест функций int
		CMD_TEST_INT,
		// Тест функций char
		CMD_TEST_CHAR,
		// Тест функций Car
		CMD_TEST_CAR
	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Тест функций int", CMD_TEST_INT),
		MenuItem("Тест функций char", CMD_TEST_CHAR),
		MenuItem("Тест функций Car", CMD_TEST_CAR),

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
				// Пункт меню 1
			case CMD_TEST_INT:
				app.intDemo();
				break;
				// Пункт меню 2
			case CMD_TEST_CHAR:
				app.charDemo();
				break;
				// Пункт меню 3
			case CMD_TEST_CAR:
				app.carDemo();
				break;
			}
		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			// что на самом деле происходит
			// string temp = oss.str();
			// cputs(temp.c_str(), errColor);
		} // try-catch
	}
} // main
