#include "pch.h"
#include "Applicant.h"


// ���������� �����������
Applicant::Applicant(const Applicant& applicant) :
    surname_   (new char[N_SURNAME] {0}),
    name_      (new char[N_NAME] {0}),
    patronymic_(new char[N_PATRONYMIC]),
    buf_       (new char[N_BUF] {0})
{
	strcpy(surname_, applicant.surname_);
	strcpy(name_, applicant.name_);
	strcpy(patronymic_, applicant.patronymic_);

	familyMembers_ = applicant.familyMembers_;
	area_ = applicant.area_;
	rooms_ = applicant.rooms_;

	acceptDate_ = applicant.acceptDate_;
} // Applicant::Applicant 

// ���������� ������� ������ ������������ �� ��������� �������� �������

// �������
void Applicant::setSurname(const char* surname)
{
	memset(surname_, 0, N_SURNAME);
	strncpy(surname_, surname, N_SURNAME-1);
} // Applicant::setSurname


// ���
void Applicant::setName(const char* name)
{
	memset(name_, 0, N_NAME);
	strncpy(name_, name, N_NAME-1);
} //  Applicant::setName


// ��������
void Applicant::setPatronymic(const char* patronymic)
{
	memset(patronymic_, 0, N_PATRONYMIC);
	strncpy(patronymic_, patronymic, N_PATRONYMIC-1);
} // Applicant::setPatronymic


// ���������� ������ �����
void Applicant::setFamilyMembers(const int familyMembers)
{
	familyMembers_ = familyMembers;
} // Applicant::setFamilyMembers7


// ������� ��������
void Applicant::setArea(const double area)
{
	area_ = area;
} // Applicant::setArea


// ���������� ������
void Applicant::setRooms(const int rooms)
{
	rooms_ = rooms;
} // Applicant::setRooms


// ���� ���������� � �������
void Applicant::setAcceptDate(const Date& acceptDate)
{
	acceptDate_ = acceptDate;
} // Applicant::setAcceptDate



// ����� ���������� ������������� �������
const char* Applicant::toString() const
{
	sprintf(buf_, "%s %s %s, � �����: %d, �������: %.2lf �2, ������: %d, ��������� � �������: %s", 
		surname_, name_, patronymic_, familyMembers_, area_, 
		rooms_, acceptDate_.toString());
	return buf_;
} // Applicant::toString

bool Applicant::operator==(const Applicant& applicant) const
{
	return strcmp(surname_, applicant.surname_) == 0 and
		strcmp(name_, applicant.name_) == 0 and
		strcmp(patronymic_, applicant.patronymic_) == 0 and
		familyMembers_ == applicant.familyMembers_ and
		area_ == applicant.area_ and
		rooms_ == applicant.rooms_ and
		acceptDate_ == applicant.acceptDate_;
} //  Applicant::operator==


// ������������
Applicant& Applicant::operator=(const Applicant& applicant)
{
	// ������ �� ����������������
	if (&applicant == this) return *this;

	// ����������� �����
	setSurname(applicant.surname_);
	setName(applicant.name_);
	setPatronymic(applicant.patronymic_);

	familyMembers_ = applicant.familyMembers_;
	area_ = applicant.area_;
	rooms_ = applicant.rooms_;
	
	acceptDate_ = applicant.acceptDate_;

	// ������� ������ �� ������
	return *this;
} // Applicant::operator=


//// ����� � ����� ������
//ostream& operator<<(ostream& os, const Applicant& applicant)
//{
//	os << applicant.toString();
//	return os;
//} // operator<<