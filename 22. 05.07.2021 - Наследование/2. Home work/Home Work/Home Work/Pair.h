#pragma once
#include "pch.h"

// класс Pair (пара вещественных чисел), определить аксессоры и метод вычисления произведения чисел.
class Pair
{
protected:

	// вещественное число a
	double a_;

	// вещественное число b
	double b_;

public:

	// конструктор по умолчанию
	Pair() = default;

	// конструктор инициализирующий
	Pair(double a, double b)
	{
		setA(a);
		setB(b);
	}

	// конструктор копирующий 
	Pair(const Pair& pair) = default;

	// деструктор 
	~Pair() = default;

	// перегрузка операции присваивания
	Pair& operator=(const Pair& pair) = default;

	// аксессоры

	// сеттер a_
	void setA(double a) { a_ = a; }

	// геттер a_
	double getA() const { return a_; }

	// сеттер b_
	void setB(double b) { b_ = b; }

	// геттер b_
	double getB() const { return b_; }

	// произведение a_ на b_
	double prod() const { return a_ * b_; }
	
	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const Pair& pair)
	{
		os << "A: " << pair.a_ << " B: " << pair.b_;

		return os;
	}
};
