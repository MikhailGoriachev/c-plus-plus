#include "NodePlanec.h"

// ���������� �������� ������
ostream& operator<<(ostream& os, NodePlanec& nodePlanec)
{
	os << nodePlanec.payload_;
	return os;
}