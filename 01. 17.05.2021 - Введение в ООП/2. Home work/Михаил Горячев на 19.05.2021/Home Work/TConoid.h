#pragma once
#include "pch.h"

struct CONOID
{
	// высота
	double height;

	// радиус 1
	double radius1;

	// радиус 2
	double radius2;

	/// методы
	// объём
	double MathV() { return M_PI / 3 * height * (radius1 * radius1 + radius1 * radius2 + radius2 * radius2); }

	// образующая l
	double MathL() { return sqrt(height * height + (radius1 - radius2) * (radius1 - radius2)); }

	// площадь 
	double MathS() { return (M_PI * MathL() * (radius1 + radius2)) + M_PI * radius1 * radius1 + M_PI * radius2 * radius2; };

	// выводит данные цилиндра в строку таблицы
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