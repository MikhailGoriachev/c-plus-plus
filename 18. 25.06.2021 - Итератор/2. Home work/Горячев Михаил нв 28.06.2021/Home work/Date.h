#pragma once

#include "pch.h"

//  ласс даты ћ»Ќ»ћјЋ№Ќјя √ќƒ 1600
class Date
{
public:

	// минимальное значение года 
	static const int MINIMAL_YEAR = 1600;

private:

	// число
	int number_;

	// мес€ц
	int month_;

	// год
	int year_;

public:

#pragma region ѕравило трЄх

	// конструктор по умолчанию
	Date() = default;

	// конструктор иницилизирующий
	explicit Date(int number, int month, int year)
	{
		// защищЄнна€ установка значений
		setDate(number, month, year);
	}

	// копирующий конструктор
	Date(const Date& date) = default;

	// деструктор
	~Date() = default;

	// перегрузка операции присваивани€
	Date& operator=(const Date& date) = default;

#pragma endregion

#pragma region —еттеры и геттеры

	// сеттер даты
	void setDate(int number, int month, int year)
	{
		// если данные некорректны
		if (year < MINIMAL_YEAR || number < 1 || month < 1 || month > 12)
			throw exception("Date: некорректна€ дата!");

		// установка года
		year_ = year;

		// массив с мес€цами и количеством дней
		int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		// ссылка на февраль
		int& february = months[1];

		// коррекци€ количества дней в феврале, если год високосный
		if (chekYear())
			february++;

		// проверка корректности даты
		if (number > months[month - 1])
			throw exception("Date: некорректна€ дата!");

		// установка значений
		number_ = number;
		month_ = month-1;
	}

	// геттер числа 
	int getNumber() { return number_; }

	// геттер мес€ца
	int getMonth() { return month_ + 1; }

	// геттер года
	int getYear() { return year_; }

#pragma endregion

	// проверка года на принадлежность к високосным годам
	bool chekYear()
	{
		// если год кратен 400 - високосный
		if (year_ % 400 == 0)
			return true;

		// если год кратен 100 - невисокосный
		if (year_ % 100 == 0)
			return false;

		// если год делитс€ 4 без остатка - високосный
		if (year_ % 4 == 0)
			return true;

		return false;
	}

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const Date& date)
	{
		os << setfill('0') << setw(2) << date.number_ << "." << setw(2) << date.month_ + 1 << "." << date.year_ << setfill(' ');

		return os;
	}

};

