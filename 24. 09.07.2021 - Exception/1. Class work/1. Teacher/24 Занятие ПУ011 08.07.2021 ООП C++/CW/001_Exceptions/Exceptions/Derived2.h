#pragma once
#include "pch.h"
#include "Base.h"

// производный класс можно создавать только от шаблонного
// закрытого конкретным типом
class Derived2 : public Base<int>
{
	public:
	Derived2() = default;
	Derived2(int a, int b): Base(a, b) {}
	Derived2(const Derived2 &obj) = default;
	virtual ~Derived2() = default;

	void foo() {
		cout << "    Derived2<int>: foo, " << *this << "\n\n";
	} // foo

	// полиморфная реализация перегрузки оператора вывода
	virtual ostream &show(ostream &os) {
		os << "Derived2: " << a_ << "; " << b_;
		return os;
	} // show
};

