#pragma once
#include "pch.h"
#include "Utils.h"

#include <functional>
#include <algorithm>
#include <numeric>
#include <iterator>

#include <vector>
#include <set>
#include <list>

#include "Task 2. Library/Library.h"
#include "Task 3. Mobile station/ListPayer.h"
#include "Task 3. Mobile station/Payer.h"
#include "Task 3. Mobile station/Bill.h"

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
	// Задание 1. Вектор
	vector<int> vec_;
	
	// Задание 1. Название бинарного файла для сохранения вектора
	string nameFileVector_;

	// Задание 2. Название файла для сохранения
	string nameFileLibrary_;

	// Задание 2. Библиотека 
	Library library_;

	// Задание 3. Название файла для сохранения результатов поиска 
	string nameFileResSearch_;

	// Задание 3. Список плательщиков
	ListPayer listPayer_;

public:

#pragma region Конструкторы, деструктор и перегрузка операции присваивания

	// конструктор по умолчанию 
	App() : vec_(), nameFileVector_("Task 1. Vector/saveVector.bin"), nameFileLibrary_("Task 2. Library/saveLibrary.csv"),
		library_("ул. Артема, д. 84, г. Донецк", "Игорь Горбатов", nameFileLibrary_), 
		nameFileResSearch_("Task 3. Mobile station/saveSearch.bin")
	{
#pragma region Задание 2. Библиотека 

		// Задание 2. Инициализация библиотеки, если нет файла для сохранения
		if (!checkFile(nameFileLibrary_))
		{
			// вектор с книгами
			vector<Book> tempBookVec{
				Book("Булгаков М. А.",		"Записки юного врача",		1926,	getRand(20, 40)),
				Book("Толстой Л. Н.",		"Война и мир",				1996,	getRand(20, 40)),
				Book("Гончаровым B. А.",	"Обломов",					1859,	getRand(20, 40)),
				Book("Гоголь Н. В.",		"Ревизор",					1835,	getRand(20, 40)),
				Book("Эрих Мария Ремарк",	"Жизнь взаймы",				1959,	getRand(20, 40)),
				Book("Роман Прокофьев",		"Стеллар. Инкарнатор",		2021,	getRand(20, 40)),
				Book("Олдос Хаксли",		"О дивный новый мир",		1932,	getRand(20, 40)),
				Book("Эльчин Сафарли",		"Мне тебя обещали",			2010,	getRand(20, 40)),
				Book("Гоголь Н. В.",		"Мёртвые души",				1842,	getRand(20, 40)),
				Book("Рэй Брэдбери",		"451 градус по Фаренгейту",	1953,	getRand(20, 40)),
				Book("Зигмунд Фрейд",		"Введение в психоанализ",	1917,	getRand(20, 40)),
				Book("Фёдор Достоевский",	"Преступление и наказание",	1866,	getRand(20, 40)),
				Book("Стивен Кинг",			"Позже",					2021,	getRand(20, 40)),
				Book("Иванов А. В.",		"Тени тевтонов",			2021,	getRand(20, 40)),
				Book("Та-Нехаси Коутс",		"Танцующий на воде",		2021,	getRand(20, 40)),
				Book("Рэй Брэдбери",		"Марсианские хроники",		1950,	getRand(20, 40)),
			};

			// инициализация Библиотеки
			library_.addAllBook(tempBookVec);

			// сохранение библиотеки в файл
			library_.saveLibrary();
		}

		// иначе загрузка из файла
		else
			library_.loadLibrary();

#pragma endregion

#pragma region Задание 3. Список плательщиков

		// инициализация списка плательщиков 
		auto getDate = []() { return genDateTime(12, 16, 8, 8, 2021, 2021, 0, 23, 0, 59, 0, 59); };
		
		// вектор с плательщиками
		vector<Payer> payers{
			// конструктор инициализирующий 
			// string namePayer, string phoneNumber, double rate, double discount, DateTime datePay
			Payer("Снегова В. А.",		"0500162535", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Соколова В. В.",		"0503395393", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Баранов А. Е.",		"0501122942", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Фролова К. Т.",		"0502575942", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Лермонтова Е. Р.",	"0506921373", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Петрова У. С.",		"0501324362", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Редкая Р. А.",		"0507577903", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Вострикова Р. П.",	"0505184613", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Градова Н. П.",		"0500644371", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("Безрукова А. Р.",	"0501394919", getRand(0., 1.), getRand(0, 20), getDate())
		};

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
				}
				while(start >= end);

				// добавление в вектор
				bills.push_back(Bill(start, end));
			}

			return bills;
		};

		// добавление разговоров плательщиков 
		for_each(payers.begin(), payers.end(), [getBills](Payer& payer) { payer.setBills(getBills(payer)); });

		// заполнение списка 
		listPayer_.addAllPayer(payers);

#pragma endregion 

	}

	// конструктор копирующий
	App(const App& app) = default;

	// деструктор 
	~App() = default;

	// перегрузка операции присварвания
	App& operator=(const App& app) = default;

#pragma endregion 

#pragma region Превью запуска приложения 

	// Превью запуска приложения
	static void preview();

	// заполнение заднего фона 
	static void fillBackground(int row, int col, short color, int time);
	
	// анимация вывода текста 
	static void outText(string message, int time, short color, int x, int y);

	// анимация полосы загрузки 
	static void loadingLine(int size, int time, int x, int y, short colorLoading = GREEN_ON_BLACK, short colorBackground = mainColor, short colorComplete = BLACK_ON_GREEN);

	// вывод рамки
	static void outFrame(int hight, int width, int x, int y, short colorFrame = mainColor, short colorBackground = infoColor);


#pragma endregion 

#pragma region Задания 

#pragma region Задание 1. Вектор

	// Задание 1. Вектор
	void task1();

	// 1. Заполнение вектора 
	void taskOneFillVector();

	// 2. Количество элементов вектора, равных 0
	void taskOneCountNull();

	// вывод элементов с подсветкой елементов со значением 0
	static void showElemVectorNull(vector<int> vec);

	// 3. Сумму элементов вектора, расположенных после минимального элемента
	void taskOneSummElem();

	// вывод элементов с подсветкой первого минимального элемента 
	static void showElemVectorMin(vector<int> vec);

	// 4. Удалить элементы, встречающиеся менее двух раз
	void taskOneDeleteDouble();

	// вывод элементов с подсветкой элементов встречающихся менее двух раз 
	static void showElemVectorRem(vector<int> vec);

	// 5. Упорядочить вектор по возрастанию модулей элементов
	void taskOneSortByModule();

	// 6. Продублировать отрицательные элементы вектора
	void taskOneDoubleNegative();

	// вывод элементов с подсветкой отрицательных елементов
	static void showElemVectorNegative(vector<int> vec);

	// 7. Сохранить вектор в бинарном файле при помощи потока вывода
	void taskOneSaveBinFile();

	// чтение вектора из файла
	void readVectorBinFile(string nameFile, vector<int>& vec);

	// сохраненеи вектора в файл
	void saveVectorBinFile(string nameFile, vector<int>& vec);

	// 8. Прочитать вектор из бинарного файла при помощи потока ввода
	void taskOneLoadBinFile();

#pragma region Общие методы 

	// вывод вектора 
	static void showVector(vector<int> vec, string messageName, string messageInfo, void showElemFunc(vector<int> vec) = showElemVector);

	// вывод шапки с информацией
	static void showHeadVector(vector<int> vec, string messageName, string messageInfo);

	// вывод элементов 
	static void showElemVector(vector<int> vec);

	// вывод разделительной линии
	static void showLineVector();

#pragma endregion

#pragma endregion 

#pragma region Задание 2. Библиотека

	// Задание 2. Библиотека
	void task2();

	// 1. Вывод данных библиотеки и коллекции книг в консоль
	void showLibrary();

	// 2. Добавление книги
	void addBook();

	// 3. Удаление книг по идентификатору
	void deleteByID();
	
	// 4. Изменение количества книг заданного автора
	void editCountBooks();
	
	// 5. Отбор книг по году издания
	void selectionByYear();
	
	// 6. Отбор книг по автору
	void selectionByAuthor();
	
	// 7. Сортировка книг по убыванию количества книг
	void sortByCountBook();
	
	// 8. Сортировка книг по идентификатору
	void sortByBookID();
	
	// 9. Сортировка книг по названию
	void sortByNameBook();

#pragma endregion

#pragma region Задание 3. Телефонная станция

	// Задание 3. Телефонная станция
	void task3();

	// 1. Вывод списка плательщиков 
	void showListPayer();

	// 2. Добавление плательщика в список
	void addPayer();

	// 3. Удаление плательщика из списка
	void deletePayer();

	// считывание объектов Payer в вектор 
	void readPayerFile(vector<Payer>& payers, string fileName);

	// 4. Поиск плательщика по номеру телефона и вывод звонков
	void searchPayerByNumber();

	// 5. Поиск плательщика по фамилии и инициалам
	void searchPayerName();

	// 6. Поиска плательщиков по дате платежа
	void searchPayerByDate();

	// 7. Вычисления полной стоимости платежей всего списка
	void sumPay();

	// 8. Объединение списков
	void mergeListPayers();

	// вывод элементов 
	void showElemPayerByList(list<Payer>& payers);

	// 9. Пересечение списков
	void crossListPayers();

	// 10. Отбор данных по дате платежа
	void selectionPayerByDate();

	// 11. Отбор данных по номеру телефона
	void selectionPayerByNumber();

	// 12. Сортировка по номеру телефона
	void sortByNumber();

	// 13. Сортировка по убыванию суммы к оплате
	void sortByPay();

	// 14. Сортировка по убыванию времени разговоров
	void sortByTime();

#pragma endregion

#pragma endregion

#pragma region Общие методы

	// проверка на открытие файла
	bool checkFile(string fileName);

	// создание даты
	static DateTime genDateTime(int minDay, int maxDay, int minMonth, int maxMonth, int minYear, int maxYear,
		int minHour, int maxHour, int minMinute, int maxMinute, int minSecond, int maxSecond);

	// создание даты 
	static DateTime genDate(DateTime dateTime, int minDay, int maxDay, int minMonth, int maxMonth, int minYear, int maxYear);

	// создание даты 
	static DateTime genTime(DateTime dateTime, int minHour, int maxHour, int minMinute, int maxMinute, int minSecond, int maxSecond);

#pragma endregion

};

