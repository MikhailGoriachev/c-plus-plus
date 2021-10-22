#include "Person.h"
#include "pch.h"

// ������������ ���� � �����������
const double Person::HEIGHT_MAX = 300.;

// ����������� ���� � �����������
const double Person::HEIGHT_MIN = 10.;

// ������������ ��� � �����������
const double Person::WEIGHT_MAX = 300.;

// ����������� ��� � �����������
const double Person::WEIGHT_MIN = 1.;


// ���������� �������� ������
ostream& operator<<(ostream& os, const Person& person)
{
	os << "\t�������: " << person.surname_
		<< "\n\t���: " << person.name_
		<< "\n\t��������: " << person.patronymic_
		<< "\n\t���� (��): " << person.height_
		<< "\n\t��� (��): " << person.weight_
		<< "\n\t�����: " << person.city_ << "\n";

	return os;
}