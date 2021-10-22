#pragma once
#include "Triad.h"

// производный от класса Triad класс Triangle (треугольник) с полями –
// сторонами.Определить методы вычисления периметра и площади.
class Triangle: private Triad
{
public:

	// конструктор по умолчанию
	Triangle() : Triad(5., 6., 7.) { };

	// конструктор инициализирующий
	Triangle(double a, double b, double c) : Triad()
	{
		setTriangle(a, b, c);
	}

	// конструктор копирующий 
	Triangle(const Triangle& triangle) = default;

	// деструктор 
	~Triangle() = default;

	// перегрузка операции присваивания
	Triangle& operator=(const Triangle& triangle) = default;


	// сеттер сторон 
	void setTriangle(double a, double b, double c)
	{
		// если стороны равны
		if (a == b || a <= 0 || b <= 0 || c <= 0 || a + b <= c || b + c <= a || c + a <= b)
			throw exception("Rectangle: Некорректные данные!");

		// установка значений
		a_ = a;
		b_ = b;
		c_ = c;
	}

	// геттер a_
	double getA() const { return a_; }

	// геттер b_
	double getB() const { return b_; }

	// геттер b_
	double getC() const { return c_; }

	// вычисление периметра 
	double perimeter() const { return a_ + b_ + c_; }

	// полупериметр
	double halfPerimeter() const { return perimeter() / 2; }

	// вычисление площади
	double area() const { return halfPerimeter() * (halfPerimeter() - a_) * (halfPerimeter() - b_) *
		(halfPerimeter() - c_); }

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const Triangle& triangle)
	{
		os << (Triad)triangle;
	}


};

