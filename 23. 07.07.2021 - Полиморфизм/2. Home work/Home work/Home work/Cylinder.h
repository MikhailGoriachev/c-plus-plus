#pragma once
#include "pch.h"
#include "Utils.h"
#include "Body.h"

// Класс цилиндер
class Cylinder : public Body
{
	// высота 
	double height_;

	// радиус основания
	double radius_;

public:


	// конструктор по умолчанию
	Cylinder() = default;

	// конструктор инициализирущий
	Cylinder(double height, double radius) : Body()
	{
		setHeight(height);
		setRadius(radius);
	}

	// конструктор копирующий
	Cylinder(const Cylinder& sphere) = default;

	// деструктор 
	~Cylinder() = default;

	// сеттер height_
	void setHeight(double height)
	{
		if (height <= 0)
			throw exception("App: Некорректные данные!");

		height_ = height;
	}

	// геттер height_
	double getHeight() { return height_; }

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
	virtual double area() override
	{
		return 2 * M_PI * pow(radius_, 2) + 2 * M_PI * radius_ * height_;
	}

	// вычисление объема фигуры
	virtual double valume() override { return M_PI * pow(radius_, 2) * height_; }

	// вывод данных по фигуре
	virtual void show() override
	{
		// текущий цвет 
		short cl = getColor();

		cout << fixed;

		cout.precision(3);

		cout << "\t| " << color(YELLOW_ON_BLACK) << "       Цилиндер       "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << height_
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