#pragma once
#include "pch.h"

// ������������ ����� Triangle � ������������� ������ � ��������� ������������ 
// (��� �������, ��� ��������������� ������������ ������ ��� ���������� ��������), 
// ����� � ������ ������������, � ������������ ��� �� ��������� "ABC".
// ������������ ����������� �� ���������, ��������������� ������� ������������ 
// � 1, ������������ � ����������� ��� ������� ���� ���� ������ � ����� ���������� 
// ��� ��������� �������� ��������������� ������������.
// ������������ ������� � ������� ��� ����� ������������. ������ ��� ������ 
// ������� �� ������, ������ ��� �������: � ����� ����������� � ����� � ��� 
// ��������������� ������������.
// ������������ �������� ������ ��� ���������� ������� ������������ �� ������� 
// ������, ��������� ������������.
// ������������ �������� ����� ��� �������� ���������� ������� ������������� 
// ������������.
// ����������� ��������: 
//     � ����� <<
//     � ������ >>
//     � ���������� � ����������� ���������, ��� ��������� ������� ������������� 
//       ������������ ����������� ���������� ���� exception
//     � ���������� � ����������� ���������, ��� ��������� ������� ������������� 
//       ������������ ����������� ���������� ���� exception
//     � �������� ��� ���������� ���� ������ ������������ �� �������� ��������, 
//       ��� ��������� ������� ������������� ������������ ����������� ���������� 
//       ���� exception 
//     � ��������� ��� ���������� ���� ������ ������������ �� �������� ��������, 
//       ��� ��������� ������� ������������� ������������ ����������� ���������� 
//       ���� exception
//     � �������� ��������� (< <= == != >= >) ��� ��������� �������� ���� 
//       �������������

class Triangle
{
public:
    static const int NAME_LEN = 31;

private:
    double a_; // ������� A
    double b_; // ������� B
    double c_; // ������� C

    char *name_; // ��� ������������

    // �������� ������� ������������� ������������
    static bool isTriangle(double a, double b, double c);

public:
    Triangle():a_(1), b_(1), c_(1), name_(new char [NAME_LEN])
    {
        memset(name_, 0, NAME_LEN);
        strcpy(name_, "ABC");
    } // Triangle

    Triangle(double a, double b, double c, const char *name = "ABC")
    {
        setSide(a, b, c);

        name_ = new char [NAME_LEN];
        memset(name_, 0, NAME_LEN);
        strcpy(name_, name);        
    } // Triangle

    Triangle(double a, const char *name = "ABC") {
        setSide(a);
        name_ = new char [NAME_LEN];
        memset(name_, 0, NAME_LEN);
        strcpy(name_, name);        
    } // Triangle

    // ���������� �����������
    Triangle(const Triangle &triangle): 
        a_(triangle.a_), b_(triangle.b_), c_(triangle.c_), name_(new char [NAME_LEN])
    {
        memset(name_, 0, NAME_LEN);
        strcpy(name_, triangle.name_);
    } // Triangle

    // ���������� - ������������ �������� 
    ~Triangle() { delete[] name_; }

    // ������� � �������
    double getA() const { return a_; }
    double getB() const { return b_; }
    double getC() const { return c_; }
    char * getName() const { return name_; }

    void setSide(double a, double b, double c);
    void setSide(double a);
    void setName(const char *name);

    // ���������� ������� � ���������
    double area() const;
    double perimeter() const;

    // ���������� ��������
    friend ostream &operator<<(ostream &os, const Triangle &triangle);
    friend istream &operator>>(istream &is, Triangle &triangle);

    // ���������� ������������ ����������� ��� ������� ���� �� ������ 
    // ������������� ����
    Triangle &operator=(const Triangle &triangle);

    Triangle &operator++();
    Triangle  operator++(int);
    Triangle &operator--();
    Triangle  operator--(int);

    Triangle operator+(double value);
    Triangle operator-(double value);

    bool operator< (const Triangle &triangle);
    bool operator<=(const Triangle &triangle); // !> -- T-SQL
    bool operator==(const Triangle &triangle);
    bool operator!=(const Triangle &triangle);
    bool operator>=(const Triangle &triangle); // !< -- T-SQL
    bool operator> (const Triangle &triangle);

};

