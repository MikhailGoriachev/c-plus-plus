#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "MyException.h"
#include "MegaException.h"
#include "App.h"

void foo();

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 08.07.2021 - наследование от шаблонного класса, исключения в C++");

	// назначение функции, вызываемой системой при аварийном завершении приложения
	set_terminate(foo);

	// назначение функции, вызываемой системой при непредусмотренном исключении
	// set_unexpected(foo);

    // коды команд приложения
    enum Commands {
        CMD_ZERO,   // Наследование от шаблонного класса
    	CMD_ONE,    // Оператор throw - выброс исключения
    	CMD_TWO,    // Собственное исключение - исключение на базе произвольного класса
    	CMD_THREE,  // Иерархия классов-исключений на базе класса exception
    	CMD_FOUR    // Исключения в функциях - раскрутка стека
    };

    // пункты меню приложения
    const int N_MENU = 6;
    MenuItem items[N_MENU] = {
        MenuItem ("Наследование от шаблонного класса", CMD_ZERO), 
        MenuItem ("Оператор throw - выброс исключения", CMD_ONE), 
        MenuItem ("Собственное исключение - исключение на базе произвольного класса", CMD_TWO), 
        MenuItem ("Иерархия классов-исключений на базе класса exception", CMD_THREE), 
        MenuItem ("Исключения в функциях - раскрутка стека", CMD_FOUR), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    //                                заголовок       пункт            выбранный пункт  консоль
    short palette[Menu::N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});
	int a, b, c;

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
        	// Наследование от шаблонного класса
			case CMD_ZERO:
			templatesAndInherit();
			break;

        	// Оператор throw - выброс исключения
            case CMD_ONE:
			try {
				a = 10;
				b = 0;
				//          throw выражение;
				// if (b == 0) throw 1001;
				// if (b == 0) throw M_PI;
				// if (b == 0) throw "Деление на ноль";
				if (b == 0) throw false;

        		c = a / b;
				cout << "    c = " << c << "\n";
			}
  	
			catch (const char *msg) {
				cout << "\n\n    " << msg << "\n\n";
			} 

        	catch (double) {
				cout << "\n\n    Ошибка с вещественным кодом\n\n";
			}
			
			catch (int code) {
				cout << "\n\n    Ошибка с кодом " << code << "\n\n";
			}

			catch (...) {
				cout << "\n\n    Случилось страшное...\n\n";
			}
            break;    

        	// Собственное исключение - исключение на базе произвольного класса
            case CMD_TWO:
			try {
			    a = getRand(-10, 10);
				
				if ((a & 1) != 0 ) throw exception("Значение нечетное");
				if (a != 0) throw MyException("Значение не равно нулю");

				cout << "    Нормальная работа\n";
			}
			catch (MyException &myException)
			{
				cout << "\n\n    Обнаружено исключение типа MyException\n\n";
				cout << "    " << myException << "\n\n";
			}
			catch (exception &ex)
			{
				cout << "    " << ex.what() << "\n\n";
			}

            break;    

        	// Иерархия классов-исключений на базе класса exception
            case CMD_THREE:
			try	{
				b = getRand(3, 9); int line = __LINE__;
				if (b % 3 == 0) {
					ostringstream oss;
					oss << "Параметр b = " << b << " кратен 3 в строке " << line 
					    << "\nфайл " << __FILE__;
					throw MegaException(oss.str());
				} // if
			} catch (MegaException &ex)
			{
				cout << "\n\n    " << ex.what() << "\n\n";
			}
            break;

        	// Исключения в функциях - раскрутка стека
			case CMD_FOUR:
			try {
				bar();
			}
     	
        	catch (range_error &ex)
			{
				cout << "\n\n    main: <<rainge_error>> " << ex.what() << "\n\n";
				throw;  // проброс исключения в RTS - повторный выброс исключения
        		        // с теми же параметрами 
			}

			catch (exception& ex)  // чем выше уровень в иерархии исключений, тем ниже обработчик в коде
			{
				cout << "\n\n    main: " << ex.what() << "\n\n";
			}
			break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main

// функция, вызываемая системой времени исполнения перед abort()
// мы можем что-нибудь сказать напоследок...
void foo()
{
	cout << "    foo: это я, запомните меня таким :)\n";
	// throw 1;
}