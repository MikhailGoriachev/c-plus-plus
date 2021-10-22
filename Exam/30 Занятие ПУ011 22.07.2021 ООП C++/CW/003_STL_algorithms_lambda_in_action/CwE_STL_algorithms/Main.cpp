// Приложение с использованием меню

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "App.h"


int main()
{
	// настройка вывода в консоль
	init(L"22.07.2021 - применение лямбда-выражений, алгоритмов STL");

    // коды команд приложения
    enum Commands {
        CMD_VARIANT16, CMD_VARIANT19
    };

    // пункты меню приложения
    const int N_MENU = 3;
    MenuItem items[N_MENU] = {
        MenuItem ("Выполнение варианта 16", CMD_VARIANT16), 
        MenuItem ("Выполнение варианта 19", CMD_VARIANT19), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок  пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {infoColor, LTCYAN_ON_BLACK, hintColor,       mainColor};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

    // приложение - реализация вариантов 16 и 19
    App *app = new App();

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
			case CMD_VARIANT16: {
	            app->make();
	            app->show("\n    Вариант 16 - вектор для обработки\n");

	            // количество отрицательных элементов вектора
	            int negatives = app->variant16a();
	            cout << "\n    Вариант 16, отрицательных элементов в векторе: "
	                << negatives << "\n";

	            double sumAbs = app->variant16b();
	            cout << "\n    Вариант 16, сумма модулей элементов после минимального\n"
	                << "\t\tпо модулю элемента в векторе: " << sumAbs << "\n";

	            app->variant16c();
	            app->show("\n    Вектор 16 - отрицательные в квадрате и сортировка по возрастанию\n");
	        }
			break;    
        
			case CMD_VARIANT19: {
	            app->make();
	            app->show("\n    Вариант 19 - вектор для обработки\n");

	            // произведение отрицательных элементов вектора
	            double prodNegatives = app->variant19a();
	            cout << "\n    Вариант 19, произведение отрицательных элементов в векторе: "
	                << prodNegatives << "\n";

	            double sumPositives = app->variant19b();
	            cout << "\n    Вариант 19, сумма положительных элементов до максимального\n"
	                << "\t\tэлемента в векторе: " << sumPositives << "\n";

	            app->variant19c();
	            app->show("\n    Вектор 19 - изменение порядка следования в векторе на обратный\n");
	        }
        	break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

    delete app;
	return 0;
} // main

