#include "pch.h"
#include "Order.h"


// Установка пункта назначения
string Order::setDestination(const string &destination)
{
	if (destination.empty())
		throw exception();
	destination_ = destination;

	return destination_;
} // Order::setDestination

// Установка номера рейса
string Order::setFlight(const string &flight)
{
	if (flight.empty())
		throw exception();
	flight_ = flight;

	return flight_;	
} // Order::setFlight

// Установка фамилии и инициалов заказчиков
string Order::setFullName(const string &fullName)
{
	if (fullName.empty())
		throw exception("Имя Заказчика не может быть пустой строкой");
	fullName_ = fullName;

	return fullName_;		
} // Order::setFullName

// Установка даты желаемого полета
Date Order::setDate(const Date &date)
{
	date_ = date;
	return date_;
} // Order::setDate

// формирование строкового представления полей данных
string Order::toString()
{
	ostringstream oss;

	oss << "destination: " << left << setw(15) << destination_
	    << "; flight: " << setw(12) << flight_ << right 
	    << "; date: " << date_
	    << "; fullName: " << fullName_;

	return oss.str();
} // toString

// --------------------------------------------------------
#pragma region Перегруженные операции

// оператор вывода использует toString
ostream &operator<<(ostream &os, Order &order)
{
	os << order.toString();
	return os;
} // operator<<

// оператор ввода
istream &operator>>(istream &is, Order &order)
{
	is.ignore(is.rdbuf()->in_avail(), '\n');
	getline(is, order.destination_);
	getline(is, order.flight_);
	getline(is, order.fullName_);
	is >> order.date_;

	return is;
} // operator>>

#pragma endregion
