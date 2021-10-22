#pragma once
#include "pch.h"

// абстрактный шаблонный класс
template <typename T> class Base
{
protected:
	T a_;  // состояние класса
	T b_;

public:
	Base():a_(), b_() {	}
	Base(T a, T b):a_(a), b_(b) {	}
	Base(const Base &base) = default;

	// чистый виртуальный деструктор - может иметь код
	virtual ~Base() = 0 {}
	Base &operator=(Base &base)=default;

	// чистые виртуальные методы - поведение для иерархии классов
	virtual ostream &show(ostream &os) = 0;
	virtual void foo() = 0;

	friend ostream &operator<<(ostream &os, Base<T> &base) {
		return base.show(os);
	}
};

