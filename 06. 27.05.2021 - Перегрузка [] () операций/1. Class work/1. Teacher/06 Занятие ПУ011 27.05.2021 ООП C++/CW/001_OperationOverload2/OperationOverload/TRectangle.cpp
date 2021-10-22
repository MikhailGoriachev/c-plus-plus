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

TRectangle TRectangle::operator-(TRectangle rect2)
{
    // ������� �������� - �� ��������� ������������� ������
    if (a_ < rect2.a_ || b_ < rect2.b_)
        throw exception("������������ ��������� �������� \"-\"");

    TRectangle *res = new TRectangle();
    res->a_ = a_ - rect2.a_;
    res->b_ = b_ - rect2.b_;
    return *res;
} // TRectangle::operator-


TRectangle TRectangle::operator-(double value)
{
    // ������� �������� - �� ��������� ������������� ������
    if (a_ < value || b_ < value)
        throw exception("������������ ���������� �������� \"-\"");

    TRectangle *res = new TRectangle();
    res->a_ = a_ - value;
    res->b_ = b_ - value;

    return *res;
} // TRectangle::operator-

// ���������� 
TRectangle &TRectangle::operator++() {
    ++a_;
    ++b_;

    return *this;  // ������� ������ �� ������� ������
}

// �����������
TRectangle &TRectangle::operator++(int) {
    TRectangle *rect = new TRectangle(a_, b_);

    ++a_;
    ++b_;

    return *rect;
}

istream &operator>>(istream &is, TRectangle &rect)
{
     // is >> rect.a_ >> rect.b_;
     double a, b;
     is >> a >> b;

     // ����� ������� ��� �������� ������������ ��������
     rect.setA(a);
     rect.setB(b);
    return is;
}

ostream &operator<<(ostream &os,  const TRectangle &rect)
{
    os << fixed << setw(6) << setprecision(3) 
       << rect.a_ 
       << " x " << rect.b_;

    return os;
} // operator<<