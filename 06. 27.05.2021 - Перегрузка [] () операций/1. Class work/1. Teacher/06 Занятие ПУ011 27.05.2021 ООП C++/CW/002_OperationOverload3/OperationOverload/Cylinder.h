#pragma once
#include "pch.h"

// �����, ����������� �������. ���������� ������������,
// ������� � �������, ������ ��� ���������� ������� � ������
// ��������, ������ ������� � ������ �������� � ������.
class Cylinder
{
    double r_;  // ������
    double h_;  // ������

    // ����� ��� ������ ������� � ������ �������� � ������
    char buf_[81];

public:
    Cylinder():r_(1), h_(1) {  } // Cylinder

    Cylinder(double r, double h) {
        setR(r);
        setH(h);
    } // Cylinder

    // ���������� �� ���������
    Cylinder(const Cylinder &cylinder) = default;
    ~Cylinder() = default;
    Cylinder &operator=(const Cylinder &cylinder) = default;

    // ������� � ������� ��� ������� � ������
    double getR() const { return r_; }
    void setR(double r) {
        if (r <= 0) {
            sprintf(buf_, "������������ ������ ��������: %lf.3", r);
            throw exception(buf_);
        } // if
        r_ = r;
    } // setR

    double getH() const { return h_; }
    void setH(double h) {
        if (h <= 0) {
            sprintf(buf_, "������������ ������ ��������: %lf.3", h);
            throw exception(buf_);
        } // if
        h_ = h;
    } // setH

    // ���������� ������� ����������� ��������
    double area() const { return 2. * M_PI * r_ * (r_ + h_); }

    // ���������� ������ ��������
    double volume() const { return M_PI * r_ * r_ * h_; }

    // ����� � ������ �� �������
    char *toString() {
        sprintf(buf_, " | %8.3lf | %8.3lf", r_, h_);
        return  buf_;
    } // toString
};

