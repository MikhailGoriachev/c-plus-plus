#pragma once
#include "pch.h"
#include "Object.h"
#include "Date.h"
#include "Utils.h"

// заказ билета
class Order: public Object
{
protected:
	string destination_;  // пункт назначения
	string flight_;       // номер рейса
	string fullName_;    // фамилия и инициалы
	Date   date_;         // желаемая дата полета

public:
	Order() = default;
	Order(const string destination, const string flight, const string fullName, const Date &date) 
	{
		setDestination(destination);
		setFlight(flight);
		setFullName(fullName);
		setDate(date);
	} // Order


	string getFlight() const { return flight_; }
	Date getDate() const { return date_; }
	
	string setDestination(const string &destination);
	string setFlight(const string &flight);
	string setFullName(const string &surnameNP);
	Date   setDate(const Date &date);

	// реализация из базового класса
	string toString() override;

	friend ostream &operator<<(ostream &os, Order &order);
	friend istream &operator>>(istream &is, Order &order);
};


