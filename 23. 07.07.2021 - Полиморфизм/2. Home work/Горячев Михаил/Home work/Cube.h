#pragma once
#include "pch.h"
#include "Body.h"
#include "Utils.h"

// Класс куб
class Cube : public Body
{
	// длина грани куба 
	double lenght_;

public:

	// конструктор по умолчанию
	Cube() = default;

	// конструктор инициализирущий
	Cube(double lenght) : Body()
	{
		setLenght(lenght);
	}

	// конструктор копирующий
	Cube(const Cube& sphere) = default;

	// деструктор 
	~Cube() = default;

	// сеттер lenght_
	void setLenght(double lenght)
	{
		if (lenght <= 0)
			throw exception("App: Некорректные данные!");

		lenght_ = lenght;
	}

	// геттер lenght_
	double getLenght() { return lenght_; }

	// вычисление площади поверхности
	virtual double area() override { return 6 * pow(lenght_, 2); }

	// вычисление объема фигуры
	virtual double valume() override { return pow(lenght_, 3); }

	// вывод данных по фигуре
	virtual void show() override
	{
		// текущий цвет 
		short cl = getColor();

		cout << fixed;

		cout.precision(3);

		cout << "\t| " << color(YELLOW_ON_BLACK) << "         Куб          "
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ——————  "
			<< color(cl) << " | "
			<< color(RED_ON_BLACK) << "  ——————  "
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << lenght_
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << area()
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << valume()
			<< color(cl) << " |\n"
			<< "\t+————————————————————————+————————————+————————————+————————————+————————————+————————————+\n";
	}
};

