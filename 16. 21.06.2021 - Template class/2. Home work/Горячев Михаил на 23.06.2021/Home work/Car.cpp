#include "Car.h"

// перегрузка операции вывода 
ostream& operator<<(ostream& os, const Car& car)
{
	os << "Номер: " << car.number_
		<< "\nЦвет: " << car.color_
		<< "\nМарка: " << car.brand_;

	return os;
}