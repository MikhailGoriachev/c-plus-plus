#pragma once
#include "pch.h"

// ������� ����� � ������������ ��������
class C
{
protected:
	int c_;

public:
	// ����� foo() ������ ������ ������ ����� ����������  - ������������
	// �� ����� ���������� - �.�. foo() �����������
	void f()   { foo(); }
	
	// ������� ���������� - ������� ������� ���������� ����������
	// ����� ����� ����� ��������
	virtual void foo() { c_ = 1; cout << "C::foo()\n"; }
	// virtual void foo() const { cout << "C::foo() const\n"; }
};

