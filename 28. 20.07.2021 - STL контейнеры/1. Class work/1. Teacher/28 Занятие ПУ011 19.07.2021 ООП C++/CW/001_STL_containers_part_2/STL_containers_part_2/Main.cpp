// Контейнерные классы STL - последовательные контейнеры
// vector, deque, list, slist, stack, qeueue

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "App.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 19.07.2021 - работа с последовательными контейнерами STL, часть 2");

    // коды команд приложения
    enum Commands {
        CMD_LIST, CMD_STACK, CMD_QUEUE
    };

    // пункты меню приложения
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Список - классы list, slist", CMD_LIST), 
        MenuItem ("Адаптер, стек - класс stack", CMD_STACK), 
        MenuItem ("Адаптер, очередь - класс queue", CMD_QUEUE), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

    App* app = new App();

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        showNavBarMessage(hintColor, "  Последовательные контейнеры STL");
    	int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {        
            case CMD_LIST:
                app->demoSlistList();
            break;    

            case CMD_STACK:
                app->demoStack();
            break;

			case CMD_QUEUE:
                app->demoQueue();
			break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main