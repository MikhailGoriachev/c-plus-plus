#pragma once
#include "pch.h"

/*
 * Сведения о каждом автобусе содержат: регистрационный номер автобуса, фамилию
 * и инициалы водителя, назначенный номер маршрута, фактический номер маршрута.
 * Нахождение в парке – особый маршрут с номером «0», в состав номера маршрута
 * входят как цифры, так и буквы, например – «42», «42а», «32в».
 */
class Bus
{
	string regNum_;       // регистрационный номер автобуса
	string fullName_;     // фамилию и инициалы водителя
	string orderedRoute_; // назначенный номер маршрута
	string actualRoute_;  // фактический номер маршрута

public:
	// размеры полей в бинарном файле
	static constexpr int N_REG_NUMBER = 10;
	static constexpr int N_FULL_NAME = 71;
	static constexpr int N_ROUTE = 8;    // длина одинаковая для обоих полей маршрутов 
	static constexpr int RECORD_SIZE = N_REG_NUMBER + N_FULL_NAME + (N_ROUTE << 1);     
	
	Bus():Bus("А111АА", "Терешкова В.С.", "42", "0") {}

	Bus(const string &regNum, const string& fullName, const string& orderedRoute, 
		const string& actualRoute)
	{
		setRegNum(regNum);
		setFullName(fullName);
		setOrderedRoute(orderedRoute);
		setActualRoute(actualRoute);
	} // Bus

	Bus(const Bus& value) = default;
	~Bus() = default;

	// аксеесоры
	const string& getRegNum() const { return regNum_;  }
	void setRegNum(const string& value) { regNum_ = value; }
	
	const string& getFullName() const { return fullName_;  }
	void setFullName(const string& value) { fullName_ = value; }
	
	const string& getOrderedRoute() const { return orderedRoute_;  }
	void setOrderedRoute(const string& value) { orderedRoute_ = value; }
	
	const string& getActualRoute() const { return actualRoute_;  }
	void setActualRoute(const string& value) { actualRoute_ = value; }

	// вывод строки таблицы
	string toTableRow(int row) const;

	// перегруженные операции
	Bus& operator=(const Bus& value) = default;

	// используются для работы с форматированными потоками ввода/вывода
	friend ostream& operator<<(ostream& os, const Bus& bus);
	friend istream& operator>>(istream& is, Bus& bus);

	// работа с бинарным потоком
	void read(fstream& fs);
	void write(fstream& fs);

	// вывод шапки таблицы
	static ostream& header(ostream& os);

	// вывод подвала таблицы
	static ostream& footer(ostream& os);
}; 

