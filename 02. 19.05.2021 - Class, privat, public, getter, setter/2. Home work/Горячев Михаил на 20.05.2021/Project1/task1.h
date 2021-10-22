#pragma once

#include "head.h"

// ��������� ������ ��������
void generCylinder(Cylinder* Cyl, size_t size);

// ������������ �����
inline bool maxNumber(double a, double b);

// ���������� ������������� ������ ��������
int maximumIndex(Cylinder* Cyl, size_t size);

// ��������� ����� ���������
double summV(Cylinder* Cyl, size_t size);

// ����� ������� ���������
double summS(Cylinder* conoid, size_t size);
