#include "head.h"

// ��������� ������ ��������
void generCylinder(Cylinder* Cyl, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// ���������� ���� ������ ��������� ������
		Cyl[i].setHeight(getRand(1., 50.0));

		// ���������� ���� ������� ��������� ������
		Cyl[i].setRadius(getRand(1., 50.0));
	}
}

// ������������ �����
inline bool maxNumber(double a, double b)
{
	return a > b;
}

// ���������� ������������� ������ ��������
int maximumIndex(Cylinder* Cyl, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		maxNumber(Cyl[max].MathV(), Cyl[i + 1].MathV()) ? false : max = i + 1;
	}

	return max;
}

// ��������� ����� ���������
double summV(Cylinder* Cyl, size_t size)
{
	double summ = 0.0;

	for (Cylinder* Cyl_p = Cyl; Cyl_p < Cyl + size; Cyl_p++)
	{
		summ += Cyl_p->MathV();
	}

	return summ;
}

// ����� ������� ���������
double summS(Cylinder* �ylinder, size_t size)
{
	double summ = 0.0;

	for (Cylinder* �ylinder_p = �ylinder; �ylinder_p < �ylinder + size; �ylinder_p++)
	{
		summ += �ylinder->MathS();
	}

	return summ;
}