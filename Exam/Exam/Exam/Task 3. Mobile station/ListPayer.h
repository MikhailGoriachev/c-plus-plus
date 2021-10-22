#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include <functional>
#include <numeric>

#include "DateTime.h"
#include "Bill.h"
#include "Payer.h"

// Разработайте класс – список плательщиков ListPayer. 
// Класс содержит:
//	- список плательщиков за телефонные услуги
//	- дату создания списка
//	- номер списка

//	Реализовать для класса ListPayer :
//		•	Метод добавления плательщика в список
//		•	Метод удаления плательщика из списка
//		•	Метод поиска плательщика по номеру телефона, найденные записи помещать в отдельную коллекцию,
//			сохранять в бинарном потоке вывода
//		•	Метод поиска плательщика по фамилии и инициалам, найденные записи помещать в отдельную
//			коллекцию, сохранять в бинарном потоке вывода
//		•	Метод поиска плательщиков по дате платежа, найденные записи помещать в отдельную коллекцию,
//			сохранять в бинарном потоке вывода
//		•	Метод вычисления полной стоимости платежей всего списка
//	Реализовать создание объектов ListPayer, операции объединения и пересечения списков.
//		•	Операция объединения списка – бинарная операция, на выходе получаем список из элементов двух
//			списков, без дубликатов.
//		•	Операция пересечения списка – бинарная операция, на выходе получаем список из элементов
//			имеющихся и в первом, и во втором списках, без дубликатов.
//	Реализовать отбор данных из списка плательщиков :
//		•	По дате платежа, сортировка по номеру телефона
//		•	По номеру телефона, сортировка по номеру телефона
//	Реализовать сортировку списка плательщиков :
//		•	По номеру телефона
//		•	По убыванию суммы к оплате
//		•	По убыванию времени разговоров


// Класс Список плательщиков
class ListPayer
{
	// генератор номера для списка 
	static int numbersGen_;

	// список плательщиков за телефонные услуги
	vector<Payer> payers_;
	
	// дата создания списка
	DateTime dateCreate_;
	
	// номер списка
	int number_;

public:

#pragma region Конструкторы, деструктор и перегрузка операции присваивания 

	// конструктор по умолчанию
	ListPayer();

	// конструктор копирующий
	ListPayer(const ListPayer& listPayer) = default;

	// деструктор 
	~ListPayer() = default;

	// перегрузка операции присваивания
	ListPayer& operator=(const ListPayer& listPayer) = default;

#pragma endregion 

#pragma region Геттеры и сеттеры

	// сеттер payers_
	void setPayers(vector<Payer>& payers);

	// геттер payers_
	vector<Payer>& getPayers();

	// геттер dateCreate_
	const DateTime& getDateCreate();

#pragma endregion

#pragma region Методы

	// проверка номера на уникальность
	// true - номер найден, false - номер НЕ найден
	bool checkNumber(string& numberPayer);

	// добавление плательщика в список
	void addPayer(Payer& payer);

	// добавление плательщиков в список
	void addAllPayer(vector<Payer>& payers);

	// удаление плательщика из списка
	void delPayer(string& numberPayer);
	
	// поиск плательщика по номеру телефона, сохранять в бинарном потоке вывода
	vector<Payer> searchByNumber(string& numberPayer, string nameSaveFile);
	
	// поиск плательщика по фамилии и инициалам, сохранять в бинарном потоке вывода
	vector<Payer> searchByName(string& namePayer, string nameSaveFile);
	
	// поиск плательщиков по дате платежа, найденные записи помещаются в отдельную коллекцию,
	// сохраняются в бинарном потоке вывода
	vector<Payer> searchByDate(DateTime& dateTime, string nameSaveFile);
	
	// вычисление полной стоимости платежей всего списка
	double payAll();

	// вычисление полного времени разговоров всего списка в минутах
	time_t timeAll();

	// вычисление полной стоимости платежей всего списка
	static double payAll(vector<Payer> payers);

	// количество элементов в списке 
	int countPayer();

	// открытие файла для записи 
	fstream openFileWrite(string& nameFile);

	// открытие файла для чтения 
	fstream openFileRead(string& nameFile);

	// открытие файла для дописи в файл
	fstream openFileWriteRead(string& nameFile);

	// вывод списка в виде таблицы
	void showTable(string nameList = "Список плательщиков", string info = "Данные");

	// вывод списка в виде таблицы
	void showTableTime(string nameList = "Список плательщиков", string info = "Данные");

	// вывод шапки таблицы
	static void showHead(ListPayer& listPayer, string nameList = "Список плательщиков", string info = "Данные");

	// вывод шапки таблицы
	static void showHeadTime(ListPayer& listPayer, string nameList = "Список плательщиков", string info = "Данные");

	// вывод элементов 
	static void showElem(vector<Payer> payers);

	// вывод элементов 
	static void showElemTime(vector<Payer> payers);

	// вывод разделителя 
	static void showLine();

	// вывод сообщения об отсутствии данных
	static void showEmpty();

	// вывод сообщения об отсутствии данных
	static void showEmptyTime();

#pragma endregion

#pragma region Дружественные функции 

#pragma endregion

};

