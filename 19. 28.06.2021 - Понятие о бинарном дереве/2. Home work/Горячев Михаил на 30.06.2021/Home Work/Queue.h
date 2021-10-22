#pragma once

#include "pch.h"
#include "utils.h"
#include "List.h"

// ������� T 
template <typename T>
class Queue
{
	// ��������� �� ������ T 
	List<T> data_;

public:

	// ������ ��������    
	template <typename TT>
	class Iterator
	{
		List<T>::Node<T>* node_;       // ��������� �� ������� ����
		int     position_;    // ������� ����, ������ ����
		const List<T>& list_; // ����������� ������ �� ������ �� �������� ������� ��������

	public:
		// ������������ � ����������
		Iterator() = default;
		Iterator(const Queue<T>& queue) :
			node_(queue.data_.getHead()),
			position_(),
			list_(queue.data_)
		{ }
		Iterator(const Iterator& iterator) = default;
		~Iterator() = default;

		// ���������� �������� =
		Iterator& operator=(const Iterator& iterator) = default;

		// ������ � ������������� �������� ��� ������ ���������

		// ������� � ������ ������
		int begin()
		{
			node_ = list_.getHead();
			position_ = 0;

			return position_;
		} // begin

		// ������� ������� �� ��������� ��������� �������� ������
		int end() const { return list_.getCount(); }

		// �������� ���������
		bool operator!=(int position) const { return position_ != position; }
		bool operator==(int position) const { return position_ == position; }

		// ������� � ���������� ���� ������
		Iterator& operator++()
		{
			if (position_ >= list_.getCount())
				throw exception("List. ����� �� ������� ������");

			// ���������� ������� �� ��������� ����
			++position_;
			node_ = node_->getNext();

			// ������� ������ �� ����
			return *this;
		} // operator++

		// ���������� �������������, �������������� �������� ���������� ������ �� ���� ������
		T operator*()
		{
			if (position_ >= list_.getCount())
				throw exception("List. ����� �� ������� ������");

			return *node_->getPayload();
		} // operator*
	};


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