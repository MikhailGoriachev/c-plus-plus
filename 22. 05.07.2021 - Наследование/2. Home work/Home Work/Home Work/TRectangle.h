#pragma once
#include "Pair.h"

// производный от класса Pair класс TRectangle (прямоугольник) с полями – сторонами.
// 
// способ "подключения" класса Pair - private. Так как в классе Pair есть аксессоры,
// которые могут привести к некорректным данным в случае с прямоугольником 
// 
// Определить методы вычисления периметра и площади

class TRectangle: private Pair
{
public:

	// конструктор по умолчанию
	TRectangle(): TRectangle(1., 2.) { };

	// конструктор инициализирующий
	TRectangle(double a, double b)
	{
		setRectangle(a, b);
	}

	// конструктор копирующий 
	TRectangle(const TRectangle& tRectangle) = default;

	// деструктор 
	~TRectangle() = default;

	// перегрузка операции присваивания
	TRectangle& operator=(const TRectangle& tRectangle) = default;

	// сеттер сторон 
	void setRectangle(double a, double b) 
	{
		// если стороны равны
		if (a == b || a <= 0 || b <= 0)
			throw exception("Rectangle: Некорректные данные!");

		// установка значений
		a_ = a;
		b_ = b;
	}

	// геттер a_
	double getA() const { return a_; }

	// геттер b_
	double getB() const { return b_; }

	// вычисление периметра 
	double perimeter() const { return (a_ + b_) * 2; }
	
	// вычисление площади
	double area() const { return prod(); }

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, TRectangle& tRectangle)
	{
		os << (Pair)tRectangle;
	}
};

