#include "pch.h"
#include "Triangle.h"

// инициализация статической константы - члена класса
const double Triangle::EPSILON = 1e-6;

// инициализация статической переменной - члена класса
int Triangle::counter_ = 0;

// определение статического метода
// !!! из статического метода нельзя получить доступ к this !!!
// проверка условия существования треугольнкиа
bool Triangle::isTriangle(double a, double b, double c)
{
    return a + b > c && a + c > b && b + c > a;
} // Triangle::isTriangle

// перегрузка операции присвваивания
Triangle &Triangle::operator=(const Triangle &triangle)
{
    // не нужна проверка, проще организовать прямое присваивание, без сеттера
    a_ = triangle.a_;
    b_ = triangle.b_;
    c_ = triangle.c_;

    // для имени выделяется память => проще использовать сеттер, выполняющий
    // все необходимые операции
    setName(triangle.name_);

    return *this;
} // Triangle::operator=

// сеттеры

// сеттер для обычнго треугольника
void Triangle::setSide(double a, double b, double c)
{
    // проверка на существовани треугольника
    if (!isTriangle(a, b, c)) {
        ostringstream oss;
        oss << "Ошибка! Значения длин " << a << ", " << b << " и " << c
            << " не образуют треугольник";
        throw exception(oss.str().c_str());
    } // if

    a_ = a;
    b_ = b;
    c_ = c;
} // Triangle::setSide

// сеттер для равностороннего треугольника
void Triangle::setSide(double a)
{
    // проверка на существовани треугольника
    if (a <= 0) {
        ostringstream oss;
        oss << "Ошибка! Значение " << a_ << " не образует равносторонний треугольник";
        throw exception(oss.str().c_str());
    } // if

    a_ = b_ = c_ = a;
} // Triangle::setSide

// сеттер для имени треугольника
void Triangle::setName(const char *name)
{
    memset(name_, 0, NAME_LEN);
    strncpy(name_, name, NAME_LEN-1);
} // Triangle::setName

// вычисление площади и периметра
// площадь
double Triangle::area() const
{
    double p = perimeter() / 2;
    return sqrt(p * (p - a_) * (p - b_) * (p - c_));
} // Triangle::area

// периметр
double Triangle::perimeter() const
{
    return a_ + b_ + c_;
} // Triangle::perimeter

// перегрузка операций
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

// перегрузка операции префиксного инкремента
Triangle &Triangle::operator++()
{
    a_++;
    b_++;
    c_++;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "Ошибка выполнения операции префиксного инкремента";
        throw exception(oss.str().c_str());
    } // if

    return *this;
} // Triangle::operator++

// перегрузка операции постфиксного инкремента
Triangle Triangle::operator++(int)
{
    Triangle saved(*this);

    a_++;
    b_++;
    c_++;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "Ошибка выполнения операции постфиксного инкремента";
        throw exception(oss.str().c_str());
    } // if

    return saved;    
} // Triangle::operator++

// перегрузка операции префиксного декремента
Triangle &Triangle::operator--()
{
    a_--;
    b_--;
    c_--;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "Ошибка выполнения операции префиксного декремента";
        throw exception(oss.str().c_str());
    } // if

    return *this;
} // Triangle::operator--

// перегрузка операции постфиксного декремента
Triangle Triangle::operator--(int)
{
    Triangle saved(*this);

    a_--;
    b_--;
    c_--;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "Ошибка выполнения операции постфиксного декремента";
        throw exception(oss.str().c_str());
    } // if

    return saved;    
} // Triangle::operator--

// увеличение всех сторон треугольника на величину value
Triangle Triangle::operator+(double value)
{
    Triangle result(*this);

    result.a_ += value;
    result.b_ += value;
    result.c_ += value;

    if (!isTriangle(a_, b_, c_)) {
        ostringstream oss;
        oss << "Ошибка выполнения операции увеличения сторон треугольника";
        throw exception(oss.str().c_str());
    } // if

    return result;
} // Triangle::operator+

// уменьшение всех сторон треугольника на величину value
Triangle Triangle::operator-(double value)
{
    // Альтернативные варианты выполнения операции -
    // а) при помощи конструктора
    // return Triangle(a_-value, b_-value, c_ - value);
    // б) при помощи уже реализованной операции сложения
    // return *this + (-value);
     Triangle result(*this);
     
     result.a_ -= value;
     result.b_ -= value;
     result.c_ -= value;
     
     if (!isTriangle(a_, b_, c_)) {
         ostringstream oss;
         oss << "Ошибка выполнения операции уменьшения сторон треугольника";
         throw exception(oss.str().c_str());
     } // if
     
     return result;
} // Triangle::operator-

// операции сравнения и отношения
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
