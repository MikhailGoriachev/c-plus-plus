#pragma once
#include "pch.h"

// Структуруа, описывающая цилиндр TCylinder (поля радиус и высота,
// тип double). Имеет методы для вычисления и возврата площади и
// объема цилиндра, вывода радиуса и высоты цилиндра в консоль
struct TCylinder
{
	// поля цилиндра
	double radius;   // радиус цилиндра
	double height;   // высота цилиндра

	// методы цилиндра по заданию
	// площадь цилиндра
	double area() { return 2. * M_PI * radius * (radius + height); }

	// объем цилиндра
	double volume()
	{
		// double r = M_PI * radius * radius * height;
		return M_PI * radius * radius * height;
	}

	// вывод полей цилиндра в консоль
	void show() { cout << "радиус " << radius << ", высота " << height; }

	
	// выводит данные цилиндра в строку таблицы
	void tableRow(int i)
	{
		cout<< "| " << setw(3) << i << " | " << setw(15) << radius
			<< " | " << setw(14) << height
			<< " | " << setw(14) << area()
			<< " | " << setw(14) << volume()
		    << " |";
	} // tableRow
	
};