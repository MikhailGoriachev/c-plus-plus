#include "pch.h"
#include "C.h"

ostream &operator<<(ostream &os, const C &c)
{
    os << c.a_ << " " << c.b_;
    return os;
} // operator<<

istream &operator>>(istream &is, C &c)
{
    is >> c.a_ >> c.b_;
    return is;
} // operator>>