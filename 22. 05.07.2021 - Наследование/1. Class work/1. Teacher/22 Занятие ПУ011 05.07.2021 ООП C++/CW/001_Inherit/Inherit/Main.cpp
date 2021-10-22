/*
 * Наследование в C++, введение 
 * 
 */


#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Base.h"
#include "Derived.h"
#include "Palette.h"


int main()
{
	// настройка вывода в консоль
	init(L"Занятие 05.07.2021 - наследование, введение");

	// коды команд
    enum Commands {
    	CMD_ONE,      // Базовый класс
    	CMD_TWO,      // Производный класс
    	CMD_THREE     // Динамические переменные - производный класс
    };

	// массив пунктов меню
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Базовый класс", CMD_ONE), 
        MenuItem ("Производный класс", CMD_TWO), 
        MenuItem ("Динамические переменные - производный класс", CMD_THREE), 
        MenuItem ("Выход",  Menu::CMD_QUIT) 
    };

	// палитра вывода меню
    const int N_PALETTE = 5;
	//                          заголовок       пункт меню       выбранный пункт  текст консоли  
    short palette[N_PALETTE] = {arrColor, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, mainColor};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5}); 
    
    while(true) {
        try {
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            showNavBarMessage(hintColor, "  Наследование");
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            switch (cmd) {
            // Базовый класс
            case CMD_ONE:
            {
                Base base1, base2(101, 202);
                cout << endlm(3) << "    base1 = " << base1 << "\n"
                    << "    base2 = " << base2;

                base1.setA(999);
                base1.setB(-99);

                cout<< endlm(2) << "    base1 = {" << base1.getA() << "; " << base1.getB() << "}\n"
                    << "    base2 = " << base2 << endlm(3);
            }
            break;

            // Производный класс
            case CMD_TWO:
	            {
                Derived derived1, derived2(-1, -2, -3);
                cout << endlm(3) << "    derived1 = " << derived1 << "\n"
                    << "    derived2 = " << derived2;

                derived1.setA(999);  // метод базового класса
                derived1.setB(-99);  // метод базового класса
                derived1.setC(-9);   // метод производного класса

                cout<< endlm(2) << "    derived1 = {" << derived1.getA() << "; "
            		<< derived1.getB() << "}\n"
                    << "    derived2 = " << derived2 << endlm(3);
	            }
                break;

            // Динамические переменные - производный класс
            case CMD_THREE:
	            {
                Derived *pDerived1 = new Derived, *pDerived2 = new Derived(-1, -2, -3);
                cout << endlm(3) << "    derived1 = " << *pDerived1 << "\n"
                    << "    derived2 = " << *pDerived2;

                pDerived1->setA(999);
                pDerived1->setB(-99);
                pDerived1->setC(-9);

                cout << endlm(2) << "    derived1 = {" << pDerived1->getA() << "; "
                    << pDerived1->getB() << "; " << pDerived1->getC() << "}\n"
                    << "    derived2 = " << *pDerived2 << endlm(3);

                delete pDerived1;
                delete pDerived2;
	            }
                break;
            } // switch

        } catch (exception &ex) {
            setColor(mainColor);
            cls();
            showNavBarMessage(hintColor, "  Ошибка приложения, нажмите любую клавишу для продолжения...");

	        // добавим 4 пробела перед выводимым сообщением об ошибке, длина строки 64 символа
            char buf[65];
            sprintf(buf, "    %-60s", ex.what());

        	// в эту секцию передается управление оператором throw
            const char* msg[] = {
                " ",
                "    [Ошибка]",
                buf,
                " ",
                " ",
                nullptr
            };
            showMessage(8, 4, 64, msg, errColor);
        } // try-catch
        cout << endlm(2);
        getKey();
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main