// Пример записи объекта в бинарный файл, чтения объекта из бинарного файла 
//

#include "pch.h"
#include "App.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Palette.h"

int main()
{
    init(L"Занятие 30.06.2021 - запись в бинарный файл/чтение из бинарного файла");

    ostringstream oss;

    enum Commands {

        CMD_TASK1, CMD_TASK2, CMD_TASK3, CMD_RW_PERSONS, CMD_QUIT
    };

    const int N_MENU = 4;
    MenuItem items[N_MENU] = {
        MenuItem("Задача 1. Двунаправленный итератор для двухсвязного списка", CMD_TASK1),
        MenuItem("Задача 2. Очереди", CMD_TASK2),
        MenuItem("Демонстрация записи в бинарный файл/чтения из бинарного файла", CMD_RW_PERSONS),
        

        MenuItem("Выход",  Menu::CMD_QUIT),
    };

    const int N_PALETTE = 5;
    short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{ 5, 5 });


    App app;

    while (true) {
        try {
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            switch (cmd)
            {
            case CMD_TASK1:
                app.task1();
                break;

            case CMD_TASK2:
                app.task2();
                break;

            case CMD_RW_PERSONS:
                app.ReadWritePersons();
                break;

            } // switch

            cout << endlm(2);
            getKey();
        }
        catch (exception& ex) {

            oss.str("");  // очистка строки - буфера вывода
            oss << "\n\t" << ex.what() << "\n";

            // вывод строки с сообщением об ошибке в цвете
            cputs(oss.str().c_str(), errColor);
            getKey();


            // что на самом деле происходит
            // string temp = oss.str();
            // cputs(temp.c_str(), errColor);
        } // try-catch

    } // while

    cout << cls << pos(0, 24);
    //getKey();

    return 0;


} // main
