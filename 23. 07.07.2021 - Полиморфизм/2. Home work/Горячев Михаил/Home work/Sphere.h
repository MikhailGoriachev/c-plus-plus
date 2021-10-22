#pragma once
#include "Body.h"
#include "pch.h"
#include "Utils.h"

// Класс сферы 
class Sphere : public Body
{
	// Радиус сферы(шара) (R) - это расстояние от центра сферы
	double radius_;

public:

	// конструктор по умолчанию
	Sphere() = default;

	// конструктор инициализирущий
	Sphere(double radius) : Body()
	{
		setRadius(radius);
	}

	// конструктор копирующий
	Sphere(const Sphere& sphere) = default;

	// деструктор 
	~Sphere() = default;

	// сеттер radius_
	void setRadius(double radius)
	{
		if (radius <= 0)
			throw exception("App: Некорректные данные!");

		radius_ = radius;
	}

	// геттер radius_
	double getRadius() { return radius_; }

	// вычисление площади поверхности
	virtual double area() override { return 4 * M_PI * pow(radius_, 2); }

	// вычисление объема фигуры
	virtual double valume() override { return M_PI / 3 * 4 * pow(radius_, 3); }

	// вывод данных по фигуре
	virtual void show() override
	{
		// текущий цвет 
		short cl = getColor();

		cout << fixed;

		cout.precision(3);

		cout << "\t| " << color(YELLOW_ON_BLACK) << "      Сфера(шар)      "
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ——————  "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << radius_
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ——————  "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << area()
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << valume()
			<< color(cl) << " |\n"
			<< "\t+————————————————————————+————————————+————————————+————————————+————————————+————————————+\n";

	}
};

