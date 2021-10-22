#include "pch.h"
#include "B.h"

ostream &operator<<(ostream &os, const B &b)
{
    os << b.value_;
    return os;
} // operator<<

istream &operator>>(istream &is, B &b)
{
    is >> b.value_;
    return is;
} // operator>>