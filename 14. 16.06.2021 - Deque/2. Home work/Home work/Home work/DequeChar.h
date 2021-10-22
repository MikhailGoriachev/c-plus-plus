#pragma once
#include "pch.h"
#include "Colors.h"
#include "Utils.h"

// Дек - двусторонняя очередь (char)
class DequeChar
{
public:

	// размер дека по умолчанию
	static const int SIZE_DEFAULT = 15;

private:

	// размер массива-контейнера
	int size_;

	// указатель на массив-контейнер (char)
	char* data_;

	// конец дека 
	int back_;

public:

#pragma region Конструкторы и деструктор 

	// конструктор по умолчанию
	DequeChar() : size_(SIZE_DEFAULT), data_(new char[size_]), back_() {};

	// конструктор инициализирующий
	DequeChar(int size);

	// конструтор на основе массива 
	DequeChar(char* arrChar, int size);

	// копирующий конструктор
	DequeChar(const DequeChar& dequeChar);

	// деструктор
	~DequeChar();

#pragma endregion

#pragma region Методы

	// добавить в начало дека
	void shift(char value);

	// добавление массива в начало дека 
	void shiftAll(char* arrChar, int size);

	// посмотреть начальный элемент дека
	char front() const;

	// взять элемент с начала дека
	char unshift();

	// добавить в конец дека
	void push(char value);

	// добавление массива в конец дека
	void pushAll(char* arrChar, int size);

	// посмотреть последний элемент дека
	char back() const;

	// взять элемент с конца дека
	char pop();

	// отчистка дека
	void clear();

	// опустошение дека
	bool isEmpty() const;

	// переполнение дека
	bool isFull() const;

	// количество элементов в деке
	int counter() const;

	// размер дека
	int size() const;

	// перегрузка операции присваивания
	DequeChar& operator=(const DequeChar& dequeChar);

#pragma endregion

#pragma region Дружественные функции 

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const DequeChar& dequeChar);

	// вывод линии, n - количество элементов
	friend ostream& showLine(ostream& os, int n);

#pragma endregion
};