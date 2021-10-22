#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "TCylinder.h"     // ��� ������������� ��������� TCylinder
#include "head.h"

// ��������� ������ ��������
void generData(CYLINDER* clndr, size_t size)
{
	srand(time(0));

	// ������������ �������� 
	const int max = 80;

	// ����� ����� ������� 
	double n;

	for (CYLINDER* clndr_p = clndr; clndr_p < clndr + size; clndr_p++)
	{
		// ������
		clndr_p->height = rand() % max;
		
		n = rand() % 1000;

		n /= 1000;

		clndr_p->height += n;

		// ������
		clndr_p->radius = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		clndr_p->radius += n;
	}
}

// ������������ �����
template <typename T>
inline bool maxNumber(T a, T b)
{
	return a > b;
}

// ���������� ������������� ������ ��������
int maximumIndex(CYLINDER* clndr, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		maxNumber(clndr[max].MathV(), clndr[i + 1].MathV()) ? false : max = i + 1;
	}

	return max;
}

// ���������� ��������
template <typename T>
T compSumm(T a, T b)
{
	return a + b;
}

// ��������� ����� ���������
double summV(CYLINDER* clndr, size_t size)
{
	double summ = 0.0;

	for (CYLINDER* clndr_p = clndr; clndr_p < clndr + size; clndr_p++)
	{
		summ += clndr_p->MathV();
	}

	return summ;
}

void task1()
{
	cls();

	gotoXY(50, 2);

	cout << "������� 1" << endl << endl;

	cout << "\t\t�������� ���������, ����������� ������� TCylinder (���� ������ � ������,\n"
		<< "\t\t��� ����� �double). ���������� ������, ����������� � ������������ �������\n"
		<< "\t\t� ����� ��������, ����� ������ ������� � ������ �������� � �������, �����\n"
		<< "\t\t������ ������ �������� (������, ������, ������� ����������� � �����) � \n"
		<< "\t\t���� ������ �������.\n\n"
		<< "\t\t�������� ������ �� 8� ���������, ������ � ������ � ��������� �����. \n"
		<< "\t\t�������� ������ � ������� � ��������� ���� : ������ � ������ ��������, \n"
		<< "\t\t������� � �����. ��� ������ �������� ������� / �������� � �������, ������\n"
		<< "\t\t�������������, �������� ����� ��������� ����� ���������.\n";

	// ���������� ���������
	size_t n;

	// ���� ���������� ���������
	cout << "\n\n\t������� ���������� ���������: ";
	cin >> n;

	// �������� ���������
	CYLINDER* clndr = new CYLINDER[n];

	// ������������� ��������� ������
	generData(clndr, n);

	// ��������� ������� �������� � ������������ �������
	int indexMax = maximumIndex(clndr, n);

	showTable("\t\t\t\t\t���������\n", clndr, n, indexMax);

	cout << "\t\t\t\t\t\t\t\t��������� �����: " << summV(clndr, n);

	delete[] clndr;

	_getch();
}