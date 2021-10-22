#pragma once

#include "pch.h"
#include "utils.h"
#include "List.h"

// Очередь T 
template <typename T>
class Queue
{
	// указатель на массив T 
	List<T> data_;

public:

	// Прямой итератор    
	template <typename TT>
	class Iterator
	{
		List<T>::Node<T>* node_;       // указатель на текущий узел
		int     position_;    // позиция узла, индекс узла
		const List<T>& list_; // константная ссылка на список по которому ведется итерация

	public:
		// конструкторы и деструктор
		Iterator() = default;
		Iterator(const Queue<T>& queue) :
			node_(queue.data_.getHead()),
			position_(),
			list_(queue.data_)
		{ }
		Iterator(const Iterator& iterator) = default;
		~Iterator() = default;

		// перегрузка операции =
		Iterator& operator=(const Iterator& iterator) = default;

		// методы и перегруженные операции для работы итератора

		// переход в начало списка
		int begin()
		{
			node_ = list_.getHead();
			position_ = 0;

			return position_;
		} // begin

		// вернуть позицию за последней доступной позицией списка
		int end() const { return list_.getCount(); }

		// операции сравнения
		bool operator!=(int position) const { return position_ != position; }
		bool operator==(int position) const { return position_ == position; }

		// переход к следующему узлу списка
		Iterator& operator++()
		{
			if (position_ >= list_.getCount())
				throw exception("List. Выход за пределы списка");

			// собственно переход на следующий узел
			++position_;
			node_ = node_->getNext();

			// вернуть ссылку на узел
			return *this;
		} // operator++

		// перегрузка разыменования, разыменованный итератор возвращает ссылку на узел списка
		T operator*()
		{
			if (position_ >= list_.getCount())
				throw exception("List. Выход за пределы списка");

			return *node_->getPayload();
		} // operator*
	};


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