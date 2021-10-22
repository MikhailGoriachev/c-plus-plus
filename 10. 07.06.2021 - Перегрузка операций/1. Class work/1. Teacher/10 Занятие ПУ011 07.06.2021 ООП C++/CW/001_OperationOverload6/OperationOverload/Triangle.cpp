#include "pch.h"
#include "Triangle.h"

// ������������� ����������� ��������� - ����� ������
const double Triangle::EPSILON = 1e-6;

// ������������� ����������� ���������� - ����� ������
int Triangle::counter_ = 0;

// ����������� ������������ ������
// !!! �� ������������ ������ ������ �������� ������ � this !!!
// �������� ������� ������������� ������������
bool Triangle::isTriangle(double a, double b, double c)
{
    return a + b > c && a + c > b && b + c > a;
} // Triangle::isTriangle

// ���������� �������� �������������
Triangle &Triangle::operator=(const Triangle &triangle)
{
    // �� ����� ��������, ����� ������������ ������ ������������, ��� �������
    a_ = triangle.a_;
    b_ = triangle.b_;
    c_ = triangle.c_;

    // ��� ����� ���������� ������ => ����� ������������ ������, �����������
    // ��� ����������� ��������
    setName(triangle.name_);

    return *this;
} // Triangle::operator=

// �������

// ������ ��� ������� ������������
void Triangle::setSide(double a, double b, double c)
{
    // �������� �� ������������ ������������
    if (!isTriangle(a, b, c)) {
        ostringstream oss;
        oss << "������! �������� ���� " << a << ", " << b << " � " << c
            << " �� �������� �����������";
        throw exception(oss.str().c_str());
    } // if

    a_ = a;
    b_ = b;
    c_ = c;
} // Triangle::setSide

// ������ ��� ��������������� ������������
void Triangle::setSide(double a)
{
    // �������� �� ������������ ������������
    if (a <= 0) {
        ostringstream oss;
        oss << "������! �������� " << a_ << " �� �������� �������������� �����������";
        throw exception(oss.str().c_str());
    } // if

    a_ = b_ = c_ = a;
} // Triangle::setSide

// ������ ��� ����� ������������
void Triangle::setName(const char *name)
{
    memset(name_, 0, NAME_LEN);
    strncpy(name_, name, NAME_LEN-1);
} // Triangle::setName

// ���������� ������� � ���������
// �������
double Triangle::area() const
{
    double p = perimeter() / 2;
    return sqrt(p * (p - a_) * (p - b_) * (p - c_));
} // Triangle::area

// ��������
double Triangle::perimeter() const
{
    return a_ + b_ + c_;
} // Triangle::perimeter

// ���������� ��������
ostream &operator<<(ostream &os, const Triangle &triangle)
{
    os << "\"" << triangle.name_ << "\": "
       << fixed << setprecision(3) << triangle.a_ << ", "
       << triangle.b_<< ", " << triangle.c_;
    return os;
} // operator<<

istream &operator>>(istream &is, Triangle &triangle)
{
    double a, b, c;
    is >>a >>b >>c;

    triangle.setSide(a, b, c);
    return is;
} // operator>>

// ���������� �������� ����������� ����������
Triangle &Triangle::operator++()
{
    a_++;
    b_++;
    c_++;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "������ ���������� �������� ����������� ����������";
        throw exception(oss.str().c_str());
    } // if

    return *this;
} // Triangle::operator++

// ���������� �������� ������������ ����������
Triangle Triangle::operator++(int)
{
    Triangle saved(*this);

    a_++;
    b_++;
    c_++;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "������ ���������� �������� ������������ ����������";
        throw exception(oss.str().c_str());
    } // if

    return saved;    
} // Triangle::operator++

// ���������� �������� ����������� ����������
Triangle &Triangle::operator--()
{
    a_--;
    b_--;
    c_--;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "������ ���������� �������� ����������� ����������";
        throw exception(oss.str().c_str());
    } // if

    return *this;
} // Triangle::operator--

// ���������� �������� ������������ ����������
Triangle Triangle::operator--(int)
{
    Triangle saved(*this);

    a_--;
    b_--;
    c_--;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "������ ���������� �������� ������������ ����������";
        throw exception(oss.str().c_str());
    } // if

    return saved;    
} // Triangle::operator--

// ���������� ���� ������ ������������ �� �������� value
Triangle Triangle::operator+(double value)
{
    Triangle result(*this);

    result.a_ += value;
    result.b_ += value;
    result.c_ += value;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "������ ���������� �������� ���������� ������ ������������";
        throw exception(oss.str().c_str());
    } // if

    return result;
} // Triangle::operator+

// ���������� ���� ������ ������������ �� �������� value
Triangle Triangle::operator-(double value)
{
    // �������������� �������� ���������� �������� -
    // �) ��� ������ ������������
    // return Triangle(a_-value, b_-value, c_ - value);
    // �) ��� ������ ��� ������������� �������� ��������
    // return *this + (-value);
     Triangle result(*this);
     
     result.a_ -= value;
     result.b_ -= value;
     result.c_ -= value;
     
     if (!isTriangle(a_, b_, c_)) {
         ostringstream oss;
         oss << "������ ���������� �������� ���������� ������ ������������";
         throw exception(oss.str().c_str());
     } // if
     
     return result;
} // Triangle::operator-

// �������� ��������� � ���������
bool Triangle::operator< (const Triangle &triangle)
{
    return area() < triangle.area();
} // Triangle::operator<

bool Triangle::operator<=(const Triangle &triangle)
{
    // return area() <= triangle.area();
    return !(*this > triangle);
} // Triangle::operator<=

bool Triangle::operator==(const Triangle &triangle)
{
    return area() == triangle.area();
} // Triangle::operator==

bool Triangle::operator!=(const Triangle &triangle)
{
    // return area() != triangle.area();
    return !(*this == triangle);
} // Triangle::operator!=

bool Triangle::operator>=(const Triangle &triangle)
{
    // return area() >= triangle.area();
    return !(*this < triangle);
} // Triangle::operator>=

bool Triangle::operator> (const Triangle &triangle)
{
    return area() > triangle.area();
} // Triangle::operator>
