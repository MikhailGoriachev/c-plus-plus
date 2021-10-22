#pragma once

#include "pch.h"

// ����������� ��������� ����� ��� ������ � ��������� �����
// �������� ������ ����������� ������ sort(), foreach()
template<typename T>
class Container
{
protected:

	// ������
	T* data_;

	// ������ ������� ������
	int size_;

public:

#pragma region ������������, ���������� � �������� ������������

	// ����������� �� ���������
	Container() : data_(), size_() { };

	// ���������������� ����������� 
	Container(T* data, int n)
	{
		// ��������� ������
		setData(data, n);
	}

	// ���������� ����������� 
	Container(const Container& container) : data_(), size_()
	{
		if (container.size_ > 0)
		{
			// ��������� ������ ��� ������
			data_ = new T[container.size_];

			// ����� �������
			size_ = container.size_;
		}
	}

	// ���������� 
	virtual ~Container() 
	{
		delete[]data_;
	};

	// ���������� �������� ������������
	Container& operator=(const Container& container)
	{
		// ���� ������ ��� �������� �� �������� ��
		if (data_ != nullptr)
			delete[] data_;

		// ��������� ������ ��� ����� ������
		data_ = new T[container.size_];

		// ��������� ����� 
		size_ = container.size_;

		// ����������� �������� 
		memcpy(data_, container.data_, sizeof(T) * size_);
	}

#pragma endregion

#pragma region ������� � �������

	// ������ ������ 
	virtual void setData(T* data, int n)
	{
		// ���� ������ ������� ����� ��� ������ 0
		if (n <= 0)
			throw exception("Container: ������������ ������!");

		// ���� ������ ��� �������� �� �������� ��
		if (data_ != nullptr)
			delete[] data_;

		// ��������� ������ ��� ����� ������
		data_ = new T[n];

		// ��������� ����� 
		size_ = n;

		// ����������� �������� 
		memcpy(data_, data, sizeof(T) * n);
	}

	// ������ size_
	int getSize() const { return size_; }

#pragma endregion

#pragma region ������

	// ���������� �������� ��������������
	T& operator[](int index) 
	{
		// ���� ������ �� ��������� 
		if (index > size_ || index < 0)
			throw exception("Container: ������ �����������");

		return data_[index];
	}

	// ����� sort() � ��� ���������� ������ � ����������
	virtual void sort() = 0;

	// ����� foreach() � ��� ������������ ��������� ����������
	virtual void foreach() = 0;

	// ����� 
	virtual void show() 
	{
		for (int i = 0; i < size_; i++)
		{
			cout << data_[i] << " ";
		}
	};

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const Container<T>& container)
	{
		for (int i = 0; i < container.size_; i++)
		{
			os << container[i] << " ";
		}
	}

#pragma endregion

};

