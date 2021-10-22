#pragma once
#include "pch.h"
#include "TRect.h"

// производный класс от абстрактного класса
class TSquare : public TRect
{
public:
	// конструкторы и деструктор
	TSquare():TSquare(1.) {}
	TSquare(double a): TRect(a, a) {}
	TSquare(const TSquare& tSquare) = default;
	virtual ~TSquare() {}

	// !! Сюжетно важно !! 
	// реализация методов абстрактного класса
	double perimeter() override { return 4. * a_; }
	double area() override { return a_ * a_; }
	void show() override
	{
		cout<< "Квадрат: " << a_ << " x " << a_
			<< ". Периметр " << perimeter() << ", площадь " << area() << "\n";
	} // show

	// Перегрузка операций класса
	TSquare& operator=(const TSquare&tSquare) = default;

	friend ostream& operator<<(ostream &os, TSquare& tSquare);
};

inline  ostream& operator<<(ostream& os, TSquare& tSquare)
{
	os  << "Квадрат: " << tSquare.a_ << " x " << tSquare.a_
		<< ". Периметр " << tSquare.perimeter() << ", площадь " << tSquare.area() << "\n";
	return os;
} // operator<<