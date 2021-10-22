#pragma once
#include "pch.h"

// Базовый класс с виртуальными методами
class Triangle
{
protected:
	double a_;
	double b_;
	double c_;

public:
	Triangle():a_(1), b_(1), c_(1) {  }
	Triangle(double a, double b, double c):a_(a), b_(b), c_(c) {  }

	virtual ~Triangle() = default;

	virtual double perimeter() const { return a_ + b_ + c_;  }
	virtual double area() const
	{
		double p = perimeter() / 2.;
		return sqrt(p*(p - a_)*(p - b_)*(p - c_));
	}

	friend ostream &operator<<(ostream &os, const Triangle &obj);
	
	virtual void show()
	{
		cout << sizeof(*this) << " | Разносторонний: " << a_ << " x " << b_ << " x " << c_
		     << ": периметр = " << perimeter() << "; площадь " << area() << "\n";
	    // return os;
	}
	
	// virtual ostream &show(ostream &os)
	// {
	// 	os << "Разносторонний: " << a_ << " x " << b_ << " x " << c_;
	//     return os;
	// }

	// компаратор для сортировки полимофрного массива при помощи
	// функции qsort() стандартной библиотеки 
	static int compare(void const *ob1, void const* ob2)
	{
		double area1 = (*(Triangle**)ob1)->area();
		double area2 = (*(Triangle**)ob2)->area();

		return area1 < area2 ? -1 : area1 > area2 ? 1 : 0;
	} // compare 
};


inline ostream &operator<<(ostream &os, const Triangle &obj)
{
	os << "Разносторонний: " << obj.a_ << " x " << obj.b_ << " x " << obj.c_;
	return os;

	// return obj.show(os);
}
