#pragma once
#include "TCylinder.h"
#include "TConoid.h"

void task1();
void task2();
void menu();

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTable(const char* title, CYLINDER* cylinders, int n, int maxIndex);

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableConoids(const char* title, CONOID* cylinders, int n, int minIndex);