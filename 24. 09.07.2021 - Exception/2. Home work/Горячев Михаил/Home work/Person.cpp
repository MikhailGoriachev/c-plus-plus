#include "Person.h"

// ������������ ����� 
const double Person::MAX_SALARY = 1'000'000.;

// ����������� �����
const double Person::MIN_SALARY = 0.;

/*
	// ��������� �����, ����� �����, ���������� � �������� ���������� unsigned int
	unsigned int number_;

	// ������� � �������� � ������������ ����, char*
	char* name_;

	// �����, ������������ �����, double
	double salary_;

	// ��� ����������� �� ������, int
	int year_;

	// ���������� ������� ���� � ������, int
	int monthWorkDay_;

	// ���������� ���������� ������������ ���� � ������, int
	int completedWorkDay_;

*/

// ����� �������� ��� �������
// ��������� ����� � ������
void Person::showElem(int i) 
{
	// ������� ���� 
	short cl = getColor();

	cout << fixed;

	cout.precision(2);

	cout << " | "
		<< setw(2) << i
		<< " | "
		<< right << color(YELLOW_ON_BLACK) << setw(10) << number_
		<< color(cl) << " | "
		<< left << color(YELLOW_ON_BLACK) << setw(15) << name_
		<< color(cl) << " | "
		<< right<< color(YELLOW_ON_BLACK) << setw(10) << salary_
		<< color(cl) << " | "
		<< color(YELLOW_ON_BLACK) << setw(4) << year_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(20) << monthWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(20) << completedWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(12) << accrued()
		<< color(cl) << " |\n";
}

// ����� ��������� �������
void Person::showHead()
{
	cout << " +����+������������+�����������������+������������+������+����������������������+����������������������+��������������+\n"
		<< " | N  | ���������  |     ������� �   |   �����    | ���  |  ���������� �������  | ���������� ���������.|    ��������� |\n"
		<< " |    |   �����    |      ��������   |            | ����.|     ���� � ������    |     ���� � ������    |              |\n"
		<< " +����+������������+�����������������+������������+������+����������������������+����������������������+��������������+\n";
}

// ����� �����������-����������� ��� �������
void Person::showLine()
{
	cout << " +����+������������+�����������������+������������+������+����������������������+����������������������+��������������+\n";
}

// ����� ������� �������� 
void Person::showEmpty()
{
	cout << " |                                                   ��� ������                                                       |\n"
		<< " +��������������������������������������������������������������������������������������������������������������������+\n";

}

// ���������� �������� ������
ostream& operator<<(ostream& os, const Person& person)
{
	cout << "\t��������� �����: " << person.number_
		<< "\n\t������� � ��������: " << person.name_
		<< "\n\t�����: " << person.salary_
		<< "\n\t��� ����������� �� ������: " << person.year_
		<< "\n\t���������� ������� ���� � ������: " << person.monthWorkDay_
		<< "\n\t���������� ������������ ���� � ������: " << person.completedWorkDay_ << "\n";

	return os;
}