/*
 * Знакомство с динамическимим структурами данных
 * Стек - stack на базе статического массива
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
	init(L"Занятие 10.06.2021 - динамические структуры данных, стек");

	// коды команд
    enum Commands {
    	CMD_ONE,      // Проверка стека int
    	CMD_TWO,      // Проверка стека Triangle
    	CMD_THREE     // Пример решения задачи на стеках int
    };

	// массив пунктов меню
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка стека int", CMD_ONE), 
        MenuItem ("Проверка стека Triangle", CMD_TWO), 
        MenuItem ("Пример решения задачи на стеках int", CMD_THREE), 
        MenuItem ("Выход",  Menu::CMD_QUIT) 
    };

	// палитра вывода меню
    const int N_PALETTE = 5;
	//                          заголовок       пункт меню       выбранный пункт  текст консоли  
    short palette[N_PALETTE] = {arrColor, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, mainColor};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

	// Объект класса для обработки данных по заданию
    App *app = new App();   
    
    while(true) {
        try {
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            showNavBarMessage(hintColor, "  Работа со стеками");
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            switch (cmd) {
            // Проверка стека
            case CMD_ONE:
                app->checkStack();
                break;

            // Выполнение второй команды
            case CMD_TWO:
                app->checkStackTriangle();
                break;

            // Пример решения задачи на стеках int
            case CMD_THREE:
                app->task();
                break;
            } // switch

        } catch (exception &ex) {
            setColor(mainColor);
            cls();
            showNavBarMessage(hintColor, "  Ошибка приложения, нажмите любую клавишу для продолжения...");

            // в эту секцию передается управление оператором throw
            const char* msg[] = {
                " ",
                "    [Ошибка]",
                ex.what(),
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