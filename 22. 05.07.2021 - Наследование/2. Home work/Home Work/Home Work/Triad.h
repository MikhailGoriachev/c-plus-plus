#pragma once

#include "pch.h"

// класс Triad(три вещественных числа), определить аксессоры и
// метод вычисления суммы чисел
class Triad
{
protected:

	// первое вещественное число
	double a_;
	
	// второе вещественное число
	double b_;
	
	// третье вещественное число
	double c_;

public:

	// конструктор по умолчанию
	Triad() = default;

	// конструктор инициализирующий
	Triad(double a, double b, double c)
	{
		setA(a);
		setB(b);
		setC(c);
	}

	// конструктор копирующий 
	Triad(const Triad& triad) = default;

	// деструктор 
	~Triad() = default;

	// перегрузка операции присваивания
	Triad& operator=(const Triad& triad) = default;

	// аксессоры

	// сеттер a_
	void setA(double a) { a_ = a; }

	// геттер a_
	double getA() const { return a_; }

	// сеттер b_
	void setB(double b) { b_ = b; }

	// геттер b_
	double getB() const { return b_; }

	// сеттер c_
	void setC(double c) { c_ = c; }

	// геттер c_
	double getC() const { return c_; }

	// сумма a_, b_, c_
	double prod() const { return a_ + b_ + c_; }

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream & os, const Triad& triad)
	{
		os << "A: " << triad.a_ << " B: " << triad.b_ << " C: " << triad.c_;

		return os;
	}

};

