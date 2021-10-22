#pragma once
#include "TRect.h"

// ���������� ������ - ��������������, ������������
// �� ������������ ������ 
class TRectangular :public TRect
{
public:
	// ������������ � ����������
	TRectangular() :TRectangular(1., 2.) {}
	TRectangular(double a, double b) : TRect(a, a) {}
	TRectangular(const TRectangular& tSquare) = default;
	virtual ~TRectangular() override {}

	// !! ������� ����� !! 
	// ���������� ������� ������������ ������
	double perimeter() override { return  2 * (a_ + b_); };
	double area() override { return a_ * b_; };
	void show() override
	{
		cout << "�������������: " << a_ << " x " << b_
			<< ". �������� " << perimeter() << ", ������� " << area() << "\n";
	}

	// ���������� �������� ������
	TRectangular& operator=(const TRectangular& tSquare) = default;
	
	friend ostream& operator<<(ostream& os, TRectangular& tSquare);
};

inline  ostream& operator<<(ostream& os, TRectangular& tRectangular)
{
	cout<< "�������������: " << tRectangular.a_ << " x " << tRectangular.b_
		<< ". �������� " << tRectangular.perimeter() << ", ������� "
	    << tRectangular.area() << "\n";
	return os;
} // operator<<

