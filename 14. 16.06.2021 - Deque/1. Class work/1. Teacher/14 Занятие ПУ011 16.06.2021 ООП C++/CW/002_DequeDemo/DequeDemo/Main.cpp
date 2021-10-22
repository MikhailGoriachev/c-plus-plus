// Реализация структуры данных - дек (deque - Double Ended QUEue)

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Deque.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 16.06.2021 - работа с деком");

    // коды команд приложения
    enum Commands {
        CMD_SHIFT,     // запись в начало дека
    	CMD_SHIFTALL,  // запись массива в начало дека
    	CMD_UNSHIFT,   // доступ к началу дека
    	CMD_PUSH,      // запись в конец дека
    	CMD_PUSHALL,   // запись массива в конец дека
        CMD_POP,       // доступ к концу дека
    	CMD_CLEAR      // очистка дека
    };

    // пункты меню приложения
    const int N_MENU = 8;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка команды shift - запись в начало дека", CMD_SHIFT), 
        MenuItem ("Проверка команды shiftAll - запись массива в начало дека", CMD_SHIFTALL), 
        MenuItem ("Проверка команд unshift, front - доступ к началу дека", CMD_UNSHIFT), 
        MenuItem ("Проверка команд push - запись в конец дека", CMD_PUSH), 
        MenuItem ("Проверка команд pushAll - запись массива в конец дека", CMD_PUSHALL), 
        MenuItem ("Проверка команд pop, back - доступ к концу дека", CMD_POP), 
        MenuItem ("Проверка команды clear - очистка дека", CMD_CLEAR), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Изучение динамической структуры \"дек\"", items, N_MENU, palette, COORD{5, 5});
    
    // дек целых чисел и данные для работы с деком
    Deque deque;
    int arr[] {12, -34, 56, -12, 6};
    int value;

    while(true) {
        try {
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            showNavBarMessage(hintColor, "  Работа с деком целых чисел");
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            cout << endlm(3) << "    " << items[cmd].text;

            switch (cmd) {
                case CMD_SHIFT:
                    showNavBarMessage(hintColor, "  Операция shift дека");
					cout<< endlm(4)
						<< "    Дек до операции shift      : " << deque << "\n\n";
					deque.shift(getRand(-100, 100));
					cout<< "    Дек после операции shift   : " << deque << endlm(3);
                break;

                case CMD_SHIFTALL:
                    showNavBarMessage(hintColor, "  Операция shiftAll дека");
            	
                    cout<< endlm(4)
						<< "    Дек до операции shiftAll   : " << deque << "\n\n";
					deque.shiftAll(arr, sizeof(arr) / sizeof(int));
					cout<< "    Массив для вставки         : ";

					for (int element : arr) cout << setw(5) << element; cout << "\n\n";
					cout<< "    Дек после операции shiftAll: " << deque << endlm(3);
                break;

                case CMD_UNSHIFT:
                    showNavBarMessage(hintColor, "  Операция unshift дека");
                    cout<< endlm(4)
                        << "    Дек до операции front     : " << deque << "\n\n";
                    value = deque.front();
                    cout<< "    В начале дека             : " << setw(5) << value << "\n\n"
                        << "    Дек после операции front  : " << deque << "\n\n";
                    
                    value = deque.unshift();
                    cout<< "    Из начала дека извлечено  : " << setw(5) << value << "\n\n"
                        << "    Дек после операции unshift: " << deque << endlm(3);
                break;    

                case CMD_PUSH:
                    showNavBarMessage(hintColor, "  Операция push дека");
                    cout<< endlm(4)
                        << "    Дек до операции push   : " << deque << "\n\n";
                    deque.push(getRand(-100, 100));
                    cout<< "    Дек после операции push: " << deque << endlm(3);
                break;                
                
                case CMD_PUSHALL:
                    showNavBarMessage(hintColor, "  Операция pushAll дека");
                    cout<< endlm(4)
                        << "    Дек до операции pushAll   : " << deque << "\n\n";
                    deque.pushAll(arr, sizeof(arr) / sizeof(int));
                    cout<< "    Массив для вставки        : ";
                    
                    for (int element : arr) cout << setw(5) << element; cout << "\n\n";
                    cout<< "    Дек после операции pushAll: " << deque << endlm(3);
                break;          
                
                case CMD_POP:
                    showNavBarMessage(hintColor, "  Операция pop дека");
                    cout<< endlm(4)
                        << "    Дек до операции back    : " << deque << "\n\n";
                    value = deque.back();
                    cout<< "    В хвосте дека           : " << setw(5) << value << "\n\n"
                        << "    Дек после операции back : " << deque << "\n\n";
                    
                    value = deque.pop();
                    cout<< "    Из хвоста дека извлечено: " << setw(5) << value << "\n\n"
                        << "    Дек после операции pop  : " << deque << endlm(3);
                break;         
                
                case CMD_CLEAR:
                    showNavBarMessage(hintColor, "  Операция clear дека");
                    cout<< endlm(4)
                        << "    Дек до операции clear   : " << deque << "\n\n";
                    deque.clear();
                    cout<< "    Дек после операции clear: " << deque << endlm(3);
                break;
            } // switch
        } catch (exception &ex) {
            cout<< color(LTRED_ON_WHITE) << endlm(2)
                << "\t    " << ex.what() << "    "
                << color(palette[Menu::PAL_CONSOLE]) << endlm(3);
        } // try-catch

        cout << endlm(3);
        getKey();
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main