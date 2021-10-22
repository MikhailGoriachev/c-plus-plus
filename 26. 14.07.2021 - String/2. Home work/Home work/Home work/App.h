#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "BinaryTree.h"
#include "DblList.h"
#include "Person.h"

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

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
public:

	// длина массива для заполнения 
	static const int SIZE_FILL_ARR = 12;

private:

	// база табельных номеров класса Person
	BinaryTree<unsigned int> numberBase_;

	// двусвязный список из объектов класса Person
	DblList<Person> list_;

	// список персон для списка 
	Person* personsByList_;

public:

	// конструктор по умолчанию
	App()
	{
		// 	Person(unsigned int number, const char* name, double salary, int year, int monthWorkDay, int completedWorkDay) try

		// список персон
		personsByList_ = new Person[SIZE_FILL_ARR]
		{
			Person(654878, "Бобров В.Б",   "Донецк",    getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(987521, "Иванов Н.Г",    "Запорожье", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(345987, "Дьячков В.Ф",   "Донецк",    getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(567442, "Тарасов Н.Х",   "Киев",      getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654574, "Шашков Г.Л",    "Мариуполь", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(324957, "Лобанов И.С",   "Киев",      getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(687684, "Третьяков О.Х", "Мариуполь", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(795215, "Бирюков М.М",   "Донецк",    getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(564957, "Игнатов Н.В",   "Киев",      getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654212, "Логинов А.Е",   "Запорожье", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(567541, "Ситников М.В",  "Мариуполь", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(245621, "Кулаков Л.Я",   "Донецк",    getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		};

		// список персон
		// personsByTree_ = new Person[SIZE_FILL_ARR]
		// {
		// 	Person(579846, "Власов А.Ф", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(324987, "Данилов Г.Г", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(654981, "Крылов Д.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(789165, "Авдеев В.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(645954, "Овчинников Р.Ф", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(989234, "Архипов А.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(651579, "Терентьев Т.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(654621, "Емельянов Б.Г", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(654653, "Александров В.Г", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(216577, "Игнатов А.П", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(654982, "Белов О.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// 	Person(215440, "Пестов А.Д", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		// };

	}

	// деструктор 
	~App() = default;


#pragma region Задание 1. Список рабочих

	// Задание 1. Список рабочих
	void task1();

	// Заполнение списка рабочих
	void fillPersons();

	// Генерация исключений
	void genExceptionAddList();

	// Генерация исключений при создании объекта
	void genExceptionCreate();

	// Вывод двусвязого списка
	void printList();

	// Сохранение двусвязного список в текстовый файл
	void saveText();

	// Загрузка данных из текстового файла в двусвязный список
	void loadText();

	// Сохранение двусвязного список в бинарный файл
	void saveBin();

	// Загрузка данных из бинарного файла в двусвязный список
	void loadBin();

	// сумма начислений по двусвязному списку
	double accruedAll(DblList<Person> list);

	// добавление одного элемента в список
	void addPerson(Person& person, DblList<Person> list);

	// добавление массива элементов в список
	void addAllPerson(Person* data, int n, DblList<Person> list);

	// добавление номера в базу номеров
	bool registrationNumber(unsigned int number);

	// вывод списка в виде таблицы
	void showPerson(DblList<Person> list);

	// Поменять местами записи с минимальным и максимальным окладом
	void swapBySalery();

	// Запись в бинарный файл записей одного города
	void saveByCity();

	// поиск позиции в файле с минимальным и максимальным окладами
	void searchSaleryMinMax(fstream& file, size_t& imin, size_t& imax);

	// перемещение содержимого в бинарном файле
	void swapForFile(fstream& file, size_t pos1, size_t pos2, size_t size1, size_t size2);

	// замена содержимого по позиции
	void reValueForFile(fstream& file, size_t position, Person& person);

	// замена содержимого по позиции
	void reValueForFile(ofstream& file, size_t position, Person& person);

	// Тихое сохранение двусвязного списка в бинарный файл
	void silentSaveBin(DblList<Person>& list);

	// Тихая загрузка данных из бинарного файла в двусвязный список
	void silentLoadBin(DblList<Person>& list, string fileName);

	// поиск запись в отдельный файл работников по городу 
	void writeByCity(string sourceName, string city);

	// размер файла 
	size_t sizeFile(ofstream& file);

	// размер файла 
	size_t sizeFile(ifstream& file);

	// размер файла 
	size_t sizeFile(fstream& file);

#pragma endregion

#pragma region Задание 2. Чтение файла

	// Задание 2. Чтение файла
	void task2();

	// вывод шапки "текствого редактора"
	void showHead(string fileName);

	// вывод линии-разделителя для "текстового редактора"
	void showLine();

	// вывод строки файла для "текстового редактора"
	// i - номер строки
	void showString(string str, int i, short colorLine);

	// проверка на нечётность количества строк
	bool isOdd(string str);

	// вывод файла 
	void showFile(string nameFile);

	// добавление строк 
	void addStrForFile(string nameFile);

	// удаление первого слова в первой строке и последнего слова в последней строке 
	void deleteWordForFile(string nameFile);

#pragma endregion

};

