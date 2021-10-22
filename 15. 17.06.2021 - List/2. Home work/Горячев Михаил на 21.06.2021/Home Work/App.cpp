#include "App.h"


/*
	Задание 1. Доработать класс List –односвязный список целых чисел.Реализовать «правило трех». 
		Реализоватьи продемонстрировать в приложении следующие операции:

		•	insert(position, payload) – вставляет элемент в список перед позицией position
			(нумерация позиций начинается с 0)
		•	get(postion)– возвращает значение элемента списка в заданной позиции (нумерация
			позиций начинается с 0)
		•	put(position, value) – записывает значение value в заданную позицию списка
			(нумерация позиций начинается с 0)
		•	перегрузить операцию [] для доступа к элементам списка по заданному значению 
			позиции position(нумерация позиций начинается с 0)
		•	addAll(data[], n)добавление массива в конец списка
		•	insertAll(position, data[], n)вставка массива data[] перед позицией position
			(нумерация позиций начинается с 0)

	Задание 2. На базе классов List и Node разработайте классы ListPlane и NodePlanec 
		для хранения данных объектов класса Plane. Продемонстрируйте работу методов класса ListPlane.

*/


#pragma region Задание 1

/*
	Задание 1. Доработать класс List –односвязный список целых чисел.Реализовать «правило трех».
		Реализоватьи продемонстрировать в приложении следующие операции:

		•	insert(position, payload) – вставляет элемент в список перед позицией position
			(нумерация позиций начинается с 0)
		•	get(postion)– возвращает значение элемента списка в заданной позиции (нумерация
			позиций начинается с 0)
		•	put(position, value) – записывает значение value в заданную позицию списка
			(нумерация позиций начинается с 0)
		•	перегрузить операцию [] для доступа к элементам списка по заданному значению
			позиции position(нумерация позиций начинается с 0)
		•	addAll(data[], n)добавление массива в конец списка
		•	insertAll(position, data[], n)вставка массива data[] перед позицией position
			(нумерация позиций начинается с 0)
*/

// меню задания 1
void App::task1()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Вставка элемента в список перед позицией 
		CMD_INSERT,
		// Возвращение значения элемента списка по заданной позиции
		CMD_GET,
		// Запись значение в заданную позицию списка
		CMD_PUT,
		// Добавление массива в конец списка
		CMD_ADD_ALL,
		// Вставка массива перед позицией 
		CMD_INSERT_ALL
	};

	// количество пунктов меню
	const int N_MENU = 6;

	MenuItem items[N_MENU] = {
		MenuItem("Вставка элемента в список перед позицией", CMD_INSERT),
		MenuItem("Возвращение значения элемента списка по заданной позиции", CMD_GET),
		MenuItem("Запись значение в заданную позицию списка", CMD_PUT),
		MenuItem("Добавление массива в конец списка", CMD_ADD_ALL),
		MenuItem("Вставка массива перед позицией ", CMD_INSERT_ALL),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 1", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
			// Вставка элемента в список перед позицией 
			case CMD_INSERT:
				app.task1Insert();
				break;

			// Возвращение значения элемента списка по заданной позиции
			case CMD_GET:
				app.task1Get();
				break;		

			// Запись значение в заданную позицию списка
			case CMD_PUT:
				app.task1Put();
				break;		

			// Добавление массива в конец списка
			case CMD_ADD_ALL:
				app.task1AddAll();
				break;

			// Вставка массива перед позицией 
			case CMD_INSERT_ALL:
				app.task1InsertAll();
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

// предикатор для вывода в цвете для вставки
bool task1InsertPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// Вставка элемента в список перед позицией 
// insert(position, payload) – вставляет элемент в список перед позицией position
// (нумерация позиций начинается с 0)
void App::task1Insert()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 1. Вставка элемента в список перед позицией\n\n";

	// размер генерируемого массива
	int size = getRand(2, 8);

	// генерация массива (int) и заполнение списка массивом 
	List list(getArrayRandom(size, -99, 99), size);
	
	// вывод списка 
	cout << "\tСписок до вставки элемента:\n" << list << "\n\n";

	// генерация позиции для вставки
	int position = getRand(0, list.getCounter() - 1);

	// генерация значения для вставки
	int value = getRand(-99, 99);

	// вставка элемента на указанную позицию
	list.insert(position, value);

	// вывод списка 
	cout << "\tСписок до вставки элемента:\n";

	// вывод позиции и элемента для вставки в цвете
	list.showListColor(task1InsertPred, &position, 1);

	cout << "\n\n\tВставляемый элемент:\n\n" << "\t\tЗначение: " << value << "\n\n\t\tПозиция: " << position << "\n\n";

	getKey();
}

// предикатор для вывода в цвете для доступа к элементу списка
bool task1GetPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// Возвращение значения элемента списка по заданной позиции
// get(postion)– возвращает значение элемента списка в заданной позиции (нумерация
// позиций начинается с 0)
void App::task1Get()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 1. Возвращение значения элемента списка по заданной позиции\n\n";

	// размер генерируемого массива
	int size = getRand(2, 8);

	// генерация массива (int) и заполнение списка массивом 
	List list(getArrayRandom(size, -99, 99), size);

	// генерация позиции
	int position = getRand(0, list.getCounter() - 1);

	cout << "\tСписок:\n";

	// вывод списка в цвете
	list.showListColor(task1GetPred, &position, 1);

	cout << "\n\n\tЭлемент по индексу [" << position << "]: " << *list[position] << "\n\n";

	getKey();
}

// предикатор для вывода в цвете для доступа к элементу списка
bool task1PutPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// Запись значение в заданную позицию списка
// put(position, value) – записывает значение value в заданную позицию списка
// (нумерация позиций начинается с 0)
void App::task1Put()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 1. Запись значение в заданную позицию списка\n\n";

	// размер генерируемого массива
	int size = getRand(2, 8);

	// генерация массива (int) и заполнение списка массивом 
	List list(getArrayRandom(size, -99, 99), size);

	// генерация позиции для изменения
	int position = getRand(0, list.getCounter() - 1);

	// генерация значения для изменения
	int value = getRand(-99, 99);

	// вывод списка 
	cout << "\tСписок до изменения элемента:\n";
	list.showListColor(task1PutPred, &position, 1);
	cout << "\n\n";

	// изменение элемента по указанной позиции
	list.put(position, value);

	// вывод списка 
	cout << "\tСписок после изменения элемента:\n";

	// вывод позиции и элемента для вставки в цвете
	list.showListColor(task1InsertPred, &position, 1);

	cout << "\n";

	cout << "\tИзменияемый элемент:\n\n" << "\t\tЗначение: " << value << "\n\n\t\tПозиция: " << position << "\n\n";

	getKey();
}

// предикатор для вывода в цвете после добавления массива в конец списка
bool task1AddAllPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition >= posArr[0] && currentPosition < posArr[1];
}

// Добавление массива в конец списка
// addAll(data[], n)добавление массива в конец списка
void App::task1AddAll()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 1. Добавление массива в конец списка\n\n";

	// размер генерируемого массива для создания списка
	int size = getRand(2, 5);

	// генерация массива (int) и заполнение списка массивом 
	List list(getArrayRandom(size, -99, 99), size);

	// длина списка до добавления массива в конец
	int counter = list.getCounter();

	// вывод списка 
	cout << "\tСписок до вставки массива в конец:\n" << list << "\n\n";

	// размер генерируемого массива для вставки в конец списка
	size = getRand(2, 5);

	// генерация значений для массива вставки
	int* values = getArrayRandom(size, -99, 99);

	// добавление массива в конец списка
	list.addAll(values, size);

	// вывод списка 
	cout << "\tСписок после вставки массива в конец:\n";

	// массив позиций (от / до) вставленного массива для вывода в цвете
	int* position = new int[2];

	// заполнение массива позициями
	// индекс первого встевленного элемента
	position[0] = counter;

	// индекс последнего вставленного элемента
	position[1] = counter + size;

	// вывод позиции и элемента для вставки в цвете
	list.showListColor(task1AddAllPred, position, 2);

	cout << "\n\n\tМассив вставленных элементов:\n\n";

	showArrInt(values, size);

	cout << "\n\n";

	getKey();
}

// Вставка массива перед позицией 
// insertAll(position, data[], n)вставка массива data[] перед позицией position
// (нумерация позиций начинается с 0)
void App::task1InsertAll()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 1. Вставка массива перед указанной позицией\n\n";

	// размер генерируемого массива для создания списка
	int size = getRand(2, 5);

	// генерация массива (int) и заполнение списка массивом 
	List list(getArrayRandom(size, -99, 99), size);

	// длина списка до добавления массива в конец
	int counter = list.getCounter();

	// вывод списка 
	cout << "\tСписок до вставки массива по указанной позиции:\n" << list << "\n\n";

	// размер генерируемого массива для вставки начиная с указанной позиции
	size = getRand(2, 5);

	// генерация значений для массива вставки
	int* values = getArrayRandom(size, -99, 99);

	// генерация позиции для вставки
	int position = getRand(0, list.getCounter() - 1);

	// вставка массива начиная с указанной позиции списке
	list.insertAll(position, values, size);

	// вывод списка 
	cout << "\tСписок после вставки массива по указанной позиции:\n";

	// массив позиций (от / до) вставленного массива для вывода в цвете
	int* positions = new int[2];

	// заполнение массива позициями
	// индекс первого встевленного элемента
	positions[0] = position;

	// индекс последнего вставленного элемента
	positions[1] = position + size;

	// вывод позиции и элемента для вставки в цвете
	list.showListColor(task1AddAllPred, positions, 2);

	cout << "\n\n\tМассив вставленных элементов:\n\n";

	showArrInt(values, size);

	cout << "\n\n\t\tНачальная позиция вставки: " << position
		<< "\n\n\t\tПоследняя позиция вставки: " << position + size - 1 << "\n\n";

	getKey();
}

// генерация массива (int)
int* App::getArrayRandom(int size, int min, int max)
{
	// выделение памяти под массив (int)
	int* arr = new int[size];

	// заполнение массива случайными числами (int)
	for (int i = 0; i < size; i++)
	{
		arr[i] = getRand(min, max);
	}

	// возвращение указателя на массив
	return arr;
}

// перегрузка функции вывода для массива (int)
void App::showArrInt(int* arr, int size)
{
	// ВЫВОД ГОРИЗОНТАЛЬНОЙ ТАБЛИЦЕЙ

	cout << "\t+——————————————————————————+\n"
		<< "\t| Количество элементов: " << setw(2) << size << " |\n";

	cout << "\t+—————————————————+";
	for (size_t i = 0; i < size; i++)
	{
		cout << "————————+";
	}

	cout << "\n\t|      Индекс     |";

	for (size_t i = 0; i < size; i++)
	{
		cout << "   " << setw(3) << i << "  |";
	}

	// если очередь пуста 
	if (size == 0)
	{
		cout << "\t+——————————————————————————+\n"
			<< "\t|                          |\n"
			<< "\t|        ЛИСТ ПУСТА        |\n"
			<< "\t|                          |\n"
			<< "\t+——————————————————————————+\n";
	}

	else
	{

		cout << "\n\t+—————————————————+";
		for (size_t i = 0; i < size; i++)
		{
			cout << "————————+";
		}

		cout << "\n\t|    Содержание   |";

		for (size_t i = 0; i < size; i++)
		{
			cout << " " << setw(7) << arr[i] << "|";
		}

		cout << "\n\t+—————————————————+";
		for (size_t i = 0; i < size; i++)
		{
			cout << "————————+";
		}

		cout << "\n";
	}
}

#pragma endregion

#pragma region Задание 2

/*
	Задание 2. На базе классов List и Node разработайте классы ListPlane и NodePlanec
		для хранения данных объектов класса Plane. Продемонстрируйте работу методов класса ListPlane.
*/

// меню задания 2
void App::task2()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Вставка элемента в список перед позицией 
		CMD_INSERT,
		// Возвращение значения элемента списка по заданной позиции
		CMD_GET,
		// Запись значение в заданную позицию списка
		CMD_PUT,
		// Добавление массива в конец списка
		CMD_ADD_ALL,
		// Вставка массива перед позицией 
		CMD_INSERT_ALL
	};

	// количество пунктов меню
	// количество пунктов меню
	const int N_MENU = 6;

	MenuItem items[N_MENU] = {
		MenuItem("Вставка элемента в список перед позицией", CMD_INSERT),
		MenuItem("Возвращение значения элемента списка по заданной позиции", CMD_GET),
		MenuItem("Запись значение в заданную позицию списка", CMD_PUT),
		MenuItem("Добавление массива в конец списка", CMD_ADD_ALL),
		MenuItem("Вставка массива перед позицией ", CMD_INSERT_ALL),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 2", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Вставка элемента в список перед позицией 
			case CMD_INSERT:
				app.task2Insert();
				break;

				// Возвращение значения элемента списка по заданной позиции
			case CMD_GET:
				app.task2Get();
				break;

				// Запись значение в заданную позицию списка
			case CMD_PUT:
				app.task2Put();
				break;

				// Добавление массива в конец списка
			case CMD_ADD_ALL:
				app.task2AddAll();
				break;

				// Вставка массива перед позицией 
			case CMD_INSERT_ALL:
				app.task2InsertAll();
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

// предикатор для вывода в цвете для вставки
bool task2InsertPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// Вставка элемента в список перед позицией 
// insert(position, payload) – вставляет элемент в список перед позицией position
// (нумерация позиций начинается с 0)
void App::task2Insert()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 2. Вставка элемента в список перед позицией\n\n";

	// размер генерируемого массива
	int size = getRand(2, 8);

	// генерация массива (Plane) и заполнение списка массивом 
	ListPlane list(fillArrPlane(size), size);

	// вывод списка 
	cout << "\tСписок до вставки элемента:\n" << list << "\n\n";

	// генерация позиции для вставки
	int position = getRand(0, list.getCounter() - 1);

	// генерация значения для вставки
	Plane value = genPlane();

	// вставка элемента на указанную позицию
	list.insert(position, value);

	// вывод списка 
	cout << "\tСписок до вставки элемента:\n";

	// вывод позиции и элемента для вставки в цвете
	list.showListPlaneColor(task1InsertPred, &position, 1);

	cout << "\n\n\tИндекс вставляемого элемента: " << position << "\n\n";

	getKey();
}

// предикатор для вывода в цвете для доступа к элементу списка
bool task2GetPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// Возвращение значения элемента списка по заданной позиции
// get(postion)– возвращает значение элемента списка в заданной позиции (нумерация
// позиций начинается с 0)
void App::task2Get()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 2. Возвращение значения элемента списка по заданной позиции\n\n";

	// размер генерируемого массива
	int size = getRand(2, 8);

	// генерация массива (Plane) и заполнение списка массивом 
	ListPlane list(fillArrPlane(size), size);

	// генерация позиции
	int position = getRand(0, list.getCounter() - 1);

	cout << "\tСписок:\n";

	// вывод списка в цвете
	list.showListPlaneColor(task1GetPred, &position, 1);

	Plane plane = list.get(position);

	// текущий цвет
	short cl = getColor();

	cout << color(GREEN_ON_BLACK)  << "\n\n\tЭлемент по индексу ["<< position << "]\n";

	plane.showPlaneTable();

	cout << color(cl);

	getKey();
}

// предикатор для вывода в цвете для доступа к элементу списка
bool task2PutPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// Запись значение в заданную позицию списка
// put(position, value) – записывает значение value в заданную позицию списка
// (нумерация позиций начинается с 0)
void App::task2Put()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 2. Запись значение в заданную позицию списка\n\n";

	// размер генерируемого массива
	int size = getRand(2, 8);

	// генерация массива (Plane) и заполнение списка массивом 
	ListPlane list(fillArrPlane(size), size);

	// генерация позиции для изменения
	int position = getRand(0, list.getCounter() - 1);

	// генерация значения для изменения
	Plane value = genPlane();

	// вывод списка 
	cout << "\tСписок до изменения элемента:\n";
	list.showListPlaneColor(task1PutPred, &position, 1);
	cout << "\n\n";

	// изменение элемента по указанной позиции
	list.put(position, value);

	// вывод списка 
	cout << "\tСписок после изменения элемента:\n";

	// вывод позиции и элемента для вставки в цвете
	list.showListPlaneColor(task1InsertPred, &position, 1);

	cout << "\n";

	cout << "\tПозиция изменияемого элемента: " << position << "\n\n";

	getKey();
}

// предикатор для вывода в цвете после добавления массива в конец списка
bool task2AddAllPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition >= posArr[0] && currentPosition < posArr[1];
}

// Добавление массива в конец списка
// addAll(data[], n)добавление массива в конец списка
void App::task2AddAll()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 2. Добавление массива в конец списка\n\n";

	// размер генерируемого массива для создания списка
	int size = getRand(2, 5);

	// генерация массива (Plane) и заполнение списка массивом 
	ListPlane list(fillArrPlane(size), size);

	// длина списка до добавления массива в конец
	int counter = list.getCounter();

	// вывод списка 
	cout << "\tСписок до вставки массива в конец:\n" << list << "\n\n";

	// размер генерируемого массива для вставки в конец списка
	size = getRand(2, 5);

	// генерация значений для массива вставки
	Plane* values = fillArrPlane(size);

	// добавление массива в конец списка
	list.addAll(values, size);

	// вывод списка 
	cout << "\tСписок после вставки массива в конец:\n";

	// массив позиций (от / до) вставленного массива для вывода в цвете
	int* position = new int[2];

	// заполнение массива позициями
	// индекс первого встевленного элемента
	position[0] = counter;

	// индекс последнего вставленного элемента
	position[1] = counter + size;

	// вывод позиции и элемента для вставки в цвете
	list.showListPlaneColor(task1AddAllPred, position, 2);

	cout << "\n\n\tДлина вставленного массива: " << size << "\n\n";

	getKey();
}

// Вставка массива перед позицией 
// insertAll(position, data[], n)вставка массива data[] перед позицией position
// (нумерация позиций начинается с 0)
void App::task2InsertAll()
{
	cls();

	// вывод условий задания
	cout << "\n\n\t\tЗадание 2. Вставка массива перед указанной позицией\n\n";

	// размер генерируемого массива для создания списка
	int size = getRand(2, 5);

	// генерация массива (Plane) и заполнение списка массивом 
	ListPlane list(fillArrPlane(size), size);

	// длина списка до добавления массива в конец
	int counter = list.getCounter();

	// вывод списка 
	cout << "\tСписок до вставки массива по указанной позиции:\n" << list << "\n\n";

	// размер генерируемого массива для вставки начиная с указанной позиции
	size = getRand(2, 5);

	// генерация значений для массива вставки
	Plane* values = fillArrPlane(size);

	// генерация позиции для вставки
	int position = getRand(0, list.getCounter() - 1);

	// вставка массива начиная с указанной позиции списке
	list.insertAll(position, values, size);

	// вывод списка 
	cout << "\tСписок после вставки массива по указанной позиции:\n";

	// массив позиций (от / до) вставленного массива для вывода в цвете
	int* positions = new int[2];

	// заполнение массива позициями
	// индекс первого встевленного элемента
	positions[0] = position;

	// индекс последнего вставленного элемента
	positions[1] = position + size;

	// вывод позиции и элемента для вставки в цвете
	list.showListPlaneColor(task1AddAllPred, positions, 2);

	cout << "\n\n\tДлина массива вставленных элементов: " << size
		<< "\n\n\tНачальная позиция вставки: " << position
		<< "\n\n\tПоследняя позиция вставки: " << position + size - 1 << "\n\n";


	getKey();
}

// генерация самолёта 
Plane App::genPlane()
{
	// размер массива шаблонов
	const int size = 5;

	// массив самолётов шаблонов
	Plane planes[size]
	{
		Plane("Airbus А380", 525, 345, 12000, 275'000'000, 15000, "F - WWOW"),
		Plane("Boeing 747", 452, 400, 10700, 266'000'000, 12000, "B - 18215"),
		Plane("Boeing 777", 550, 500, 13500, 280'000'000, 13000, "G - YMMM"),
		Plane("Airbus A320", 150, 115, 2100, 93'900'000, 10000, "F - GFKC"),
		Plane("Airbus A318", 132, 86, 2150, 65'000'000, 11000, "D - APWG"),
	};

	// копирование случайного элемента из массива шаблонов
	Plane newPlane = planes[getRand(0, size - 1)];

	// генерация данных

	// количество пассажиров
	int tmp = newPlane.getSeat();
	newPlane.setCount_passengers(getRand(0, tmp));

	// дистанция полёта
	tmp = newPlane.getDistance();
	newPlane.setDistance(getRand(tmp - 1000, tmp + 1000));

	// цена
	tmp = newPlane.getPrice();
	newPlane.setPrice(getRand(tmp - 10'000'000, tmp + 10'000'000));

	// новый номер
	char newNumber[Plane::NUMBER_SIZE + 1];

	// длина номера самолёта
	int len = strlen(newPlane.getNumber());

	strncpy(newNumber, newPlane.getNumber(), len);

	for (size_t i = 0; i < len; i++)
	{
		// текущий символ
		char ch = newNumber[i];

		// если текущий символ является цифрой 
		if (ch >= '0' && ch <= '9')
			ch = getRand('0', '9');

		// если текущий символ является буквой
		else if (ch >= 'A' && ch <= 'Z')
			ch = getRand('A', 'Z');

		newNumber[i] = ch;
	}

	newNumber[len] = 0;

	newPlane.setNumber(newNumber);

	return newPlane;
}

// создание заполнение массива (Plane)
Plane* App::fillArrPlane(int size)
{
	Plane* planes = new Plane[size];

	for (size_t i = 0; i < size; i++)
	{
		planes[i] = genPlane();
	}

	return planes;
}

#pragma endregion