#pragma once
#include "pch.h"

/*
 * �������� � ������ �������� ��������: ��������������� ����� ��������, �������
 * � �������� ��������, ����������� ����� ��������, ����������� ����� ��������.
 * ���������� � ����� � ������ ������� � ������� �0�, � ������ ������ ��������
 * ������ ��� �����, ��� � �����, �������� � �42�, �42�, �32�.
 */
class Bus
{
	string regNum_;       // ��������������� ����� ��������
	string fullName_;     // ������� � �������� ��������
	string orderedRoute_; // ����������� ����� ��������
	string actualRoute_;  // ����������� ����� ��������

public:
	// ������� ����� � �������� �����
	static constexpr int N_REG_NUMBER = 10;
	static constexpr int N_FULL_NAME = 71;
	static constexpr int N_ROUTE = 8;    // ����� ���������� ��� ����� ����� ��������� 
	static constexpr int RECORD_SIZE = N_REG_NUMBER + N_FULL_NAME + (N_ROUTE << 1);     
	
	Bus():Bus("�111��", "��������� �.�.", "42", "0") {}

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

	// ���������
	const string& getRegNum() const { return regNum_;  }
	void setRegNum(const string& value) { regNum_ = value; }
	
	const string& getFullName() const { return fullName_;  }
	void setFullName(const string& value) { fullName_ = value; }
	
	const string& getOrderedRoute() const { return orderedRoute_;  }
	void setOrderedRoute(const string& value) { orderedRoute_ = value; }
	
	const string& getActualRoute() const { return actualRoute_;  }
	void setActualRoute(const string& value) { actualRoute_ = value; }

	// ����� ������ �������
	string toTableRow(int row) const;

	// ������������� ��������
	Bus& operator=(const Bus& value) = default;

	// ������������ ��� ������ � ���������������� �������� �����/������
	friend ostream& operator<<(ostream& os, const Bus& bus);
	friend istream& operator>>(istream& is, Bus& bus);

	// ������ � �������� �������
	void read(fstream& fs);
	void write(fstream& fs);

	// ����� ����� �������
	static ostream& header(ostream& os);

	// ����� ������� �������
	static ostream& footer(ostream& os);
}; 

