// Лямбда-выражения в C++
// Это компактная форма записи анонимного функтора
// 
// Синтаксис лямбда-выражения
// [списокЗахвата](параметрыВыражения)->типВозвращаемогоЗначения
// mutable  -- изменение копий переменных из списка захвата в лямбда-выражении
// {
//     операторы;
//     return значение;
// }

// Простейшее лямбда-выражение [](){}

#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include <vector>
#include <algorithm>

void show(string title, vector<int> vector1);
void show(string title, int* arr, int n);

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 21.07.2021 - лямбда-выражения в C++");

    // коды команд приложения
    enum Commands {
        CMD_ONE,     // Унарная функция - лямбда-выражение
        CMD_TWO,     // Унарный предикат - лямбда-выражение 
        CMD_THREE,   // Лямбда-выражение со списком захвата
        CMD_FOUR,    // Бинарная функция - лямбда-выражение
        CMD_FIVE     // Бинарный предикат - лямбда-выражение 
    };

    // пункты меню приложения
    const int N_MENU = 6;
    MenuItem items[N_MENU] = {
        MenuItem ("Унарная функция - лямбда-выражение", CMD_ONE), 
        MenuItem ("Унарный предикат - лямбда-выражение", CMD_TWO), 
        MenuItem ("Лямбда-выражение со списком захвата", CMD_THREE), 
        MenuItem ("Бинарная функция - лямбда-выражение", CMD_FOUR), 
        MenuItem ("Бинарный предикат - лямбда-выражение", CMD_FIVE), 
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {hintColor, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, mainColor};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

	// для демонстрации необходимы векторы с заданной длиной
    int n = getRand(5, 12);
    vector<int> v1(n);
    vector<int> v2(n);
    vector<int> v3(n);

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        showNavBarMessage(hintColor, "  Введение в лямбда-выражения");
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;
		
		cout << endlm(3) << "    " << items[cmd].text << endlm(3);

        switch (cmd)
        {
        	// Унарная функция - лямбда-выражение
            case CMD_ONE: {
            	// генерация случайных чисел в векторе
            	/*
            	class Random
            	{
            	public:
                    int operator()() { return getRand(-10, 10); }
            	};

                generate(v1.begin(), v1.end(), Random());
                */
                generate(v1.begin(), v1.end(), []() {return getRand(-10, 10); });
            	show("    Вектор: ", v1);
	        }
            break;    

            // Унарный предикат - лямбда-выражение
            case CMD_TWO: {
            	// найти первый отрицательный элемент в векторе
                generate(v1.begin(), v1.end(), []() {return getRand(-10, 10); });
                show("    Вектор: ", v1);

            	// собственно поиск:
                auto it = find_if(v1.begin(), v1.end(), 
                    [](int x) { return x < 0; });
                if (it != v1.end())
                    cout << "    первый отрицательный: " << *it << "\n";
                else
                    cout << "    В векторе нет отрицательных элементов\n";
            }
            break;    

            // Лямбда - выражение со списком захвата
            case CMD_THREE: {
            	// генерация случайных чисел заданного диапазона в векторе	
                int lo = -50, hi = 35;
            	// !!! generate() требует функтора без параметров !!!
                generate(v1.begin(), v1.end(), [lo, hi]() mutable {lo -= 10; return getRand(lo, hi); });
                // generate(v1.begin(), v1.end(), [&lo, hi]() {lo -= 10; return getRand(lo, hi); });
                show("    Вектор: ", v1);
                // cout << "    lo = " << lo << "\n";
            }
            break;

            // Бинарная функция - лямбда-выражение
            case CMD_FOUR: {
            	// поэлементная сумма двух одинаковых по длине векторов
                int lo = -10, hi = 10;
                auto lambda = [lo, hi]() {  return getRand(lo, hi); };
                generate(v1.begin(), v1.end(), lambda);
                show("    v1: ", v1);

                generate(v2.begin(), v2.end(), lambda);
                show("    v2: ", v2);

                // ---- бинарная функция в лямбде
                transform(v1.begin(), v1.end(), v2.begin(), v3.begin(),
                    [](int item1, int item2) { return item1 + item2; }
                );

                show("    v3: ", v3);
            }
            break;

            // Бинарный предикат - лямбда-выражение
            case CMD_FIVE: {
                // сортировка вектора
                int lo = -10, hi = 10;
                generate(v1.begin(), v1.end(), [lo, hi]() {  return getRand(lo, hi); });
                show("    v1 до сортировки: ", v1);

                sort(v1.begin(), v1.end(), [](int x, int y) { return x > y; });
                show("    v1 по убыванию  : ", v1);

            	// сортировка вектора по возрастанию модулей
                random_shuffle(v1.begin(), v1.end());
                show("    v1 перепутан               : ", v1);
                sort(v1.begin(), v1.end(),
                    [](int x, int y) { return abs(x) < abs(y); });
                show("    v1 по возрастанию модулей  : ", v1);
            		
                // обработка массива
                cout << "\n    массив: ";
                int* arr = new int[n];
                generate(arr, arr + n, [lo, hi]() { return getRand(lo, hi); });
                sort(arr, arr + n, [](int x, int y) { return x > y; });
                // for_each(arr, arr + n, [](int x) {cout << setw(6) << x; });
                show("\n    массив отсортирован: ", arr, n);
                cout << "\n";

                delete[] arr;
            }
            break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main

// вывод вектора в консоль
void show(string title, vector<int> vector1)
{
    cout << title;
    for_each(vector1.begin(), vector1.end(), [](int x)
        {
            cout << color(x < 0 ? hintColor : mainColor) << setw(4) << x << " "
                << color(mainColor) << " ";
        });
    cout << "\n";
} // show

// вывод массива в консоль
void show(string title, int *arr, int n)
{
    cout << title;
    for_each(arr, arr+n, [](int x)
        {
            cout << color(x < 0 ? hintColor : mainColor) << setw(4) << x << " "
                << color(mainColor) << " ";
        });
    cout << "\n";
} // show