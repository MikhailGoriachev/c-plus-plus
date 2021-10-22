#pragma once
#include "pch.h"
#include "Colors.h"
#include "Utils.h"
#include "List.h"

class Goods;

// Дек - двусторонняя очередь (T)
template<typename T>
class Deque
{
	// указатель на массив-контейнер (T)
	List<T> data_;

public:

#pragma region Конструкторы и деструктор 

	// конструктор по умолчанию
	Deque() = default;

	// конструтор на основе массива 
	Deque(T* arrT, int size);

	// копирующий конструктор
	Deque(const Deque& Deque) = default;

	// деструктор
	~Deque() = default;

#pragma endregion

#pragma region Методы

	// добавить в начало дека
	void shift(T value);

	// добавление массива в начало дека 
	void shiftAll(T* arrT, int size);

	// посмотреть начальный элемент дека
	T front() const;

	// взять элемент с начала дека
	T unshift();

	// добавить в конец дека
	void push(T value);

	// добавление массива в конец дека
	void pushAll(T* arrT, int size);

	// посмотреть последний элемент дека
	T back() const;

	// взять элемент с конца дека
	T pop();

	// отчистка дека
	void clear();

	// опустошение дека
	bool isEmpty() const;

	// количество элементов в деке
	int counter() const;

	// перегрузка операции присваивания
	Deque& operator=(const Deque& Deque);

#pragma endregion

#pragma region Дружественные функции 

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const Deque& deque)
	{
		int counter = deque.counter();

		// если дек пуст
		if (counter == 0)
			os << "Дек пуст\n";

		// если стек заполнен
		else
		{
			os << deque.data_ << "\n";
		}


		return os;
	}

	// вывод Deque (int)
	// friend void DequeIntOut(const Deque<int>& Deque);

	// вывод Deque (char)
	// friend void DequeCharOut(const Deque<char>& Deque);

	// вывод Deque (Goods)
	friend void DequeGoodsOut(Deque<Goods>& Deque, int positionMin, int positionMax);


#pragma endregion
};

#pragma region КЛАССА

#pragma region Конструкторы и деструктор 

// конструтор на основе массива 
template<typename T>
Deque<T>::Deque(T* arr, int size)
{
	// если передаваемый size меньше или равен нулю
	if (size <= 0)
		throw exception("Deque: Длина передаваемого массива должна быть больше нуля!");

	// если указатель на массив arr имеет значение nullptr
	if (arr == nullptr)
		throw exception("Deque: Передаваемого массива не существует!");

	// копирование массива 
	data_.addAll(arr, size);
}

#pragma endregion

#pragma region Методы

#pragma region Операции с началом дека

// добавить в начало дека
template<typename T>
void Deque<T>::shift(T value)
{
	// установка элемента в начало дека
	data_.insert(0, value);
}

// добавление массива в начало дека
template<typename T>
void Deque<T>::shiftAll(T* arr, int size)
{
	// если передаваемый size меньше или равен нулю
	if (size <= 0)
		throw exception("Deque: Длина передаваемого массива должна быть больше нуля!");

	// если указатель на массив arr имеет значение nullptr
	if (arr == nullptr)
		throw exception("Deque: Передаваемого массива не существует!");

	data_.insertAll(0, arr, size);
}

// посмотреть начальный элемент дека
template<typename T>
T Deque<T>::front() const
{
	// если дек пуст
	if (isEmpty())
		throw exception("Deque: Дек пуст!");

	// возвращение начального элемента дека
	return data_.get(0);
}

// взять элемент с начала дека
template<typename T>
T Deque<T>::unshift()
{
	// если дек пуст
	if (isEmpty())
		throw exception("Deque: Дек пуст!");

	T save = data_.get(0);

	data_.removeAt(0);

	// возвращение и удаление нулевого элемента
	return save;
}

#pragma endregion

// ------------------------------------------------------------------------------

#pragma region Операции с концом дека

// добавить в конец дека
template<typename T>
void Deque<T>::push(T value)
{
	// добавление элемента и увеличение back_
	data_.add(value);
}

// добавление массива в конец дека 
template<typename T>
void Deque<T>::pushAll(T* arr, int size)
{
	// если длина массива меньше или равна нулю
	if (size <= 0)
		throw exception("Deque: Длина передаваемого массива должна быть больше нуля!");

	// если указатель на массив arr имеет значение nullptr
	if (arr == nullptr)
		throw exception("Deque: Передаваемого массива не существует!");

	// добавление элементов в конец дека
	data_.addAll(arr, size);
}

// посмотреть последний элемент дека 
template<typename T>
T Deque<T>::back() const
{
	// если дек опустошён
	if (isEmpty())
		throw exception("Deque: Дек пуст!");

	// возвращение последнего элемента
	return data_.get(data_.getCount() - 1);
}

// взять элемент с конца дека 
template<typename T>
T Deque<T>::pop()
{
	// если дек пуст
	if (isEmpty())
		throw exception("Deque: Дек пуст!");

	T save = data_.get(data_.getCount() - 1);

	data_.removeAt(data_.getCount() - 1);

	// уменьшение back_ и возвращение последнего элемента
	return save;
}

#pragma endregion

// отчистка дека
template<typename T>
void Deque<T>::clear()
{
	data_.clear();
}

// опустошение дека 
template<typename T>
bool Deque<T>::isEmpty() const
{
	return data_.isEmpty();
}

// длина дека 
template<typename T>
int Deque<T>::counter() const
{
	return data_.getCount();
}

// перегрузка операции присваивания
template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& deque)
{
	// защита от самоприсваивания
	if (this == &deque) return *this;

	data_ = deque.data_();

	// возвращение ссылки на наш объект
	return *this;
}

#pragma endregion

#pragma endregion