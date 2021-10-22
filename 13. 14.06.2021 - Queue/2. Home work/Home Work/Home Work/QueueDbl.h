#pragma once

#include "pch.h"
#include "utils.h"

// Очередь double 
class QueueDbl
{
public:

	// длина очереди по умолчанию
	static const int SIZE_DEFAULT = 10;

private:

	// индекс начала 
	int front_;

	// индекс конца
	int back_;

	// указатель на массив double 
	double* data_;

	// счётчик элементов в очереди
	int counter_;

	// длина очереди 
	int size_;

public:

#pragma region Конструкторы и деструктор

	// конструктор по умолчанию
	QueueDbl() :front_(), back_(), data_(new double[SIZE_DEFAULT]), counter_(), size_(SIZE_DEFAULT) {};

	// конструктор инициализирующий
	explicit QueueDbl(int size);

	// копирующий конструктор 
	QueueDbl(const QueueDbl& queueDbl);

	// дестркутор 
	~QueueDbl();

#pragma endregion

#pragma region Геттеры и сеттеры

private:

	// сеттер size_
	void setSize(int size);

public:

	// геттер size_
	int getSize() const { return size_; }

	// геттер counter_
	int getCounter() const { return counter_; }

#pragma endregion

#pragma region Методы 

	// перегрузка операции присваивания 
	QueueDbl& operator=(const QueueDbl& queueDbl);

	// добавление элемента в очередь
	void enqueue(double value);

	// добавление массива в очередь
	void enqueueAll(double* arr, int size);

	// просмотр элемента вершины очереди
	double front() const;

	// просмотр элемента конца очереди
	double back() const;

	// взятие элемента из очереди
	double dequeue();

	// отчистка очереди
	void clear();

	// опустошение очереди
	bool isEmpty() const;

	// переполнение очереди
	bool isFull() const;

#pragma endregion

#pragma region Дружественные функции
	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const QueueDbl& queueDbl);

	// вывод элементов
	friend ostream& showElem(ostream& os, const QueueDbl& queueDbl);

	// вывод горизонтальной линии
	friend ostream& showLine(ostream& os, const QueueDbl& queueDbl);

	// вывод индекса элементов
	friend ostream& showIndex(ostream& os, const QueueDbl& queueDbl);

	// вывод максимального размера
	friend ostream& showSize(ostream& os, const QueueDbl& queueDbl);

	// вывод количества элементов
	friend ostream& showCounter(ostream& os, const QueueDbl& queueDbl);
#pragma endregion
};