/*
 * Знакомство с бинарным деревом
 * 
 */


#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "App.h"
#include "Palette.h"


int main()
{
	// настройка вывода в консоль
	init(L"Занятие 01.07.2021 - бинарное дерево поиска");

    // коды команд приложения
    enum Commands {
        CMD_ADD_DATA,   // добавить узел или значение в дерево
    	CMD_SHOW_TREE,  // показать данные дерева
    	CMD_FIND_TREE   // поиск в дереве
    };

    // пункты меню приложения
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem("Добавление данных в бинарное дерево", CMD_ADD_DATA),
        MenuItem("Просмотр бинарного дерева", CMD_SHOW_TREE),
        MenuItem("Поиск в бинарном дереве", CMD_FIND_TREE),
        MenuItem("Выход",  Menu::CMD_QUIT),
    };

	// палитра вывода меню
    const int N_PALETTE = 5;
	//                          заголовок       пункт меню       выбранный пункт  текст консоли  
    short palette[N_PALETTE] = {arrColor, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, mainColor};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

	// Объект класса для обработки по заданию
    App *app = new App();   
    
    while(true) {
        try {
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            showNavBarMessage(hintColor, "  Работа с бинарным деревом");
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            switch (cmd) {
            // Добавление данных в бинарное дерево
            case CMD_ADD_DATA:
                app->demoAdd();
                break;

            // Просмотр бинарного дерева
            case CMD_SHOW_TREE:
                app->demoShowTree();
                break;

            // Поиск в бинарном дереве
            case CMD_FIND_TREE:
                app->demoFindTree();
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
	
    delete app;
	return 0;
} // main