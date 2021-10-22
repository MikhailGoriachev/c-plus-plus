#include "pch.h"
#include "Trapezium.h"

// конструктор по умолчанию
Trapezium::Trapezium():a_(1), b_(1.5), c_(1)
{
    cout << "Trapezium: Конструктор по умолчанию\n";
}


// конструктор с параметрами
Trapezium::Trapezium(double a, double b, double c)
{
    cout << "Trapezium:  работает конструктор с парметрами\n";

	// установка полей класса при помощи сеттеров
    setA(a);
    setB(b);
    setC(c);
} // Trapezium::Trapezium


// сеттер для установки стороны А
void Trapezium::setA(double a)
{
    // this указатель на текущий экземпляр класса
    // (на текущий объект)
    // this->a_ = a <= 0?1:a;

    if (a <= 0)
        throw exception("Trapezium: Недопустимое значение стороны A");

    this->a_ = a;
} // Trapezium::setA

// сеттер для установки стороны В
void Trapezium::setB(double b)
{
    if (b <= 0)
       throw exception("Trapezium: Недопустимое значение стороны B");

    this->b_ = b;
} // Trapezium::setB

// сеттер для установки стороны C
void Trapezium::setC(double c)
{
    if (c <= 0)
       throw exception("Trapezium: Недопустимое значение стороны C");

    this->c_ = c;
} // Triangle::SetC

// пример определения геттера в файле исходного текста
double Trapezium::getC() const
{
    return c_;
} // Trapezium::GetC


// Вычисление площади прямоугольной трапеции
double Trapezium::area() const
{
    return b_ * (a_+c_)/2;
} // Trapezium::area


// Вычисление периметра прямоугольной трапеции
// double Trapezium::perimeter() const {  }
double Trapezium::perimeter() const { return a_ + b_ + c_ + sqrt(pow(c_ - a_, 2) + b_ * b_); }
