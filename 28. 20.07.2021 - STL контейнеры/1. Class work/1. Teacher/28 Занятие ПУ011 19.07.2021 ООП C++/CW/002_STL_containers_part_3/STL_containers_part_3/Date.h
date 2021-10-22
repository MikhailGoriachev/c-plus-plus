#pragma once
#include "pch.h"
#include "Object.h"

// �����, ����������� ����: ����, �����, ���. 
class Date: public Object
{
    short day_;   // ����
    short month_; // �����
    short year_;  // ���

    static bool  dateValid(short day, short month, short year);
    static short daysInMonth(short month, short year);
    static bool  isLeapYear(short year);

	int  toJulianDays() const;
	void toGrigorian(int julianDays);

public:
    // �������� �������������
    Date(): day_(1), month_(1), year_(1970) {}
    Date(short day, short month, short year)    
    {
        setDate(day, month, year);
    } // Date

    Date(const Date &date) = default; 
    virtual ~Date() = default;

    // ������� � ������
    short getDay()   const { return day_;   }
    short getMonth() const { return month_; }
    short getYear()  const { return year_;  }

    void setDate(short day, short month, short year);

	// ���������� ������������ ������
	virtual string toString();

    // ������������� ���������

    // �������� <, <=, ==, !=, >=, >
    bool operator<(const Date &date) const;
    bool operator<=(const Date &date) const;
    bool operator==(const Date &date) const;
    bool operator!=(const Date &date) const;
    bool operator>=(const Date &date) const;
    bool operator>(const Date &date) const;

    friend ostream &operator<<(ostream &os, Date &date);
	friend istream &operator>>(istream &is, Date &date);
};