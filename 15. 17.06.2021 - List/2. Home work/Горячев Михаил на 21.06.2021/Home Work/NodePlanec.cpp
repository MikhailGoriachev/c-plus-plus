#include "NodePlanec.h"

// перегрузка операции вывода
ostream& operator<<(ostream& os, NodePlanec& nodePlanec)
{
	os << nodePlanec.payload_;
	return os;
}