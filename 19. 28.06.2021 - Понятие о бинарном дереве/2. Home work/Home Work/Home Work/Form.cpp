#include "Form.h"
#include "pch.h"

// ����������� ������� ��������
const double Form::AREA_MAX = 600.;

// ����������� ������� ��������
const double Form::AREA_MIN = 10.;

// ���������� �������� ������
ostream& operator<<(ostream& os, const Form& Form)
{
	os << "\t�������: " << Form.surname_
		<< "\n\t���: " << Form.name_
		<< "\n\t��������: " << Form.patronymic_
		<< "\n\t���������� ������ �����: " << Form.countFamily_
		<< "\n\t������� ��������: " << Form.area_
		<< "\n\t���������� ������: " << Form.countRoom_
		<< "\n\t���� ���������� �� ����: " << Form.date_ << "\n";

	return os;
}