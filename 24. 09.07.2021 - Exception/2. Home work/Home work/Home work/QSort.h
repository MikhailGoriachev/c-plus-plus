#pragma once

#include "pch.h"
#include "Container.h"
#include "ContainerException.h"
#include "Utils.h"

// В производном классе QSort сортировка реализуется методом быстрой сортировки,
// вызовом функции qsort(), поэлементная обработка – вычисление десятичного
// логарифма log10().

// Производный класс Bubble
class QSort : public Container<double>
{
public:

	// конструктор по умолчанию
	QSort() = default;

	// инициализирующий конструктор 
	QSort(double* data, int n) : Container(data, n) {}

	// копирующий конструктор 
	QSort(const QSort & QSort) = default;

	// деструктор 
	virtual ~QSort() override = default;

private:

	// компаратор для сортировки
	static int compar(const void* val1, const void* val2)
	{
		double value1 = *(double*)val1;
		double value2 = *(double*)val2;

		return value1 > value2 ? 1 : value1 < value2 ? -1 : 0;
	}

public:

	// сортировка реализуется методом быстрой сортировки
	virtual void sort() override
	{
		// быстрая сортировка
		qsort(data_, size_, sizeof(double), compar);
	}

	// поэлементная обработка – вычисление десятичного логарифма log10()
	virtual void foreach() override try
	{ 
		for (int i = 0; i < size_; i++)
		{
			data_[i] = log10Func(data_[i]);
		}
	}
	catch (ContainerException<double>& ex)
	{
		// текущий цвет
		short cl = getColor();

		// вывод исключения
		cout << color(RED_ON_BLACK) << ex << color(cl);
	}

	// вычисление десятичного логарифма log10()
	double log10Func(double value)
	{
		// если значение меньше нуля
		if (value <= 0)
		{
			stringstream os;

			os.precision(3);

			// формирование строки
			os << " | QSort: Значение меньше или равно нулю!           Значение элемента массива: " << right << setw(7) << value << setw(34) << " |\n";
			// передача строки в ContainerException
			throw ContainerException<double>(os.str().c_str());
		}

		return log10(value);

	}
};

