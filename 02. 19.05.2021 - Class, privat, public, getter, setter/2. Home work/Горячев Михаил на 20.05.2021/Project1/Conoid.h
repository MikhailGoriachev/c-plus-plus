#pragma once

#include "head.h"

class Conoid
{
	// ������
	double height_;

	// ������ 1
	double radius1_;

	// ������ 2
	double radius2_;

public:

	// ����������� �� ���������
	Conoid() :height_(0), radius1_(0), radius2_(0) {};

	// ����������� � �����������
	Conoid(double height, double radius1, double radius2)
	{
		setHeight(height);
		setRadius1(radius1);
		setRadius2(radius2);
	}
	// ����������
	~Conoid()
	{
		cout << "Conoid: ������ ���������" << endl;
	}

	// ������ ������
	inline void setHeight(double height)
	{
		// ���� �������� ������ ��� ��������� ����
		if (height <= 0.)
		{
			throw exception("�������� ������ ������ ��� ����� ����!");
		}

		height_ = height;
	}

	// ������ ������
	inline double getHeight() const { return height_; };

	// ������ ������ 1
	inline void setRadius1(double radius1)
	{
		// ���� �������� ������ ��� ��������� ����
		if (radius1 <= 0.)
		{
			throw exception("�������� ������ ������ ��� ����� ����!");
		}

		radius1_ = radius1;
	}

	// ������ ������ 1
	inline double getRadius1() const { return radius1_; };
	
	// ������ ������ 2
	inline void setRadius2(double radius2)
	{
		// ���� �������� ������ ��� ��������� ����
		if (radius2 <= 0.)
		{
			throw exception("�������� ������ ������ ��� ����� ����!");
		}

		radius2_ = radius2;
	}

	// ������ ������ 2
	inline double getRadius2() const { return radius2_; };

	/// ������
	// �����
	inline double MathV() { return M_PI / 3 * getHeight() * (getRadius1() * getRadius1() + getRadius1() * getRadius2() + getRadius2() * getRadius2()); }

	// ���������� l
	inline double MathL() { return sqrt(getHeight() * getHeight() + (getRadius1() - getRadius2()) * (getRadius1() - getRadius2())); }

	// ������� 
	inline double MathS() { return (M_PI * MathL() * (getRadius1() + getRadius2())) + M_PI * getRadius1() * getRadius1() + M_PI * getRadius2() * getRadius2(); };

	// ������� ������ �������� � ������ �������
	inline void tableRow(int i)
	{
		cout << "| " << setw(3) << i << " | " << setw(15) << radius1_
			<< " | " << setw(14) << radius2_
			<< " | " << setw(14) << height_
			<< " | " << setw(14) << MathS()
			<< " | " << setw(14) << MathV()
			<< " |";
	}

};