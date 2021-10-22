#include "pch.h"
#include "Utils.h"
#include "MenuItem.h"
#include "Menu.h"
#include "ClassA.h"
#include "List.h"
#include "Goods.h"
#include "Stack.h"
#include "Plane.h"

// служебные методы для вывода контейнеров - шаблонных классов,
// закрытых типом Goods
void showListGoods(const char *title, const List<Goods> &listGoods);
void showStackGoods(const char *title, const Stack<Goods> &stackGoods);

int main()
{	
	// настройка вывода в консоль
	init(L"Занятие 21.06.2021 - шаблонные классы, применение шаблонных классов");

    // коды команд приложения
    enum Commands {
        CMD_CLASS_A, CMD_СLASS_A1, CMD_CLASS_A2,
        CMD_LIST_INT, CMD_LIST_CHAR, CMD_LIST_GOODS,
        CMD_STACK_INT, CMD_STACK_CHAR, CMD_STACK_GOODS
    };

    // пункты меню приложения
    const int N_MENU = 10;
    MenuItem items[N_MENU] = {
        MenuItem ("Проверка класса ClassA на типах int, double", CMD_CLASS_A), 
        MenuItem ("Проверка класса ClassA на типах float, int", CMD_СLASS_A1), 
        MenuItem ("Проверка класса ClassA на типах char, bool", CMD_CLASS_A2),
        MenuItem ("Проверка класса List на типе int", CMD_LIST_INT),
        MenuItem ("Проверка класса List на типе char", CMD_LIST_CHAR),
        MenuItem ("Проверка класса List на типе Goods", CMD_LIST_GOODS),
        MenuItem ("Проверка класса Stack на типе int", CMD_STACK_INT),
        MenuItem ("Проверка класса Stack на типе char", CMD_STACK_CHAR),
        MenuItem ("Проверка класса Stack на типе Goods", CMD_STACK_GOODS),
        MenuItem ("Выход",  Menu::CMD_QUIT), 
    };

    const int N_PALETTE = 5;
    //                          заголовок       пункт            выбранный пункт  консоль
    short palette[N_PALETTE] = {WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK};

    Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{5, 5});

    // объявление переменной с шаболонным типом - должно использовать явные
    // типы, которыми "закрывается" шаблон
	// T == int   V == double
    ClassA<int, double> classA(-1, M_PI, 101);

	// T == float  V == int
	ClassA<float, int> classA1(-1.f, 3, 10.1f);

    // T == char  V == bool
	ClassA<char, bool> classA2('z', true, 'w');

    const int N_INT_ARR = 5;
    int arrInt[N_INT_ARR] = {11, -12, 34, 89, 90};
    List<int> intList(arrInt, N_INT_ARR);  

    const int N_CHAR_ARR = 6;
    char arrChar[N_CHAR_ARR] = {'ж', 'ш', 'ы', 'z', 'j', 'w'};
    List<char> charList(arrChar, N_CHAR_ARR);

     // список товаров для формирования чека
    const int N_ARR_GOODS = 5;
    Goods arrGoods[N_ARR_GOODS] = {
        Goods(8001, "сахар песок", 43., 3),
        Goods(9500, "мука пшеничная", 45., 1),
        Goods(7588, "сок яблочный", 65., 2),
        Goods(1252, "тарелка пластиковая", 5., 20),
        Goods(6522, "кинокамера импортная", 15000., 1)
    };
    List<Goods> goodsList(arrGoods, N_ARR_GOODS);

	// Массив самолетов
	Plane planes[10] = {
		Plane("SSJ-100-95LR",    100,  12, 2296.,  5100, "HK-NIW"),
		Plane("МС-21-300UL",     200,  19, 2265.,  5400, "RA56155"),
		Plane("Boeing 777-300ER",365, 267, 7800., 15400, "VP-CDD"),
		Plane("Ил-76Т",            0,   0, 8262.,  6300, "HK-LOW"),
		Plane("Бе-200ЧС",          0,   0, 1540.,  5400, "RA77689"),
		Plane("ATR-72-600",       74,  32,  580.,  2100, "RA26211"),
		Plane("Ил-96-300",       300, 212, 7800., 12000, "YS-TOR"),
		Plane("Fokker-100",      107,  18, 2150.,  2800, "XU-BOM"),
		Plane("Falcon 7X",        19,   1,  318., 12100, "RF11221"),
		Plane("L-410UVP",         19,   9,  247.,  1040, "XU-ATT"),
	};
	List<Plane> planesList(planes, 10);
	

    // Стеки для проверки работы шаблонного Stack<>
    Stack<int> intStack;
    Stack<char> charStack;
    Stack<Goods> goodsStack;

    while(true) {
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        showNavBarMessage(hintColor, "  Работа с шаблонными типами");
        int cmd = mainMenu.Navigate();
        cout << color(palette[Menu::PAL_CONSOLE]) << cls;
        if (cmd == Menu::CMD_QUIT) break;

        cout << endlm(3) << "    " << items[cmd].text << endlm(3);
        double r;
        int value;
        char char1;

        switch (cmd) {
            case CMD_CLASS_A:
	            cout << "\n\n    classA: " << classA << "\n\n";
	            classA.setA(-classA.getA());
	            classA.setB(-classA.getB());
	            classA.setC(-classA.getC());
	            cout << "\n\n    classA: " << classA << endlm(5);
            break;    
        
            case CMD_СLASS_A1:
	            cout << "\n\n    classA1: " << classA1 << "\n\n";
	            classA1.setA(-classA1.getA());
	            classA1.setB(-classA1.getB());
	            classA1.setC(-classA1.getC());
	            cout << "\n\n    classA1: " << classA1 << endlm(5);
            break;    

            case CMD_CLASS_A2:
	            cout << boolalpha << "\n\n    classA2: " << classA2 << "\n\n";
	            classA2.setA(-classA2.getA());
	            classA2.setB(-classA2.getB());  // операция, зависящая от типа !!!
	            classA2.setC(-classA2.getC());
	            cout << "\n\n    classA2: " << classA2 << endlm(5) << noboolalpha;

	            // О смысле операций заботится программист !!!
	            // !!! это вычисляется только из-за многократных неявных приведений типа !!!
	            r = classA2.getA() * M_PI + classA2.getC()/M_E - classA2.getB() * M_SQRT2;
	            cout << "    r = " << r << endlm(5); 
            break;

            case CMD_LIST_INT:
	            cout << "\n\n    Список int: " << intList << "\n\n";
	           
	            intList.add(555);
	            cout<< "    В конец добавили 555\n"
	                << "    Список int: " << intList << "\n\n";

	            intList.insert(0, 787);
	            cout<< "    В начало вставили 787\n"
	                << "    Список int: " << intList << "\n\n";

	            intList.removeAt(0);
	            cout<< "    Из начала удалили 787\n"
	                << "    Список int: " << intList << "\n\n";
            break;

            case CMD_LIST_CHAR:
	            cout << "\n\n    Список char: " << charList << "\n\n";
	           
	            charList.add('~');
	            cout<< "    В конец добавили ~\n"
	                << "    Список char: " << charList << "\n\n";

	            charList.insert(0, '>');
	            cout<< "    В начало вставили >\n"
	                << "    Список char: " << charList << "\n\n";

	            charList.removeAt(0);
	            cout<< "    Из начала удалили >\n"
	                << "    Список char: " << charList << "\n\n";
            break;

            case CMD_LIST_GOODS:
	            showListGoods("\n\n    Список товаров:\n", goodsList);
	            cout << "\n\n";
	           
	            goodsList.add(arrGoods[0]);
	            showListGoods("    В конец добавлен элемент:\n", goodsList);
	            cout << "\n\n";

	            goodsList.insert(0, arrGoods[0]);
	            showListGoods("    В начало вставлен элемент:\n", goodsList);
	            cout << "\n\n";

	            goodsList.removeAt(0);
	            showListGoods("    Из начала удален элемент:\n", goodsList);
	            cout << "\n\n";

				cout << "    Самолеты\n" << planesList << "\n";
            break;

            case CMD_STACK_INT:
	            intStack.clear();
	            intStack.push(100);
	            cout<< "\n\n"
	                << "    intStack: " << intStack << "\n\n";

	            // массив для добавления в стек
	            cout<< "    arrInt  : ";
	            for(auto item: arrInt) cout << setw(5) << item;
	            cout<< "\n\n";

	            intStack.pushAll(arrInt, N_INT_ARR);
	            cout<< "    intStack: " << intStack << "\n\n";

	            value = intStack.pop();
	            cout<< "    из стека прочитано: " << value << ", в стеке осталось: " 
	                << intStack << endlm(5);
            break;

            case CMD_STACK_CHAR:
	            charStack.clear();
	            charStack.push('$');
	            cout<< "\n\n"
	                << "    charStack: " << charStack << "\n\n";

	            // массив для добавления в стек
	            cout<< "    arrChar  : ";
	            for(auto item: arrChar) cout << setw(5) << item;
	            cout<< "\n\n";

	            charStack.pushAll(arrChar, N_CHAR_ARR);
	            cout<< "    charStack: " << charStack << "\n\n";

	            char1 = charStack.pop();
	            cout<< "    из стека прочитано: " << char1 << ", в стеке осталось: " 
	                << charStack << endlm(5);
            break;

            case CMD_STACK_GOODS:
	            showStackGoods("\n\n    Стек товаров:\n", goodsStack);
	            cout << "\n\n";
	           
	            goodsStack.push(arrGoods[0]);
	            showStackGoods("    В стек добавлен элемент:\n", goodsStack);
	            cout << "\n\n";

	            goodsStack.pushAll(arrGoods, N_ARR_GOODS);
	            showStackGoods("    В стек добавлен массив:\n", goodsStack);
	            cout << "\n\n";

	            goodsStack.pop();
	            showStackGoods("    Из начала стека удален элемент:\n", goodsStack);
            cout << "\n\n";
            break;
        } // switch

        cout << endlm(3);
        getKey("    Нажмите любую клавишу для продолжения...");
    } // while

    cout << cls << pos(0,24);
    getKey();

	return 0;
} // main

// вывод односвязного списка товаров
void showListGoods(const char *title, const List<Goods> &listGoods)
{
    cout << title;
    if (listGoods.isEmpty())
        cout << "список пуст";
    else {
        Node<Goods> *node = listGoods.getHead();  // адрес первого элемента
        while(node != nullptr) {  // пока не достигли конца списка
            cout << "    " << node->getPayload() << " -->\n";  // вывели очередной элемент
            node = node->getNext();                // адрес следующего элемента списка 
        } // while
    } // if
} // showListGoods

// вывод стека товаров
void showStackGoods(const char *title, const Stack<Goods> &stackGoods)
{
    cout << title;
    if (stackGoods.isEmpty())
        cout << "стек пуст";
    else {
        Stack<Goods> temp = stackGoods;
        while(!temp.isEmpty()) {  // пока не достигли конца списка
            cout << "    " << temp.pop() << " -->\n";  // вывели очередной элемент
        } // while
    } // if
} // showListGoods