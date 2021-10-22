// Итераторы, функциональные объекты, алгоритмы

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "App.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 19.07.2021 - итераторы, функциональные объекты, алгоритмы");

    // коды команд приложения
    enum Commands {
        CMD_ITERS,
    	CMD_FUNC_OBJ,
    	CMD_ALGORITHMS
    };

    // пункты меню приложения
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Итераторы", CMD_ITERS), 
        MenuItem ("Функциональные объекты", CMD_FUNC_OBJ), 
        MenuItem ("Алгоритмы", CMD_ALGORITHMS), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    //                               заголовок       пункт            выбранный пункт  консоль
    short palette[Menu::N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

    App* app = new App();
	
    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        showNavBarMessage(hintColor, " Ввдение в итераторы, функциональные объекты, алгоритмы");
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
            case CMD_ITERS:
            app->iteratorsDemo();
            break;    
        
            case CMD_FUNC_OBJ:
            app->functionalObjectsDemo();
            break;    

            case CMD_ALGORITHMS:
            app->algorithmsDemo();
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