#include "pch.h"
#include "TRectangle.h"

// ������ ��� ������ ��������������
void TRectangle::setSides(double a, double b)
{
    setA(a);
    setB(b);
} // TRectangle::setSides

// ������� ��� ������� ������
void TRectangle::setA(double a)
{
      if (a <= 0)
        throw exception("������������ �������� ������� A");
     this->a_ = a;
} // TRectangle::setA

void TRectangle::setB(double b)
{
    if (b <= 0)
        throw exception("������������ �������� ������� B");
    this->b_ = b;
} // TRectangle::setB


// ����� ������ ��������������
void TRectangle::show(const char *title) const
{
    cout << title << fixed << setw(6) << setprecision(3) << a_ << " x " << b_;     
} // TRectangle::show


// ���������� �������� ����� ������� ��������
istream &operator>>(istream &is, TRectangle &rect)
{
	 // ������ ���� ������������� �������� - ����������� 
     // is >> rect.a_ >> rect.b_;
     double a, b;
     is >> a >> b;
      
     // ����� ������� ��� �������� ������������ ��������
     rect.setA(a);
     rect.setB(b);
    return is;
}

// ���������� �������� ������ ������������� ��������
// ��������������� ������� (�������� ����� friend) �������� � ���������� ������
ostream &operator<<(ostream &os,  const TRectangle &rect)
{
    os << fixed << setw(6) << setprecision(3) 
       << rect.a_ 
       << " x " << rect.b_;

    return os;
} // operator<<