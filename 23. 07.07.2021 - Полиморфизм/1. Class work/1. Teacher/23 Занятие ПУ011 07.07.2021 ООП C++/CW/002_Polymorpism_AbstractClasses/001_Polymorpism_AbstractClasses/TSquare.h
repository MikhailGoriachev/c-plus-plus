#pragma once
#include "pch.h"
#include "TRect.h"

// ����������� ����� �� ������������ ������
class TSquare : public TRect
{
public:
	// ������������ � ����������
	TSquare():TSquare(1.) {}
	TSquare(double a): TRect(a, a) {}
	TSquare(const TSquare& tSquare) = default;
	virtual ~TSquare() {}

	// !! ������� ����� !! 
	// ���������� ������� ������������ ������
	double perimeter() override { return 4. * a_; }
	double area() override { return a_ * a_; }
	void show() override
	{
		cout<< "�������: " << a_ << " x " << a_
			<< ". �������� " << perimeter() << ", ������� " << area() << "\n";
	} // show

	// ���������� �������� ������
	TSquare& operator=(const TSquare&tSquare) = default;

	friend ostream& operator<<(ostream &os, TSquare& tSquare);
};

inline  ostream& operator<<(ostream& os, TSquare& tSquare)
{
	os  << "�������: " << tSquare.a_ << " x " << tSquare.a_
		<< ". �������� " << tSquare.perimeter() << ", ������� " << tSquare.area() << "\n";
	return os;
} // operator<<