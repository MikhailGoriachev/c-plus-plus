#pragma once

#include "Plane.h"

class StackPlane
{
public:

	// размер стека по умолчанию
	static const int SIZE_DEFAULT = 10;

private:

	// вершина 
	int top_;

	// указатель на массив объектов Plane
	Plane planes_[SIZE_DEFAULT];

	// максимальный размер стека 
	int size_ = SIZE_DEFAULT;

	// сеттер size_
	void setSize(int size)
	{
		// если size меньше или равно 0 
		if (size <= 0)
		{
			exception("Заданный размер стека должен быть больше нуля");
		}

		size_ = size;
	}

public:

#pragma region Конструкторы и декструктор

	// конструктор по умолчанию 
	StackPlane() :top_(), size_(SIZE_DEFAULT) {};

	// копирующий конструктор 
	StackPlane(const StackPlane& stackPlane) = default;

	// деструктор 
	~StackPlane() = default;

#pragma endregion

#pragma region Методы

	// положить в стек
	void push(Plane& plane)
	{
		if (isFull())
			throw exception("Stack: стек переполнен!");

		planes_[top_++] = plane;
	}

	// положить в стек пассив
	void pushAll(Plane* planeArr, int size)
	{
		for(int i = 0; i < size; i++)
		{
			push(planeArr[i]);
		}
	}

	// посмотреть вершину
	Plane peek()
	{
		// если стек опустошён
		if (isEmpty())
			throw exception("Stack: стек пуст!");

		return planes_[top_ - 1];
	}

	// взять из стека 
	Plane pop()
	{
		// если стек опустошён
		if (isEmpty())
			throw exception("Stack: стек пуст!");

		return planes_[--top_];
	}

	// переполнение стека 
	bool isFull()
	{
		return top_ == size_;
	}

	// опустошение стека 
	bool isEmpty()
	{
		return top_ == 0;
	}

	// отчистка стека 
	void clear()
	{
		top_ = 0;
	}

#pragma endregion

#pragma region Сеттеры и геттеры

	// геттер size_
	int getSize() const { return size_; }

#pragma endregion 

#pragma region Перегрузка операций

	// перегрузка операции присваивания
	StackPlane& operator=(const StackPlane stackPlane)
	{
		// создание копии объекта StackPlane
		StackPlane* newStack = new StackPlane(stackPlane);

		// копирование полей 
		top_ = stackPlane.top_;
		size_ = stackPlane.size_;

		// копирование элементов массива 
		for (size_t i = 0; i < size_; i++)
		{
			planes_[i] = stackPlane.planes_[i];
		}

		return *newStack;
	}

#pragma endregion

#pragma region Дружественные функции

	//  перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, StackPlane& stack);

#pragma endregion

};