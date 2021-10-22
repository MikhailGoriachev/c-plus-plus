#include "pch.h"
#include "TRectangle.h"

// сеттер дл€ сторон пр€моугольника
void TRectangle::setSides(double a, double b)
{
    setA(a);
    setB(b);
} // TRectangle::setSides

// сеттеры дл€ задани€ сторон
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


// вывод сторон пр€моугольника
void TRectangle::show(const char *title) const
{
    cout << title << fixed << setw(6) << setprecision(3) << a_ << " x " << b_;     
} // TRectangle::show


// перегрузка операции ввода обычной функцией
istream &operator>>(istream &is, TRectangle &rect)
{
	 // пр€мой ввод дружественной функцией - небезопасен 
     // is >> rect.a_ >> rect.b_;
     double a, b;
     is >> a >> b;
      
     // вызов сеттера дл€ контрол€ правильности значений
     rect.setA(a);
     rect.setB(b);
    return is;
}

// перегрузка операции вывода дружественной функцией
// дружественность функции (ключевое слово friend) задаетс€ в объ€влении класса
ostream &operator<<(ostream &os,  const TRectangle &rect)
{
    os << fixed << setw(6) << setprecision(3) 
       << rect.a_ 
       << " x " << rect.b_;

    return os;
} // operator<<