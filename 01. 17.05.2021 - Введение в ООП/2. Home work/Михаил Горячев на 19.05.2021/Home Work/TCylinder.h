#pragma once

struct CYLINDER
{
	// высота 
	double height;

	// радиус
	double radius;

	/// <методы>
	// вычисление площади
	double MathS() { return  M_2_PI * radius * (radius + height); }

	// вычисление объёма
	double MathV() { return M_PI * (radius * radius) * height; }

	// вывод структуры
	// выводит данные цилиндра в строку таблицы
	void tableRow(int i)
	{
		cout << "| " << setw(3) << i << " | " << setw(15) << radius
			<< " | " << setw(14) << height
			<< " | " << setw(14) << MathS()
			<< " | " << setw(14) << MathV()
			<< " |";
	}

	/// </методы>
};