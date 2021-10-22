#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "List.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 16.06.21 - односвязный список, класс List");

    // коды команд приложения
    enum Commands {
        CMD_ADD, CMD_INSERT, CMD_GET_PUT, CMD_CLEAR
    };

    // пункты меню приложения
    const int N_MENU = 5;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка операции add()", CMD_ADD), 
        MenuItem ("Проверка операции insert()", CMD_INSERT), 
        MenuItem ("Проверка операций get(), put()", CMD_GET_PUT), 
        MenuItem ("Проверка операции clear()", CMD_CLEAR), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Работаем с одосвязным списком", items, N_MENU, palette, COORD{5, 5});

    const int N_TIMES = 5;
    List list;

    while(true) {
        try {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;

        cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
            // проверка команды add() - добавление элементов в конец списка
            case CMD_ADD:
            for (int i = 0; i < N_TIMES; i++) {
                cout<< pos(4, 5) << "Список:                    "
            	    << pos(12, 5) << list;
            	
                int value = getRand(-100, 100);
                list.add(value);
                Sleep(500);
            } // for i
            break;    

            // проверка команды insert - вставка в список перед заданной позицией
            case CMD_INSERT:
            cout<< "    Список: " << list;
            Sleep(1000);

            list.insert(0, 111);
            cout<< "\r    Список: " << list;
            Sleep(1000);
            
            list.insert(list.getCount()-1, 333);
            cout<< "\r    Список: " << list;
            Sleep(1000);
            
            list.insert(list.getCount()-1, 999);
            cout<< "\r    Список: " << list << "\n\n";
            break;

        	// Проверка операций get(), put()
            case CMD_GET_PUT:
                cout << "\n\n    Список: " << list << "\n\n";
                cout << "    " << list.get(0) << "     "
        	         << list.get(list.getCount() - 1) << "\n\n";

                list.put(0, 999);
                list.put(list.getCount() - 1, 888);
                cout << "\n\n    Список: " << list << "\n\n";
        	break;

            // проверка команды clear - очистка списка
            case CMD_CLEAR:
            cout<< "    Список: " << list << "\n\n";
            list.clear();
            cout<< "    Список: " << list << "\n\n";
            break;
        } // switch
        } catch (exception &ex) {
            cout << "\n\n" << ex.what() << "\n\n";
        } // try-catch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main