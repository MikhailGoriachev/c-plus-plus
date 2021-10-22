#pragma once
#include "pch.h"
#include "Utils.h"

// ����� Person, �������������� ������ � ������ ���������� ������, ���� ������ �������, ���, �������� (��� ��� ���� ���� char *), 
// ���� � ����������� (��� double), ��� � ����������� (��� double), ����� ���������� (��� char *).
class Person
{
public:
	// ���������
	static const int NAME_SIZE = 30;
	static const int SURNAME_SIZE = 30;
	static const int PARTRONUMIC_SIZE = 30;
	static const int CURRENTCITY_SIZE = 30;
	const double MAX_HEIGHT = 300;
	const double MAX_WEIGHT = 500;


	// ���� ������
private:
	char* surname_;			// �������
	char* name_;				// ���
	char* patronymic_;		// ��������
	double height_;			// ���� � ��
	double weight_;			// ��� � ����������� 
	char* currentCity_;		// ����� ����������

	// ������
public:

	//�������� �������������
	Person() : Person("������","����","��������",175,70,"������") {  }
	Person(const char* surname, const char* name, const char* patronymic, double height, double weight, const char* currentCity) 
		: surname_(new char[SURNAME_SIZE] {0}), 
		name_(new char[NAME_SIZE] {0}), 
		patronymic_(new char[PARTRONUMIC_SIZE] {0}), 
		currentCity_(new char[CURRENTCITY_SIZE] {0}) {

		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setHeight(height);
		setWeight(weight);
		setCurrentCity(currentCity);
		

	}
	Person(const Person& person) 
		:surname_(new char[SURNAME_SIZE] {0}),
		name_(new char[NAME_SIZE] {0}),
		patronymic_(new char[PARTRONUMIC_SIZE] {0}),
		currentCity_(new char[CURRENTCITY_SIZE] {0}),
		height_(person.height_), weight_(person.weight_)  {

		strncpy(surname_, person.surname_, SURNAME_SIZE);
		strncpy(name_, person.name_, NAME_SIZE);
		strncpy(patronymic_, person.patronymic_, PARTRONUMIC_SIZE);
		strncpy(currentCity_, person.currentCity_, CURRENTCITY_SIZE);

	}
	~Person() {	
		delete[] surname_;
		delete[] name_;
		delete[] patronymic_;
		delete[] currentCity_;
	}


	// �������

	char* getSurname() { return surname_; }
	char* getName() { return name_; }
	char* getPatronymic() { return patronymic_; }
	double  getHeight() { return height_; }
	double  getWeight() { return weight_; }
	char* getCurrentCity() { return currentCity_; }

	// �������
	void setSurname(const char* surname);
	void setName(const char* name);
	void setPatronymic(const char* patronymic);
	void setHeight(double height);
	void setWeight(double weight);
	void setCurrentCity(const char* currentCity);

	// �������� ������������
	Person& operator=(const Person& person)
	{
		// ������ �� ����������������
		if (&person == this) return *this;

		memset(surname_, 0, SURNAME_SIZE);
		strncpy(surname_, person.surname_, SURNAME_SIZE);

		memset(name_, 0, NAME_SIZE);
		strncpy(name_, person.name_, NAME_SIZE);

		memset(patronymic_, 0, PARTRONUMIC_SIZE);
		strncpy(patronymic_, person.patronymic_, PARTRONUMIC_SIZE);

		memset(currentCity_, 0, CURRENTCITY_SIZE);
		strncpy(currentCity_, person.currentCity_, CURRENTCITY_SIZE);

		height_ = person.height_;
		weight_ = person.weight_;


		return *this;
	} // operator=

	static int getRecordSize() { return SURNAME_SIZE + NAME_SIZE + PARTRONUMIC_SIZE + 2 * sizeof(double) + CURRENTCITY_SIZE; }


	// �������� ������
	static ostream& showHeader(ostream& os) {

		os  << "\n\t+��������������������������+�������������������������+�������������������������+��������+�������+�������������������������+"
			<< "\n\t|�������                   |���                      |��������                 |  ����  |  ���  |����� ����������         |"//17
			<< "\n\t+��������������������������+�������������������������+�������������������������+��������+�������+�������������������������+";

		return os;




	}

	static ostream& showFooter(ostream& os) {

		os << "\n\t+�������������������������+��������������������������+�������������������������+��������+�������+�������������������������+\n";

		return os;




	}

	friend ostream& operator<<(ostream& os, const Person person)
	{

		os << endl << "\t| " << left << setw(25)  << person.surname_
			<< "|" << setw(25)  << person.name_ 
			<< "|" << setw(25)  << person.patronymic_
			<< "|" << right <<setprecision(2)<< setw(8)  << person.height_
			<< "|" << right << setw(7)  << person.weight_
			<< "|" << setw(25) << left << person.currentCity_ << "|";

		return os;
	} // operator<<



	// ������ � �������� ����, ���� ������ ���� ������
	void write(FILE *f);

	// ������ �� ��������� �����, ���� ������ ���� ������
	void read(FILE* f);
};

