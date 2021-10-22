#include "pch.h"
#include "Base.h"

ostream &operator<<(ostream &os, const Base &base)
{
	os << "base.a_ = " << base.a_ << "; base.b_ = " << base.b_;
	return os;
}
