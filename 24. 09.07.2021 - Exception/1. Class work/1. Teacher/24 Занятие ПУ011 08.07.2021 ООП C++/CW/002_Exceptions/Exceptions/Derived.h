#pragma once
#include "Base.h"
class Derived1 :	public Base<double>
{
public:
	Derived1() {}
	Derived1(double a, double b): Base(a, b) {}
	virtual ~Derived1() = default;

	void foo() {
		cout << "Derived1<double>: foo, " << *this << "\n\n";
	} // foo
};

