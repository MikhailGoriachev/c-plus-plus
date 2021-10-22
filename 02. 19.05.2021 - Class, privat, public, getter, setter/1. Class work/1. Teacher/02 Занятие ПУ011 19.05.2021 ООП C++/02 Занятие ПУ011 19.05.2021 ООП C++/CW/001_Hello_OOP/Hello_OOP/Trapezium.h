#pragma once
// прямоугольная трапеция
class Trapezium
{
    double a_;   // верхнее основание
    double b_;   // высота
    double c_;   // нижнее основание

public:
    // Конструктор
    Trapezium();
    Trapezium(double a, double b, double c);
    ~Trapezium() { cout << "Trapezium: Объект уничтожен\n"; }

    // геттеры и сеттеры для сторон / аксессор и мутаторы
    void setA(double a);
    double getA() const { return a_; } // константный геттер

    void setB(double b);
    double getB() const { return b_; }

    void setC(double c);
    double getC() const;

    // константные методы для расчета площади и периметра 
    double area() const;
    double perimeter() const;
};

