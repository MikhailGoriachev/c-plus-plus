#include "pch.h"
#include "Node.h"

// ����� ������ ���� ������
ostream& operator<<(ostream& os, const Node& node)
{
	os << node.payload_;
	return os;
} // operator<<