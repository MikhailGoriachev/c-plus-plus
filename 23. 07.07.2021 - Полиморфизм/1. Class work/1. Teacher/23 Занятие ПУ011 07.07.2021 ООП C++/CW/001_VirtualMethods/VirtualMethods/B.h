#pragma once
#include "pch.h"
#include "A.h"

// производный класс
class B : public A
{
public:
	// переопределение метода базового класса
	void foo() { cout << "B::foo()\n"; }

	// метод производного класса
	void bar() { cout << "B::bar()\n"; }
};

