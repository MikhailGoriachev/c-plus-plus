#pragma once

#include "pch.h"
#include "Date.h"

// Класс Person, представляющий данные о жителе некоторого города, поля
// класса фамилия, имя, отчество(все три поля типа char*), рост в сантиметрах(тип double),
// вес в килограммах(тип double), город проживания(тип char*).

// Класс данных человека города
class Person
{
public:

#pragma region Константы значений 

	// максимальная длина фамилии
	static const int SURNAME_MAX_SIZE = 50;

	// минимальная длина фамилии
	static const int SURNAME_MIN_SIZE = 1;

	// максимальная длина имени 
	static const int NAME_MAX_SIZE = 40;

	// минимальная длина имени
	static const int NAME_MIN_SIZE = 1;

	// максимальная длина отчества 
	static const int PATRONYMIC_MAX_SIZE = 50;

	// минимальная длина отчества 
	static const int PATRONYMIC_MIN_SIZE = 3;

	// максимальный рост в сантиметрах
	static const double HEIGHT_MAX;
	
	// минимальный рост в сантиметрах
	static const double HEIGHT_MIN;

	// максимальный вес в киллограмах
	static const double WEIGHT_MAX;

	// минимальный вес в киллограмах
	static const double WEIGHT_MIN;

	// минмильная длина названия города
	static const int CITY_MAX_SIZE = 90;
	
	// максимальная длина названия города
	static const int CITY_MIN_SIZE = 1;

#pragma endregion

private:

	// фамилия
	char* surname_;

	// имя
	char* name_;

	// отчество
	char* patronymic_;

	// рост в сантиметрах
	double height_;

	// вес в килограммах
	double weight_;

	// город проживания
	char* city_;

public:

#pragma region Конструкторы, деструктор и перегрузка присваивания

	// конструктор по умолчанию
	Person()
	{
		// выделение памяти для полей типа char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};
		city_ = new char[CITY_MAX_SIZE + 1];
	}

	// конструктор инициализирующий
	Person(const char* surname, const char* name, const char* patronymic, double height, double weight, const char* city)
	{
		// выделение памяти для полей типа char*
		surname_ = new char[SURNAME_MAX_SIZE + 1]{ 0 };
		name_ = new char[NAME_MAX_SIZE + 1]{ 0 };
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1]{ 0 };
		city_ = new char[CITY_MAX_SIZE + 1];
		
		// установка значений
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setHeight(height);
		setWeight(weight);
		setCity(city);
	}

	// конструктор копирующий
	Person(const Person& person) :
		height_(person.height_),
		weight_(person.weight_)
	{
		// выделение памяти для полей типа char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};
		city_ = new char[CITY_MAX_SIZE + 1];

		// копирование значений
		memcpy(surname_, person.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, person.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, person.patronymic_, PATRONYMIC_MAX_SIZE);
		memcpy(city_, person.city_, CITY_MAX_SIZE);
	}
	
	// деструктор
	~Person()
	{
		delete[]surname_;
		delete[]name_;
		delete[]patronymic_;
		delete[]city_;
	}

	// перегрузка операции присваивания
	Person& operator=(const Person& person)
	{
		// присваивание 
		height_ = person.height_;
		weight_ = person.weight_;

		// копирование значений
		memcpy(surname_, person.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, person.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, person.patronymic_, PATRONYMIC_MAX_SIZE);
		memcpy(city_, person.city_, CITY_MAX_SIZE);

		return *this;
	}

#pragma endregion

#pragma region Сеттеры и Геттеры

	// сеттер surname_ const char*
	void setSurname(const char* surname)
	{
		// длина строки
		int size = strlen(surname);

		// если данные некорректны
		if (size < SURNAME_MIN_SIZE && size > SURNAME_MAX_SIZE)
			throw exception("Person: данные некорректны!");

		// копирование строки
		strcpy(surname_, surname);
	}

	// геттер surname_
	char* getSurname()
	{
		// создание строки для возвращения значения
		char* tmp = new char[SURNAME_MAX_SIZE + 1];

		// копирование значение 
		memcpy(tmp, surname_, SURNAME_MAX_SIZE);

		return tmp;
	}

	// сеттер name_ const char*
	void setName(const char* name)
	{
		// длина строки
		int size = strlen(name);

		// если данные некорректны
		if (size < NAME_MIN_SIZE && size > NAME_MAX_SIZE)
			throw exception("Person: данные некорректны!");

		// копирование строки
		strcpy(name_, name);
	}

	// геттер name_
	char* getName()
	{
		// создание строки для возвращения значения
		char* tmp = new char[NAME_MAX_SIZE + 1];

		// копирование значение 
		memcpy(tmp, name_, NAME_MAX_SIZE);

		return tmp;
	}

	// сеттер patronymic_ const char*
	void setPatronymic(const char* patronymic)
	{
		// длина строки
		int size = strlen(patronymic);

		// если данные некорректны
		if (size < PATRONYMIC_MIN_SIZE && size > PATRONYMIC_MAX_SIZE)
			throw exception("Person: данные некорректны!");

		// копирование строки
		strcpy(patronymic_, patronymic);
	}

	// геттер patronymic_
	char* getPatronymic()
	{
		// создание строки для возвращения значения
		char* tmp = new char[PATRONYMIC_MAX_SIZE + 1];

		// копирование значение 
		memcpy(tmp, patronymic_, PATRONYMIC_MAX_SIZE);

		return tmp;
	}

	// сеттер height_
	void setHeight(double height)
	{
		// если данные некорректны
		if (height < HEIGHT_MIN && height > HEIGHT_MAX)
			throw exception("Person: данные некорректны!");

		// копирование значения 
		height_ = height;
	}

	// геттер height_
	double getHeight() { return height_; }

	// сеттер weight_
	void setWeight(double weight)
	{
		// если данные некорректны
		if (weight < WEIGHT_MIN && weight > WEIGHT_MAX)
			throw exception("Person: данные некорректны!");

		// копирование значения 
		weight_ = weight;
	}

	// геттер weight_
	double getWeight() { return weight_; }

	// сеттер city_ const char*
	void setCity(const char* city)
	{
		// длина строки
		int size = strlen(city);

		// если данные некорректны
		if (size < CITY_MIN_SIZE && size > CITY_MAX_SIZE)
			throw exception("Person: данные некорректны!");

		// копирование строки
		strcpy(city_, city);
	}

	// геттер city_
	char* getCity()
	{
		// создание строки для возвращения значения
		char* tmp = new char[CITY_MAX_SIZE + 1];

		// копирование значение 
		memcpy(tmp, city_, CITY_MAX_SIZE);

		return tmp;
	}


#pragma endregion

#pragma region Методы

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const Person& person);

#pragma endregion
};

