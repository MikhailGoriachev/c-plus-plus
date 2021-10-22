// ����� Cylinder
#include "Cylinder.h"

// ��������� ������ ��������
void generCylinder(Cylinder* Cyl, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// ���������� ���� ������ ��������� ������
		Cyl[i].setHeight(getRand(1., 10.0));

		// ���������� ���� ������� ��������� ������
		Cyl[i].setRadius(getRand(1., 10.0));
	}
}

// ������������ �����
inline bool maxNumber(double a, double b)
{
	return a > b;
}

// ���������� ������������� ������ ��������
int maximumIndex(Cylinder** Cyl, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		maxNumber(Cyl[max][0].MathV(), Cyl[i + 1][0].MathV()) ? false : max = i + 1;
	}

	return max;
}

// ��������� ����� ���������
double summV(Cylinder** Cyl, size_t size)
{
	double summ = 0.0;

	for (Cylinder** Cyl_p = Cyl; Cyl_p < Cyl + size; Cyl_p++)
	{
		summ += (**Cyl_p).MathV();
	}

	return summ;
}

// ����� ������� ���������
double summS(Cylinder** �ylinder, size_t size)
{
	double summ = 0.0;

	for (Cylinder** �ylinder_p = �ylinder; �ylinder_p < �ylinder + size; �ylinder_p++)
	{
		summ += (**�ylinder).MathS();
	}

	return summ;
}

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableCylinder(const char* title, Cylinder** cylinders, int n, int maxIndex)
{
	cout << title
		<< "\t    +�����+�����������������+����������������+���������������������������������+\n"
		<< "\t    |  N  |    ������, R    |    ������, H   |   �������, S   |    �����, V    |\n"
		<< "\t    +�����+�����������������+����������������+���������������������������������+\n";

	// ������� ������ ������� ���������, � ���������� ������
	// ������ � ����������� �������, ����� � ����� ���� ������
	// ������� �������� "��������"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(cylinders[i][0].MathV() == cylinders[maxIndex][0].MathV() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i][0].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +�����+�����������������+����������������+���������������������������������+\n";
} // showTable

// ���������� �������� ����������� ����� � ��������
Cylinder* operator+(Cylinder cyl, double num)
{
	// �������� �������� �� ����
	Cylinder* cylinder = new Cylinder();

	// ����������� � ������� �����
	cylinder->setRadius(cyl.getRadius() + num);

	// ����������� � ������ �����
	cylinder->setHeight(cyl.getHeight() + num);

	return cylinder;
}

// ���������� �������� ������� �������� �� �����
Cylinder* operator/(Cylinder cyl, double num)
{
	// �������� �������� �� ����
	Cylinder* cylinder = new Cylinder;

	// ������� ������� �� �����
	cylinder->setRadius(cyl.getRadius() / num);

	// ������� ������ �� �����
	cylinder->setHeight(cyl.getHeight() / num);

	return cylinder;
}