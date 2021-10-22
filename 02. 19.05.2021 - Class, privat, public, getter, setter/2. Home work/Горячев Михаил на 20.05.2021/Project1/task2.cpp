#include "head.h"

// ��������� ������ ���������� ������
void generConoid(Conoid* conoid, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// ������
		conoid[i].setHeight(getRand(1., 50.));

		// ������ 1
		conoid[i].setRadius1(getRand(1., 50.));
		
		// ������ 2
		conoid[i].setRadius2(getRand(1., 50.));

		// ���� ������ 1 ������ ������� 2
		if (conoid[i].getRadius1() < conoid[i].getRadius2())
		{
			double tmp = conoid[i].getRadius1();
			conoid[i].setRadius1(conoid[i].getRadius2());
			conoid[i].setRadius2(tmp);
		}
	}

}

// ����������� �����
inline bool minNumber(double a, double b)
{
	return a < b;
}

// ���������� ����������� ������� ������
int minimumIndex(Conoid* conoid, size_t size)
{
	int min = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		minNumber(conoid[min].MathS(), conoid[i + 1].MathS()) ? false : min = i + 1;
	}

	return min;
}

// ����� ������
double summV(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

// ����� �������
double summS(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}