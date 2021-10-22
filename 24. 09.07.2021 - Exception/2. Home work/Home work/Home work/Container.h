#pragma once

#include "pch.h"

// јбстрактный шаблонный класс дл€ работы с массивами чисел
// содержит чистые виртуальные методы sort(), foreach()
template<typename T>
class Container
{
protected:

	// данные
	T* data_;

	// размер массива данных
	int size_;

public:

#pragma region  онструкторы, деструктор и операци€ присваивани€

	// конструктор по умолчанию
	Container() : data_(), size_() { };

	// инициализирующий конструктор 
	Container(T* data, int n)
	{
		// установка данных
		setData(data, n);
	}

	// копирующий конструктор 
	Container(const Container& container) : data_(), size_()
	{
		if (container.size_ > 0)
		{
			// выделение пам€ти под массив
			data_ = new T[container.size_];

			// длина массива
			size_ = container.size_;
		}
	}

	// деструктор 
	virtual ~Container() 
	{
		delete[]data_;
	};

	// перегрузка операции присваивани€
	Container& operator=(const Container& container)
	{
		// если данные уже хран€тс€ то очистить их
		if (data_ != nullptr)
			delete[] data_;

		// выделение пам€ти под новый массив
		data_ = new T[container.size_];

		// установка длины 
		size_ = container.size_;

		// копирование значений 
		memcpy(data_, container.data_, sizeof(T) * size_);
	}

#pragma endregion

#pragma region —еттеры и геттеры

	// сеттер данных 
	virtual void setData(T* data, int n)
	{
		// если размер массива равен или меньше 0
		if (n <= 0)
			throw exception("Container: Ќекорректные данные!");

		// если данные уже хран€тс€ то очистить их
		if (data_ != nullptr)
			delete[] data_;

		// выделение пам€ти под новый массив
		data_ = new T[n];

		// установка длины 
		size_ = n;

		// копирование значений 
		memcpy(data_, data, sizeof(T) * n);
	}

	// геттер size_
	int getSize() const { return size_; }

#pragma endregion

#pragma region ћетоды

	// перегрузка операции индексировани€
	T& operator[](int index) 
	{
		// если индекс не корректен 
		if (index > size_ || index < 0)
			throw exception("Container: »ндекс некорректен");

		return data_[index];
	}

	// ћетод sort() Ч дл€ сортировки данных в контейнере
	virtual void sort() = 0;

	// ћетод foreach() Ц дл€ поэлементной обработки контейнера
	virtual void foreach() = 0;

	// вывод 
	virtual void show() 
	{
		for (int i = 0; i < size_; i++)
		{
			cout << data_[i] << " ";
		}
	};

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const Container<T>& container)
	{
		for (int i = 0; i < container.size_; i++)
		{
			os << container[i] << " ";
		}
	}

#pragma endregion

};

