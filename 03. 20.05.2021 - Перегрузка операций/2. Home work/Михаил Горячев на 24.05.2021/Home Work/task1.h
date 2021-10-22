#pragma once

// класс Cylinder
#include "Cylinder.h"

// генерация данных цилиндра
void generCylinder(Cylinder* Cyl, size_t size);

// максимальное число
inline bool maxNumber(double a, double b);

// нахождение максимального объёма цилиндра
int maximumIndex(Cylinder** Cyl, size_t size);

// суммарный объём цилиндров
double summV(Cylinder** Cyl, size_t size);

// сумма площади цилиндров
double summS(Cylinder** conoid, size_t size);

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void showTableCylinder(const char* title, Cylinder** cylinders, int n, int maxIndex);

// перегрузка операции прибавления числа к цилиндру
Cylinder* operator+(Cylinder cyl, double num);

// перегрузка операции деления цилиндра на число
Cylinder* operator/(Cylinder cyl, double num);