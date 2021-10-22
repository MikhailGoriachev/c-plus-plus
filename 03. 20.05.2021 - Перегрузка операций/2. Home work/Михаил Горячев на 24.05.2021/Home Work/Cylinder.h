#pragma once
#include <exception>
#include "pch.h"

using namespace std;

// класс Cylinder
class Cylinder
{
	// радиус 
	double radius_;

	// высота 
	double height_;

public:

#pragma region Конструкторы и Деструкторы
	// констуктор по умолчанию
	Cylinder() :radius_(0), height_(0) {};

	// коструктор с заданием двух аргументов
	Cylinder(double radius, double height)
	{
		setRadius(radius);
		setHeight(height);
	}

	~Cylinder()
	{
		cout << "Cylinder: Объект уничтожен" << endl;
	}

#pragma endregion

#pragma region Сеттеры и Геттеры

	// сеттер radius_
	void setRadius(double radius)
	{
		// если число <= 0
		if (radius <= 0)
		{
			throw exception("Введенное число должно быть <= 0");
		}

		radius_ = radius;
	}

	// сеттер height_
	void setHeight(double height)
	{
		// если число <= 0
		if (height <= 0)
		{
			throw exception("Введенное число должно быть <= 0");
		}

		height_ = height;
	}

	// геттер radius_
	double getRadius() const { return radius_; };

	// геттер height_
	double getHeight() const { return height_; };

#pragma endregion

#pragma region Методы
	// вычисление площади
	double MathS() { return  M_2_PI * radius_ * (radius_ + height_); }

	// вычисление объёма
	double MathV() { return M_PI * (radius_ * radius_) * height_; }

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

	// Сложение двух цилиндров 
	Cylinder* operator+ (Cylinder cyl2)
	{
		Cylinder* cyl = new Cylinder;

		// сложение длин двух цилиндров
		cyl->setHeight(this->getHeight() + cyl2.getHeight());

		// сложение радиусов двух цилиндров
		cyl->setRadius(this->getRadius() + cyl2.getRadius());

		return cyl;
	}

	// Вычитание числа из цилиндра
	Cylinder* operator - (double n)
	{
		Cylinder* cyl = new Cylinder;

		// вычитание числа из длины цилиндра 
		cyl->setHeight(this->getHeight() - n);

		// вычитание числа из радиуса цилиндра
		cyl->setRadius(this->getRadius() - n);

		return cyl;
	}
#pragma endregion
};