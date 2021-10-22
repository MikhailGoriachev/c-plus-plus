#pragma once

#include "pch.h"

// ����� ���� ����������� ��� 1600
class Date
{
public:

	// ����������� �������� ���� 
	static const int MINIMAL_YEAR = 1600;

private:

	// �����
	int number_;

	// �����
	int month_;

	// ���
	int year_;

public:

#pragma region ������� ���

	// ����������� �� ���������
	Date() = default;

	// ����������� ���������������
	explicit Date(int number, int month, int year)
	{
		// ���������� ��������� ��������
		setDate(number, month, year);
	}

	// ���������� �����������
	Date(const Date& date) = default;

	// ����������
	~Date() = default;

	// ���������� �������� ������������
	Date& operator=(const Date& date) = default;

#pragma endregion

#pragma region ������� � �������

	// ������ ����
	void setDate(int number, int month, int year)
	{
		// ���� ������ �����������
		if (year < MINIMAL_YEAR || number < 1 || month < 1 || month > 12)
			throw exception("Date: ������������ ����!");

		// ��������� ����
		year_ = year;

		// ������ � �������� � ����������� ����
		int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		// ������ �� �������
		int& february = months[1];

		// ��������� ���������� ���� � �������, ���� ��� ����������
		if (chekYear())
			february++;

		// �������� ������������ ����
		if (number > months[month - 1])
			throw exception("Date: ������������ ����!");

		// ��������� ��������
		number_ = number;
		month_ = month-1;
	}

	// ������ ����� 
	int getNumber() { return number_; }

	// ������ ������
	int getMonth() { return month_ + 1; }

	// ������ ����
	int getYear() { return year_; }

#pragma endregion

	// �������� ���� �� �������������� � ���������� �����
	bool chekYear()
	{
		// ���� ��� ������ 400 - ����������
		if (year_ % 400 == 0)
			return true;

		// ���� ��� ������ 100 - ������������
		if (year_ % 100 == 0)
			return false;

		// ���� ��� ������� 4 ��� ������� - ����������
		if (year_ % 4 == 0)
			return true;

		return false;
	}

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const Date& date)
	{
		os << setfill('0') << setw(2) << date.number_ << "." << setw(2) << date.month_ + 1 << "." << date.year_ << setfill(' ');

		return os;
	}

};

