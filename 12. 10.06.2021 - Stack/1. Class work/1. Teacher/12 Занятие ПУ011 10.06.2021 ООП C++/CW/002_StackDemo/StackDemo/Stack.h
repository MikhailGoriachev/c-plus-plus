#pragma once
#include "pch.h"

// Стек для int-значений
class Stack
{
public:
	static const int SIZE_STACK = 12;
	
private:	
	int counter_;            // счетчик элементов в стеке
	int top_;                // индекс ячейки записи - вершина стека
	int data_[SIZE_STACK];   // данные
	
public:
	Stack() :top_()
	{
		
		memset(data_, 0, sizeof(int) * SIZE_STACK);
	}

	
	Stack(const int* data, int n)
	{
		memset(data_, 0, sizeof(int) * SIZE_STACK);
		pushAll(data, n);
	}
	
	Stack(const Stack& stack) = default;
	~Stack() = default;
	Stack& operator=(const Stack& stack) = default;
	
	void push(int value);
	int pop();
	int peek();
	void pushAll(const int* data, int n);
	void clear();

	// проверка стека на опустошение (true, если стек пуст)
	bool isEmpty() const { return top_ == 0; }

	// проверкам стека на переполнение (true, если стек полон)
	bool isFull() const { return top_ == SIZE_STACK; };

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const Stack& stack);
};

