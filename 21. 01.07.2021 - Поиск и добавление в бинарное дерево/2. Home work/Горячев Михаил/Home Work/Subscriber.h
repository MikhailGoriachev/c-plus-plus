#pragma once

#include "pch.h"
#include "Utils.h"

/*
	Разработать класс для представления абонента телефонной станции с полями для
	хранения :
	•	фамилии и инициалов
	•	телефонного номера
	•	времени разговоров(в минутах) за последний месяц.
*/

// Класс телефонного абонента
class Subscriber
{
public:

	// максимальная длина поля фамилии и инициалов
	static const int OWNER_MAX_SIZE = 40;

	// минимальная длина поля фамилии и инициалов
	static const int OWNER_MIN_SIZE = 0;

	// обязательная длина телефонного номера
	static const int NUMBER_SIZE = 10;

	// максимальное количество минут в месяце
	static const int MINUTE_MAX = 43800;

	// минимальное количество минут в месяце 
	static const int MINUTE_MIN = 0;

private:

	// фамилия и инициалы
	char* owner_;

	// телефонный номер
	char* number_;

	// время разговоров(в минутах) за последний месяц
	int minute_;

public:

#pragma region Конструкторы, деструктор, присваивание

	// конструктор по умолчанию
	Subscriber() :
		owner_(new char[OWNER_MAX_SIZE + 1]{ 0 }),
		number_(new char[NUMBER_SIZE + 1]{ 0 }),
		minute_() {}

	// конструктор инициализирущий
	Subscriber(const char* owner, const char* number, int minute) :
		owner_(new char[OWNER_MAX_SIZE + 1]{ 0 }),
		number_(new char[NUMBER_SIZE + 1]{ 0 }),
		minute_() 
	{
		setOwner(owner);
		setNumber(number);
		setMinute(minute);
	}

	// конструктор копирующий
	Subscriber(const Subscriber& subscriber) :
		owner_(new char[OWNER_MAX_SIZE + 1]{ 0 }),
		number_(new char[NUMBER_SIZE + 1]{ 0 }),
		minute_(subscriber.minute_)
	{
		memcpy(owner_, subscriber.owner_, OWNER_MAX_SIZE);
		memcpy(number_, subscriber.number_, NUMBER_SIZE);
	}

	// перегрузка операции присваивания
	Subscriber& operator=(const Subscriber& subscriber)
	{
		if (this == &subscriber) return *this;

		memcpy(owner_, subscriber.owner_, OWNER_MAX_SIZE);
		memcpy(number_, subscriber.number_, NUMBER_SIZE);
		minute_ = subscriber.minute_;

		return *this;
	}

	// деструктор 
	~Subscriber()
	{
		delete[]owner_;
		delete[]number_;
	}

#pragma endregion

#pragma region Сеттеры и геттеры
	
	// сеттер owner_
	void setOwner(const char* owner) 
	{
		size_t size = strlen(owner);

		// если данные некорректны
		if (size < OWNER_MIN_SIZE and size > OWNER_MAX_SIZE)
			throw exception("Subscriber: Данные некорректны!");

		// копирование значения 
		strncpy(owner_, owner, OWNER_MAX_SIZE);
	}

	// геттер owner_
	const char* getOwner() { return owner_; }

	// сеттер number_
	void setNumber(const char* number)
	{
		size_t size = strlen(number);

		// если данные некорректны
		if (size != NUMBER_SIZE)
			throw exception("Subscriber: Данные некорректны!");

		// копирование значения 
		strncpy(number_, number, NUMBER_SIZE);
	}

	// геттер number_
	const char* getNumber() { return number_; }

	// сеттер minute_
	void setMinute(int minute)
	{
		// если данные некорректны
		if (minute < MINUTE_MIN and minute > MINUTE_MAX)
			throw exception("Subscriber: Данные некорректны!");

		// копирование значения 
		minute_ = minute;
	}

	// геттер minute_
	int getMinute() { return minute_; }

#pragma endregion

#pragma region Методы

	// шапка таблицы 
	static void showHead()
	{
		cout << "\t+————+——————————————————————+————————————+——————————————————+\n"
				"\t|    |       Владелец       |    Номер   | Время разговоров |\n"
				"\t|    |                      |            |     (минута)     |\n"
				"\t+————+——————————————————————+————————————+——————————————————+\n";
	}

	// вывод элемента для таблицы в цвете + сумма к оплате
	void showElem(int i = 1, short cl = WHITE_ON_BLACK)
	{
		cout << right << "\t| " << setw(2) << i
			<< left << " | " << setw(OWNER_MAX_SIZE - 20)
			<< color(YELLOW_ON_BLACK) << owner_
			<< color(cl) << " | "
			<< setw(NUMBER_SIZE)
			<< color(YELLOW_ON_BLACK) << number_
			<< color(cl) << " | "
			<< color(GREEN_ON_BLACK) << right << setw(16) << minute_
			<< color(cl) << " |\n";
	}

	// вывод линии таблицы
	static void showLine()
	{
		cout << "\t+————+——————————————————————+————————————+——————————————————+\n";
	}

	// вывод если нет данных
	static void showEmpty(short cl = WHITE_ON_BLACK)
	{
		cout << color(RED_ON_BLACK) << "\t|                        НЕТ ДАННЫХ                    |\n" << color(cl);

		showLine();
	}

	// перегрззка операции вывода 
	friend ostream& operator<<(ostream& os, const Subscriber& subscriber)
	{
		os << "ФИО: " << subscriber.owner_
			<< "\nНомер: " << subscriber.number_
			<< "\nВремя разговоров: " << subscriber.minute_ << "\n";

		return os;
	}

	// вычисление суммы к оплате 
	float price(float rate) { return minute_ * rate; }

	// перегрузка операции больше по номеру телефона
	bool operator>(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) > 0; }

	// перегрузка операции больше или равно по номеру телефона
	bool operator>=(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) >= 0; }

	// перегрузка операции равно по номеру телефона
	bool operator==(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) == 0; }

	// перегрузка операции НЕравно по номеру телефона
	bool operator!=(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) != 0; }

	// перегрузка операции меньше или равно по номеру телефона
	bool operator<=(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) <= 0; }

	// перегрузка операции меньше по номеру телефона
	bool operator<(Subscriber& subscriber) { return strcmp(number_, subscriber.number_) < 0; }

#pragma endregion
};

