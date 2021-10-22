#pragma once
#include "pch.h"

class Stack
{
	static const int STACK_SIZE = 12;
	
	int top_;                // ������� ����� 
	int data_[STACK_SIZE];   // ������ �����

public:
	Stack():top_() {}
	
	Stack(int *data, int n):top_()
	{
		pushAll(data, n);
	}
	
	Stack(const Stack& stack) = default;
	~Stack() = default;
	Stack &operator=(const Stack& stack) = default;

	// ��������� � ���� �����
	void push(int value)
	{
		// ������ �� ������������ ��������
		if (isFull())
			throw exception("Stack: ���� �����");

		// ������ �� ������� �����
		data_[top_++] = value;
	} // push

	// ��������� � ���� ������ �����
	void pushAll(int *data, int n)
	{
		for (int i = 0; i < n; ++i)
			push(data[i]);
	} // pushAll

	// ������ ������� �����
	int pop()
	{
		// ������ �� ������������ ��������
		if (isEmpty())
			throw exception("Stack: ���� ����");

		// ������ ������� �����
		return data_[--top_];
	} // pop

	// �������� ������� �����
	int peek()
	{
		// ������ �� ������������ ��������
		if (isEmpty())
			throw exception("Stack: ���� ����");
		
		// ������ ������� �����
		return data_[top_-1];
	} // peek

	// ������� �����
	void clear() {
		top_ = 0; 
	} // clear

	// �������� ��������� �����
	// ������������ 
	bool isFull() const { return top_ == STACK_SIZE; } // isFull

	// �����������
	bool isEmpty() const { return top_ == 0; } // isEmpty

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const Stack& stack);
};
