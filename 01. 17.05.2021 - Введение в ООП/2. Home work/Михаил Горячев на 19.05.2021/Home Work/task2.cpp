#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "head.h"
#include "TConoid.h"

// ��������� ������ ���������� ������
void generData(CONOID* conoid, size_t size)
{
	srand(time(0));

	// ������������ �������� 
	const int max = 80;

	// ����� ����� ������� 
	double n;

	for (CONOID* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		// ������
		conoid_p->height = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		conoid_p->height += n;

		// ������ 1
		conoid_p->radius1 = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		conoid_p->radius1 += n;

		// ������ 2
		conoid_p->radius2 = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		conoid_p->radius2 += n;

		// ���� ������ 1 ������ ������� 2
		conoid_p->radius1 < conoid_p->radius2 ? swap(conoid_p->radius1, conoid_p->radius2) : (void)false;
	}
}

// ����������� �����
template <typename T>
inline bool minNumber(T a, T b)
{
	return a < b;
}

// ���������� ����������� ������� ������
int minimumIndex(CONOID* conoid, size_t size)
{
	int min = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		minNumber(conoid[min].MathS(), conoid[i + 1].MathS()) ? false : min = i + 1;
	}

	return min;
}

double summV(CONOID* conoid, size_t size)
{
	double summ = 0.0;

	for (CONOID* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

double summS(CONOID* conoid, size_t size)
{
	double summ = 0.0;

	for (CONOID* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}

void task2()
{
	cls();

	gotoXY(50, 2);

	cout << "������� 2" << endl;

	cout << "\t\t�������� ���������, ����������� ��������� ����� TConoid (���� ������\n"
		<< "\t\t������� ���������, ������ �������� ��������� � ������, ��� ����� � double).\n"
		<< "\t\t���������� ������, ����������� � ������������������� � ��������������� ������,\n"
		<< "\t\t����� ������ ������ ���������� ������ (������� � ������, ������� ����������� � \n"
		<< "\t\t�����) � ���� ������ �������.\n\n"
		<< "\t\t�������� ������ �� 5� ��������� �������, ������� � ������ � ��������� �����.\n"
		<< "\t\t�������� ������ � ������� � ��������� ���� : ������� � ������, ������� � �����.���\n"
		<< "\t\t������ ������������� / ������ � �������� �����������, ������ �����������, �������� \n"
		<< "\t\t����� ��������� �������, ����� ��������� �������.\n\n";

	// ���������� �������
	int n;

	// ���� ���������� �������
	cout << "\n\n\t������� ���������� ��������� �������: ";
	cin >> n;

	// ������ �������� �������
	CONOID* cons = new CONOID[n];

	generData(cons, n);

	showTableConoids("\t\t\t\t\t���������\n", cons, n, minimumIndex(cons, n));

	cout << "\t\t\t\t\t\t\t\t��������� �����: " << summV(cons, n) << endl << endl;
	cout << "\t\t\t\t\t\t\t\t��������� �������: " << summS(cons, n) << endl << endl;

	delete[] cons;

	_getch();
}