#pragma once

#include "pch.h"
#include "Date.h"

// ����� Person, �������������� ������ � ������ ���������� ������, ����
// ������ �������, ���, ��������(��� ��� ���� ���� char*), ���� � �����������(��� double),
// ��� � �����������(��� double), ����� ����������(��� char*).

// ����� ������ �������� ������
class Person
{
public:

#pragma region ��������� �������� 

	// ������������ ����� �������
	static const int SURNAME_MAX_SIZE = 50;

	// ����������� ����� �������
	static const int SURNAME_MIN_SIZE = 1;

	// ������������ ����� ����� 
	static const int NAME_MAX_SIZE = 40;

	// ����������� ����� �����
	static const int NAME_MIN_SIZE = 1;

	// ������������ ����� �������� 
	static const int PATRONYMIC_MAX_SIZE = 50;

	// ����������� ����� �������� 
	static const int PATRONYMIC_MIN_SIZE = 3;

	// ������������ ���� � �����������
	static const double HEIGHT_MAX;
	
	// ����������� ���� � �����������
	static const double HEIGHT_MIN;

	// ������������ ��� � �����������
	static const double WEIGHT_MAX;

	// ����������� ��� � �����������
	static const double WEIGHT_MIN;

	// ���������� ����� �������� ������
	static const int CITY_MAX_SIZE = 90;
	
	// ������������ ����� �������� ������
	static const int CITY_MIN_SIZE = 1;

#pragma endregion

private:

	// �������
	char* surname_;

	// ���
	char* name_;

	// ��������
	char* patronymic_;

	// ���� � �����������
	double height_;

	// ��� � �����������
	double weight_;

	// ����� ����������
	char* city_;

public:

#pragma region ������������, ���������� � ���������� ������������

	// ����������� �� ���������
	Person()
	{
		// ��������� ������ ��� ����� ���� char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};
		city_ = new char[CITY_MAX_SIZE + 1];
	}

	// ����������� ����������������
	Person(const char* surname, const char* name, const char* patronymic, double height, double weight, const char* city)
	{
		// ��������� ������ ��� ����� ���� char*
		surname_ = new char[SURNAME_MAX_SIZE + 1]{ 0 };
		name_ = new char[NAME_MAX_SIZE + 1]{ 0 };
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1]{ 0 };
		city_ = new char[CITY_MAX_SIZE + 1];
		
		// ��������� ��������
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setHeight(height);
		setWeight(weight);
		setCity(city);
	}

	// ����������� ����������
	Person(const Person& person) :
		height_(person.height_),
		weight_(person.weight_)
	{
		// ��������� ������ ��� ����� ���� char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};
		city_ = new char[CITY_MAX_SIZE + 1];

		// ����������� ��������
		memcpy(surname_, person.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, person.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, person.patronymic_, PATRONYMIC_MAX_SIZE);
		memcpy(city_, person.city_, CITY_MAX_SIZE);
	}
	
	// ����������
	~Person()
	{
		delete[]surname_;
		delete[]name_;
		delete[]patronymic_;
		delete[]city_;
	}

	// ���������� �������� ������������
	Person& operator=(const Person& person)
	{
		// ������������ 
		height_ = person.height_;
		weight_ = person.weight_;

		// ����������� ��������
		memcpy(surname_, person.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, person.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, person.patronymic_, PATRONYMIC_MAX_SIZE);
		memcpy(city_, person.city_, CITY_MAX_SIZE);

		return *this;
	}

#pragma endregion

#pragma region ������� � �������

	// ������ surname_ const char*
	void setSurname(const char* surname)
	{
		// ����� ������
		int size = strlen(surname);

		// ���� ������ �����������
		if (size < SURNAME_MIN_SIZE && size > SURNAME_MAX_SIZE)
			throw exception("Person: ������ �����������!");

		// ����������� ������
		strcpy(surname_, surname);
	}

	// ������ surname_
	char* getSurname()
	{
		// �������� ������ ��� ����������� ��������
		char* tmp = new char[SURNAME_MAX_SIZE + 1];

		// ����������� �������� 
		memcpy(tmp, surname_, SURNAME_MAX_SIZE);

		return tmp;
	}

	// ������ name_ const char*
	void setName(const char* name)
	{
		// ����� ������
		int size = strlen(name);

		// ���� ������ �����������
		if (size < NAME_MIN_SIZE && size > NAME_MAX_SIZE)
			throw exception("Person: ������ �����������!");

		// ����������� ������
		strcpy(name_, name);
	}

	// ������ name_
	char* getName()
	{
		// �������� ������ ��� ����������� ��������
		char* tmp = new char[NAME_MAX_SIZE + 1];

		// ����������� �������� 
		memcpy(tmp, name_, NAME_MAX_SIZE);

		return tmp;
	}

	// ������ patronymic_ const char*
	void setPatronymic(const char* patronymic)
	{
		// ����� ������
		int size = strlen(patronymic);

		// ���� ������ �����������
		if (size < PATRONYMIC_MIN_SIZE && size > PATRONYMIC_MAX_SIZE)
			throw exception("Person: ������ �����������!");

		// ����������� ������
		strcpy(patronymic_, patronymic);
	}

	// ������ patronymic_
	char* getPatronymic()
	{
		// �������� ������ ��� ����������� ��������
		char* tmp = new char[PATRONYMIC_MAX_SIZE + 1];

		// ����������� �������� 
		memcpy(tmp, patronymic_, PATRONYMIC_MAX_SIZE);

		return tmp;
	}

	// ������ height_
	void setHeight(double height)
	{
		// ���� ������ �����������
		if (height < HEIGHT_MIN && height > HEIGHT_MAX)
			throw exception("Person: ������ �����������!");

		// ����������� �������� 
		height_ = height;
	}

	// ������ height_
	double getHeight() { return height_; }

	// ������ weight_
	void setWeight(double weight)
	{
		// ���� ������ �����������
		if (weight < WEIGHT_MIN && weight > WEIGHT_MAX)
			throw exception("Person: ������ �����������!");

		// ����������� �������� 
		weight_ = weight;
	}

	// ������ weight_
	double getWeight() { return weight_; }

	// ������ city_ const char*
	void setCity(const char* city)
	{
		// ����� ������
		int size = strlen(city);

		// ���� ������ �����������
		if (size < CITY_MIN_SIZE && size > CITY_MAX_SIZE)
			throw exception("Person: ������ �����������!");

		// ����������� ������
		strcpy(city_, city);
	}

	// ������ city_
	char* getCity()
	{
		// �������� ������ ��� ����������� ��������
		char* tmp = new char[CITY_MAX_SIZE + 1];

		// ����������� �������� 
		memcpy(tmp, city_, CITY_MAX_SIZE);

		return tmp;
	}


#pragma endregion

#pragma region ������

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const Person& person);

#pragma endregion
};

