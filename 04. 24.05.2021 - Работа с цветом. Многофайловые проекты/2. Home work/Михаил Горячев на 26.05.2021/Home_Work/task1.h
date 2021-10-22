#pragma once

#include "Conoid.h"	// структура конуса

// генераци€ данных усечЄнного конуса
void generConoid(Conoid* conoid, size_t size);

// нахождение минимальной площади конуса
int maximumIndex(Conoid** conoid, size_t size);

// сумма объЄма
double summV(Conoid* conoid, size_t size);

// сумма площади
double summS(Conoid* conoid, size_t size);

// суммарна€ площадь
double allSummV(Conoid** conoid, size_t size);

// сумма площадь
double allSummS(Conoid** conoid, size_t size);

// вывод массива цилиндров в табличном формате, горизонтальна€ лини€: Ч Alt+0151
void showTableConoids(const char* title, Conoid** conoids, int n, int maxIndex);