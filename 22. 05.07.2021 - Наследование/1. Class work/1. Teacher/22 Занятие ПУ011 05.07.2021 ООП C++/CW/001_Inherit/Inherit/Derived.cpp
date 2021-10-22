#include "Derived.h"

// перегруженный оператор вывод дл€ производного класса
ostream& operator<<(ostream& os, const Derived& derived)
{
	// вывод производного класса, затем вывод пол€/полей
	// производного класса
	// принцип подстановки Ћисков (Ѕарбара Ћисков)
	// вместо призводного класса модно использовать базовый 
	os << (const Base &)derived << ", derived.c_ = " << derived.c_;
	// os << static_cast<const Base&>(derived) << ", derived.c_ = " << derived.c_;
	return os;
} // operator<<