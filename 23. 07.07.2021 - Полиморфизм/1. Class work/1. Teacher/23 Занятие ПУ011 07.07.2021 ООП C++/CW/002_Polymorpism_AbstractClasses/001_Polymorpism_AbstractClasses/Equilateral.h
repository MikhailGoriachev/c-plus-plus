#pragma once
#include "Triangle.h"

// �������������� �����������
class Equilateral : public Triangle
{
public:
	Equilateral() = default;
	Equilateral(double a): Triangle(a, a, a) {}
	~Equilateral() = default;

	double perimeter() const override { return  3. * a_; }
	double area() const override { return a_ * a_ * sqrt(3.) / 2.; }

	void show() override
	{
		cout << sizeof(*this) << " | ��������������: " << a_
			<< ": �������� = " << perimeter() << "; ������� " << area() << "\n";
	}
	friend ostream& operator<<(ostream& os, const Equilateral& obj);
};

inline ostream& operator<<(ostream& os, const Equilateral& obj)
{
	return os << "��������������: " << obj.a_;
}