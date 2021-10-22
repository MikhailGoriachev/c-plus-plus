#pragma once
#include "head.h"

using namespace std;

// ����� ��������
class Cylinder
{
	double radius_;	// ������ �������� 
	double height_;	// ������ ��������

// ������ ��������� �����
public:

	//  ����������� �� ���������
	Cylinder():radius_(0), height_(0) {};

	// ����������� � �����������
	Cylinder(double radius, double height)
	{
		setRadius(radius);
		setHeight(height);
	}

	// ���������� 
	~Cylinder()
	{
		cout << "Cylinder: ������ ���������" << endl;
	}

	// ������ ������� 
	double getRadius() const { return radius_; };

	// ������ ������� 
	void setRadius(double radius)
	{
		// ���� ����� ������ ��� ��������� ����
		if (radius <= 0.)
		{
			throw exception("�������� ������ ������ ��� ����� ����!");
		}

		radius_ = radius;
	}

	// ������ ������
	double getHeight() const { return height_; };

	// ������ ������� 
	void setHeight(double height)
	{
		// ���� ����� ������ ��� ��������� ����
		if (height <= 0.)
		{
			throw exception("�������� ������ ������ ��� ����� ����!");
		}

		height_ = height;
	}

	// ���������� �������
	double MathS() { return  M_2_PI * getRadius() * (getRadius() + getHeight()); }

	// ���������� ������
	double MathV() { return M_PI * (getRadius() * getRadius()) * getHeight(); }

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

};