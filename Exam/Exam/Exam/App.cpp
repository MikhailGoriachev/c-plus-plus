#include "App.h"

#include "menu.h"
#include "MenuItem.h"

#pragma region Превью запуска приложения 

// Превью запуска приложения
void App::preview()
{
	// заполенение фона 
	fillBackground(35, 121, BLACK_ON_CYAN, 20);

	// вывод рамки
	outFrame(10, 50, 35, 10, BLACK_ON_LTCYAN, BLACK_ON_CYAN);

	// вывод текста 
	outText("Экзаменационная работа Горячева Михаила", 30, BLACK_ON_CYAN, 40, 13);
	outText("ООП C++", 30, BLACK_ON_CYAN, 57, 15);

	// вывод полосы загрузки 
	loadingLine(61, 4000, 30, 30);

	cout << "\n";

	Sleep(500);
}

// заполнение заднего фона 
void App::fillBackground(int row, int col, short color, int time)
{
	// текущий цвет 
	short cl = getColor();
	
	// включение заданного цвета 
	setColor(color);

	ostringstream os;

	os << setw(col) << " ";

	string str = os.str();

	// заполнение 
	for (int i = 0; i < row; i++)
	{
		cout << pos(0, i) << str;
		Sleep(time);
	}

	// переключение цвета на исходный 
	setColor(cl);
}

// анимация вывода текста 
void App::outText(string message, int time, short color = mainColor, int x = -1, int y = -1)
{
	// установка позиции курсора, если параметры переданы
	if (x != -1 and y != -1)
	{
		// установка курсора 
		cout << pos(x, y);
	}

	// если параметры некорректны
	if (x < -1 and y < -1)
	{
		throw exception(("App: Параметры"s + "x - " + to_string(x) + "y - " + to_string(y) + " некорректны").c_str());
	}

	// текущий цвет
	short cl = getColor();

	// установка цвета 
	setColor(color);

	// длина строки
	size_t size = message.size();

	// вывод строки
	for (size_t i = 0; i < size; i++)
	{
		cout << message[i];
		Sleep(time);
	}
}

// анимация полосы загрузки 
void App::loadingLine(int size, int time, int x, int y, short colorLoading, short colorBackground, short colorComplete)
{

#pragma region Установка позиции и проверка исключений 

	// если переданны некорректные параметры
	if (size < 10 and time <= 0)
		throw exception("App: Переданы некорректные параметры в анимацию полосы загрузки");

	// если параметры некорректны
	if (x < 10 and y < 1)
	{
		throw exception(("App: Параметры"s + "x - " + to_string(x) + "y - " + to_string(y) + " некорректны").c_str());
	}

	// цвет по умолчанию 
	short cl = getColor();

	// установка курсора 
	// cout << pos(x + (size / 2) - 7, y - 3) << color(colorLoading) << setw(18) << " "
	// 	<< pos(x + (size / 2) - 7, y - 2) << " Загрузка ";

	// позиция начала вывода процентов 
	int posX = size / 2 - 8 + x;

	cout << pos(posX, y - 3) << color(BLACK_ON_BLACK) << setw(19) << left << " a" << color(colorLoading)
		<< pos(posX, y - 2) << " Загрузка " << right;

#pragma endregion 

#pragma region Переменные для вывода 

	// количество ячеек 
	int countPercent = (size / 100 > 0 ? size / 100 : size % 100 / 10);

	// длина ячейки
	int sizePercent = size / countPercent;

	// время на одно деление процентов
	int timePercent = time / countPercent;

	// время вывода одного символа 
	int timeOne = timePercent / sizePercent;

	// остаточное время вывода 
	int timeRem = timePercent % sizePercent;

	// процентов в одной ячейке
	double percentCell = 100. / countPercent;

	// процентов на один символ
	double percentCymb = 100. / size;

	// остаток символов от целого деления 
	int sizeRem = size % countPercent;

	// позиция начала процентов 
	int xPosPercent = posX + 10; // x + (size / 2) + 2;

	// проценты 
	double percent = 0.;

#pragma endregion

#pragma region Вывод 

	// вывод полосы фона 
	cout << pos(x - 1, y - 1) << color(colorBackground) << setw(size + 2) << " " 
		<< pos(x - 1, y) << color(colorBackground) << setw(size + 2) << " " 
		<< pos(x - 1, y + 1) << color(colorBackground) << setw(size + 2) << " " << color(colorComplete);

	// возвращение в начало полосы загрузки 
	for (int i = 0; i < size; i++)	cout << "\b";


	cout.precision(2);

	// вывод заполенения 
	for (int i = 0; i < countPercent; i++)
	{
		// вывод одного деления 
		for (int k = 0; k < sizePercent; k++)
		{
			percent += percentCymb;
			cout << color(colorLoading) << pos(xPosPercent, y - 2) << setw(7) << percent << "% "
				<< color(colorComplete) << pos(x++, y) << " ";

			Sleep(timeOne);
		}

		cout << color(colorLoading) << pos(xPosPercent, y - 2) << setw(7) << percent << "% ";

		// задержка по времени
		Sleep(timeRem);
	}

	// если времени на одно деление процентов равно нулю
	if (timePercent == 0)
		Sleep(time);

	// если длина строки загрузки не делится нацело на 100
	if (sizeRem != 0)
	{
		// вывод одного деления
		for (int k = 0; k < sizeRem; k++)
		{
			percent += percentCymb;

			cout << color(colorLoading) << pos(xPosPercent, y - 2) << setw(7) << percent << "% "
				<< color(colorComplete) << pos(x++, y) << " ";
			
			Sleep(timeOne);
		}
	}

	// возвращение цвета по умолчанию
	setColor(cl);

#pragma endregion

}

// вывод рамки
void App::outFrame(int hight, int width, int x, int y, short colorFrame, short colorBackground)
{
	cout << pos(x, y++) << color(colorFrame) << setw(width) << " ";

	for (int i = 0; i < hight - 2; i++, y++)
	{
		cout << pos(x, y) << color(colorFrame) << " " 
			<< color(colorBackground) << setw(width - 2) << " " 
			<< color(colorFrame) << " ";
	}

	cout << pos(x, y) << color(colorFrame) << setw(width) << " ";
}

#pragma endregion

/*
	Итоговое задание по курсу «Объектно-ориентированное программирование с 
	использованием языка C++»
	С использованием STL разработать три приложения для решения следующих задач 
	в консольных приложениях с использованием меню.

	——————————————————————————————————————————————————————————————————————————————————————————————————————————

	Задача 1 (обязательная, максимум 8 баллов)
	В векторе, состоящем из п целых элементов, выполнить следующие операции (по 
	командам меню):
	1)	количество элементов вектора, равных 0
	2)	сумму элементов вектора, расположенных после минимального элемента
	3)	удалить элементы, встречающиеся менее двух раз
	4)	упорядочить вектор по возрастанию модулей элементов
	5)	продублировать отрицательные элементы вектора
	6)	сохранить вектор в бинарном файле при помощи потока вывода
	7)	прочитать вектор из бинарного файла при помощи потока ввода

	——————————————————————————————————————————————————————————————————————————————————————————————————————————

	Задача 2 (для претендентов на 10 баллов).
	С использованием классов и алгоритмов STL, лямбда-выражений написать приложение 
	для решения следующей задачи из практикума Павловской Т.А. и Щупака Ю.А. по ООП 
	на C++:
	Написать приложения для учета книг в библиотеке. Сведения о книгах содержат: 
	идентификатор (учетный номер единицы хранения), фамилию и инициалы автора, название 
	книги, год издания, количество экземпляров данной книги в библиотеке. Сведения о 
	библиотеке – адрес библиотеки, фамилия и инициалы директора, коллекция книг. Данные 
	о библиотеке и книгах хранить в текстовом файле в формате CSV, символ разделителя «;».
	Формат файла – в первой строке данные библиотеки, в остальных строках данные о книгах, 
	одна книга – одна строка, начальная инициализация при первом запуске приложения – не 
	менее 12 книг. С помощью меню реализовать выбор и выполнение следующих функций:
	•	Вывод данных библиотеки и коллекции книг в консоль
	•	Добавление книги, ввод данных с клавиатуры, сохранение измененной коллекции в 
		текстовый файл
	•	Удаление книг по идентификатору, сохранение измененной коллекции в текстовый файл
	•	Изменение количества книг заданного автора на вводимое с клавиатуры значение, 
		сохранение измененной коллекции в текстовый файл
	•	Отбор книг в отдельный список по заданному году издания, вывод этого списка в 
		консоль, упорядочив по году издания, не изменять исходную коллекцию книг, файл 
		данных
	•	Отбор заявок в отдельный список по автору, вывод этого списка в консоль, упорядочив 
		по автору, не изменять исходную коллекцию книг, файл данных
	•	Сортировка книг по убыванию количества книг, вывод в консоль без изменения файла 
		данных
	•	Сортировка книг по идентификатору, вывод в консоль без изменения файла данных
	•	Сортировка книг по названию, вывод в консоль без изменения файла данных
	Постарайтесь свести к минимуму использование циклов – максимально используйте алгоритмы 
	STL.

	——————————————————————————————————————————————————————————————————————————————————————————————————————————

	Задача 3 (для претендентов на 12 баллов) – вариант 1
	Класс Bill представляет собой разовый платеж за телефонный разговор. Класс должен включать 
	поля: дата и время начала разговора, дата и время окончания разговора.

	Время разговора вычисляется в минутах, неполная минута, считается за полную. Должен быть 
	реализован метод, вычисляющий сумму к оплате за разговор.
	Для представления даты и времени используйте класс DateTime с полями – день, месяц, год, 
	час, минута, секунда. Реализуйте методы вычисления разности между двумя моментами времени 
	в секундах. Перегрузите операции сравнения двух моментов времени.

	Разработайте класс – список плательщиков ListPayer. Класс содержит список плательщиков за 
	телефонные услуги, дату создания списка, номер списка.

	Один элемент списка включает: информацию о плательщике – номер телефона	фамилия и инициалы 
	плательщика, тариф за минуту разговора, скидка (в процентах), 
	коллекция записей класса Bill, дату платежа, сумму платежа.

	Реализовать для класса ListPayer:
	•	Метод добавления плательщика в список
	•	Метод удаления плательщика из списка
	•	Метод поиска плательщика по номеру телефона, найденные записи помещать в отдельную коллекцию, 
		сохранять в бинарном потоке вывода
	•	Метод поиска плательщика по фамилии и инициалам, найденные записи помещать в отдельную 
		коллекцию, сохранять в бинарном потоке вывода
	•	Метод поиска плательщиков по дате платежа, найденные записи помещать в отдельную коллекцию, 
		сохранять в бинарном потоке вывода
	•	Метод вычисления полной стоимости платежей всего списка
	Реализовать создание объектов ListPayer, операции объединения и пересечения списков.
	•	Операция объединения списка – бинарная операция, на выходе получаем список из элементов двух 
		списков, без дубликатов.
	•	Операция пересечения списка – бинарная операция, на выходе получаем список из элементов 
		имеющихся и в первом, и во втором списках, без дубликатов.
	Реализовать отбор данных из списка плательщиков:
	•	По дате платежа, сортировка по номеру телефона
	•	По номеру телефона, сортировка по номеру телефона
	Реализовать сортировку списка плательщиков:
	•	По номеру телефона
	•	По убыванию суммы к оплате
	•	По убыванию времени разговоров

	Варианты для выполнения задания
	Вариант 1: Болдырев А., Горячев М., Сапелкин Д.
	Вариант 2: Вагнер В., Куцый Д., Поддубный А.

	Дополнительно
	Срок выполнения задания – 3 недели, до 16.08.2021.
*/

#pragma region Задание 1. Вектор

/*
	——————————————————————————————————————————————————————————————————————————————————————————————————————————

	Задача 1 (обязательная, максимум 8 баллов)
	В векторе, состоящем из п целых элементов, выполнить следующие операции (по
	командам меню):
	1)	количество элементов вектора, равных 0
	2)	сумму элементов вектора, расположенных после минимального элемента
	3)	удалить элементы, встречающиеся менее двух раз
	4)	упорядочить вектор по возрастанию модулей элементов
	5)	продублировать отрицательные элементы вектора
	6)	сохранить вектор в бинарном файле при помощи потока вывода
	7)	прочитать вектор из бинарного файла при помощи потока ввода

	——————————————————————————————————————————————————————————————————————————————————————————————————————————
*/

// Задание 1. Вектор
void App::task1()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// 1. Заполнение вектора 
		CMD_POINT_ONE,
		// 2. Количество элементов вектора, равных 0
		CMD_POINT_TWO,
		// 3. Сумму элементов вектора, расположенных после минимального элемента
		CMD_POINT_THREE,
		// 4. Удалить элементы, встречающиеся менее двух раз
		CMD_POINT_FOUR,
		// 5. Упорядочить вектор по возрастанию модулей элементов
		CMD_POINT_FIVE,
		// 6. Продублировать отрицательные элементы вектора
		CMD_POINT_SIX,
		// 7. Сохранить вектор в бинарном файле при помощи потока вывода
		CMD_POINT_SEVEN,
		// 8. Прочитать вектор из бинарного файла при помощи потока ввода
		CMD_POINT_EIGHT
	};

	// количество пунктов меню
	const int N_MENU = 9;

	/*
		1)	количество элементов вектора, равных 0
		2)	сумму элементов вектора, расположенных после минимального элемента
		3)	удалить элементы, встречающиеся менее двух раз
		4)	упорядочить вектор по возрастанию модулей элементов
		5)	продублировать отрицательные элементы вектора
		6)	сохранить вектор в бинарном файле при помощи потока вывода
		7)	прочитать вектор из бинарного файла при помощи потока ввода
	*/

	MenuItem items[N_MENU] = {
		MenuItem("1. Заполнение вектора", CMD_POINT_ONE),
		MenuItem("2. Количество элементов вектора, равных 0", CMD_POINT_TWO),
		MenuItem("3. Сумму элементов вектора, расположенных после минимального элемента", CMD_POINT_THREE),
		MenuItem("4. Удалить элементы, встречающиеся менее двух раз", CMD_POINT_FOUR),
		MenuItem("5. Упорядочить вектор по возрастанию модулей элементов", CMD_POINT_FIVE),
		MenuItem("6. Продублировать отрицательные элементы вектора", CMD_POINT_SIX),
		MenuItem("7. Сохранить вектор в бинарном файле при помощи потока вывода", CMD_POINT_SEVEN),
		MenuItem("8. Прочитать вектор из бинарного файла при помощи потока ввода", CMD_POINT_EIGHT),

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

			cls();

			switch (cmd)
			{
			// 1. Заполнение вектора
			case CMD_POINT_ONE:
				app.taskOneFillVector();
				break;
			// 2. Количество элементов вектора, равных 0
			case CMD_POINT_TWO:
				app.taskOneCountNull();
				break;
			// 3. Сумму элементов вектора, расположенных после минимального элемента
			case CMD_POINT_THREE:
				app.taskOneSummElem();
				break;
			// 4. Удалить элементы, встречающиеся менее двух раз
			case CMD_POINT_FOUR:
				app.taskOneDeleteDouble();
				break;
			// 5. Упорядочить вектор по возрастанию модулей элементов
			case CMD_POINT_FIVE:
				app.taskOneSortByModule();
				break;
			// 6. Продублировать отрицательные элементы вектора
			case CMD_POINT_SIX:
				app.taskOneDoubleNegative();
				break;
			// 7. Сохранить вектор в бинарном файле при помощи потока вывода
			case CMD_POINT_SEVEN:
				app.taskOneSaveBinFile();
				break;
			// 8. Прочитать вектор из бинарного файла при помощи потока ввода
			case CMD_POINT_EIGHT:
				app.taskOneLoadBinFile();
				break;
			}

			cout << "\n\n";
			getKey();
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

#pragma region Реализация функций 

// 1. Заполнение вектора 
void App::taskOneFillVector()
{
	showNavBarMessage(hintColor, "  1. Заполнение вектора");

	cout << "\n";

	// вывод вектора до заполнения
	showVector(vec_, "Вектор", "Вектор до заполнения");

	// отчистка вектора и создание с заданной длиной
	vec_ = vector<int>(getRand(7, 9));

	// заполнение вектора 
	generate(vec_.begin(), vec_.end(), []() {return getRand(-5, 5); });

	cout << "\n\n\n";

	// вывод после заполнения 
	showVector(vec_, "Вектор", "Вектор после заполнения");
}

// 2. Количество элементов вектора, равных 0
void App::taskOneCountNull()
{
	showNavBarMessage(hintColor, "  2. Количество элементов вектора, равных 0");

	cout << "\n";

	// вывод вектора 
	showVector(vec_, "Вектор", "Исходный вектор", showElemVectorNull);

	// подсчёт нулевых елементов
	int countNull = (int)count_if(vec_.begin(), vec_.end(), [](int n) { return n == 0; });

	// текущий цвет по умолчанию
	short cl = getColor();

	// вывод количества элементов 
	cout << color(LTYELLOW_ON_BLACK) << "\n\n     Количество элементов со значением 0: " << color(LTGREEN_ON_BLACK) << countNull << color(cl);
}

// вывод элементов с подсветкой елементов со значением 0
void App::showElemVectorNull(vector<int> vec)
{
	// если вектор пуст 
	if (vec.empty())
	{
		cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+                                       "
			<< color(LTRED_ON_BLACK) << "  НЕТ ДАННЫХ  " << color(LTCYAN_ON_BLACK)
			<< "                                    |\n"
			<< color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+—————————————————————————————————————————————————————————————————————————————————————————+\n";

		return;
	}

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     "
		<< color(LTCYAN_ON_BLACK) << " | ";

	// индекс 
	int i = 0;

	// вывод индексов 
	for_each(vec.begin(), vec.end(), [i](int value) mutable 
	{
		cout << color(value == 0 ? LTMAGENTA_ON_BLACK : LTYELLOW_ON_BLACK) << setw(2)
			<< i++ << color(LTCYAN_ON_BLACK) << " | ";
	});

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    "
		<< color(LTCYAN_ON_BLACK) << " | ";

	// вывод элементов 
	for_each(vec.begin(), vec.end(), [](int value) mutable 
	{
		cout << color(value == 0 ? LTMAGENTA_ON_BLACK : LTGREEN_ON_BLACK) << setw(2)
			<< value << color(LTCYAN_ON_BLACK) << " | ";
	});

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();
}

// 3. Сумму элементов вектора, расположенных после минимального элемента
void App::taskOneSummElem()
{
	showNavBarMessage(hintColor, "  3. Сумму элементов вектора, расположенных после минимального элемента");

	cout << "\n";

	// вывод вектора 
	showVector(vec_, "Вектор", "Исходный вектор", showElemVectorMin);

	// поиск минимального элемента 
	auto pos = min_element(vec_.begin(), vec_.end());

	// сумма элементов после минимального 
	int sum = 0;

	// подсчёт суммы элементов после минимального
	sum = accumulate(pos + 1, vec_.end(), sum);

	// текущий цвет 
	short cl = getColor();

	// вывод суммы элементов после минимального элемента 
	cout << color(LTYELLOW_ON_BLACK) << "\n\n\n     Сумма элементов после минимального: " 
		<< color(LTGREEN_ON_BLACK) << sum << color(cl) << "\n\n\n\n\n";

}

// вывод элементов с подсветкой первого минимального элемента 
void App::showElemVectorMin(vector<int> vec)
{
	// если вектор пуст 
	if (vec.empty())
	{
		cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+                                       "
			<< color(LTRED_ON_BLACK) << "  НЕТ ДАННЫХ  " << color(LTCYAN_ON_BLACK)
			<< "                                    |\n"
			<< color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+—————————————————————————————————————————————————————————————————————————————————————————+\n";

		return;
	}

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     " 
		<< color(LTCYAN_ON_BLACK) << " | ";

	// минимальный элемент
	auto min = min_element(vec.begin(), vec.end());

	// флаг указывает является ли элемент первым минимальным
	bool flagMin = false;

	// индекс 
	int i = 0;

	// вывод индексов 
	for_each(vec.begin(), vec.end(), [i, flagMin, min](int value) mutable { 

		cout << color(!flagMin and value == *min ? LTMAGENTA_ON_BLACK : flagMin ? LTYELLOW_ON_BLACK : YELLOW_ON_BLACK) << setw(2) 
			<< i++ << color(LTCYAN_ON_BLACK) << " | "; 

		// если значение элемента равно минимальному
		if (value == *min)
			flagMin = true;
		});

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    " 
		<< color(LTCYAN_ON_BLACK) << " | ";

	// вывод элементов 
	for_each(vec.begin(), vec.end(), [flagMin, min](int value) mutable {

		cout << color(!flagMin and value == *min ? LTMAGENTA_ON_BLACK : flagMin ? LTGREEN_ON_BLACK : GREEN_ON_BLACK) << setw(2)
			<< value << color(LTCYAN_ON_BLACK) << " | ";

		// если значение элемента равно минимальному
		if (value == *min)
			flagMin = true;
		});

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();
}

// 4. Удалить элементы, встречающиеся менее двух раз
void App::taskOneDeleteDouble()
{
	showNavBarMessage(hintColor, "  4. Удалить элементы, встречающиеся менее двух раз");

	cout << "\n";

	// вывод вектора 
	showVector(vec_, "Вектор", "Исходный вектор", showElemVectorRem);

	cout << "\n\n\n";

	// удаление элементов вектора, встречающихся меньше двух раз
	for (int i = 0; i < vec_.size(); i++)
	{
		// текущее значение 
		int val = vec_[i];

		// если элементов с теущим значеним меньше двух 
		if (count_if(vec_.begin(), vec_.end(), [val](int value) { return value == val;}) < 2)
		{
			// удаление элементов по значению
			vec_.erase(remove_if(vec_.begin(), vec_.end(), [val](int value) { return value == val; }));

			// обнуление индекса 
			i = 0;
		}
	}

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор после удаления", showElemVectorRem);
}

// вывод элементов с подсветкой элементов встречающихся менее двух раз 
void App::showElemVectorRem(vector<int> vec)
{
	// если вектор пуст 
	if (vec.empty())
	{
		cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+                                       "
			<< color(LTRED_ON_BLACK) << "  НЕТ ДАННЫХ  " << color(LTCYAN_ON_BLACK)
			<< "                                    |\n"
			<< color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+—————————————————————————————————————————————————————————————————————————————————————————+\n";

		return;
	}

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     "
		<< color(LTCYAN_ON_BLACK) << " | ";

	// индекс 
	int i = 0;

	// ссылка на вектор 
	auto& vecLink = vec;

	// вывод индексов 
	for_each(vec.begin(), vec.end(), [i, vec](int value) mutable {

		cout << color(count_if(vec.begin(), vec.end(), [value](int val) { return value == val; }) < 2 ? LTMAGENTA_ON_BLACK : LTYELLOW_ON_BLACK) << setw(2)
			<< i++ << color(LTCYAN_ON_BLACK) << " | ";
		});

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    "
		<< color(LTCYAN_ON_BLACK) << " | ";

	// вывод элементов 
	for_each(vec.begin(), vec.end(), [vec](int value) mutable {

		cout << color(count_if(vec.begin(), vec.end(), [value](int val) { return value == val; }) < 2 ? LTMAGENTA_ON_BLACK : LTGREEN_ON_BLACK) << setw(2)
			<< value << color(LTCYAN_ON_BLACK) << " | ";
		});

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();
}

// 5. Упорядочить вектор по возрастанию модулей элементов
void App::taskOneSortByModule()
{
	showNavBarMessage(hintColor, "  5. Упорядочить вектор по возрастанию модулей элементов");

	cout << "\n";

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор до сортировки");

	cout << "\n\n\n";

	// сортировка 
	sort(vec_.begin(), vec_.end(), [](int val1, int val2) { return abs(val1) < abs(val2); });

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор после сортировки");

}

// 6. Продублировать отрицательные элементы вектора
void App::taskOneDoubleNegative()
{
	showNavBarMessage(hintColor, "  6. Продублировать отрицательные элементы вектора");

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор до дублирования", showElemVectorNegative);

	// итератор для поиска отрицательных элементов
	auto it = vec_.begin();

	// дублирование отрицательных элементов
	while(true)
	{
		// поиск отрицательного элемента 
		it = find_if(it, vec_.end(), [](int value) { return value < 0; });
		
		// если элемент не найден то выход из цикла
		if (it == vec_.end())
			break;

		// дублирование отрицательного элемента 
		it = vec_.insert(it, *it) + 2;
	}

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор после дублирования", showElemVectorNegative);

	cout << "\n\n";
}

// вывод элементов с подсветкой отрицательных елементов
void App::showElemVectorNegative(vector<int> vec)
{
	// если вектор пуст 
	if (vec.empty())
	{
		cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+                                       "
			<< color(LTRED_ON_BLACK) << "  НЕТ ДАННЫХ  " << color(LTCYAN_ON_BLACK)
			<< "                                    |\n"
			<< color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+—————————————————————————————————————————————————————————————————————————————————————————+\n";

		return;
	}

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     "
		<< color(LTCYAN_ON_BLACK) << " | ";

	// индекс 
	int i = 0;
	
	// вывод индексов 
	for_each(vec.begin(), vec.end(), [i](int value) mutable
		{
			cout << color(value < 0 ? LTMAGENTA_ON_BLACK : LTYELLOW_ON_BLACK) << setw(2)
				<< i++ << color(LTCYAN_ON_BLACK) << " | ";
		});
	
	cout << "\n";

	// вывод разделительной полосы
	showLineVector();

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    "
		<< color(LTCYAN_ON_BLACK) << " | ";

	// вывод элементов 
	for_each(vec.begin(), vec.end(), [](int value) mutable
		{
			cout << color(value < 0 ? LTMAGENTA_ON_BLACK : LTGREEN_ON_BLACK) << setw(2)
				<< value << color(LTCYAN_ON_BLACK) << " | ";
		});

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();
}

// 7. Сохранить вектор в бинарном файле при помощи потока вывода
void App::taskOneSaveBinFile()
{
	showNavBarMessage(hintColor, "  7. Сохранить вектор в бинарном файле при помощи потока вывода");

	cout << "\n";

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор для сохранения в файл");

	// сохранение вектора в файл
	saveVectorBinFile(nameFileVector_, vec_);

	cout << "\n\n\n";

	// отчистка вектора 
	vec_.clear();

	// считываение вектора из файла в вектор
	readVectorBinFile(nameFileVector_, vec_);
	
	// вывода вектора 
	showVector(vec_, "Вектор", "Вектор из файла");

	cout << "\n\n\n";
}

// сохранение вектора в файл
void App::saveVectorBinFile(string nameFile, vector<int>& vec)
{
	// открытие потока для бинарной записи в файл 
	ofstream ofs(nameFile.c_str(), ios::binary | ios::trunc);

	// если поток открыт неуспешно
	if (!ofs.is_open())
	{
		throw exception(("App: Ошибка отрытия файла "s + nameFile).c_str());
	}

	// вывод в файл вектора 
	for_each(vec.begin(), vec.end(), [&ofs](int value) { ofs.write((char*)&value, sizeof(value)); });

	// закрытие потока 
	ofs.close();
}

// чтение вектора из файла
void App::readVectorBinFile(string nameFile, vector<int>& vec)
{
	// открытие потока для бинарного чтения
	ifstream ifs(nameFile, ios::binary | ios::beg | ios::in);

	// если поток открыт неуспешно
	if (!ifs.is_open())
	{
		throw exception(("App: Ошибка отрытия файла "s + nameFile).c_str());
	}

	// ввод из файла в вектор 
	while (true)
	{
		int tmp = 0;
		ifs.read((char*)&tmp, sizeof(tmp));

		if (ifs.eof()) break;
	
		vec.push_back(tmp);
	}

	// закрытие потока 
	ifs.close();
}

// 8. Прочитать вектор из бинарного файла при помощи потока ввода
void App::taskOneLoadBinFile()
{
	showNavBarMessage(hintColor, "  8. Прочитать вектор из бинарного файла при помощи потока ввода");

	cout << "\n";

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор до загрузки");

	cout << "\n\n\n";

	// отчистка вектора 
	vec_.clear();

	// считываение вектора из файла в вектор
	readVectorBinFile(nameFileVector_, vec_);

	// вывод вектора 
	showVector(vec_, "Вектор", "Вектор после загрузки");

	cout << "\n\n\n";
}

#pragma region Общие методы 

// вывод вектора 
void App::showVector(vector<int> vec, string messageName, string messageInfo, void showElemFunc(vector<int> vec))
{
	// вывод шапки с информацией
	showHeadVector(vec, messageName, messageInfo);

	// вывод элементов 
	showElemFunc(vec);
}

// вывод шапки с информацией
void App::showHeadVector(vector<int> vec, string messageName, string messageInfo)
{
	//           |        18        |                  37                   |                         48                      |
	cout << color(LTCYAN_ON_BLACK)
		<< "     +——————————————————+———————————————————————————————————————+—————————————————————————————————————————————————+\n"
		<< "     | " << color(WHITE_ON_BLACK) << "Размер: " << color(LTGREEN_ON_BLACK) << setw(8) << vec.size() << color(LTCYAN_ON_BLACK) << " | "
		<< left
		<< color(WHITE_ON_BLACK) << "Название: " << color(LTYELLOW_ON_BLACK) << setw(27) << messageName << color(LTCYAN_ON_BLACK) << " | "
		<< color(WHITE_ON_BLACK) << "Описание: " << color(LTYELLOW_ON_BLACK) << setw(37) << messageInfo << color(LTCYAN_ON_BLACK) << " |\n"
		<< right;

	showLineVector();
}

// вывод элементов 
void App::showElemVector(vector<int> vec)
{
	// если вектор пуст 
	if (vec.empty())
	{
		cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+                                       " 
			<< color(LTRED_ON_BLACK) << "  НЕТ ДАННЫХ  " << color(LTCYAN_ON_BLACK) 
			<< "                                    |\n"
			<< color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    " << color(LTCYAN_ON_BLACK) << " | "
			<< setw(90) << "|\n"
			<< "     +——————————————————+—————————————————————————————————————————————————————————————————————————————————————————+\n";
			
		return;
	}

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "     Индекс     " << color(LTCYAN_ON_BLACK) << " | ";

	int i = 0;

	// вывод индексов 
	for_each(vec.begin(), vec.end(), [i](int vec) mutable { cout << color(LTYELLOW_ON_BLACK) << setw(2) << i++ << color(LTCYAN_ON_BLACK) << " | "; });

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();

	cout << color(LTCYAN_ON_BLACK) << "     | " << color(WHITE_ON_BLACK) << "    Значение    " << color(LTCYAN_ON_BLACK) << " | ";

	// вывод элементов 
	for_each(vec.begin(), vec.end(), [](int vec) { cout << color(LTGREEN_ON_BLACK) << setw(2) << vec << color(LTCYAN_ON_BLACK) << " | "; });

	cout << "\n";

	// вывод разделительной полосы
	showLineVector();
}

// вывод разделительной линии
void App::showLineVector()
{
	// текущий цвет 
	short cl = getColor();

	//           |        18        |                                     4 x 18                                              |
	cout << color(LTCYAN_ON_BLACK)
		<< "     +——————————————————+————+————+————+————+————+————+————+————+————+————+————+————+————+————+————+————+————+————+\n"
		<< color(cl);
}

#pragma endregion 

#pragma endregion

#pragma endregion

#pragma region Задание 2. Библиотека

/*
	——————————————————————————————————————————————————————————————————————————————————————————————————————————

	Задача 2 (для претендентов на 10 баллов).
	С использованием классов и алгоритмов STL, лямбда-выражений написать приложение
	для решения следующей задачи из практикума Павловской Т.А. и Щупака Ю.А. по ООП
	на C++:

	Написать приложения для учета книг в библиотеке. Сведения о книгах содержат:
	идентификатор (учетный номер единицы хранения), фамилию и инициалы автора, название
	книги, год издания, количество экземпляров данной книги в библиотеке. Сведения о
	библиотеке – адрес библиотеки, фамилия и инициалы директора, коллекция книг. Данные
	о библиотеке и книгах хранить в текстовом файле в формате CSV, символ разделителя «;».
	Формат файла – в первой строке данные библиотеки, в остальных строках данные о книгах,
	одна книга – одна строка, начальная инициализация при первом запуске приложения – не
	менее 12 книг. С помощью меню реализовать выбор и выполнение следующих функций:
	•	Вывод данных библиотеки и коллекции книг в консоль
	•	Добавление книги, ввод данных с клавиатуры, сохранение измененной коллекции в
		текстовый файл
	•	Удаление книг по идентификатору, сохранение измененной коллекции в текстовый файл
	•	Изменение количества книг заданного автора на вводимое с клавиатуры значение,
		сохранение измененной коллекции в текстовый файл
	•	Отбор книг в отдельный список по заданному году издания, вывод этого списка в
		консоль, упорядочив по году издания, не изменять исходную коллекцию книг, файл
		данных
	•	Отбор книг в отдельный список по автору, вывод этого списка в консоль, упорядочив
		по автору, не изменять исходную коллекцию книг, файл данных
	•	Сортировка книг по убыванию количества книг, вывод в консоль без изменения файла
		данных
	•	Сортировка книг по идентификатору, вывод в консоль без изменения файла данных
	•	Сортировка книг по названию, вывод в консоль без изменения файла данных
	Постарайтесь свести к минимуму использование циклов – максимально используйте алгоритмы
	STL.

	——————————————————————————————————————————————————————————————————————————————————————————————————————————
*/

// Задание 2. Библиотека
void App::task2()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// 1. Вывод данных библиотеки и коллекции книг в консоль
		CMD_POINT_ONE,
		// 2. Добавление книги
		CMD_POINT_TWO,
		// 3. Удаление книг по идентификатору
		CMD_POINT_THREE,
		// 4. Изменение количества книг заданного автора
		CMD_POINT_FOUR,
		// 5. Отбор книг по году издания
		CMD_POINT_FIVE,
		// 6. Отбор книг по автору
		CMD_POINT_SIX,
		// 7. Сортировка книг по убыванию количества книг
		CMD_POINT_SEVEN,
		// 8. Сортировка книг по идентификатору
		CMD_POINT_EIGHT,
		// 9. Сортировка книг по названию
		CMD_POINT_NINE
	};

	// количество пунктов меню
	const int N_MENU = 10;

	MenuItem items[N_MENU] = {
		MenuItem("1. Вывод данных библиотеки и коллекции книг в консоль", CMD_POINT_ONE),
		MenuItem("2. Добавление книги", CMD_POINT_TWO),
		MenuItem("3. Удаление книг по идентификатору", CMD_POINT_THREE),
		MenuItem("4. Изменение количества книг заданного автора", CMD_POINT_FOUR),
		MenuItem("5. Отбор книг по году издания", CMD_POINT_FIVE),
		MenuItem("6. Отбор книг по автору", CMD_POINT_SIX),
		MenuItem("7. Сортировка книг по убыванию количества книг", CMD_POINT_SEVEN),
		MenuItem("8. Сортировка книг по идентификатору", CMD_POINT_EIGHT),
		MenuItem("9. Сортировка книг по названию", CMD_POINT_NINE),

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

			cls();

			switch (cmd)
			{

			// 1. Вывод данных библиотеки и коллекции книг в консоль
			case CMD_POINT_ONE:
				app.showLibrary();
				break;

			// 2. Добавление книги
			case CMD_POINT_TWO:
				app.addBook();
				break;

			// 3. Удаление книг по идентификатору
			case CMD_POINT_THREE:
				app.deleteByID();
				break;

			// 4. Изменение количества книг заданного автора
			case CMD_POINT_FOUR:
				app.editCountBooks();
				break;

			// 5. Отбор книг по году издания
			case CMD_POINT_FIVE:
				app.selectionByYear();
				break;

			// 6. Отбор книг по автору
			case CMD_POINT_SIX:
				app.selectionByAuthor();
				break;

			// 7. Сортировка книг по убыванию количества книг
			case CMD_POINT_SEVEN:
				app.sortByCountBook();
				break;

			// 8. Сортировка книг по идентификатору
			case CMD_POINT_EIGHT:
				app.sortByBookID();
				break;

			// 9. Сортировка книг по названию
			case CMD_POINT_NINE:
				app.sortByNameBook();
				break;

			}

			cout << "\n\n";
			getKey();
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

// 1. Вывод данных библиотеки и коллекции книг в консоль
void App::showLibrary()
{
	showNavBarMessage(hintColor, "  1. Вывод данных библиотеки и коллекции книг в консоль");

	cout << "\n";

	// вывод библиотеки
	library_.showLibrary();
}

// 2. Добавление книги
void App::addBook()
{
	showNavBarMessage(hintColor, "  2. Добавление книги");

	cout << "\n";

	// вывод библиотеки
	library_.showLibrary("Библиотека", "До добавления книги");

	cout << "\n\n";

	// книга для добавления
	Book newBook;

#pragma region Ввод даных книги 

	// строка для ввода 
	string line;

	// цвет по умолчанию
	short cl = getColor();

	// ввод ID
	showInputLine("\tID(разамер 10; если оставить поле пустым ID будет сгенерирован): ", 12, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);

	// установка цвета по умолчанию
	setColor(cl);

	// если строка пуста 
	if (line.size() == 0)
		line = Book::genId();

	// проверка ID на уникальность
	if (!library_.checkId(line))
		throw exception(("App: ID "s + line + " не уникален!").c_str());

	// установка ID
	newBook.setId(line);

	cout << "\n\n";

	// ввод названия книги
	showInputLine("\tНазвание книги: ", 30, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);

	// установка названия книги
	newBook.setNameBook(line);

	cout << "\n\n";

	// установка цвета по умолчанию
	setColor(cl);

	// ввод автора
	showInputLine("\tАвтор: ", 30, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);

	// установка автора 
	newBook.setNameAuthor(line);

	cout << "\n\n";

	// установка цвета по умолчанию
	setColor(cl);

	// переменная для ввода 
	int num;

	// ввод года издания
	showInputLine("\tГод издания: ", 6, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> num;
	
	// установка года издания 
	newBook.setYear(num);

	cout << "\n\n";

	// установка цвета по умолчанию
	setColor(cl);

	// ввод количества книг
	showInputLine("\tКоличество книг: ", 6, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> num;

	// установка года издания 
	newBook.setCountBook(num);

	cout << "\n\n";

	// установка цвета по умолчанию
	setColor(cl);

	// выключение курсора 
	setCursorVisible(false);

#pragma endregion 

	// добавление книги в библиотеку
	library_.addBook(newBook);

	// сохранение библиотеки в файл
	library_.saveLibrary();

	// !!! ДЛЯ ДЕМОНСТРАЦИИ ПРАВИЛЬНОЙ РАБОТЫ СОХРАНЕНИЯ И ЗАГРУЗКИ ИЗ ФАЙЛА !!!

	// отчистка библиотеки
	library_.clear();

	// загрузка из файла 
	library_.loadLibrary();

	// !!! !!!

	cout << "\n";

	// вывод списка книг после добавления
	library_.showLibrary("Библиотека", "После добавления книги");

	cout << "\n\n\n";

	// вывод книги 
	library_.showHead(1, "Книга", "Новая книга для добавления");
	library_.showElem(newBook);
	library_.showLine();
}

// 3. Удаление книг по идентификатору
void App::deleteByID()
{
	showNavBarMessage(hintColor, "  3. Удаление книг по идентификатору");

	cout << "\n";

	// вывод библиотеки
	library_.showLibrary("Библиотека", "До удаления книги");

	cout << "\n\n\n";

	// строка для ввода 
	string line;

	// цвет по умолчанию
	short cl = getColor();

	// ввод ID
	showInputLine("\tID(рзамер 10): ", 12, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);

	// установка цвета по умолчанию
	setColor(cl);

	// выключение курсора 
	setCursorVisible(false);

	// если строка пуста 
	if (line.size() == 0)
		line = Book::genId();

	// книга удаляемая
	Book remBook = library_.getBook(line);

	// поиск и удаление книги
	library_.removeBook(line);

	// сохранение библиотеки в файл
	library_.saveLibrary();

	// !!! ДЛЯ ДЕМОНСТРАЦИИ ПРАВИЛЬНОЙ РАБОТЫ СОХРАНЕНИЯ И ЗАГРУЗКИ ИЗ ФАЙЛА !!!

	// отчистка библиотеки
	library_.clear();

	cout << "\n";

	// загрузка из файла 
	library_.loadLibrary();

	// !!! !!!

	// вывод библиотеки после удаления
	library_.showLibrary("Библиотека", "После удаления книги");

	// вывод удалённой книги
	library_.showHead(1, "Книга", "Удалённая книга");
	library_.showElem(remBook);
	library_.showLine();
}

// 4. Изменение количества книг заданного автора
void App::editCountBooks()
{
	showNavBarMessage(hintColor, "  4. Изменение количества книг заданного автора");

	cout << "\n";

	// вывод библиотеки
	library_.showLibrary("Библиотека", "До изменения количества книг");

	cout << "\n\n\n";

	// ссылка на вектор с книгами
	vector<Book>& vec = library_.getBooks();

#pragma region Ввод данных

	// строка для ввода 
	string line;

	// переменная для ввода 
	int num;

	// цвет по умолчанию
	short cl = getColor();

	// ввод ID
	showInputLine("\tАвтор: ", 30, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);

	// установка цвета по умолчанию
	setColor(cl);

	// выключение курсора 
	setCursorVisible(false);

	// если нет книг заданного автора 
	if (find_if(vec.begin(), vec.end(), [&line](Book& book) { return book.getNameAuthor() == line; }) == vec.end())
		throw exception("App: Книг с заданного автора не найдено!");

	cout << "\n\n";

	// ввод количества книг
	showInputLine("\tКоличество книг: ", 6, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> num;

	// установка цвета по умолчанию
	setColor(cl);

	// выключение курсора 
	setCursorVisible(false);

	// если количество книг некорректно
	if (num < 0)
		throw exception("App: Некорректное количество книг!");

#pragma endregion

	cout << "\n";

	// изменение по автору
	for_each(vec.begin(), vec.end(), [&line, num](Book &book) { if (book.getNameAuthor() == line) book.setCountBook(num); });

	// сохранение библиотеки в файл
	library_.saveLibrary();

	// !!! ДЛЯ ДЕМОНСТРАЦИИ ПРАВИЛЬНОЙ РАБОТЫ СОХРАНЕНИЯ И ЗАГРУЗКИ ИЗ ФАЙЛА !!!

	// отчистка библиотеки
	library_.clear();

	// загрузка из файла 
	library_.loadLibrary();

	// !!! !!!

	// вывод библиотеки
	library_.showLibrary("Библиотека", "После изменения количества книг");
}

// 5. Отбор книг по году издания
void App::selectionByYear()
{
	showNavBarMessage(hintColor, "  5. Отбор книг по году издания");

	cout << "\n";

	// вывод библиотеки
	library_.showLibrary();

	cout << "\n\n\n";

#pragma region Ввод данных

	// переменная для ввода 
	int num;

	// цвет по умолчанию
	short cl = getColor();

	// ввод года издания
	showInputLine("\tГод издания: ", 6, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin >> num;

	// установка цвета по умолчанию
	setColor(cl);

	// выключение курсора 
	setCursorVisible(false);

#pragma endregion

	cout << "\n";

	// вектор для отбора 
	vector<Book> selVec;

	// вектор книг
	vector<Book>& books = library_.getBooks();

	// отбор по году издания в отдельный вектор 
	for_each(books.begin(), books.end(), [&selVec, &num](Book& book) { if (book.getYear() == num) selVec.push_back(book); });

	// вывод отобранных по автору книг
	Library::showHead((int)selVec.size(), "Книги", "Селекция по году издания");
	Library::showElem(selVec);
	Library::showLine();
}

// 6. Отбор книг по автору
void App::selectionByAuthor()
{
	showNavBarMessage(hintColor, "  6. Отбор книг по автору");

	cout << "\n";

	// вывод библиотеки
	library_.showLibrary();

	cout << "\n\n\n";

#pragma region Ввод данных

	// строка для ввода 
	string line;

	// цвет по умолчанию
	short cl = getColor();

	// ввод года автора
	showInputLine("\tАвтор: ", 30, BLACK_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	getline(cin, line);

	// установка цвета по умолчанию
	setColor(cl);

	// выключение курсора 
	setCursorVisible(false);

#pragma endregion

	cout << "\n";

	// вектор для отбора 
	vector<Book> selVec;

	// вектор книг
	vector<Book>& books = library_.getBooks();

	// отбор по году издания в отдельный вектор 
	for_each(books.begin(), books.end(), [&selVec, &line](Book& book) { if (book.getNameAuthor() == line) selVec.push_back(book); });

	// вывод отобранных по автору книг
	Library::showHead((int)selVec.size(), "Книги", "Селекция по автору");
	Library::showElem(selVec);
	Library::showLine();

}

// 7. Сортировка книг по убыванию количества книг
void App::sortByCountBook()
{
	showNavBarMessage(hintColor, "  7. Сортировка книг по убыванию количества книг");

	cout << "\n";

	// ссылка на вектор книг в библиотеке
	auto& books = library_.getBooks();

	// сортировка по убыванию количества книг 
	sort(books.begin(), books.end(), [](Book book1, Book book2) { return book1.getCountBook() > book2.getCountBook(); });

	// вывод библиотеки
	library_.showLibrary("Библиотека", "Сортировка по количеству книг");

	cout << "\n";
}

// 8. Сортировка книг по идентификатору
void App::sortByBookID()
{
	showNavBarMessage(hintColor, "  8. Сортировка книг по идентификатору");

	cout << "\n";

	// ссылка на вектор книг в библиотеке
	auto& books = library_.getBooks();

	// сортировка книг по идентификатору 
	sort(books.begin(), books.end(), [](Book book1, Book book2) { return book1.getId() < book2.getId(); });

	// вывод библиотеки
	library_.showLibrary("Библиотека", "Сортировка по идентификатору");

	cout << "\n";
}

// 9. Сортировка книг по названию
void App::sortByNameBook()
{
	showNavBarMessage(hintColor, "  9. Сортировка книг по названию");

	cout << "\n";

	// ссылка на вектор книг в библиотеке
	auto& books = library_.getBooks();

	// сортировка книг по названию 
	sort(books.begin(), books.end(), [](Book book1, Book book2) { return book1.getNameBook() < book2.getNameBook(); });

	// вывод библиотеки
	library_.showLibrary("Библиотека", "Сортировка по названию книг");

	cout << "\n";
}

#pragma endregion

#pragma region Задание 3. Телефонная станция

/*
	——————————————————————————————————————————————————————————————————————————————————————————————————————————

	Задача 3 (для претендентов на 12 баллов) – вариант 1
	Класс Bill представляет собой разовый платеж за телефонный разговор. Класс должен включать
	поля: дата и время начала разговора, дата и время окончания разговора.

	Время разговора вычисляется в минутах, неполная минута, считается за полную. Должен быть
	реализован метод, вычисляющий сумму к оплате за разговор.
	Для представления даты и времени используйте класс DateTime с полями – день, месяц, год,
	час, минута, секунда. Реализуйте методы вычисления разности между двумя моментами времени
	в секундах. Перегрузите операции сравнения двух моментов времени.

	Разработайте класс – список плательщиков ListPayer. Класс содержит список плательщиков за
	телефонные услуги, дату создания списка, номер списка.

	Один элемент списка включает: информацию о плательщике – фамилия и инициалы плательщика, 
	номер телефона, тариф за минуту разговора, скидка (в процентах), коллекция записей класса
	Bill, дату платежа, сумму платежа.

	Реализовать для класса ListPayer:
	•	Метод добавления плательщика в список
	•	Метод удаления плательщика из списка
	•	Метод поиска плательщика по номеру телефона, сохранять в бинарном потоке вывода
	•	Метод поиска плательщика по фамилии и инициалам, сохранять в бинарном потоке вывода
	•	Метод поиска плательщиков по дате платежа, найденные записи помещать в отдельную коллекцию,
		сохранять в бинарном потоке вывода
	•	Метод вычисления полной стоимости платежей всего списка
	Реализовать создание объектов ListPayer, операции объединения и пересечения списков.
	•	Операция объединения списка – бинарная операция, на выходе получаем список из элементов двух
		списков, без дубликатов.
	•	Операция пересечения списка – бинарная операция, на выходе получаем список из элементов
		имеющихся и в первом, и во втором списках, без дубликатов.
	Реализовать отбор данных из списка плательщиков:
	•	По дате платежа, сортировка по номеру телефона
	•	По номеру телефона, сортировка по номеру телефона
	Реализовать сортировку списка плательщиков:
	•	По номеру телефона
	•	По убыванию суммы к оплате
	•	По убыванию времени разговоров

	——————————————————————————————————————————————————————————————————————————————————————————————————————————
*/

// Задание 3. Телефонная станция
void App::task3()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// 1. Вывод списка плательщиков 
		CMD_POINT_ONE,
		// 2. Добавление плательщика в список
		CMD_POINT_TWO,
		// 3. Удаление плательщика из списка
		CMD_POINT_THREE,
		// 4. Поиск плательщика по номеру телефона и вывод звонков
		CMD_POINT_FOUR,
		// 5. Поиск плательщика по фамилии и инициалам
		CMD_POINT_FIVE,
		// 6. Поиска плательщиков по дате платежа
		CMD_POINT_SIX,
		// 7. Вычисления полной стоимости платежей всего списка
		CMD_POINT_SEVEN,
		// 8. Объединения списка
		CMD_POINT_EIGHT,
		// 9. Пересечения списка
		CMD_POINT_NINE,
		// 10. Отбор данных по дате платежа
		CMD_POINT_TEN,
		// 11. Отбор данных по номеру телефона
		CMD_POINT_ELEVEN,
		// 12. Сортировка по номеру телефона
		CMD_POINT_TWELVE,
		// 13. Сортировка по убыванию суммы к оплате
		CMD_POINT_THIRTEEN,
		// 14. Сортировка по убыванию времени разговоров
		CMD_POINT_FOURTEEN
	};

	// количество пунктов меню
	const int N_MENU = 15;

	MenuItem items[N_MENU] = {
		MenuItem("1. Вывод списка плательщиков ", CMD_POINT_ONE),
		MenuItem("2. Добавление плательщика в список", CMD_POINT_TWO),
		MenuItem("3. Удаление плательщика из списка", CMD_POINT_THREE),
		MenuItem("4. Поиск плательщика по номеру телефонаи и вывод звонков", CMD_POINT_FOUR),
		MenuItem("5. Поиск плательщика по фамилии и инициалам", CMD_POINT_FIVE),
		MenuItem("6. Поиска плательщиков по дате платежа", CMD_POINT_SIX),
		MenuItem("7. Вычисления полной стоимости платежей всего списка", CMD_POINT_SEVEN),
		MenuItem("8. Объединения списка", CMD_POINT_EIGHT),
		MenuItem("9. Пересечения списка", CMD_POINT_NINE),
		MenuItem("10. Отбор данных по дате платежа", CMD_POINT_TEN),
		MenuItem("11. Отбор данных по номеру телефона", CMD_POINT_ELEVEN),
		MenuItem("12. Сортировка по номеру телефона", CMD_POINT_TWELVE),
		MenuItem("13. Сортировка по убыванию суммы к оплате", CMD_POINT_THIRTEEN),
		MenuItem("14. Сортировка по убыванию времени разговоров", CMD_POINT_FOURTEEN),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 3. Телефонная станция", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			cls();

			switch (cmd)
			{
			// 1. Вывод списка плательщиков 
			case CMD_POINT_ONE:
				app.showListPayer();
				break;
			// 2. Добавление плательщика в список
			case CMD_POINT_TWO:
				app.addPayer();
				break;
			// 3. Удаление плательщика из списка
			case CMD_POINT_THREE:
				app.deletePayer();
				break;
			// 4. Поиск плательщика по номеру телефона и вывод звонков
			case CMD_POINT_FOUR:
				app.searchPayerByNumber();
				break;
			// 5. Поиск плательщика по фамилии и инициалам
			case CMD_POINT_FIVE:
				app.searchPayerName();
				break;
			// 6. Поиска плательщиков по дате платежа
			case CMD_POINT_SIX:
				app.searchPayerByDate();
				break;
			// 7. Вычисления полной стоимости платежей всего списка
			case CMD_POINT_SEVEN:
				app.sumPay();
				break;
			// 8. Объединения списка
			case CMD_POINT_EIGHT:
				app.mergeListPayers();
				break;
			// 9. Пересечения списка
			case CMD_POINT_NINE:
				app.crossListPayers();
				break;
			// 10. Отбор данных по дате платежа
			case CMD_POINT_TEN:
				app.selectionPayerByDate();
				break;
			// 11. Отбор данных по номеру телефона
			case CMD_POINT_ELEVEN:
				app.selectionPayerByNumber();
				break;
			// 12. Сортировка по номеру телефона
			case CMD_POINT_TWELVE:
				app.sortByNumber();
				break;
			// 13. Сортировка по убыванию суммы к оплате
			case CMD_POINT_THIRTEEN:
				app.sortByPay();
				break;
			// 14. Сортировка по убыванию времени разговоров
			case CMD_POINT_FOURTEEN:
				app.sortByTime();
				break;
			}

			cout << "\n\n";
			getKey();

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

// 1. Вывод списка плательщиков 
void App::showListPayer()
{
	showNavBarMessage(hintColor, "  1. Вывод списка плательщиков");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();
}

// 2. Добавление плательщика в список
void App::addPayer()
{
	showNavBarMessage(hintColor, "  2. Добавление плательщика в список");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable("Список плательщиков", "Данные до добавления");

	// выражение для генерации
	auto lambda = []() { return genDateTime(1, 28, 1, 12, 2018, 2020, 0, 23, 0, 59, 0, 59); };

	// плательщик для добавления
	Payer payer("Нектов В. Т.", "0509320610", getRand(0., 1.), getRand(0, 20), lambda());

	// генерация списка разговоров
	auto getBills = [](Payer& payer) {

		// вектор объектов Bill
		vector<Bill> bills;

		// максимальная дата и время
		DateTime max = payer.getDatePay();

		// размер вектора с звонками
		int size = getRand(1, 10);

		// генерация начального и конечного времени звонка
		DateTime start, end;

		for (int i = 0; i < size; i++)
		{
			do
			{
				end = DateTime(getRand(1, max.getDay()), max.getMonth(), max.getYear(),
					getRand(0, max.getHour()), getRand(0, max.getMinute()), getRand(0, max.getSecond()));

				start = DateTime(end.getDay(), end.getMonth(), end.getYear(),
					getRand(0, end.getHour()), getRand(0, end.getMinute()), getRand(0, end.getSecond()));
			} 				while (start >= end);

			// добавление в вектор
			bills.push_back(Bill(start, end));
		}

		return bills;
	};

	// звонки для добавления 
	payer.setBills(getBills(payer));

	cout << "\n";

	// добавление плетельщика 
	listPayer_.addPayer(payer);

	// вывод списка 
	listPayer_.showTable("Список плательщиков", "Данные после добавления");

	// вывод плательщика для добавления 
	cputs("\n     ——————————————————————————————————————— Плательщик для добавления ———————————————————————————————————————\n", MAGENTA_ON_BLACK);
	payer.showHead();
	payer.showPayer(1);
	payer.showLine();
	payer.showBills();

}

// 3. Удаление плательщика из списка
void App::deletePayer()
{
	showNavBarMessage(hintColor, "  3. Удаление плательщика из списка");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable("Список плательщиков", "Данные до удаления");

	// номер удаляемого плательщика 
	string number;

	// ввод данных для удаления 
	setColor(LTYELLOW_ON_BLACK);
	showInputLine("\n\n     Введите номер телефона: ", 12, BLACK_ON_LTCYAN);
	getline(cin, number);
	setColor(mainColor);

	// удаление номера 
	listPayer_.delPayer(number);

	// вывод списка 
	listPayer_.showTable("Список плательщиков", "Данные после удаления");
}

// считывание объектов Payer в вектор 
void App::readPayerFile(vector<Payer>& payers, string fileName)
{
	// открытие потока бинарного чтения/записи 
	fstream fs(nameFileResSearch_, ios::binary | ios::in);

	// если файл не удалось открыть
	if (!fs.is_open())
		throw exception(("App: Не удалось открыть файл "s + nameFileResSearch_).c_str());

	// объект Payer для чтения из файла 
	Payer payer;

	// считывание из файла в вектор 
	while (true)
	{
		// считывание данных из файла 
		payer.read(fs);

		// если достигнут конец файла 
		if (fs.eof()) break;

		// добавление считанного объекта в конец вектора 
		payers.push_back(payer);
	}

	// закрытие файла 
	fs.close();
}

// 4. Поиск плательщика по номеру телефона и вывод звонков
void App::searchPayerByNumber()
{
	showNavBarMessage(hintColor, "  4. Поиск плательщика по номеру телефона и вывод звонков");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

	// номер искомого плательщика 
	string number;

	// ввод данных для поиска 
	setColor(LTYELLOW_ON_BLACK);
	showInputLine("\n\n     Введите номер телефона: ", Payer::N_PHONE_NUMBER + 2, BLACK_ON_LTCYAN);
	getline(cin, number);
	setColor(mainColor);

	// поиск и запись в файл найденного плательщика  
	listPayer_.searchByNumber(number, nameFileResSearch_);

	// коллекция найденных объектов Payer 
	vector<Payer>payers;

	// чтение результата из файла 
	readPayerFile(payers, nameFileResSearch_);

	// вывод плательщика 
	cputs("\n     ——————————————————————————————— Найденные плательщики загруженные из файла ——————————————————————————————\n", MAGENTA_ON_BLACK);
	ListPayer::showElem(payers);
	payers[0].showBills();

	// файл для сохранения 
	cout << color(LTYELLOW_ON_BLACK) << "\n\n     Файл для сохранения/загрузки: " << color(LTGREEN_ON_BLACK) << nameFileResSearch_ << endl;
}

// 5. Поиск плательщика по фамилии и инициалам
void App::searchPayerName()
{
	showNavBarMessage(hintColor, "  5. Поиск плательщика по фамилии и инициалам");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

	// имя и инициалы искомого плательщика 
	string name;

	// ввод данных для поиска 
	setColor(LTYELLOW_ON_BLACK);
	showInputLine("\n\n     Введите филию и инициалы: ", Payer::N_MAX_NAME_PAYER + 2, BLACK_ON_LTCYAN);
	getline(cin, name);
	setColor(mainColor);

	// поиск и запись в файл найденного плательщика  
	listPayer_.searchByName(name, nameFileResSearch_);

	// коллекция найденных объектов Payer 
	vector<Payer>payers;

	// чтение результата из файла 
	readPayerFile(payers, nameFileResSearch_);

	// вывод плательщика 
	cputs("\n     ——————————————————————————————— Найденные плательщики загруженные из файла ——————————————————————————————\n", MAGENTA_ON_BLACK);
	ListPayer::showElem(payers);

	// файл для сохранения 
	cout << color(LTYELLOW_ON_BLACK) << "\n\n     Файл для сохранения/загрузки: " << color(LTGREEN_ON_BLACK) << nameFileResSearch_ << endl;
}

// 6. Поиска плательщиков по дате платежа
void App::searchPayerByDate()
{
	showNavBarMessage(hintColor, "  6. Поиска плательщиков по дате платежа");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

	// день
	int day;

	// месяц
	int month;

	// года 
	int year;

	// ввод данных для поиска 
	setColor(LTYELLOW_ON_BLACK);
	showInputLine("\n\n     Введите дату платежа(день.месяц.год): ", 16, BLACK_ON_LTCYAN);
	cin >> day;
	cin.ignore(1, '.');
	cin >> month;
	cin.ignore(1, '.');
	cin >> year;

	setColor(mainColor);

	// если данные некорректны
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		throw exception("App: Дата должна иметь вид: день.месяц.год!");
	}

	// дата платежа 
	DateTime date;

	// установка даты 
	date.setDate(day, month, year);

	// поиск и запись в файл найденного плательщика  
	listPayer_.searchByDate(date, nameFileResSearch_);

	// коллекция найденных объектов Payer 
	vector<Payer>payers;

	// чтение результата из файла 
	readPayerFile(payers, nameFileResSearch_);

	// вывод плательщика 
	cputs("\n     ——————————————————————————————— Найденные плательщики загруженные из файла ——————————————————————————————\n", MAGENTA_ON_BLACK);
	ListPayer::showElem(payers);

	// файл для сохранения 
	cout << color(LTYELLOW_ON_BLACK) << "\n\n     Файл для сохранения/загрузки: " << color(LTGREEN_ON_BLACK) << nameFileResSearch_ << endl;
}

// 7. Вычисления полной стоимости платежей всего списка
void App::sumPay()
{
	showNavBarMessage(hintColor, "  7. Вычисления полной стоимости платежей всего списка");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

	// ссылка на вектор списка 
	auto& payers = listPayer_.getPayers();

	cputs("\n\n     —————————————————————————————————— Подробная информация о плательщиках ——————————————————————————————————\n\n\n", LTMAGENTA_ON_BLACK);

	// вывод всех плательщиков и звонков
	for_each(payers.begin(), payers.end(), [](Payer payer) { ListPayer::showElem(vector<Payer> { payer }); payer.showBills(); cout << endl; });

	cputs("\n\n     —————————————————————————————————————————————————————————————————————————————————————————————————————————\n\n\n", LTMAGENTA_ON_BLACK);

	// вывод полной стоимости платежей всего списка 
	cout << color(LTYELLOW_ON_BLACK) << "\n\n\n     Полная стоимость всего списка: " 
		<< color(LTGREEN_ON_BLACK) << listPayer_.payAll() << color(mainColor);
}

// 8. Объединение списков
void App::mergeListPayers()
{
	showNavBarMessage(hintColor, "  8. Объединения списка");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

	// ссылка на вектор списка 
	auto payers = listPayer_.getPayers();

	// списки на основе вектора 
	list<Payer> listOne{ payers.begin(), payers.end() };
	list<Payer> listTwo{ payers.begin(), payers.end() };

	// размер вектора
	int size = (int)payers.size();

	// генерация итератора 
	auto genIt = [](list<Payer> list)
	{
		// индекс для элемента 
		int index = getRand(0, (int)list.size());
	
		// итератор 
		auto it = list.begin();
	
		// установка итератора
		for (int i = 0; i < index; i++)
			it++;
	
		return it;
	};

	// удаление случайных элементов из списков 
	for (int i = 0, n = size / 2; i < n; i++, size--)
	{
		// индекс для элемента 
		int indexOne = getRand(0, size - 1);
		int indexTwo = getRand(0, size - 1);

		// итератор 
		auto itOne = listOne.begin();
		auto itTwo = listTwo.begin();

		// установка итератора
		for (int i = 0; i < indexOne; i++)
			itOne++;
		// установка итератора
		for (int i = 0; i < indexTwo; i++)
			itTwo++;

		// удаление случайного элемента
		listOne.erase(itOne);
		listTwo.erase(itTwo);
	}

	// вывод списков 

	cputs("\n     ——————————————————————————————————————————————— Первый список ———————————————————————————————————————————————\n", MAGENTA_ON_BLACK);
	
	showElemPayerByList(listOne);
	
	cout << endl;
	
	cputs("\n     ——————————————————————————————————————————————— Второй список ———————————————————————————————————————————————\n", MAGENTA_ON_BLACK);
	
	showElemPayerByList(listTwo);
	
	cputs("\n     ————————————————————————————————————————— Списки после объединения ——————————————————————————————————————————\n", MAGENTA_ON_BLACK);
	
	// объединение списков
	listOne.splice(listOne.end(), listTwo);

	// сортировка списка 
	listOne.sort([](Payer& payerOne, Payer& payerTwo) { return payerOne.getPhoneNumber() > payerTwo.getPhoneNumber(); });

	// удаление дубликатов
	listOne.unique([](Payer& payerOne, Payer& payerTwo) { return payerOne.getPhoneNumber() == payerTwo.getPhoneNumber(); });

	// демонстрация списка 
	showElemPayerByList(listOne);

	cout << endl;
}

// вывод элементов 
void App::showElemPayerByList(list<Payer>& payers)
{
	Payer::showHead();

	// если в векторе нет элементов 
	if (payers.size() == 0)
		ListPayer::showEmpty();

	// индекс 
	int i = 1;

	// вывод элементов 
	for_each(payers.begin(), payers.end(), [i](Payer payer) mutable { payer.showPayer(i++); });

	Payer::showLine();
}

// 9. Пересечение списков
void App::crossListPayers()
{
	showNavBarMessage(hintColor, "  9. Пересечения списка");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

	// ссылка на вектор списка 
	auto payers = listPayer_.getPayers();

	// списки на основе вектора 
	list<Payer> listOne{ payers.begin(), payers.end() };
	list<Payer> listTwo{ payers.begin(), payers.end() };

	// предикатор для сортировки
	auto pred = [](Payer& payerOne, Payer& payerTwo) { return payerOne.getPhoneNumber() < payerTwo.getPhoneNumber(); };

	// сортировка списка 
	listOne.sort(pred);
	listTwo.sort(pred);

	// размер вектора
	int size = (int)payers.size();

	// генерация итератора 
	auto genIt = [](list<Payer> list)
	{
		// индекс для элемента 
		int index = getRand(0, (int)list.size());

		// итератор 
		auto it = list.begin();

		// установка итератора
		for (int i = 0; i < index; i++)
			it++;

		return it;
	};

	// удаление случайных элементов из списков 
	for (int i = 0, n = size / 2; i < n; i++, size--)
	{
		// индекс для элемента 
		int indexOne = getRand(0, size - 1);
		int indexTwo = getRand(0, size - 1);

		// итератор 
		auto itOne = listOne.begin();
		auto itTwo = listTwo.begin();

		// установка итератора
		for (int i = 0; i < indexOne; i++)
			itOne++;
		// установка итератора
		for (int i = 0; i < indexTwo; i++)
			itTwo++;

		// удаление случайного элемента
		listOne.erase(itOne);
		listTwo.erase(itTwo);
	}

	// вывод списков 

	cputs("\n     ——————————————————————————————————————————————— Первый список ———————————————————————————————————————————————\n", MAGENTA_ON_BLACK);

	showElemPayerByList(listOne);

	cout << endl;

	cputs("\n     ——————————————————————————————————————————————— Второй список ———————————————————————————————————————————————\n", MAGENTA_ON_BLACK);

	showElemPayerByList(listTwo);

	cputs("\n     ————————————————————————————————————————— Списки после пересечения ——————————————————————————————————————————\n", MAGENTA_ON_BLACK);

	// результирующий список
	list<Payer> result;

	// пересечение списков
	set_intersection(listOne.begin(), listOne.end(), listTwo.begin(), listTwo.end(), back_inserter(result), pred);

	// демонстрация списка 
	showElemPayerByList(result);

	cout << endl;
}

// 10. Отбор данных по дате платежа
void App::selectionPayerByDate()
{
	showNavBarMessage(hintColor, "  10. Отбор данных по дате платежа");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

#pragma region Ввод данных

	// день
	int day;

	// месяц
	int month;

	// года 
	int year;

	// ввод данных 
	setColor(LTYELLOW_ON_BLACK);
	cin.ignore(cin.rdbuf()->in_avail());
	showInputLine("\n\n     Введите дату платежа(день.месяц.год): ", 16, BLACK_ON_LTCYAN);
	cin >> day;
	cin.ignore(1, '.');
	cin >> month;
	cin.ignore(1, '.');
	cin >> year;

	setColor(mainColor);
	setCursorVisible(false);

	// если данные некорректны
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());

		throw exception("App: Дата должна иметь вид: день.месяц.год!");
	}

	// дата платежа 
	DateTime date(day, month, year, 0, 0, 0);

#pragma endregion 

	// вектор для отбора данных
	vector<Payer> result;

	// ссылка на вектор плательщиков списка
	auto payers = listPayer_.getPayers();

	// лямбда для выборки данных
	auto lambda = [&date, &result](Payer& payer) { if (payer.getDatePay().equalDate(date)) result.push_back(payer); };

	// выборка данных
	for_each(payers.begin(), payers.end(), lambda);

	cputs("\n     ———————————————————————————————————————————— Отобранные данные ——————————————————————————————————————————————\n", MAGENTA_ON_BLACK);

	// вывод результата
	ListPayer::showElem(result);
}

// 11. Отбор данных по номеру телефона
void App::selectionPayerByNumber()
{
	showNavBarMessage(hintColor, "  11. Отбор данных по номеру телефона");

	cout << "\n";

	// вывод списка 
	listPayer_.showTable();

#pragma region Ввод данных

	// номер 
	string number;

	// ввод данных
	setColor(LTYELLOW_ON_BLACK);
	cin.ignore(cin.rdbuf()->in_avail());
	showInputLine("\n\n     Введите номер телефона: ", Payer::N_PHONE_NUMBER + 2, BLACK_ON_LTCYAN);
	getline(cin, number);
	setColor(mainColor);
	setCursorVisible(false);

#pragma endregion 

	// вектор для отбора данных
	vector<Payer> result;

	// ссылка на вектор плательщиков списка
	auto payers = listPayer_.getPayers();

	// лямбда для выборки данных
	auto lambda = [&number, &result](Payer& payer) { if (payer.getPhoneNumber() == number) result.push_back(payer); };

	// выборка данных
	for_each(payers.begin(), payers.end(), lambda);

	cputs("\n     ———————————————————————————————————————————— Отобранные данные ——————————————————————————————————————————————\n", MAGENTA_ON_BLACK);

	// вывод результата
	ListPayer::showElem(result);
}

// 12. Сортировка по номеру телефона
void App::sortByNumber()
{
	showNavBarMessage(hintColor, "  12. Сортировка по номеру телефона");

	cout << "\n";

	// предикатор для сортировки
	auto pred = [](Payer& payerOne, Payer& payerTwo) {return payerOne.getPhoneNumber() > payerTwo.getPhoneNumber(); };

	// ссылка на вектор плательщиков списка
	auto& payers = listPayer_.getPayers();
	
	// сортировка 
	sort(payers.begin(), payers.end(), pred);

	// вывод списка 
	listPayer_.showTable();
}

// 13. Сортировка по убыванию суммы к оплате
void App::sortByPay()
{
	showNavBarMessage(hintColor, "  13. Сортировка по убыванию суммы к оплате");

	cout << "\n";

	// предикатор для сортировки
	auto pred = [](Payer& payerOne, Payer& payerTwo) {return payerOne.getSumPay() > payerTwo.getSumPay(); };

	// ссылка на вектор плательщиков списка
	auto& payers = listPayer_.getPayers();

	// сортировка 
	sort(payers.begin(), payers.end(), pred);

	// вывод списка 
	listPayer_.showTable();
}

// 14. Сортировка по убыванию времени разговоров
void App::sortByTime()
{
	showNavBarMessage(hintColor, "  14. Сортировка по убыванию времени разговоров");
	cout << "\n";

	// предикатор для сортировки
	auto pred = [](Payer& payerOne, Payer& payerTwo) {return payerOne.timeCall() > payerTwo.timeCall(); };

	// ссылка на вектор плательщиков списка
	auto& payers = listPayer_.getPayers();

	// сортировка 
	sort(payers.begin(), payers.end(), pred);

	// вывод списка 
	listPayer_.showTableTime();
}

#pragma endregion

#pragma region Общие методы

// проверка на открытие файла
bool App::checkFile(string fileName)
{
	// открытие файла в режиме чтения/записи
	fstream file(fileName, ios::in | ios::out);

	// проверка на открытие файла 
	bool isOpen = file.is_open();

	// закрытие файла 
	file.close();

	return isOpen;
}

// создание даты
DateTime App::genDateTime(int minDay, int maxDay, int minMonth, int maxMonth, int minYear, int maxYear,
	int minHour, int maxHour, int minMinute, int maxMinute, int minSecond, int maxSecond)
{
	return DateTime(getRand(minDay, maxDay), getRand(minMonth, maxMonth), getRand(minYear, maxYear),
		getRand(minHour, maxHour), getRand(minMinute, maxMinute), getRand(minSecond, maxSecond));
}

// создание даты 
DateTime App::genDate(DateTime dateTime, int minDay, int maxDay, int minMonth, int maxMonth, int minYear, int maxYear)
{
	dateTime.setDate(getRand(minDay, maxDay), getRand(minMonth, maxMonth), getRand(minYear, maxYear));

	return dateTime;
}

// создание даты 
DateTime App::genTime(DateTime dateTime, int minHour, int maxHour, int minMinute, int maxMinute, int minSecond, int maxSecond)
{
	dateTime.setDate(getRand(minHour, maxHour), getRand(minMinute, maxMinute), getRand(minSecond, maxSecond));

	return dateTime;
}

#pragma endregion
