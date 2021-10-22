#pragma once
#include "..\\pch.h"
#include "..\\Utils.h"
#include "Book.h"
#include <vector>
#include <algorithm>

/*
	Сведения о библиотеке:
		- адрес библиотеки
		- фамилия и инициалы директора
		- коллекция книг
*/

// Класс библиотека 
class Library
{

#pragma region Константы

public:

	// максимальный размер поля address_
	static const int N_MAX_ADDRESS = 80;

	// минимальный размер поля address_
	static const int N_MIN_ADDRESS = 1;

	// максимальный размер поля nameDirector_
	static const int N_MAX_NAME_DIRECTOR = 40;

	// минимальный размер поля nameDirector_
	static const int N_MIN_NAME_DIRECTOR = 1;

	// максимальный размер поля fileName_
	static const int N_MAX_FILE_NAME = MAX_PATH;

	// минимальный размер поля fileName_
	static const int N_MIN_FILE_NAME = 0;

#pragma endregion

private:

	// Поле идентификации книг(учетных номеров)
	set<string> baseID_;

	// адрес библиотеки
	string address_;
	
	// фамилия и инициалы директора
	string nameDirector_;
	
	// коллекция книг
	vector<Book> books_;
	
	// имя файла для сохранения
	string fileName_;

public:

#pragma region Конструкторы, деструктор, перегрузка операции присваивания 

	// конструктор по умолчанию
	Library() = default;

	// конструктор инициализирующий 
	Library(string address, string nameDirector, string fileName);

	// конструктор инициализирующий (загрузка из файла)
	Library(string fileName);

	// конструктор инициализирующий (загрузка из массива Book)
	Library(string address, string nameDirector, vector<Book>& books, string fileName);

	// конструктор копирующий 
	Library(const Library& library) = default;

	// деструктор 
	~Library() = default;

	// перегрузка операции присваивания
	Library& operator=(const Library& library) = default;

#pragma endregion 

#pragma region Сеттеры и геттеры

	// сеттер address_
	void setAddress(string adress);

	// геттер address_
	const string& getAddress();

	// сеттер nameDirector_
	void setNameDirector(string nameDirector);

	// геттер nameDirector_
	const string& getNameDirector();

	// геттер books_
	vector<Book>& getBooks();

	// сеттер fileName_
	void setFileName(string fileName);

	// геттер fileName_
	const string& getFileName();

#pragma endregion

#pragma region Методы 

	// проверка идентификатора на уникальность
	bool checkId(string id);

	// генерация идентификатора
	string genId();

	// добавление книги в библиотеку 
	void addBook(Book& book);

	// добавление вектора книг в библиотеку
	void addAllBook(vector<Book> books);

	// удаление книги из библиотеки
	void removeBook(string id);

	// отчистка библиотеки от книг
	void clear();

	// получение книги по ID
	Book& getBook(string id);

	// загрузка библиотеки из файла .csv - по умолачнию
	void loadLibrary();

	// загрузка библиотеки из файла .csv - указанного файла 
	void loadLibrary(string fileName);

	// сохранение библиотеки в файл .csv - по умолачнию
	void saveLibrary();

	// сохранение библиотеки в файл .csv - указанного файла 
	void saveLibrary(string fileName);

	// количество книг в библиотеке 
	int countBooks();

	// вывод данных библиотеки и коллекции книг в консоль
	void showLibrary(string nameLibrary = "Библиотека", string info = "Данные о книгах");

	// вывод шапки таблицы 
	static void showHead(int countElem, string nameLibrary = "Библиотека", string infoLibrary = "Данные о книгах");

	// вывод шапки таблицы 
	static void showHead(string address, string director, int countElem, string nameLibrary = "Библиотека", string infoLibrary = "Данные о книгах");

	// вывод коллекции книг
	static void showElem(vector<Book> books, short colorLine = LTCYAN_ON_BLACK, short colorText1 = LTYELLOW_ON_BLACK, short colorText2 = LTGREEN_ON_BLACK);

	// вывод книги
	static void showElem(Book book, short colorLine = LTCYAN_ON_BLACK, short colorText1 = LTYELLOW_ON_BLACK, short colorText2 = LTGREEN_ON_BLACK);

	// вывод разделителя 
	static void showLine(short colorLine = LTCYAN_ON_BLACK);

	// перегрузка операции индексирования
	Book& operator[](int index);

#pragma endregion

#pragma region Дружественные функции 

	// перегрузка операции вывода в строку вектора Book
	friend ostream& operator<<(ostream & os, const vector<Book>&books);

	// перегрузка операции вывода в сторку
	friend ostream& operator<<(ostream & os, const Library & library);

	// перегрузка операции вывода в файл
	friend ofstream& operator<<(ofstream & os, const Library & library);

	// перегрузка операции ввода из строки в вектор Book
	friend istream& operator>>(istream & is, vector<Book>&books);

	// перегузка операции ввода из строки
	friend istream& operator>>(istream & os, Library & library);

	// перегрузка операции ввода из файла 
	friend ifstream& operator>>(ifstream & os, Library & library);

#pragma endregion 

#pragma region Общие методы

	// проверка на открытие файла
	bool checkFile(string fileName);

#pragma endregion

};

