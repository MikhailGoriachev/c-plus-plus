#pragma once
#include "pch.h"
#include "Base.h"

// ����������� ����� ����� ��������� ������ �� ����������
// ��������� ���������� �����
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

	// ����������� ���������� ���������� ��������� ������
	virtual ostream &show(ostream &os) {
		os << "Derived2: " << a_ << "; " << b_;
		return os;
	} // show
};

