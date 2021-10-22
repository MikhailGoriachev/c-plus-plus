#pragma once

#include "Node.h" // класс узла списка (int)

// Класс список (int)
class List
{
	// счётчик узлов в списке 
	int counter_;

	// адрес начального элемента списка 
	Node* head_;

public:

#pragma region Конструкторы и деструкторы 

	// конструктор по умолчанию 
	List() : counter_(), head_() { };

	// конструктор инициализирующий
	List(int counter);

	// конструктор создающий список на базе массива 
	List(int* arr, int counter);

	// конструктор копирующий
	List(const List& list);

	// дестркутор 
	~List() { clear(); }

#pragma endregion

	// перегрузка операции присваивания 
	List& operator=(const List& list);

	// добавление узла в конец списка 
	void add(int value);

	// добавление массива узлов в конец списка 
	void addAll(int* data, int n);

	// вставка узла перед указанной позицией
	void insert(int position, int value);

	// вставка массива узлов перед указанной позицией
	void insertAll(int position, int* data, int n);

	// чтение значения узла списка по указанной позиции
	int get(int position);

	// изенение значения узла списка по указанной позиции 
	void put(int position, int value);

	// удаление узла из списка по указанной позиции 
	void removeAt(int position);

	// отчистка списка 
	void clear();

	// геттер counter_
	int getCounter() { return counter_; }

	// перегрузка операции [] для доступа к узлу списка по индексу
	Node* operator[](int position);

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const List& list);

	// вывод элементов
	friend ostream& showElem(ostream& os, const List& list);

	// вывод горизонтальной линии
	friend ostream& showLine(ostream& os, const List& list);

	// вывод индекса элементов
	friend ostream& showIndex(ostream& os, const List& list);

	// вывод количества элементов
	friend ostream& showCounter(ostream& os, const List& list);

	// вывод списка в цвете
	void showListColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr);

private:
	// вывод элементов в цвете
	void showElemColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr);

public:

};

