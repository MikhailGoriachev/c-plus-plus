#pragma once

#include "pch.h"
#include "Utils.h"

/*
	����������� ����� ��� ������������� �������� ���������� ������� � ������ ���
	�������� :
	�	������� � ���������
	�	����������� ������
	�	������� ����������(� �������) �� ��������� �����.
*/

// ����� ����������� ��������
class Subscriber
{
public:

	// ������������ ����� ���� ������� � ���������
	static const int OWNER_MAX_SIZE = 40;

	// ����������� ����� ���� ������� � ���������
	static const int OWNER_MIN_SIZE = 0;

	// ������������ ����� ����������� ������
	static const int NUMBER_SIZE = 10;

	// ������������ ���������� ����� � ������
	static const int MINUTE_MAX = 43800;

	// ����������� ���������� ����� � ������ 
	static const int MINUTE_MIN = 0;

private:

	// ������� � ��������
	char* owner_;

	// ���������� �����
	char* number_;

	// ����� ����������(� �������) �� ��������� �����
	int minute_;

public:

#pragma region ������������, ����������, ������������

	// ����������� �� ���������
	Subscriber() :
		owner_(new char[OWNER_MAX_SIZE + 1]{ 0 }),
		number_(new char[NUMBER_SIZE + 1]{ 0 }),
		minute_() {}

	// ����������� ���������������
	Subscriber(const char* owner, const char* number, int minute) :
		owner_(new char[OWNER_MAX_SIZE + 1]{ 0 }),
		number_(new char[NUMBER_SIZE + 1]{ 0 }),
		minute_() 
	{
		setOwner(owner);
		setNumber(number);
		setMinute(minute);
	}

	// ����������� ����������
	Subscriber(const Subscriber& subscriber) :
		owner_(new char[OWNER_MAX_SIZE + 1]{ 0 }),
		number_(new char[NUMBER_SIZE + 1]{ 0 }),
		minute_(subscriber.minute_)
	{
		memcpy(owner_, subscriber.owner_, OWNER_MAX_SIZE);
		memcpy(number_, subscriber.number_, NUMBER_SIZE);
	}

	// ���������� �������� ������������
	Subscriber& operator=(const Subscriber& subscriber)
	{
		if (this == &subscriber) return *this;

		memcpy(owner_, subscriber.owner_, OWNER_MAX_SIZE);
		memcpy(number_, subscriber.number_, NUMBER_SIZE);
		minute_ = subscriber.minute_;

		return *this;
	}

	// ���������� 
	~Subscriber()
	{
		delete[]owner_;
		delete[]number_;
	}

#pragma endregion

#pragma region ������� � �������
	
	// ������ owner_
	void setOwner(const char* owner) 
	{
		size_t size = strlen(owner);

		// ���� ������ �����������
		if (size < OWNER_MIN_SIZE and size > OWNER_MAX_SIZE)
			throw exception("Subscriber: ������ �����������!");

		// ����������� �������� 
		strncpy(owner_, owner, OWNER_MAX_SIZE);
	}

	// ������ owner_
	const char* getOwner() { return owner_; }

	// ������ number_
	void setNumber(const char* number)
	{
		size_t size = strlen(number);

		// ���� ������ �����������
		if (size != NUMBER_SIZE)
			throw exception("Subscriber: ������ �����������!");

		// ����������� �������� 
		strncpy(number_, number, NUMBER_SIZE);
	}

	// ������ number_
	const char* getNumber() { return number_; }

	// ������ minute_
	void setMinute(int minute)
	{
		// ���� ������ �����������
		if (minute < MINUTE_MIN and minute > MINUTE_MAX)
			throw exception("Subscriber: ������ �����������!");

		// ����������� �������� 
		minute_ = minute;
	}

	// ������ minute_
	int getMinute() { return minute_; }

#pragma endregion

#pragma region ������

	// ����� ������� 
	static void showHead()
	{
		cout << "\t+����+����������������������+������������+������������������+\n"
				"\t|    |       ��������       |    �����   | ����� ���������� |\n"
				"\t|    |                      |            |     (������)     |\n"
				"\t+����+����������������������+������������+������������������+\n";
	}

	// ����� �������� ��� ������� � ����� + ����� � ������
	void showElem(int i = 1, short cl = WHITE_ON_BLACK)
	{
		cout << right << "\t| " << setw(2) << i
			<< left << " | " << setw(OWNER_MAX_SIZE - 20)
			<< color(YELLOW_ON_BLACK) << owner_
			<< color(cl) << " | "
			<< setw(NUMBER_SIZE)
			<< color(YELLOW_ON_BLACK) << number_
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << right << setw(16) << minute_
			<< color(cl) << " |\n";
	}

	// ����� ����� �������
	static void showLine()
	{
		cout << "\t+����+����������������������+������������+������������������+\n";
	}

	// ����� ���� ��� ������
	static void showEmpty(short cl = WHITE_ON_BLACK)
	{
		cout << color(RED_ON_BLACK) << "\t|                        ��� ������                    |\n" << color(cl);

		showLine();
	}

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const Subscriber& subscriber)
	{
		os << "���: " << subscriber.owner_
			<< "\n�����: " << subscriber.number_
			<< "\n����� ����������: " << subscriber.minute_ << "\n";

		return os;
	}

	// ���������� ����� � ������ 
	float price(float rate) { return minute_ * rate; }

	// ���������� �������� ������ �� ������ ��������
	bool operator>(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) > 0; }

	// ���������� �������� ������ ��� ����� �� ������ ��������
	bool operator>=(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) >= 0; }

	// ���������� �������� ����� �� ������ ��������
	bool operator==(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) == 0; }

	// ���������� �������� ������� �� ������ ��������
	bool operator!=(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) != 0; }

	// ���������� �������� ������ ��� ����� �� ������ ��������
	bool operator<=(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) <= 0; }

	// ���������� �������� ������ �� ������ ��������
	bool operator<(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) < 0; }

#pragma endregion
};

