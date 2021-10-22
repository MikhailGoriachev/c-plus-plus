/*
 * Реализация операций с двусвязным списком - выполнение части
 * домашнего задания на 17.06.2021
 *
 * Разработайте шаблонный класс DblList – двухсвязный список) – конструкторы,
 * деструктор. Разработайте консольное приложение, в котором продемонстрируйте
 * операции со списком для типов int, char, Car (из задачи о парковке, поля
 * класса – регистрационный номер, цвет, бренд). 
 *
 * Операции для реализации:
 *     • Перегруженная операция вывода списка
 *     • Перегруженная операция присваивания
 *     • add(value)              – добавление элемента в конец списка
 *     • insert(position, value) – добавление элемента перед заданной
 *                                 позицией списка
 *     • removeAt(position)      – удаление элемента списка в заданной позиции,
 *                                 возвращает удаляемый элемент
 *     • get(position)           – получение элемента списка в заданной позиции
 *     • put(position, value)    – запись нового значения в существующий
 *                                 элемент списка в заданной позиции position
 *     • clear()                 – очистка списка
 * 
 */

#include "App.h"
#include "pch.h"

#include "DblList.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 23.06.2021 - двусвязный список, основные операции");

	// класс приложения
    App* app = new App();
	
    // коды команд приложения
    enum Commands {
        CMD_ADD,     // Проверка метода add()
    	CMD_INSERT,  // Проверка метода insert()
    	CMD_GET_PUT, // Проверка методов get(), put()
    	CMD_REMOVE,  // Проверка метода removeAt()
    	CMD_CLEAR    // Проверка метода clear()
    };

    // пункты меню приложения
    const int N_MENU = 6;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка метода add()", CMD_ADD), 
        MenuItem ("Проверка метода insert()", CMD_INSERT), 
        MenuItem ("Проверка методов get(), put()", CMD_GET_PUT), 
        MenuItem ("Проверка метода removeAt()", CMD_REMOVE), 
        MenuItem ("Проверка метода clear()", CMD_CLEAR), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Разработка двусвязного списка", items, N_MENU, palette, COORD{5, 5});
    DblList<int> intList;

    while(true) {
        try {
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            showNavBarMessage(hintColor, "  DblLinkedList: двусвязный список, основные операции");
            int cmd = mainMenu.Navigate();
            cout << color(palette[Menu::PAL_CONSOLE]) << cls;
            if (cmd == Menu::CMD_QUIT) break;

            switch (cmd) {
            // Проверка метода add()
            case CMD_ADD:
                app->testAdd();
                break;

            // Проверка метода insert()	
            case CMD_INSERT:
                app->testInsert();
                break;

            // Проверка методов get(), put()	
            case CMD_GET_PUT:
                app->testGetPut();
                break;

            // Проверка метода removeAt()	
            case CMD_REMOVE:
                app->testRemoveAt();
                break;

            // Проверка метода clear()	
            case CMD_CLEAR:
                app->testClear();
                break;
            } // switch
        } catch (exception & ex) {
            cout<< "    " << color(acctColor) << "    " << ex.what() << "    "
                << color(mainColor);
        } // try-catch
        getKey("\n\n\n    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

    delete app;
	return 0;
} // main