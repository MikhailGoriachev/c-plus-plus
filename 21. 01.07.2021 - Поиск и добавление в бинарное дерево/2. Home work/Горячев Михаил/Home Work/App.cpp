#include "App.h"
#include "Subscriber.h"

/*
	Задача 1.
	С использованием бинарного дерева поиска реализовать картотеку нуждающихся в
	улучшении жилищных условий. Начальное заполнение картотеки – из массива.
	Элемент картотеки должен хранить фамилию, имя и отчество претендента, количество
	членов семьи, площадь квартиры в м2, количество комнат, дату постановки на учет
	(день, месяц, год–класс Date). Добавление в картотеку выполняется по фамилии.
	Реализовать дополнительно операции:
		•	Поиск в картотеке по фамилии – находим первую подходящую фамилию, остальных
			однофамильцев игнорировать
		•	Запись в бинарный файл всех элементов картотеки (в файле данные будут
			упорядочены по алфавиту).
	Задача 2.
	Разработать класс для представления абонента телефонной станции с полями для
	хранения:
		•	фамилии и инициалов
		•	телефонного номера
		•	времени разговоров (в минутах) за последний месяц.
	Разработать класс для представления телефонной станции с полями для хранения
	названия телефонной станции (код станции – три цифровых символа), текущий тариф
	за минуту разговора абонента, картотеки абонентов в виде бинарного дерева поиска.
	Ключом для узлов является телефонный номер абонента.
	Создать объект телефонной станции, заполнить картотеку из массива (не менее 10
	записей), реализовать поиск по телефонному номеру, вывод сумм к оплате в порядке
	возрастания телефонных номеров.
*/

#pragma region Задание 1. Картотека нуждающихся в улучшении жилищных условий

/*
	Задача 1.
	С использованием бинарного дерева поиска реализовать картотеку нуждающихся в
	улучшении жилищных условий. Начальное заполнение картотеки – из массива.
	Элемент картотеки должен хранить фамилию, имя и отчество претендента, количество
	членов семьи, площадь квартиры в м2, количество комнат, дату постановки на учет
	(день, месяц, год–класс Date). Добавление в картотеку выполняется по фамилии.
	Реализовать дополнительно операции:
		•	Поиск в картотеке по фамилии – находим первую подходящую фамилию, остальных
			однофамильцев игнорировать
		•	Запись в бинарный файл всех элементов картотеки (в файле данные будут
			упорядочены по алфавиту).
*/

// Задание 1. Картотека нуждающихся в улучшении жилищных условий
void App::task1()
{
	init(L"Задание 1. Картотека нуждающихся в улучшении жилищных условий");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Поиск в картотеке по фамилии
		CMD_SEARCH_SURNAME,
		// Запись в бинарный файл всех элементов картотеки
		CMD_TASK_TWO,
	};

	// количество пунктов меню
	const int N_MENU = 3;

	MenuItem items[N_MENU] = {
		MenuItem("Поиск в картотеке по фамилии", CMD_SEARCH_SURNAME),
		MenuItem("Запись в бинарный файл всех элементов картотеки", CMD_TASK_TWO),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 1. Картотека нуждающихся в улучшении жилищных условий", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Поиск в картотеке по фамилии
			case CMD_SEARCH_SURNAME:
				app.searchSurname();
				break;
				// Задание 2
			case CMD_TASK_TWO:
				app.writeFormBinFile();
				break;
			} // switch (cmd)
		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();
		} // try-catch
	}
} // main

// поиск в картотеке по фамилии
void App::searchSurname()
{
	cls();

	// вывод заголовка
	showNavBarMessage(hintColor, "Поиск в картотеке по фамилии");

	cputs("     —————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод банарного дерева
	printBinaryTreeFormColor(forms_.getRoot());

	// фамилия для поиска
	char* surname = new char[Form::SURNAME_MAX_SIZE + 1];
	
	// текущий цвет
	short cl = getColor();

	// ввод фамилии для поиска
	showInputLine("\n\n\n     Введите фамилию для поиска: ", Form::SURNAME_MAX_SIZE - 20, WHITE_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(surname, Form::SURNAME_MAX_SIZE);

	// выключание курсора
	setCursorVisible(false);

	// установка цвета по умолчанию
	setColor(cl);

	// временный объект Form для поиска
	Form tmp;
	tmp.setSurname(surname);

	delete[] surname;

	// вывод результата
	cputs("     ———————————————————————————————————————————— РЕЗУЛЬТАТ ПОИСКА ———————————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// возвращенная Form
	BinaryTree<Form>::NodeTree<Form>* node = forms_.find(tmp);

	// заголовка таблицы
	cout << tmp.showHead();

	// если объект не найден
	if (node == nullptr)
		cout << "\t|                                           НЕ НАЙДЕНО                                                    |\n";
	else
	{

		tmp = node->getData();

		// вывод элемента 
		tmp.showColor();
	}

	cout << tmp.showLine();

	getKey();
}

// запись в бинарный файл всех элементов картотеки
void App::writeFormBinFile()
{
	cls();

	// вывод заголовка
	showNavBarMessage(hintColor, "Запись в бинарный файл всех элементов картотеки");

	// название файла 
	const char* nameFile = "save.bin";

	cputs("\n    ————————————————————————————————————————————— ИСХОДНОЕ ДЕРЕВО ——————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод банарного дерева
	printBinaryTreeFormColor(forms_.getRoot());

	// вывод имени файла
	cputs("    Файл для сохранения: ", GRAY_ON_BLACK);
	cputs(nameFile, GREEN_ON_BLACK);
	cout << "\n";

	// открытие файла в режиме бинарной записи
	FILE* file = fopen(nameFile, "wb");

	// если файл открыт неуспешно 
	if (file == nullptr)
	{
		throw exception("App: не удалось открыть файл");

	}

	// если файл открыт успешно
	// запись в файл
	forms_.write(file);

	// закрытие файла
	fclose(file);

	cputs("    Файл сохранён\n", GREEN_ON_BLACK);


	cputs("\n    ————————————————————————————————————————————— ПОСЛЕ СОХРАНЕНИЯ —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// новое пустое бинарное дерево
	BinaryTree<Form> newTree;

	// вывод банарного дерева
	printBinaryTreeFormColor(newTree.getRoot());

	// загрузка из файла
	cputs("\n    ———————————————————————————————————————————— ЗАГРУЗКА ИЗ ФАЙЛА —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// открытие файла в режиме бинарного чтения
	file = fopen(nameFile, "rb");

	// если файл открыт неуспешно 
	if (file == nullptr)
	{
		
		throw exception("App: не удалось открыть файл");

	}
	// если файл открыт успешно
	// чтение из файла
	newTree.read(file);

	// закрытие файла
	fclose(file);

	cputs("\n    —————————————————————————————————————————————— ПОСЛЕ ЗАГРУЗКИ ——————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод очереди
	printBinaryTreeFormColor(newTree.getRoot());

	getKey();

}

// обход узлов дерева для вывода в цвете объектов Form
void App::showFormColor(BinaryTree<Form>::NodeTree<Form>* node, short cl, int& i)
{
	// если текущий узел является nullptr
	if (node == nullptr) return;

	// прохождение по левому поддереву
	showFormColor(node->getLeft(), cl, i);

	// вывода элемента  цвете
	node->getData().showColor(i++);

	// прохождение по правому поддереву
	showFormColor(node->getRight(), cl, i);
}

// вывод бинарного дерева с объектами Form в цвете
void App::printBinaryTreeFormColor(BinaryTree<Form>::NodeTree<Form>* node)
{
	cout << Form::showHead();

	// если в дереве нет данных
	if (node == nullptr)
		cputs("\t|                                               НЕТ ДАННЫХ                                                |\n", RED_ON_BLACK);

	else
	{
		// цвет по умолчанию
		short cl = getColor();

		// номер элемента
		int i = 1;

		cout << fixed;
		cout.precision(2);

		// вывод дерева в цвете
		showFormColor(node, cl, i);
	}

	cout << Form::showLine();

}


#pragma endregion

#pragma region Задание 2. Телефонная станция

/*
	Задача 2.
	Разработать класс для представления абонента телефонной станции с полями для
	хранения :
		•	фамилии и инициалов
		•	телефонного номера
		•	времени разговоров(в минутах) за последний месяц.
	Разработать класс для представления телефонной станции с полями для хранения
	названия телефонной станции(код станции – три цифровых символа), текущий тариф
	за минуту разговора абонента, картотеки абонентов в виде бинарного дерева поиска.
	Ключом для узлов является телефонный номер абонента.
	Создать объект телефонной станции, заполнить картотеку из массива(не менее 10
	записей), реализовать поиск по телефонному номеру, вывод сумм к оплате в порядке
	возрастания телефонных номеров.
*/

// Задание 2. Телефонная станция
void App::task2()
{
	init(L"Задание 2. Телефонная станция");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Поиск по телефонному номеру
		CMD_TASK_ONE,
		// Вывод сумм к оплате в порядке возрастания телефонных номеров
		CMD_TASK_TWO,
	}; // Commands

	// количество пунктов меню
	const int N_MENU = 3;

	MenuItem items[N_MENU] = {
		MenuItem("Поиск по телефонному номеру", CMD_TASK_ONE),
		MenuItem("Вывод сумм к оплате в порядке возрастания телефонных номеров", CMD_TASK_TWO),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	}; // MenuItem items

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 2. Телефонная станция", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Поиск по телефонному номеру
			case CMD_TASK_ONE:
				app.searchNumber();
				break;
				// Вывод сумм к оплате в порядке возрастания телефонных номеров
			case CMD_TASK_TWO:
				app.showPay();
				break;
			} // switch (cmd)
		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();
		} // try-catch
	} // while (true)
} // App::task2

// поиск по телефонному номеру
void App::searchNumber()
{
	cls();

	// вывод заголовка
	showNavBarMessage(hintColor, "Поиск абонента по телефонному номеру");

	cputs("     —————————————————————————————————————————————————————————————————————————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод бинарного дерева
	station_.showTable();

	// фамилия для поиска
	char* number = new char[Subscriber::NUMBER_SIZE + 2];

	// текущий цвет
	short cl = getColor();

	// ввод фамилии для поиска
	showInputLine("\n\n\n     Введите номер для поиска: ", Subscriber::NUMBER_SIZE + 2, WHITE_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(number, Subscriber::NUMBER_SIZE + 1);

	// выключание курсора
	setCursorVisible(false);

	// установка цвета по умолчанию
	setColor(cl);

	// временный объект Form для поиска
	Subscriber tmp;

	// вывод результата
	cputs("     ———————————————————————————————————————————— РЕЗУЛЬТАТ ПОИСКА ———————————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// возвращенная Form
	BinaryTree<Subscriber>::NodeTree<Subscriber>*node = station_.find(number);

	// заголовка таблицы
	tmp.showHead();

	// если объект не найден
	if (node == nullptr)
		tmp.showEmpty();
	else
	{
		tmp = node->getData();

		// вывод элемента 
		tmp.showElem();
	}

	tmp.showLine();

	delete[] number;

	getKey();

}

// вывод сумм к оплате в порядке возрастания телефонных номеров
void App::showPay()
{
	cls();

	showNavBarMessage(hintColor, "Сумма к оплате телефонных номеров");
	
	// вывод абонентской платы
	station_.showTablePrice();

	getKey();
}

#pragma endregion