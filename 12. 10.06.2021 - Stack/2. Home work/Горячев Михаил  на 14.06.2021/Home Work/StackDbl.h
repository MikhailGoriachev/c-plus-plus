#pragma once

#include "pch.h"
#include "StackDbl.h"


class StackDbl
{
	// размер стека по умолчанию
	static const int DEFAULT_SIZE = 12;

	// индекс вершины
	int top_;

	// длина стека 
	int size_;

	// указатель на массив стека 
	double* arr_ = nullptr;

	// сеттер size_
	void setSize(int size)
	{
		// если size меньше или равно 0 
		if (size <= 0)
		{
			exception("«аданный размер стека должен быть больше нул€");
		}

		size_ = size;
	}

public:
	
#pragma region  онструкторы и деструктор

	// конструктор по умолчанию
	StackDbl() :top_(), size_(DEFAULT_SIZE), arr_(new double[DEFAULT_SIZE]) {}

	// конструктор инициализирующий
	explicit StackDbl(int size)
	{
		// установка длины стека 
		setSize(size);

		// выделение пам€ти дл€ стека 
		arr_ = new double[size_];
	}

	// копирующий конструктор
	StackDbl(const StackDbl& stack)
	{
		// отчистка пам€ти от старого массива стека 
		delete[] arr_;

		// выделение пам€ти под новый массив
		arr_ = new double[stack.size_];

		// копирование значений
		memcpy(arr_, stack.arr_, stack.size_ * sizeof(double));

		// длина массива
		size_ = stack.size_;
	}

	// деструктор
	~StackDbl()
	{
		delete[] arr_;
	}
#pragma endregion

#pragma region —еттеры и геттеры

	// геттер size_
	int getSize() const { return size_; }

#pragma endregion

#pragma region ћетоды

	// поместить в стек
	void push(double value)
	{
		// если стек переполнен
		if (isFull())
			throw exception("Stack: стек переполнен!");

		arr_[top_++] = value;
	}

	// поместить в стек массив
	void pushAll(double* arr, int size)
	{
		// копирование стека
		for (size_t i = 0; i < size; i++)
		{
			push(arr[i]);
		}
	}

	// вз€ть из стека 
	double pop()
	{
		// если стек опустошЄн
		if (isEmpty())
			throw exception("Stack: стек пуст!");


		return arr_[--top_];
	}

	// посмотреть вершину стека 
	double peek()
	{
		// если стек опустошЄн
		if (isEmpty())
			throw exception("Stack: стек пуст!");

		return arr_[top_ - 1];
	}

	// отчистка стека
	void clear() { top_ = 0; }

	// переполнение стека
	bool isFull() { return top_ == size_; }

	// опустошение стека 
	bool isEmpty() { return top_ == 0; }

#pragma endregion

#pragma region ѕерегрузка операций

	// перегрузка функции присваивани€
	StackDbl& operator=(StackDbl& stack)
	{
		// выделение пам€ти под новый стек
		StackDbl* newStack = new StackDbl(stack);

		// отчистка пам€ти от старого массива стека 
		delete[] arr_;

		// выделение пам€ти под новый массив
		arr_ = new double[stack.size_];

		// копирование значений
		memcpy(arr_, stack.arr_, stack.size_ * sizeof(double));

		// длина массива
		size_ = stack.size_;

		return *newStack;
	}

#pragma endregion

#pragma region ƒружественные функции 

	friend ostream& operator<<(ostream& os, StackDbl& stack);

#pragma endregion
};