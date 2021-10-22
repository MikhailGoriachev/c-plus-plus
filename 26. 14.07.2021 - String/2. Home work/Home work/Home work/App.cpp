#include "App.h"

/*
 * Задача 1. Продолжение задания на 14.07.2021 – с использованием класса Person,
 * двусвязного списка(класс DblList<Person>)объектов класса Person.Примените 
 * функциональные try - блоки в конструкторах класса Person.
 * 
 * Класс Personи меет поля(модификация класса предыдущего задания, добавлено
 * поле, используются строки в стиле C++ т.е.класс string) :
 * 	•	Табельный номер, целое число, уникальное в пределах приложения
 * 	•	Фамилия и инициалы – поле класса string
 * 	•	Город проживания – поле классаstring
 * 	•	Оклад, вещественное число
 * 	•	Год поступления на работу
 * 	•	Количество рабочих дней в месяце
 * 	•	Количество фактически отработанных дней в месяце
 * 	Реализовать обработки бинарного файла :
 * •	найти первые записи с минимальным и максимальным окладом, поменять их местами
 * •	прочитать данные о персонах в двусвязный список, записать в новый бинарный 
 *		файл всех жителей города, название которого введено с клавиатуры
 * 
 * Задача 2. Дан текстовый файл с текстом русском языке, слова разделяются только одним
 * пробелом, переносов слов в тексте нет.Для файла реализуйте обработки :
 * •	Выведите в консоль исходный файл, выделяя цветом строки с нечетным количеством слов.
 * •	В каждой четной строке файла в начало строки вставьте строку «ух ты », в каждой 
 *		нечетной строке замените последнее слово(т.е.после последнего пробела) строкой 
 *		«именно так и будет»
 * •	Из первой и последней строк файла удалите первое и последнее слова соответственно(т.е.
 *		символы первой строки до первого пробела и символы последней строки после последнего 
 *		пробела)
*/


#pragma region Задание 1. Список рабочих

/*
* Задача 1. Продолжение задания на 14.07.2021 – с использованием класса Person,
* двусвязного списка(класс DblList<Person>)объектов класса Person.Примените
* функциональные try - блоки в конструкторах класса Person.
*
*Класс Personи меет поля(модификация класса предыдущего задания, добавлено
* поле, используются строки в стиле C++ т.е.класс string) :
*	 •	Табельный номер, целое число, уникальное в пределах приложения
*	 •	Фамилия и инициалы – поле класса string
*	 •	Город проживания – поле классаstring
*	 •	Оклад, вещественное число
*	 •	Год поступления на работу
*	 •	Количество рабочих дней в месяце
*	 •	Количество фактически отработанных дней в месяце
* Реализовать обработки бинарного файла :
*	 •	найти первые записи с минимальным и максимальным окладом, поменять их местами
*	 •	прочитать данные о персонах в двусвязный список, записать в новый бинарный
*		файл всех жителей города, название которого введено с клавиатуры
*/

// Задание 1. Список рабочих
void App::task1()
{
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
		// Сохранение двусвязного список в текстовый файл
		CMD_SAVE_TEXT,
		// Загрузка данных из текстового файла в двусвязный список
		CMD_LOADING_TEXT,
		// Сохранение двусвязного список в бинарный файл
		CMD_SAVE_BIN,
		// Загрузка данных из бинарного файла в двусвязный список
		CMD_LOADING_BIN,
		// Поменять местами записи с минимальным и максимальным окладом
		CMD_SWAP_PERSON,
		// Запись в бинарный файл записей одного города
		CMD_SAVE_BY_CITY
	};

	// количество пунктов меню
	const int N_MENU = 11;

	MenuItem items[N_MENU] = {
		MenuItem("Заполнение списка рабочих", CMD_FILL),
		MenuItem("Генерация исключений при добавлении в список", CMD_ADD_EX),
		MenuItem("Генерация исключений при создании объекта", CMD_CREATE_EX),
		MenuItem("Вывод двусвязого списка", CMD_PRINT_LIST),
		MenuItem("Сохранение двусвязного список в текстовый файл", CMD_SAVE_TEXT),
		MenuItem("Загрузка данных из текстового файла в двусвязный список", CMD_LOADING_TEXT),
		MenuItem("Сохранение двусвязного список в бинарный файл", CMD_SAVE_BIN),
		MenuItem("Загрузка данных из бинарного файла в двусвязный список", CMD_LOADING_BIN),
		MenuItem("Поменять местами записи с минимальным и максимальным окладом", CMD_SWAP_PERSON),
		MenuItem("Запись в бинарный файл записей одного города", CMD_SAVE_BY_CITY),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задание 1. Список рабочих", items, N_MENU, palette, COORD{ 5, 5 });

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
				// Сохранение двусвязного список в текстовый файл
			case CMD_SAVE_TEXT:
				app.saveText();
				break;
				// Загрузка данных из текстового файла в двусвязный список
			case CMD_LOADING_TEXT:
				app.loadText();
				break;
				// Сохранение двусвязного список в бинарный файл
			case CMD_SAVE_BIN:
				app.saveBin();
				break;
				// Загрузка данных из бинарного файла в двусвязный список
			case CMD_LOADING_BIN:
				app.loadBin();
				break;
				// Поменять местами записи с минимальным и максимальным окладом
			case CMD_SWAP_PERSON:
				app.swapBySalery();
				break;
				// Запись в бинарный файл записей одного города
			case CMD_SAVE_BY_CITY:
				app.saveByCity();
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

	// заполнение двусвязного списка 
	addAllPerson(personsByList_, SIZE_FILL_ARR, list_);

	cputs("\n————————————————————————————————————————————————— ПОСЛЕ ЗАПОЛНЕНИЯ ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	cputs("\n———————————————————————————————————————————————— ДВУСВЯЗНЫЙ СПИСОК ———————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

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

	Person exPers = Person(654878, "Кононов  Т.Д", "Одесса", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15));

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

	Person(751742, "Ершов А.К", "Днепропетровск", 10'000., 2004, 15, 18);

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

// добавление массива элементов в список
void App::addAllPerson(Person* data, int n, DblList<Person> list)
{
	for (int i = 0; i < n; i++)
	{
		addPerson(data[i], list);
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

	cout<< " |                                                                           | " 
		<< color(YELLOW_ON_BLACK) << "СУММА НАЧИСЛЕНИЙ:      " << color(cl) << " | "
		<< setw(12) << accruedAll(list_) << " |\n"
		<< " +———————————————————————————————————————————————————————————————————————————+—————————————————————————+——————————————+\n";
}

// Сохранение двусвязного списка в текстовый файл
void App::saveText()
{
	cls();

	showNavBarMessage(hintColor, "Сохранение двусвязного список в текстовый файл");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

	// текущий цвет 
	short cl = getColor();

	// название файла 
	const char* name = "saveText.txt";

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << name
		<< color(cl) << "\n\n";

	// создание и открытие файла в режиме записи
	ofstream file(name, ios::beg);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << name << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}
	
	// итератор двусвязного списка
	DblList<Person>::Iterator<Person> iterator(list_);

	// запись двусвязного списка в файл
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		file << (*iterator);
	}

	// закрытие файла 
	file.close();

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	getKey();
}

// Загрузка данных из текстового файла в двусвязный список
void App::loadText()
{
	cls();

	showNavBarMessage(hintColor, "Загрузка данных из текстового файла в двусвязный список");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// отчистка списка 
	list_.clear();

	// вывод списка 
	showPerson(list_);

	// текущий цвет 
	short cl = getColor();

	// название файла 
	const char* name = "saveText.txt";

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << name
		<< color(cl) << "\n\n";

	// создание и открытие файла в режиме чтения
	ifstream file(name, ios::in);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << name << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// буфер 
	Person temp;

	// считвание файла в двусвязный список 
	while (true)
	{
		// считвание данных в буфер
		temp.readText(file);

		// если достигнут конец файла 
		if (file.eof()) break;

		// заполнение списка объектом Person из буфера 
		list_.add(temp);
	}

	// закрытие файла 
	file.close();

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tЗагрузка завершена\n\n" << color(cl);

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

	getKey();

}

// Сохранение двусвязного список в бинарный файл
void App::saveBin()
{
	cls();

	showNavBarMessage(hintColor, "Сохранение двусвязного список в бинарный файл");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

	// текущий цвет 
	short cl = getColor();

	// название файла 
	const char* name = "saveBin.bat";

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << name
		<< color(cl) << "\n\n";

	// создание и открытие файла в режиме записи
	ofstream file(name, ios::binary | ios::out);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << name << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// итератор двусвязного списка
	DblList<Person>::Iterator<Person> iterator(list_);

	// запись двусвязного списка в файл
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		(*iterator).write(file);
	}

	// закрытие файла 
	file.close();

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	getKey();

}

// Тихое сохранение двусвязного списка в бинарный файл
void App::silentSaveBin(DblList<Person>& list)
{
	// название файла 
	const char* name = "saveBin.bat";

	// создание и открытие файла в режиме записи
	ofstream file(name, ios::binary | ios::out);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << name << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// итератор двусвязного списка
	DblList<Person>::Iterator<Person> iterator(list);

	// запись двусвязного списка в файл
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		(*iterator).write(file);
	}

	// закрытие файла 
	file.close();
}

// Загрузка данных из бинарного файла в двусвязный список
void App::loadBin()
{
	cls();

	showNavBarMessage(hintColor, "Загрузка данных из бинарного файла в двусвязный список");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// отчистка списка 
	list_.clear();

	// вывод списка 
	showPerson(list_);

	// текущий цвет 
	short cl = getColor();

	// название файла 
	const char* name = "saveBin.bat";

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для загрузки: " << color(GREEN_ON_BLACK) << name
		<< color(cl) << "\n\n";

	// создание и открытие файла в режиме чтения
	ifstream file(name, ios::binary | ios::in);

	// если файл открыт неуспешно
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << name << " открыт неуспешно!";

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
		list_.add(temp);
	}

	// закрытие файла 
	file.close();

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tЗагрузка завершена\n\n" << color(cl);

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод списка 
	showPerson(list_);

	getKey();

}

// Загрузка данных из бинарного файла в двусвязный список
void App::silentLoadBin(DblList<Person>& list, string fileName)
{
	// отчистка списка 
	list.clear();

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
		list.add(temp);
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

	// название файла 
	string name = "saveBin.bat";

	// загрузка файла из бинарного файла для демонстрации
	silentLoadBin(list_, name);

	// вывод списка 
	showPerson(list_);

	cputs("\n————————————————————————————————————————————————— ПОСЛЕ ПЕРЕМЕЩЕНИЯ ——————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// открытие файла для чтения и записи
	fstream file(name, ios::binary | ios::in | ios::out);

	// если файл открыт неудачно 
	if (!file.is_open())
	{
		stringstream os;

		os << "Файл " << name << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// позиции в файле с максимальным и минимальным окладами
	size_t max, min;
	searchSaleryMinMax(file, min, max);

	// размер Person
	int sizePerson = Person::RECORD_SIZE;

	// перемещение 
	swapForFile(file, max, min, sizePerson, sizePerson);

	// сохранение файла 
	file.close();

	// текущий цвет 
	short cl = getColor();


	// загрузка из бинарного файла
	silentLoadBin(list_, name);

	// вывод списка 
	showPerson(list_);

	cout << color(YELLOW_ON_BLACK) << "\n\n\tНомер по списку работника с максимальным окладом: "
		<< color(GREEN_ON_BLACK) << max / sizePerson + 1
		<< color(YELLOW_ON_BLACK) << "\n\tНомер по списку работника с минимальным окладом: "
		<< color(GREEN_ON_BLACK) << min / sizePerson + 1 << color(cl) << endl;

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << name
		<< color(cl) << "\n\n";

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	getKey();

}

// перемещение содержимого в бинарном файле
void App::swapForFile(fstream& file, size_t pos1, size_t pos2, size_t size1, size_t size2)
{
	// исходные позиции в файле по записи и чтению
	size_t curg, curp;

	curp = file.tellp();
	curg = file.tellg();

	// буфер
	char* buf1 = new char[size1 + 1]{ 0 };
	char* buf2 = new char[size2 + 1]{ 0 };

	// считывание содержимого
	file.seekg(pos1, ios::beg);
	file.read(buf1, size1);

	file.seekg(pos2, ios::beg);
	file.read(buf2, size2);

	// замена содержимого
	file.seekp(pos1, ios::beg);
	file.write(buf2, size1);

	file.seekp(pos2, ios::beg);
	file.write(buf1, size2);

	// возвращение по исходным позициям
	file.seekp(curp, ios::beg);
	file.seekg(curg, ios::beg);

	delete[]buf1;
	delete[]buf2;
}

// замена содержимого по позиции
void App::reValueForFile(fstream& file, size_t position, Person& person)
{
	// текущая позиция по записи
	size_t cur = file.tellp();

	// установка указартеля в файле по записи на требуемую позицию по вставке
	file.seekp(position, ios::beg);

	// вставка содержимого
	person.write(file);

	// возврат на позицию по умолчанию
	file.seekp(cur, ios::beg);
}

// замена содержимого по позиции
void App::reValueForFile(ofstream& file, size_t position, Person& person)
{
	// текущая позиция по записи
	size_t cur = file.tellp();

	// установка указартеля в файле по записи на требуемую позицию по вставке
	file.seekp(position, ios::beg);

	// вставка содержимого
	person.write(file);

	// возврат на позицию по умолчанию
	file.seekp(cur, ios::beg);
}

// поиск позиции в файле с минимальным и максимальным окладами
void App::searchSaleryMinMax(fstream& file, size_t& imin, size_t& imax)
{
	// максимальное значение оклада
	double maxVal = 0.;

	// минимальное значение оклада
	double minVal = DBL_MAX;

	// размер файла 
	size_t fSize = sizeFile(file);

	Person temp;

	// размер в файле одного объекта Person
	int sizePerson = Person::RECORD_SIZE;

	// текущая позиция в файле
	int tell = (int)file.tellg();

	// считывание и проверка файла 
	for (file.seekg(0, ios::beg); tell < fSize; )
	{
		temp.read(file);

		tell = file.tellg();
		// значение оклада 
		double val = temp.getSalary();

		// начальная позиция текущей персоны в файле
		int pos = tell - sizePerson;

		// если текущий максимум меньше теукщего значения оклада
		if (maxVal < val)
		{
			maxVal = val;
			imax = pos;
		}

		// если текущий максимум меньше теукщего значения оклада
		if (minVal > val)
		{
			minVal = val;
			imin = pos;
		}
	}
}

// размер файла 
size_t App::sizeFile(ifstream& file)
{
	// текущая позиция
	size_t cur = file.tellg();

	// установка указателя в конец файла 
	file.seekg(0, ios::end);

	// размер файла 
	size_t size = file.tellg();

	// установка указателя в файле в исходную позицию
	file.seekg(cur, ios::beg);

	return size;
}

// размер файла 
size_t App::sizeFile(ofstream& file)
{
	// текущая позиция
	size_t cur = file.tellp();

	// установка указателя в конец файла 
	file.seekp(0, ios::end);

	// размер файла 
	size_t size = file.tellp();

	// установка указателя в файле в исходную позицию
	file.seekp(cur, ios::beg);

	return size;
}

// размер файла 
size_t App::sizeFile(fstream& file)
{
	// текущая позиция
	size_t cur = file.tellg();

	// установка указателя в конец файла 
	file.seekg(0, ios::end);

	// размер файла 
	size_t size = file.tellg();

	// установка указателя в файле в исходную позицию
	file.seekg(cur, ios::beg);

	return size;
}

// Запись в бинарный файл записей одного города
void App::saveByCity()
{
	cls();

	showNavBarMessage(hintColor, "Запись в бинарный файл записей одного города");

	cputs("\n—————————————————————————————————————————————————————— СПИСОК ————————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// имя файла
	string name = "saveBin.bat";

	// загрузка файла из бинарного файла для демонстрации
	silentLoadBin(list_, name);

	// вывод списка 
	showPerson(list_);

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

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << city + ".bat"
		<< color(cl) << "\n\n";

	// поиск запись в отдельный файл работников по городу 
	writeByCity(name, city);

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tСохранение завершено\n\n" << color(cl);

	cputs("\n———————————————————————————————————————————————————— СОХРАНЁННЫЕ —————————————————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// список для демонстрации результата
	DblList<Person> temp;

	// загрузка файла из бинарного файла для демонстрации
	silentLoadBin(temp, city + ".bat");

	// вывод списка 
	showPerson(temp);

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для загрузки: " << color(GREEN_ON_BLACK) << city + ".bat"
		<< color(cl) << "\n\n";

	// вывод сообщения о заверешении сохранения 
	cout << color(GREEN_ON_BLACK) << "\tЗагрузка завершена\n\n" << color(cl);

	getKey();
}

// поиск запись в отдельный файл работников по городу 
void App::writeByCity(string sourceName, string city)
{
	// откртие файла источника 
	fstream source(sourceName, ios::binary | ios::in);

	// если файл открыт неуспешно
	if (!source.is_open())
	{
		stringstream os;

		os << "Файл " << sourceName << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// название файла рездьтирующего
	string name = city + ".bat";

	// создание и открытие файла в режиме записи
	fstream dest(name, ios::binary | ios::out);

	// если файл открыт неуспешно
	if (!dest.is_open())
	{
		stringstream os;

		os << "Файл " << name << " открыт неуспешно!";

		throw exception(os.str().c_str());
	}

	// текущий работник
	Person tmp;

	// сохранение по городу и вывод
	while(true)
	{
		// если достигнут конец файла
		if (source.eof()) break;

		// считывание данных из файла источника
		tmp.read(source);

		// если название города совпадает 
		if (tmp.getCity() == city)
		{
			// сохранение в файл
			tmp.write(dest);
		}
	}

	// закрытие результирующего файла и файла ресурса 
	source.close();
	dest.close();
}

#pragma endregion

#pragma region Задание 2. Чтение файла

/*
 * Задача 2. Дан текстовый файл с текстом русском языке, слова разделяются только одним
 * пробелом, переносов слов в тексте нет.Для файла реализуйте обработки :
 * •	Выведите в консоль исходный файл, выделяя цветом строки с нечетным количеством слов.
 * •	В каждой четной строке файла в начало строки вставьте строку «ух ты », в каждой
 *		нечетной строке замените последнее слово(т.е.после последнего пробела) строкой
 *		«именно так и будет»
 * •	Из первой и последней строк файла удалите первое и последнее слова соответственно(т.е.
 *		символы первой строки до первого пробела и символы последней строки после последнего
 *		пробела)
*/

// Задание 2. Чтение файла
void App::task2()
{
	cls();

	showNavBarMessage(hintColor, "Задание 2. Чтение файла");

	// имя файла 
	string name("test.txt");

	cout << endl;

	// вывод содержимого файла 
	showFile(name);

	// вывод задания
	cputs("\n\n\tВ каждой четной строке файла в начало строки вставьте строку «ух ты », в каждой"
		"\n\tнечетной строке замените последнее слово(т.е.после последнего пробела) строкой"
		"\n\t«именно так и будет»\n\n", YELLOW_ON_BLACK);
	
	// в начало строки вставьте строку «ух ты », в каждой нечетной строке 
	// замените последнее слово на «именно так и будет»
	addStrForFile(name);

	// вывод содержимого файла 
	showFile(name);

	// вывод задания
	cputs("\n\n\tИз первой и последней строк файла удалите первое и последнее слова соответственно(т.е."
		"\n\tсимволы первой строки до первого пробела и символы последней строки после последнего"
		"\n\tпробела)\n\n", YELLOW_ON_BLACK);

	// удаление первого слова в первой строке и последнего слова в последней строке 
	deleteWordForFile(name);

	// вывод содержимого файла 
	showFile(name);

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
		showString(buf, i++, isOdd(buf) ? LTBLUE_ON_BLACK : LTRED_ON_BLACK);
	}

	// вывод разделительной линии для "текстового редактора"
	showLine();

	file.close();
}

// добавление строк 
void App::addStrForFile(string nameFile)
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

		// если достигнут конец файла 
		// if (ifs.eof()) break;

		// buf += '\n';

		// изменение строки

		// если строка чётная 
		if ((i & 1) == 0)
		{
			// вставка в начало строки строку «ух ты »
			buf.insert(0, "Ух ты ");
		}
		else
		{
			// замена последнего слова(т.е.после последнего пробела) строкой «именно так и будет»

			// строка для вставки
			string str("именно так и будет");

			// поиск позиции последнего пробела 
			size_t pos = buf.rfind(' ');

			// если пробел был не найден
			if (pos == string::npos)
			{
				buf = str;
				continue;
			}

			// замена последнего слова
			buf.replace(pos + 1, buf.size(), str);
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

// удаление первого слова в первой строке и последнего слова в последней строке 
void App::deleteWordForFile(string nameFile)
{
	// открытие файла в режиме чтения
	ifstream ifs(nameFile.c_str());

	// имя вспомогательного файла 
	string tempName = "temp.txt";

	// вспомогательный файл
	ofstream ofs(tempName);

	// буфер для строки файла 
	string buf;

	// поиск позиции первого пробела
	getline(ifs, buf);

	// удаление первого слова
	buf.erase(0, buf.find(' '));

	// запись строки в вспомогательный файл
	ofs << buf.c_str() << '\n';

	// считывания файла в строку
	while (true)
	{
		// считывание содержимого строки в буфер
		getline(ifs, buf);

		// просмотр следующего элемента 
		ifs.peek();

		// если достигнут конец файла 
		if (ifs.eof())
		{
			// удаление последнего слова из строки
			buf.erase(buf.rfind(' ') + 1);

			// запись строку в вспомогательный файл
			ofs << buf;

			break;
		}

		// запись строку в вспомогательный файл
		ofs << buf << "\n";
	}

	// закрытие файлов
	ifs.close();
	ofs.close();

	// удаление исходного файла 
	remove(nameFile.c_str());

	// переименование вспомогательного файла
	rename(tempName.c_str(), nameFile.c_str());
}

// проверка на нечётность количества слов
bool App::isOdd(string str)
{
	// количество слов
	int counter = 0;

	// позиция найденного символа
	size_t pos = 0;
	while (true)
	{
		// поиск символа 
		pos = str.find(' ', pos);

		// если символ небыл найден
		if (pos == string::npos)
			return (++counter & 1) == 1;

		// увеличение количества слов в строке 
		counter++;

		// увеличение позиции
		pos++;
	}
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