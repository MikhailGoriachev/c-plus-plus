#pragma once

#include "head.h"

class Conoid
{
	// высота
	double height_;

	// радиус 1
	double radius1_;

	// радиус 2
	double radius2_;

public:

	// конструктор по умолчанию
	Conoid() :height_(0), radius1_(0), radius2_(0) {};

	// конструктор с аргументами
	Conoid(double height, double radius1, double radius2)
	{
		setHeight(height);
		setRadius1(radius1);
		setRadius2(radius2);
	}
	// деструктор
	~Conoid()
	{
		cout << "Conoid: Объект уничтожен" << endl;
	}

	// сеттер высоты
	inline void setHeight(double height)
	{
		// если значение меньше или ровняется нулю
		if (height <= 0.)
		{
			throw exception("Ввёденная высота меньше или равна нулю!");
		}

		height_ = height;
	}

	// геттер высоты
	inline double getHeight() const { return height_; };

	// сеттер радиус 1
	inline void setRadius1(double radius1)
	{
		// если значение меньше или ровняется нулю
		if (radius1 <= 0.)
		{
			throw exception("Ввёденный радиус меньше или равна нулю!");
		}

		radius1_ = radius1;
	}

	// геттер радиус 1
	inline double getRadius1() const { return radius1_; };
	
	// сеттер радиус 2
	inline void setRadius2(double radius2)
	{
		// если значение меньше или ровняется нулю
		if (radius2 <= 0.)
		{
			throw exception("Ввёденный радиус меньше или равна нулю!");
		}

		radius2_ = radius2;
	}

	// геттер радиус 2
	inline double getRadius2() const { return radius2_; };

	/// методы
	// объём
	inline double MathV() { return M_PI / 3 * getHeight() * (getRadius1() * getRadius1() + getRadius1() * getRadius2() + getRadius2() * getRadius2()); }

	// образующая l
	inline double MathL() { return sqrt(getHeight() * getHeight() + (getRadius1() - getRadius2()) * (getRadius1() - getRadius2())); }

	// площадь 
	inline double MathS() { return (M_PI * MathL() * (getRadius1() + getRadius2())) + M_PI * getRadius1() * getRadius1() + M_PI * getRadius2() * getRadius2(); };

	// выводит данные цилиндра в строку таблицы
	inline void tableRow(int i)
	{
		cout << "| " << setw(3) << i << " | " << setw(15) << radius1_
			<< " | " << setw(14) << radius2_
			<< " | " << setw(14) << height_
			<< " | " << setw(14) << MathS()
			<< " | " << setw(14) << MathV()
			<< " |";
	}

};