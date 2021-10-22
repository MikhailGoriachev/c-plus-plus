#include "pch.h"
#include "Trapezium.h"

// ����������� �� ���������
Trapezium::Trapezium():a_(1), b_(1.5), c_(1)
{
    cout << "Trapezium: ����������� �� ���������\n";
}


// ����������� � �����������
Trapezium::Trapezium(double a, double b, double c)
{
    cout << "Trapezium:  �������� ����������� � ����������\n";

	// ��������� ����� ������ ��� ������ ��������
    setA(a);
    setB(b);
    setC(c);
} // Trapezium::Trapezium


// ������ ��� ��������� ������� �
void Trapezium::setA(double a)
{
    // this ��������� �� ������� ��������� ������
    // (�� ������� ������)
    // this->a_ = a <= 0?1:a;

    if (a <= 0)
        throw exception("Trapezium: ������������ �������� ������� A");

    this->a_ = a;
} // Trapezium::setA

// ������ ��� ��������� ������� �
void Trapezium::setB(double b)
{
    if (b <= 0)
       throw exception("Trapezium: ������������ �������� ������� B");

    this->b_ = b;
} // Trapezium::setB

// ������ ��� ��������� ������� C
void Trapezium::setC(double c)
{
    if (c <= 0)
       throw exception("Trapezium: ������������ �������� ������� C");

    this->c_ = c;
} // Triangle::SetC

// ������ ����������� ������� � ����� ��������� ������
double Trapezium::getC() const
{
    return c_;
} // Trapezium::GetC


// ���������� ������� ������������� ��������
double Trapezium::area() const
{
    return b_ * (a_+c_)/2;
} // Trapezium::area


// ���������� ��������� ������������� ��������
// double Trapezium::perimeter() const {  }
double Trapezium::perimeter() const { return a_ + b_ + c_ + sqrt(pow(c_ - a_, 2) + b_ * b_); }
