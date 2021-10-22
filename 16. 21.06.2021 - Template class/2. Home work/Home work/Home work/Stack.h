#pragma once

#include "pch.h"
#include "Stack.h"

template <typename T>
class Stack
{
	// ������ ����� �� ���������
	static const int DEFAULT_SIZE = 12;

	// ������ �������
	int top_;

	// ����� ����� 
	int size_;

	// ��������� �� ������ ����� 
	T* data_ = nullptr;

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
	Stack() :top_(), size_(DEFAULT_SIZE), data_(new T[DEFAULT_SIZE]) {}

	// ����������� ����������������
	explicit Stack(int size): top_()
	{
		// ��������� ����� ����� 
		setSize(size);

		// ��������� ������ ��� ����� 
		data_ = new T[size_];
	}

	// ���������� �����������
	Stack(const Stack& stack)
	{
		// �������� ������ �� ������� ������� ����� 
		delete[] data_;

		// ��������� ������ ��� ����� ������
		data_ = new T[stack.size_];

		// ����������� ��������
		for (int i = 0; i < stack.size_; i++)
		{
			data_[i] = stack.data_[i];
		}

		// ����� �������
		size_ = stack.size_;

		top_ = stack.top_;
	}

	// ����������
	~Stack()
	{
		delete[] data_;
	}
#pragma endregion

#pragma region ������� � �������

	// ������ size_
	int getSize() const { return size_; }

	// ������� ���������� ���������
	int getCounter() const { return top_; }

#pragma endregion

#pragma region ������

	// ��������� � ����
	void push(T value)
	{
		// ���� ���� ����������
		if (isFull())
			throw exception("Stack: ���� ����������!");

		data_[top_++] = value;
	}

	// ��������� � ���� ������
	void pushAll(T* arr, int size)
	{
		// ����������� �����
		for (size_t i = 0; i < size; i++)
		{
			push(arr[i]);
		}
	}

	// ����� �� ����� 
	T pop()
	{
		// ���� ���� ���������
		if (isEmpty())
			throw exception("Stack: ���� ����!");


		return data_[--top_];
	}

	// ���������� ������� ����� 
	T peek()
	{
		// ���� ���� ���������
		if (isEmpty())
			throw exception("Stack: ���� ����!");

		return data_[top_ - 1];
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
	Stack& operator=(Stack& stack)
	{
		// ��������� ������ ��� ����� ����
		Stack* newStack = new Stack(stack);

		// �������� ������ �� ������� ������� ����� 
		delete[] data_;

		// ��������� ������ ��� ����� ������
		data_ = new T[stack.size_];

		// ����������� ��������
		for (int i = 0; i < stack.size_; i++)
		{
			data_[i] = stack.data_[i];
		}

		// ����� �������
		size_ = stack.size_;

		top_ = stack.top_;

		return *newStack;
	}

#pragma endregion

#pragma region ������������� ������� 

	friend ostream& operator<<(ostream& os, Stack& stack)
	{
		if (stack.isEmpty())
		{
			os << "Stack: ���� ����";
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