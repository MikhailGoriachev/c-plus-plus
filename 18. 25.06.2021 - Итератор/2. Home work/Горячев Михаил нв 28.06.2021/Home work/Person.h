#pragma once

#include "pch.h"
#include "Date.h"

// ������� ������� ������ ������� �������, ��� � �������� �����������, ����������
// ������ �����, ������� �������� � �2, ���������� ������, ���� ���������� �� ����
// (����, �����, �������� Date).

// ����� ������ �������� � �������
class Person
{
public:

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

	// ������������ ���������� ������ �����
	static const int COUNT_FAMILY_MAX = 30;

	// ����������� ���������� ������ �����
	static const int COUNT_FAMILY_MIN = 1;

	// ����������� ������� ��������
	static const double AREA_MAX;

	// ����������� ������� ��������
	static const double AREA_MIN;

	// ������������ ���������� ������
	static const int COUNT_ROOM_MAX = 50;

	// ����������� ���������� ������
	static const int COUNT_ROOM_MIN = 1;

	// ������������ ��� ���������� �� ����
	static const int YEAR_MAX = 2022;

	// ������������ ����� ���������� �� ���� 
	static const int MONTH_MAX = 1;

	// ������������ ����� ���������� �� ����
	static const int NUMBER_MAX = 1;

	// ����������� ��� ���������� �� ����
	static const int YEAR_MIN = 1960;

	// ����������� ����� ���������� �� ���� 
	static const int MONTH_MIN = 1;

	// ����������� ����� ���������� �� ����
	static const int NUMBER_MIN = 1;

private:

	// �������
	char* surname_;

	// ���
	char* name_;

	// ��������
	char* patronymic_;

	// ���������� ������ �����
	int countFamily_;

	// ������� ��������
	double area_;

	// ���������� ������
	int countRoom_;

	// ���� ���������� �� ���� 
	Date date_;

public:

#pragma region ������������, ���������� � ���������� ������������

	// ����������� �� ���������
	Person()
	{
		// ��������� ������ ��� ����� ���� char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};
	}

	// ����������� ����������������
	Person(char* surname, char* name, char* patronymic, int countFamily, double area, int countRoom, Date date)
	{
		// ��������� ������ ��� ����� ���� char*
		surname_ = new char[SURNAME_MAX_SIZE + 1]{ 0 };
		name_ = new char[NAME_MAX_SIZE + 1]{ 0 };
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1]{ 0 };

		// ��������� ��������
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setCountFamily(countFamily);
		setArea(area);
		setCountRoom(countRoom);
		setDate(date);
	}

	// ����������� ����������������
	Person(const char* surname, const char* name, const char* patronymic, int countFamily, double area, int countRoom, Date date)
	{
		// ��������� ������ ��� ����� ���� char*
		surname_ = new char[SURNAME_MAX_SIZE + 1]{ 0 };
		name_ = new char[NAME_MAX_SIZE + 1]{ 0 };
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1]{ 0 };

		// ��������� ��������
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setCountFamily(countFamily);
		setArea(area);
		setCountRoom(countRoom);
		setDate(date);
	}

	// ����������� ����������
	Person(const Person& person) : 
		countFamily_(person.countFamily_), 
		area_(person.area_), 
		countRoom_(person.countRoom_),
		date_(person.date_)
	{
		// ��������� ������ ��� ����� ���� char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};

		// ����������� ��������
		memcpy(surname_, person.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, person.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, person.patronymic_, PATRONYMIC_MAX_SIZE);
	}
	
	// ����������
	~Person()
	{
		delete[]surname_;
		delete[]name_;
		delete[]patronymic_;
	}

	// ���������� �������� ������������
	Person& operator=(const Person& person)
	{
		// ������������ 
		countFamily_ = person.countFamily_;
		area_ = person.area_;
		countRoom_ = person.countRoom_;
		date_ = person.date_;

		// ����������� ��������
		memcpy(surname_, person.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, person.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, person.patronymic_, PATRONYMIC_MAX_SIZE);

		return *this;
	}

#pragma endregion

#pragma region ������� � �������

	// ������ surname_ char*
	void setSurname(char* surname)
	{
		// ����� ������
		int size = strlen(surname);

		// ���� ������ �����������
		if (size < SURNAME_MIN_SIZE && size > SURNAME_MAX_SIZE)
			throw exception("Person: ������ �����������!");

		// ����������� ������
		strcpy(surname_, surname);
	}

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

	// ������ name_ char*
	void setName(char* name)
	{
		// ����� ������
		int size = strlen(name);

		// ���� ������ �����������
		if (size < NAME_MIN_SIZE && size > NAME_MAX_SIZE)
			throw exception("Person: ������ �����������!");

		// ����������� ������
		strcpy(name_, name);
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

	// ������ patronymic_ char* 
	void setPatronymic(char* patronymic)
	{
		// ����� ������
		int size = strlen(patronymic);

		// ���� ������ �����������
		if (size < PATRONYMIC_MIN_SIZE && size > PATRONYMIC_MAX_SIZE)
			throw exception("Person: ������ �����������!");

		// ����������� ������
		strcpy(patronymic_, patronymic);
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

	// ������ countFamily_ int
	void setCountFamily(int countFamily)
	{
		// ���� ������ �����������
		if (countFamily < COUNT_FAMILY_MIN && countFamily > COUNT_FAMILY_MAX)
			throw exception("Person: ������ �����������!");

		// ����������� �������� 
		countFamily_ = countFamily;
	}

	// ������ countFamily_
	int getCountFamily() { return countFamily_; }

	// ������ area_
	void setArea(double area)
	{
		// ���� ������ �����������
		if (area < AREA_MIN && area > AREA_MAX)
			throw exception("Person: ������ �����������!");

		// ����������� �������� 
		area_ = area;
	}

	// ������ area_
	double getArea() { return area_; }

	// ������ countRoom_
	void setCountRoom(int countRoom)
	{
		// ���� ������ �����������
		if (countRoom < COUNT_FAMILY_MIN && countRoom > COUNT_FAMILY_MAX)
			throw exception("Person: ������ �����������!");

		// ����������� �������� 
		countRoom_ = countRoom;
	}

	// ������ countRoom_
	int getCountRoom() { return countRoom_; }

	// ������ date_
	void setDate(Date date)
	{
		date_ = date;
	}

	// ������ date_
	Date getDate() { return date_; }

#pragma endregion

#pragma region ������

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const Person& person);


#pragma endregion
};

