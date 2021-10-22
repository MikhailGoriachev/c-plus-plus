#pragma once

#include "pch.h"
#include "Container.h"
#include "ContainerException.h"
#include "Utils.h"


// В производном классе Choice сортировка реализуется методом выбора, 
// Поэлементная обработка – вычисление натурального логарифма log().

// Производный класс Bubble
class Choice : public Container<double>
{
public:

	// конструктор по умолчанию
	Choice() = default;

	// инициализирующий конструктор 
	Choice(double* data, int n) : Container(data, n) {}

	// копирующий конструктор 
	Choice(const Choice & choice) = default;

	// деструктор 
	virtual ~Choice() override = default;

	// сортировка реализуется методом выбора (источник http://algolist.ru/sort/select_sort.php) 
	virtual void sort() override
	{
		double x;

		for (int i = 0, k; i < size_; i++) {   	// i - номер текущего шага
			k = i; x = data_[i];

			for (int j = i + 1; j < size_; j++)	// цикл выбора наименьшего элемента
				if (data_[j] < x) {
					k = j; x = data_[j];	        // k - индекс наименьшего элемента
				}

			data_[k] = data_[i]; data_[i] = x;   	// меняем местами наименьший с data_[i]
		}
	}

	// поэлементная обработка – вычисление натурального логарифма log()
	virtual void foreach() override try 
	{ 
		for (int i = 0; i < size_; i++)
		{
			data_[i] = logFunc(data_[i]);
		}
	}
	catch (ContainerException<double>& ex)
	{
		// текущий цвет
		short cl = getColor();

		// вывод исключения
		cout << color(RED_ON_BLACK) << ex << color(cl);
	}

	// вычисление натурального логарифма log()
	double logFunc(double value)
	{
		// если значение меньше нуля
		if (value <= 0)
		{
			stringstream os;

			os.precision(3);

			// формирование строки
			os << " | Choice: Значение меньше или равно нулю!           Значение элемента массива: " << right << setw(7) << value << setw(33) << " |\n";

			// передача строки в ContainerException
			throw ContainerException<double>(os.str().c_str());
		}
		return log(value);

	}
};

