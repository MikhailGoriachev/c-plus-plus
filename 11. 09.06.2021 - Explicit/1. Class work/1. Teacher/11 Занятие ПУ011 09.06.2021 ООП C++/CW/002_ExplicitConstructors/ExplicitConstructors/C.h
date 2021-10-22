#pragma once
#include "pch.h"

// пример класса с explicit-конструктором
class C
{
    double a_;
    int b_;

public:
    C(): a_(), b_() {}
    explicit C(double a, int b): a_(a), b_(b) {}

    double  getA() const { return a_; }
    void setA(double value) { a_ = value; }

    int  getB() const { return b_; }
    void setB(int value) { b_ = value; }

    friend ostream &operator<<(ostream &os, const C &c);
    friend istream &operator>>(istream &is, C &c);
};

