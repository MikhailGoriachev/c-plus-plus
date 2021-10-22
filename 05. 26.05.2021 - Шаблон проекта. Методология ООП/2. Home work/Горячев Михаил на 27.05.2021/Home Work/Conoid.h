#pragma once

#include "pch.h"

class Conoid
{
	// ������
	double height_;

	// ������ 1 - ������ ���������
	double radius1_;

	// ������ 2 - ������ �������
	double radius2_;

public:

#pragma region ������������ � �����������

	// ����������� �� ���������
	Conoid() :height_(1), radius1_(1), radius2_(1) {};

	// ����������� � �����������
	Conoid(double height, double radius1, double radius2)
	{
		setHeight(height);
		setRadius1(radius1);
		setRadius2(radius2);

		if (radius1 < radius2)
		{
			throw exception("������ ��������� ������ ���� ������, ��� ������ �������!\n");
		}
	}
	// ����������
	~Conoid()
	{
		cout << "Conoid: ������ ���������" << endl;
	}

#pragma endregion

#pragma region ������� � �������

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

#pragma endregion

#pragma region ������

	// �����
	inline double MathV() { return M_PI / 3 * height_ * (radius1_ * radius1_ + radius1_ * radius2_ + radius2_ * radius2_); }

	// ���������� l
	inline double MathL() { return sqrt(height_ * height_ + (radius1_ - radius2_) * (radius1_ - radius2_)); }

	// ������� 
	inline double MathS() { return (M_PI * MathL() * (radius1_ + radius2_)) + M_PI * radius1_ * radius1_ + M_PI * radius2_ * radius2_; };

	// �������� ���� �������
	Conoid* operator+(Conoid& con)
	{
		Conoid* newConoid = new Conoid;

		// �������� ������
		newConoid->setHeight(this->height_ + con.getHeight());

		// �������� ������� 1
		newConoid->setRadius1(this->radius1_ + con.getRadius1());

		// �������� ������� 2
		newConoid->setRadius2(this->radius2_ + con.getRadius2());

		return newConoid;
	}

	// ��������� �� �����
	Conoid* operator*(double num)
	{
		Conoid* newConoid = new Conoid;

		// ��������� ������
		newConoid->setHeight(this->height_ * num);

		// ��������� ������� 1
		newConoid->setRadius1(this->radius1_ * num);

		// ��������� ������� 2
		newConoid->setRadius2(this->radius2_ * num);

		return newConoid;
	}

	// ��������� �����
	Conoid* operator-(double num)
	{
		Conoid* newConoid = new Conoid;

		// ��������� ������
		newConoid->setHeight(this->height_ - num);

		// ��������� ������� 1
		newConoid->setRadius1(this->radius1_ - num);

		// ��������� ������� 2
		newConoid->setRadius2(this->radius2_ - num);

		return newConoid;
	}

#pragma endregion

#pragma region friend

	// ���������� �������� ������ << 
	friend ostream& operator<<(ostream& link, Conoid& con);

	// ������������� ������� ������ Conoid. ���������� �������� ����� >> 
	friend	istream& operator>>(istream& link, Conoid& con);

#pragma endregion

};