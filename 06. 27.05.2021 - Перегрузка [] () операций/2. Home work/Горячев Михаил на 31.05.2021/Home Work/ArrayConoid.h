#pragma once
#include "Utils.h"
#include "pch.h"
#include "Conoid.h"
#include "App.h"

class ArrayConoid
{
	// длина массива
	size_t size_;
	
	// указатель на первый элемент массива
	Conoid* point_;

public:

#pragma region Конструкторы и декструктор
	// конструктор по умолчанию. Создаёт по умолчанию массив из трёх объектов
	// класса Conoid
	ArrayConoid(): size_(3)
	{
		point_ = new Conoid[size_];
	}

	// конструктор принимающий количество элементов и создающий массив 
	ArrayConoid(size_t size)
	{
		// если размер массива меньше нуля
		if (size <= 0)
		{
			throw exception("Размер массива должен быть больше 0\n");
		}

		size_ = size;

		point_ = new Conoid[size_];
	}

	// деструктор
	~ArrayConoid()
	{
		delete[] point_;
	}
#pragma endregion

#pragma region Методы класса

	// фукнция возвращает длину массива
	size_t size() const { return size_; };

	/// <summary>
	/// Перегрузка индексирования. Выбрасывает exception если
	/// индекс выходит за пределы массива
	/// </summary>
	/// <param name="index">Индекс</param>
	/// <returns>Возвращает ссылку на обьект массива Conoid</returns>
	Conoid& operator[](size_t index)
	{
		if (index < 0)
			throw exception("Индекс должен быть равным или больше нуля");
		if (index > size_)
			throw exception("Индекс выходит за пределы массива");

		return point_[index];
	}

	/// <summary>
	/// Поиск индекса первого элемента массива с минимальным объемом
	/// </summary>
	/// <returns>Индекс элемента</returns>
	size_t MinimumV() const
	{
		// индекс минимального элемента
		int minV = 0;

		for (size_t i = 1; i < size_; i++)
		{
			if (point_[i].MathV() < point_[minV].MathV())
			{
				minV = i;
			}
		}

		return minV;
	}

	/// <summary>
	/// Поиск индекса элемента массива с максимальной площадью. 
	/// </summary>
	/// <returns>Индекс элемента</returns>
	size_t MaximumS() const
	{
		// индекс максимального элемента
		int maxS = 0;

		for (size_t i = 1; i < size_; i++)
		{
			if (point_[i].MathS() > point_[maxS].MathS())
			{
				maxS = i;
			}
		}

		return maxS;
	}

#pragma endregion

#pragma region Дружественные функции

	// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
	friend ostream& operator<<(ostream& os, ArrayConoid& arr);

#pragma endregion

};

