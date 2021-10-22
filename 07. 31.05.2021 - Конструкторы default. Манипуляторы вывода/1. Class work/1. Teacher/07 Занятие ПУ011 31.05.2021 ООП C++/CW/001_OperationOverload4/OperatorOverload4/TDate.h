#pragma once

// �������� �����, ����������� ����: ����, �����, ���. 
// ���������� ������������ �� ���������, � ����������� (����, �����, ���). 
// ������������ ������� � �������.
// ����������� �������� �������� ������:
//     � �������� � �������� ���� ���, ���������� ���������� ���� ����� ������
//     � �������� + ���������� � ���� ��������� ���������� ����, ���������� ����
//     � �������� <, <=, ==, !=, >=, >
//     � �������� ++, -- ������������ ��������� � ���������� ���� ��������������
// ������������� �������� ����������� �������� ������ <<
// ������� �������� ����������� �������� ����� >> 

class TDate
{
    int day_;      // ����
    int month_;    // �����
    int year_;     // ���

    // ��������������� ������
    int toJulianDays() const;
    void ToGrigorian(int julianDays);
    bool DateValid(int day, int month, int year);

    int DaysInMonth(int month, int year);
    bool IsLeapYear(int year);

public:
    // �������� �������������
    TDate(): day_(1), month_(1), year_(1970) {}
    TDate(int day, int month, int year)    
    {
        SetDate(day, month, year);
    }

	// �������� ������������ �� ���������
	// !!! ���������� ����������� !!! ����� ����������� ��������� !!! ������� ����� !!!
	//                                ����� ����������� ��� ������������� ������ 
    TDate(const TDate& date) = default;

    // �������� ����������� �� ���������
	~TDate() = default;

    // ������� � ������
    int GetDay()   const { return day_;   }
    int GetMonth() const { return month_; }
    int GetYear()  const { return year_;  }

    void SetDate(int day, int month, int year);

    // ������������� ���������
    // a = Date();
    // a = b = c = Date()
    // TDate &operator=(const TDate &date) = default;
    TDate &operator=(const TDate &date);

    TDate operator+(int days) const;
    int operator-(const TDate &date) const;

    TDate &operator++();     // ���������� ��������
    TDate operator++(int);   // ����������� �������� - ���������� �������������� 
    
    TDate &operator--();    // ���������� ��������
    TDate operator--(int);  // ����������� �������� - ���������� ��������������

    // �������� <, <=, ==, !=, >=, >
    bool operator< (const TDate &date) const;
    bool operator<=(const TDate &date) const;
    bool operator==(const TDate &date) const;
    bool operator!=(const TDate &date) const;
    bool operator>=(const TDate &date) const;
    bool operator> (const TDate &date) const;

    friend ostream &operator<<(ostream &os, const TDate &date);
    friend TDate operator+(int days, const TDate &date);
};

istream &operator>>(istream &is, TDate &date);


