#include "pch.h"
#include "Date.h"

bool Date::operator==(const Date& date) const
{
    return day_ == date.day_ and month_ == date.month_ and year_ == date.year_;
}

// �������� ���������� �� ����������� ������������ ���������� ����
bool Date::dateValid(short day, short month, short year)
{
    return (month >= 1 and month <= 12)  and
	       (day >= 1 and day <= daysInMonth(month, year)) and
	       year >= 0;
} // Date::DateValid

// ���������� ���������� ���� � ������
short Date::daysInMonth(short month, short year)
{
    short daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (isLeapYear(year)) daysInMonth[1]++;
    return daysInMonth[month - 1];
} // Date::DaysInMonth

// �������� ���� �� ������������
bool Date::isLeapYear(short year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
} // Date::IsLeapYear


// ������ ��� ����
void Date::setDate(short day, short month, short year)
{
    // ���� ��������� �� �������� ���������� ���� - ����������� ����������
    if (!dateValid(day, month, year)) {
        throw exception("Date: ������������ ����");
    } // if

    // ���������� ������ - ��������� ����� ��������
    day_ = day;
    month_ = month;
    year_ = year;
} // Date::setDate


const char* Date::toString() const
{
    sprintf(buf_, "%02d/%02d/%04d", day_, month_, year_);
    return buf_;
} // Date::toString

Date& Date::operator=(const Date& date)
{
    if (this == &date) return *this;

    day_ = date.day_;
    month_ = date.month_;
    year_ = date.year_;

    memcpy(buf_, date.buf_, Date::N_BUF);
    return *this;
}

