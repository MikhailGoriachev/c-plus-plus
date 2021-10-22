#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <vcruntime_string.h>
#include "pch.h"

// ����� ������ � ������
class Car
{
public:

	// ����� ���� ������
	static const int NUMBER_SIZE = 11;

	// ����� ���� ����� 
	static const int COLOR_SIZE = 21;

	// ����� ���� �����
	static const int BRAND_SIZE = 21;

private:

	// ����� 
	char* number_;

	// ���� 
	char* color_;

	// ����� 
	char* brand_;

public:

	// ������������ �� ���������
	Car() : number_(new char[NUMBER_SIZE]), color_(new char[COLOR_SIZE]), brand_(new char[BRAND_SIZE])
	{
		// ���������� ����� ������
		memset(number_, 0, NUMBER_SIZE);
		memset(color_, 0, COLOR_SIZE);
		memset(brand_, 0, BRAND_SIZE);
	}

	// ����������� ����������������
	Car(const char* number, const char* color, const char* brand) : number_(new char[NUMBER_SIZE]), color_(new char[COLOR_SIZE]), brand_(new char[BRAND_SIZE])
	{
		// ��������� ��������
		setNumber(number);
		setColor(color);
		setBrand(brand);
	}

	// ���������� ����������� 
	Car(const Car& car) : number_(new char[NUMBER_SIZE]), color_(new char[COLOR_SIZE]), brand_(new char[BRAND_SIZE])
	{
		strcpy(number_, car.number_);
		strcpy(color_, car.color_);
		strcpy(brand_, car.brand_);
	}

	// ���������� 
	~Car() 
	{ 
		delete[]number_;
		delete[]color_;
		delete[]brand_;
	}

	// ���������� �������� ������������
	Car& operator=(const Car& car)
	{
		memcpy(number_, car.number_, NUMBER_SIZE);
		memcpy(color_, car.color_, COLOR_SIZE);
		memcpy(brand_, car.brand_, BRAND_SIZE);

		return *this;
	}

	// ������ number_
	char* getNumber()
	{
		char* number = new char[NUMBER_SIZE];

		memcpy(number, number_, NUMBER_SIZE);

		return number;
	}

	// ������ number_
	void setNumber(const char* number)
	{
		strcpy(number_, number);
	}

	// ������ color_
	char* getColor()
	{
		char* color = new char[COLOR_SIZE];

		strcpy(color, color_);

		return color;
	}

	// ������ color_
	void setColor(const char* color)
	{
		strcpy(color_, color);
	}

	// ������ brand_
	char* getBrand()
	{
		char* brand = new char[BRAND_SIZE];

		memcpy(brand, brand_, BRAND_SIZE);

		return brand;
	}

	// ������ brand_
	void setBrand(const char* brand)
	{
		strcpy(brand_, brand);
	}

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const Car& car);
};

