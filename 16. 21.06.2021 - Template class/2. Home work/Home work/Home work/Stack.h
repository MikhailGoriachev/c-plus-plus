#pragma once

#include "pch.h"
#include "Stack.h"

template <typename T>
class Stack
{
	// размер стека по умолчанию
	static const int DEFAULT_SIZE = 12;

	// индекс вершины
	int top_;

	// длина стека 
	int size_;

	// указатель на массив стека 
	T* data_ = nullptr;

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
	Stack() :top_(), size_(DEFAULT_SIZE), data_(new T[DEFAULT_SIZE]) {}

	// конструктор инициализирующий
	explicit Stack(int size): top_()
	{
		// установка длины стека 
		setSize(size);

		// выделение пам€ти дл€ стека 
		data_ = new T[size_];
	}

	// копирующий конструктор
	Stack(const Stack& stack)
	{
		// отчистка пам€ти от старого массива стека 
		delete[] data_;

		// выделение пам€ти под новый массив
		data_ = new T[stack.size_];

		// копирование значений
		for (int i = 0; i < stack.size_; i++)
		{
			data_[i] = stack.data_[i];
		}

		// длина массива
		size_ = stack.size_;

		top_ = stack.top_;
	}

	// деструктор
	~Stack()
	{
		delete[] data_;
	}
#pragma endregion

#pragma region —еттеры и геттеры

	// геттер size_
	int getSize() const { return size_; }

	// текущее количество элементов
	int getCounter() const { return top_; }

#pragma endregion

#pragma region ћетоды

	// поместить в стек
	void push(T value)
	{
		// если стек переполнен
		if (isFull())
			throw exception("Stack: стек переполнен!");

		data_[top_++] = value;
	}

	// поместить в стек массив
	void pushAll(T* arr, int size)
	{
		// копирование стека
		for (size_t i = 0; i < size; i++)
		{
			push(arr[i]);
		}
	}

	// вз€ть из стека 
	T pop()
	{
		// если стек опустошЄн
		if (isEmpty())
			throw exception("Stack: стек пуст!");


		return data_[--top_];
	}

	// посмотреть вершину стека 
	T peek()
	{
		// если стек опустошЄн
		if (isEmpty())
			throw exception("Stack: стек пуст!");

		return data_[top_ - 1];
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
	Stack& operator=(Stack& stack)
	{
		// выделение пам€ти под новый стек
		Stack* newStack = new Stack(stack);

		// отчистка пам€ти от старого массива стека 
		delete[] data_;

		// выделение пам€ти под новый массив
		data_ = new T[stack.size_];

		// копирование значений
		for (int i = 0; i < stack.size_; i++)
		{
			data_[i] = stack.data_[i];
		}

		// длина массива
		size_ = stack.size_;

		top_ = stack.top_;

		return *newStack;
	}

#pragma endregion

#pragma region ƒружественные функции 

	friend ostream& operator<<(ostream& os, Stack& stack)
	{
		if (stack.isEmpty())
		{
			os << "Stack: стек пуст";
			return os;
		}

		for (size_t i = 0; i < stack.top_; i++)
		{
			os << "\n\t\t" << stack.data_[i];
		}

		return os;
	}

#pragma endregion
};