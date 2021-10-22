#pragma once
#include "pch.h"

struct CONOID
{
	// ������
	double height;

	// ������ 1
	double radius1;

	// ������ 2
	double radius2;

	/// ������
	// �����
	double MathV() { return M_PI / 3 * height * (radius1 * radius1 + radius1 * radius2 + radius2 * radius2); }

	// ���������� l
	double MathL() { return sqrt(height * height + (radius1 - radius2) * (radius1 - radius2)); }

	// ������� 
	double MathS() { return (M_PI * MathL() * (radius1 + radius2)) + M_PI * radius1 * radius1 + M_PI * radius2 * radius2; };

	// ������� ������ �������� � ������ �������
	void tableRow(int i)
	{
		cout << "| " << setw(3) << i << " | " << setw(15) << radius1
			<< " | " << setw(14) << radius2
			<< " | " << setw(14) << height
			<< " | " << setw(14) << MathS()
			<< " | " << setw(14) << MathV()
			<< " |";
	}

};