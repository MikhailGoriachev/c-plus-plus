// STL - Standart Template Library
//       1. потоки ввода/вывода   -  fstream<char>, wfstream<wchar_t>
//       2. строки                - класс string<char>, wstring<wchar_t>  
//       3. контейнеры            - классы vector, deque, list, stack, queue, tree, map, ...
//       4. алгоритмы, функторы   - вычислительные объекты, итераторы

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "App.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 14.07.2021 - знакомство с классом string из STL");

    // коды команд приложения
    enum Commands {
        CMD_ONE, CMD_TWO, CMD_THREE, CMD_FOUR, CMD_FIVE
    };

    // пункты меню приложения
    const int N_MENU = 6;
    MenuItem items[N_MENU] = {
        MenuItem ("Конструкторы строк, операции со строками", CMD_ONE), 
        MenuItem ("Информационные методы строк", CMD_TWO), 
        MenuItem ("Обрабатывающие методы", CMD_THREE), 
        MenuItem ("Запись в файлы, чтение из файлов", CMD_FOUR), 
		MenuItem ("Дополнительные методы поиска в строке", CMD_FIVE), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    //                                заголовок       пункт            выбранный пункт  консоль
    short palette[Menu::N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});
    App* app = new App();
	
    // Главный цикл приложения
    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        showNavBarMessage(hintColor, "  STL. Работа со строками - класс string");
    	int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
            case CMD_ONE:
				app->doDemoConstructors();
            break;    
        
            case CMD_TWO:
                app->doDemoInfo();
            break;    

            case CMD_THREE:
                app->doDemoMethods();
            break;

        	case CMD_FOUR:
                app->doDemoFiles();
            break;
			
			case CMD_FIVE:
                app->doDemoFind();
            break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main