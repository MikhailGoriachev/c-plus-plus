#pragma once
#include "pch.h"
#include "Utils.h"

class Date
{
    short day_;      // ����
    short month_;    // �����
    short year_;     // ���

    static const short N_BUF = 21;
    char* buf_;   // ��� ������ toString()

public:
    // �������� �������������
    Date():buf_(new char[N_BUF] {0}) {
        // ��������� ������� ����
        SYSTEMTIME st;
    	GetLocalTime(&st);

    	year_  = st.wYear;
        month_ = st.wMonth;
        day_   = st.wDay;
    } // Date 

    Date(short day, short month, short year) : buf_(new char[N_BUF] {0}){
            setDate(day, month, year);
    } // Date

    Date(const Date& date) :
        day_(date.day_), month_(date.month_), year_(date.year_),
        buf_(new char[N_BUF] {0}) {} // Date

    ~Date() { delete[] buf_; }
    bool operator==(const Date& date) const;

    // ��������������� ������
    static bool  dateValid(short day, short month, short year);
    static short daysInMonth(short month, short year);
    static bool  isLeapYear(short year);
    static Date getRandDate() {

        Date newDate(getRand(1, 29), getRand(1, 12), getRand(2010, 2021));
        return newDate;

    }

    // ������� 
    short getDay()   const { return day_; }
    short getMonth() const { return month_; }
    short getYear()  const { return year_;  }

    // ������
    void setDate(short day, short month, short year);

    const char* toString() const;

    Date& operator=(const Date& date);

    // ���������� �������� ������ ��� Date
   // friend ostream &operator<<(ostream &os, const Date &date);
    friend ostream& operator<<(ostream& os, const Date& date)
    {
        os << date.toString();
        return os;
    } // operator<<
};



