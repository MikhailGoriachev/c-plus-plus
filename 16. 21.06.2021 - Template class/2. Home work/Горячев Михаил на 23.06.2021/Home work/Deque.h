#pragma once
#include "pch.h"
#include "Colors.h"
#include "Utils.h"
#include "List.h"

class Goods;

// ��� - ������������ ������� (T)
template<typename T>
class Deque
{
	// ��������� �� ������-��������� (T)
	List<T> data_;

public:

#pragma region ������������ � ���������� 

	// ����������� �� ���������
	Deque() = default;

	// ���������� �� ������ ������� 
	Deque(T* arrT, int size);

	// ���������� �����������
	Deque(const Deque& Deque) = default;

	// ����������
	~Deque() = default;

#pragma endregion

#pragma region ������

	// �������� � ������ ����
	void shift(T value);

	// ���������� ������� � ������ ���� 
	void shiftAll(T* arrT, int size);

	// ���������� ��������� ������� ����
	T front() const;

	// ����� ������� � ������ ����
	T unshift();

	// �������� � ����� ����
	void push(T value);

	// ���������� ������� � ����� ����
	void pushAll(T* arrT, int size);

	// ���������� ��������� ������� ����
	T back() const;

	// ����� ������� � ����� ����
	T pop();

	// �������� ����
	void clear();

	// ����������� ����
	bool isEmpty() const;

	// ���������� ��������� � ����
	int counter() const;

	// ���������� �������� ������������
	Deque& operator=(const Deque& Deque);

#pragma endregion

#pragma region ������������� ������� 

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const Deque& deque)
	{
		int counter = deque.counter();

		// ���� ��� ����
		if (counter == 0)
			os << "��� ����\n";

		// ���� ���� ��������
		else
		{
			os << deque.data_ << "\n";
		}


		return os;
	}

	// ����� Deque (int)
	// friend void DequeIntOut(const Deque<int>& Deque);

	// ����� Deque (char)
	// friend void DequeCharOut(const Deque<char>& Deque);

	// ����� Deque (Goods)
	friend void DequeGoodsOut(Deque<Goods>& Deque, int positionMin, int positionMax);


#pragma endregion
};

#pragma region ������

#pragma region ������������ � ���������� 

// ���������� �� ������ ������� 
template<typename T>
Deque<T>::Deque(T* arr, int size)
{
	// ���� ������������ size ������ ��� ����� ����
	if (size <= 0)
		throw exception("Deque: ����� ������������� ������� ������ ���� ������ ����!");

	// ���� ��������� �� ������ arr ����� �������� nullptr
	if (arr == nullptr)
		throw exception("Deque: ������������� ������� �� ����������!");

	// ����������� ������� 
	data_.addAll(arr, size);
}

#pragma endregion

#pragma region ������

#pragma region �������� � ������� ����

// �������� � ������ ����
template<typename T>
void Deque<T>::shift(T value)
{
	// ��������� �������� � ������ ����
	data_.insert(0, value);
}

// ���������� ������� � ������ ����
template<typename T>
void Deque<T>::shiftAll(T* arr, int size)
{
	// ���� ������������ size ������ ��� ����� ����
	if (size <= 0)
		throw exception("Deque: ����� ������������� ������� ������ ���� ������ ����!");

	// ���� ��������� �� ������ arr ����� �������� nullptr
	if (arr == nullptr)
		throw exception("Deque: ������������� ������� �� ����������!");

	data_.insertAll(0, arr, size);
}

// ���������� ��������� ������� ����
template<typename T>
T Deque<T>::front() const
{
	// ���� ��� ����
	if (isEmpty())
		throw exception("Deque: ��� ����!");

	// ����������� ���������� �������� ����
	return data_.get(0);
}

// ����� ������� � ������ ����
template<typename T>
T Deque<T>::unshift()
{
	// ���� ��� ����
	if (isEmpty())
		throw exception("Deque: ��� ����!");

	T save = data_.get(0);

	data_.removeAt(0);

	// ����������� � �������� �������� ��������
	return save;
}

#pragma endregion

// ------------------------------------------------------------------------------

#pragma region �������� � ������ ����

// �������� � ����� ����
template<typename T>
void Deque<T>::push(T value)
{
	// ���������� �������� � ���������� back_
	data_.add(value);
}

// ���������� ������� � ����� ���� 
template<typename T>
void Deque<T>::pushAll(T* arr, int size)
{
	// ���� ����� ������� ������ ��� ����� ����
	if (size <= 0)
		throw exception("Deque: ����� ������������� ������� ������ ���� ������ ����!");

	// ���� ��������� �� ������ arr ����� �������� nullptr
	if (arr == nullptr)
		throw exception("Deque: ������������� ������� �� ����������!");

	// ���������� ��������� � ����� ����
	data_.addAll(arr, size);
}

// ���������� ��������� ������� ���� 
template<typename T>
T Deque<T>::back() const
{
	// ���� ��� ���������
	if (isEmpty())
		throw exception("Deque: ��� ����!");

	// ����������� ���������� ��������
	return data_.get(data_.getCount() - 1);
}

// ����� ������� � ����� ���� 
template<typename T>
T Deque<T>::pop()
{
	// ���� ��� ����
	if (isEmpty())
		throw exception("Deque: ��� ����!");

	T save = data_.get(data_.getCount() - 1);

	data_.removeAt(data_.getCount() - 1);

	// ���������� back_ � ����������� ���������� ��������
	return save;
}

#pragma endregion

// �������� ����
template<typename T>
void Deque<T>::clear()
{
	data_.clear();
}

// ����������� ���� 
template<typename T>
bool Deque<T>::isEmpty() const
{
	return data_.isEmpty();
}

// ����� ���� 
template<typename T>
int Deque<T>::counter() const
{
	return data_.getCount();
}

// ���������� �������� ������������
template<typename T>
Deque<T>& Deque<T>::operator=(const Deque& deque)
{
	// ������ �� ����������������
	if (this == &deque) return *this;

	data_ = deque.data_();

	// ����������� ������ �� ��� ������
	return *this;
}

#pragma endregion

#pragma endregion