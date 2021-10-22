#include "pch.h"
#include "TDate.h"

// ������ ��� ����
void TDate::SetDate(int day, int month, int year)
{
    // ���� ��������� �� �������� ���������� ���� - ����������� ����������
    char buf[1024];
    if (!DateValid(day, month, year)) {
        sprintf(buf, "%02d/%02d%04d - ������������ ����", day, month, year);
        throw exception(buf);
    } // if

    // ���������� ������ - ��������� ����� ��������
    day_   = day;
    month_ = month;
    year_  = year;
} // TDate::SetDate

// �������� ���������� �� ����������� ������������ ���������� ����
bool TDate::DateValid(int day, int month, int year)
{
    if (month <= 0) return false;
    if (year <= 0) return false;

    bool result = true;

    // TODO: �������� ������
    // TODO: �������� ���
 
    return result;
} // TDate::DateValid

// ���������� ���������� ���� � ������
int TDate::DaysInMonth(int month, int year)
{
    int daysInMonth[12] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (IsLeapYear(year)) daysInMonth[1]++;
    return daysInMonth[month - 1];
} // TDate::DaysInMonth

// �������� ���� �� ������������
bool TDate::IsLeapYear(int year)
{
    // TODO: �����������
    return false;
} // TDate::IsLeapYear

// �������� ������� ��������� �������� ��������� ��������
TDate &TDate::operator=(const TDate &date)
{	
    day_ = date.day_;
    month_ = date.month_;
    year_ = date.year_;

    // strcpy(holidays_, date.holidays_);

	// ��� ���������� ������� ��������
    return *this;
}

// �������� ���� � ���������� ����
TDate TDate::operator+(int days) const
{
    TDate result(*this);  // ����� ����, ��� ����������

    result.ToGrigorian(result.toJulianDays() + days);
    return result;
} // TDate::operator+

// �������� days + date
TDate operator+(int days, const TDate &date)
{
    // TDate result(date);  // ����� ������� ���������
    // result.ToGrigorian(result.toJulianDays() + days);

    // return result;
    return date + days;
} // operator+

// ��������� - �������� ���� ���
// this - date, this - ������ ���������� ������ ���������
int TDate::operator-(const TDate &date) const
{
    return toJulianDays() - date.toJulianDays();
} // TDate::operator-

// -------------------------------------------------------------------

// ���������� ���������
TDate& TDate::operator++()
{
    int jdn = toJulianDays();
    ToGrigorian(++jdn);
    return *this;   // ��� ���������� ������ �� ������� ������
} // TDate::operator++

// ����������� ���������
TDate TDate::operator++(int)
{
    TDate date(*this);
    // TDate *date = new TDate(*this);
    int jdn = toJulianDays();
    ToGrigorian(++jdn);
    
    // return *date;
    return date;
} // TDate::operator++

// ���������� ���������
TDate& TDate::operator--()
{
    ToGrigorian(toJulianDays() - 1);
    return *this;
} // TDate::operator--

// ����������� ���������
TDate TDate::operator--(int)
{
    TDate date(*this);
    ToGrigorian(toJulianDays() - 1);
    
    return date;
} // TDate::operator--

// -------------------------------------------------------------------

bool TDate::operator<(const TDate &date) const
{
    return toJulianDays() < date.toJulianDays();
} // TDate::operator<


bool TDate::operator<=(const TDate &date) const
{
    return toJulianDays() <= date.toJulianDays();
} // TDate::operator<=


bool TDate::operator==(const TDate &date) const
{
    return toJulianDays() == date.toJulianDays();
} // TDate::operator==


bool TDate::operator!=(const TDate &date) const
{
    // return toJulianDays() != date.toJulianDays();
    return !(*this == date);
} // TDate::operator!=


bool TDate::operator>=(const TDate &date) const
{
    return toJulianDays() >= date.toJulianDays();
} // TDate::operator>=


bool TDate::operator>(const TDate &date) const
{
    return toJulianDays() > date.toJulianDays();
} // TDate::operator>

// -------------------------------------------------------------------

// ���������� ���������� ��������� ���� � �������������
// (�.�. �������) ����
// https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0#%D0%92%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D0%BD%D0%BE%D0%BC%D0%B5%D1%80%D0%B0_%D1%8E%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%BE%D0%B3%D0%BE_%D0%B4%D0%BD%D1%8F_(JDN)_%D0%BF%D0%BE_%D0%B4%D0%B0%D1%82%D0%B5_%D0%B3%D1%80%D0%B8%D0%B3%D0%BE%D1%80%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%BE%D0%B3%D0%BE_%D0%BA%D0%B0%D0%BB%D0%B5%D0%BD%D0%B4%D0%B0%D1%80%D1%8F
int TDate::toJulianDays() const
{
    int a = (14 - month_) / 12;
    int y = year_ + 4800 - a;
    int m = month_ + 12 * a - 3;

    return day_ + (153 * m + 2)/5 + 365 * y + y/4 - y/100 + y/400 - 32045;
} // TDate::toJulianDays

// ��������� ����� ���� �� ���������� ���������� ����
void TDate::ToGrigorian(int julianDays)
{
    int a = julianDays + 32044;
    int b = (4*a + 3) / 146097;
    int c = a - 146097*b / 4;
    int d = (4*c + 3) / 1461;
    int e = c - 1461 * d / 4;
    int m = (5 * e + 2) / 153;

    day_   = e - (153 * m + 2) / 5 + 1;
    month_ = m + 3 - 12 * (m / 10);
    year_  = 100 * b + d - 4800 + m/10; 
} // TDate::ToGrigorian


ostream &operator<<(ostream &os, const TDate &date)
{
    os << setfill('0') << setw(2) << date.day_ << "/" << setw(2) << date.month_
       << "/" << date.year_ << setfill(' ');
    return os;
} // operator<<

istream &operator>>(istream &is, TDate &date)
{
    int day, month, year;
    is >> day >> month >> year;

    date.SetDate(day, month, year);
    return is;
} // operator>>