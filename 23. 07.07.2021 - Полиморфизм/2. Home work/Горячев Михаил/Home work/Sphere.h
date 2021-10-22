#pragma once
#include "Body.h"
#include "pch.h"
#include "Utils.h"

// ����� ����� 
class Sphere : public Body
{
	// ������ �����(����) (R) - ��� ���������� �� ������ �����
	double radius_;

public:

	// ����������� �� ���������
	Sphere() = default;

	// ����������� ���������������
	Sphere(double radius) : Body()
	{
		setRadius(radius);
	}

	// ����������� ����������
	Sphere(const Sphere& sphere) = default;

	// ���������� 
	~Sphere() = default;

	// ������ radius_
	void setRadius(double radius)
	{
		if (radius <= 0)
			throw exception("App: ������������ ������!");

		radius_ = radius;
	}

	// ������ radius_
	double getRadius() { return radius_; }

	// ���������� ������� �����������
	virtual double area() override { return 4 * M_PI * pow(radius_, 2); }

	// ���������� ������ ������
	virtual double valume() override { return M_PI / 3 * 4 * pow(radius_, 3); }

	// ����� ������ �� ������
	virtual void show() override
	{
		// ������� ���� 
		short cl = getColor();

		cout << fixed;

		cout.precision(3);

		cout << "\t| " << color(YELLOW_ON_BLACK) << "      �����(���)      "
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ������  "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << radius_
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ������  "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << area()
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << valume()
			<< color(cl) << " |\n"
			<< "\t+������������������������+������������+������������+������������+������������+������������+\n";

	}
};

