#pragma once
#include "pch.h"

// базовый класс для наследования, от него будем наследоваться
// базовый == супер-класс == предок/родитель
class Base
{
	// private
	int a_;

// уровень доступа protected:
// виден в производном классе (классе-наследнике), не доступен внешнему коду
protected:
	int b_;

public:
	Base(): a_(), b_() { cout << "Base: конструктор по умолчанию\n"; }
	Base(int a, int b): a_(a), b_(b) { cout << "Base: конструктор с параметрами\n"; }
	Base(const Base &base): a_(base.a_), b_(base.b_) { cout << "Base: копирующий конструктор\n"; }
	~Base() { cout << "Base: деструктор\n"; }

	int getA() const { return a_; }
	int getB() const { return b_; }

	void setA(int value) { a_ = value; }
	void setB(int value) { b_ = value; }

	friend ostream &operator<<(ostream &os, const Base &base);
};

