#pragma once
#include "Triangle.h"

// прямоугольный треугольник, добавлен на занятии
class Rectangular : public Triangle
{
public:
	Rectangular():Rectangular(2., 3.) {}
	Rectangular(double a, double b) : Triangle(a, b, sqrt(a*a + b*b)) {}
	~Rectangular() = default;

	virtual double perimeter() const override { return Triangle::perimeter(); }
	virtual double area() const override { return a_ * b_ / 2.; }

	virtual void show() override
	{
		cout << sizeof(*this) << " | Прямоугольный: " << a_ << " x " << b_
			<< ": периметр = " << perimeter() << "; площадь " << area() << "\n";
	}
	friend ostream& operator<<(ostream & os, const Rectangular& obj);
};


inline ostream& operator<<(ostream& os, const Rectangular& obj)
{
	return os << "Прямоугольный: " << obj.a_ << " x " << obj.b_;
}