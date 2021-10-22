#pragma once
#include "pch.h"

// ����� Pair (���� ������������ �����), ���������� ��������� � ����� ���������� ������������ �����.
class Pair
{
protected:

	// ������������ ����� a
	double a_;

	// ������������ ����� b
	double b_;

public:

	// ����������� �� ���������
	Pair() = default;

	// ����������� ����������������
	Pair(double a, double b)
	{
		setA(a);
		setB(b);
	}

	// ����������� ���������� 
	Pair(const Pair& pair) = default;

	// ���������� 
	~Pair() = default;

	// ���������� �������� ������������
	Pair& operator=(const Pair& pair) = default;

	// ���������

	// ������ a_
	void setA(double a) { a_ = a; }

	// ������ a_
	double getA() const { return a_; }

	// ������ b_
	void setB(double b) { b_ = b; }

	// ������ b_
	double getB() const { return b_; }

	// ������������ a_ �� b_
	double prod() const { return a_ * b_; }
	
	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const Pair& pair)
	{
		os << "A: " << pair.a_ << " B: " << pair.b_;

		return os;
	}
};
