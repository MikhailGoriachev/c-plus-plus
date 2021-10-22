// Демонстрация методов работы с очередью

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Queue.h"

int main()
{
	// настройка вывода в консоль
	init(L"12.06.2021 - работа с очередью");

    // TODO: проверка всех методов очереди
    // коды команд приложения
    enum Commands {
        CMD_ENQUEUE,
    	CMD_ENQUEUE_ALL,
    	CMD_DEQUEUE
    };

    // пункты меню приложения
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка добавления в очередь элемента", CMD_ENQUEUE), 
        MenuItem ("Проверка добавления в очередь массива элементов",CMD_ENQUEUE_ALL), 
        MenuItem ("Проверка извлечения из очереди", CMD_DEQUEUE), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});
    Queue queue;

    while(true) {
        try {
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            showNavBarMessage(hintColor, "  Работа с очередью целых чисел");
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            int x, arr[] {3, 6, 7, -7, -6, -3};

            switch (cmd) {
                case CMD_ENQUEUE:
                    showNavBarMessage(hintColor, "  Добавление элемента в очередь");

            	    cout << "\n\n\n\n    До добавления   : " << queue << "\n";
                    x = getRand(-100, 100);
                    cout << "    Добавляется     : " << setw(5) << x << "\n";
                    queue.enqueue(x);
                    cout << "    После добавления: " << queue << "\n\n\n"; 
                break;    
            
                case CMD_ENQUEUE_ALL:
                    showNavBarMessage(hintColor, "  Добавление элементов в очередь");
                    cout << "\n\n    До добавления   : " << queue << "\n"; 
                    queue.enqueueAll(arr, sizeof(arr) / sizeof(int));
                    cout << "    После добавления: " << queue << "\n\n\n"; 
                break;    

                case CMD_DEQUEUE:
                    showNavBarMessage(hintColor, "  Удаление элемента из очереди");
                    cout << "\n\n    До удаления   : " << queue << "\n"; 
                    x = queue.dequeue();
                    cout << "    После удаления: " << queue << "\n";
                    cout << "    Удален элемент " << x << "\n\n\n";
                break;
            } // switch
        } catch (exception &ex) {
            cout<< endlm(3) << color(RED_ON_WHITE)
                << "\t   " << ex.what() << "    \n"
                << color(palette[Menu::PAL_CONSOLE]);
        } // try-catch

        cout << endlm(3);
        getKey();
    } // while
  
   
    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main