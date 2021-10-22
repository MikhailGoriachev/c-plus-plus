#pragma once

#include "Utils.h"
#include "pch.h"
#include "app.h"

#include "Cylinder.h"	// ����� Cylinder
#include "Palette.h"	// ������� ������

#include "task1.h"	// ����� ���������� ������� 1
#include "task2.h"	// ����� ���������� ������� 2

#include <exception>

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableCylinder(const char* title, Cylinder* cylinders, int n, int maxIndex);

// ����
void menu();

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableConoids(const char* title, Conoid* cylinders, int n, int minIndex);