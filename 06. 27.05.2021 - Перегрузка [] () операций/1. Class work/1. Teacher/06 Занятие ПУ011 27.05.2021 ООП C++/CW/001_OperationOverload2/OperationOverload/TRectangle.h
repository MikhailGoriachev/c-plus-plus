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

    // перегрузка операций методами класса
    TRectangle operator-(TRectangle rect2);  // *this - rect2
    TRectangle operator-(double value);      // *this - value

    // перегрузка инкремента
    TRectangle &operator++();     // префиксный 
    TRectangle &operator++(int);  // постфиксный

    // friend istream &operator>>(istream &is, TRectangle &rect);
    friend ostream &operator<<(ostream &os,  const TRectangle &rect);
};

istream &operator>>(istream &is, TRectangle &rect);