#pragma once
#include "pch.h"

// Разработайте класс Triangle с вещественными полями – сторонами треугольника 
// (три стороны, для равностороннего треугольника храним три одинаковых значения), 
// полем – именем треугольника, в конструкторе имя по умолчанию "ABC".
// Разработайте конструктор по умолчанию, устанавливающий стороны треугольника 
// в 1, конструкторы с параметрами для задания всех трех сторон и одним параметром 
// для упрощения создания равностороннего треугольника.
// Разработайте геттеры и сеттеры для полей треугольника. Сеттер для каждой 
// стороны не делаем, делаем два сеттера: с тремя параметрами и одним – для 
// равностороннего треугольника.
// Разработайте открытые методы для вычисления площади треугольника по формуле 
// Герона, периметра треугольника.
// Разработайте закрытый метод для проверки выполнения условия существования 
// треугольника.
// Перегрузите операции: 
//     • ввода <<
//     • вывода >>
//     • префиксный и постфиксный инкремент, при нарушении условия существования 
//       треугольника выбрасывать исключение типа exception
//     • префиксный и постфиксный декремент, при нарушении условия существования 
//       треугольника выбрасывать исключение типа exception
//     • сложение для увеличение всех сторон треугольника на заданное значение, 
//       при нарушении условия существования треугольника выбрасывать исключение 
//       типа exception 
//     • вычитание для уменьшения всех сторон треугольника на заданное значение, 
//       при нарушении условия существования треугольника выбрасывать исключение 
//       типа exception
//     • операции сравнения (< <= == != >= >) для сравнения площадей двух 
//       треугольников

class Triangle
{
public:
    static const int NAME_LEN = 31;

private:
    double a_; // сторона A
    double b_; // сторона B
    double c_; // сторона C

    char *name_; // имя треугольника

    // проверка условия существования треугольнкиа
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

    // копирующий конструктор
    Triangle(const Triangle &triangle): 
        a_(triangle.a_), b_(triangle.b_), c_(triangle.c_), name_(new char [NAME_LEN])
    {
        memset(name_, 0, NAME_LEN);
        strcpy(name_, triangle.name_);
    } // Triangle

    // деструктор - освобождение ресурсов 
    ~Triangle() { delete[] name_; }

    // геттеры и сеттеры
    double getA() const { return a_; }
    double getB() const { return b_; }
    double getC() const { return c_; }
    char * getName() const { return name_; }

    void setSide(double a, double b, double c);
    void setSide(double a);
    void setName(const char *name);

    // вычисление площади и периметра
    double area() const;
    double perimeter() const;

    // перегрузка операций
    friend ostream &operator<<(ostream &os, const Triangle &triangle);
    friend istream &operator>>(istream &is, Triangle &triangle);

    // перегрузка присваивания обязательна при наличии хотя бы одного 
    // динамического поля
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

