#pragma once
#include "Pair.h"

// ����������� �� ������ Pair ����� TRectangle (�������������) � ������ � ���������.
// 
// ������ "�����������" ������ Pair - private. ��� ��� � ������ Pair ���� ���������,
// ������� ����� �������� � ������������ ������ � ������ � ��������������� 
// 
// ���������� ������ ���������� ��������� � �������

class TRectangle: private Pair
{
public:

	// ����������� �� ���������
	TRectangle(): TRectangle(1., 2.) { };

	// ����������� ����������������
	TRectangle(double a, double b)
	{
		setRectangle(a, b);
	}

	// ����������� ���������� 
	TRectangle(const TRectangle& tRectangle) = default;

	// ���������� 
	~TRectangle() = default;

	// ���������� �������� ������������
	TRectangle& operator=(const TRectangle& tRectangle) = default;

	// ������ ������ 
	void setRectangle(double a, double b) 
	{
		// ���� ������� �����
		if (a == b || a <= 0 || b <= 0)
			throw exception("Rectangle: ������������ ������!");

		// ��������� ��������
		a_ = a;
		b_ = b;
	}

	// ������ a_
	double getA() const { return a_; }

	// ������ b_
	double getB() const { return b_; }

	// ���������� ��������� 
	double perimeter() const { return (a_ + b_) * 2; }
	
	// ���������� �������
	double area() const { return prod(); }

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, TRectangle& tRectangle)
	{
		os << (Pair)tRectangle;
	}
};

