#include "Person.h"
#include "pch.h"

// максимальный рост в сантиметрах
const double Person::HEIGHT_MAX = 300.;

// минимальный рост в сантиметрах
const double Person::HEIGHT_MIN = 10.;

// максимальный вес в киллограмах
const double Person::WEIGHT_MAX = 300.;

// минимальный вес в киллограмах
const double Person::WEIGHT_MIN = 1.;


// перегрузка операции вывода
ostream& operator<<(ostream& os, const Person& person)
{
	os << "\tФамилия: " << person.surname_
		<< "\n\tИмя: " << person.name_
		<< "\n\tОтчество: " << person.patronymic_
		<< "\n\tРост (см): " << person.height_
		<< "\n\tВес (кг): " << person.weight_
		<< "\n\tГород: " << person.city_ << "\n";

	return os;
}