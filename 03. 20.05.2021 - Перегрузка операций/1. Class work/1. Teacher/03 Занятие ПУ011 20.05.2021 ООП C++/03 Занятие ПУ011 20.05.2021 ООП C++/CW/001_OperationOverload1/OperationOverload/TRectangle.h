#pragma once
#include "pch.h"

//  ласс представл€ющий пр€моугольник 
class TRectangle
{
    // стороны пр€моугольника
    double a_;
    double b_;

public:
    // конструкторы
    TRectangle():a_(1), b_(1) { }  // использование списка инициализациии конструктора
    TRectangle(double a, double b)
    {
        setSides(a, b);
    } // TRectangle

    // сеттер дл€ задани€ двух сторон одной операцией
    void setSides(double a, double b);

    // сеттеры дл€ задани€ сторон
    void setA(double a);
    void setB(double b);

    // геттеры
    double getA() const { return a_; }
    double getB() const { return b_; }

    // методы вычислени€ площади и периметра
    double area()      const { return a_ * b_;       }
    double perimeter() const { return 2 * (a_ + b_); }

    // вывод сторон пр€моугольника в консоль
    void show(const char *title="") const;

    // реализаци€ операции вычитани€ перегрузкой оператора -
	TRectangle operator-(const TRectangle &r)   // *this - r
	{
        return TRectangle(a_ - r.a_, b_ - r.b_);
	}
	

    // объ€вление дружественной функции дл€ перегрузки операции ввода
    friend TRectangle operator-(double value, const TRectangle& r);

    // объ€вление дружественной функции дл€ перегрузки операции ввода
    // friend istream &operator>>(istream &is, TRectangle &rect);

	// объ€вление дружественной функции дл€ перегрузки операции вывода
    friend ostream &operator<<(ostream &os,  const TRectangle &rect);
};

// объ€вление обычной, не дружественной перегрузки операции ввода
istream &operator>>(istream &is, TRectangle &rect);