#pragma once
#include "pch.h"
#include "C.h"

class D : public C
{
public:
	// переопределение виртуального метода базового класс D
	virtual void foo() override { cout << "D::foo()\n"; }
	// void foo() { cout << "D::foo()\n"; }

	// void foo() const { cout << "D::foo() const\n"; }
	void bar() { cout << "D::bar()\n"; }
};

