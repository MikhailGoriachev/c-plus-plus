// Напишите консольное приложение для демонстрации всех разработанных методов и 
// перегруженных операций. В этом приложении разработайте функции поиска 
// индекса первого треугольника в массиве с минимальной площадью, последнего 
// треугольника в массиве с максимальной площадью.
// Продемонстрируйте работу функций поиска минимального и максимального элементов.
// Обязательно используйте меню из предыдущих проектов для демонстрации работы 
// Вашего приложения.


#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "Figures.h"
#include "App.h"

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 07.06.2021 - работа с массивом объектов, перегрузка операций");

	enum Commands {
    	CMD_GENER, CMD_VIEW, CMD_ORDER, CMD_ORDER_BY_NAME, CMD_ORDER_BY_SIDE_A, CMD_INDEX_BY_NAME,
    	CMD_ADD_ITEM, CMD_DEL_ITEM, CMD_INS_ITEM
    };

    const int N_MENU = 8;
    MenuItem items[N_MENU] = {
        MenuItem ("Сформировать новый объект Figures", CMD_GENER), 
        MenuItem ("Просмотр объекта Figures", CMD_VIEW), 
        MenuItem ("Сортировка массива треугольников в Figures по площади", CMD_ORDER), 
        MenuItem ("Сортировка массива треугольников в Figures по имени", CMD_ORDER_BY_NAME), 
        MenuItem ("Сортировка массива треугольников в Figures по стороне A", CMD_ORDER_BY_SIDE_A), 
        MenuItem ("Индексирование массива по имени треугольника в Figures", CMD_INDEX_BY_NAME), 
        MenuItem ("Добавление элемента в массив треугольников Figures", CMD_ADD_ITEM), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

    // Объект с массивом треугольников
    const int N_TRIANGLES = 10;
    Triangle triangles[N_TRIANGLES] = {
        Triangle(3, 4, 5),
        Triangle(12, "DEF"),
        Triangle(7, 8, 5, "ZXE"),
        Triangle(8, "WEB"),
        Triangle(3, "BRE"),
        Triangle(5, 8, 6, "JKL"),
        Triangle(10, 12, 8, "KFC"),
        Triangle(3, "UVT"),
        Triangle(12, "MET"),
        Triangle(8, 11, 9, "YOU")
    };
    Figures figures(triangles, N_TRIANGLES);
    
    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls; 
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;

        switch (cmd)
        {
            case CMD_GENER:
            figures.setData(triangles, N_TRIANGLES);
            showTable(figures, "Сформирован массив треугольников:\n");
            break;    
        
            case CMD_VIEW:
            showTable(figures, "Массив треугольников:\n");
            break;    

            case CMD_ORDER:
            figures = ~figures;
            showTable(figures, "Элементы в массиве треугольников упорядочены по возрастанию площадей:\n");
            break;

        	// Сортировка массива треугольников в Figures по имени
            case CMD_ORDER_BY_NAME:
        	figures = figures % compareByName;
            showTable(figures, "Элементы в массиве треугольников упорядочены по имени:\n");
            break;

        	// Сортировка массива треугольников по стороне A
            case CMD_ORDER_BY_SIDE_A:
        	figures = figures % compareBySideA;
            showTable(figures, "Элементы в массиве треугольников упорядочены по стороне A:\n");
            break;
        	
            // индексирование по имени треугольника
            case CMD_INDEX_BY_NAME:
            demoIndexByName(figures);
            break;

            // добавление элемента в в конец массива
            case CMD_ADD_ITEM:
            demoAddItem(figures);
            break;
        } // switch

        cout << endlm(2);
        getKey();
    } // while
	
    cout << cls << pos(0,24);
    getKey();
    
	return 0;
} // main