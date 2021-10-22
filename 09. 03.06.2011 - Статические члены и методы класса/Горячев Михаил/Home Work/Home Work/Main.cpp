// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"
#include "Palette.h"
#include "menu.h"
#include "MenuItem.h"

int main()
{
    init(L"Домашнее задание на 07.06.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	enum Commands {
		// Вывод самлётов
		CMD_OUT_PLANES, 
		// Вывод самолёта по индексу
		CMD_OUT_PLANE_INDEX, 
		// Добавление по 10 пассажиров каждому самолету компании
		CMD_ADD_TEN_PLANES, 
		// Уменьшение количества пассажиров каждого самолета на 3
		CMD_DEC_THREE_PLANES,
		// Поиск первого самолета с максимальной стоимостью
		CMD_SEARCH_MAX_PRICE,
		// Поиск первого самолета с минимальной стоимостью
		CMD_SEARCH_MIN_PRICE,
		// Увеличения стоимости самолетов на заданный коэффициент
		CMD_INCREAS_COEF_PLANES,
	};

	const int N_MENU = 8;
	MenuItem items[N_MENU] = {
		MenuItem("Вывод самолётов", CMD_OUT_PLANES),
		MenuItem("Вывод самолёта по индексу", CMD_OUT_PLANE_INDEX),
		MenuItem("Добавление по 10 пассажиров каждому самолету компании", CMD_ADD_TEN_PLANES),
		MenuItem("Уменьшение количества пассажиров каждого самолета на 3", CMD_DEC_THREE_PLANES),
		MenuItem("Поиск первого самолета с максимальной стоимостью", CMD_SEARCH_MAX_PRICE),
		MenuItem("Поиск первого самолета с минимальной стоимостью", CMD_SEARCH_MIN_PRICE),
		MenuItem("Увеличения стоимости самолетов на заданный коэффициент", CMD_INCREAS_COEF_PLANES),
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	const int N_PALETTE = 5;
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			while (true) {
				cout << color(palette[Menu::PAL_CONSOLE]) << cls;
				int cmd = mainMenu.Navigate();
				cout << color(palette[Menu::PAL_CONSOLE]) << cls;
				if (cmd == Menu::CMD_QUIT) return 0;
				
				switch (cmd)
				{
					// Вывод самлётов
				case CMD_OUT_PLANES:
					app.outPlanes();
					break;

					// Вывод самолёта по индексу
				case CMD_OUT_PLANE_INDEX:
					app.outPlaneIndex();
					break;

					// Добавление по 10 пассажиров каждому самолету компании
				case CMD_ADD_TEN_PLANES:
					app.addTenPlanes();
					break;

					// Уменьшение количества пассажиров каждого самолета на 3
				case CMD_DEC_THREE_PLANES:
					app.decThreePlanes();
					break;

					// Поиск первого самолета с максимальной стоимостью
				case CMD_SEARCH_MAX_PRICE:
					app.searchMaxPrice();
					break;
					// Поиск первого самолета с минимальной стоимостью
				case CMD_SEARCH_MIN_PRICE:
					app.searchMinPrice();
					break;

					// Увеличения стоимости самолетов на заданный коэффициент
				case CMD_INCREAS_COEF_PLANES:
					app.increasCoefPlanes();
					break;

				} // switch
			} // while
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
