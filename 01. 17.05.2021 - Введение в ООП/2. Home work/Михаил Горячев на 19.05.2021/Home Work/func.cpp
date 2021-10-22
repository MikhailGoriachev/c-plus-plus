#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "TCylinder.h"     // ��� ������������� ��������� TCylinder
#include "TConoid.h"

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTable(const char* title, CYLINDER* cylinders, int n, int maxIndex)
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
		setColor(cylinders[i].MathV() == cylinders[maxIndex].MathV() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +�����+�����������������+����������������+���������������������������������+\n";
} // showTable

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void showTableConoids(const char* title, CONOID* cylinders, int n, int minIndex)
{
	cout << title
		<< "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n"
		<< "\t    |  N  |    ������, R    |    ������, r   |    ������, H   |   �������, S   |    �����, V    |\n"
		<< "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n";

	// ������� ������ ������� ���������, � ���������� ������
	// ������ � ����������� �������, ����� � ����� ���� ������
	// ������� �������� "��������"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(cylinders[i].MathS() == cylinders[minIndex].MathS() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n";
} // showTable