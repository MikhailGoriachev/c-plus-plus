#include "App.h"


#pragma region Задание 1 

/*
 * 	Разработать консольное приложение, с использованием класса Person, двусвязного
 *	списка (класс DblList<Person>)объектов класса Person. Примените функциональные
 *	try-блоки в конструкторах класса Person.
 *
 *	Класс Person имеет поля:
 *		Табельный номер, целое число, уникальное в пределах приложения
 *		Фамилия и инициалы – динамическое поле, char *
 *		Оклад, вещественное число
 *		Год поступления на работу
 *		Количество рабочих дней в месяце
 *		Количество фактически отработанных дней в месяце
 *	Разработать конструкторы и деструктор, аксессоры, метод записи полей в
 *	форматированный поток вывода, метод чтения полей из форматированного потока ввода,
 *	метод записи в бинарный поток вывода, метод чтения из бинарного потока ввода, метод
 *	вычисления начислений –произведение оклада на отношение количества фактически
 *	отработанных дней к количеству рабочих дней в месяце.
 *	Начислено=Оклад∙ (Фактически отработано)/(Рабочих дней в месяце)
 *	  — Создать двусвязный список из объектов класса Person–не менее 12 элементов,
 *		показать работу конструкторов, методов, генерацию и обработку исключений.
 *	  —	Разработать функцию, вычисляющую сумму начислений по двусвязному списку персон
 *	  —	Сохранить двусвязный список в текстовом файле с использованием форматированного
 *		потока записи, формат вывода в поток одного элемента списка:
 *			Первая строка – табельный номер
 *			Вторая строка – фамилия и инициалы
 *			Третья строка – остальные поля данных, через пробел
 *	  —	Загрузить из записанного файла в другой двусвязный список записи с окладом в
 *		заданном диапазоне значений. Использовать форматированный файловый поток чтения.
 *	  —	Выгрузить двусвязный список персон в файл при помощи бинарного потока вывода ofstream.
 *	  —	Прочитать из бинарного файла при помощи бинарного потока ввода ifstream и в односвязный
 *		список записи и отобразить этот односвязный список в консоли.
*/

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

	cout<< " |                                                                              | " 
		<< color(YELLOW_ON_BLACK) << "СУММА НАЧИСЛЕНИЙ:   " << color(cl) << " | "
		<< setw(12) << accruedAll(list_) << " |\n"
		<< " +——————————————————————————————————————————————————————————————————————————————+——————————————————————+——————————————+\n";
}

// Сохранение двусвязного список в текстовый файл
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

	// Табельный номер, целое число, уникальное в пределах приложения unsigned int
	unsigned int number_;

	// Фамилия и инициалы – динамическое поле, char*
	char* name_ = new char[Person::MAX_NAME_SIZE + 1];

	// Оклад, вещественное число, double
	double salary_;

	// Год поступления на работу, int
	int year_;

	// Количество рабочих дней в месяце, int
	int monthWorkDay_;

	// Количество фактически отработанных дней в месяце, int
	int completedWorkDay_;

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
	const char* name = "saveBin.txt";

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
	const char* name = "saveBin.txt";

	// вывод названия файла 
	cout << color(YELLOW_ON_BLACK) << "\n\n\n\tФайл для сохранения: " << color(GREEN_ON_BLACK) << name
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

	// Табельный номер, целое число, уникальное в пределах приложения unsigned int
	unsigned int number_;

	// Фамилия и инициалы – динамическое поле, char*
	char* name_ = new char[Person::MAX_NAME_SIZE + 1];

	// Оклад, вещественное число, double
	double salary_;

	// Год поступления на работу, int
	int year_;

	// Количество рабочих дней в месяце, int
	int monthWorkDay_;

	// Количество фактически отработанных дней в месяце, int
	int completedWorkDay_;

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

#pragma endregion
