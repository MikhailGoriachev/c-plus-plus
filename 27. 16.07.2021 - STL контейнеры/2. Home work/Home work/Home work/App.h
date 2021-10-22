#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include <vector>
#include <deque>

#include "Person.h"

/*
 *	Задача 1. Дан текстовый файл с текстом русском языке, слова разделяются только
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
// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
public:

	// длина массива для заполнения 
	static const int SIZE_FILL_ARR = 12;

private:

	// база табельных номеров класса Person
	vector<unsigned int> numberBase_;

	// двусвязный список из объектов класса Person
	vector<Person> persons_;

	// список персон для списка 
	Person* personsByVector_;

	// имя файла для задания 1
	string taskOneFileName_;

	// вектор для второго задания
	vector<int> vectorTaskThree_;

	// имя файла для задания 3
	string taskThreeFileName_;


public:

	// конструктор по умолчанию
	App()
	{
		// имя файла для задания 1
		taskOneFileName_ = "test.txt";

		// заполенение вектора для задания 2
		int sizeVector = getRand(8, 12);

		vectorTaskThree_ = { 10, 45, 10, 45, 15, 10, 14, 45, 45 };

		// имя файла для задания 3
		taskThreeFileName_ = "person.bin";

		// 	Person(unsigned int number, const char* name, double salary, int year, int monthWorkDay, int completedWorkDay) try

		// список персон
		personsByVector_ = new Person[SIZE_FILL_ARR]
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


#pragma region Задание 1. Чтение файла

	// Задание 1. Чтение файла
	void task1();

	// Вывод исходного файла с выделением чётных строк
	void outFile();

	// вывод файла в цвете с подсветкой чётных строк
	void showColorOddEvenFile(string nameFile);

	// Замена второго слова в каждой строке на «+++ возможно +++»
	void replace();

	// Удаление последнего слова с чётных строк
	void changeEven();

	// Вставка в начало нечётных строк «это STL »
	void changeOdd();

	// замена слова в строках на строку
	void replaceForFile(string nameFile, string insStr, int nWord, int nStr, int positioningWord);

	// вывод шапки "текствого редактора"
	void showHead(string fileName);

	// вывод линии-разделителя для "текстового редактора"
	void showLine();

	// вывод строки файла для "текстового редактора"
	// i - номер строки
	void showString(string str, int i, short colorLine);

	// вывод файла 
	void showFile(string nameFile);

#pragma endregion

#pragma region Задание 2. Вектор с числами

	// Задание 2. Вектор с числами
	void task2();

	// Удаление из вектора всех элементов, встречающихся более двух раз
	void deleteElem();

	// удаление из вектора элеменов, которые всечаются больше двух раз по заданию
	void deleteOverDouble(vector<int>& vec);

	// Вставка нулевого элемента
	void insertBefore();

	// вставка нулевого элемента
	void insertNullElem(vector<int>& vec, int index);

	// минимальный элемент 
	void searchMinForVector(vector<int>& vec, int& min);

	// максимальный элемент 
	void searchMaxForVector(vector<int>& vec, int& max);

	// Вставка нулевого элемента перед минимальным и после максимального элемента
	void insertMinMax();

	// вывод вектора в таблице
	void showVector(vector<int>& vec, string dataName, string description, int colorElem);

	// вывод шапки таблицы
	void showHead(vector<int>& vec, string& dataName, string& description);

	// вывод элементов таблицы
	void showElem(vector<int>& vec, int colorElem);

	// вывод линии-разделителя таблицы
	void showLineVec();

	// вывод сообщения об отсутствии данных для таблицы
	void showEmpty();

#pragma endregion

#pragma region Задание 3. Список рабочих

	// Задание 3. Список рабочих
	void task3();

	// Заполнение списка рабочих
	void fillVector();

	// Вывод двусвязого списка
	void printVector();

	// Сохранение двусвязного список в бинарный файл
	void saveBin();

	// Загрузка данных из бинарного файла в двусвязный список
	void loadBin();

	// сумма начислений по двусвязному списку
	double accruedAll(vector<Person> persons);

	// добавление одного элемента в список
	void addPerson(Person& person, vector<Person>& persons);

	// добавление массива элементов в список
	void addAllPerson(Person* data, int n, vector<Person>& persons);

	// добавление номера в базу номеров
	bool registrationNumber(unsigned int number);

	// поиск по номеру Person в векторе 
	bool numberFind(vector<unsigned int>& numberBase, unsigned int number);

	// вывод списка в виде таблицы
	void showPerson(vector<Person>& persons);

	// Поменять местами записи с минимальным и максимальным окладом
	void swapBySalery();

	// Запись в бинарный файл записей одного города
	void saveByCity();

	// поиск позиции в векторе с минимальным и максимальным окладами
	void searchSaleryMinMax(vector<Person>& persons, int& imin, int& imax);

	// Тихое сохранение двусвязного списка в бинарный файл
	void silentSaveBin(vector<Person>& persons, string fileName);

	// Тихая загрузка данных из бинарного файла в двусвязный список
	void silentLoadBin(vector<Person>& persons, string fileName);

	// поиск запись в отдельный файл работников по городу 
	void writeByCity(vector<Person>& persons, string destFile, string city);

	// Копирование в очередь записей по диапазону окладов
	void saveBySalary();

	// поиск и запись в отдельный файл работников по окладу 
	void writeBySalary(vector<Person>& persons, deque<Person>& deq, string destFile, double sMin, double sMa);

	// загрузка в очередь из файла 
	void loadBinDeq(deque<Person>& persons, string fileName);

	// вывод списка в виде таблицы
	void showPerson(deque<Person>& persons);

	// сумма начислений по двусвязному списку
	double accruedAll(deque<Person>& persons);

#pragma endregion

};

