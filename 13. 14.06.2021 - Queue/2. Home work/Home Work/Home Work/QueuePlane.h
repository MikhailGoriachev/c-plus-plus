#pragma once

#include "pch.h"
#include "Plane.h"
#include "QueuePlane.h"

// очередь Plane
class QueuePlane
{
public:

	// размер очереди по умолчанию
	static const int SIZE_DEFAULT = 10;

private:

	// начало
	int front_;

	// конец
	int back_;

	// размер массива Plane
	int size_;

	// массив Plane
	Plane* data_;

	// текущий размер очереди
	int counter_;

public:

#pragma region  онструкторы и деструктор 

	// конструктор по умолчанию
	QueuePlane() : front_(), back_(), size_(SIZE_DEFAULT), data_(new Plane[SIZE_DEFAULT]), counter_() {};

	// инициализирующий конструктор 
	explicit QueuePlane(int size);

	// копирующий конструктор
	QueuePlane(const QueuePlane& queuePlane);

#pragma endregion

#pragma region —еттеры и геттеры

private:
	// сеттер size_
	void setSize(int size);

public:

	// геттер size_
	int getSize() const;

	// геттер counter_
	int getCounter() const;

#pragma endregion

#pragma region ћетоды

	// перегрузка операции присваивани€ 
	QueuePlane& operator=(const QueuePlane& queuePlane);

	// добавление в очередь элемента 
	void enqueue(Plane plane);

	// добавление в очередь массива 
	void enqueueAll(Plane* planeArr, int size);

	// просмотр начала очереди
	Plane front() const;

	// просмотр конца очереди
	// Plane back() const;

	// вз€тие элемента с начала очереди
	Plane dequeue();

	// отчистка очереди
	void clear();

	// опустошение очереди
	bool isEmpty() const;

	// переполнение очереди
	bool isFull() const;

#pragma endregion

#pragma region ƒружественные функции

	// перегрузка вывода 
	friend ostream& operator<<(ostream& os, QueuePlane& queuePlane);

#pragma endregion
};

