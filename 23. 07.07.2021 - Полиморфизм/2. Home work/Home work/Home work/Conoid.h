#pragma once

#include "pch.h"
#include "Utils.h"
#include "Body.h"

// ����� ������ 
class Conoid : public Body
{
	// ������ 
	double height_;

	// ������ ���������
	double radius_;
	
public:


	// ����������� �� ���������
	Conoid() = default;

	// ����������� ���������������
	Conoid(double height, double radius) : Body()
	{
		setHeight(height);
		setRadius(radius);
	}

	// ����������� ����������
	Conoid(const Conoid & sphere) = default;

	// ���������� 
	~Conoid() = default;

	// ������ height_
	void setHeight(double height)
	{
		if (height <= 0)
			throw exception("App: ������������ ������!");

		height_ = height;
	}

	// ������ height_
	double getHeight() { return height_; }

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
	virtual double area() override 
	{ 
		// l - ����������
		double l = sqrt(pow(radius_, 2) + pow(height_, 2));
		return M_PI * pow(radius_, 2) + M_PI * radius_ * l;
	}

	// ���������� ������ ������
	virtual double valume() override { return M_PI / 3 * pow(radius_, 2) * height_; }

	// ����� ������ �� ������
	virtual void show() override
	{
		// ������� ���� 
		short cl = getColor();

		cout << fixed;

		cout.precision(3);

		cout << "\t| " << color(YELLOW_ON_BLACK) << "        �����         "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << height_
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

