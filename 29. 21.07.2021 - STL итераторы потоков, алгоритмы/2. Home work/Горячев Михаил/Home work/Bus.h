#pragma once

#include "pch.h"

// Сведения о каждом автобусе содержат : 
// регистрационный номер автобуса
// фамилию и инициалы водителя
// назначенный номер маршрута
// фактический номер маршрута

class Bus
{
public:

	// размер поля регистрационный номер автобуса
	static const int N_NUMBER = 6;

	// размер поля фамилии и инициалов 
	static const int N_NAME = 20;

	// размер номера маршрута 
	static const int N_ROUT = 5;

private:

	// регистрационный номер автобуса
	string number_;

	// фамилия и инициалы водителя
	string name_;
	
	// назначенный номер маршрута
	string routApp_;
	
	// фактический номер маршрута
	string routAct_;

public:

#pragma region Конструкторы, деструктор, перегрузка операции присваивания

	// конструктор по умолчанию
	Bus() = default;

	// конструктор инициализирующий 
	explicit Bus(string number, string name, string routApp, string routAct)
	{
		setNumber(number);
		setName(name);
		setRoutApp(routApp);
		setRoutAct(routAct);
	}

	// копирующий конструктор 
	Bus(const Bus& bus) = default;

	// деструктор 
	~Bus() = default;
	
	// перегрузка операции присваивания
	Bus& operator=(const Bus& bus) = default;

#pragma endregion

#pragma region Методы

	// запись в бинарный файл
	void write(fstream& file);
	
	// чтение из бинарного файла
	void read(fstream& file);

	// запись в текстовый файл
	void writeText(ostream_iterator<Bus>& it);
	
	// чтение из текстовый файл
	void readText(istream_iterator<Bus>& it);

	// размер объекта в байтах
	static constexpr int SIZE_RECORD = N_NAME + N_NUMBER + (N_ROUT * 2);

#pragma endregion 

#pragma region Сеттеры и геттеры

	// сеттер number_
	void setNumber(string number)
	{
		// если размер строки больше допустимого 
		if (number.size() > N_NUMBER)
			throw exception("Bus: Некорректные данные!");

		number_ = number;
	}

	// геттер 
	string getNumber() { return number_; }

	// сеттер name_
	void setName(string name)
	{
		// если размер строки больше допустимого 
		if (name.size() > N_NAME)
			throw exception("Bus: Некорректные данные!");

		name_ = name;
	}

	// геттер name_
	string getName() { return name_; }

	// сеттер routApp_
	void setRoutApp(string routApp)
	{
		// если размер строки больше допустимого 
		if (routApp.size() > N_ROUT)
			throw exception("Bus: Некорректные данные!");

		routApp_ = routApp;

	}

	// геттер routApp_
	string getRoutApp() { return routApp_; }
	
	// сеттер routAct_
	void setRoutAct(string routAct)
	{
		// если размер строки больше допустимого 
		if (routAct.size() > N_ROUT)
			throw exception("Bus: Некорректные данные!");

		routAct_ = routAct;
	}

	// геттер 
	string getRoutAct() { return routAct_; }

#pragma endregion 

#pragma region Дружественные функции

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const Bus& bus);

	// перегрузка операции ввода 
	friend istream& operator>>(istream& os, Bus& bus);

#pragma endregion 

};

