#pragma once

#include "..\pch.h"
#include "..\Utils.h"
#include "Bill.h"

#include <vector>
#include <algorithm>
#include <numeric>

/*
	������ � �����������:
		- ��������� �������� (������� ������ Bill)
		- ������� � �������� �����������
		- ����� ��������
		- ����� �� ������ ���������
		- ������(� ���������)
		- ���� �������
		- ����� �������
*/

// ����� ������ � ����������� 
class Payer
{
#pragma region ��������� 

public:

	// ����������� ������ ���� namePayer
	static const int N_MIN_NAME_PAYER = 1;

	// ������������ ������ ���� namePayer
	static const int N_MAX_NAME_PAYER = 40;

	// ������ ���� phoneNumber_ 
	static const int N_PHONE_NUMBER = 10;

	// ����������� �������� ���� rate_
	static constexpr double V_MIN_RATE = 0.;

	// ������������ �������� ���� rate_
	static constexpr double V_MAX_RATE = 1000.;

	// ����������� �������� ���� discount_
	static constexpr double V_MIN_DISCOUNT = 0.;

	// ������������ �������� ���� discount_
	static constexpr double V_MAX_DISCOUNT = 100.;

	// ����������� �������� DateTime
	static const DateTime V_MIN_DATE;

#pragma endregion

private:

	// ������� � �������� �����������
	string namePayer_;			
	
	// ����� ��������
	string phoneNumber_;		
	
	// ����� �� ������ ���������
	double rate_;				
	
	// ������(� ���������)
	double discount_;			

	// ���������� ������ - ��������� ��� ������ � ���������� � ��������� ����� 
	int countBills_;			

	// ���� �������
	DateTime datePay_;			

	// ����� �������
	double sumPay_;				

	// ��������� ��������(������� ������ Bill)
	vector<Bill> bills_;

public:

#pragma region ������������, ���������� � ���������� �������� ������������ 

	// ����������� �� ��������� 
	Payer() : countBills_(), sumPay_(), datePay_(){};

	// ����������� ���������������� 
	Payer(string namePayer, string phoneNumber, double rate, double discount, DateTime datePay);

	// ����������� ���������� 
	Payer(const Payer& payer) = default;

	// ���������� 
	~Payer() = default;

	// ���������� �������� ������������ 
	Payer& operator=(const Payer& payer) = default;

#pragma endregion

#pragma region ������� � ������� 

	// ������ namePayer_
	void setNamePayer(string namePayer);

	// ������ namePayer_
	const string& getNamePayer() const;
	
	// ������ phoneNumber_ 
	void setPhoneNumber(string phoneNumber);

	// ������ phoneNumber_
	const string& getPhoneNumber() const;
	
	// ������ rate_
	void setRate(double rate);

	// ������ rate_
	double getRate() const;
	
	// ������ discount_
	void setDiscount(double discount);

	// ������ discount_
	double getDiscount() const;

	// ������ datePay_ 
	void setDatePay(DateTime datePay);

	// ������ datePay_
	const DateTime& getDatePay();

	// ������ sumPay_
	double getSumPay();

	// ������ bills_
	void setBills(vector<Bill> bills);

	// ������ bills_
	const vector<Bill>& getBills();

#pragma endregion 

#pragma region ������ 

	// ���������� ������� 
	void addBill(Bill bill);

	// ������ � �������� ���� 
	void write(fstream& fs);

	// ������ �� ��������� ����� 
	void read(fstream& fs);
	
	// ����� ���������� 
	time_t timeCall();

	// ����� ��������� ������� 
	static void showHead();
	
	// ����� ��������� ������� � ������� ������� ��������
	static void showHeadTime();

	// ����� ����������� 
	static void showLine();	

	// ����� ����������� � ������� ������� ��������
	static void showLineTime();

	// ����� �������� ��� �������
	void showPayer(int index);

	// ����� �������� ��� ������� ������� ������� ��������
	void showPayerTime(int index);

	// ����� �������� 
	void showBills();

	// ���������� �������� ���������
	bool operator<(const Payer& payer) const;
	bool operator<=(const Payer& payer) const;
	bool operator==(const Payer& payer) const;
	bool operator!=(const Payer& payer) const;
	bool operator>=(const Payer& payer) const;
	bool operator>(const Payer& payer) const;


#pragma endregion 

#pragma region ������������� ������� 

	// ����� � ������
	friend ostream& operator<<(ostream & os, const Payer& payer);

#pragma endregion

};
