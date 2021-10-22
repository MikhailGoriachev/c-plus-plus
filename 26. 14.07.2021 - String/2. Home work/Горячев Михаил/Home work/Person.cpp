#include "Person.h"

// ������������ ����� 
const double Person::MAX_SALARY = 1'000'000.;

// ����������� �����
const double Person::MIN_SALARY = 0.;

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
		<< right << color(YELLOW_ON_BLACK) << setw(10) << salary_
		<< color(cl) << " | "
		<< color(YELLOW_ON_BLACK) << setw(4) << year_
		<< color(cl) << " | "
		<< left << color(YELLOW_ON_BLACK) << setw(17) << city_  << right
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(10) << monthWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(10) << completedWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(12) << accrued()
		<< color(cl) << " |\n";
}

// ����� ��������� �������
// void Person::showHead()
// {
// 	cout << " +����+������������+�����������������+������������+������+���������������������+����������������������+��������������+\n"
// 		<< " | N  | ���������  |     ������� �   |   �����    | ���  |  ���������� �������  | ���������� ���������.|    ��������� |\n"
// 		<< " |    |   �����    |      ��������   |            | ����.|     ���� � ������    |     ���� � ������    |              |\n"
// 		<< " +����+������������+�����������������+������������+������+����������������������+����������������������+��������������+\n";
// }

// ����� ��������� �������
void Person::showHead()
{
	cout<< " +����+������������+�����������������+������������+������+�������������������+������������+������������+��������������+\n"
		<< " | N  | ���������  |     ������� �   |   �����    | ���  |       �����       | �����. ���.| �����. ���.|  ���������   |\n"
		<< " |    |   �����    |      ��������   |            | ����.|     ����������    |    ����    |    ����    |              |\n"
		<< " +����+������������+�����������������+������������+������+�������������������+������������+������������+��������������+\n";
}


// ����� �����������-����������� ��� �������
void Person::showLine()
{
	cout << " +����+������������+�����������������+������������+������+�������������������+������������+������������+��������������+\n";
}

// ����� ������� �������� 
void Person::showEmpty()
{
	cout << " |                                                   ��� ������                                                       |\n"
		<< " +����+������������+�����������������+������������+������+�������������������+������������+������������+��������������+\n";

}

// ������ � �������� ���� 
void Person::write(ofstream& ofs)
{

	// ����� ��� ������
	char* buf = new char[BUF_SIZE]{0};

	// ������ �����
	ofs.write((const char*)(&number_), sizeof(number_));

	// ����������� ���� name_ � ����� ��� ������
	memcpy(buf, name_.c_str(), MAX_NAME_SIZE);
	ofs.write(buf,MAX_NAME_SIZE);

	// ������ ������ 
	memset(buf, 0, BUF_SIZE);

	// ����������� ���� city_ � ����� ��� ������
	memcpy(buf, city_.c_str(), MAX_NAME_SIZE);
	ofs.write(buf, MAX_CITY_SIZE);

	// ������ �����
	ofs.write((const char*)(&salary_), sizeof(salary_));
	ofs.write((const char*)(&year_), sizeof(year_));
	ofs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ofs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));

	// �������� ������ �� ������ 
	delete[] buf;
}

// ������ � �������� ���� 
void Person::write(fstream& fs)
{

	// ����� ��� ������
	char* buf = new char[BUF_SIZE] {0};

	// ������ �����
	fs.write((const char*)(&number_), sizeof(number_));

	// ����������� ���� name_ � ����� ��� ������
	memcpy(buf, name_.c_str(), MAX_NAME_SIZE);
	fs.write(buf, MAX_NAME_SIZE);

	// ������ ������ 
	memset(buf, 0, BUF_SIZE);

	// ����������� ���� city_ � ����� ��� ������
	memcpy(buf, city_.c_str(), MAX_NAME_SIZE);
	fs.write(buf, MAX_CITY_SIZE);

	// ������ �����
	fs.write((const char*)(&salary_), sizeof(salary_));
	fs.write((const char*)(&year_), sizeof(year_));
	fs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	fs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));

	// �������� ������ �� ������ 
	delete[] buf;
}

// ������ �� ��������� ����� 
void Person::read(ifstream& ifs)
{
	// ����� ��� ������ 
	char* buf = new char[BUF_SIZE];

	ifs.read((char*)(&number_), sizeof(number_));
	ifs.read(buf, MAX_NAME_SIZE);	// ������ � �����
	name_ = buf;					// ������������ ������ �� ������ 
	ifs.read(buf, MAX_CITY_SIZE);	// ������ � �����
	city_ = buf;					// ������������ ������ �� ������ 
	ifs.read((char*)(&salary_), sizeof(salary_));
	ifs.read((char*)(&year_), sizeof(year_));
	ifs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ifs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// ������ �� ��������� ����� 
void Person::read(fstream& fs)
{
	// ����� ��� ������ 
	char* buf = new char[BUF_SIZE];

	fs.read((char*)(&number_), sizeof(number_));
	fs.read(buf, MAX_NAME_SIZE);	// ������ � �����
	name_ = buf;					// ������������ ������ �� ������ 
	fs.read(buf, MAX_CITY_SIZE);	// ������ � �����
	city_ = buf;					// ������������ ������ �� ������ 
	fs.read((char*)(&salary_), sizeof(salary_));
	fs.read((char*)(&year_), sizeof(year_));
	fs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	fs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// ������ �� ���������� ����� 
void Person::readText(ifstream& ifs)
{
	ifs >> number_;
	// ������� ������� ������� ������ '\n'
	ifs.get();
	getline(ifs, name_);
	getline(ifs, city_);
	ifs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
}

// ������ �� ���������� ����� 
void Person::readText(fstream& fs)
{
	fs >> number_;
	// ������� ������� ������� ������ '\n'
	fs.get();
	getline(fs, name_);
	getline(fs, city_);
	fs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
}

// ���������� �������� ������
ostream& operator<<(ostream& os, const Person& person)
{
	cout << "\t��������� �����: " << person.number_
		<< "\n\t������� � ��������: " << person.name_
		<< "\n\t����� ����������: " << person.city_
		<< "\n\t�����: " << person.salary_
		<< "\n\t��� ����������� �� ������: " << person.year_
		<< "\n\t���������� ������� ���� � ������: " << person.monthWorkDay_
		<< "\n\t���������� ������������ ���� � ������: " << person.completedWorkDay_ << "\n";

	return os;
}

// ���������� �������� ������ � ����
ofstream& operator<<(ofstream& ofs, const Person& person)
{
	ofs << person.number_ << "\n" 
		<< person.name_ << "\n" 
		<< person.city_ << "\n"
		<< person.salary_ << " "
		<< person.year_ << " "
		<< person.monthWorkDay_ << " "
		<< person.completedWorkDay_ << "\n";

	return ofs;
}

// ���������� �������� ������ � ����
fstream& operator<<(fstream& fs, const Person& person)
{
	fs << person.number_ << "\n"
		<< person.name_ << "\n"
		<< person.city_ << "\n"
		<< person.salary_ << " "
		<< person.year_ << " "
		<< person.monthWorkDay_ << " "
		<< person.completedWorkDay_ << "\n";

	return fs;
}