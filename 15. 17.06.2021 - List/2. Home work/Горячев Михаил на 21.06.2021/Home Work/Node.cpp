#include "Node.h"

// ��������� ������� ������ 
ostream& operator<<(ostream& os, Node& node)
{
	os << node.payload_;

	return os;
}