#include "pch.h"
#include "Node.h"

// вывод данных узла списка
ostream& operator<<(ostream& os, const Node& node)
{
	os << node.payload_;
	return os;
} // operator<<