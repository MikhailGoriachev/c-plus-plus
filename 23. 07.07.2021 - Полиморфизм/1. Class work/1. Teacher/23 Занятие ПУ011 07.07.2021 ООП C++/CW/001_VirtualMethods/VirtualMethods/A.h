#pragma once
#include "pch.h"

// ������� �����
class A
{
protected:
	int a_;

public:
	A():a_() {  }
	
	// ������ ���������� - ���������� ������ ��� foo() � ������� ������ A
	void f()   { foo(); }

	void foo() { a_ = 1; cout << "A::foo()\n"; }
};

