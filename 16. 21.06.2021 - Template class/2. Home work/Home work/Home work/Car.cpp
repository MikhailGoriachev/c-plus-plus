#include "Car.h"

// ���������� �������� ������ 
ostream& operator<<(ostream& os, const Car& car)
{
	os << "�����: " << car.number_
		<< "\n����: " << car.color_
		<< "\n�����: " << car.brand_;

	return os;
}