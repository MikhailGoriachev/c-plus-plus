#pragma once

#include "pch.h"
#include "App.h"
#include "Utils.h"
#include "Bus.h"
#include <vector>
// ������� ��� ���������� ������� ���������� ����������
class func_fill_vec
{
	// ����������� �������� 
	double min_;
	// ������������ �������� 
	double max_;

public:

	// ����������� ���������������� 
	func_fill_vec(double min, double max)
	{
		// ���� ������ �����������
		if (min > max)
			throw exception("Functor: ������������ ������!");

		// ��������� ��������
		min_ = min;
		max_ = max;
	}

	// ���������� �������� ()
	double operator()()
	{
		return getRand(min_, max_);
	}
};

// ������� ��� ������ ������� � ��������� ���� � ������� for_each
class func_save_text_vec : public unary_function<double, void>
{
	// ������ �� �������� ������ ������ 
	ostream_iterator<double>& os_;
	
public:

	// ����������� ����������������
	func_save_text_vec(ostream_iterator<double>& os) : os_(os) {}

	// ���������� �������� ()
	void operator()(double value)
	{
		*os_ = value;

		os_++;
	}
};

// ������� ��� ���������� �������� �� ��������� �����
class func_power : public unary_function<double, double>
{
	// ���������
	double n_;

public:

	// ����������� ���������������� ����������� ���������
	func_power(double n)
	{
		// ��������� ����� 0
		if (n == 0.)
			throw exception("������ �����������!");

		// ��������� ��������
		n_ = n;
	}

	// ���������� �������� ()
	double operator()(double& value)
	{
		return value *= n_;
	}
};

// ������� ���������� ��� ���������� �� ������� - ������� �������������, ����� ������������� 
class pred_positive_vector : public binary_function<double, double, bool>
{
public :

	// ���������� �������� ��������� 
	bool operator()(double val1, double val2)
	{
		return val1 >= 0 && val2 < 0;
	}
};

// ������� ��� ������ ��������� � ������� ����� ���� for_each
class func_out_bus : public unary_function<Bus&, void>
{
	// ����� �������� 
	int i_ = 0;

public:

	// ����������� �� ���������
	func_out_bus() = default;

	// ���������� �������� ()
	void operator()(Bus& bus)
	{
		// ������� ���� �� ���������
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

// ������� ��� ���������� ��������� � ��������� ����
class func_save_bus : public unary_function<Bus&, void>
{
	// �������� ��� ������ 
	ostream_iterator<Bus> it_;

public:

	// ����������� ���������������� 
	func_save_bus(ofstream& file) : it_((file)) {}

	// ���������� �������� ()
	void operator()(Bus& bus)
	{
		*it_ = bus;
	}
};


/*// ������� ��� �������� ��������� �� ���������� �����
class func_load_bus : public unary_function<vector<Bus>&, void>
{
	// �������� ��� ������ 
	istream_iterator<Bus> it_;

public:

	// ����������� ���������������� 
	func_load_bus(ifstream& file) : it_((file)) {}

	// ���������� �������� ()
	void operator()(vector<Bus>& bus)
	{
		bus.push_back(*it_++);
	}
};*/

// ������� ��� ���������� ������� ���������� �� ������� Bus
class func_fill_bus : public unary_function<Bus&, void>
{
	// ������ �� ������
	vector<Bus>& bus_;

public:

	// ����������� ���������������� 
	func_fill_bus(vector<Bus>& bus) : bus_((bus)) {}

	// ���������� �������� ()
	void operator()(Bus& newBus)
	{
		bus_.push_back(newBus);
	}
};

// ������� ��� ��������� ��������������� �������
class func_comp_by_number : binary_function <Bus&, Bus&, int>
{
public:

	func_comp_by_number() = default;

	int operator()(Bus& bus1, Bus& bus2) { return bus1.getNumber() < bus2.getNumber(); }
};

// ������� ��� ��������� ���������
class func_comp_by_name : binary_function <Bus&, Bus&, int>
{
public:

	func_comp_by_name() = default;

	int operator()(Bus& bus1, Bus& bus2) { return bus1.getName() < bus2.getName(); }
};