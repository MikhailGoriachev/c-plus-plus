#include "App.h"
#include "MenuItem.h"
#include "menu.h"
#include "Deque.h"
#include "Goods.h"
#include "Queue.h"
#include "pch.h"
#include "List.h"

/*
	Задача 1. Разработайте шаблонные классы Deque и Queue(дек и очередь 
		соответственно) на базе шаблонного класса List(односвязный список)
		.Разработайте консольное приложение, в котором продемонстрируйте 
		операции с деком и очередью для типов int, char, Goods(класс для 
		представления товаров, поля класса – код товара и наименование 
		товара, цена за единицу товара, количество покупаемых единиц товара.
		В классе должны быть реализованы конструкторы и деструктор, методы 
		доступа к полям для получения и изменения информации, а также методы
		вычисления суммы оплаты за товар – произведение цены за единицу 
		товара и количества покупаемых единиц товара.Перегрузите операции 
		присваивания, вывода).

	Задача 2. При помощи шаблонного класса Stack(с ограничением во 
		внешнем классе емкости до 12 элементов) для представления полос 
		парковки, решите задачу моделирования парковки автомобилей у 
		магазина, в котором и приобретался товар.
	
		Автомобили могут ставиться на парковку только в начало парковочной полосы,
		автомобили могут забираться с парковкитолько с начала полосы.Но владельцы 
		могут забирать автомобили в произвольном порядке.Для этого машины с начала 
		парковочной полосы перемещаются на маневровую полосу, до машины, которую 
		требуется забрать.Эта машина покидает парковочную полосу, затем машины с 
		маневровой полосы возвращаются на парковочную.
		Разработайте класс Parking для решения задачи парковки.В классе Parking 
		реализуйте методы добавления автомобиля на парковку, изъятия произвольного 
		автомобиля с парковки.
*/


#pragma region Задания

#pragma region Задание 1. Демонстрация Deque и Queue

/*
	Задача 1. Разработайте шаблонные классы Deque и Queue(дек и очередь
		соответственно) на базе шаблонного класса List(односвязный список)
		.Разработайте консольное приложение, в котором продемонстрируйте
		операции с деком и очередью для типов int, char, Goods(класс для
		представления товаров, поля класса – код товара и наименование
		товара, цена за единицу товара, количество покупаемых единиц товара.
		В классе должны быть реализованы конструкторы и деструктор, методы
		доступа к полям для получения и изменения информации, а также методы
		вычисления суммы оплаты за товар – произведение цены за единицу
		товара и количества покупаемых единиц товара.Перегрузите операции
		присваивания, вывода).
*/

// Задание 1. Демонстрация Deque и Queue
void App::task1()
{
	init(L"Домашнее задание на 23.06.2021 | Задание 1. Демонстрация Deque и Queue");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Демонстрация Deque и Queue (int)
		CMD_DEMO_INT,
		// Демонстрация Deque и Queue (char)
		CMD_DEMO_CHAR,
		// Демонстрация Deque и Queue (Goods)
		CMD_DEMO_GOODS,
	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Демонстрация Deque и Queue (int)", CMD_DEMO_INT),
		MenuItem("Демонстрация Deque и Queue (char)", CMD_DEMO_CHAR),
		MenuItem("Демонстрация Deque и Queue (Goods)", CMD_DEMO_GOODS),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Демонстрация Deque и Queue (int)
			case CMD_DEMO_INT:
				app.task1DemoIntDeq();
				app.task1DemoIntQue();
				break;
				// Демонстрация Deque и Queue (char)
			case CMD_DEMO_CHAR:
				app.task1DemoCharDeq();
				app.task1DemoCharQue();
				break;
				// Демонстрация Deque и Queue (Goods)
			case CMD_DEMO_GOODS:
				app.task1DemoGoodsDeq();
				app.task1DemoGoodsQue();
				break;
			}
		}
		catch (exception& ex) {

			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

		} // try-catch
	}

}

#pragma region Демонстрация Deque и Queue (int)

// вывод линии, n - количество элементов
ostream& showLine(ostream& os, int n)
{
	os << "\t+————————————————————+";

	// вывод линии для дальнейших элементов
	for (size_t i = 0; i < n; i++)
	{
		os << "————+";
	}

	os << "\n";

	return os;
}

// вывод Deque (int)
/*void DequeIntOut(const Deque<int>& Deque)
{
	stringstream os;

	// вывод шапки
	os << "\t+————————————————————+———————————————————+\n"
		<< "\t|   Макс. размер: " << setw(2) << Deque.size_ << " |   Тек. размер: " << setw(2) << Deque.back_ << " |\n";

	// вывод линии
	showLine(os, Deque.back_ < 4 ? 4 : Deque.back_);

	// если дек пуст
	if (Deque.back_ == 0)
		os << "\t|                                        |\n"
		<< "\t|                 ДЕК ПУСТ               |\n"
		<< "\t|                                        |\n"
		<< "\t+————————————————————+———————————————————+\n";

	// если стек заполнен
	else
	{
		// вывод индекса элемента
		os << "\t|  Индекс элемента:  |";
		for (int i = 0; i < Deque.back_; i++)
		{
			os << " " << setw(2) << i << " |";
		}

		os << "\n";

		// вывод линии
		showLine(os, Deque.back_);

		// вывод элементов
		os << "\t|      Значение:     |";
		for (int i = 0; i < Deque.back_; i++)
		{
			// элмент
			int tmp = Deque.data_[i];

			short clOld = getColor();

			// текущий цвет
			short cl = tmp >= 'a' && tmp <= 'z' ? BLUE_ON_BLACK : RED_ON_BLACK;

			// если буква латниская или русская;

			os << color(cl) << "  " << Deque.data_[i] << " " << color(clOld) << "|";
		}

		os << "\n";

		// вывод линии
		showLine(os, Deque.back_);

	}

	cout << os.str();
}*/


// перегрзка операции вывода массива int 
void showArrInt(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

// Демонстрация Deque и Queue (int)
void App::task1DemoIntDeq()
{
	cls();

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\t\tДемонстрация работы шаблонного Deque с типом int\n";

	// объект дека 
	Deque<int> deq;

	int size = 3;

	// массив 
	int* arr = new int[3]{ 1,2,3 };
	int* arr1 = new int[3]{ -10,-20,-30 };
	int* arr2 = new int[3]{ 100,200,300 };

	cout << "\n\tИсходный дек Deque      : " << deq
		 << "\n\n\tЗаполнение дека массивом: ";

	// демонстрация массива 
	showArrInt(arr, size);

	// заполнение дека массивом
	deq.pushAll(arr, size);

	int n = 99;

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для начала Deque"
		<< "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление элемента в начало: " << n;

	// добавление элемента в начало 
	deq.shift(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		 << "\n\n\tВзятие элемента с начала";

	// взятие элемента с начала 
	n = deq.unshift();
	cout << "\n\tDeque                       : " << deq
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в начало массива : ";

	// демонстрация массива 
	showArrInt(arr1, size);
	
	// добавление в начало массива
	deq.shiftAll(arr1, size);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с начала"
		<< "\n\tDeque                       : " << deq;

	// просмотр элемента с начала
	n = deq.front();

	cout << "\n\tЭлемент с начала            : " << n;

	n = -999;

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для конца Deque"
		<< "\n\n\tДобавление элемента в конец : " << n;

	// добавление элемента в конец
	deq.push(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с конца";
		 
	// взятие элемента с конца
	n = deq.pop();

	cout << "\n\tDeque                       : " << deq
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в конец массива  : ";

	// демонстрация массива 
	showArrInt(arr2, size);

	// добавление в конец массива
	deq.pushAll(arr2, size);

	n = 687;

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с конца"
		<< "\n\tDeque                       : " << deq;

	// просмотр элемента с начала
	n = deq.back();

	cout << "\n\tЭлемент с конца             : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

	getKey();
}

// Демонстрация Deque и Queue (int)
void App::task1DemoIntQue()
{
	cls();

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\t\tДемонстрация работы шаблонного Deque с типом int\n";

	// объект дека 
	Queue<int> que;

	int size = 3;

	// массив 
	int* arr = new int[3]{ 1,2,3 };
	int* arr1 = new int[3]{ -10,-20,-30 };
	int* arr2 = new int[3]{ 100,200,300 };

	cout << "\n\tИсходный дек Deque      : " << que
		<< "\n\n\tЗаполнение дека массивом: ";

	// демонстрация массива 
	showArrInt(arr, size);

	// заполнение очереди массивом
	que.enqueueAll(arr, size);

	int n = 99;

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для начала Queue"
		<< "\n\tQueue                       : " << que
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление элемента в начало: " << n;

	// добавление элемента в начало 
	que.enqueue(n);

	cout << "\n\tQueue                       : " << que
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с начала";

	// взятие элемента с начала 
	n = que.dequeue();
	cout << "\n\tQueue                       : " << que
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в начало массива : ";

	// демонстрация массива 
	showArrInt(arr1, size);

	// добавление в начало массива
	que.enqueueAll(arr1, size);

	cout << "\n\tQueue                       : " << que
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с начала"
		<< "\n\tQueue                       : " << que;

	// просмотр элемента с начала
	n = que.front();

	cout << "\n\tЭлемент с начала            : " << n;

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

	getKey();
}

#pragma endregion 

#pragma region Демонстрация Deque и Queue (char)

// вывод Deque (char)
/*void DequeCharOut(const Deque<char>& Deque)
{
	stringstream os;

	// вывод шапки
	os << "\t+————————————————————+———————————————————+\n"
		<< "\t|   Макс. размер: " << setw(2) << Deque.size_ << " |   Тек. размер: " << setw(2) << Deque.back_ << " |\n";

	// вывод линии
	showLine(os, Deque.back_ < 4 ? 4 : Deque.back_);

	// если дек пуст
	if (Deque.back_ == 0)
		os << "\t|                                        |\n"
		<< "\t|                 ДЕК ПУСТ               |\n"
		<< "\t|                                        |\n"
		<< "\t+————————————————————+———————————————————+\n";

	// если стек заполнен
	else
	{
		// вывод индекса элемента
		os << "\t|  Индекс элемента:  |";
		for (int i = 0; i < Deque.back_; i++)
		{
			os << " " << setw(2) << i << " |";
		}

		os << "\n";

		// вывод линии
		showLine(os, Deque.back_);

		// вывод элементов
		os << "\t|      Значение:     |";
		for (int i = 0; i < Deque.back_; i++)
		{
			// элмент
			char tmp = Deque.data_[i];

			short clOld = getColor();

			// текущий цвет
			short cl = tmp >= 'a' && tmp <= 'z' ? BLUE_ON_BLACK : RED_ON_BLACK;

			// если буква латниская или русская;

			os << color(cl) << "  " << Deque.data_[i] << " " << color(clOld) << "|";
		}

		os << "\n";

		// вывод линии
		showLine(os, Deque.back_);

	}

	cout << os.str();
}*/

// перегрзка операции вывода массива int 
void showArrChar(char* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

// Демонстрация Deque и Queue (char)
void App::task1DemoCharDeq()
{
	cls();

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\t\tДемонстрация работы шаблонного Deque с типом char\n";

	// объект дека 
	Deque<char> deq;

	int size = 3;

	// массив 
	char* arr = new char[3]{ 'a','b','c' };
	char* arr1 = new char[3]{ 'd','f','g' };
	char* arr2 = new char[3]{ 'h','i','m' };

	cout << "\n\tИсходный дек Deque      : " << deq
		<< "\n\n\tЗаполнение дека массивом: ";

	// демонстрация массива 
	showArrChar(arr, size);

	// заполнение дека массивом
	deq.pushAll(arr, size);

	char n = 'Q';

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для начала Deque"
		<< "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление элемента в начало: " << n;

	// добавление элемента в начало 
	deq.shift(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с начала";

	// взятие элемента с начала 
	n = deq.unshift();
	cout << "\n\tDeque                       : " << deq
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в начало массива : ";

	// демонстрация массива 
	showArrChar(arr1, size);

	// добавление в начало массива
	deq.shiftAll(arr1, size);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с начала"
		<< "\n\tDeque                       : " << deq;

	// просмотр элемента с начала
	n = deq.front();

	cout << "\n\tЭлемент с начала            : " << n;

	n = 'Z';

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для конца Deque"
		<< "\n\n\tДобавление элемента в конец : " << n;

	// добавление элемента в конец
	deq.push(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с конца";

	// взятие элемента с конца
	n = deq.pop();

	cout << "\n\tDeque                       : " << deq
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в конец массива  : ";

	// демонстрация массива 
	showArrChar(arr2, size);

	// добавление в конец массива
	deq.pushAll(arr2, size);

	n = 'K';

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с конца"
		<< "\n\tDeque                       : " << deq;

	// просмотр элемента с начала
	n = deq.back();

	cout << "\n\tЭлемент с конца             : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

	getKey();

}

// Демонстрация Deque и Queue (char)
void App::task1DemoCharQue()
{
	cls();

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\t\tДемонстрация работы шаблонного Queue с типом char\n";

	// объект дека 
	Queue<char> que;

	int size = 3;

	// массив 
	char* arr = new char[3]{ 'a','b','c' };
	char* arr1 = new char[3]{ 'd','f','g' };
	char* arr2 = new char[3]{ 'h','i','m' };

	cout << "\n\tИсходный дек Queue      : " << que
		<< "\n\n\tЗаполнение дека массивом: ";

	// демонстрация массива 
	showArrChar(arr, size);

	// заполнение дека массивом
	que.enqueueAll(arr, size);

	char n = 'Q';

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для начала Queue"
		<< "\n\tQueue                       : " << que
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление элемента в начало: " << n;

	// добавление элемента в начало 
	que.enqueue(n);

	cout << "\n\tQueue                       : " << que
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с начала";

	// взятие элемента с начала 
	n = que.dequeue();
	cout << "\n\tQueue                       : " << que
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в начало массива : ";

	// демонстрация массива 
	showArrChar(arr1, size);

	// добавление в начало массива
	que.enqueueAll(arr1, size);

	cout << "\n\tQueue                       : " << que
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с начала"
		<< "\n\tQueue                       : " << que;

	// просмотр элемента с начала
	n = que.front();

	cout << "\n\tЭлемент с начала            : " << n;

	n = 'Z';

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

	getKey();

}


#pragma endregion  

#pragma region Демонстрация Deque и Queue (Goods)

// для вывода в цвете
bool pregicatorDemoGoods(int position, int positionMin, int positionMax)
{
	return position >= positionMin && position <= positionMax;
}

// вывод Deque (Goods) в цвете
void DequeGoodsOut(Deque<Goods>& deque, int positionMin = -1, int positionMax = -1)
{
	int size = deque.counter();

	short cl = getColor();

	if (size == 0)
	{
		cout << "Deque пуст\n";
		return;
	}

	List<Goods> list = deque.data_;

	for (size_t i = 0; i < size; i++)
	{
		Goods deq = list.get(i);

		cout << fixed << setprecision(2) << "\n\t\t\t\t\t"
			<< color(pregicatorDemoGoods(i, positionMin, positionMax) ? GREEN_ON_BLACK : cl)
			<< deq.code_ << "; " << deq.name_
			<< "; цена ед. " << deq.price_
			<< "; количество " << deq.amount_;
	}

	setColor(cl);

	cout << "\n";
}

// Демонстрация Deque и Queue (Goods)
void App::task1DemoGoodsDeq()
{
	cls();

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\t\tДемонстрация работы шаблонного Deque с типом char\n";

	// начальная позция вставки
	int posMin;

	// последння позиция вставки
	int posMax;

	// объект дека 
	Deque<Goods> deq;

	// длина массивов
	int size = 3;

	// Goods(int code, const char* name, double price, int amount)

	// массив 
	Goods* arr = new Goods[3]{ 
		Goods(483124, "Хлеб", 15, 5),
		Goods(987321, "Пломбир", 36, 3),
		Goods(134547, "Сырок", 13, 4)
	};
	Goods* arr1 = new Goods[3]{ 
		Goods(897683, "Чипсы", 56, 1),
		Goods(987321, "Fanta", 47, 2),
		Goods(546747, "Coca-Cola", 63, 3) 
	};
	Goods* arr2 = new Goods[3]{
		Goods(582346, "Old Spice", 97, 5),
		Goods(324132, "Мыло жидкое", 42, 2),
		Goods(875364, "Пельмени", 143, 2)
	};

	cout << "\n\tИсходный дек Deque      : ";

	DequeGoodsOut(deq);

	cout << "\n\n\tЗаполнение дека массивом: ";

	// демонстрация массива 
	DequeGoodsOut(deq);

	// заполнение дека массивом
	deq.pushAll(arr, size);

	Goods n = Goods(734936, "Батон", 26, 2);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для начала Deque"
		<< "\n\tDeque                       : ";

	DequeGoodsOut(deq, -1, -1);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление элемента в начало: " << n;

	// добавление элемента в начало 
	deq.shift(n);

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, 0, 0);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с начала";

	// взятие элемента с начала 
	n = deq.unshift();

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, -1, -1);

	cout << "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в начало массива : ";

	// демонстрация массива 
	//showArrChar(arr1, size);

	// добавление в начало массива
	deq.shiftAll(arr1, size);

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, 0, 2);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с начала"
		<< "\n\tDeque                       : ";

	DequeGoodsOut(deq, 0, 0);

	// просмотр элемента с начала
	n = deq.front();

	cout << "\n\tЭлемент с начала            : " << n;

	n = Goods(194638, "Сухарики", 53, 4);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для конца Deque"
		<< "\n\n\tДобавление элемента в конец : " << n;

	// добавление элемента в конец
	deq.push(n);

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, deq.counter() - 1, deq.counter() - 1);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с конца";

	// взятие элемента с конца
	n = deq.pop();

	cout << "\n\tDeque                       : ";
	DequeGoodsOut(deq);
	cout << "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в конец массива  : ";

	// демонстрация массива 
	//showArrChar(arr2, size);

	posMin = deq.counter() - 1;

	// добавление в конец массива
	deq.pushAll(arr2, size);

	n = Goods(546812, "Торт", 253, 1);

	cout << "\n\tDeque                       : ";
	DequeGoodsOut(deq, posMin, posMin + size);
	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с конца"
		<< "\n\tDeque                       : ";
	DequeGoodsOut(deq, deq.counter() - 1, deq.counter() - 1);

	// просмотр элемента с начала
	n = deq.back();

	cout << "\n\tЭлемент с конца             : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

	getKey();

}

// вывод Deque (Goods) в цвете
void QueueGoodsOut(Queue<Goods>& queue, int positionMin = -1, int positionMax = -1)
{
	int size = queue.getCounter();

	short cl = getColor();

	if (size == 0)
	{
		cout << "Deque пуст\n";
		return;
	}

	List<Goods> list = queue.data_;

	for (size_t i = 0; i < size; i++)
	{

		Goods goods = list.get(i);

		cout << fixed << setprecision(2) << "\n\t\t\t\t\t"
			<< color(pregicatorDemoGoods(i, positionMin, positionMax) ? GREEN_ON_BLACK : cl)
			<< goods.code_ << "; " << goods.name_
			<< "; цена ед. " << goods.price_
			<< "; количество " << goods.amount_;
	}

	setColor(cl);

	cout << "\n";
}

// Демонстрация Deque и Queue (Goods)
void App::task1DemoGoodsQue()
{
	cls();

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\t\tДемонстрация работы шаблонного Queue с типом char\n";

	// начальная позция вставки
	int posMin;

	// последння позиция вставки
	int posMax;

	// объект дека 
	Queue<Goods> que;

	// длина массивов
	int size = 3;

	// Goods(int code, const char* name, double price, int amount)

	// массив 
	Goods* arr = new Goods[3]{
		Goods(483124, "Хлеб", 15, 5),
		Goods(987321, "Пломбир", 36, 3),
		Goods(134547, "Сырок", 13, 4)
	};
	Goods* arr1 = new Goods[3]{
		Goods(897683, "Чипсы", 56, 1),
		Goods(987321, "Fanta", 47, 2),
		Goods(546747, "Coca-Cola", 63, 3)
	};
	Goods* arr2 = new Goods[3]{
		Goods(582346, "Old Spice", 97, 5),
		Goods(324132, "Мыло жидкое", 42, 2),
		Goods(875364, "Пельмени", 143, 2)
	};

	cout << "\n\tИсходный дек Queue      : ";

	QueueGoodsOut(que);

	cout << "\n\n\tЗаполнение дека массивом: ";

	// демонстрация массива 
	QueueGoodsOut(que);

	// заполнение дека массивом
	que.enqueueAll(arr, size);

	Goods n = Goods(734936, "Батон", 26, 2);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для начала Queue"
		<< "\n\tDeque                       : ";

	QueueGoodsOut(que, -1, -1);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление элемента в начало: " << n;

	// добавление элемента в начало 
	que.enqueue(n);

	cout << "\n\tDeque                       : ";

	QueueGoodsOut(que, 0, 0);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с начала";

	// взятие элемента с начала 
	n = que.dequeue();

	cout << "\n\tDeque                       : ";

	QueueGoodsOut(que, -1, -1);

	cout << "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в начало массива : ";

	// демонстрация массива 
	//showArrChar(arr1, size);

	// добавление в начало массива
	que.enqueueAll(arr1, size);

	cout << "\n\tQueue                       : ";

	QueueGoodsOut(que, 0, 2);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с начала"
		<< "\n\tQueue                       : ";

	QueueGoodsOut(que, 0, 0);

	// просмотр элемента с начала
	n = que.front();

	cout << "\n\tЭлемент с начала            : " << n;

	n = Goods(194638, "Сухарики", 53, 4);

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

	getKey();

}


#pragma endregion

#pragma endregion

#pragma region  Задача 2. Парковка

/*
	Задача 2. При помощи шаблонного класса Stack(с ограничением во
		внешнем классе емкости до 12 элементов) для представления полос
		парковки, решите задачу моделирования парковки автомобилей у
		магазина, в котором и приобретался товар.

		Автомобили могут ставиться на парковку только в начало парковочной полосы,
		автомобили могут забираться с парковки только с начала полосы.Но владельцы
		могут забирать автомобили в произвольном порядке. Для этого машины с начала
		парковочной полосы перемещаются на маневровую полосу, до машины, которую
		требуется забрать.Эта машина покидает парковочную полосу, затем машины с
		маневровой полосы возвращаются на парковочную.
		Разработайте класс Parking для решения задачи парковки.В классе Parking
		реализуйте методы добавления автомобиля на парковку, изъятия произвольного
		автомобиля с парковки.
*/

// Задача 2. Парковка
void App::task2()
{
	init(L"Домашнее задание на 23.06.2021 | Задача 2. Парковка");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Вывести парковку
		CMD_OUT_PARK,
		// Добавить автомобиль
		CMD_ADD_CAR,
		// Забрать последний автомобиль
		CMD_POP_CAR,
		// Забрать любой автомобиль (Владелец)
		CMD_POP_ANY_CAR
	};

	// количество пунктов меню
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("Вывести парковку", CMD_OUT_PARK),
		MenuItem("Добавить автомобиль", CMD_ADD_CAR),
		MenuItem("Забрать последний автомобиль", CMD_POP_CAR),
		MenuItem("Забрать любой автомобиль (Владелец)", CMD_POP_ANY_CAR),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Вывести парковку
			case CMD_OUT_PARK:
				app.showParking();
				break;
				// Добавить автомобиль
			case CMD_ADD_CAR:
				app.addParking();
				break;
				// Забрать последний автомобиль
			case CMD_POP_CAR:
				app.popParking();
				break;
				// Забрать любой автомобиль (Владелец)
			case CMD_POP_ANY_CAR:
				app.popAnyParking();
				break;
			}
		}
		catch (exception& ex) {

			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();

		} // try-catch
	}
}

// вывод парковки
void App::showParking()
{
	cls();

	cout << "\n\t\t\t\tВЫВОД ПАРКОВКИ\n";

	// вывод парковки в цвете в виде схемы
	park_.showColor();

	// вывод парковки в виде таблицы
	cout << park_;

	getKey();
}

// добавление автомобиля
void App::addParking()
{
	cls();

	cout << "\n\t\tДобавление автомобиля\n";

	// вывод парковки в цвете в виде схемы
	park_.showColor();

	// вывод парковки в виде таблицы
	cout << park_;

	Sleep(500);

	// вывод после добавления
	park_.push(genCar());

	cls();

	cout << "\n\t\tДобавление автомобиля\n";

	// вывод парковки в цвете в виде схемы
	park_.showColor();

	// вывод парковки в виде таблицы
	cout << park_;

	getKey();
}

// удаление последнего автомобиля
void App::popParking()
{
	cls();

	cout << "\n\t\tУдаление последнего автомобиля\n";

	// вывод парковки в цвете в виде схемы
	park_.showColor();

	// вывод парковки в виде таблицы
	cout << park_;

	Sleep(500);

	// вывод после добавления
	Car save = park_.pop();

	cls();

	cout << "\n\t\tУдаление последнего автомобиля\n";

	// вывод парковки в цвете в виде схемы
	park_.showColor();

	short cl = getColor();

	// вывод парковки в виде таблицы
	cout << park_ << color(GREEN_ON_BLACK)
		<< "\tУдалённая машина: \n" << save << "\n\n\n" << color(cl);

	getKey();

}

// удаление любого автомобиля по индексу
void App::popAnyParking()
{
	cls();

	cout << "\n\t\tУдаление любого автомобиля по индексу\n";

	// вывод парковки в цвете в виде схемы
	park_.showColor();

	// вывод парковки в виде таблицы
	cout << park_;

	int counter = park_.getCounterPark();

	int n = getRand(0, counter != 0 ? counter : 1);

	short cl = getColor();

	cout << color(GREEN_ON_BLACK) << "\n\t\tИндекс: " << n << "\n" << color(cl);

	Sleep(3000);

	Car save = park_.popAny(n);

	cls();

	cout << "\n\t\tУдаление последнего автомобиля\n";

	// вывод парковки в цвете в виде схемы
	park_.showColor();

	// вывод парковки в виде таблицы
	cout << park_;

	cout << color(GREEN_ON_BLACK) << "\n\t\tИндекс: " << n << "\n"
		<< save << "\n" << color(cl);

	getKey();

}

// генерация автомобиля
Car App::genCar()
{
	char number[8] = "АН1234\0";

	Car car;

	for (int i = 0; i < 7; i++)
	{
		if (number[i] >= 'А' && number[i] <= 'Я')
			number[i] = getRand('А', 'Я');

		else if (number[i] >= '0' && number[i] <= '9')
			number[i] = getRand('0', '9');
	}

	car.setNumber(number);

	char** brand = new char* [5];

	for (int i = 0; i < 5; i++)
	{
		brand[i] = new char[10];
	}

	strcpy(brand[0], "BMW");
	strcpy(brand[1], "MERCEDES");
	strcpy(brand[2], "OPEL");
	strcpy(brand[3], "AUDI");
	strcpy(brand[4], "LADA");

	car.setBrand(brand[getRand(0, 4)]);

	struct Color
	{
		// название цвета 
		char name[15];

		// код цвета
		short color;
	};

	const int size = 8;

	// массив цветов со значениями
	Color colors[size];

	// чёрный
	strcpy(colors[0].name, "Black");
	colors[0].color = WHITE_ON_BLACK;

	// синий
	strcpy(colors[1].name, "Blue");
	colors[1].color = BLACK_ON_BLUE;

	// зелёный
	strcpy(colors[2].name, "Green");
	colors[2].color = BLACK_ON_GREEN;

	// голубой
	strcpy(colors[3].name, "Cyan");
	colors[3].color = BLACK_ON_CYAN;

	// красный
	strcpy(colors[4].name, "Red");
	colors[4].color = BLACK_ON_RED;

	// лиловый
	strcpy(colors[5].name, "Magenta");
	colors[5].color = BLACK_ON_MAGENTA;

	// жёлтый
	strcpy(colors[6].name, "Yellow");
	colors[6].color = BLACK_ON_YELLOW;

	// серый 
	strcpy(colors[7].name, "Gray");
	colors[7].color = BLACK_ON_GRAY;

	car.setColor(colors[getRand(0, 7)].name);

	return car;
}
#pragma endregion 

#pragma endregion
