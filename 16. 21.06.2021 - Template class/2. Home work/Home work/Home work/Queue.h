#pragma once

#include "pch.h"
#include "utils.h"
#include "List.h"

// Очередь T 
template <typename T>
class Queue
{
public:

	// длина очереди по умолчанию
	static const int SIZE_DEFAULT = 10;

private:

	// указатель на массив T 
	List<T> data_;

public:

#pragma region Конструкторы и деструктор

	// конструктор по умолчанию
	Queue() = default;

	// копирующий конструктор 
	Queue(const Queue& Queue) = default;

	// дестркутор 
	~Queue() = default;

#pragma endregion

#pragma region Геттеры и сеттеры

public:

	// геттер counter_
	int getCounter() const { return data_.getCount(); }

#pragma endregion

#pragma region Методы 

	// перегрузка операции присваивания 
	Queue& operator=(const Queue& Queue) = default;

	// добавление элемента в очередь
	void enqueue(T value);

	// добавление массива в очередь
	void enqueueAll(T* arr, int size);

	// просмотр элемента вершины очереди
	T front() const;

	// взятие элемента из очереди
	T dequeue();

	// отчистка очереди
	void clear();

	// опустошение очереди
	bool isEmpty() const;

#pragma endregion

#pragma region Дружественные функции

	friend ostream& operator<<(ostream& os, const Queue<T>& Queue)
	{
		// если очередь пуста
		if (Queue.getCounter() == 0)
		{
			os << "очередь пуста";
		}

		else
		{
			os << Queue.data_;

			os << "\n";
		}

		return os;
	}

#pragma endregion

	// вывод Deque (Goods) в цвете
	friend void QueueGoodsOut(Queue<Goods>& queue, int positionMin, int positionMax);

#pragma endregion
};

#pragma region Конструкторы и деструктор

#pragma endregion

#pragma region Методы 
// добавление элемента в очередь
template <typename T>
void Queue<T>::enqueue(T value)
{
	data_.add(value);
}

// добавление массива в очередь
template <typename T>
void Queue<T>::enqueueAll(T* arr, int size)
{
	data_.addAll(arr, size);
}

// просмотр элемента вершины очереди
template <typename T>
T Queue<T>::front() const
{
	// если очередь опустошена
	if (isEmpty())
		throw exception("Queue: очередь пуста");

	return data_.get(0);
}

// взятие элемента из очереди
template <typename T>
T Queue<T>::dequeue()
{
	// копия значение элемента
	T n = data_.get(0);

	data_.removeAt(0);

	return n;
}

// отчистка очереди
template <typename T>
void Queue<T>::clear()
{
	data_.clear();
}

// опустошение очереди
template <typename T>
bool Queue<T>::isEmpty() const { return data_.getCount() == 0; }

#pragma endregion