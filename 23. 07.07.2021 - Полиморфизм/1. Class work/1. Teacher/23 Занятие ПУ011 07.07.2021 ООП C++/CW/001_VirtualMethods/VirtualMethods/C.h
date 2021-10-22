#pragma once
#include "pch.h"

// базовый класс с виртуальными методами
class C
{
protected:
	int c_;

public:
	// метод foo() какого именно класса будет вызываться  - определяется
	// на этапе исполнения - т.к. foo() виртуальный
	void f()   { foo(); }
	
	// позднее связывание - система времени исполнения определяет
	// какой метод будем вызывать
	virtual void foo() { c_ = 1; cout << "C::foo()\n"; }
	// virtual void foo() const { cout << "C::foo() const\n"; }
};

