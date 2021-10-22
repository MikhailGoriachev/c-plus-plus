#pragma once
// ������������� ��������
class Trapezium
{
    double a_;   // ������� ���������
    double b_;   // ������
    double c_;   // ������ ���������

public:
    // �����������
    Trapezium();
    Trapezium(double a, double b, double c);
    ~Trapezium() { cout << "Trapezium: ������ ���������\n"; }

    // ������� � ������� ��� ������ / �������� � ��������
    void setA(double a);
    double getA() const { return a_; } // ����������� ������

    void setB(double b);
    double getB() const { return b_; }

    void setC(double c);
    double getC() const;

    // ����������� ������ ��� ������� ������� � ��������� 
    double area() const;
    double perimeter() const;
};

