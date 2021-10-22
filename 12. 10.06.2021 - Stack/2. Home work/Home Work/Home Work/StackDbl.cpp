#include "StackDbl.h"

ostream& operator<<(ostream& os, StackDbl& stack)
{
	if (stack.isEmpty())
	{
		os << "Stack: стек пуст";
		return os;
	}

	for (size_t i = 0; i < stack.top_; i++)
	{
		os << "\n\t\t" << stack.arr_[i];
	}

	return os;
}
