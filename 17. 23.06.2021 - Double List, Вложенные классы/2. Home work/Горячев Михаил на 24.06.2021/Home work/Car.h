#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <vcruntime_string.h>
#include "pch.h"

// класс данных о машине
class Car
{
public:

	// длина поля номера
	static const int NUMBER_SIZE = 11;

	// длина поля цвета 
	static const int COLOR_SIZE = 21;

	// длина поля марки
	static const int BRAND_SIZE = 21;

private:

	// номер 
	char* number_;

	// цвет 
	char* color_;

	// марка 
	char* brand_;

public:

	// констркуктор по умолчанию
	Car() : number_(new char[NUMBER_SIZE]), color_(new char[COLOR_SIZE]), brand_(new char[BRAND_SIZE])
	{
		// заполнение строк нулями
		memset(number_, 0, NUMBER_SIZE);
		memset(color_, 0, COLOR_SIZE);
		memset(brand_, 0, BRAND_SIZE);
	}

	// констркутор инициализирующий
	Car(const char* number, const char* color, const char* brand) : number_(new char[NUMBER_SIZE]), color_(new char[COLOR_SIZE]), brand_(new char[BRAND_SIZE])
	{
		// установка значений
		setNumber(number);
		setColor(color);
		setBrand(brand);
	}

	// копирующий констркутор 
	Car(const Car& car) : number_(new char[NUMBER_SIZE]), color_(new char[COLOR_SIZE]), brand_(new char[BRAND_SIZE])
	{
		strcpy(number_, car.number_);
		strcpy(color_, car.color_);
		strcpy(brand_, car.brand_);
	}

	// деструктор 
	~Car() 
	{ 
		delete[]number_;
		delete[]color_;
		delete[]brand_;
	}

	// перегрузка операции присваивания
	Car& operator=(const Car& car)
	{
		memcpy(number_, car.number_, NUMBER_SIZE);
		memcpy(color_, car.color_, COLOR_SIZE);
		memcpy(brand_, car.brand_, BRAND_SIZE);

		return *this;
	}

	// геттер number_
	char* getNumber()
	{
		char* number = new char[NUMBER_SIZE];

		memcpy(number, number_, NUMBER_SIZE);

		return number;
	}

	// сеттер number_
	void setNumber(const char* number)
	{
		strcpy(number_, number);
	}

	// геттер color_
	char* getColor()
	{
		char* color = new char[COLOR_SIZE];

		strcpy(color, color_);

		return color;
	}

	// сеттер color_
	void setColor(const char* color)
	{
		strcpy(color_, color);
	}

	// геттер brand_
	char* getBrand()
	{
		char* brand = new char[BRAND_SIZE];

		memcpy(brand, brand_, BRAND_SIZE);

		return brand;
	}

	// сеттер brand_
	void setBrand(const char* brand)
	{
		strcpy(brand_, brand);
	}

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const Car& car);
};

