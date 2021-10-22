#pragma once
#include <exception>
#include "pch.h"

using namespace std;

// ����� Cylinder
class Cylinder
{
	// ������ 
	double radius_;

	// ������ 
	double height_;

public:

#pragma region ������������ � �����������
	// ���������� �� ���������
	Cylinder() :radius_(0), height_(0) {};

	// ���������� � �������� ���� ����������
	Cylinder(double radius, double height)
	{
		setRadius(radius);
		setHeight(height);
	}

	~Cylinder()
	{
		cout << "Cylinder: ������ ���������" << endl;
	}

#pragma endregion

#pragma region ������� � �������

	// ������ radius_
	void setRadius(double radius)
	{
		// ���� ����� <= 0
		if (radius <= 0)
		{
			throw exception("��������� ����� ������ ���� <= 0");
		}

		radius_ = radius;
	}

	// ������ height_
	void setHeight(double height)
	{
		// ���� ����� <= 0
		if (height <= 0)
		{
			throw exception("��������� ����� ������ ���� <= 0");
		}

		height_ = height;
	}

	// ������ radius_
	double getRadius() const { return radius_; };

	// ������ height_
	double getHeight() const { return height_; };

#pragma endregion

#pragma region ������
	// ���������� �������
	double MathS() { return  M_2_PI * radius_ * (radius_ + height_); }

	// ���������� ������
	double MathV() { return M_PI * (radius_ * radius_) * height_; }

	// ����� ���������
	// ������� ������ �������� � ������ �������
	void tableRow(int i)
	{
		cout << "| " << setw(3) << i << " | " << setw(15) << getRadius()
			<< " | " << setw(14) << getHeight()
			<< " | " << setw(14) << MathS()
			<< " | " << setw(14) << MathV()
			<< " |";
	}

	// �������� ���� ��������� 
	Cylinder* operator+ (Cylinder cyl2)
	{
		Cylinder* cyl = new Cylinder;

		// �������� ���� ���� ���������
		cyl->setHeight(this->getHeight() + cyl2.getHeight());

		// �������� �������� ���� ���������
		cyl->setRadius(this->getRadius() + cyl2.getRadius());

		return cyl;
	}

	// ��������� ����� �� ��������
	Cylinder* operator - (double n)
	{
		Cylinder* cyl = new Cylinder;

		// ��������� ����� �� ����� �������� 
		cyl->setHeight(this->getHeight() - n);

		// ��������� ����� �� ������� ��������
		cyl->setRadius(this->getRadius() - n);

		return cyl;
	}
#pragma endregion
};