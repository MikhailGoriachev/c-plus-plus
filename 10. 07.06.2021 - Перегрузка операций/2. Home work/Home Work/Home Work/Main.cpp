// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"
#include "Palette.h"
#include "menu.h"
#include "MenuItem.h"
#include "Plane.h"

// инициализация констант
const double Plane::MAX_FUEL = 20000.;
const double Plane::MIN_FUEL = 0.1;

int main()
{
    init(L"Домашнее задание на 09.06.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	enum Commands {
		// Вывод самлётов
		CMD_OUT_PLANES, 
		// Вывод самолёта по индексу
		CMD_OUT_PLANE_INDEX, 
		// Добавление самолёта
		CMD_ADD_PLANE, 
		// Уменьшение количества пассажиров каждого самолета на 3
		CMD_DEC_THREE_PLANES,
		// Сортировка самолёта по текущему количеству пассажиров
		CMD_SORT_BY_COUNT_PASSANGERS,
		// Сортировка самолёта по регистрационному номеру
		CMD_SORT_BY_NUMBER,
		// Сортировка самолёта по часовому расходу горючего
		CMD_SORT_BY_FUEL,
		// Сортировка самолёта по дальности полёта
		CMD_SORT_BY_DISTANCE,
		// Вывод данных авиакомпании в табличном виде с выделением цветом
		// самолетов с максимальной и минимальной дальностями полета
		CMD_OUT_TABLE_COLOR
	}; 

	const int N_MENU = 9;
	MenuItem items[N_MENU] = {
		MenuItem("Вывод самолётов", CMD_OUT_PLANES),
		MenuItem("Вывод самолёта по индексу", CMD_OUT_PLANE_INDEX),
		MenuItem("Добавление самолёта", CMD_ADD_PLANE),
		MenuItem("Сортировка самолёта по текущему количеству пассажиров", CMD_SORT_BY_COUNT_PASSANGERS),
		MenuItem("Сортировка самолёта по регистрационному номеру", CMD_SORT_BY_NUMBER),
		MenuItem("Сортировка самолёта по часовому расходу горючего", CMD_SORT_BY_FUEL),
		MenuItem("Сортировка самолёта по дальности полёта", CMD_SORT_BY_DISTANCE),
		MenuItem("Максимальная и минимальная дальность полета самолёта", CMD_OUT_TABLE_COLOR),
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	const int N_PALETTE = 5;
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
				// Вывод самлётов
			case CMD_OUT_PLANES:
				app.outPlanes();
				break;

				// Вывод самолёта по индексу
			case CMD_OUT_PLANE_INDEX:
				app.outPlaneIndex();
				break;

				// Добавление по 10 пассажиров каждому самолету компании
			case CMD_ADD_PLANE:
				app.addPlane();
				break;

				// Сортировка самолёта по текущему количеству пассажиров
			case CMD_SORT_BY_COUNT_PASSANGERS:
				app.sortByCountPassangers();
				break;
				// Сортировка самолёта по регистрационному номеру
			case CMD_SORT_BY_NUMBER:
				app.sortByNumber();
				break;

				// Сортировка самолёта по часовому расходу горючего
			case CMD_SORT_BY_FUEL:
				app.sortByFuel();
				break;

				// Сортировка самолёта по дальности полёта
			case CMD_SORT_BY_DISTANCE:
				app.sortByDistance();
				break;

				// Максимальная и минимальная дальность полета самолёта
			case CMD_OUT_TABLE_COLOR:
				app.outTableColor();
				break;
			} // switch
		} // try
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
	}// while

} // main
