#include "Form.h"
#include "pch.h"

// максимальна площадь квартиры
const double Form::AREA_MAX = 600.;

// минимальная площадь квартиры
const double Form::AREA_MIN = 10.;

// перегрузка операции вывода
ostream& operator<<(ostream& os, const Form& Form)
{
	os << "\tФамилия: " << Form.surname_
		<< "\n\tИмя: " << Form.name_
		<< "\n\tОтчество: " << Form.patronymic_
		<< "\n\tКоличество членов семьи: " << Form.countFamily_
		<< "\n\tПлощадь квартиры: " << Form.area_
		<< "\n\tКоличество комнат: " << Form.countRoom_
		<< "\n\tДата постановки на учёт: " << Form.date_ << "\n";

	return os;
}