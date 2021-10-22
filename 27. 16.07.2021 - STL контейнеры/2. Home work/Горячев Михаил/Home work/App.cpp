#include "App.h"

/*
 *	Задача 1. Дан текстовый файл с текстом на русском языке, слова разделяются только
 *	одним пробелом, переносов слов в тексте нет, знаков препинания нет. Для файла 
 *	реализуйте обработки:
 *		•	Выведите в консоль исходный файл, выделяя цветом четные строки
 *		•	В каждой строке замените второе слово на строку «+++ возможно +++», если в 
 *			строке одно слово, ничего не изменяйте 
 *		•	Из строк с четными номерами удалите последнее слово
 *		•	В начало строк с  нечетными номерами вставьте строку «это STL » 
 *	Задача 2. Разработайте консольное приложение для выполнения следующего задания. 
 *	Хранить данные при помощи класса vector<int>. Размер вектора от 8 до 15 элементов. 
 *	Создать вектор, заполнить его случайными числами и сохранить в бинарном файле при 
 *	помощи потока вывода. По командам меню читать данные в вектор из бинарного файла при
 *	помощи потока ввода, выполнять обработку вектора, выводить вектор в консоль до и после
 *	обработки. 
 *		•	Удалить из вектора все элементы, встречающиеся более двух раз
 *		•	Перед элементом вектора с индексом K вставить новый элемент с нулевым значением
 *		•	Вставить элемент с нулевым значением перед минимальным и после максимального 
 *			элемента массива
 *	Задача 3. C использованием класса Person, вектора, закрытого классом Person, списка, 
 *	закрытого типом Person, разработайте решение. Примените функциональные try-блоки в 
 *	конструкторах класса Person.
 *	Класс Personимеет поля:
 *		•	Табельный номер, целое число, уникальное в пределах приложения
 *		•	Фамилия и инициалы – поле класса string
 *		•	Город проживания – поле класса string
 *		•	Оклад, вещественное число
 *		•	Год поступления на работу
 *		•	Количество рабочих дней в месяце 
 *		•	Количество фактически отработанных дней в месяце
 *	Перегрузите операции сравнения объектов Person по табельному номеру 
 *	Создать вектор объектов типа Person–объект класса vector<Person>, заполнить его 
 *	некоторым набором начальных значений. Реализовать обработки вектора:
 *		•	в векторе найти первые записи с минимальным и максимальным окладом, поменять их
 *			местами, записать измененный вектор в бинарный файл people.bin
 *		•	записать в новый вектор всех жителей заданного с клавиатуры города, сохранить этот 
 *			вектор в бинарный файл названиеГорода.bin
 *		•	из вектора записать в дек deque<Person> всех персон, оклад которых принадлежит 
 *			заданному с клавиатуры диапазону значений. Добавлять записи в начало дека, сохранить 
 *			данные дека в бинарном файле salary.bin
*/

#pragma region Задание 1. Чтение файла

/*
 *	Задача 1. Дан текстовый файл с текстом на русском языке, слова разделяются только
 *	одним пробелом, переносов слов в тексте нет, знаков препинания нет. Для файла
 *	реализуйте обработки:
 *		•	Выведите в консоль исходный файл, выделяя цветом четные строки
 *		•	В каждой строке замените второе слово на строку «+++ возможно +++», если в
 *			строке одно слово, ничего не изменяйте
 *		•	Из строк с четными номерами удалите последнее слово
 *		•	В начало строк с нечетными номерами вставьте строку «это STL »
*/

// Задание 1. Чтение файла
void App::task1()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Вывод исходного файла с выделением чётных строк
		CMD_OUT_FILE,
		// Замена второго слова в каждой строке на «+++ возможно +++»
		CMD_REPLACE,
		// Удаление последнего слова с чётных строк
		CMD_CHANGE_EVEN,
		// Вставка в начало нечётных строк «это STL »
		CMD_CHANGE_ODD
	};

	// количество пунктов меню
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("Вывод исходного файла с выделением чётных строк", CMD_OUT_FILE),
		MenuItem("Замена второго слова в каждой строке на «+++ возможно +++»", CMD_REPLACE),
		MenuItem("Удаление последнего слова с чётных строк", CMD_CHANGE_EVEN),
		MenuItem("Вставка в начало нечётных строк «это STL »", CMD_CHANGE_ODD),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 1. Чтение файла", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Вывод исходного файла с выделением чётных строк
			case CMD_OUT_FILE:
				app.outFile();
				break;
				// Замена второго слова в каждой строке на «+++ возможно +++»
			case CMD_REPLACE:
				app.replace();
				break;
				// Удаление последнего слова с чётных строк
			case CMD_CHANGE_EVEN:
				app.changeEven();
				break;
				// Вставка в начало нечётных строк «это STL »
			case CMD_CHANGE_ODD:
				app.changeOdd();
				break;
			}
		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();
		} // try-catch
	}
}

// Вывод исходного файла с выделением чётных строк
void App::outFile()
{
	cls();

	showNavBarMessage(hintColor, "Вывод исходного файла с выделением чётных строк");

	cout << endl;

	// вывод файла с подсветкой чётных строк
	showColorOddEvenFile(taskOneFileName_);

	cout << "\n\n\n";

	getKey();
}

// вывод файла в цвете с подсветкой чётных строк
void App::showColorOddEvenFile(string nameFile)
{
	// вывод шапки "текстового редактора"
	showHead(nameFile);

	// открытие файла в режиме чтения 
	fstream file(nameFile, ios::in);

	// если файл не открылся 
	if (!file.is_open())
	{
		throw exception("  |                                               ОШИБКА ОТКРЫТИЯ ФАЙЛА                                             |\n"
			"  +—————+———————————————————————————————————————————————————————————————————————————————————————————————————————————+\n");
	}

	// буфер для строки
	string buf;

	int i = 1;

	// считывания файла в строку
	while (!file.eof())
	{
		// считывание содержимого строки в буфер
		getline(file, buf);

		// вывод строки для "текстового редактора"
		showString(buf, i++, (i & 1) == 1 ? WHITE_ON_BLACK : LTYELLOW_ON_BLACK);
	}
	// вывод разделительной линии для "текстового редактора"
	showLine();

	file.close();
}

// Замена второго слова в каждой строке на «+++ возможно +++»
void App::replace()
{
	cls();

	showNavBarMessage(hintColor, "Замена второго слова в каждой строке на «+++ возможно +++»");

	cout << endl;

	cputs("—————————————————————————————————————————————————— ФАЙЛ ДО ИЗМЕНЕНИЯ ——————————————————————————————————————————————————", YELLOW_ON_BLACK);

	// вывод файла до замены
	showFile(taskOneFileName_);

	// замена слов на строки
	replaceForFile(taskOneFileName_, "+++ возможно +++"s, 2, 1, 0);

	cputs("———————————————————————————————————————————————— ФАЙЛ ПОСЛЕ ИЗМЕНЕНИЯ —————————————————————————————————————————————————", YELLOW_ON_BLACK);

	// вывод файла после замены
	showFile(taskOneFileName_);

	cout << "\n\n\n";

	getKey();
}

// замена слова в строках на строку
// nWord - номер слова: -1 - вставка начало, 0 - вставка в конец и т.д
// nStr - кратность строк: -1 - нечётная, 0 - чётная, 1 - каждая, 2 - каждая вторая и и.д
// positioningWord - позиционирование отсчёта слова 0 - сначала, 2 - c конца
void App::replaceForFile(string nameFile, string insStr, int nWord, int nStr = 1, int positioningWord = 0)
{
	// открытие файла в режиме чтения
	ifstream ifs(nameFile.c_str());

	// имя вспомогательного файла 
	string tempName = "temp.txt";

	// вспомогательный файл
	ofstream ofs(tempName);

	// буфер для строки файла 
	string buf;

	// считывания файла в строку
	for (int i = 1; !ifs.eof(); i++)
	{
		// считывание содержимого строки в буфер
		getline(ifs, buf);

		// размер буфера
		size_t sizeBuf = buf.size();

		// если достигнут конец файла 
		// if (ifs.eof()) break;

		// buf += '\n';

		// изменение строки

		// проверка на кратность
		bool flag = nStr <= 0 ? false : (i % nStr) == 0;

		// проверка на кратность строки 
		//     проверка на нечётность    ||    проверка на чётность     || проверка на кратность
		while ((nStr == -1 && (i & 1) == 1) || (nStr == 0 && (i & 1) == 0) || flag)
		{
			// если вставка в начало строки
			if (nWord == -1)
			{
				buf.insert(0, insStr);

				break;
			}

			// если вставка в конец строки
			if (nWord == 0)
			{
				buf.append(insStr);

				break;
			}

			// позиции начала и конца слова
			size_t posStart;
			size_t posEnd;

			// если строка пуста 
			if (buf.size() == 0) break;

			// если с начала строки
			if (positioningWord == ios::beg)
			{
				posStart = 0;
				posEnd = 0;
				// если требуется заменить первое слово с начала строки
				if (nWord == 1)
				{
					posStart = 0;
					posEnd = buf.find(' ') - 1;

					// если не найден конец слова 
					if (posEnd == string::npos)
						posEnd = sizeBuf;
				}
				else
				{
					for (int i = 0; i < nWord; i++)
					{
						// позиция конца слова
						posEnd = buf.find(' ', posEnd + 1);
					}

					// если не найден конец слова 
					if (posEnd == string::npos)
						posEnd = sizeBuf;

					// позиция конца слова
					posStart = buf.rfind(' ', posEnd - 1) + 1;

					// если позиция не найдена 
					if (posStart == string::npos)
						break;

				}
			}

			// если с конца строки
			else
			{
				posStart = sizeBuf;
				posEnd = sizeBuf;
				// если требуется заменить первое слово с конца строки
				if (nWord == 1)
				{
					posStart = buf.rfind(' ', posStart) + 1;
					posEnd = sizeBuf;

					// если не найден конец слова 
					if (posStart == string::npos)
						posStart = 0;
				}
				else
				{
					for (int i = 0; i < nWord ; i++)
					{
						// позиция начала слова
						posStart = buf.rfind(' ', posStart - 1);

						// если позиция не найдена 
						if (posStart == string::npos)
							break;
					}

					posStart++;

					// позиция конца слова
					posEnd = buf.find(' ', posStart);

					// если позиция не найдена 
					if (posStart == string::npos)
						posStart = sizeBuf;
				}
			}

			// вставка строки
			buf.replace(posStart, posEnd - posStart, insStr);

			break;
		}

		// если это не последняя строка 
		ifs.peek();
		if (!ifs.eof())
			buf += '\n';

		// запись строки в вспомогательный файл
		ofs << buf.c_str();

		// отчистка буфера
		buf.erase();
	}

	// закрытие файлов 
	ifs.close();
	ofs.close();

	// удаление исходного файла 
	remove(nameFile.c_str());

	// переименование вспомогательного файла
	rename(tempName.c_str(), nameFile.c_str());
}

// Удаление последнего слова с чётных строк
void App::changeEven()
{
	cls();

	showNavBarMessage(hintColor, "Удаление последнего слова с чётных строк");

	cout << endl;

	cputs("—————————————————————————————————————————————————— ФАЙЛ ДО ИЗМЕНЕНИЯ ——————————————————————————————————————————————————", YELLOW_ON_BLACK);

	// вывод файла до замены
	showFile(taskOneFileName_);

	// удаление последнего слова с чётных строк
	replaceForFile(taskOneFileName_, ""s, 1, 0, ios::end);

	cputs("———————————————————————————————————————————————— ФАЙЛ ПОСЛЕ ИЗМЕНЕНИЯ —————————————————————————————————————————————————", YELLOW_ON_BLACK);

	// вывод файла после замены
	showFile(taskOneFileName_);

	cout << "\n\n\n";

	getKey();
}

// Вставка в начало нечётных строк «это STL »
void App::changeOdd()
{
	cls();

	showNavBarMessage(hintColor, "Вставка в начало нечётных строк «это STL »");

	cout << endl;

	cputs("—————————————————————————————————————————————————— ФАЙЛ ДО ИЗМЕНЕНИЯ ——————————————————————————————————————————————————", YELLOW_ON_BLACK);

	// вывод файла до замены
	showFile(taskOneFileName_);

	// вставка в начало нечётных строк
	replaceForFile(taskOneFileName_, "это STL "s, -1, -1, ios::beg);

	cputs("———————————————————————————————————————————————— ФАЙЛ ПОСЛЕ ИЗМЕНЕНИЯ —————————————————————————————————————————————————", YELLOW_ON_BLACK);

	// вывод файла после замены
	showFile(taskOneFileName_);

	cout << "\n\n\n";

	getKey();

}

// вывод файла 
void App::showFile(string nameFile)
{
	// вывод шапки "текстового редактора"
	showHead(nameFile);

	// открытие файла в режиме чтения 
	fstream file(nameFile, ios::in);

	// если файл не открылся 
	if (!file.is_open())
	{
		throw exception("  |                                               ОШИБКА ОТКРЫТИЯ ФАЙЛА                                             |\n"
			"  +—————+———————————————————————————————————————————————————————————————————————————————————————————————————————————+\n");
	}

	// буфер файла 
	string buf;

	int i = 1;

	// считывания файла в строку
	while (!file.eof())
	{
		// считывание содержимого строки в буфер
		getline(file, buf);

		// вывод строки для "текстового редактора"
		showString(buf, i++, WHITE_ON_BLACK);
	}

	// вывод разделительной линии для "текстового редактора"
	showLine();

	file.close();
}

// вывод шапки "текствого редактора"
void App::showHead(string fileName)
{
	cout << color(LTCYAN_ON_BLACK) << "  +——————————————————————————————————————————————————————————————————————————————————+——————————————————————————————+\n"
		<< "  | " << color(LTYELLOW_ON_BLACK) << "                                              Текстовый редактор         "
		<< color(LTGREEN_ON_BLACK) << " v 1.0 "
		<< color(LTCYAN_ON_BLACK) << " | " << color(WHITE_ON_BLACK) << "  Имя файла: "
		<< color(LTGREEN_ON_BLACK) << left << setw(15) << fileName << color(LTCYAN_ON_BLACK) << " |\n" << right
		<< "  +—————+————————————————————————————————————————————————————————————————————————————+——————————————————————————————+\n"
		<< "  |  " << color(WHITE_ON_BLACK) << "N" << color(LTCYAN_ON_BLACK) << "  | "
		<< color(LTYELLOW_ON_BLACK) << "                                         Содержание файла                                                "
		<< color(LTCYAN_ON_BLACK) << " |\n"
		<< "  +—————+———————————————————————————————————————————————————————————————————————————————————————————————————————————+\n"
		<< color(WHITE_ON_BLACK);

	// cout << "  +——————————————————————————————————————————————————————————————————————————————————+——————————————————————————————+\n"
	// 		<< "  |                                             Текстовый редактор v 1.0             |   Имя файла:                 |\n"
	// 		<< "  +—————+————————————————————————————————————————————————————————————————————————————+——————————————————————————————+\n"
	// 		<< "  |  N  |                                             Содержание файла                                              |\n"
	// 		<< "  +—————+———————————————————————————————————————————————————————————————————————————————————————————————————————————+\n"
}

// вывод линии-разделителя для "текстового редактора"
void App::showLine()
{
	cputs("  +—————+———————————————————————————————————————————————————————————————————————————————————————————————————————————+\n", LTCYAN_ON_BLACK);
}

// вывод строки файла для "текстового редактора"
// i - номер строки
void App::showString(string str, int i, short colorLine)
{
	cout << color(LTCYAN_ON_BLACK) << "  | " << color(LTBLACK_ON_BLACK) << setw(3) << i
		<< color(LTCYAN_ON_BLACK) << " | "
		<< color(colorLine) << left << setw(105) << str
		<< color(LTCYAN_ON_BLACK) << " |\n" << color(WHITE_ON_BLACK) << right;
}

#pragma endregion

#pragma region Задание 2. Вектор с числами

/*
 *	Задача 2. Разработайте консольное приложение для выполнения следующего задания.
 *	Хранить данные при помощи класса vector<int>. Размер вектора от 8 до 15 элементов.
 *	Создать вектор, заполнить его случайными числами и сохранить в бинарном файле при
 *	помощи потока вывода. По командам меню читать данные в вектор из бинарного файла при
 *	помощи потока ввода, выполнять обработку вектора, выводить вектор в консоль до и после
 *	обработки.
 *		•	Удалить из вектора все элементы, встречающиеся более двух раз
 *		•	Перед элементом вектора с индексом K вставить новый элемент с нулевым значением
 *		•	Вставить элемент с нулевым значением перед минимальным и после максимального
 *			элемента массива
*/

// Задание 2. Вектор с числами
void App::task2() 
{

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Удаление из вектора всех элементов, встречающихся более двух раз
		CMD_DELETE_ELEM,
		// Вставка нулевого элемента
		CMD_INSERT,
		// Вставка нулевого элемента перед минимальным и после максимального элемента
		CMD_INSERT_MIN_MAX
	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Удаление из вектора всех элементов, встречающихся более двух раз", CMD_DELETE_ELEM),
		MenuItem("Вставка нулевого элемента", CMD_INSERT),
		MenuItem("Вставка нулевого элемента перед минимальным и после максимального элемента", CMD_INSERT_MIN_MAX),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 2. Вектор с числами", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return ;

			switch (cmd)
			{
			// Удаление из вектора всех элементов, встречающихся более двух раз
			case CMD_DELETE_ELEM:
				app.deleteElem();
				break;
			// Вставка нулевого элемента
			case CMD_INSERT:
				app.insertBefore();
				break;
			// Вставка нулевого элемента перед минимальным и после максимального элемента
			case CMD_INSERT_MIN_MAX:
				app.insertMinMax();
				break;
			}
		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();
		} // try-catch
	}
}

// Удаление из вектора всех элементов, встречающихся более двух раз
void App::deleteElem()
{
	cls();

	showNavBarMessage(hintColor, "Удаление из вектора всех элементов, встречающихся более двух раз");

	// вывод вектора до удаления 
	showVector(vectorTaskThree_, "Вектор", "До удаления элементов", -1);

	cout << "\n\n";

	// удаление из вектора элеменов, которые всечаются больше двух раз по заданию
	deleteOverDouble(vectorTaskThree_);

	// вывод вектора после удаления 
	showVector(vectorTaskThree_, "Вектор", "После удаления элементов", -1);
	
	cout << "\n\n\n";

	getKey();
}

// удаление из вектора элеменов, которые всечаются больше двух раз по заданию
void App::deleteOverDouble(vector<int>& vec)
{
	for (int i = vec.size() - 1; i > 0; i--)
	{
		// количество вхождений 
		int countIn = 0;
		
		// поиск элемента
		for (int k = i - 1; k >= 0; k--)
		{
			// если найден дубликат
			if (vec[i] == vec[k])
			{
				// увлечение счётчика 
				countIn++;

				// если дубликат уже был найден
				if (countIn > 1)
				{
					// удаление элемента
					vec.erase(vec.begin() + i);

					break;
				}
			}
		}
	}
}

// Вставка нулевого элемента
void App::insertBefore()
{
	cls();

	showNavBarMessage(hintColor, "Вставка нулевого элемента по позиции");

	// вывод вектора до вставки
	showVector(vectorTaskThree_, "Вектор", "До вставки элемента", -1);

	cout << "\n\n";

	// позиция для вставки
	int posit = getRand(0, vectorTaskThree_.size() - 1);

	int add = 0;

	// вставка нулевого элемента по позиции 
	vectorTaskThree_.insert(vectorTaskThree_.begin() + posit, 1, add);

	// вывод вектора после удаления 
	showVector(vectorTaskThree_, "Вектор", "После вставки элемента", posit);

	// текущий цвет
	short cl = getColor();

	cout << color(YELLOW_ON_BLACK) << "Позиция для вставки: " << color(GREEN_ON_BLACK) << posit << color(cl);

	getKey();
}

// Вставка нулевого элемента перед минимальным и после максимального элемента
void App::insertMinMax()
{
	cls();

	showNavBarMessage(hintColor, "Вставка нулевого элемента перед минимальным и после максимального элемента");

	// вывод вектора до вставки
	showVector(vectorTaskThree_, "Вектор", "До вставки элементов", -1);

	cout << "\n\n";

	// позиция для вставки
	int posMin, posMax;

	int add = 0;

	// поиск индекса минимального элемента 
	searchMinForVector(vectorTaskThree_, posMin);

	// вставка нулевого элемента перед минимальным
	vectorTaskThree_.insert(vectorTaskThree_.begin() + posMin, 1, add);

	// поиск индекса максимального элемента 
	searchMaxForVector(vectorTaskThree_, posMax);

	// вставка нулевого элемента после максимальным
	vectorTaskThree_.insert(vectorTaskThree_.begin() + posMax + 1, 1, add);

	// вывод вектора после удаления 
	showVector(vectorTaskThree_, "Вектор", "После вставки элементов", -1);


	// текущий цвет
	short cl = getColor();

	cout << color(YELLOW_ON_BLACK) << "Позиция минимального: " << color(GREEN_ON_BLACK) << posMin << color(cl) << "\n"
		<< color(YELLOW_ON_BLACK) << "Позиция максимального: " << color(GREEN_ON_BLACK) << posMax << color(cl) << "\n\n\n";

	getKey();

}

// минимальный элемент 
void App::searchMinForVector(vector<int>& vec, int& min)
{
	// значение 
	int valMin;

	valMin = vec[0];

	min = 0;

	for (int i = 1; i < vec.size(); i++)
	{
		int value = vec[i];

		// поиск минимального
		if (valMin > value)
		{
			valMin = value;
			min = i;
		}
	}
}

// максимальный элемент 
void App::searchMaxForVector(vector<int>& vec, int& max)
{
	// значение 
	int valMax;

	valMax = vec[0];

	max = 0;

	for (int i = 1; i < vec.size(); i++)
	{
		int value = vec[i];

		// поиск максмального
		if (valMax < value)
		{
			valMax = value;
			max = i;
		}
	}
}

// вывод вектора в таблице
void App::showVector(vector<int>& vec, string dataName, string description, int colorElem = -1)
{
	cout << endl;

	// вывод шапки таблицы
	showHead(vec, dataName, description);

	// если вектор пуст
	if (vec.size() == 0)
		showEmpty();

	// вывод элементов в таблицу
	showElem(vec, colorElem);

	cout << endl;
}

// вывод шапки таблицы
void App::showHead(vector<int>& vec, string& dataName, string& description)
{
	// текущий цвет
	short cl = getColor();

	cout << "\n" // 12, 34, 34
		<< "    +——————————————+———————————————————————————————————+———————————————————————————————————+\n"
		<< "    | Размер: "  << right << color(YELLOW_ON_BLACK) << setw(4) << vec.size() << color(cl) << left
		<< " | Данные: " << color(YELLOW_ON_BLACK) << setw(25) << dataName << color(cl)
		<< " | Описание: " << color(YELLOW_ON_BLACK) << setw(24) << description << color(cl) << right << "|\n";
		
	showLineVec();
}

// вывод элементов таблицы
void App::showElem(vector<int>& vec, int colorElem)
{
	// максимлальная длина вектора 
	int const MAX_SIZE = 12;

	// текущий цвет 
	short cl = getColor();

	// вывод индекса 
	cout << "    |    Индекс    | ";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		// требуемый для подствекти индекс элемента  
		if (i == colorElem)
		{
			cout << color(LTBLACK_ON_BLACK) << setw(3) << i << color(cl) << " | ";
		}

		// если индекс входит в максимальный индекс вектора 
		else if (i < vec.size())
		{ 
			cout << color(YELLOW_ON_BLACK) << setw(3) << i << color(cl) << " | ";
		}
		else
			cout << "    | ";
	}

	cout << endl;

	showLineVec();

	// вывод значения
	cout << "    |   Значение   | ";
	for (int i = 0; i < MAX_SIZE; i++)
	{
		// требуемый для подствекти элемент 
		if (i == colorElem)
		{
			cout << color(LTGREEN_ON_BLACK) << setw(3) << vec[i] << color(cl) << " | ";
		}

		// если индекс входит в максимальный индекс вектора 
		else if (i < vec.size())
		{
			cout << color(GREEN_ON_BLACK) << setw(3) << vec[i] << color(cl) << " | ";
		}
		else
			cout << "    | ";
	}

	cout << endl;

	showLineVec();
}

// вывод линии-разделителя таблицы
void App::showLineVec()
{
	cout << "    +——————————————+—————+—————+—————+—————+—————+—————+—————+—————+—————+—————+—————+—————+\n";
}

// вывод сообщения об отсутствии данных для таблицы
void App::showEmpty()
{
	// текущий цвет 
	short cl = getColor();
	cout << "    |   " << color(RED_ON_BLACK) 
		 << "                                          НЕТ ДАННЫХ                           "
		 << color (cl) << "      |\n";
}

#pragma endregion

#pragma region Задание 3. Список рабочих

/*
 *	Задача 3. C использованием класса Person, вектора, закрытого классом Person, списка,
 *	закрытого типом Person, разработайте решение. Примените функциональные try-блоки в
 *	конструкторах класса Person.
 *	Класс Personимеет поля:
 *		•	Табельный номер, целое число, уникальное в пределах приложения
 *		•	Фамилия и инициалы – поле класса string
 *		•	Город проживания – поле класса string
 *		•	Оклад, вещественное число
 *		•	Год поступления на работу
 *		•	Количество рабочих дней в месяце
 *		•	Количество фактически отработанных дней в месяце
 *	Перегрузите операции сравнения объектов Person по табельному номеру
 *	Создать вектор объектов типа Person–объект класса vector<Person>, заполнить его
 *	некоторым набором начальных значений. Реализовать обработки вектора:
 *		•	в векторе найти первые записи с минимальным и максимальным окладом, поменять их
 *			местами, записать измененный вектор в бинарный файл people.bin
 *		•	записать в новый вектор всех жителей заданного с клавиатуры города, сохранить этот
 *			вектор в бинарный файл названиеГорода.bin
 *		•	из вектора записать в дек deque<Person> всех персон, оклад которых принадлежит
 *			заданному с клавиатуры диапазону значений. Добавлять записи в начало дека, сохранить
 *			данные дека в бинарном файле salary.bin
*/

// Задание 3. Список рабочих
void App::task3()
{
	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Заполнение списка рабочих данными
		CMD_FILL_VECTOR,
		// Вывод данных о рабочих
		CMD_PRINT_VECTOR,
		// Обмен местами записей с максимальным и минимальным окладами
		CMD_SWAP_BY_SALERY,
		// Копирование записей в новый вектор и сохранение его в файл по городу
		CMD_COPY_BY_CITY,
		// Копирование в очередь записей по диапазону окладов
		CMD_COPY_BY_SALARY,
		// Сохранение данных в бинарный файл
		CMD_SAVE_BIN,
		// Загрузка данных из бианарного файла
		CMD_LOADING_BIN,
	};

	// количество пунктов меню
	const int N_MENU = 8;

	MenuItem items[N_MENU] = {
		MenuItem("Заполнение списка рабочих данными", CMD_FILL_VECTOR),
		MenuItem("Вывод данных о рабочих", CMD_PRINT_VECTOR),
		MenuItem("Обмен местами записей с максимальным и минимальным окладами", CMD_SWAP_BY_SALERY),
		MenuItem("Копирование записей в новый вектор и сохранение его в файл по городу", CMD_COPY_BY_CITY),
		MenuItem("Копирование в очередь записей по диапазону окладов", CMD_COPY_BY_SALARY),
		MenuItem("Сохранение данных в бинарный файл", CMD_SAVE_BIN),
		MenuItem("Загрузка данных из бианарного файла", CMD_LOADING_BIN),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 3. Список рабочих", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
			// Заполнение списка рабочих данными
			case CMD_FILL_VECTOR:
				app.fillVector();
				break;
				// Вывод данных о рабочих
			case CMD_PRINT_VECTOR:
				app.printVector();
				break;
			// Обмен местами записей с максимальным и минимальным окладами
			case CMD_SWAP_BY_SALERY:
				app.swapBySalery();
				break;
			// Копирование записей в новый вектор и сохранение его в файл по городу
			case CMD_COPY_BY_CITY:
				app.saveByCity();
				break;
			// Копирование в очередь записей по диапазону окладов
			case CMD_COPY_BY_SALARY:
				app.saveBySalary();
				break;
			// Сохранение данных в бинарный файл
			case CMD_SAVE_BIN:
				app.saveBin();
				break;
			// Загрузка данных из бианарного файла
			case CMD_LOADING_BIN:
				app.loadBin();
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

// Заполнение списка рабочих данными
void App::fillVector()
{
	cls();

	showNavBarMessage(hintColor, "Заполнение списка рабочих");

	cputs("\n———————————————————————————————————————————————— ДВУСВЯЗНЫЙ СПИСОК ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(persons_);

	// заполнение дека данными
	addAllPerson(personsByVector_, SIZE_FILL_ARR, persons_);

	cputs("\n————————————————————————————————————————————————— ПОСЛЕ ЗАПОЛНЕНИЯ ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(persons_);

	getKey();
}

// добавление одного элемента в вектор
void App::addPerson(Person& person, vector<Person>& persons)
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
	persons.push_back(person);
}

// добавление номера в базу номеров
bool App::registrationNumber(unsigned int number)
{
	// если в базе уже есть такой номер
	if (numberFind(numberBase_, number))
		return false;

	// добавление в базу
	numberBase_.push_back(number);

	return true;
}

// поиск по номеру Person в векторе 
bool App::numberFind(vector<unsigned int>& numberBase, unsigned int number)
{
	for (unsigned int num : numberBase)
	{
		// если номер совпадает 
		if (num == number)
			return true;
	}

	return false;
}

// добавление массива элементов в вектор
void App::addAllPerson(Person* data, int n, vector<Person>& persons)
{
	for (int i = 0; i < n; i++)
	{
		addPerson(data[i], persons);
	}
}

// Вывод вектора
void App::printVector()
{
	cls();

	showNavBarMessage(hintColor, "Вывод вектора");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод дерева
	showPerson(persons_);

	cout << "\n\n\n";

	getKey();
}

// вывод вектора в виде таблицы
void App::showPerson(vector<Person>& persons)
{
	// текущий цвет
	short cl = getColor();

	// шапка таблицы
	Person::showHead();

	// если в списке нет данных
	if (persons.size() == 0)
	{
		Person::showEmpty();
		return;
	}

	int i = 1;

	// вывод элементов
	for (auto person : persons)
	{
		person.showElem(i++);
	}

	// вывод подвала таблицы
	Person::showLine();

	cout << " |                                                                           | "
		<< color(YELLOW_ON_BLACK) << "СУММА НАЧИСЛЕНИЙ:      " << color(cl) << " | "
		<< setw(12) << accruedAll(persons) << " |\n"
		<< " +———————————————————————————————————————————————————————————————————————————+—————————————————————————+——————————————+\n";
}

// сумма начислений по двусвязному списку
double App::accruedAll(vector<Person> persons)
{
	double summ = 0.;

	// подсчёт суммы
	for (auto person : persons)
	{
		summ += person.accrued();
	}

	return summ;
}

// Сохранение вектора в бинарный файл
void App::saveBin()
{
	cls();

	showNavBarMessage(hintColor, "Сохранение вектора в бинарный файл");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(persons_);

	// текущий цвет 
	short cl = getColor();

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << taskThreeFileName_
		<< color(cl) << "\n\n";

	// создание и открытие файла в режиме записи
	ofstream file(taskThreeFileName_, ios::binary | ios::out);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << taskThreeFileName_ << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// запись вектора в файл
	for (auto person: persons_)
	{
		person.write(file);
	}

	// закрытие файла 
	file.close();

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	getKey();

}

// Тихое сохранение вектора в бинарный файл
void App::silentSaveBin(vector<Person>& persons, string fileName)
{
	// создание и открытие файла в режиме записи
	ofstream file(fileName, ios::binary | ios::out);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << fileName << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// запись двусвязного списка в файл
	for (auto person: persons)
	{
		person.write(file);
	}

	// закрытие файла 
	file.close();
}

// Загрузка данных из бинарного файла в вектора
void App::loadBin()
{
	cls();

	showNavBarMessage(hintColor, "Загрузка данных из бинарного файла в двусвязный список");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// отчистка списка 
	persons_.clear();

	// вывод списка 
	showPerson(persons_);

	// текущий цвет 
	short cl = getColor();

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для загрузки: " << color(GREEN_ON_BLACK) << taskThreeFileName_
		<< color(cl) << "\n\n";

	// создание и открытие файла в режиме чтения
	ifstream file(taskThreeFileName_, ios::binary | ios::in);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << taskThreeFileName_ << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// буфер 
	Person temp;

	// считвание файла в двусвязный список 
	while (true)
	{
		// считвание данных в буфер
		temp.read(file);

		// если достигнут конец файла 
		if (file.eof()) break;

		// заполнение списка объектом Person из буфера 
		persons_.push_back(temp);
	}

	// закрытие файла 
	file.close();

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tЗагрузка завершена\n\n" << color(cl);

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(persons_);

	getKey();

}

// Загрузка данных из бинарного файла в вектора
void App::silentLoadBin(vector<Person>& persons, string fileName)
{
	// отчистка списка 
	persons.clear();

	// текущий цвет 
	short cl = getColor();

	// создание и открытие файла в режиме чтения
	ifstream file(fileName, ios::binary | ios::in);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << fileName << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// буфер 
	Person temp;

	// считвание файла в вектор
	while (true)
	{
		// считвание данных в буфер
		temp.read(file);

		// если достигнут конец файла 
		if (file.eof()) break;

		// заполнение списка объектом Person из буфера 
		persons.push_back(temp);
	}

	// закрытие файла 
	file.close();
}

// Поменять местами записи с минимальным и максимальным окладом
void App::swapBySalery()
{
	cls();

	showNavBarMessage(hintColor, "Поменять местами записи с минимальным и максимальным окладом");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(persons_);

	cputs("\n————————————————————————————————————————————————— ПОСЛЕ ПЕРЕМЕЩЕНИЯ ——————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// позиции в файле с максимальным и минимальным окладами
	int max, min;

	max = min = -1;

	if (persons_.size() > 0)
	{
		searchSaleryMinMax(persons_, min, max);

		// обмен позициями в векторе 
		swap(persons_[min], persons_[max]);
	}
	// имя файла для сохранения измененного вектора
	string resNameFile("people.bin");

	// сохранение вектора в файл
	silentSaveBin(persons_, resNameFile);

	// текущий цвет 
	short cl = getColor();

	// загрузка из бинарного файла
	silentLoadBin(persons_, resNameFile);

	// вывод данных
	showPerson(persons_);

	cout << color(YELLOW_ON_BLACK) << "\n\n\tНомер по списку работника с максимальным окладом: "
		<< color(GREEN_ON_BLACK) << max + 1
		<< color(YELLOW_ON_BLACK) << "\n\tНомер по списку работника с минимальным окладом: "
		<< color(GREEN_ON_BLACK) << min + 1 << color(cl) << endl;

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << resNameFile
		<< color(cl) << "\n\n";

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	getKey();
}

// поиск позиции в векторе с минимальным и максимальным окладами
void App::searchSaleryMinMax(vector<Person>& persons, int& imin, int& imax)
{
	// максимальное значение оклада
	double maxVal = 0.;

	// минимальное значение оклада
	double minVal = DBL_MAX;

	// индекс 
	int i = 0;

	// считывание и проверка файла 
	for (auto person: persons)
	{
		// значение оклада 
		double val = person.getSalary();

		// если текущий максимум меньше теукщего значения оклада
		if (maxVal < val)
		{
			maxVal = val;
			imax = i;
		}

		// если текущий максимум меньше теукщего значения оклада
		if (minVal > val)
		{
			minVal = val;
			imin = i;
		}

		i++;
	}
}

// Запись в бинарный файл записей одного города
void App::saveByCity()
{
	cls();

	showNavBarMessage(hintColor, "Запись в бинарный файл записей одного города");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// загрузка данных из бинарного файла для демонстрации
	silentLoadBin(persons_, taskThreeFileName_);

	// вывод данных
	showPerson(persons_);

	// город
	string city;

	// включение курсора
	setCursorVisible(true);

	// текущий цвет
	short cl = getColor();

	// ввод города 
	showInputLine("Введите название города: ", 20, hintColor);
	getline(cin, city);

	// выключение курсора
	setCursorVisible(false);

	// возвращение цвета
	setColor(cl);

	cout << "\n";

	// название файла для сохранения
	string cityNameFile = city + ".bat";

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << cityNameFile
		<< color(cl) << "\n\n";

	// поиск запись в отдельный файл работников по городу 
	writeByCity(persons_, cityNameFile, city);

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	cputs("\n———————————————————————————————————————————————————— СОХРАНЁННЫЕ —————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вектор для демонстрации результата
	vector<Person> result;

	// загрузка файла из бинарного файла для демонстрации
	silentLoadBin(result, cityNameFile);

	// вывод списка 
	showPerson(result);

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для загрузки: " << color(GREEN_ON_BLACK) << cityNameFile
		<< color(cl) << "\n\n";

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tЗагрузка завершена\n\n" << color(cl);

	getKey();
}

// поиск и запись в отдельный файл работников по городу 
void App::writeByCity(vector<Person>& persons, string destFile, string city)
{
	// создание и открытие файла в режиме записи
	fstream dest(destFile, ios::binary | ios::out);

	// если файл открыт неуспешно
	if (!dest.is_open())
	{
		stringstream os;

		os << "Файл " << destFile << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// сохранение по городу и вывод
	for(auto person: persons)
	{

		// если название города совпадает 
		if (person.getCity() == city)
		{
			// сохранение в файл
			person.write(dest);
		}
	}

	// закрытие результирующего файла  
	dest.close();
}

// Копирование в очередь записей по диапазону окладов
void App::saveBySalary()
{
	cls();

	showNavBarMessage(hintColor, "Копирование в очередь записей по диапазону окладов");

	cputs("\n—————————————————————————————————————————————————————— ОЧЕРЕДЬ ———————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// загрузка данных из бинарного файла для демонстрации
	silentLoadBin(persons_, taskThreeFileName_);

	// вывод данных
	showPerson(persons_);

	// диапазон зарплаты
	double sMin, sMax;

	// включение курсора
	setCursorVisible(true);

	// текущий цвет
	short cl = getColor();

	// ввод города 
	showInputLine("Введите диапазон зарплат (min/max): ", 20, hintColor);
	cin >> sMin >> sMax;

	// если введены некорректные значения 
	if (cin.fail())
		throw exception("App: некорректные значения!");

	// выключение курсора
	setCursorVisible(false);

	// возвращение цвета
	setColor(cl);

	cout << "\n";

	// название файла для сохранения
	string resFileName("salary.bin");

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << resFileName
		<< color(cl) << "\n\n";

	// результирующий дек
	deque<Person> res;

	// поиск и запись в отдельный файл работников по окладу
	writeBySalary(persons_, res, resFileName, sMin, sMax);

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	cputs("\n———————————————————————————————————————————————————— СОХРАНЁННЫЕ —————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вектор для демонстрации результата
	deque<Person> result;

	// загрузка файла из бинарного файла для демонстрации
	loadBinDeq(result, resFileName);

	// вывод данных 
	showPerson(result);

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для загрузки: " << color(GREEN_ON_BLACK) << resFileName
		<< color(cl) << "\n\n";

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tЗагрузка завершена\n\n" << color(cl);

	getKey();
}

// поиск и запись в отдельный файл работников по окладу 
void App::writeBySalary(vector<Person>& persons, deque<Person>& deq, string destFile, double sMin, double sMax)
{
	// сохранение в дек по окладу
	for (auto person: persons)
	{
		// текущий оклад
		double salary = person.getSalary();

		// если название города совпадает 
		if (salary >= sMin and salary <= sMax)
		{
			// сохранение в дек
			deq.push_front(person);
		}
	}

	// создание и открытие файла в режиме записи
	fstream dest(destFile, ios::binary | ios::out);

	// если файл открыт неуспешно
	if (!dest.is_open())
	{
		stringstream os;

		os << "Файл " << destFile << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// сохранение дека в файл
	for (auto person: deq)
	{
		person.write(dest);
	}

	// закрытие результирующего файла
	dest.close();
}

// загрузка в очередь из файла 
void App::loadBinDeq(deque<Person>& persons, string fileName)
{
	// отчистка очереди
	persons.clear();

	// текущий цвет 
	short cl = getColor();

	// создание и открытие файла в режиме чтения
	ifstream file(fileName, ios::binary | ios::in);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << fileName << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// буфер 
	Person temp;

	// считвание файла в двусвязный список 
	while (true)
	{
		// считвание данных в буфер
		temp.read(file);

		// если достигнут конец файла 
		if (file.eof()) break;

		// заполнение списка объектом Person из буфера 
		persons.push_back(temp);
	}

	// закрытие файла 
	file.close();
}

// вывод списка в виде таблицы
void App::showPerson(deque<Person>& persons)
{
	// текущий цвет
	short cl = getColor();

	// шапка таблицы
	Person::showHead();

	// если в списке нет данных
	if (persons.size() == 0)
	{
		Person::showEmpty();
		return;
	}

	int i = 1;

	// вывод элементов
	for (auto person : persons)
	{
		person.showElem(i);
	}

	// вывод подвала таблицы
	Person::showLine();

	cout << " |                                                                           | "
		<< color(YELLOW_ON_BLACK) << "СУММА НАЧИСЛЕНИЙ:      " << color(cl) << " | "
		<< setw(12) << accruedAll(persons) << " |\n"
		<< " +———————————————————————————————————————————————————————————————————————————+—————————————————————————+——————————————+\n";
}

// сумма начислений по двусвязному списку
double App::accruedAll(deque<Person>& persons)
{
	double summ = 0.;

	// подсчёт суммы
	for (auto person : persons)
	{
		summ += person.accrued();
	}

	return summ;
}

#pragma endregion