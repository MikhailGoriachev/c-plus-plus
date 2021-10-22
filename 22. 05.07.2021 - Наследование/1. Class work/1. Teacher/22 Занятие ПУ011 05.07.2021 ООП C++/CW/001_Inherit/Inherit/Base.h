#pragma once
#include "pch.h"

// ������� ����� ��� ������������, �� ���� ����� �������������
// ������� == �����-����� == ������/��������
class Base
{
	// private
	int a_;

// ������� ������� protected:
// ����� � ����������� ������ (������-����������), �� �������� �������� ����
protected:
	int b_;

public:
	Base(): a_(), b_() { cout << "Base: ����������� �� ���������\n"; }
	Base(int a, int b): a_(a), b_(b) { cout << "Base: ����������� � �����������\n"; }
	Base(const Base &base): a_(base.a_), b_(base.b_) { cout << "Base: ���������� �����������\n"; }
	~Base() { cout << "Base: ����������\n"; }

	int getA() const { return a_; }
	int getB() const { return b_; }

	void setA(int value) { a_ = value; }
	void setB(int value) { b_ = value; }

	friend ostream &operator<<(ostream &os, const Base &base);
};

