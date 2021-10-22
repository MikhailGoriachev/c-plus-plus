#pragma once
#include "head.h"

using namespace std;

// класс цилиндра
class Cylinder
{
	double radius_;	// радиус цилиндра 
	double height_;	// высота цилиндра

// внешне доступная часть
public:

	//  конструктор по умолчанию
	Cylinder():radius_(0), height_(0) {};

	// конструктор с параметрами
	Cylinder(double radius, double height)
	{
		setRadius(radius);
		setHeight(height);
	}

	// деструктор 
	~Cylinder()
	{
		cout << "Cylinder: Объект уничтожен" << endl;
	}

	// геттер радиуса 
	double getRadius() const { return radius_; };

	// сеттер радиуса 
	void setRadius(double radius)
	{
		// если радус меньше или ровняется нулю
		if (radius <= 0.)
		{
			throw exception("Ввёденный радиус меньше или равен нулю!");
		}

		radius_ = radius;
	}

	// геттер высоты
	double getHeight() const { return height_; };

	// сеттер радиуса 
	void setHeight(double height)
	{
		// если радус меньше или ровняется нулю
		if (height <= 0.)
		{
			throw exception("Ввёденная высота меньше или равна нулю!");
		}

		height_ = height;
	}

	// вычисление площади
	double MathS() { return  M_2_PI * getRadius() * (getRadius() + getHeight()); }

	// вычисление объёма
	double MathV() { return M_PI * (getRadius() * getRadius()) * getHeight(); }

	// вывод структуры
	// выводит данные цилиндра в строку таблицы
	void tableRow(int i)
	{
		cout << "| " << setw(3) << i << " | " << setw(15) << getRadius()
			<< " | " << setw(14) << getHeight()
			<< " | " << setw(14) << MathS()
			<< " | " << setw(14) << MathV()
			<< " |";
	}

};