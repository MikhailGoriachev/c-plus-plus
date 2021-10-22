// Контейнеры STL: ассоциативные контейнеры/ассоциативные массивы/отображения

// pair     - пара: ключ (key, first) - значение (value, second), first - second 
// map      - словарь - коллекция уникальных ключей, т.е. ключ не повторяется
// multimap - словарь  - коллекция повторяющихся ключей
// set      - множество - коллекция уникальных ключей (вторая часть пары не хранится)
//            коллекция уникальных значений
// multiset - множество с повторением, коллекция повторяющися значений
// bitset   - битовое множество


#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "App.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 19.07.2021 - STL, ассоциативные контейнеры, часть 3");

    // коды команд приложения
    enum Commands {
        CMD_PAIR,
    	CMD_MAP,
    	CMD_MULTIMAP,
    	CMD_SET,
    	CMD_MULTISET
    };

    // пункты меню приложения
    const int N_MENU = 6;
    MenuItem items[N_MENU] = {
        MenuItem ("Класс pair", CMD_PAIR), 
        MenuItem ("Класс map", CMD_MAP), 
        MenuItem ("Класс multimap", CMD_MULTIMAP), 
        MenuItem ("Класс set", CMD_SET), 
        MenuItem ("Класс multiset", CMD_MULTISET), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});


    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        showNavBarMessage(hintColor, "  Ассоциативные контейнеры в C++");
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd)
        {
            case CMD_PAIR:
			App::demoPair();
            break;    
        
            case CMD_MAP:
			App::demoMap();
            break;    

            case CMD_MULTIMAP:
			App::demoMultimap();
            break;

			case CMD_SET:
			App::demoSet();
            break;    

            case CMD_MULTISET:
			App::demoMultiset();
            break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main