#pragma once
#include "pch.h"

// ����������, ����������� ������� TCylinder (���� ������ � ������,
// ��� double). ����� ������ ��� ���������� � �������� ������� �
// ������ ��������, ������ ������� � ������ �������� � �������
struct TCylinder
{
	// ���� ��������
	double radius;   // ������ ��������
	double height;   // ������ ��������

	// ������ �������� �� �������
	// ������� ��������
	double area() { return 2. * M_PI * radius * (radius + height); }

	// ����� ��������
	double volume()
	{
		// double r = M_PI * radius * radius * height;
		return M_PI * radius * radius * height;
	}

	// ����� ����� �������� � �������
	void show() { cout << "������ " << radius << ", ������ " << height; }

	
	// ������� ������ �������� � ������ �������
	void tableRow(int i)
	{
		cout<< "| " << setw(3) << i << " | " << setw(15) << radius
			<< " | " << setw(14) << height
			<< " | " << setw(14) << area()
			<< " | " << setw(14) << volume()
		    << " |";
	} // tableRow
	
};