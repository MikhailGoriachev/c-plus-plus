#pragma once
#include "pch.h"
#include "A.h"

// ����������� �����
class B : public A
{
public:
	// ��������������� ������ �������� ������
	void foo() { cout << "B::foo()\n"; }

	// ����� ������������ ������
	void bar() { cout << "B::bar()\n"; }
};

