#pragma once
#include "pch.h"
#include "Triangle.h"

class StackTriangle
{
	static const int STACK_SIZE = 12;
	
	int top_;                // ������� ����� 
	Triangle data_[STACK_SIZE];   // ������ �����

public:
	StackTriangle():top_() {}
	
	StackTriangle(Triangle *data, int n)
	{
		pushAll(data, n);
	}
	
	StackTriangle(const StackTriangle& stack) = default;
	~StackTriangle() = default;
	StackTriangle&operator=(const StackTriangle& stack) = default;

	// ��������� � ���� 
	void push(const Triangle &value)
	{
		// ������ �� ������������ ��������
		if (isFull())
			throw exception("Stack: ���� �����");

		// ������ �� ������� �����
		data_[top_++] = value;
	} // push

	// ��������� � ���� ������ 
	void pushAll(Triangle *data, int n)
	{
		for (int i = 0; i < n; ++i)
			push(data[i]);
	} // pushAll

	// ������ ������� �����
	const Triangle &pop()
	{
		// ������ �� ������������ ��������
		if (isEmpty())
			throw exception("Stack: ���� ����");

		// ������ ������� �����
		return data_[--top_];
	} // pop

	// �������� ������� �����
	const Triangle &peek()
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
	friend ostream& operator<<(ostream& os, const StackTriangle& stack);
};



