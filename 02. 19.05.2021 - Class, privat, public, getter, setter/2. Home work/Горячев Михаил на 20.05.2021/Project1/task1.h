#pragma once

#include "head.h"

// генерация данных цилиндра
void generCylinder(Cylinder* Cyl, size_t size);

// максимальное число
inline bool maxNumber(double a, double b);

// нахождение максимального объёма цилиндра
int maximumIndex(Cylinder* Cyl, size_t size);

// суммарный объём цилиндров
double summV(Cylinder* Cyl, size_t size);

// сумма площади цилиндров
double summS(Cylinder* conoid, size_t size);
