#pragma once

#include "pch.h"
#include "Utils.h"

/* 
 * Класс Personи меет поля(модификация класса предыдущего задания, добавлено
 * поле, используются строки в стиле C++ т.е.класс string) :
 *	•	Табельный номер, целое число, уникальное в пределах приложения
 *	•	Фамилия и инициалы – поле класса string
 *	•	Город проживания – поле класса string
 *	•	Оклад, вещественное число
 *	•	Год поступления на работу
 *	•	Количество рабочих дней в месяце
 *	•	Количество фактически отработанных дней в месяце

 * Разработать конструкторы и деструктор, аксессоры, метод вычисления начислений
 * – произведение оклада на отношение количества фактически отработанных дней к
 * количеству рабочих дней в месяце.
 * Начислено = Оклад∙(Фактически отработано) / (Рабочих дней в месчце)
*/
// Класс данных о рабочем
class Person
{
public:

#pragma region Константы

	// размер буфера для работы с файлами
	static const int BUF_SIZE = 1024;

	// максимальная длина поля фамилия и инициалы – поле, класса string
	static const int MAX_NAME_SIZE = 80;

	// минимальная длина поля фамилия и инициалы – поле, класса string
	static const int MIN_NAME_SIZE = 0;
	
	// максимальная длина поля город проживания — поле, класса string
	static const int MAX_CITY_SIZE = 100;

	// минимальная длина поля город проживания — поле, класса string 
	static const int MIN_CITY_SIZE = 1;

	// максимальный оклад 
	static const double MAX_SALARY;

	// минимальный оклад
	static const double MIN_SALARY;

	// максимальный год поступления на работу
	static const int MAX_YEAR = 2021;
	
	// минимальный год поступления на работу
	static const int MIN_YEAR = 1930;

	// максимальное количество рабочих дней в месяце
	static const int MAX_MONTH_WORK_DAY = 31;

	// минимальное количество рабочих дней в месяце
	static const int MIN_MONTH_WORK_DAY = 0;

	// минимальное количество фактически отработанных дней в месяце
	static const int MIN_COMPLETED_WORK_DAY = 0;

#pragma endregion

private:

	// Табельный номер, целое число, уникальное в пределах приложения unsigned int
	unsigned int number_;

	// Фамилия и инициалы – поле, класса string
	string name_;

	// Город проживания – поле, класса string
	string city_;

	// Оклад, вещественное число, double
	double salary_;

	// Год поступления на работу, int
	int year_;

	// Количество рабочих дней в месяце, int
	int monthWorkDay_;

	// Количество фактически отработанных дней в месяце, int
	int completedWorkDay_;

public:

#pragma region Конструкторы, деструктор и операция присваивания

	// конструктор по умолчанию 
	Person() try {}
	catch (...)
	{
		// вывод ошибки
		cputs("Person: Ошибка в конструкторе по умолчанию", errColor);
	}

	// конструктор инициализирующий 
	Person(unsigned int number, string name, string city, double salary, int year, int monthWorkDay, int completedWorkDay) try
		: name_(new char[MAX_NAME_SIZE] {0})
	{
		// установка значений
		setNumber(number);
		setName(name);
		setCity(city);
		setSalary(salary);
		setYear(year);
		setWorkDay(monthWorkDay, completedWorkDay);
	}
	catch (exception &ex)
	{
		stringstream os;

		os << "\tPerson: Конструктор инициализирующий: " << ex.what() << "\n\n";

		// вывод ошибки
		cputs(os.str().c_str(), errColor);
	}

	// конструктор копирующий
	Person(const Person& person) try : name_(new char[MAX_NAME_SIZE] {0})
	{
		number_ = person.number_;
		name_ = person.name_;
		city_ = person.city_;
		salary_ = person.salary_;
		year_ = person.year_;
		monthWorkDay_ = person.monthWorkDay_;
		completedWorkDay_ = person.completedWorkDay_;
	}
	catch (...)
	{
		// вывод ошибки
		cputs("Person: Ошибка в копирующем конструкторе", errColor);
	}

	// деструктор 
	~Person() {}

	// операция присваивания
	Person& operator=(const Person& person)
	{
		number_ = person.number_;
		name_ = person.name_;
		city_ = person.city_;
		salary_ = person.salary_;
		year_ = person.year_;
		monthWorkDay_ = person.monthWorkDay_;
		completedWorkDay_ = person.completedWorkDay_;

		return *this;
	}

#pragma endregion

#pragma region Сеттеры и геттеры

	// сеттер number_
	void setNumber(unsigned int number)
	{
		number_ = number;
	}

	// геттер number_
	unsigned int getNumber() { return number_; }

	// сеттер name_
	void setName(string name)
	{
		// длина строки
		size_t size = name.size();

		// если данные некорректны 
		if (size < MIN_NAME_SIZE or size > MAX_NAME_SIZE)
			throw exception("Person: Некорректные данные!");

		// присваивание строки
		name_ = name;
	}

	// геттер name_
	const string getName() { return name_; }

	// сеттер city_
	void setCity(string city)
	{
		// длина строки
		size_t size = city.size();

		// если данные некорректны
		if (size < MIN_CITY_SIZE or size > MAX_CITY_SIZE)
			throw exception("Person: Некорректные данные!");

		// присваивание строки
		city_ = city;
	}

	// геттер city_
	const string getCity() { return city_; }

	// сеттер salary_
	void setSalary(double salary)
	{
		// если данные некорректны
		if (salary > MAX_SALARY or salary < MIN_SALARY)
			throw exception("Person: Некорректные данные!");

		salary_ = salary;
	}

	// геттер salary_
	double getSalary() { return salary_; }

	// сеттер year_
	void setYear(int year)
	{
		// если данные некорректны
		if (year > MAX_YEAR or year < MIN_YEAR)
			throw exception("Person: Данные некорректны!");

		year_ = year;
	}

	// геттер year_
	int getYear() { return year_; }

	// сеттер monthWorkDay_ и completedWorkDay_
	void setWorkDay(int monthWorkDay, int completedWorkDay)
	{
		// если данные некорректны
		if (monthWorkDay > MAX_MONTH_WORK_DAY or monthWorkDay < MIN_MONTH_WORK_DAY
			or completedWorkDay > monthWorkDay or completedWorkDay < MIN_COMPLETED_WORK_DAY)
			throw exception("Person: Данные некорректны!");

		monthWorkDay_ = monthWorkDay;
		completedWorkDay_ = completedWorkDay;
	}

	// геттер monthWorkDay_
	int getMonthWorkDay() { return monthWorkDay_; }

	// геттер completedWorkDay_
	int getcompletedWorkDay() { return completedWorkDay_; }

#pragma endregion

#pragma region Методы

	// метод вычисления начислений
	// – произведение оклада на отношение количества фактически отработанных дней к
	// количеству рабочих дней в месяце.
	// Начислено = Оклад∙(Фактически отработано) / (Рабочих дней в месяце)
	double accrued() { return salary_* completedWorkDay_ / monthWorkDay_; }

	// вывод элемента для таблицы
	void showElem(int i);

	// вывод пустого элемента 
	static void showEmpty();

	// вывод заголовка таблицы
	static void showHead();

	// вывод разделителя-разделителя для таблицы
	static void showLine();

	// перегрузка операции сравнения
	bool operator<(Person person) { return number_ < person.number_; }
	bool operator<=(Person person) { return number_ <= person.number_; }
	bool operator==(Person person) { return number_ == person.number_; }
	bool operator!=(Person person) { return number_ != person.number_; }
	bool operator>=(Person person) { return number_ >= person.number_; }
	bool operator>(Person person) { return number_ > person.number_; }

	// запись в бинарный файл 
	void write(ofstream& ofs);

	// запись в бинарный файл 
	void write(fstream& fs);

	// чтение из бинарного файла 
	void read(ifstream& ifs);

	// чтение из бинарного файла 
	void read(fstream& fs);

	// чтение из текстового файла 
	void readText(ifstream& ifs);

	// чтение из текстового файла 
	void readText(fstream& fs);


	// размер объекта в файле
	static constexpr int RECORD_SIZE = sizeof(Person::number_) + Person::MAX_NAME_SIZE +
		Person::MAX_CITY_SIZE + sizeof(Person::salary_) + sizeof(Person::year_) +
		sizeof(Person::monthWorkDay_) + sizeof(Person::completedWorkDay_);

#pragma endregion
	
#pragma region Дружественные функции

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const Person& person);

	// перегрузка операции вывода в текстовый файл 
	friend ofstream& operator<<(ofstream& os, const Person& person);

	// перегрузка операции вывода в текстовый файл 
	friend fstream& operator<<(fstream& os, const Person& person);

#pragma endregion

};