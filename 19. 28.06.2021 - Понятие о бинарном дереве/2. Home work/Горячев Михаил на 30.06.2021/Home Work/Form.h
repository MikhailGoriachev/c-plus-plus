#pragma once

#include "pch.h"
#include "Date.h"

// Элемент очереди должен хранить фамилию, имя и отчество претендента, количество
// членов семьи, площадь квартиры в м2, количество комнат, дату постановки на учет
// (день, месяц, год–класс Date).

// Класс данных человека в очереди
class Form
{
public:

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

	// максимальное количество членов семьи
	static const int COUNT_FAMILY_MAX = 30;

	// минимальное количество членов чемьи
	static const int COUNT_FAMILY_MIN = 1;

	// максимальна площадь квартиры
	static const double AREA_MAX;

	// минимальная площадь квартиры
	static const double AREA_MIN;

	// максимальное количество комнат
	static const int COUNT_ROOM_MAX = 50;

	// минимальное количество комнат
	static const int COUNT_ROOM_MIN = 1;

	// максимальный год постановки на учёт
	static const int YEAR_MAX = 2022;

	// максимальный месяц постановки на учёт 
	static const int MONTH_MAX = 1;

	// максимальное число постановки на учёт
	static const int NUMBER_MAX = 1;

	// минимальный год постановки на учёт
	static const int YEAR_MIN = 1960;

	// минимальный месяц постановки на учёт 
	static const int MONTH_MIN = 1;

	// минимальное число постановки на учёт
	static const int NUMBER_MIN = 1;

private:

	// фамилия
	char* surname_;

	// имя
	char* name_;

	// отчество
	char* patronymic_;

	// количество членов семьи
	int countFamily_;

	// площадь квартиры
	double area_;

	// количество комнат
	int countRoom_;

	// дата постановки на учёт 
	Date date_;

public:

#pragma region Конструкторы, деструктор и перегрузка присваивания

	// конструктор по умолчанию
	Form()
	{
		// выделение памяти для полей типа char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};
	}

	// конструктор инициализирующий
	Form(char* surname, char* name, char* patronymic, int countFamily, double area, int countRoom, Date date)
	{
		// выделение памяти для полей типа char*
		surname_ = new char[SURNAME_MAX_SIZE + 1]{ 0 };
		name_ = new char[NAME_MAX_SIZE + 1]{ 0 };
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1]{ 0 };

		// установка значений
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setCountFamily(countFamily);
		setArea(area);
		setCountRoom(countRoom);
		setDate(date);
	}

	// конструктор инициализирующий
	Form(const char* surname, const char* name, const char* patronymic, int countFamily, double area, int countRoom, Date date)
	{
		// выделение памяти для полей типа char*
		surname_ = new char[SURNAME_MAX_SIZE + 1]{ 0 };
		name_ = new char[NAME_MAX_SIZE + 1]{ 0 };
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1]{ 0 };

		// установка значений
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setCountFamily(countFamily);
		setArea(area);
		setCountRoom(countRoom);
		setDate(date);
	}

	// конструктор копирующий
	Form(const Form& Form) : 
		countFamily_(Form.countFamily_), 
		area_(Form.area_), 
		countRoom_(Form.countRoom_),
		date_(Form.date_)
	{
		// выделение памяти для полей типа char*
		surname_ = new char[SURNAME_MAX_SIZE + 1] {0};
		name_ = new char[NAME_MAX_SIZE + 1] {0};
		patronymic_ = new char[PATRONYMIC_MAX_SIZE + 1] {0};

		// копирование значений
		memcpy(surname_, Form.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, Form.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, Form.patronymic_, PATRONYMIC_MAX_SIZE);
	}
	
	// деструктор
	~Form()
	{
		delete[]surname_;
		delete[]name_;
		delete[]patronymic_;
	}

	// перегрузка операции присваивания
	Form& operator=(const Form& Form)
	{
		// присваивание 
		countFamily_ = Form.countFamily_;
		area_ = Form.area_;
		countRoom_ = Form.countRoom_;
		date_ = Form.date_;

		// копирование значений
		memcpy(surname_, Form.surname_, SURNAME_MAX_SIZE);
		memcpy(name_, Form.name_, NAME_MAX_SIZE);
		memcpy(patronymic_, Form.patronymic_, PATRONYMIC_MAX_SIZE);

		return *this;
	}

#pragma endregion

#pragma region Сеттеры и Геттеры

	// сеттер surname_ char*
	void setSurname(char* surname)
	{
		// длина строки
		int size = strlen(surname);

		// если данные некорректны
		if (size < SURNAME_MIN_SIZE && size > SURNAME_MAX_SIZE)
			throw exception("Form: данные некорректны!");

		// копирование строки
		strcpy(surname_, surname);
	}

	// сеттер surname_ const char*
	void setSurname(const char* surname)
	{
		// длина строки
		int size = strlen(surname);

		// если данные некорректны
		if (size < SURNAME_MIN_SIZE && size > SURNAME_MAX_SIZE)
			throw exception("Form: данные некорректны!");

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

	// сеттер name_ char*
	void setName(char* name)
	{
		// длина строки
		int size = strlen(name);

		// если данные некорректны
		if (size < NAME_MIN_SIZE && size > NAME_MAX_SIZE)
			throw exception("Form: данные некорректны!");

		// копирование строки
		strcpy(name_, name);
	}

	// сеттер name_ const char*
	void setName(const char* name)
	{
		// длина строки
		int size = strlen(name);

		// если данные некорректны
		if (size < NAME_MIN_SIZE && size > NAME_MAX_SIZE)
			throw exception("Form: данные некорректны!");

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

	// сеттер patronymic_ char* 
	void setPatronymic(char* patronymic)
	{
		// длина строки
		int size = strlen(patronymic);

		// если данные некорректны
		if (size < PATRONYMIC_MIN_SIZE && size > PATRONYMIC_MAX_SIZE)
			throw exception("Form: данные некорректны!");

		// копирование строки
		strcpy(patronymic_, patronymic);
	}

	// сеттер patronymic_ const char*
	void setPatronymic(const char* patronymic)
	{
		// длина строки
		int size = strlen(patronymic);

		// если данные некорректны
		if (size < PATRONYMIC_MIN_SIZE && size > PATRONYMIC_MAX_SIZE)
			throw exception("Form: данные некорректны!");

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

	// сеттер countFamily_ int
	void setCountFamily(int countFamily)
	{
		// если данные некорректны
		if (countFamily < COUNT_FAMILY_MIN && countFamily > COUNT_FAMILY_MAX)
			throw exception("Form: данные некорректны!");

		// копирование значения 
		countFamily_ = countFamily;
	}

	// геттер countFamily_
	int getCountFamily() { return countFamily_; }

	// сеттер area_
	void setArea(double area)
	{
		// если данные некорректны
		if (area < AREA_MIN && area > AREA_MAX)
			throw exception("Form: данные некорректны!");

		// копирование значения 
		area_ = area;
	}

	// геттер area_
	double getArea() { return area_; }

	// сеттер countRoom_
	void setCountRoom(int countRoom)
	{
		// если данные некорректны
		if (countRoom < COUNT_FAMILY_MIN && countRoom > COUNT_FAMILY_MAX)
			throw exception("Form: данные некорректны!");

		// копирование значения 
		countRoom_ = countRoom;
	}

	// геттер countRoom_
	int getCountRoom() { return countRoom_; }

	// сеттер date_
	void setDate(Date date)
	{
		date_ = date;
	}

	// геттер date_
	Date getDate() { return date_; }

#pragma endregion

#pragma region Методы

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const Form& Form);


#pragma endregion
};

