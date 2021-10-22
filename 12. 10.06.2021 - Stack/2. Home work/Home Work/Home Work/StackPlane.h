#pragma once

#include "Plane.h"

class StackPlane
{
public:

	// ������ ����� �� ���������
	static const int SIZE_DEFAULT = 10;

private:

	// ������� 
	int top_;

	// ��������� �� ������ �������� Plane
	Plane planes_[SIZE_DEFAULT];

	// ������������ ������ ����� 
	int size_ = SIZE_DEFAULT;

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

#pragma region ������������ � �����������

	// ����������� �� ��������� 
	StackPlane() :top_(), size_(SIZE_DEFAULT) {};

	// ���������� ����������� 
	StackPlane(const StackPlane& stackPlane) = default;

	// ���������� 
	~StackPlane() = default;

#pragma endregion

#pragma region ������

	// �������� � ����
	void push(Plane& plane)
	{
		if (isFull())
			throw exception("Stack: ���� ����������!");

		planes_[top_++] = plane;
	}

	// �������� � ���� ������
	void pushAll(Plane* planeArr, int size)
	{
		for(int i = 0; i < size; i++)
		{
			push(planeArr[i]);
		}
	}

	// ���������� �������
	Plane peek()
	{
		// ���� ���� ���������
		if (isEmpty())
			throw exception("Stack: ���� ����!");

		return planes_[top_ - 1];
	}

	// ����� �� ����� 
	Plane pop()
	{
		// ���� ���� ���������
		if (isEmpty())
			throw exception("Stack: ���� ����!");

		return planes_[--top_];
	}

	// ������������ ����� 
	bool isFull()
	{
		return top_ == size_;
	}

	// ����������� ����� 
	bool isEmpty()
	{
		return top_ == 0;
	}

	// �������� ����� 
	void clear()
	{
		top_ = 0;
	}

#pragma endregion

#pragma region ������� � �������

	// ������ size_
	int getSize() const { return size_; }

#pragma endregion 

#pragma region ���������� ��������

	// ���������� �������� ������������
	StackPlane& operator=(const StackPlane stackPlane)
	{
		// �������� ����� ������� StackPlane
		StackPlane* newStack = new StackPlane(stackPlane);

		// ����������� ����� 
		top_ = stackPlane.top_;
		size_ = stackPlane.size_;

		// ����������� ��������� ������� 
		for (size_t i = 0; i < size_; i++)
		{
			planes_[i] = stackPlane.planes_[i];
		}

		return *newStack;
	}

#pragma endregion

#pragma region ������������� �������

	//  ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, StackPlane& stack);

#pragma endregion

};