#pragma once

#include "Conoid.h"	// ��������� ������

// ��������� ������ ���������� ������
void generConoid(Conoid* conoid, size_t size);

// ���������� ����������� ������� ������
int maximumIndex(Conoid** conoid, size_t size);

// ����� ������
double summV(Conoid* conoid, size_t size);

// ����� �������
double summS(Conoid* conoid, size_t size);

// ��������� �������
double allSummV(Conoid** conoid, size_t size);

// ����� �������
double allSummS(Conoid** conoid, size_t size);

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableConoids(const char* title, Conoid** conoids, int n, int maxIndex);