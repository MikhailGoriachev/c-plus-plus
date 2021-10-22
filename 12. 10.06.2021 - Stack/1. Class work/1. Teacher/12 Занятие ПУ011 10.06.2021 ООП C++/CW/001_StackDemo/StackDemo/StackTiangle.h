#pragma once
#include "pch.h"
#include "Triangle.h"

class StackTriangle
{
	static const int STACK_SIZE = 12;
	
	int top_;                // вершина стека 
	Triangle data_[STACK_SIZE];   // данные стека

public:
	StackTriangle():top_() {}
	
	StackTriangle(Triangle *data, int n)
	{
		pushAll(data, n);
	}
	
	StackTriangle(const StackTriangle& stack) = default;
	~StackTriangle() = default;
	StackTriangle&operator=(const StackTriangle& stack) = default;

	// поместить в стек 
	void push(const Triangle &value)
	{
		// защита от некорректной операции
		if (isFull())
			throw exception("Stack: стек полон");

		// запись на вершину стека
		data_[top_++] = value;
	} // push

	// поместить в стек массив 
	void pushAll(Triangle *data, int n)
	{
		for (int i = 0; i < n; ++i)
			push(data[i]);
	} // pushAll

	// чтение вершины стека
	const Triangle &pop()
	{
		// защита от некорректной операции
		if (isEmpty())
			throw exception("Stack: стек пуст");

		// чтение вершины стека
		return data_[--top_];
	} // pop

	// просмотр вершины стека
	const Triangle &peek()
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
	friend ostream& operator<<(ostream& os, const StackTriangle& stack);
};



