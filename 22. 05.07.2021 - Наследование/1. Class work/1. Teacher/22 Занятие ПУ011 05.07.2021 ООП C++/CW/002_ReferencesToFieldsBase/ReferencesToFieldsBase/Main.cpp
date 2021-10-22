// Ссылки на поля базового класса в производном классе

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Triad.h"
#include "Time.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 05.07.2021. Использование ссылок на поля базового класса в производном классе");

    // коды команд приложения
    enum Commands {
        CMD_TRIAD, CMD_TIME
    };

    // пункты меню приложения
    const int N_MENU = 3;
    MenuItem items[N_MENU] = {
        MenuItem ("Демонстрация работы класса Triad", CMD_TRIAD), 
        MenuItem ("Демонстрация работы класса Time", CMD_TIME), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});
	Triad triad(10, 20, 30);
	Time time(21, 40, 58);

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd) {
            case CMD_TRIAD:
			cout<< endlm(3)
        	    << "    Размер класса Triad: " << sizeof(Triad) << "\n"
        	    << "    Размер класса Time : " << sizeof(Time) << "\n"
        	    << "    Размер типа   int& : " << sizeof(int &) << "\n\n\n"
        	    << "    Исходное состояние объекта класса Triad: " << triad << "\n\n"
        	    << "    Увеличение полей объекта базового класса...\n\n";
        	triad.incA();
        	triad.incB();
        	triad.incC();
			cout<< "    Поля объекта класса Triad изменены     : " << triad << endlm(4);
            break;    
        
            case CMD_TIME:
			cout<< endlm(3)
        	    << "    Исходное состояние объекта класса Time:\n"
        	    << "    time = " << time << endlm(2);
			cout << "    Увеличение полей объекта производного класса методами базового класса:\n";
        	time.incA();
        	time.incB();
        	time.incC();
        
			cout << "    time = " << time << endlm(2);

			cout << "    Увеличение полей объекта производного класса методами производного класса:\n";
			time.incSeconds();
			time.incMinutes();
			time.incHours();
            cout << "    time = " << time << endlm(4);
        	break;    
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main