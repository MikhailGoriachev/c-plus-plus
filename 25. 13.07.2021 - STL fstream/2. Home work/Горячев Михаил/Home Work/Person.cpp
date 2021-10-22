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

// ������ � �������� ���� 
void Person::write(ofstream& ofs)
{
	ofs.write((const char*)(&number_), sizeof(number_));
	ofs.write(name_,MAX_NAME_SIZE);
	ofs.write((const char*)(&salary_), sizeof(salary_));
	ofs.write((const char*)(&year_), sizeof(year_));
	ofs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ofs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// ������ �� ��������� ����� 
void Person::read(ifstream& ifs)
{
	ifs.read((char*)(&number_), sizeof(number_));
	ifs.read(name_, MAX_NAME_SIZE);
	ifs.read((char*)(&salary_), sizeof(salary_));
	ifs.read((char*)(&year_), sizeof(year_));
	ifs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ifs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// ������ �� ���������� ����� 
void Person::readText(ifstream& ifs)
{
	ifs >> number_;
	// ������� ������� ������� ������ '\n'
	ifs.get();
	ifs.getline(name_, Person::MAX_NAME_SIZE);
	ifs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
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

// ���������� �������� ������ � ����
/*ofstream& operator<<(ofstream& ofs, const Person& person)
{
	ofs << "��������� �����: " << person.number_
		<< "\n������� � ��������: " << person.name_
		<< "\n�����: " << person.salary_
		<< " ��� ����������� �� ������: " << person.year_
		<< " ���������� ������� ���� � ������: " << person.monthWorkDay_
		<< " ���������� ������������ ���� � ������: " << person.completedWorkDay_ << "\n\n";

	return ofs;
}*/

// ���������� �������� ������ � ����
ofstream& operator<<(ofstream& ofs, const Person& person)
{
	ofs << person.number_
		<< "\n" << person.name_
		<< "\n" << person.salary_ << "\n"
		<< person.year_ << " "
		<< person.monthWorkDay_ << " "
		<< person.completedWorkDay_ << "\n";

	return ofs;
}