#pragma once

#include "pch.h"

class Conoid
{
	// высота
	double height_;

	// радиус 1 - радиус основания
	double radius1_;

	// радиус 2 - радиус вершины
	double radius2_;

public:

#pragma region Конструкторы и Деструкторы

	// конструктор по умолчанию
	Conoid() :height_(1), radius1_(1), radius2_(1) {};

	// конструктор с аргументами
	Conoid(double height, double radius1, double radius2)
	{
		setHeight(height);
		setRadius1(radius1);
		setRadius2(radius2);

		if (radius1 < radius2)
		{
			throw exception("Радиус основания должен быть больше, чем радиус вершины!\n");
		}
	}
	// деструктор
	~Conoid()
	{
		cout << "Conoid: Объект уничтожен" << endl;
	}

#pragma endregion

#pragma region Сеттеры и Геттеры

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
			throw exception("Ввёденный радиус меньше или равен нулю!");
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
			throw exception("Ввёденный радиус меньше или равен нулю!");
		}

		radius2_ = radius2;
	}

	// геттер радиус 2
	inline double getRadius2() const { return radius2_; };

#pragma endregion

#pragma region Методы

	// объём
	inline double MathV() { return M_PI / 3 * height_ * (radius1_ * radius1_ + radius1_ * radius2_ + radius2_ * radius2_); }

	// образующая l
	inline double MathL() { return sqrt(height_ * height_ + (radius1_ - radius2_) * (radius1_ - radius2_)); }

	// площадь 
	inline double MathS() { return (M_PI * MathL() * (radius1_ + radius2_)) + M_PI * radius1_ * radius1_ + M_PI * radius2_ * radius2_; };

	// сложение двух конусов
	Conoid* operator+(Conoid& con)
	{
		Conoid* newConoid = new Conoid;

		// сложение высоты
		newConoid->setHeight(this->height_ + con.getHeight());

		// сложение радиуса 1
		newConoid->setRadius1(this->radius1_ + con.getRadius1());

		// сложение радиуса 2
		newConoid->setRadius2(this->radius2_ + con.getRadius2());

		return newConoid;
	}

	// умножение на число
	Conoid* operator*(double num)
	{
		Conoid* newConoid = new Conoid;

		// умножение высоты
		newConoid->setHeight(this->height_ * num);

		// умножение радиуса 1
		newConoid->setRadius1(this->radius1_ * num);

		// умножение радиуса 2
		newConoid->setRadius2(this->radius2_ * num);

		return newConoid;
	}

	// вычитание числа
	Conoid* operator-(double num)
	{
		Conoid* newConoid = new Conoid;

		// умножение высоты
		newConoid->setHeight(this->height_ - num);

		// умножение радиуса 1
		newConoid->setRadius1(this->radius1_ - num);

		// умножение радиуса 2
		newConoid->setRadius2(this->radius2_ - num);

		return newConoid;
	}

#pragma endregion

#pragma region friend

	// перегрузка операции вывода << 
	friend ostream& operator<<(ostream& link, Conoid& con);

	// дружественная функция класса Conoid. перегрузка операции ввода >> 
	friend	istream& operator>>(istream& link, Conoid& con);

#pragma endregion

};