#pragma once

#include "Conoid.h"	// структура конуса

// генерация данных усечённого конуса
void generConoid(Conoid* conoid, size_t size);

// минимальное число
inline bool minNumber(double a, double b);

// нахождение минимальной площади конуса
int minimumIndex(Conoid* conoid, size_t size);

// сумма объёма
double summV(Conoid* conoid, size_t size);

// сумма площади
double summS(Conoid* conoid, size_t size);
