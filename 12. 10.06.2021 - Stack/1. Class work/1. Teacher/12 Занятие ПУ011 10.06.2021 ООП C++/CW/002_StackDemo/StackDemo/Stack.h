#pragma once
#include "pch.h"

// ���� ��� int-��������
class Stack
{
public:
	static const int SIZE_STACK = 12;
	
private:	
	int counter_;            // ������� ��������� � �����
	int top_;                // ������ ������ ������ - ������� �����
	int data_[SIZE_STACK];   // ������
	
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

	// �������� ����� �� ����������� (true, ���� ���� ����)
	bool isEmpty() const { return top_ == 0; }

	// ��������� ����� �� ������������ (true, ���� ���� �����)
	bool isFull() const { return top_ == SIZE_STACK; };

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const Stack& stack);
};

