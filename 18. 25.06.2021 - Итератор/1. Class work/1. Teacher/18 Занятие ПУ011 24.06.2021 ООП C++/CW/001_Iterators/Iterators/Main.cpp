/*
 * Итераторы для контейнеров данных
 * Прямые и двунаправленные итераторы
 */
#include "App.h"
#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "List.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 21.06.2021 - понятие об итераторах");

    // коды команд приложения
    enum Commands {
        CMD_ONE,   // Проверка списка List<char>
    	CMD_TWO,    // Проверка итератора List<char>::Iterator<char>
    	CMD_THREE    // Проверка итератора Stack<int>::Iterator<int
    };

    // пункты меню приложения
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка списка List<char>", CMD_ONE), 
        MenuItem ("Проверка итератора List<char>::Iterator<char>", CMD_TWO), 
        MenuItem ("Проверка итератора Stack<int>::Iterator<int>", CMD_THREE), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Работа с односвязным списком и его итератором", items, N_MENU, palette, COORD{5, 5});

    const int N_CHAR_ARR = 6;
    char arrChar[N_CHAR_ARR] = {'ж', 'ш', 'ы', 'z', 'j', 'w'};

	// ---------------------------------------------------------
    /*
    // пример итерации по массиву символов
	// указатель на массив - играет роль объекта, реализующего цикл, роль итератора
	// !!! прямой итератор !!!
	for (char* p = arrChar, *p0 = arrChar; p != p0+N_CHAR_ARR; ++p) {
        cout << *p << " ";
    } // for p
    cout << "\n";

	// !!! цикл с итератором - неявно реализует "механику" первого примера !!!
    for (char c: arrChar) {
        cout << c << " ";
    }
    cout << "\n";
	
	for (int i = 0; i < N_CHAR_ARR; ++i) {
        // cout << i[arrChar] << " ";   
        cout << arrChar[i] << " ";
	}
    cout << "\n";

	// пример обратного итератора по массиву - при помощи указателя 
    for (char* p = arrChar+N_CHAR_ARR-1; p != arrChar-1; --p) {
        cout << *p << " ";
    } // for p
    cout << "\n";
    getKey();
    */
	// ----------------------------------
    List<char> charList(arrChar, N_CHAR_ARR);

    App *app = new App(charList);

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        showNavBarMessage(hintColor, "  Работа с итераторами коллекций");
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;

        cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
        	// Проверка списка List<char>
            case CMD_ONE:
                app->checkListMethods();
            break;
        	
            // Проверка итератора List<char>::Iterator<char>
            case CMD_TWO: {
                app->checkListIterator();
            } break;
        	
            // Проверка итератора Stack<int>::Iterator<int>
            case CMD_THREE: {
                app->checkStackIterator();
            } break;    
        } // switch

        cout << "\n\n\n    Нажмите любую клавишу для продолжения..." << cursor_on;
        getKey("");
        cout << cursor_off;
    } // while

    cout << cls << pos(0,24) << "    Нажмите любую клавишу для продолжения..." << cursor_on;
    getKey("");

    delete app;
	return 0;
} // main