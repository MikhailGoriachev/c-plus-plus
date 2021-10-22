#include "DateTime.h"

#pragma region Конструкторы, деструктор и перегрузка операции присваивания

	// конструктор по умолчанию - устанавливает текущую дату и время
	DateTime::DateTime()
	{
		// текущая дата и время
		time_t now = time(0);
		tm* date = localtime(&now);

		// установка значений 
		day_ = date->tm_mday;
		month_ = date->tm_mon + 1;
		year_ = date->tm_year + 1900;
		hour_ = date->tm_hour;
		minute_ = date->tm_min;
		second_ = date->tm_sec;
	}
	
	// конструктор инициализирующий 
	DateTime::DateTime(int day, int month, int year, int hour, int minute, int second)
	{
		// установка даты и времени
		setDateTime(day, month, year, hour, minute, second);
	}
	
#pragma endregion

#pragma region Сеттеры и геттеры

	// сеттер даты и времени
	void DateTime::setDateTime(int day, int month, int year, int hour, int minute, int second)
	{
		// проверка даты
		if (!checkDateTime(day, month, year, hour, minute, second))
			throw exception("App: Время и/или дата некорректны!");

		// установка значений 
		day_ = day;
		month_ = month;
		year_ = year;
		hour_ = hour;
		minute_ = minute;
		second_ = second;
	}

	// сеттер даты
	void DateTime::setDate(int day, int month, int year)
	{
		// проверка даты
		if (!checkDate(day, month, year))
			throw exception("App: Дата некорректна!");

		// установка значений 
		day_ = day;
		month_ = month;
		year_ = year;
	}
		
	// сеттер времени
	void DateTime::setTime(int hour, int minute, int second)
	{
		// проверка даты
		if (!checkTime(hour, minute, second))
			throw exception("App: Время некорректно!");

		// установка значений 
		hour_ = hour;
		minute_ = minute;
		second_ = second;
	}

	// геттер day_
	int DateTime::getDay() { return day_; }

	// геттер month_
	int DateTime::getMonth() { return month_; }

	// геттер year_
	int DateTime::getYear() { return year_; }

	// геттер hour_
	int DateTime::getHour() { return hour_; }

	// геттер minute_
	int DateTime::getMinute() { return minute_; }

	// геттер second_
	int DateTime::getSecond() { return second_; }

#pragma endregion
	
#pragma region Методы

	// получение разницы между двумя моментами времени в секундах
	time_t DateTime::differenceTime(DateTime dateTime1, DateTime dateTime2)
	{
		// количество секунд 
		time_t second;

		// текущее время
		time(&second);

		// структура даты и времени
		tm* date;

		// инициализация структура 
		date = localtime(&second);

		// установка значений
		date->tm_year = dateTime1.year_ - 1900;
		date->tm_mon = dateTime1.month_ - 1;
		date->tm_mday = dateTime1.day_;
		date->tm_hour = dateTime1.hour_;
		date->tm_min = dateTime1.minute_;
		date->tm_sec = dateTime1.second_;

		// вычисление времени
		second = mktime(date);

		// установка значений
		date->tm_year = dateTime2.year_ - 1900;
		date->tm_mon = dateTime2.month_ - 1;
		date->tm_mday = dateTime2.day_;
		date->tm_hour = dateTime2.hour_;
		date->tm_min = dateTime2.minute_;
		date->tm_sec = dateTime2.second_;

		// вычисление времени
		second -= mktime(date);

		return second;
	}

	// проверка даты и времени на корректность от 1600 года н. э.
	bool DateTime::checkDateTime(int day, int month, int year, int hour, int minute, int second)
	{
		// массив количества дней в месяце
		int daysMonth[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// если год или месяц некорректны
		if (year < 1600 or month < 1 or month > 12)
			return false;

		// если год високосный
		if (isLeap(year))
			daysMonth[1]++;

		// если день некорректен 
		if (day <= 0 and day > daysMonth[month - 1])
			return false;

		// если время некорректно
		if (hour < 0 or hour > 23 or minute < 0 or minute > 59 or second < 0 or second > 59)
			return false;

		return true;
	}

	// проверка даты на корректность
	bool DateTime::checkDate(int day, int month, int year)
	{
		// массив количества дней в месяце
		int daysMonth[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		// если год или месяц некорректны
		if (year < 1600 or month < 1 or month > 12)
			return false;

		// если год високосный
		if (isLeap(year))
			daysMonth[1]++;

		// если день некорректен 
		if (day <= 0 and day > daysMonth[month - 1])
			return false;

		return true;
	}

	// проверка времени на корректность
	bool DateTime::checkTime(int hour, int minute, int second)
	{
		// если время некорректно
		if (hour < 0 or hour > 23 or minute < 0 or minute > 59 or second < 0 or second > 59)
			return false;

		return true;
	}
	
	// является и год високосным
	bool DateTime::isLeap(int year)
	{
		return year % 4 == 0 ? year % 100 == 0 ? year % 400 == 0 : true : false;
	}

	// вывод даты и времени в цвете
	void DateTime::showDateTime(short colorText)
	{
		// текущий цвет
		short cl = getColor();

		cout << color(colorText) << setfill('0') << setw(2) << day_ << "." << setw(2) << month_ << "."
			<< setw(4) << year_ << " " << setw(2) << hour_ << ":" << setw(2) << minute_ << ":" 
			<< setw(2) << second_ << setfill(' ') << color(cl);
	}

	// запись в бинарный файл
	void DateTime::write(fstream& fs)
	{
		fs.write((char*)&day_, sizeof(day_));
		fs.write((char*)&month_, sizeof(month_));
		fs.write((char*)&year_, sizeof(year_));
		fs.write((char*)&hour_, sizeof(hour_));
		fs.write((char*)&minute_, sizeof(minute_));
		fs.write((char*)&second_, sizeof(second_));
	}

	// чтение из банарного файла 
	void DateTime::read(fstream& fs)
	{
		fs.read((char*)&day_, sizeof(day_));
		fs.read((char*)&month_, sizeof(month_));
		fs.read((char*)&year_, sizeof(year_));
		fs.read((char*)&hour_, sizeof(hour_));
		fs.read((char*)&minute_, sizeof(minute_));
		fs.read((char*)&second_, sizeof(second_));
	}


	// равность по дате 
	bool DateTime::equalDate(const DateTime& dateTime) const
	{
		return day_ == dateTime.day_ and
			month_ == dateTime.month_ and
			year_ == dateTime.year_;
	}

#pragma endregion

#pragma region Дружественные функции

	// вывод в строку 
	ostream& operator<<(ostream& os, const DateTime& dateTime)
	{
		os << dateTime.day_ << "." << dateTime.month_ << "." << dateTime.year_ << " " 
			<< dateTime.hour_ << ":" << dateTime.minute_ << ":" << dateTime.second_ << "\n";

		return os;
	}

#pragma endregion