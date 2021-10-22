#pragma once
#include "TRect.h"

// реализация класса - прямоугольника, производного
// от абстрактного класса 
class TRectangular :public TRect
{
public:
	// конструкторы и деструктор
	TRectangular() :TRectangular(1., 2.) {}
	TRectangular(double a, double b) : TRect(a, a) {}
	TRectangular(const TRectangular& tSquare) = default;
	virtual ~TRectangular() override {}

	// !! Сюжетно важно !! 
	// реализация методов абстрактного класса
	double perimeter() override { return  2 * (a_ + b_); };
	double area() override { return a_ * b_; };
	void show() override
	{
		cout << "Прямоугольник: " << a_ << " x " << b_
			<< ". Периметр " << perimeter() << ", площадь " << area() << "\n";
	}

	// Перегрузка операций класса
	TRectangular& operator=(const TRectangular& tSquare) = default;
	
	friend ostream& operator<<(ostream& os, TRectangular& tSquare);
};

inline  ostream& operator<<(ostream& os, TRectangular& tRectangular)
{
	cout<< "Прямоугольник: " << tRectangular.a_ << " x " << tRectangular.b_
		<< ". Периметр " << tRectangular.perimeter() << ", площадь "
	    << tRectangular.area() << "\n";
	return os;
} // operator<<

