#include "Node.h"

// пергрузка оперции вывода 
ostream& operator<<(ostream& os, Node& node)
{
	os << node.payload_;

	return os;
}