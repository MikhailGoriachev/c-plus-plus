#pragma once

#include "..\pch.h"
#include "..\Utils.h"
#include "Bill.h"

#include <vector>
#include <algorithm>
#include <numeric>

/*
	Данные о плательщике:
		- коллекция платежей (объекты класса Bill)
		- фамилия и инициалы плательщика
		- номер телефона
		- тариф за минуту разговора
		- скидка(в процентах)
		- дата платежа
		- сумма платежа
*/

// Класс Данные о плательщике 
class Payer
{
#pragma region Константы 

public:

	// минимальный размер поля namePayer
	static const int N_MIN_NAME_PAYER = 1;

	// максимальный размер поля namePayer
	static const int N_MAX_NAME_PAYER = 40;

	// размер поля phoneNumber_ 
	static const int N_PHONE_NUMBER = 10;

	// минимальное значение поля rate_
	static constexpr double V_MIN_RATE = 0.;

	// максимальное значение поля rate_
	static constexpr double V_MAX_RATE = 1000.;

	// минимальное значение поля discount_
	static constexpr double V_MIN_DISCOUNT = 0.;

	// максимальное значение поля discount_
	static constexpr double V_MAX_DISCOUNT = 100.;

	// минимальное значение DateTime
	static const DateTime V_MIN_DATE;

#pragma endregion

private:

	// фамилия и инициалы плательщика
	string namePayer_;			
	
	// номер телефона
	string phoneNumber_;		
	
	// тариф за минуту разговора
	double rate_;				
	
	// скидка(в процентах)
	double discount_;			

	// количество счетов - требуется для записи и считывания с бинарного файла 
	int countBills_;			

	// дата платежа
	DateTime datePay_;			

	// сумма платежа
	double sumPay_;				

	// коллекция платежей(объекты класса Bill)
	vector<Bill> bills_;

public:

#pragma region Конструкторы, деструктор и перегрузка операции присваивания 

	// конструктор по умолчанию 
	Payer() : countBills_(), sumPay_(), datePay_(){};

	// конструктор инициализирующий 
	Payer(string namePayer, string phoneNumber, double rate, double discount, DateTime datePay);

	// конструктор копирующий 
	Payer(const Payer& payer) = default;

	// деструктор 
	~Payer() = default;

	// перегрузка операции присваивания 
	Payer& operator=(const Payer& payer) = default;

#pragma endregion

#pragma region Сеттеры и геттеры 

	// сеттер namePayer_
	void setNamePayer(string namePayer);

	// геттер namePayer_
	const string& getNamePayer() const;
	
	// сеттер phoneNumber_ 
	void setPhoneNumber(string phoneNumber);

	// геттер phoneNumber_
	const string& getPhoneNumber() const;
	
	// сеттер rate_
	void setRate(double rate);

	// геттер rate_
	double getRate() const;
	
	// сеттер discount_
	void setDiscount(double discount);

	// геттер discount_
	double getDiscount() const;

	// сеттер datePay_ 
	void setDatePay(DateTime datePay);

	// геттер datePay_
	const DateTime& getDatePay();

	// геттер sumPay_
	double getSumPay();

	// сеттер bills_
	void setBills(vector<Bill> bills);

	// геттер bills_
	const vector<Bill>& getBills();

#pragma endregion 

#pragma region Методы 

	// добавление платежа 
	void addBill(Bill bill);

	// запись в бинарный файл 
	void write(fstream& fs);

	// чтение из бинарного файла 
	void read(fstream& fs);
	
	// время разговоров 
	time_t timeCall();

	// вывод заголовка таблицы 
	static void showHead();
	
	// вывод заголовка таблицы с выводом времени разгоров
	static void showHeadTime();

	// вывод разделителя 
	static void showLine();	

	// вывод разделителя с выводом времени разгоров
	static void showLineTime();

	// вывод элемента для таблицы
	void showPayer(int index);

	// вывод элемента для таблицы выводом времени разгоров
	void showPayerTime(int index);

	// вывод платежей 
	void showBills();

	// перегрузка операций сравнения
	bool operator<(const Payer& payer) const;
	bool operator<=(const Payer& payer) const;
	bool operator==(const Payer& payer) const;
	bool operator!=(const Payer& payer) const;
	bool operator>=(const Payer& payer) const;
	bool operator>(const Payer& payer) const;


#pragma endregion 

#pragma region Дружественные функции 

	// вывод в строку
	friend ostream& operator<<(ostream & os, const Payer& payer);

#pragma endregion

};
