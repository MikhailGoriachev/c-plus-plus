#pragma once
#include "pch.h"

// пример класса с explicit-конструктором 
class B
{
    int value_;

public:
    B(): value_() {}
	
    // explicit - запрет неявного вызова конструктора
    // B b = 1; -- такой синтаксис запрещается
    // B b(1);  -- такой синтаксис разрешен, явный вызов конструктора
    explicit B(int value): value_(value) {}

    int  getValue() const { return value_; }
    void setValue(int value) { value_ = value; }

    friend ostream &operator<<(ostream &os, const B &b);
    friend istream &operator>>(istream &is, B &b);
};

