#pragma once
#include "pch.h"

// базовый класс
class A
{
protected:
	int a_;

public:
	A():a_() {  }
	
	// раннее связывание - компилятор связал имя foo() с методом класса A
	void f()   { foo(); }

	void foo() { a_ = 1; cout << "A::foo()\n"; }
};

