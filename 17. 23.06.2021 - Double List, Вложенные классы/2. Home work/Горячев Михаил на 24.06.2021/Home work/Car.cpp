#include "Car.h"

// ���������� �������� ������ 
ostream& operator<<(ostream& os, const Car& car)
{
	os << "\n\t\t�����: " << car.number_
		<< "; ����: " << car.color_
		<< "; �����: " << car.brand_;

	return os;
}