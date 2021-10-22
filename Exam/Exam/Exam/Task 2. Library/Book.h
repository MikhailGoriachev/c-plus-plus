#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include <ctime>
#include <set>

/*
	Сведения о книгах содержат :
		— Идентификатор(учетный номер единицы хранения)
		— Фамилию и инициалы автора
		— Название книги год издания
		— Количество экземпляров данной книги в библиотеке
*/

// Класс книги
class Book
{
public:

#pragma region Константы 

	// размер строки идентификатора 
	static const int N_ID = 10;

	// минимальный размер поля nameAuthor_
	static const int N_MIN_NAME_AUTHOR = 1;

	// максимальный размер поля nameAuthor_
	static const int N_MAX_NAME_AUTHOR = 20;

	// минимальный размер поля nameBook_ 
	static const int N_MIN_NAME_BOOK = 1;

	// максимальный размер поля nameBook_
	static const int N_MAX_NAME_BOOK = 30;

	// минимальное значение поля year_
	static const int V_MIN_YEAR = 1;

	// минимальное значения поля countBook_
	static const int V_MIN_COUNT_BOOK = 0;

	// максимальное значение поля countBook_
	static const int V_MAX_COUNT_BOOK = INT_MAX;
	
#pragma endregion 

private:

	// Идентификатор(учетный номер единицы хранения)
	string id_;

	// Фамилию и инициалы автора
	string nameAuthor_;
	
	// Название книги 
	string nameBook_;

	// Год издания
	int year_;
	
	// Количество экземпляров данной книги в библиотеке
	int countBook_;

public:

#pragma region Конструкторы, деструктор и перегрузка операции присваивания

	// конструктор по умолнию
	Book() = default;

	// конструктор инициализирующий генерирующий ID
	Book(string nameAuthor, string nameBook, int year, int countBook);

	// конструктор инициализирующий принимающий ID
	Book(string id, string nameAuthor, string nameBook, int year, int countBook);

	// конструктор копирующий
	Book(const Book& book) = default;

	// декструктор 
	~Book();

	// перегрузка операции присваивания
	Book& operator=(const Book& book) = default;

#pragma endregion 

#pragma region Сеттеры и геттеры

	// сеттер id_
	void setId(string id);

	// геттер id_
	string getId();

	// сеттер nameAuthor_ 
	void setNameAuthor(string nameAuthor);

	// геттер nameAuthor_
	string getNameAuthor();

	// сеттер nameBook_
	void setNameBook(string nameBook);

	// геттер nameBook_
	string getNameBook();

	// сеттер year_
	void setYear(int year);

	// геттер year_
	int getYear();

	// сеттер countBook_
	void setCountBook(int countBook);

	// геттер countBook_
	int getCountBook();

#pragma endregion 

#pragma region Методы 

	// генерация идентификатора
	static string genId();

#pragma endregion

#pragma region Дружественные функции 
	
	// перегрузка операции вывода в консоль 
	friend ostream& operator<<(ostream& os, const Book& book);

	// перегрузка операции вывода в текстовый файл 
	friend ofstream& operator<<(ofstream& ofs, const Book& book);
	friend fstream& operator<<(fstream& fs, const Book& book);

	// перегрузка операции ввода из istream
	friend istream& operator>>(istream & is, Book & book);

	// перегрузка операции ввода из текстового файла
	friend ifstream& operator>>(ifstream& ifs, Book& book);
	friend fstream& operator>>(fstream& fs, Book& book);

#pragma endregion

};

