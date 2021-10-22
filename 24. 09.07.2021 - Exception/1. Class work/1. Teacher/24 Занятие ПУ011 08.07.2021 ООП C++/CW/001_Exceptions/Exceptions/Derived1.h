#pragma once
#include "pch.h"
#include "Base.h"

// ����������� ����� ����� ��������� ������ �� ����������
// ��������� ���������� �����

class Derived1: public Base<double>
{
public:
	Derived1() = default;
	Derived1(double a, double b): Base(a, b) {}
	Derived1(const Derived1 &obj) = default;
	virtual ~Derived1() = default;

	void foo() {
		cout << "    Derived1<double>: foo, " << *this << "\n\n";
	} // foo

	// ����������� ���������� ���������� ��������� ������
	virtual ostream &show(ostream &os) {
		os << "Derived1: " << a_ << "; " << b_;
		return os;
	} // show
};

