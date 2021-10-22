#pragma once

// ����� Cylinder
#include "Cylinder.h"

// ��������� ������ ��������
void generCylinder(Cylinder* Cyl, size_t size);

// ������������ �����
inline bool maxNumber(double a, double b);

// ���������� ������������� ������ ��������
int maximumIndex(Cylinder** Cyl, size_t size);

// ��������� ����� ���������
double summV(Cylinder** Cyl, size_t size);

// ����� ������� ���������
double summS(Cylinder** conoid, size_t size);

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableCylinder(const char* title, Cylinder** cylinders, int n, int maxIndex);

// ���������� �������� ����������� ����� � ��������
Cylinder* operator+(Cylinder cyl, double num);

// ���������� �������� ������� �������� �� �����
Cylinder* operator/(Cylinder cyl, double num);