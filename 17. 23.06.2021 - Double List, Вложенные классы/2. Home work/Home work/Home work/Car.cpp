#include "Car.h"

// перегрузка операции вывода 
ostream& operator<<(ostream& os, const Car& car)
{
	os << "\n\t\tНомер: " << car.number_
		<< "; Цвет: " << car.color_
		<< "; Марка: " << car.brand_;

	return os;
}