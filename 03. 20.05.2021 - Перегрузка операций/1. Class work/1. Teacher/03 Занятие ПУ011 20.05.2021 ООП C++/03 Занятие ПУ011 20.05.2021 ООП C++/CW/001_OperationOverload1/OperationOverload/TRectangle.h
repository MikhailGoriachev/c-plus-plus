#pragma once
#include "pch.h"

// ����� �������������� ������������� 
class TRectangle
{
    // ������� ��������������
    double a_;
    double b_;

public:
    // ������������
    TRectangle():a_(1), b_(1) { }  // ������������� ������ �������������� ������������
    TRectangle(double a, double b)
    {
        setSides(a, b);
    } // TRectangle

    // ������ ��� ������� ���� ������ ����� ���������
    void setSides(double a, double b);

    // ������� ��� ������� ������
    void setA(double a);
    void setB(double b);

    // �������
    double getA() const { return a_; }
    double getB() const { return b_; }

    // ������ ���������� ������� � ���������
    double area()      const { return a_ * b_;       }
    double perimeter() const { return 2 * (a_ + b_); }

    // ����� ������ �������������� � �������
    void show(const char *title="") const;

    // ���������� �������� ��������� ����������� ��������� -
	TRectangle operator-(const TRectangle &r)   // *this - r
	{
        return TRectangle(a_ - r.a_, b_ - r.b_);
	}
	

    // ���������� ������������� ������� ��� ���������� �������� �����
    friend TRectangle operator-(double value, const TRectangle& r);

    // ���������� ������������� ������� ��� ���������� �������� �����
    // friend istream &operator>>(istream &is, TRectangle &rect);

	// ���������� ������������� ������� ��� ���������� �������� ������
    friend ostream &operator<<(ostream &os,  const TRectangle &rect);
};

// ���������� �������, �� ������������� ���������� �������� �����
istream &operator>>(istream &is, TRectangle &rect);