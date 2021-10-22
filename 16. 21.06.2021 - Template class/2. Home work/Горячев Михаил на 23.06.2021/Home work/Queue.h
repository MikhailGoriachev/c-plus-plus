#pragma once

#include "pch.h"
#include "utils.h"
#include "List.h"

// ������� T 
template <typename T>
class Queue
{
public:

	// ����� ������� �� ���������
	static const int SIZE_DEFAULT = 10;

private:

	// ��������� �� ������ T 
	List<T> data_;

public:

#pragma region ������������ � ����������

	// ����������� �� ���������
	Queue() = default;

	// ���������� ����������� 
	Queue(const Queue& Queue) = default;

	// ���������� 
	~Queue() = default;

#pragma endregion

#pragma region ������� � �������

public:

	// ������ counter_
	int getCounter() const { return data_.getCount(); }

#pragma endregion

#pragma region ������ 

	// ���������� �������� ������������ 
	Queue& operator=(const Queue& Queue) = default;

	// ���������� �������� � �������
	void enqueue(T value);

	// ���������� ������� � �������
	void enqueueAll(T* arr, int size);

	// �������� �������� ������� �������
	T front() const;

	// ������ �������� �� �������
	T dequeue();

	// �������� �������
	void clear();

	// ����������� �������
	bool isEmpty() const;

#pragma endregion

#pragma region ������������� �������

	friend ostream& operator<<(ostream& os, const Queue<T>& Queue)
	{
		// ���� ������� �����
		if (Queue.getCounter() == 0)
		{
			os << "������� �����";
		}

		else
		{
			os << Queue.data_;

			os << "\n";
		}

		return os;
	}

#pragma endregion

	// ����� Deque (Goods) � �����
	friend void QueueGoodsOut(Queue<Goods>& queue, int positionMin, int positionMax);

#pragma endregion
};

#pragma region ������������ � ����������

#pragma endregion

#pragma region ������ 
// ���������� �������� � �������
template <typename T>
void Queue<T>::enqueue(T value)
{
	data_.add(value);
}

// ���������� ������� � �������
template <typename T>
void Queue<T>::enqueueAll(T* arr, int size)
{
	data_.addAll(arr, size);
}

// �������� �������� ������� �������
template <typename T>
T Queue<T>::front() const
{
	// ���� ������� ����������
	if (isEmpty())
		throw exception("Queue: ������� �����");

	return data_.get(0);
}

// ������ �������� �� �������
template <typename T>
T Queue<T>::dequeue()
{
	// ����� �������� ��������
	T n = data_.get(0);

	data_.removeAt(0);

	return n;
}

// �������� �������
template <typename T>
void Queue<T>::clear()
{
	data_.clear();
}

// ����������� �������
template <typename T>
bool Queue<T>::isEmpty() const { return data_.getCount() == 0; }

#pragma endregion