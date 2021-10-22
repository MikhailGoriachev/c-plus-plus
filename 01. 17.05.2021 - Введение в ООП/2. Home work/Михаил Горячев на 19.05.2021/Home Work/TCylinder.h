#pragma once

struct CYLINDER
{
	// ������ 
	double height;

	// ������
	double radius;

	/// <������>
	// ���������� �������
	double MathS() { return  M_2_PI * radius * (radius + height); }

	// ���������� ������
	double MathV() { return M_PI * (radius * radius) * height; }

	// ����� ���������
	// ������� ������ �������� � ������ �������
	void tableRow(int i)
	{
		cout << "| " << setw(3) << i << " | " << setw(15) << radius
			<< " | " << setw(14) << height
			<< " | " << setw(14) << MathS()
			<< " | " << setw(14) << MathV()
			<< " |";
	}

	/// </������>
};