#include "pch.h"
#include "StackTiangle.h"

ostream& operator<<(ostream& os, const StackTriangle& stack)
{
	if (stack.isEmpty())
		os << "стек пуст";
	else
		for (int i = stack.top_ - 1; i >= 0; --i)
			os << stack.data_[i] << "\n";
	
	return os;
}
