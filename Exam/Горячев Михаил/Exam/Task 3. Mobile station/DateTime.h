#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include <ctime>

// ��� ������������� ���� � ������� ����������� ����� DateTime � ������ � ����, �����, ���,
// ���, ������, �������.���������� ������ ���������� �������� ����� ����� ��������� �������
// � ��������.����������� �������� ��������� ���� �������� �������.

// ����� ���� � �������
class DateTime
{
#pragma region ��������� 

public:

	// ���������� ������ � ���� ���������� 
	static int const N_SECOND_LEAP_YEAR = 31622400;
	
	// ���������� ������ � ���� �� ���������� 
	static int const N_SECOND_YEAR = 31536000;

	// ���������� ������ � ��� 
	static int const N_SECOND_DAY = 86400;

	// ���������� ������ � ���� 
	static int const N_SECOND_HOUR = 3600;

	// ���������� ������ � ������ 
	static int const N_SECOND_MINUTE = 60;

#pragma endregion

private:

	// ���� 
	int day_;

	// �����
	int month_;

	// ���
	int year_;

	// ���
	int hour_;

	// ������
	int minute_;

	// ������� 
	int second_;

public:

#pragma region ������������, ���������� � ���������� �������� ������������

	// ����������� �� ��������� - ������������� ������� ���� � �����
	DateTime();

	// ����������� ���������������� 
	DateTime(int day, int month, int year, int hour, int minute, int second);

	// ����������� ���������� 
	DateTime(const DateTime& dateTime) = default;

	// ���������� 
	~DateTime() = default;

	// ���������� �������� ������������
	DateTime& operator=(const DateTime& dateTime) = default;

#pragma endregion

#pragma region ������� � �������

	// ������ ���� � �������
	void setDateTime(int day, int month, int year, int hour, int minute, int second);

	// ������ ����
	void setDate(int day, int month, int year);

	// ������ �������
	void setTime(int hour, int minute, int second);

	// ������ day_
	int getDay();

	// ������ month_
	int getMonth();

	// ������ year_
	int getYear();

	// ������ hour_
	int getHour();

	// ������ minute_
	int getMinute();

	// ������ second_
	int getSecond();

#pragma endregion

#pragma region ������

	// ��������� ������� ����� ����� ��������� ������� � ��������
	static time_t differenceTime(DateTime dateTime1, DateTime dateTime2);

	// �������� ���� � ������� �� ������������
	static bool checkDateTime(int day, int month, int year, int hour, int minute, int second);

	// �������� ���� �� ������������
	static bool checkDate(int day, int month, int year);

	// �������� ������� �� ������������
	static bool checkTime(int hour, int minute, int second);

	// �������� � ��� ����������
	static bool isLeap(int year);

	// ����� ���� � ������� � �����
	void showDateTime(short colorText);

	// ������ � �������� ����
	void write(fstream& fs);

	// ������ �� ��������� ����� 
	void read(fstream& fs);

	// �������� �� ���� 
	bool equalDate(const DateTime & dateTime) const;

#pragma region ���������� �������� ��������� 

	// ������
	bool operator<(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ < dateTime.year_ :
			month_ != dateTime.month_ ? month_ < dateTime.month_ :
			day_ != dateTime.day_ ? day_ < dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ < dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ < dateTime.minute_ :
			second_ < dateTime.second_;
	}

	// ������ ��� �����
	bool operator<=(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ <= dateTime.year_ :
			month_ != dateTime.month_ ? month_ <= dateTime.month_ :
			day_ != dateTime.day_ ? day_ <= dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ <= dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ <= dateTime.minute_ :
			second_ <= dateTime.second_;
	}

	// �����
	bool operator==(const DateTime& dateTime) const
	{
		return year_ == dateTime.year_ and month_ == dateTime.month_ and
			day_ == dateTime.day_ and hour_ == dateTime.hour_ and
			minute_ == dateTime.minute_ and	second_ == dateTime.second_;
	}

	// �� �����
	bool operator!=(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ and month_ != dateTime.month_ and
			day_ != dateTime.day_ and hour_ != dateTime.hour_ and
			minute_ != dateTime.minute_ and second_ != dateTime.second_;
	}

	// ������ ��� �����
	bool operator>=(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ >= dateTime.year_ :
			month_ != dateTime.month_ ? month_ >= dateTime.month_ :
			day_ != dateTime.day_ ? day_ >= dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ >= dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ >= dateTime.minute_ :
			second_ >= dateTime.second_;
	}

	// ������ 
	bool operator>(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ > dateTime.year_ :
			month_ != dateTime.month_ ? month_ > dateTime.month_ :
			day_ != dateTime.day_ ? day_ > dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ > dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ > dateTime.minute_ :
			second_ > dateTime.second_;
	}

#pragma endregion

#pragma endregion

#pragma region ������������� �������
	
	// ����� � ������ 
	friend ostream& operator<<(ostream& os, const DateTime& dateTime);

#pragma endregion

};