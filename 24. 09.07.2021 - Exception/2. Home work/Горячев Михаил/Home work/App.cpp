#include "App.h"

/*
	Задача 1. Разработайте иерархию классов для работы с массивами чисел.
	Базовый шаблонный абстрактный класс Container содержит чистые виртуальные
	методы sort(), foreach(). 
		Метод sort() будет использоваться для сортировки данных в контейнере, 
	метод foreach() – для поэлементной обработки контейнера.
		Производные классы работают с данными типа double. При работе методов 
	поэлементной обработки контролировать условия выполнимости операции. Если 
	операция не выполнима – выбрасывать исключение, обрабатываемое в методе. 
		Разработайте собственный класс исключения, унаследованный от класса 
	exception. Передавать в исключение: сообщении об ошибке, значение элемента 
	массива, при обработке исключения сам элемент массива не менять. 
		В производном классе Bubble сортировка реализуется методом пузырька, 
	поэлементная обработка – извлечение квадратного корня.
		В производном классе Choice сортировка реализуется методом выбора, 
	поэлементная обработка – вычисление натурального логарифма log().
		В производном классе QSort сортировка реализуется методом быстрой сортировки,
	вызовом функции qsort(),  поэлементная обработка – вычисление десятичного 
	логарифма log10().

	Задача 2. Разработать консольное приложение, с использованием класса Person, 
	двусвязного списка (класс DblList<Person>)объектов класса Person. Примените 
	функциональные try-блоки в конструкторах класса Person.
	Класс Person имеет поля:
		Табельный номер, целое число, уникальное в пределах приложения
		Фамилия и инициалы – динамическое поле, char *
		Оклад, вещественное число, double
		Год поступления на работу, int
		Количество рабочих дней в месяце, int
		Количество фактически отработанных дней в месяце, int
	Разработать конструкторы и деструктор, аксессоры, метод вычисления начислений
	– произведение оклада на отношение количества фактически отработанных дней к 
	количеству рабочих дней в месяце.
	Начислено=Оклад∙ (Фактически отработано)/(Рабочих дней в месчце)
		Создать двусвязный список из объектов класса Person–не менее 12 элементов, 
		показать работу конструкторов, методов, генерацию и обработку исключений. 
		Разработать функцию, вычисляющую сумму начислений по двусвязному списку персон
		Добавить данные списка в бинарное дерево поиска, использовать табельный номер
		для записи в бинарное дерево поиска, вывести данные из бинарного дерева поиска 
		в порядке возрастания табельных номеров
*/

#pragma region Задание 1

/*
	Задача 1. Разработайте иерархию классов для работы с массивами чисел.
	Базовый шаблонный абстрактный класс Container содержит чистые виртуальные
	методы sort(), foreach().
	Метод sort() будет использоваться для сортировки данных в контейнере,
	метод foreach() – для поэлементной обработки контейнера.
	Производные классы работают с данными типа double. При работе методов
	поэлементной обработки контролировать условия выполнимости операции. Если
	операция не выполнима – выбрасывать исключение, обрабатываемое в методе.
	Разработайте собственный класс исключения, унаследованный от класса
	exception.Передавать в исключение: сообщении об ошибке, значение элемента
	массива, при обработке исключения сам элемент массива не менять.
	В производном классе Bubble сортировка реализуется методом пузырька,
	поэлементная обработка – извлечение квадратного корня.
	В производном классе Choice сортировка реализуется методом выбора,
	поэлементная обработка – вычисление натурального логарифма log().
	В производном классе QSort сортировка реализуется методом быстрой сортировки,
	вызовом функции qsort(),  поэлементная обработка – вычисление десятичного
	логарифма log10().
*/

// Задание 1. Работа с массивами вещественных чисел (double)
void App::task1()
{
	init(L"Задание 1. Работа с массивами вещественных чисел (double)");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Демонстрация функций Bubble
		CMD_DEMO_BUBBLE,
		// Демонстрация функций Choice
		CMD_DEMO_CHOICE,
		// Демонстрация функций QSort
		CMD_DEMO_QSORT
	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Демонстрация функций Bubble", CMD_DEMO_BUBBLE),
		MenuItem("Демонстрация функций Choice", CMD_DEMO_CHOICE),
		MenuItem("Демонстрация функций QSort", CMD_DEMO_QSORT),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 1. Работа с массивами вещественных чисел (double)", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Демонстрация функций Bubble
			case CMD_DEMO_BUBBLE:
				app.demoBubble();
				break;
				// Демонстрация функций Choice
			case CMD_DEMO_CHOICE:
				app.demoChoice();
				break;
				// Демонстрация функций QSort
			case CMD_DEMO_QSORT:
				app.demoQSort();
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

// Демонстрация функций Bubble
void App::demoBubble()
{
	showNavBarMessage(hintColor, "Демонстрация функций Bubble");

	cout << "\n\n";

	// таблица с демонстрацией функций
	showTable("Bubble", "Пузырёк", "Квадратный корень", bubble_);

	cout << "\n\n\n";

	getKey();
}

// Демонстрация функций Choice
void App::demoChoice()
{
	showNavBarMessage(hintColor, "Демонстрация функций Choice");

	cout << "\n\n";

	// таблица с демонстрацией функций
	showTable("Choice", "Выбором", "log", choice_);

	cout << "\n\n\n";

	getKey();
}

// Демонстрация функций QSort
void App::demoQSort()
{
	showNavBarMessage(hintColor, "Демонстрация функций QSort");

	cout << "\n\n";

	// таблица с демонстрацией функций
	showTable("QSort", "Быстрая", "log10", qSort_);

	cout << "\n\n\n";

	getKey();
}

// вывод таблицы 
void App::showTable(const char* nameClass, const char* nameSort, const char* nameForeach, Container<double>& container)
{
	// текущий цвет
	short cl = getColor();

	cout << fixed;
	cout.precision(2);

	// вывод названия класса
	cout << " +————————————+———————————————————————+———————————————————————————————+———————————————————————————————————————————————+\n"
		<< " | Размер: " << color(GREEN_ON_BLACK) << setw(2) << container.getSize() << color(cl)
		<< " | Класс: " << color(GREEN_ON_BLACK) << left << setw(14) << nameClass << color(cl)
		<< " | Сортировка: " << color(GREEN_ON_BLACK) << setw(17) << nameSort << color(cl)
		<< " | Поэлементная обработка: " << color(GREEN_ON_BLACK) << setw(21) << nameForeach << color(cl) << right
		<< " |\n";

	// вывод элементов
	showElem(container);

	// вывод названия сортировки 
	cout << " |                                                Сортировка: " << color(GREEN_ON_BLACK) << left << setw(20) << nameSort << right << color(cl) << "                                    |\n";
	
	// сортировка 
	container.sort();

	// вывод элементов
	showElem(container);

	// вывод названия поэлементной обработки
	cout << " |                                    Поэлементная обработка: " << color(GREEN_ON_BLACK) << left << setw(20) << nameForeach << right << color(cl) << "                                    |\n";

	// поэлементная обработка
	container.foreach();

	// вывод элементов
	showElem(container);
}

// вывод элементов
void App::showElem(Container<double>& container)
{
	// количество элементов
	int size = container.getSize();

	// текущий цвет 
	short cl = getColor();

	// вывод линии
	cout << " +————————————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+\n";

	// вывод индексов 
	cout << " |  Индекс    | ";

	for (int i = 0; i < size; i++)
	{
		cout << color(YELLOW_ON_BLACK) << setw(5) << i << color(cl) << " | ";
	}

	// вывод линии
	cout << "\n +————————————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+\n";

	// вывод значений
	cout << right << " | Значение   | ";

	for (int i = 0; i < size; i++)
	{
		cout << color(GREEN_ON_BLACK) << setw(5) << container[i] << color(cl) << " | ";
	}

	cout << left;

	// вывод линии
	cout << "\n +————————————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+———————+\n";
}

// инициалзиция конейнера 
void App::fillContainer(Container<double>& container, double minValue, double maxValue, int n)
{
	// массив для заполения
	double* arr = new double[n] {0};

	// заполнение массива числами из диапазона
	for (int i = 0; i < n; i++)
	{
		arr[i] = getRand(minValue, maxValue);
	}

	// заполнение контейнера массивом
	container.setData(arr, n);

	// отчистка памяти
	delete[]arr;
}

#pragma endregion

#pragma region Задание 2. 

/*
	Задача 2. Разработать консольное приложение, с использованием класса Person,
	двусвязного списка (класс DblList<Person>)объектов класса Person. Примените
	функциональные try-блоки в конструкторах класса Person.
	Класс Personимеет поля:
		Табельный номер, целое число, уникальное в пределах приложения
		Фамилия и инициалы – динамическое поле, char *
		Оклад, вещественное число, double
		Год поступления на работу, int
		Количество рабочих дней в месяце, int
		Количество фактически отработанных дней в месяце, int
	Разработать конструкторы и деструктор, аксессоры, метод вычисления начислений
	– произведение оклада на отношение количества фактически отработанных дней к
	количеству рабочих дней в месяце.
	Начислено=Оклад∙ (Фактически отработано)/(Рабочих дней в месчце)
		Создать двусвязный список из объектов класса Person–не менее 12 элементов,
		показать работу конструкторов, методов, генерацию и обработку исключений.
		Разработать функцию, вычисляющую сумму начислений по двусвязному списку персон
		Добавить данные списка в бинарное дерево поиска, использовать табельный номер
		для записи в бинарное дерево поиска, вывести данные из бинарного дерева поиска
		в порядке возрастания табельных номеров
*/

// Задание 2. Список рабочих
void App::task2()
{

	init(L"Задание 2. Список рабочих");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Заполнение списка рабочих
		CMD_FILL,
		// Генерация исключений при добавлении в список
		CMD_ADD_EX,
		// Генерация исключений при создании объекта
		CMD_CREATE_EX,
		// Вывод двусвязого списка
		CMD_PRINT_LIST,
		// Вывод бинарного дерева
		CMD_PRINT_TREE

	};

	// количество пунктов меню
	const int N_MENU = 6;

	MenuItem items[N_MENU] = {
		MenuItem("Заполнение списка рабочих", CMD_FILL),
		MenuItem("Генерация исключений при добавлении в список", CMD_ADD_EX),
		MenuItem("Генерация исключений при создании объекта", CMD_CREATE_EX),
		MenuItem("Вывод двусвязого списка", CMD_PRINT_LIST),
		MenuItem("Вывод бинарного дерева", CMD_PRINT_TREE),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 2. Список рабочих", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Заполнение списка рабочих
			case CMD_FILL:
				app.fillPersons();
				break;
				// Генерация исключений при добавлении в список
			case CMD_ADD_EX:
				app.genExceptionAddList();
				break;
				// Генерация исключений при создании объекта
			case CMD_CREATE_EX:
				app.genExceptionCreate();
				break;
				// Вывод двусвязого списка
			case CMD_PRINT_LIST:
				app.printList();
				break;
				// Вывод бинарного дерева
			case CMD_PRINT_TREE:
				app.printTree();
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

// Заполнение списка рабочих
void App::fillPersons()
{
	cls();

	showNavBarMessage(hintColor, "Заполнение списка рабочих");

	cputs("\n———————————————————————————————————————————————— ДВУСВЯЗНЫЙ СПИСОК ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

	cputs("\n————————————————————————————————————————————————— БИНАРНОЕ ДЕРЕВО ————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод дерева
	showPerson(tree_);

	// заполнение двусвязного списка 
	addAllPerson(personsByList_, SIZE_FILL_ARR, list_);

	// заполенение бинарного дерева
	addAllPerson(personsByTree_, SIZE_FILL_ARR, tree_);

	cputs("\n————————————————————————————————————————————————— ПОСЛЕ ЗАПОЛНЕНИЯ ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	cputs("\n———————————————————————————————————————————————— ДВУСВЯЗНЫЙ СПИСОК ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

	cputs("\n————————————————————————————————————————————————— БИНАРНОЕ ДЕРЕВО ————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод дерева
	showPerson(tree_);

	getKey();
}

// Генерация исключений
void App::genExceptionAddList()
{
	cls();

	showNavBarMessage(hintColor, "Заполнение списка рабочих");

	cputs("\n———————————————————————————————————————————————— ДВУСВЯЗНЫЙ СПИСОК ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

	cputs("\n————————————————————————————— ДОБАВЛЕНИЕ ЭЛЕМЕНТА С НЕ УНИКАЛЬНЫМ ТАБЕЛЬНЫМ НОМЕРОВ ————————————————————————————————\n\n", YELLOW_ON_BLACK);

	Person::showHead();

	Person exPers = Person(654878, "Кононов  Т.Д", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15));

	exPers.showElem(1);

	Person::showLine();

	cout << "\n\n\n";

	addPerson(exPers, list_);

	cout << "\n\n\n";

	getKey();
}

// Генерация исключений при создании объекта
void App::genExceptionCreate()
{
	cls();

	showNavBarMessage(hintColor, "Генерация исключений при создании объекта");

	cputs("\n———————————————————————— СОЗДАНИЕ ЭЛЕМЕНТА С НЕПРАВИЛЬНЫМ КОЛИЧЕСТВОМ ОТРАБОТАННЫХ ДНЕЙ ————————————————————————————\n\n", YELLOW_ON_BLACK);

	// Табельный номер, целое число, уникальное в пределах приложения unsigned int
	unsigned int number_;

	// Фамилия и инициалы – динамическое поле, char*
	char* name_;

	// Оклад, вещественное число, double
	double salary_;

	// Год поступления на работу, int
	int year_;

	// Количество рабочих дней в месяце, int
	int monthWorkDay_;

	// Количество фактически отработанных дней в месяце, int
	int completedWorkDay_;

	short cl = getColor();

	cout << "\t+——————————————————————————————————————————————————————————————————————————+\n"
		<< "\t|                           Данные для заполнения                          |\n"
		<< "\t+————————————————————————————————————+—————————————————————————————————————+\n"
		<< "\t|               Поле                 |               Данные                |\n"
		<< "\t+————————————————————————————————————+—————————————————————————————————————+\n"
		<< "\t|  " << color(YELLOW_ON_BLACK) << "Табельный номер                  " << color(cl) << " | "
		<< color(GREEN_ON_BLACK) << " 751742                            " << color(cl) << " |\n"
		<< "\t|  " << color(YELLOW_ON_BLACK) << "Фамилия и инициалы               " 
		<< color(cl) << " | " << color(GREEN_ON_BLACK) << "Ершов А.К                          " << color(cl) << " | \n"
		<< "\t|  " << color(YELLOW_ON_BLACK) << "Оклад                            " 
		<< color(cl) << " | " << color(GREEN_ON_BLACK) << " 10 000                            " << color(cl) << " |\n"

		<< "\t|  " << color(YELLOW_ON_BLACK) << "Год поступления на работу        " 
		<< color(cl) << " | " << color(GREEN_ON_BLACK) << " 2004                              " << color(cl) << " |\n"
		<< "\t|  " << color(YELLOW_ON_BLACK) << "Количество рабочих дней в месяце "
		<< color(cl) << " | " << color(GREEN_ON_BLACK) << " 15                                " << color(cl) << " |\n"
		<< "\t|  " << color(YELLOW_ON_BLACK) << "Количество фактически отработанных" 
		<< color(cl) << "| " << color(RED_ON_BLACK) << " 18    -    НЕПРАВИЛЬНЫЕ ДАННЫЕ    " << color(cl) << " |\n"
		<< "\t+————————————————————————————————————+—————————————————————————————————————+\n";

	Person(751742, "Ершов А.К", 10'000., 2004, 15, 18);

	getKey();
}

// Вывод бинарного дерева
void App::printTree()
{
	cls();

	showNavBarMessage(hintColor, "Генерация исключений при создании объекта");

	cputs("\n————————————————————————————————————————————————— БИНАРНОЕ ДЕРЕВО ————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод дерева
	showPerson(tree_);

	cout << "\n\n\n";

	getKey();
}

// Вывод двусвязого списка
void App::printList()
{
	cls();

	showNavBarMessage(hintColor, "Генерация исключений при создании объекта");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод дерева
	showPerson(list_);

	cout << "\n\n\n";

	getKey();
}


// сумма начислений по двусвязному списку
double App::accruedAll(DblList<Person> list)
{
	// итератор по списку
	DblList<Person>::Iterator<Person> iterator(list);

	double summ = 0.;

	// подсчёт суммы
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		summ += (*iterator).accrued();
	}

	return summ;
}

// добавление одного элемента в список
void App::addPerson(Person& person, DblList<Person> list)
{
	// табельный номер
	unsigned int number = person.getNumber();

	// если номер зарегистрирован неуспешно
	if (!registrationNumber(number))
	{
		stringstream os;

		os << "App: Табельный номер " << setw(15) << number << " не уникален!";

		throw exception(os.str().c_str());
	}

	// добовление в список
	list_.add(person);
}

// добавление одного элемента в дерево
void App::addPerson(Person& person, BinaryTree<Person> tree)
{
	// табельный номер
	unsigned int number = person.getNumber();

	// если номер зарегистрирован неуспешно
	if (!registrationNumber(number))
	{
		stringstream os;

		os << "App: Табельный номер " << setw(15) << number << " не уникален!";

		throw exception(os.str().c_str());
	}

	// добавление в бинарное дерево
	tree_.add(person);
}

// добавление массива элементов в список
void App::addAllPerson(Person* data, int n, DblList<Person> list)
{
	for (int i = 0; i < n; i++)
	{
		addPerson(data[i], list);
	}
}

// добавление массива элементов в дерево
void App::addAllPerson(Person* data, int n, BinaryTree<Person> tree)
{
	for (int i = 0; i < n; i++)
	{
		addPerson(data[i], tree);
	}
}

// добавление номера в базу номеров
bool App::registrationNumber(unsigned int number)
{
	// если в базе уже есть такой номер
	if (numberBase_.find(number) != nullptr)
		return false;

	// добавление в базу
	numberBase_.add(number);

	return true;
}

// обход узлов дерева для вывода в таблицу
void App::showElementPerson(BinaryTree<Person>::NodeTree<Person>* node, int& index)
{
	// если текущий узел является nullptr
	if (node == nullptr) return;

	// прохождение по левому поддереву
	showElementPerson(node->getLeft(), index);

	// вывод текущего значения
	node->getData().showElem(index++);

	// прохождение по правому поддереву
	showElementPerson(node->getRight(), index);
}

// вывод дерева в таблицу
void App::showPerson(BinaryTree<Person> tree)
{
	// шапка таблицы
	Person::showHead();

	// если в дереве нет данных
	if (tree.isEmpty())
	{
		Person::showEmpty();
		return;
	}

	int i = 1;

	// обход узлов дерева для вывода в таблицу
	showElementPerson(tree.getRoot(), i);

	// вывод подвала таблицы
	Person::showLine();
}

// вывод списка в виде таблицы
void App::showPerson(DblList<Person> list)
{
	// текущий цвет
	short cl = getColor();

	// шапка таблицы
	Person::showHead();

	// если в списке нет данных
	if (list.isEmpty())
	{
		Person::showEmpty();
		return;
	}

	// итератор по списку
	DblList<Person>::Iterator<Person> iterator(list);

	int i = 1;

	// вывод элементов
	for (iterator.begin(); iterator != iterator.end(); ++iterator, i++)
	{
		(*iterator).showElem(i);
	}

	// вывод подвала таблицы
	Person::showLine();

	cout<< " |                                                                              | " 
		<< color(YELLOW_ON_BLACK) << "СУММА НАЧИСЛЕНИЙ:   " << color(cl) << " | "
		<< setw(12) << accruedAll(list_) << " |\n"
		<< " +——————————————————————————————————————————————————————————————————————————————+——————————————————————+——————————————+\n";
}

#pragma endregion
