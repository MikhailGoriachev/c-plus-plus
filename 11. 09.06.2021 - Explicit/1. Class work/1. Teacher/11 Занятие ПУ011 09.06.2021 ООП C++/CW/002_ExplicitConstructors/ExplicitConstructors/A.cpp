#include "pch.h"
#include "A.h"

ostream &operator<<(ostream &os, const A &a)
{
    os << a.value_;
    return os;
} // operator<<

istream &operator>>(istream &is, A &a)
{
    is >> a.value_;
    return is;
} // operator>>