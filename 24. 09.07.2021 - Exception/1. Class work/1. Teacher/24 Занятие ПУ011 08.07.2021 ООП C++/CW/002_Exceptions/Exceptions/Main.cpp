// Спецификация исключений в заголовке функции
// Функциональный try-блок

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "App.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 08.07.2021 - исключения, часть 2");

    // коды команд приложения
    enum Commands {
        CMD_ONE, CMD_TWO
    };

    // пункты меню приложения
    const int N_MENU = 3;
    MenuItem items[N_MENU] = {
        MenuItem ("Функция с выбросом исключения", CMD_ONE), 
        MenuItem ("Функциональный try-блок", CMD_TWO), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    //                                заголовок       пункт            выбранный пункт  консоль
    short palette[Menu::N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});


    while(true) {
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) break;
		
			cout << endlm(3) << "    " << items[cmd].text << endlm(3);

			switch (cmd) {
				case CMD_ONE:
					foo();
				break;    
        
				case CMD_TWO:
					bar();
				break;    
			} // switch

		} // try
		catch (exception &ex) {
			cout << endlm(2) << "    " << ex.what() << endlm(3);
		} // catch

		cout << endlm(3);
		getKey("    Нажмите любую клавишу для продолжения...");
	} // while
	
    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main