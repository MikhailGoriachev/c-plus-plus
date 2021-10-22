#include "head.h"

// генерация данных цилиндра
void generCylinder(Cylinder* Cyl, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// заполнение поля высоты случайным числом
		Cyl[i].setHeight(getRand(1., 50.0));

		// заполнение поля радиуса случайным числом
		Cyl[i].setRadius(getRand(1., 50.0));
	}
}

// максимальное число
inline bool maxNumber(double a, double b)
{
	return a > b;
}

// нахождение максимального объёма цилиндра
int maximumIndex(Cylinder* Cyl, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		maxNumber(Cyl[max].MathV(), Cyl[i + 1].MathV()) ? false : max = i + 1;
	}

	return max;
}

// суммарный объём цилиндров
double summV(Cylinder* Cyl, size_t size)
{
	double summ = 0.0;

	for (Cylinder* Cyl_p = Cyl; Cyl_p < Cyl + size; Cyl_p++)
	{
		summ += Cyl_p->MathV();
	}

	return summ;
}

// сумма площади цилиндров
double summS(Cylinder* сylinder, size_t size)
{
	double summ = 0.0;

	for (Cylinder* сylinder_p = сylinder; сylinder_p < сylinder + size; сylinder_p++)
	{
		summ += сylinder->MathS();
	}

	return summ;
}