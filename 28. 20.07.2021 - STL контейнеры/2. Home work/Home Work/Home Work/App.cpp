#include "App.h"

/*
 * Задача 1.Напишите решения задач для развития навыков работы с контейнерными
 * классами STL.Тип данных, который обрабатывается в задачах –int, коллекции
 * заполнять случайными числами:
 * •	Дан непустой стек. Создать два новых стека, переместив в первый из них все
 *		элементы исходного стека с четными значениями, а во второй — с нечетными
 *		(элементы в новыхстеках будут располагаться в порядке, обратном исходному;
 *		один из этихстеков может оказаться пустым). Вывести стеки до и после обработки.
 * •	Даны две непустые очереди. Перемещать элементы из начала первой очереди в конец
 *		второй, пока значение начального элемента первой очереди не станет четным (если
 *		 первая очередь не содержит четных элементов,то переместить из первой очереди во
 *		 вторую все элементы). Вывести очереди до и после обработки.
 * •	Дан двусвязный список, содержащий не менее двух элементов. Вывести этот список.
 *		Продублировать в списке первый и последний элементы (новые элементы добавлять
 *		перед существующими элементами),вывести преобразованный список.
 *
 * Задача 2. Сведения о каждом автобусе содержат: регистрационный номер автобуса,
 * фамилию и инициалы водителя, назначенный номер маршрута, фактический номер маршрута.
 *
 * Нахождение в парке – особый маршрут с номером «0», в состав номера маршрута входят
 * как цифры, так и буквы, например – «42», «42а», «32в».Хранение всех необходимых коллекций
 * организовать с применением контейнерного класса map. В качестве ключа использовать значение
 * поля «регистрационный номер автобуса», в качестве значения – собственно данные автобуса
 * (т.е. map<string, Bus>).
 *
 * Приложение должно обеспечивать выбор с помощью меню и выполнение одной изследующих функций:
 * •	начальное формирование коллекции данных обо всех автобусах, копирование этой коллекции
 *		в коллекции автобусов, находящихся в парке, находящихся на маршруте, сохранение коллекции
 *		всех автобусов в бинарном файле (если такого файла нет) и чтение данных в коллекцию из
 *		бинарного файла (если такой файл есть);
 * •	имитация выезда автобуса из парка: вводится номер автобуса; удаляются данные об этом
 *		автобусе из коллекции автобусов, находящихся в парке, и записывает эти данные в коллекцию
 *		автобусов, находящихся на маршрутах; выводятся данные автобусов в парке и на маршруте;
 *		корректируются данные в коллекции всех автобусов, измененные данные сохраняются в бинарном
 *		 файле
 * •	имитация въезда автобуса в парк: вводится номер автобуса; удаляются данные об этом автобусе
 *		из коллекции автобусов, находящихся на маршрутах, и записываются эти данные в коллекцию
 *		автобусов, находящихся в парке;выводятся данные автобусов в парке и на маршруте;
 *		корректируются данные в коллекции всех автобусов, измененные данные сохраняются в бинарном
 *		файле
 * •	вывод сведений обо всех автобусах, об автобусах, находящихся в парке, и об автобусах,
 *		находящихся на маршрутах, упорядоченных по номерам маршрутов.
*/


#pragma region Задание 1. Работа с контейнерами

/*
 * Задача 1.Напишите решения задач для развития навыков работы с контейнерными
 * классами STL.Тип данных, который обрабатывается в задачах –int, коллекции
 * заполнять случайными числами:
 * •	Дан непустой стек. Создать два новых стека, переместив в первый из них все
 *		элементы исходного стека с четными значениями, а во второй — с нечетными
 *		(элементы в новыхстеках будут располагаться в порядке, обратном исходному;
 *		один из этих стеков может оказаться пустым). Вывести стеки до и после обработки.
 * •	Даны две непустые очереди. Перемещать элементы из начала первой очереди в конец
 *		второй, пока значение начального элемента первой очереди не станет четным (если
 *		первая очередь не содержит четных элементов,то переместить из первой очереди во
 *		вторую все элементы). Вывести очереди до и после обработки.
 * •	Дан двусвязный список, содержащий не менее двух элементов. Вывести этот список.
 *		Продублировать в списке первый и последний элементы (новые элементы добавлять
 *		перед существующими элементами),вывести преобразованный список.
*/

// Задание 1. Работа с контейнерами
void App::task1()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Разделение стека на стек с отрицательными и положительными значениями
		CMD_STACK,
		// Перемещение элементов из исходной очереди до четного значения
		CMD_QUEUE,
		// Дублирование первого и последенго элементов в двусвязном списке
		CMD_LIST
	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Разделение стека на стек с отрицательными и положительными значениями", CMD_STACK),
		MenuItem("Перемещение элементов из исходной очереди до четного значения", CMD_QUEUE),
		MenuItem("Дублирование первого и последенго элементов в двусвязном списке", CMD_LIST),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 1. Работа с контейнерами", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Разделение стека на стек с отрицательными и положительными значениями
			case CMD_STACK:
				app.stackDemo();
				break;
				// Перемещение элементов из исходной очереди до четного значения
			case CMD_QUEUE:
				app.queueDemo();
				break;	
				// Дублирование первого и последенго элементов в двусвязном списке
			case CMD_LIST:
				app.listDemo();
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
} // App::task1()

// вывод линии для таблицы
void App::showLine()
{
	cout << "    +————————————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+\n";
} // App::showLine()

// вывод сообщения об отсутвии данных для таблицы
void App::showEmpty()
{
	// текущий цвет
	short cl = getColor();

	cout << "    |  " << color(LTRED_ON_BLACK)
		<< "                                                 НЕТ ДАННЫХ                                                "
		<< color(cl) << " | \n";
} // App::showEmpty()

#pragma region Stack

// Разделение стека на стеки с отрицательными и положительными значениями
void App::stackDemo()
{
	cls();

	showNavBarMessage(hintColor, "Разделение стека на стеки с отрицательными и положительными значениями");

	// исходный стек 
	stack<int> source;

	// заполнение стека 
	fillStack(source, 10);

	// вывод исходного стека до разделения
	outStack(source, "Исходный стек", "До разделения", LTGREEN_ON_BLACK);

	cputs("\n ———————————————————————————————————————————————————————————————————————————————————————————————————————————————— \n\n", YELLOW_ON_BLACK);

	// стеки для отрицательных и положительных элементов
	stack<int> pos, neg;

	// разделение стека на стеки с отрицательными и положительными значениями
	separationStack(source, neg, pos);

	// вывод исходного стека после изменения
	outStack(source, "Исходный стек", "После разделения", LTGREEN_ON_BLACK);

	cout << "\n\n";

	// вывод стека с положительными элементами
	outStack(pos, "Стек с положительными элементами", "После разделения", LTRED_ON_BLACK);

	// вывод стека с отрицательными элементами
	outStack(neg, "Стек с отрицательными элементами", "После разделения", LTCYAN_ON_BLACK);

	getKey();

} // App::stackDemo()

// заполнение стека 
void App::fillStack(stack<int>& source, int n)
{
	for (int i = 0; i < n; i++)
	{
		source.push(getRand(-10, 10));
	}
} // App::fillStack()

// разделение стека на стеки с отрицательными и положительными значениями по заданию
void App::separationStack(stack<int>& source, stack<int>& neg, stack<int>& pos)
{
	// размер исходого стека 
	int n = source.size();

	// разделение исходого стека 
	for (int i = 0; i < n; i++)
	{
		// элемент
		int val = source.top();

		// удаление элемента 
		source.pop();

		// если значение положительное 
		if (val >= 0)
			pos.push(val);
		// иначе 
		else
			neg.push(val);
	}
} // App::separationStack()

// вывод стека 
void App::outStack(stack<int> source, string type, string descript, short colorElem)
{
	// размер стека 
	int n = source.size();

	// текущий цвет
	short cl = getColor();

	cout<< "    +————————————+————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
		<< "    | Размер: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | Тип данных: " << left << color(YELLOW_ON_BLACK) << setw(34) << type << color(cl)
		<< " | Описание: " << color(YELLOW_ON_BLACK) << setw(36) << descript << color(cl) << right << " |\n";

	// вывод разделительной линии
	showLine();

	// если в стеке нет данных
	if (source.empty())
	{
		showEmpty();
		showLine();
		return;
	}

	cout << "    |  Значения  | ";

	// вывод элементов 
	for (int i = 0; i < n; i++)
	{
		// вывод элемента 
		cout << color(colorElem) << setw(4) << source.top() << color(cl) << " | ";

		source.pop();
	}

	cout << "\n";

	// вывод разделительной линии
	showLine();

} // outStack()

#pragma endregion

#pragma region Queue

// Перемещение элементов из исходной очереди до четного значения
void App::queueDemo()
{
	cls();

	showNavBarMessage(hintColor, "Перемещение элементов из исходной очереди до четного значения");

	// исходная очередь 
	queue<int> source;

	// заполнение очереди 
	fillQueue(source, 10);

	// вывод исходной очереди до перемещения
	outQueue(source, "Исходная очредь", "До перемещения", LTGREEN_ON_BLACK);

	cputs("\n ———————————————————————————————————————————————————————————————————————————————————————————————————————————————— \n\n", YELLOW_ON_BLACK);

	// очередь для перемещения 
	queue<int> result;

	// перемещение элементов из исходной очереди до четного значения
	movingQueue(source, result);

	// вывод исходного стека после изменения
	outQueue(source, "Исходная очредь", "После перемещения", LTGREEN_ON_BLACK);

	cout << "\n\n";

	// вывод результирующей очереди после перемещения
	outQueue(result, "Результирующая очередь", "После перемещения", LTGREEN_ON_BLACK);

	getKey();

} // App::queueDemo()

// перемещение элементов из исходной очереди до четного значения по заданию 
void App::movingQueue(queue<int>& source, queue<int>& dest)
{
	// размер исходной очереди
	int n = source.size();

	for (int i = 0; i < n; i++ )
	{
		// текущий элемент
		int item = source.front();

		// если значение отрицательное 
		if (item < 0)
			return;

		// добавление элемента в очередь
		dest.push(item);

		// удаление элемента из исходной очереди
		source.pop();
	}
} // App::movingQueue()

// заполнение очереди
void App::fillQueue(queue<int>& source, int n)
{
	for (int i = 0; i < n; i++)
	{
		source.push(getRand(-10, 10));
	}

} // App::fillQueue()

// вывод очереди
void App::outQueue(queue<int> source, string type, string descript, short colorElem)
{
	// размер очереди 
	int n = source.size();

	// текущий цвет
	short cl = getColor();

	cout << "    +————————————+————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
		<< "    | Размер: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | Тип данных: " << left << color(YELLOW_ON_BLACK) << setw(34) << type << color(cl)
		<< " | Описание: " << color(YELLOW_ON_BLACK) << setw(36) << descript << color(cl) << right << " |\n";

	// вывод разделительной линии
	showLine();

	// если в стеке нет данных
	if (source.empty())
	{
		showEmpty();
		showLine();
		return;
	}

	cout << "    |  Значения  | ";

	// вывод элементов 
	for (int i = 0; i < n; i++)
	{
		// вывод элемента 
		cout << color(colorElem) << setw(4) << source.front() << color(cl) << " | ";

		source.pop();
	}

	cout << "\n";

	// вывод разделительной линии
	showLine();

} // App::outQueue()

#pragma endregion

#pragma region List

// Дублирование первого и последенго элементов в двусвязном списке
void App::listDemo()
{
	cls();

	showNavBarMessage(hintColor, "Дублирование первого и последенго элементов в двусвязном списке");

	// исходный список
	list<int> source;

	// заполнение списка 
	fillList(source, 10);

	// вывод исходного списка до добавления
	outList(source, "Исходный список", "До добавления", LTGREEN_ON_BLACK);

	cputs("\n ———————————————————————————————————————————————————————————————————————————————————————————————————————————————— \n\n", YELLOW_ON_BLACK);

	// дублирование первого и последенго элементов в двусвязном спискея
	dublicationList(source);

	// вывод исходного списка после изменения
	outList(source, "Исходная список", "После добавления", LTGREEN_ON_BLACK);

	cout << "\n\n";

	getKey();

} // App::listDemo()

// дублирование первого и последенго элементов в двусвязном списке по заданию
void App::dublicationList(list<int>& source)
{
	// если список пуст 
	if (source.empty())
		throw exception("App: Список пуст");

	source.insert(source.begin(), source.front());
	source.insert(source.end(), source.back());
}

// заполнение списка
void App::fillList(list<int>& source, int n)
{
	for (int i = 0; i < n; i++)
	{
		source.push_back(getRand(-10, 10));
	}
}

// вывод списка
void App::outList(list<int> source, string type, string descript, short colorElem)
{
	// размер списка 
	int n = source.size();

	// текущий цвет
	short cl = getColor();

	cout << "    +————————————+————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
		<< "    | Размер: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | Тип данных: " << left << color(YELLOW_ON_BLACK) << setw(34) << type << color(cl)
		<< " | Описание: " << color(YELLOW_ON_BLACK) << setw(36) << descript << color(cl) << right << " |\n";

	// вывод разделительной линии
	showLine();

	// если в стеке нет данных
	if (source.empty())
	{
		showEmpty();
		showLine();
		return;
	}

	cout << "    |  Значения  | ";

	// вывод элементов 
	for (auto item: source)
	{
		// вывод элемента 
		cout << color(colorElem) << setw(4) << item << color(cl) << " | ";
	}

	cout << "\n";

	// вывод разделительной линии
	showLine();
}

#pragma endregion

#pragma endregion 

#pragma region Задание 2. Автобусный парк

/*
 * Задача 2. Сведения о каждом автобусе содержат: регистрационный номер автобуса,
 * фамилию и инициалы водителя, назначенный номер маршрута, фактический номер маршрута.
 *
 * Нахождение в парке – особый маршрут с номером «0», в состав номера маршрута входят
 * как цифры, так и буквы, например – «42», «42а», «32в».Хранение всех необходимых коллекций
 * организовать с применением контейнерного класса map. В качестве ключа использовать значение
 * поля «регистрационный номер автобуса», в качестве значения – собственно данные автобуса
 * (т.е. map<string, Bus>).
 *
 * Приложение должно обеспечивать выбор с помощью меню и выполнение одной изследующих функций:
 * •	начальное формирование коллекции данных обо всех автобусах, копирование этой коллекции
 *		в коллекции автобусов, находящихся в парке, находящихся на маршруте, сохранение коллекции
 *		всех автобусов в бинарном файле (если такого файла нет) и чтение данных в коллекцию из
 *		бинарного файла (если такой файл есть);
 * •	имитация выезда автобуса из парка: вводится номер автобуса; удаляются данные об этом
 *		автобусе из коллекции автобусов, находящихся в парке, и записывает эти данные в коллекцию
 *		автобусов, находящихся на маршрутах; выводятся данные автобусов в парке и на маршруте;
 *		корректируются данные в коллекции всех автобусов, измененные данные сохраняются в бинарном
 *		файле
 * •	имитация въезда автобуса в парк: вводится номер автобуса; удаляются данные об этом автобусе
 *		из коллекции автобусов, находящихся на маршрутах, и записываются эти данные в коллекцию
 *		автобусов, находящихся в парке;выводятся данные автобусов в парке и на маршруте;
 *		корректируются данные в коллекции всех автобусов, измененные данные сохраняются в бинарном
 *		файле
 * •	вывод сведений обо всех автобусах, об автобусах, находящихся в парке, и об автобусах,
 *		находящихся на маршрутах, упорядоченных по номерам маршрутов.
*/

// Задание 2. Автобусный парк
void App::task2()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Начальное формирование коллекции данных обо всех автобусах
		CMD_CREATE_PARK,
		// Выезд автобуса из парка
		CMD_EXIT,
		// Въезда автобуса в парк
		CMD_ENTRY,
		// Вывод сведений обо всех автобусах
		CMD_PRINT_ALL
	};

	// количество пунктов меню
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("Начальное формирование коллекции данных обо всех автобусах", CMD_CREATE_PARK),
		MenuItem("Выезд автобуса из парка", CMD_EXIT),
		MenuItem("Въезда автобуса в парк", CMD_ENTRY),
		MenuItem("Вывод сведений обо всех автобусах", CMD_PRINT_ALL),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 2. Автобусный парк", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
			// Начальное формирование коллекции данных обо всех автобусах
			case CMD_CREATE_PARK:
				app.createPark();
				break;
			// Выезд автобуса из парка
			case CMD_EXIT:
				app.exitBus();
				break;
			
			// Въезда автобуса в парк
			case CMD_ENTRY:
				app.entryBus();
				break;
				
			// Вывод сведений обо всех автобусах
			case CMD_PRINT_ALL:
				app.printAll();
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

} // App::task2()

// Начальное формирование коллекции данных обо всех автобусах
void App::createPark()
{
	cls();

	showNavBarMessage(hintColor, "Начальное формирование коллекции данных обо всех автобусах");

	const int SIZE_ARR = 12;

	// вывод автобусов
	showBus(mapBus_, "Все автобусы", "До заполнения");

	// если файла не существует 
	if (!isFile(busFile_))
	{
		// список автобусов
		Bus* busList = new Bus[SIZE_ARR + 1]
		{
			Bus("С227НА", "Бобров В.Б",    "42а", "0"),
			Bus("В754ОР", "Иванов Н.Г",    "41б", "41б"),
			Bus("А245РВ", "Дьячков В.Ф",   "76", "76"),
			Bus("С984ХВ", "Тарасов Н.Х",   "41б", "41б"),
			Bus("В425ОР", "Шашков Г.Л",    "42а", "42а"),
			Bus("У465ХИ", "Лобанов И.С",   "41б", "0"),
			Bus("О691ВО", "Третьяков О.Х", "76", "76"),
			Bus("Е943ОА", "Бирюков М.М",   "41б", "41б"),
			Bus("Н698НА", "Игнатов Н.В",   "42а", "0"),
			Bus("О789АР", "Логинов А.Е",   "76", "76"),
			Bus("Х438ОХ", "Ситников М.В",  "42а", "42а"),
			Bus("А879РО", "Кулаков Л.Я",   "41б", "0")
		};

		// заполнение автобусами
		for (int i = 0; i < SIZE_ARR; i++)
		{
			mapBus_[busList[i].getName()] = busList[i];
		}

		// сохранение в файл 
		saveMap(mapBus_, busFile_);
	}

	// загрузка из файла
	loadMap(mapBus_, busFile_);

	cout << endl;

	// вывод автобусов
	showBus(mapBus_, "Все автобусы", "После загрузки файла");

	cout << "\n\n\n";

	// вывод автобусов в парке 
	showBus(mapPark_, "Автобусы в парке", "После загрузки файла");

	cout << "\n\n\n";

	// вывод автобусов на рейсе  
	showBus(mapVoy_, "Автобусы на рейсе", "После загрузки файла");

	cout << "\n\n\n";

	getKey();


} // App::createPark()

// Выезд автобуса из парка
void App::exitBus()
{
	cls();

	showNavBarMessage(hintColor, "Выезд автобуса из парка");

	// загрузка из файла 
	loadMap(mapBus_, busFile_);

	// вывод автобусов в парке 
	showBus(mapPark_, "Автобусы в парке", "После загрузки файла");

	cout << "\n";

	// вывод автобусов на рейсе  
	showBus(mapVoy_, "Автобусы на рейсе", "После загрузки файла");

	cout << "\n\n";

	// номер автобуса 
	string number;

	// текущий цвет 
	short cl = getColor();

	// ввод номера автобуса 
	setCursorVisible(true);
	showInputLine("Введите номер автобуса: ", 12, hintColor);

	getline(cin, number);

	setCursorVisible(false);
	setColor(cl);

	// выезд автобуса 
	exitBusMap(mapBus_, mapPark_, mapVoy_, number);

	// вывод до сохранения в файл 
	showBus(mapBus_, "Все автобусы", "До сохранения в файл");

	cout << "\n";

	// вывод автобусов в парке 
	showBus(mapPark_, "Автобусы в парке", "До сохранения в файл");

	cout << "\n";

	// вывод автобусов на рейсе  
	showBus(mapVoy_, "Автобусы на рейсе", "До сохранения в файл");

	cout << "\n";

	// сохранение в файл
	saveMap(mapBus_, busFile_);

	cputs("\tДанные успешно сохранены!", GREEN_ON_BLACK);

	cout << "\n\n";

	getKey();

} // App::exitBus()

// выезд автобуса 
void App::exitBusMap(map<string, Bus>& mapBus, map<string, Bus>& mapPark, map<string, Bus>& mapVoy, string number)
{
	// поиск
	auto res = mapBus.find(number);

	// если такой номер не найден
	if (res == mapBus.end())
		throw exception("Такой номер не найден!");

	// автобус 
	Bus& bus = (*res).second;

	// если автобус находится на рейсе 
	if (bus.getRoutAct() != "0")
		throw exception("Автобус уже на рейсе!");

	// установка маршрута 
	bus.setRoutAct(bus.getRoutApp());

	// удаление из базы автобусов в парке 
	mapPark.erase(number);

	// добавление в базу автобусов на рейсе 
	mapVoy[number] = bus;
}

// Въезд автобуса в парк
void App::entryBus()
{
	cls();

	showNavBarMessage(hintColor, "Въезд автобуса в парк");

	// загрузка из файла 
	loadMap(mapBus_, busFile_);

	// вывод автобусов на рейсе  
	showBus(mapVoy_, "Автобусы на рейсе", "После загрузки файла");

	cout << "\n";

	// вывод автобусов в парке 
	showBus(mapPark_, "Автобусы в парке", "После загрузки файла");

	cout << "\n\n";

	// номер автобуса 
	string number;

	// текущий цвет 
	short cl = getColor();

	// ввод номера автобуса 
	setCursorVisible(true);
	showInputLine("Введите номер автобуса: ", 12, hintColor);

	getline(cin, number);

	setCursorVisible(false);
	setColor(cl);

	// въезд автобуса 
	entryBussMap(mapBus_, mapPark_, mapVoy_, number);

	// вывод до сохранения в файл 
	showBus(mapBus_, "Все автобусы", "До сохранения в файл");

	cout << "\n";

	// вывод автобусов на рейсе  
	showBus(mapVoy_, "Автобусы на рейсе", "До сохранения в файл");

	cout << "\n";

	// вывод автобусов в парке 
	showBus(mapPark_, "Автобусы в парке", "До сохранения в файл");

	cout << "\n";

	// сохранение в файл
	saveMap(mapBus_, busFile_);

	cputs("\tДанные успешно сохранены!", GREEN_ON_BLACK);

	cout << "\n\n";

	getKey();


} // App::entryBus()

// въезд автобуса 
void App::entryBussMap(map<string, Bus>& mapBus, map<string, Bus>& mapPark, map<string, Bus>& mapVoy, string number)
{
	// поиск
	auto res = mapBus.find(number);

	// если такой номер не найден
	if (res == mapBus.end())
		throw exception("Такой номер не найден!");

	// автобус 
	Bus& bus = (*res).second;

	// если автобус находится в парке 
	if (bus.getRoutAct() == "0")
		throw exception("Автобус уже в парке!");

	// установка маршрута 
	bus.setRoutAct("0");

	// удаление из базы автобусов на рейсе 
	mapVoy.erase(number);

	// добавление в базу автобусов в парке 
	mapPark[number] = bus;
}

// Вывод сведений обо всех автобусах
void App::printAll()
{
	cls();


	showNavBarMessage(hintColor, "Вывод сведений обо всех автобусах");

	// загрузка из файла
	loadMap(mapBus_, busFile_);

	// для вывода 
	multimap<string, Bus> muBus, muPark, muVoy;

	for (auto item : mapBus_)
	{
		// текущий элемент
		auto p = item.second;

		muBus.emplace(p.getRoutApp(), p);
	}

	for (auto item : mapPark_)
	{
		// текущий элемент
		auto p = item.second;

		muPark.emplace(p.getRoutApp(), p);
	}

	for (auto item : mapVoy_)
	{
		// текущий элемент
		auto p = item.second;

		muVoy.emplace(p.getRoutApp(), p);
	}


	cout << endl;

	// вывод автобусов
	showBus(muBus, "Все автобусы", "После загрузки файла");

	cout << "\n";

	// вывод автобусов в парке 
	showBus(muPark, "Автобусы в парке", "После загрузки файла");

	cout << "\n";

	// вывод автобусов на рейсе  
	showBus(muVoy, "Автобусы на рейсе", "После загрузки файла");

	cout << "\n";

	getKey();


	
} // App::printAll()

// вывод map автобусов
void App::showBus(map<string, Bus>& mapBus, string name, string specific)
{
	// вывод шапки таблицы
	showHeadBus(mapBus, name, specific);

	// если map пустая 
	if (mapBus.empty())
		showEmptyBus();

	// вывод элементов 
	showBusElem(mapBus);

	// вывод линии разделителя 
	showLineBus();

} // App::outBus()

// вывод шапки таблицы
void App::showHeadBus(map<string, Bus>& mapBus, string name, string specific)
{
	// теукщий цвет
	short cl = getColor();

	cout << "    +————————————+—————————————————————————————————+—————————————————————————————————+\n"
		<< "    | Размер: " << left << color(GREEN_ON_BLACK) << setw(2) << mapBus.size()
		<< color(cl) << " | Данные: " << color(GREEN_ON_BLACK) << setw(23) << name
		<< color(cl) << " | Описание: " << color(GREEN_ON_BLACK) << setw(21) << specific
		<< color(cl) << " |\n" << right
		<< "    +——————+—————+————————+——————————————————+—————+————————————————+————————————————+\n"
		<< "    |  N   |    Номер     |           ФИО          | Назн. маршрут  | Факт. маршрут  |\n"
		<< "    +——————+——————————————+————————————————————————+————————————————+————————————————+\n";
} // App::showHeadBus()

// вывод линии-разделителя
void App::showLineBus()
{
	cout << "    +——————+——————————————+————————————————————————+————————————————+————————————————+\n";
}

// вывод "пустоты" 
void App::showEmptyBus()
{
	// теукщий цвет
	short cl = getColor();

	cout << "    | " << color(LTRED_ON_BLACK)
		<< "                                    НЕТ ДАННЫХ                                "
		<< color(cl) << " |\n";
}

// вывод автобуса для таблицы
void App::showBusElem(map<string, Bus>& mapBus)
{
	short cl = getColor();

	int i = 1;

	for (auto item: mapBus)
	{
		// текущее значение 
		Bus p = item.second;

		cout << "    | " << setw(4) << i++ << " | " << left
			<< color(LTYELLOW_ON_BLACK) << setw(12) << p.getNumber()
			<< color(cl) << " | " 
			<< color(LTYELLOW_ON_BLACK) << setw(22) << p.getName()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutApp()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutAct()
			<< color(cl) << " | " << right << endl;
	}

} // showBusElem()

// вывод map автобусов
void App::showBus(multimap<string, Bus>& mapBus, string name, string specific)
{
	// вывод шапки таблицы
	showHeadBus(mapBus, name, specific);

	// если map пустая 
	if (mapBus.empty())
		showEmptyBus();

	// вывод элементов 
	showBusElem(mapBus);

	// вывод линии разделителя 
	showLineBus();

} // App::outBus()

// вывод шапки таблицы
void App::showHeadBus(multimap<string, Bus>& mapBus, string name, string specific)
{
	// теукщий цвет
	short cl = getColor();

	cout << "    +————————————+—————————————————————————————————+—————————————————————————————————+\n"
		<< "    | Размер: " << left << color(GREEN_ON_BLACK) << setw(2) << mapBus.size()
		<< color(cl) << " | Данные: " << color(GREEN_ON_BLACK) << setw(23) << name
		<< color(cl) << " | Описание: " << color(GREEN_ON_BLACK) << setw(21) << specific
		<< color(cl) << " |\n" << right
		<< "    +——————+—————+————————+——————————————————+—————+————————————————+————————————————+\n"
		<< "    |  N   |    Номер     |           ФИО          | Назн. маршрут  | Факт. маршрут  |\n"
		<< "    +——————+——————————————+————————————————————————+————————————————+————————————————+\n";
} // App::showHeadBus()

// вывод автобуса для таблицы
void App::showBusElem(multimap<string, Bus>& mapBus)
{
	short cl = getColor();

	int i = 1;

	for (auto item : mapBus)
	{
		// текущее значение 
		Bus p = item.second;

		cout << "    | " << setw(4) << i++ << " | " << left
			<< color(LTYELLOW_ON_BLACK) << setw(12) << p.getNumber()
			<< color(cl) << " | "
			<< color(LTYELLOW_ON_BLACK) << setw(22) << p.getName()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutApp()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutAct()
			<< color(cl) << " | " << right << endl;
	}

} // showBusElem()


// сохранение map в файл 
void App::saveMap(map<string, Bus>& mapBus, string nameFile)
{
	// отрктие файла в режиме бинарной записи
	fstream file(nameFile, ios::binary | ios::out);

	for (auto p: mapBus)
	{

		p.second.write(file);
	}

	file.close();
}

// загрузка map из файла 
void App::loadMap(map<string, Bus>& mapBus, string nameFile)
{
	mapBus.clear();

	// отрктие файла в режиме бинарной записи
	fstream file(nameFile, ios::binary | ios::in);

	Bus temp;

	while (!file.eof())
	{
		// считываение из файла
		temp.read(file);

		// номер текущего автобуса 
		string number = temp.getNumber();

		// если достигнут конец файла 
		if (file.eof()) break;

		// добавление в общую базу
		mapBus[number] = temp;

		// если автобус в парке 
		if (temp.getRoutAct() == "0")
			mapPark_[number] = temp;

		// если автобус на рейсе 
		else
			mapVoy_[number] = temp;
	}

	file.close();
}

// проверка на наличие файла 
bool App::isFile(string nameFile)
{
	fstream file(nameFile, ios::in);

	bool flag = file.is_open();

	file.close();

	return flag;
}

#pragma endregion 
