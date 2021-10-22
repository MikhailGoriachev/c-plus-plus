#include "head.h"

// генерация данных усечённого конуса
void generConoid(Conoid* conoid, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// высота
		conoid[i].setHeight(getRand(1., 50.));

		// радиус 1
		conoid[i].setRadius1(getRand(1., 50.));
		
		// радиус 2
		conoid[i].setRadius2(getRand(1., 50.));

		// если радиус 1 меньше радиуса 2
		if (conoid[i].getRadius1() < conoid[i].getRadius2())
		{
			double tmp = conoid[i].getRadius1();
			conoid[i].setRadius1(conoid[i].getRadius2());
			conoid[i].setRadius2(tmp);
		}
	}

}

// минимальное число
inline bool minNumber(double a, double b)
{
	return a < b;
}

// нахождение минимальной площади конуса
int minimumIndex(Conoid* conoid, size_t size)
{
	int min = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		minNumber(conoid[min].MathS(), conoid[i + 1].MathS()) ? false : min = i + 1;
	}

	return min;
}

// сумма объёма
double summV(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

// сумма площади
double summS(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}