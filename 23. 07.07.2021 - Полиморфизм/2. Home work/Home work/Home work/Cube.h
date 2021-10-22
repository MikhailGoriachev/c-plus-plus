#pragma once
#include "pch.h"
#include "Body.h"
#include "Utils.h"

// ����� ���
class Cube : public Body
{
	// ����� ����� ���� 
	double lenght_;

public:

	// ����������� �� ���������
	Cube() = default;

	// ����������� ���������������
	Cube(double lenght) : Body()
	{
		setLenght(lenght);
	}

	// ����������� ����������
	Cube(const Cube& sphere) = default;

	// ���������� 
	~Cube() = default;

	// ������ lenght_
	void setLenght(double lenght)
	{
		if (lenght <= 0)
			throw exception("App: ������������ ������!");

		lenght_ = lenght;
	}

	// ������ lenght_
	double getLenght() { return lenght_; }

	// ���������� ������� �����������
	virtual double area() override { return 6 * pow(lenght_, 2); }

	// ���������� ������ ������
	virtual double valume() override { return pow(lenght_, 3); }

	// ����� ������ �� ������
	virtual void show() override
	{
		// ������� ���� 
		short cl = getColor();

		cout << fixed;

		cout.precision(3);

		cout << "\t| " << color(YELLOW_ON_BLACK) << "         ���          "
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ������  "
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ������  "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << lenght_
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << area()
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << valume()
			<< color(cl) << " |\n"
			<< "\t+������������������������+������������+������������+������������+������������+������������+\n";
	}
};

