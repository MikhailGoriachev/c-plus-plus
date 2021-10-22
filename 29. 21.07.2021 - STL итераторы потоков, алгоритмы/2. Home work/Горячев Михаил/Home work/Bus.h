#pragma once

#include "pch.h"

// �������� � ������ �������� �������� : 
// ��������������� ����� ��������
// ������� � �������� ��������
// ����������� ����� ��������
// ����������� ����� ��������

class Bus
{
public:

	// ������ ���� ��������������� ����� ��������
	static const int N_NUMBER = 6;

	// ������ ���� ������� � ��������� 
	static const int N_NAME = 20;

	// ������ ������ �������� 
	static const int N_ROUT = 5;

private:

	// ��������������� ����� ��������
	string number_;

	// ������� � �������� ��������
	string name_;
	
	// ����������� ����� ��������
	string routApp_;
	
	// ����������� ����� ��������
	string routAct_;

public:

#pragma region ������������, ����������, ���������� �������� ������������

	// ����������� �� ���������
	Bus() = default;

	// ����������� ���������������� 
	explicit Bus(string number, string name, string routApp, string routAct)
	{
		setNumber(number);
		setName(name);
		setRoutApp(routApp);
		setRoutAct(routAct);
	}

	// ���������� ����������� 
	Bus(const Bus& bus) = default;

	// ���������� 
	~Bus() = default;
	
	// ���������� �������� ������������
	Bus& operator=(const Bus& bus) = default;

#pragma endregion

#pragma region ������

	// ������ � �������� ����
	void write(fstream& file);
	
	// ������ �� ��������� �����
	void read(fstream& file);

	// ������ � ��������� ����
	void writeText(ostream_iterator<Bus>& it);
	
	// ������ �� ��������� ����
	void readText(istream_iterator<Bus>& it);

	// ������ ������� � ������
	static constexpr int SIZE_RECORD = N_NAME + N_NUMBER + (N_ROUT * 2);

#pragma endregion 

#pragma region ������� � �������

	// ������ number_
	void setNumber(string number)
	{
		// ���� ������ ������ ������ ����������� 
		if (number.size() > N_NUMBER)
			throw exception("Bus: ������������ ������!");

		number_ = number;
	}

	// ������ 
	string getNumber() { return number_; }

	// ������ name_
	void setName(string name)
	{
		// ���� ������ ������ ������ ����������� 
		if (name.size() > N_NAME)
			throw exception("Bus: ������������ ������!");

		name_ = name;
	}

	// ������ name_
	string getName() { return name_; }

	// ������ routApp_
	void setRoutApp(string routApp)
	{
		// ���� ������ ������ ������ ����������� 
		if (routApp.size() > N_ROUT)
			throw exception("Bus: ������������ ������!");

		routApp_ = routApp;

	}

	// ������ routApp_
	string getRoutApp() { return routApp_; }
	
	// ������ routAct_
	void setRoutAct(string routAct)
	{
		// ���� ������ ������ ������ ����������� 
		if (routAct.size() > N_ROUT)
			throw exception("Bus: ������������ ������!");

		routAct_ = routAct;
	}

	// ������ 
	string getRoutAct() { return routAct_; }

#pragma endregion 

#pragma region ������������� �������

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const Bus& bus);

	// ���������� �������� ����� 
	friend istream& operator>>(istream& os, Bus& bus);

#pragma endregion 

};

