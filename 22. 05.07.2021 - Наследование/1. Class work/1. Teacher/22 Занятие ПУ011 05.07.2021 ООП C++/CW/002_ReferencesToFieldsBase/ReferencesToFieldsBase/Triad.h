#pragma once
#include "pch.h"

class Triad // Базовый класс, представляет три числа
{
protected:
	
	int a_;
	int b_;
	int c_;

public:
	Triad():a_(), b_(), c_() {}
	Triad(int a, int b, int c):a_(a), b_(b), c_(c) {}
	Triad(const Triad &triad)=default;
	~Triad()=default;

	int incA() { a_++; return a_;}
	int incB() { b_++; return b_; }
	int incC() { c_++; return c_; }

	friend ostream &operator<<(ostream &os, const Triad &triad);
};

// реализация оператора вывода
inline ostream &operator<<(ostream &os, const Triad &triad)
{
	os << triad.a_ << " " << triad.b_ << " " << triad.c_;
	return os;
} // operator<<