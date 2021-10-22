#pragma once

#include "pch.h"
#include "Container.h"
#include "ContainerException.h"
#include "Utils.h"


// В производном класс Bubble.
// Сортировка реализуется методом пузырька.
// Поэлементная обработка – извлечение квадратного корня.

// Производный класс Bubble
class Bubble : public Container<double>
{
public:

	// конструктор по умолчанию
	Bubble() = default;

	// инициализирующий конструктор 
	Bubble(double* data, int n) : Container(data, n) {}

	// копирующий конструктор 
	Bubble(const Bubble& bubble) = default;

	// деструктор 
	virtual ~Bubble() override = default;

	// Сортировка реализуется методом пузырька.
	virtual void sort() override 
	{
		// сортировка пузырьком 
		for (int i = size_ - 1; i > 0; i--)
		{
			for (int k = 0; k < i; k++)
			{
				if (data_[k] > data_[k + 1])
					swap(data_[k], data_[k + 1]);
			}
		}
	}

	// Поэлементная обработка – извлечение квадратного корня.
	virtual void foreach() override try 
	{
		for (int i = 0; i < size_; i++)
		{
			data_[i] = sqrtFunc(data_[i]);
		}
	} 
	// обработка исключения
	catch (ContainerException<double>& ex) 
	{
		// текущий цвет
		short cl = getColor();

		// вывод исключения
		cout << color(RED_ON_BLACK) << ex << color(cl); 
	}

	// извлечение квадратного корня
	double sqrtFunc(double value)
	{
		// если значение меньше нуля
		if (value < 0)
		{
			stringstream os;

			os.precision(3);

			// формирование строки
			os << " | Bubble: Значение меньше нуля!                    Значение элемента массива: " << right << setw(7) << value << setw(34) << " |\n";

			// передача строки в ContainerException
			throw ContainerException<double>(os.str().c_str());
		}
		return sqrt(value);

	}
};

