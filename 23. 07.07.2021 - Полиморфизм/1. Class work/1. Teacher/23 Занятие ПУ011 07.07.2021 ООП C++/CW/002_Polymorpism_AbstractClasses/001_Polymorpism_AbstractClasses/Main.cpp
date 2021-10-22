/*
 * Полиморфизм
 * Абстрактные классы
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
	init(L"Занятие 07.07.2021 - полиморфизм, абстрактные классы");

	// коды команд
    enum Commands {
    	CMD_ONE,      // Полиморфные классы
    	CMD_TWO,      // Абстрактные классы
    	CMD_THREE     // Сортировка
    };

	// массив пунктов меню
    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem ("Полиморфные классы", CMD_ONE), 
        MenuItem ("Абстрактные классы", CMD_TWO), 
        MenuItem ("Сортировка", CMD_THREE), 
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
            // Полиморфные классы
            case CMD_ONE:
                app->point1();
                break;

            // Абстрактные классы
            case CMD_TWO:
                app->point2();
                break;

            // Сортировка
            case CMD_THREE:
                app->point3();
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