#pragma once

#include "pch.h"
#include "StackDbl.h"


class StackDbl
{
	// ������ ����� �� ���������
	static const int DEFAULT_SIZE = 12;

	// ������ �������
	int top_;

	// ����� ����� 
	int size_;

	// ��������� �� ������ ����� 
	double* arr_ = nullptr;

	// ������ size_
	void setSize(int size)
	{
		// ���� size ������ ��� ����� 0 
		if (size <= 0)
		{
			exception("�������� ������ ����� ������ ���� ������ ����");
		}

		size_ = size;
	}

public:
	
#pragma region ������������ � ����������

	// ����������� �� ���������
	StackDbl() :top_(), size_(DEFAULT_SIZE), arr_(new double[DEFAULT_SIZE]) {}

	// ����������� ����������������
	explicit StackDbl(int size)
	{
		// ��������� ����� ����� 
		setSize(size);

		// ��������� ������ ��� ����� 
		arr_ = new double[size_];
	}

	// ���������� �����������
	StackDbl(const StackDbl& stack)
	{
		// �������� ������ �� ������� ������� ����� 
		delete[] arr_;

		// ��������� ������ ��� ����� ������
		arr_ = new double[stack.size_];

		// ����������� ��������
		memcpy(arr_, stack.arr_, stack.size_ * sizeof(double));

		// ����� �������
		size_ = stack.size_;
	}

	// ����������
	~StackDbl()
	{
		delete[] arr_;
	}
#pragma endregion

#pragma region ������� � �������

	// ������ size_
	int getSize() const { return size_; }

#pragma endregion

#pragma region ������

	// ��������� � ����
	void push(double value)
	{
		// ���� ���� ����������
		if (isFull())
			throw exception("Stack: ���� ����������!");

		arr_[top_++] = value;
	}

	// ��������� � ���� ������
	void pushAll(double* arr, int size)
	{
		// ����������� �����
		for (size_t i = 0; i < size; i++)
		{
			push(arr[i]);
		}
	}

	// ����� �� ����� 
	double pop()
	{
		// ���� ���� ���������
		if (isEmpty())
			throw exception("Stack: ���� ����!");


		return arr_[--top_];
	}

	// ���������� ������� ����� 
	double peek()
	{
		// ���� ���� ���������
		if (isEmpty())
			throw exception("Stack: ���� ����!");

		return arr_[top_ - 1];
	}

	// �������� �����
	void clear() { top_ = 0; }

	// ������������ �����
	bool isFull() { return top_ == size_; }

	// ����������� ����� 
	bool isEmpty() { return top_ == 0; }

#pragma endregion

#pragma region ���������� ��������

	// ���������� ������� ������������
	StackDbl& operator=(StackDbl& stack)
	{
		// ��������� ������ ��� ����� ����
		StackDbl* newStack = new StackDbl(stack);

		// �������� ������ �� ������� ������� ����� 
		delete[] arr_;

		// ��������� ������ ��� ����� ������
		arr_ = new double[stack.size_];

		// ����������� ��������
		memcpy(arr_, stack.arr_, stack.size_ * sizeof(double));

		// ����� �������
		size_ = stack.size_;

		return *newStack;
	}

#pragma endregion

#pragma region ������������� ������� 

	friend ostream& operator<<(ostream& os, StackDbl& stack);

#pragma endregion
};