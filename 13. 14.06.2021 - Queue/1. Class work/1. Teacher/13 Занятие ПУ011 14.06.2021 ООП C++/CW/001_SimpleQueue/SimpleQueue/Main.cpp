/*
 * Простая очередь на базе статического массива 
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
	init(L"Занятие 14.06.2021 - простая очередь на базе статического массива");

	// коды команд
    enum Commands {
    	CMD_ONE,      // Проверка операции enqueue()
    	CMD_TWO,      // Проверка операции enqueueAll()
    	CMD_THREE,    // Проверка операции dequeue()
    	CMD_FOUR,     // Проверка разных операций    
    	CMD_FIVE      // Проверка операции checkClear()
    };

	// массив пунктов меню
    const int N_MENU = 6;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка операции enqueue()", CMD_ONE),
        MenuItem("Проверка операции enqueueAll()", CMD_TWO),
        MenuItem("Проверка операции dequeue()", CMD_THREE),
        MenuItem("Проверка разных операций", CMD_FOUR),
        MenuItem("Проверка операции checkClear()", CMD_FIVE),
        MenuItem ("Выход",  Menu::CMD_QUIT) 
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
            showNavBarMessage(hintColor, "  Работа с контейнером объектов");
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            switch (cmd) {
            // Выполнение первой команды
            case CMD_ONE:
                app->checkEnqueue();
                break;

            // Выполнение второй команды
            case CMD_TWO:
                app->checkEnqueueAll();
                break;

            // Выполнение третьей команды
            case CMD_THREE:
                app->checkDequeue();
                break;
            	
            // Выполнение второй команды
            case CMD_FOUR:
                app->checkMisc();
                break;

            // Выполнение третьей команды
            case CMD_FIVE:
                app->checkClear();
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