#pragma once
#include "pch.h"
#include "Object.h"
#include "Date.h"
#include "Utils.h"

// ����� ������
class Order: public Object
{
protected:
	string destination_;  // ����� ����������
	string flight_;       // ����� �����
	string fullName_;    // ������� � ��������
	Date   date_;         // �������� ���� ������

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

	// ���������� �� �������� ������
	string toString() override;

	friend ostream &operator<<(ostream &os, Order &order);
	friend istream &operator>>(istream &is, Order &order);
};


