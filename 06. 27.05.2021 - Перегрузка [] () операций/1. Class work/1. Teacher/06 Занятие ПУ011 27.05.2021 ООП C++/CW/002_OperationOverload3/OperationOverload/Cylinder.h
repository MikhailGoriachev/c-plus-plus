#pragma once
#include "pch.h"

// Класс, описывающий цилиндр. Реализуйте конструкторы,
// геттеры и сеттеры, методы для вычисления площади и объема
// цилиндра, вывода радиуса и высоты цилиндра в строку.
class Cylinder
{
    double r_;  // радиус
    double h_;  // высота

    // буфер для вывода радиуса и высоты цилиндра в строку
    char buf_[81];

public:
    Cylinder():r_(1), h_(1) {  } // Cylinder

    Cylinder(double r, double h) {
        setR(r);
        setH(h);
    } // Cylinder

    // реализации по умолчанию
    Cylinder(const Cylinder &cylinder) = default;
    ~Cylinder() = default;
    Cylinder &operator=(const Cylinder &cylinder) = default;

    // геттеры и сеттеры для радиуса и высоты
    double getR() const { return r_; }
    void setR(double r) {
        if (r <= 0) {
            sprintf(buf_, "Недопустимый радиус цилиндра: %lf.3", r);
            throw exception(buf_);
        } // if
        r_ = r;
    } // setR

    double getH() const { return h_; }
    void setH(double h) {
        if (h <= 0) {
            sprintf(buf_, "Недопустимая высота цилиндра: %lf.3", h);
            throw exception(buf_);
        } // if
        h_ = h;
    } // setH

    // вычисление площади поверхности цилиндра
    double area() const { return 2. * M_PI * r_ * (r_ + h_); }

    // вычисление объема цилиндра
    double volume() const { return M_PI * r_ * r_ * h_; }

    // вывод в строку по заданию
    char *toString() {
        sprintf(buf_, " | %8.3lf | %8.3lf", r_, h_);
        return  buf_;
    } // toString
};

