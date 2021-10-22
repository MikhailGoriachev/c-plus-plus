#include "pch.h"
#include "Stack.h"

ostream& operator<<(ostream& os, const Stack& stack)
{
	if (stack.isEmpty())
		os << "стек пуст";
	else
		for (int i = stack.top_ - 1; i >= 0; --i)
			os << setw(8) << stack.data_[i];

	return os;
}