#include "pch.h"
#include "TRectangle.h"

// сеттер для сторон прямоугольника
void TRectangle::setSides(double a, double b)
{
    setA(a);
    setB(b);
} // TRectangle::setSides

// сеттеры для задания сторон
void TRectangle::setA(double a)
{
      if (a <= 0)
        throw exception("недопустимое значение стороны A");
     this->a_ = a;
} // TRectangle::setA

void TRectangle::setB(double b)
{
    if (b <= 0)
        throw exception("недопустимое значение стороны B");
    this->b_ = b;
} // TRectangle::setB


// вывод сторон прямоугольника
void TRectangle::show(const char *title) const
{
    cout << title << fixed << setw(6) << setprecision(3) << a_ << " x " << b_;     
} // TRectangle::show

TRectangle TRectangle::operator-(TRectangle rect2)
{
    // добавим проверку - не допускаем отрицательных сторон
    if (a_ < rect2.a_ || b_ < rect2.b_)
        throw exception("Недопустимый результат операции \"-\"");

    TRectangle *res = new TRectangle();
    res->a_ = a_ - rect2.a_;
    res->b_ = b_ - rect2.b_;
    return *res;
} // TRectangle::operator-


TRectangle TRectangle::operator-(double value)
{
    // добавим проверку - не допускаем отрицательных сторон
    if (a_ < value || b_ < value)
        throw exception("Недопустимый результата операции \"-\"");

    TRectangle *res = new TRectangle();
    res->a_ = a_ - value;
    res->b_ = b_ - value;

    return *res;
} // TRectangle::operator-

// префиксный 
TRectangle &TRectangle::operator++() {
    ++a_;
    ++b_;

    return *this;  // вернуть ссылку на текущий объект
}

// постфиксный
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

     // вызов сеттера для контроля правильности значений
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