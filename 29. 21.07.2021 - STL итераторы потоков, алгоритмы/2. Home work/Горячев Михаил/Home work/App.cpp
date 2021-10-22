#include "App.h"

/*
*	Задача 1. При помощи STL, с использованием алгоритмов, функциональных объектов,
*	потоковых итераторов написать консольное приложение, обрабатывающее векторы по заданию:
*	•	Сформировать вектор из случайных вещественных чисел, диапазон генерации
*		вводите с клавиатуры. Сохранить вектор в форматированном потоке вывода при помощи
*		потокового итератора
*	•	Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
*		Умножить все элементы вектора на 2. Сохранить вектор в форматированном потоке вывода
*		при помощи потокового итератора
*	•	Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
*		Упорядочить вектор по правилу – положительные в начало вектора. Вывести вектор с
*		цветовым выделением положительных элементов
*	•	Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
*		Упорядочить вектор по убыванию. Вывести вектор с цветовым выделением отрицательных
*		элементов
*
*	Задача 2. Сведения о каждом автобусе содержат: регистрационный номер автобуса, фамилию
*	и инициалыводителя, назначенный номер маршрута, фактический номер маршрута.
*
*	Нахождение в парке – особый маршрут с номером «0», в состав номера маршрута входят как
*	цифры, так и буквы, например – «42», «42а», «32в».Коллекцию заявок постройте на классе
*	vector. Хранить коллекцию в форматированном потоке вывода, запись/чтение файла реализуйте
*	при помощи потокового итератора. При первом запуске приложения запишите начальные данные
*	в файл из вектора инициирующих значений.
*
*	Программа должна обеспечивать выбор с помощью меню и выполнение одной из следующих функций:
*	•	запись данных об автобусах в текстовый файл (форматированный поток вывода)
*	•	чтение данных об автобусах из текстового файла(форматированного потока ввода)
*	•	вывод данных об автобусах при помощи алгоритма for_each()и анонимного функтора
*	•	упорядочить коллекцию автобусов по регистрационным номерам при помощи алгоритма sort()
*		и анонимного функтора – компаратора;
*	•	упорядочить коллекцию автобусов по фамилии и инициалам водителяпри помощи алгоритма sort()
*		и анонимного функтора – компаратора;
*	Постарайтесь свести к минимуму использование циклов – максимально используйте алгоритмы STL.
*/


#pragma region Задания 

#pragma region Задание 1. Демонстрация алгоритмов на векторе

/*
*	Задача 1. При помощи STL, с использованием алгоритмов, функциональных объектов,
*	потоковых итераторов написать консольное приложение, обрабатывающее векторы по заданию:
*	•	Сформировать вектор из случайных вещественных чисел, диапазон генерации
*		вводите с клавиатуры. Сохранить вектор в форматированном потоке вывода при помощи
*		потокового итератора
*	•	Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
*		Умножить все элементы вектора на 2. Сохранить вектор в форматированном потоке вывода
*		при помощи потокового итератора
*	•	Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
*		Упорядочить вектор по правилу – положительные в начало вектора. Вывести вектор с
*		цветовым выделением положительных элементов
*	•	Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
*		Упорядочить вектор по убыванию. Вывести вектор с цветовым выделением отрицательных
*		элементов
*/

// Задание 1. Демонстрация алгоритмов на векторе
void App::task1()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Заполенение вектора случайными вещёственными числами 
		CMD_FILL_VECTOR,
		// Умножение элементов вектора на 2
		CMD_POW_TWO,
		// Сортировка вектора по правилу - положительные в начало вектора
		CMD_SORT_BY_POS,
		// Сортировка вектора по убыванию
		CMD_SORT_BY_DECR
	};

	// количество пунктов меню
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("Заполенение вектора случайными вещёственными числами", CMD_FILL_VECTOR),
		MenuItem("Чтение вектора из форматированного потока ввода и умножение на 2", CMD_POW_TWO),
		MenuItem("Сортировка вектора по правилу - положительные в начало вектора", CMD_SORT_BY_POS),
		MenuItem("Сортировка вектора по убыванию", CMD_SORT_BY_DECR),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 1. Демонстрация алгоритмов на векторе", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
			// Заполенение вектора случайными вещёственными числами
			case CMD_FILL_VECTOR:
				app.fillVector();
				break;
			// Чтение вектора из форматированного потока ввода и умножение на 2
			case CMD_POW_TWO:
				app.posTwo();
				break;
			// Упорядочивание вектора по правилу - положительные в начало вектора
			case CMD_SORT_BY_POS:
				app.sortByPos();
				break;			
			// Сортировка вектора по убыванию
			case CMD_SORT_BY_DECR:
				app.sortByDecr();
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

// Заполенение вектора случайными вещёственными числами
void App::fillVector()
{
	// Сформировать вектор из случайных вещественных чисел, диапазон генерации
	// вводите с клавиатуры.Сохранить вектор в форматированном потоке вывода при помощи
	// потокового итератора

	showNavBarMessage(hintColor, "Заполенение вектора случайными вещёственными числами");

	// вывод вектора 
	showVector(sourceVec_, "Вектор", "После заполенения", GREEN_ON_BLACK);

	// диапазон значений 
	double min, max;

	// цвет по умолчанию
	short cl = getColor();

	setColor(YELLOW_ON_BLACK);

	// ввод размера вектора 
	showInputLine("\n\n\tВведите диапазон значений (минимальное/максимальное): ", 10, hintColor);

	// влючение курсора 
	setCursorVisible(true);

	// ввод данных 
	cin >> min >> max;

	// установка цвета 
	setColor(cl);

	// выключение курсора 
	setCursorVisible(false);

	// если данные некорректны
	if (cin.fail())
	{
		// отчистка буфера ввода 
		cin.rdbuf()->in_avail();

		throw exception("Данные некорректны!");
	}
	if (min > max)
	{
		throw exception("Данные некорректны!");
	}
	
	// размер вектора 
	const int N_VECTOR = 14;

	// выделение памяти для заполенение 
	sourceVec_ = vector<double>(N_VECTOR);

	// заполенение вектора 
	generate(sourceVec_.begin(), sourceVec_.end(), func_fill_vec(min, max));

	// вывод вектора 
	showVector(sourceVec_, "Вектор", "После заполенения", GREEN_ON_BLACK);

	// сохранение в файл 
	saveTextVector(sourceVec_, nameTextFile_);

	// загрузка вектора из файла 
	loadTextVector(sourceVec_, nameTextFile_);

	// вывод вектора 
	showVector(sourceVec_, "Вектор из файла"s + nameTextFile_, "После загрузки из файла", GREEN_ON_BLACK);

	getKey();

} // App::fillVector()

// Чтение вектора из форматированного потока ввода и умножение на 2
void App::posTwo()
{
	// Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
	// Умножить все элементы вектора на 2. Сохранить вектор в форматированном потоке вывода
	// при помощи потокового итератора

	showNavBarMessage(hintColor, "Чтение вектора из форматированного потока ввода и умножение на 2");

	// загрузка файла 
	loadTextVector(sourceVec_, nameTextFile_);

	// вывод вектора 
	showVector(sourceVec_, "Вектор из файла"s + nameTextFile_, "До изменения", GREEN_ON_BLACK);

	// умножение значений вектора на 2
	for_each(sourceVec_.begin(), sourceVec_.end(), func_power(2));

	cout << "\n\n\n";

	// сохраненеие в текстовый файл 
	saveTextVector(sourceVec_, nameTextFile_);

	// загрузка файла 
	loadTextVector(sourceVec_, nameTextFile_);

	// вывод вектора 
	showVector(sourceVec_, "Вектор из файла"s + nameTextFile_, "После измененения", GREEN_ON_BLACK);

	getKey();

} // App::posTwo()

// Упорядочивание вектора по правилу - положительные в начало вектора
void App::sortByPos()
{
	// Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
	// Упорядочить вектор по правилу – положительные в начало вектора. Вывести вектор с
	// цветовым выделением положительных элементов

	showNavBarMessage(hintColor, "Упорядочивание вектора по правилу - положительные в начало вектора");

	// загрузка файла 
	loadTextVector(sourceVec_, nameTextFile_);

	// вывод вектора 
	showVectorColor(sourceVec_, "Вектор из файла "s + nameTextFile_, "До сортировки", GREEN_ON_BLACK, RED_ON_BLACK);

	// сортировка вектора 
	// greater<double> pred;
	sort(sourceVec_.begin(), sourceVec_.end(), pred_positive_vector());

	// сохранение в файл
	saveTextVector(sourceVec_, nameTextFile_);

	// загрузка файла 
	loadTextVector(sourceVec_, nameTextFile_);

	cout << "\n\n\n";

	// вывод вектора 
	showVectorColor(sourceVec_, "Вектор из файла "s + nameTextFile_, "После сортировки", GREEN_ON_BLACK, RED_ON_BLACK);

	getKey();

} // App::sortByPos()

// Сортировка вектора по убыванию
void App::sortByDecr()
{
	// Прочитать вектор из форматированного потока ввода при помощи потокового итератора.
	// Упорядочить вектор по убыванию. Вывести вектор с цветовым выделением отрицательных
	// элементов

	showNavBarMessage(hintColor, "Сортировка вектора по убыванию");

	// загрузка файла 
	loadTextVector(sourceVec_, nameTextFile_);

	// вывод вектора 
	showVectorColor(sourceVec_, "Вектор из файла "s + nameTextFile_, "До сортировки", RED_ON_BLACK, GREEN_ON_BLACK);

	// сортировка вектора 
	greater<double> pred_decr;
	sort(sourceVec_.begin(), sourceVec_.end(), pred_decr);

	// сохранение в файл
	saveTextVector(sourceVec_, nameTextFile_);

	// загрузка файла 
	loadTextVector(sourceVec_, nameTextFile_);

	cout << "\n\n\n";

	// вывод вектора 
	showVectorColor(sourceVec_, "Вектор из файла "s + nameTextFile_, "После сортировки", RED_ON_BLACK, GREEN_ON_BLACK);

	getKey();



} // App::sortByDecr()

// сохранение вектора в текстовый файл
void App::saveTextVector(vector<double>& vec, string nameFile)
{
	// форматированный поток вывода
	ofstream file(nameFile, ios::out);

	// если файл не удалось открыть
	if (!file.is_open())
		throw exception(("Файл"s + nameFile + "не удалось открыть!").c_str());

	// сохранение в файл с помощью итератора потока вывода
	ostream_iterator<double> stream(file, "\n");

	// запись в файл с помощью итератора 
	for_each(vec.begin(), vec.end(), func_save_text_vec(stream));

	// закрытие потока вывода 
	file.close();
} // App::saveTextVector(vector<double>& vec, string nameFile)

// загрузка вектора из текстового файла 
void App::loadTextVector(vector<double>& vec, string nameFile)
{
	// открытие потока ввода из файла 
	ifstream file(nameFile);

	// итератор по потоку ввода 
	istream_iterator<double> it(file);

	// отчистка вектора 
	sourceVec_.clear();

	// ввод из файла 
	while (!file.eof())
	{
		// добавление элемента в вектор 
		vec.push_back(*it++);
	}

	// закрытие потока ввода 
	file.close();
} // loadTextVector(vector<double>& vec, string nameFile)

// вывод вектора с подсветкой положительных элементов
void App::showVector(vector<double>& vec, string name, string specific, short colorElem)
{
	// размер вектора 
	int n = vec.size();

	// текущий цвет
	short cl = getColor();

	cout << "    +————————————+————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
		<< "    | Размер: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | Тип данных: " << left << color(YELLOW_ON_BLACK) << setw(34) << name << color(cl)
		<< " | Описание: " << color(YELLOW_ON_BLACK) << setw(36) << specific << color(cl) << right << " |\n";

	// вывод разделительной линии
	showLineVector();

	// если в векторе нет данных
	if (vec.empty())
	{
		showEmptyVector();
		showLineVector();
		return;
	}

	cout << "    |  Значения  |";

	cout.precision(1);

	// вывод элементов 
	for (auto item : vec)
	{
		// вывод элемента 
		cout << color(colorElem) << setw(5) << item << color(cl) << " |";
	}

	cout << "\n";

	// вывод разделительной линии
	showLineVector();
} // App::showVector(vector<double>& vec, string name, string specific, short colorElem)

// вывод вектора с подсветкой положительных элементов
void App::showVectorColor(vector<double>& vec, string name, string specific, short colorElem, short backlight)
{
	// размер вектора 
	int n = vec.size();

	// текущий цвет
	short cl = getColor();

	cout << "    +————————————+————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
		<< "    | Размер: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | Тип данных: " << left << color(YELLOW_ON_BLACK) << setw(34) << name << color(cl)
		<< " | Описание: " << color(YELLOW_ON_BLACK) << setw(36) << specific << color(cl) << right << " |\n";

	// вывод разделительной линии
	showLineVector();

	// если в векторе нет данных
	if (vec.empty())
	{
		showEmptyVector();
		showLineVector();
		return;
	}

	cout << "    |  Значения  |";

	cout.precision(1);

	// вывод элементов 
	for (auto item : vec)
	{
		// цвет для вывода 
		short colOut = item >= 0 ? backlight : colorElem;

		// вывод элемента 
		cout << color(colOut) << setw(5) << item << color(cl) << " |";
	}

	cout << "\n";

	// вывод разделительной линии
	showLineVector();
} // App::showVector(vector<double>& vec, string name, string specific, short colorElem)

// вывод линии для таблицы
void App::showLineVector()
{
	cout << "    +————————————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+——————+\n";
} // App::showLineVector()

// вывод сообщения об отсутвии данных для таблицы
void App::showEmptyVector()
{
	// текущий цвет
	short cl = getColor();

	cout << "    |  " << color(LTRED_ON_BLACK)
		<< "                                                 НЕТ ДАННЫХ                                                "
		<< color(cl) << " | \n";
} // App::showEmptyVector()

#pragma endregion 

#pragma region Задание 2. Автобусный парк

/*
*	Задача 2. Сведения о каждом автобусе содержат: регистрационный номер автобуса, фамилию
*	и инициалыводителя, назначенный номер маршрута, фактический номер маршрута.
*
*	Нахождение в парке – особый маршрут с номером «0», в состав номера маршрута входят как
*	цифры, так и буквы, например – «42», «42а», «32в».Коллекцию заявок постройте на классе
*	vector. Хранить коллекцию в форматированном потоке вывода, запись/чтение файла реализуйте
*	при помощи потокового итератора. При первом запуске приложения запишите начальные данные
*	в файл из вектора инициирующих значений.
*
*	Программа должна обеспечивать выбор с помощью меню и выполнение одной из следующих функций:
*	•	запись данных об автобусах в текстовый файл (форматированный поток вывода)
*	•	чтение данных об автобусах из текстового файла (форматированного потока ввода)
*	•	вывод данных об автобусах при помощи алгоритма for_each()и анонимного функтора
*	•	упорядочить коллекцию автобусов по регистрационным номерам при помощи алгоритма sort()
*		и анонимного функтора – компаратора;
*	•	упорядочить коллекцию автобусов по фамилии и инициалам водителя при помощи алгоритма sort()
*		и анонимного функтора – компаратора;
*	Постарайтесь свести к минимуму использование циклов – максимально используйте алгоритмы STL.
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
		// Запись данных об автобусах в текстовый файл
		CMD_SAVE_FILE,
		// Чтение данных об автобусах из текстового файла
		CMD_LOAD_FILE,
		// Вывод данных об автобусах
		CMD_PRINT_ALL,
		// Сортировка коллекции автобусов по регистрационным номерам
		CMD_SORT_BY_NUMBER,
		// Сортировка коллекции автобусов по фамилии и инициалам водителя
		CMD_SORT_BY_NAME
	};

	// количество пунктов меню
	const int N_MENU = 7;

	MenuItem items[N_MENU] = {
		MenuItem("Начальное формирование коллекции данных обо всех автобусах", CMD_CREATE_PARK),
		MenuItem("Запись данных об автобусах в текстовый файл", CMD_SAVE_FILE),
		MenuItem("Чтение данных об автобусах из текстового файла", CMD_LOAD_FILE),
		MenuItem("Вывод данных об автобусах", CMD_PRINT_ALL),
		MenuItem("Сортировка коллекции автобусов по регистрационным номерам", CMD_SORT_BY_NUMBER),
		MenuItem("Сортировка коллекции автобусов по фамилии и инициалам водителя", CMD_SORT_BY_NAME),

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

				// Запись данных об автобусах в текстовый файл
			case CMD_SAVE_FILE:
				app.saveBusFile();
				break;

				// Чтение данных об автобусах из текстового файла
			case CMD_LOAD_FILE:
				app.loadBusFile();
				break;

				// Вывод сведений обо всех автобусах
			case CMD_PRINT_ALL:
				app.printAll();
				break;

				// Сортировка коллекции автобусов по регистрационным номерам
			case CMD_SORT_BY_NUMBER:
				app.sortByNumber();
				break;

				// Сортировка коллекции автобусов по фамилии и инициалам водителя
			case CMD_SORT_BY_NAME:
				app.sortByName();
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
	showBus(buses_, "Все автобусы", "До заполнения");

	// если файла не существует 
	if (!isFile(busText_))
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
		for_each(busList, busList + SIZE_ARR, func_fill_bus(buses_));

		// сохранение в файл 
		saveBus(buses_, busText_);
	}

	// загрузка из файла
	loadBus(buses_, busText_);

	cout << endl;

	// вывод автобусов
	showBus(buses_, "Все автобусы", "После загрузки файла");

	cout << "\n\n\n";

	getKey();


} // App::createPark()

// Вывод сведений обо всех автобусах
void App::printAll()
{
	cls();

	showNavBarMessage(hintColor, "Вывод сведений обо всех автобусах");

	// вывод автобусов
	showBus(buses_, "Все автобусы", "После загрузки файла");

	getKey();

} // App::printAll()

// Запись данных об автобусах в текстовый файл
void App::saveBusFile()
{
	cls();

	showNavBarMessage(hintColor, "Запись данных об автобусах в текстовый файл");

	// вывод всех автобусов
	showBus(buses_, "Вектор автобусов", "До сохранения в файл");

	// сохраненеи в файл
	saveBus(buses_, busText_);

	// загрузка из файла  
	loadBus(buses_, busText_);

	cout << "\n\n\n";

	// вывод всех автобусов
	showBus(buses_, "Вектор автобусов", "После сохранения");
	
	cout << "\n\n";

	getKey();
}

// Чтение данных об автобусах из текстового файла
void App::loadBusFile()
{
	cls();

	showNavBarMessage(hintColor, "Запись данных об автобусах в текстовый файл");

	// вывод всех автобусов
	showBus(buses_, "Вектор автобусов", "До загрузки файла");

	// загрузка из файла  
	loadBus(buses_, busText_);

	cout << "\n\n\n";

	// вывод всех автобусов
	showBus(buses_, "Вектор автобусов", "После загрузки файла");

	cout << "\n\n";

	getKey();

}

// Сортировка коллекции автобусов по регистрационным номерам
void App::sortByNumber()
{
	cls();

	showNavBarMessage(hintColor, "Сортировка коллекции автобусов по регистрационным номерам");

	// вывод автобусов
	showBus(buses_, "Все автобусы", "До сортировки");

	cout << "\n\n\n";

	// сортировка 
	sort(buses_.begin(), buses_.end(), func_comp_by_number());

	// сохранение в файл
	saveBus(buses_, busText_);

	// загрузка из файла
	loadBus(buses_, busText_);

	// вывод автобусов
	showBus(buses_, "Все автобусы", "После сортировки");

	cout << "\n\n\n";


	getKey();

}

// Сортировка коллекции автобусов по фамилии и инициалам водителя
void App::sortByName()
{
	cls();

	showNavBarMessage(hintColor, "Сортировка коллекции автобусов по фамилии и инициалам водителя");

	// вывод автобусов
	showBus(buses_, "Все автобусы", "До сортировки");

	// сортировка 
	sort(buses_.begin(), buses_.end(), func_comp_by_name());

	cout << "\n\n\n";

	// сохранение в файл
	saveBus(buses_, busText_);

	// загрузка из файла
	loadBus(buses_, busText_);

	// вывод автобусов
	showBus(buses_, "Все автобусы", "После сортировки");

	cout << "\n\n\n";

	getKey();

}

// вывод map автобусов
void App::showBus(vector<Bus>& vecBus, string name, string specific)
{
	// вывод шапки таблицы
	showHeadBus(vecBus, name, specific);

	// если map пустая 
	if (vecBus.empty())
		showEmptyBus();

	// вывод элементов 
	showBusElem(vecBus);

	// вывод линии разделителя 
	showLineBus();

} // App::outBus()

// вывод шапки таблицы
void App::showHeadBus(vector<Bus>& vecBus, string name, string specific)
{
	// теукщий цвет
	short cl = getColor();

	cout << "    +————————————+—————————————————————————————————+—————————————————————————————————+\n"
		<< "    | Размер: " << left << color(GREEN_ON_BLACK) << setw(2) << vecBus.size()
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
void App::showBusElem(vector<Bus>& vecBus)
{
	// вывод всех автобусов с помощью анонимного функтора и цикла for_each
	for_each(vecBus.begin(), vecBus.end(), func_out_bus());
} // showBusElem()

// сохранение vector в файл 
void App::saveBus(vector<Bus>& vecBus, string nameFile)
{
	// отрктие файла в режиме бинарной записи
	ofstream file(nameFile, ios::out);

	// сохранение в файл
	for_each(vecBus.begin(), vecBus.end(), func_save_bus(file));

	file.close();
}

// загрузка vector из файла 
void App::loadBus(vector<Bus>& vecBus, string nameFile)
{
	vecBus.clear();

	// отрктие файла в режиме бинарной записи
	ifstream file(nameFile);

	Bus temp;

	istream_iterator<Bus> it(file);

	while (!file.eof())
	{
		// добавление в общую базу
		vecBus.push_back(*it++);
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

#pragma endregion
