#pragma once
#include "pch.h"

class Stack
{
	static const int STACK_SIZE = 12;
	
	int top_;                // вершина стека 
	int data_[STACK_SIZE];   // данные стека

public:
	Stack():top_() {}
	
	Stack(int *data, int n):top_()
	{
		pushAll(data, n);
	}
	
	Stack(const Stack& stack) = default;
	~Stack() = default;
	Stack &operator=(const Stack& stack) = default;

	// поместить в стек число
	void push(int value)
	{
		// защита от некорректной операции
		if (isFull())
			throw exception("Stack: стек полон");

		// запись на вершину стека
		data_[top_++] = value;
	} // push

	// поместить в стек массив чисел
	void pushAll(int *data, int n)
	{
		for (int i = 0; i < n; ++i)
			push(data[i]);
	} // pushAll

	// чтение вершины стека
	int pop()
	{
		// защита от некорректной операции
		if (isEmpty())
			throw exception("Stack: стек пуст");

		// чтение вершины стека
		return data_[--top_];
	} // pop

	// просмотр вершины стека
	int peek()
	{
		// защита от некорректной операции
		if (isEmpty())
			throw exception("Stack: стек пуст");
		
		// чтение вершины стека
		return data_[top_-1];
	} // peek

	// очистка стека
	void clear() {
		top_ = 0; 
	} // clear

	// контроль состояния стека
	// переполнение 
	bool isFull() const { return top_ == STACK_SIZE; } // isFull

	// опустошение
	bool isEmpty() const { return top_ == 0; } // isEmpty

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const Stack& stack);
};
