#include "Person.h"
#include "pch.h"

// максимальна площадь квартиры
const double Person::AREA_MAX = 600.;

// минимальная площадь квартиры
const double Person::AREA_MIN = 10.;

// перегрузка операции вывода
ostream& operator<<(ostream& os, const Person& person)
{
	os << "\tФамилия: " << person.surname_
		<< "\n\tИмя: " << person.name_
		<< "\n\tОтчество: " << person.patronymic_
		<< "\n\tКоличество членов семьи: " << person.countFamily_
		<< "\n\tПлощадь квартиры: " << person.area_
		<< "\n\tКоличество комнат: " << person.countRoom_
		<< "\n\tДата постановки на учёт: " << person.date_ << "\n";

	return os;
}