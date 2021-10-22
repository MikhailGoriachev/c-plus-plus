#pragma once
#include "Figures.h"


void showTable(const Figures &figures, const char *title);
void showTable(const Figures &figures, const char *title, int index);

void demoIndexByName(const Figures &figures);
void demoAddItem(Figures &figures);


// компаратор для сортировки по имени треугольника
inline int compareByName(const Triangle& tr1, const Triangle& tr2)
{
	return strcmp(tr1.getName(), tr2.getName());
}

// компаратор для сортировки по имени стороне A
inline int compareBySideA(const Triangle& tr1, const Triangle& tr2)
{
	double sideA1 = tr1.getA();
	double sideA2 = tr2.getA();
	
	return sideA1 < sideA2?-1: sideA1 > sideA2? 1: 0;
}