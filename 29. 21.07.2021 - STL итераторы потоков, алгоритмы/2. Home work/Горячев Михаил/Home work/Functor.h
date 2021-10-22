#pragma once

#include "pch.h"
#include "App.h"
#include "Utils.h"
#include "Bus.h"
#include <vector>
// функтор для заполнения массива случайными значениями
class func_fill_vec
{
	// минимальное значение 
	double min_;
	// максимальное значение 
	double max_;

public:

	// конструктор инициализирующий 
	func_fill_vec(double min, double max)
	{
		// если данные некорректны
		if (min > max)
			throw exception("Functor: Некорректные данные!");

		// установка значений
		min_ = min;
		max_ = max;
	}

	// перегрзука операции ()
	double operator()()
	{
		return getRand(min_, max_);
	}
};

// функтор для записи вектора в текстовый файл с помощью for_each
class func_save_text_vec : public unary_function<double, void>
{
	// ссылка на итератор потока вывода 
	ostream_iterator<double>& os_;
	
public:

	// конструктор инициализирующий
	func_save_text_vec(ostream_iterator<double>& os) : os_(os) {}

	// перегрузка операции ()
	void operator()(double value)
	{
		*os_ = value;

		os_++;
	}
};

// функтор для умножнения значения на указанное число
class func_power : public unary_function<double, double>
{
	// множитель
	double n_;

public:

	// конструктор инициализирующий принимающий множитель
	func_power(double n)
	{
		// множитель равен 0
		if (n == 0.)
			throw exception("Данные некорректны!");

		// установка значения
		n_ = n;
	}

	// перегрузка операции ()
	double operator()(double& value)
	{
		return value *= n_;
	}
};

// функтор предикатор для сортировки по правилу - сначала положительные, потом отрицательные 
class pred_positive_vector : public binary_function<double, double, bool>
{
public :

	// перегрзука операции сравнения 
	bool operator()(double val1, double val2)
	{
		return val1 >= 0 && val2 < 0;
	}
};

// функтор для вывода автобусов в таблицы через цикл for_each
class func_out_bus : public unary_function<Bus&, void>
{
	// номер элемента 
	int i_ = 0;

public:

	// конструктор по умолчанию
	func_out_bus() = default;

	// перегрузка операции ()
	void operator()(Bus& bus)
	{
		// текущий цвет по умолчанию
		short cl = getColor();

		cout << "    | " << setw(4) << i_++ << " | " << left
			<< color(LTYELLOW_ON_BLACK) << setw(12) << bus.getNumber()
			<< color(cl) << " | "
			<< color(LTYELLOW_ON_BLACK) << setw(22) << bus.getName()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << bus.getRoutApp()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << bus.getRoutAct()
			<< color(cl) << " | " << right << endl;
	}
};

// функтор для сохранение автобусов в текстовый файл
class func_save_bus : public unary_function<Bus&, void>
{
	// итератор для потока 
	ostream_iterator<Bus> it_;

public:

	// конструктор инициализирующий 
	func_save_bus(ofstream& file) : it_((file)) {}

	// перегрузка операции ()
	void operator()(Bus& bus)
	{
		*it_ = bus;
	}
};


/*// функтор для загрузки автобусов из текстового файла
class func_load_bus : public unary_function<vector<Bus>&, void>
{
	// итератор для потока 
	istream_iterator<Bus> it_;

public:

	// конструктор инициализирующий 
	func_load_bus(ifstream& file) : it_((file)) {}

	// перегрузка операции ()
	void operator()(vector<Bus>& bus)
	{
		bus.push_back(*it_++);
	}
};*/

// функтор для заполнения вектора элементами из массива Bus
class func_fill_bus : public unary_function<Bus&, void>
{
	// ссылка на вектор
	vector<Bus>& bus_;

public:

	// конструктор инициализирующий 
	func_fill_bus(vector<Bus>& bus) : bus_((bus)) {}

	// перегрузка операции ()
	void operator()(Bus& newBus)
	{
		bus_.push_back(newBus);
	}
};

// функтор для сравнения регистрационных номеров
class func_comp_by_number : binary_function <Bus&, Bus&, int>
{
public:

	func_comp_by_number() = default;

	int operator()(Bus& bus1, Bus& bus2) { return bus1.getNumber() < bus2.getNumber(); }
};

// функтор для сравнения инициалов
class func_comp_by_name : binary_function <Bus&, Bus&, int>
{
public:

	func_comp_by_name() = default;

	int operator()(Bus& bus1, Bus& bus2) { return bus1.getName() < bus2.getName(); }
};