#pragma once
#include"pch.h"

// пример класса с обычными, implicit-конструкторами
class A
{
    int value_;   // пример поля класса

public:
	// набор конструкторов - implicit-конструкторы
    A(): value_() {}
    A(int value): value_(value) {}

    int  getValue() const { return value_; }
    void setValue(int value) { value_ = value; }

    friend ostream &operator<<(ostream &os, const A &a);
    friend istream &operator>>(istream &is, A &a);
};

