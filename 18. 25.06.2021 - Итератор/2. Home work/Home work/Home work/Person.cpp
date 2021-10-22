#include "Person.h"
#include "pch.h"

// ����������� ������� ��������
const double Person::AREA_MAX = 600.;

// ����������� ������� ��������
const double Person::AREA_MIN = 10.;

// ���������� �������� ������
ostream& operator<<(ostream& os, const Person& person)
{
	os << "\t�������: " << person.surname_
		<< "\n\t���: " << person.name_
		<< "\n\t��������: " << person.patronymic_
		<< "\n\t���������� ������ �����: " << person.countFamily_
		<< "\n\t������� ��������: " << person.area_
		<< "\n\t���������� ������: " << person.countRoom_
		<< "\n\t���� ���������� �� ����: " << person.date_ << "\n";

	return os;
}