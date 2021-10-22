#pragma once
#include "pch.h"
#include "Date.h"


/*
 * ������� ������� ����������� � ��������� �������� �������. ������ �������,
 * ��� � �������� �����������, ���������� ������ �����, ������� �������� � �2,
 * ���������� ������, ���� ���������� �� ���� (����, �����, ���).
 */
class Applicant
{
public:
	// ����� ������� ��������� ����� ������
	//               �������         ���          ��������
	static const int N_SURNAME = 61, N_NAME = 51, N_PATRONYMIC = 61;

private:
	char*  surname_;        // �������
	char*  name_;           // ���
	char*  patronymic_;     // ��������
	int    familyMembers_;  // ���������� ������ �����
	double area_;           // ������� �������� � �2
	int    rooms_;          // ���������� ������
	Date   acceptDate_;     // ���� ���������� �� ���� (����, �����, ���)

	static const int N_BUF = 1024;
	char* buf_;  // ����� ������ ������ � ��������� �������

public:
	Applicant():Applicant(
		"������", "����", "��������", 
		4, 120.2, 3, 
			Date{1,1,2021})
	{  } // Applicant

	Applicant(const char* surname, const char* name, const char* patronymic, 
		int familyMembers, double area, int rooms, const Date& acceptDate)
		: surname_(new char[N_SURNAME] {0}),
		  name_(new char[N_NAME] {0}),
		  patronymic_(new char[N_PATRONYMIC]), buf_(new char[N_BUF] {0})
	{
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setFamilyMembers(familyMembers);
		setArea(area);
		setRooms(rooms);
		setAcceptDate(acceptDate);
	} // Applicant

	// ���������� �����������
	Applicant(const Applicant& applicant);

	// ����������
	~Applicant()
	{
		delete[] surname_;
		delete[] name_;
		delete[] patronymic_;
		delete[] buf_;
	} // ~Applicant 

	// ��������� ��� ������ � ������ ������
	char* getSurname() const { return surname_; }
	void  setSurname(const char* surname);
	
	char* getName() const { return name_; }
	void  setName(const char* name);

	char* getPatronymic() const { return patronymic_; }
	void  setPatronymic(const char* patronymic);

	int  getFamilyMembers() const { return familyMembers_; }
	void setFamilyMembers(const int familyMembers);

	double getArea() const { return area_; }
	void   setArea(const double area);

	int  getRooms() const { return rooms_; }
	void setRooms(const int rooms);

	Date getAcceptDate() const { return acceptDate_;  }
	void setAcceptDate(const Date& acceptDate);

	// ����� ���������� �������������
	const char* toString() const;


	// ���������� ��������

	bool operator==(const Applicant& applicant) const;

	// ������������
	Applicant& operator=(const Applicant& applicant);

	

	static ostream& showHeader(ostream& os) {

		os  << "\n\t+��������������������������+�������������������������+�������������������������+�������������+����������+������������+�����������������+"
			<< "\n\t|�������                   |���                      |��������                 | ���. ������ | �������  | ���������� | ���� ���������� |"//17
			<< "\n\t|                          |                         |                         |    �����    | �������� |   ������   |     �� ����     |"//17
			<< "\n\t+��������������������������+�������������������������+�������������������������+�������������+����������+������������+�����������������+";

		return os;

	}

	static ostream& showFooter(ostream& os) {

		os << "\n\t+��������������������������+�������������������������+�������������������������+�������������+����������+������������+�����������������+\n";

		return os;




	}

	friend ostream& operator<<(ostream& os, const Applicant& applicant)
	{

		os << endl << "\t| " << left << setw(25) << applicant.surname_
			<< "|" << setw(25) << applicant.name_
			<< "|" << setw(25) << applicant.patronymic_

			<< "|" << right << setprecision(2) << setw(13) << applicant.familyMembers_
			<< "|" << setw(10) << applicant.area_
			<< "|" << setw(12) << applicant.rooms_
			<< "|" << setw(17) << applicant.acceptDate_ << "|";

		return os;
	} // operator<<
};

