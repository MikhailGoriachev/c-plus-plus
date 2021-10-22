#pragma once

#include "Conoid.h"	// ��������� ������

// ��������� ������ ���������� ������
void generConoid(Conoid* conoid, size_t size);

// ����������� �����
inline bool minNumber(double a, double b);

// ���������� ����������� ������� ������
int minimumIndex(Conoid* conoid, size_t size);

// ����� ������
double summV(Conoid* conoid, size_t size);

// ����� �������
double summS(Conoid* conoid, size_t size);
