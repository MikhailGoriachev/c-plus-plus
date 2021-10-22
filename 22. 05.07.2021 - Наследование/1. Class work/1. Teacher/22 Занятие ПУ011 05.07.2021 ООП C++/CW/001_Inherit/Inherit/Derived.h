#pragma once
#include "pch.h"
#include "Base.h"

// Производный от Base класс - класс, наследник Base, потомок, дочерний класс

// синтаксис наследования
// class ИмяКласса: режим1 Базовый1, режим2 Базовый2, ..., режимN БазовыйN
// Режимы наследования
//              Базовый     Производный
// public       private     не доступно
//              protected   protected
//              public      public
// ————————————————————————————————————————
// protected    private     не доступно
//              protected   protected
//              public      protected
// ————————————————————————————————————————
// private      private     не доступно
//              protected   private
//              public      private
class Derived :public Base  // класс Derived в открытую наследуется от Base  
{
protected:
	int c_;

public:
	// конструкторы
	Derived() :/* Base(), */ c_() { cout << "Derived: конструктор по умолчанию\n"; }

	// синтаксис конструктора с параметрами
	// порядок вызова: базовый класс -> производный класс
	Derived(int a, int b, int c):Base(a, b), c_(c) { cout << "Derived: конструктор с параметрами\n"; }

	// порядок вызова: производный класс -> базовый класс
	~Derived() { cout << "Derived: деструктр\n"; }

	int getC() const { return c_; }
	void setC(int value)  { c_ = value; }

	friend ostream& operator<<(ostream &os, const Derived &derived);
};

