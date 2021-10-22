#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include "DateTime.h"

// Класс Bill представляет собой разовый платеж за телефонный разговор. Класс должен включать
// поля: дата и время начала разговора, дата и время окончания разговора.
// 
// Время разговора вычисляется в минутах, неполная минута, считается за полную. Должен быть
// реализован метод, вычисляющий сумму к оплате за разговор.
// Для представления даты и времени используйте класс DateTime с полями – день, месяц, год,
// час, минута, секунда. Реализуйте методы вычисления разности между двумя моментами времени
// в секундах. Перегрузите операции сравнения двух моментов времени.


// Класс Разовый платеж за телефонный разговор
class Bill
{

#pragma region Константы

public:

	// минимальное значение DateTime
	static const DateTime V_MIN_DATE;

#pragma endregion

private:

	// дата и время начала разговора
	DateTime startCall_;

	// дата и время окончания разговора
	DateTime endCall_;

public:

#pragma region Конструкторы, деструктор и перегрузка операции присваивания

	// консруктор по умолчанию
	Bill() = default;

	// конструктор инициализирующий
	Bill(DateTime startCall, DateTime endCall);

	// конструктор копирующий 
	Bill(const Bill& bill) = default;

	// деструктор
	~Bill() = default;

	// перегрузка операции присваивания
	Bill& operator=(const Bill& bill) = default;

#pragma endregion

#pragma region Сеттеры и геттеры

	// сеттер времени платежа 
	void setTime(DateTime startCall, DateTime endCall);

	// геттер startCall_
	DateTime& getStartCall();

	// геттер endCall_
	DateTime& getEndCall();

#pragma endregion

#pragma region Методы

	// вычисление суммы к оплате за разговор
	double pay(double rate, double discount);

	// запись в бинарный файл
	void write(fstream& fs);

	// чтение из бинарного файла 
	void read(fstream& fs);

	// время разговора в минутах
	time_t callTime();

	// вывод шапки таблицы
	static void showHead(double minutes);
	
	// вывод элемента таблицы
	void showElem(int index, double rate, double discount);

	// вывод разделителя
	static void showLine();

	// перегрузка операций сравнения
	bool operator<(const Bill& bill) const;
	bool operator<=(const Bill& bill) const;
	bool operator==(const Bill& bill) const;
	bool operator!=(const Bill& bill) const;
	bool operator>=(const Bill& bill) const;
	bool operator>(const Bill& bill) const;

#pragma endregion

#pragma region Дружественные фукнции

	// вывод в строку
	friend ostream& operator<<(ostream& os, const Bill& bill);

#pragma endregion

};

