#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include <ctime>

// Для представления даты и времени используйте класс DateTime с полями – день, месяц, год,
// час, минута, секунда.Реализуйте методы вычисления разности между двумя моментами времени
// в секундах.Перегрузите операции сравнения двух моментов времени.

// Класс даты и времени
class DateTime
{
#pragma region Константы 

public:

	// количество секунд в годе високосном 
	static int const N_SECOND_LEAP_YEAR = 31622400;
	
	// количество секунд в годе НЕ високосном 
	static int const N_SECOND_YEAR = 31536000;

	// количество секунд в дне 
	static int const N_SECOND_DAY = 86400;

	// количество секунд в часе 
	static int const N_SECOND_HOUR = 3600;

	// количество секунд в минуте 
	static int const N_SECOND_MINUTE = 60;

#pragma endregion

private:

	// день 
	int day_;

	// месяц
	int month_;

	// год
	int year_;

	// час
	int hour_;

	// минута
	int minute_;

	// секунда 
	int second_;

public:

#pragma region Конструкторы, деструктор и перегрузка операции присваивания

	// конструктор по умолчанию - устанавливает текущую дату и время
	DateTime();

	// конструктор инициализирующий 
	DateTime(int day, int month, int year, int hour, int minute, int second);

	// конструктор копирующий 
	DateTime(const DateTime& dateTime) = default;

	// деструктор 
	~DateTime() = default;

	// перегрузка операции присваивания
	DateTime& operator=(const DateTime& dateTime) = default;

#pragma endregion

#pragma region Сеттеры и геттеры

	// сеттер даты и времени
	void setDateTime(int day, int month, int year, int hour, int minute, int second);

	// сеттер даты
	void setDate(int day, int month, int year);

	// сеттер времени
	void setTime(int hour, int minute, int second);

	// геттер day_
	int getDay();

	// геттер month_
	int getMonth();

	// геттер year_
	int getYear();

	// геттер hour_
	int getHour();

	// геттер minute_
	int getMinute();

	// геттер second_
	int getSecond();

#pragma endregion

#pragma region Методы

	// получение разницы между двумя моментами времени в секундах
	static time_t differenceTime(DateTime dateTime1, DateTime dateTime2);

	// проверка даты и времени на корректность
	static bool checkDateTime(int day, int month, int year, int hour, int minute, int second);

	// проверка даты на корректность
	static bool checkDate(int day, int month, int year);

	// проверка времени на корректность
	static bool checkTime(int hour, int minute, int second);

	// является и год високосным
	static bool isLeap(int year);

	// вывод даты и времени в цвете
	void showDateTime(short colorText);

	// запись в бинарный файл
	void write(fstream& fs);

	// чтение из банарного файла 
	void read(fstream& fs);

	// равность по дате 
	bool equalDate(const DateTime & dateTime) const;

#pragma region Перегрузка операций сравнения 

	// меньше
	bool operator<(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ < dateTime.year_ :
			month_ != dateTime.month_ ? month_ < dateTime.month_ :
			day_ != dateTime.day_ ? day_ < dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ < dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ < dateTime.minute_ :
			second_ < dateTime.second_;
	}

	// меньше или равно
	bool operator<=(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ <= dateTime.year_ :
			month_ != dateTime.month_ ? month_ <= dateTime.month_ :
			day_ != dateTime.day_ ? day_ <= dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ <= dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ <= dateTime.minute_ :
			second_ <= dateTime.second_;
	}

	// равно
	bool operator==(const DateTime& dateTime) const
	{
		return year_ == dateTime.year_ and month_ == dateTime.month_ and
			day_ == dateTime.day_ and hour_ == dateTime.hour_ and
			minute_ == dateTime.minute_ and	second_ == dateTime.second_;
	}

	// НЕ равно
	bool operator!=(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ and month_ != dateTime.month_ and
			day_ != dateTime.day_ and hour_ != dateTime.hour_ and
			minute_ != dateTime.minute_ and second_ != dateTime.second_;
	}

	// больше или равно
	bool operator>=(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ >= dateTime.year_ :
			month_ != dateTime.month_ ? month_ >= dateTime.month_ :
			day_ != dateTime.day_ ? day_ >= dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ >= dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ >= dateTime.minute_ :
			second_ >= dateTime.second_;
	}

	// больше 
	bool operator>(const DateTime& dateTime) const
	{
		return year_ != dateTime.year_ ? year_ > dateTime.year_ :
			month_ != dateTime.month_ ? month_ > dateTime.month_ :
			day_ != dateTime.day_ ? day_ > dateTime.day_ :
			hour_ != dateTime.hour_ ? hour_ > dateTime.hour_ :
			minute_ != dateTime.minute_ ? minute_ > dateTime.minute_ :
			second_ > dateTime.second_;
	}

#pragma endregion

#pragma endregion

#pragma region Дружественные функции
	
	// вывод в строку 
	friend ostream& operator<<(ostream& os, const DateTime& dateTime);

#pragma endregion

};