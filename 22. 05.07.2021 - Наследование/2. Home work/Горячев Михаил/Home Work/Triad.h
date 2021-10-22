#pragma once

#include "pch.h"

// ����� Triad(��� ������������ �����), ���������� ��������� �
// ����� ���������� ����� �����
class Triad
{
protected:

	// ������ ������������ �����
	double a_;
	
	// ������ ������������ �����
	double b_;
	
	// ������ ������������ �����
	double c_;

public:

	// ����������� �� ���������
	Triad() = default;

	// ����������� ����������������
	Triad(double a, double b, double c)
	{
		setA(a);
		setB(b);
		setC(c);
	}

	// ����������� ���������� 
	Triad(const Triad& triad) = default;

	// ���������� 
	~Triad() = default;

	// ���������� �������� ������������
	Triad& operator=(const Triad& triad) = default;

	// ���������

	// ������ a_
	void setA(double a) { a_ = a; }

	// ������ a_
	double getA() const { return a_; }

	// ������ b_
	void setB(double b) { b_ = b; }

	// ������ b_
	double getB() const { return b_; }

	// ������ c_
	void setC(double c) { c_ = c; }

	// ������ c_
	double getC() const { return c_; }

	// ����� a_, b_, c_
	double prod() const { return a_ + b_ + c_; }

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream & os, const Triad& triad)
	{
		os << "A: " << triad.a_ << " B: " << triad.b_ << " C: " << triad.c_;

		return os;
	}

};

