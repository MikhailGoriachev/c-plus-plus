// Вложенные классы C++

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Outer.h"
#include "TemplateOuter.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 23.06.2021 - вложенные классы в C++");

    // коды команд приложения
    enum Commands {
        CMD_ONE, CMD_TWO, CMD_THREE
    };

    // пункты меню приложения
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Вложенный класс", CMD_ONE), 
        MenuItem ("Вложенный класс - шаблонный класс int, double", CMD_TWO), 
        MenuItem ("Вложенный класс - шаблонный класс char, bool", CMD_THREE), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

    Outer outer1;
    Outer::Inner inner1(-1, 15., &outer1);

    TemplateOuter<int, double> templateOuter1(232, M_LN2);
    TemplateOuter<int, double>::Inner templateInner1(-100, 123.6, &templateOuter1);

    TemplateOuter<char, bool> templateOuter2('ё', false);
    TemplateOuter<char, bool>::Inner templateInner2('ш', true, &templateOuter2);

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
        
        cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
            case CMD_ONE:
            cout << "    outer1.a = " << outer1.getA() << "\n"
                 << "    inner1.c = " << inner1.getC() << "\n";

        	// вызовы методов внешнего и внутреннего классов
        	outer1.bar();
            inner1.foo();
        	
            break;    
        
            case CMD_TWO:
            cout << "    templateOuter1.a = " << templateOuter1.getA() << "\n"
                 << "    templateInner1.c = " << templateInner1.getC() << "\n";
            break;    

            case CMD_THREE:
            cout<< boolalpha 
                << "    templateOuter2.a = " << templateOuter2.getA() << "\n"
                << "    templateInner2.c = " << templateInner2.getC() << "\n"
                << noboolalpha;
            break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main