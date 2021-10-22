#include "Person.h"

void Person::setSurname(const char* surname) {

	if (strlen(surname) > SURNAME_SIZE)
		throw exception("Person: ������ ����� ���");

	memset(surname_, 0, SURNAME_SIZE);
	strncpy(surname_, surname, SURNAME_SIZE);


}
void Person::setName(const char* name) {

	if (strlen(name) > NAME_SIZE)
		throw exception("Person: ������ ����� ���");

	memset(name_, 0, NAME_SIZE);
	strncpy(name_, name, NAME_SIZE);
}
void Person::setPatronymic(const char* patronymic) {

	if (strlen(patronymic) > PARTRONUMIC_SIZE)
		throw exception("Person: ������ ����� ���");

	memset(patronymic_, 0, PARTRONUMIC_SIZE);
	strncpy(patronymic_, patronymic, PARTRONUMIC_SIZE);
}
void Person::setHeight(double height) {

	if (height > MAX_HEIGHT)
		throw exception("Person: ������ ����� height");

	height_ = height;


}
void Person::setWeight(double weight) {

	if (weight > MAX_WEIGHT)
		throw exception("Person: ������ ����� height");

	weight_ = weight;

}
void Person::setCurrentCity(const char* currentCity) {

	if (strlen(currentCity) > CURRENTCITY_SIZE)
		throw exception("Person: ������ ����� ���");

	memset(currentCity_, 0, CURRENTCITY_SIZE);
	strncpy(currentCity_, currentCity, CURRENTCITY_SIZE);

}

// ������ � �������� ����, ���� ������ ���� ������
void Person::write(FILE* f)
{
	/*
	static const int NAME_SIZE = 30;
	static const int SURNAME_SIZE = 30;
	static const int PARTRONUMIC_SIZE = 30;
	static const int CURRENTCITY_SIZE = 30;
	
	char* surname_;			// �������
	char* name_;			// ���
	char* patronymic_;		// ��������
	double height_;			// ���� � ��
	double weight_;			// ��� � ����������� 
	char* currentCity_;		// ����� ����������
	 */

	// fwrite(surname_, sizeof(char), SURNAME_SIZE, f);
	// cout << t << "\n";
	
	fwrite(surname_, SURNAME_SIZE, 1, f);
	fwrite(name_, NAME_SIZE, 1, f);
	fwrite(patronymic_, PARTRONUMIC_SIZE, 1, f);
	fwrite(&height_, sizeof(height_), 1, f);
	fwrite(&weight_, sizeof(weight_), 1, f);
	fwrite(currentCity_, CURRENTCITY_SIZE, 1, f);
	
}

// ������ �� ��������� �����, ���� ������ ���� ������
void Person::read(FILE* f)
{

	fread(surname_, SURNAME_SIZE, 1, f);
	fread(name_, NAME_SIZE, 1, f);
	fread(patronymic_, PARTRONUMIC_SIZE, 1, f);
	fread(&height_, sizeof(height_), 1, f);
	fread(&weight_, sizeof(weight_), 1, f);
	fread(currentCity_, CURRENTCITY_SIZE, 1, f);

}
