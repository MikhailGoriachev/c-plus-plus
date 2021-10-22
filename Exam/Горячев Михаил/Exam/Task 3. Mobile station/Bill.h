#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include "DateTime.h"

// ����� Bill ������������ ����� ������� ������ �� ���������� ��������. ����� ������ ��������
// ����: ���� � ����� ������ ���������, ���� � ����� ��������� ���������.
// 
// ����� ��������� ����������� � �������, �������� ������, ��������� �� ������. ������ ����
// ���������� �����, ����������� ����� � ������ �� ��������.
// ��� ������������� ���� � ������� ����������� ����� DateTime � ������ � ����, �����, ���,
// ���, ������, �������. ���������� ������ ���������� �������� ����� ����� ��������� �������
// � ��������. ����������� �������� ��������� ���� �������� �������.


// ����� ������� ������ �� ���������� ��������
class Bill
{

#pragma region ���������

public:

	// ����������� �������� DateTime
	static const DateTime V_MIN_DATE;

#pragma endregion

private:

	// ���� � ����� ������ ���������
	DateTime startCall_;

	// ���� � ����� ��������� ���������
	DateTime endCall_;

public:

#pragma region ������������, ���������� � ���������� �������� ������������

	// ���������� �� ���������
	Bill() = default;

	// ����������� ����������������
	Bill(DateTime startCall, DateTime endCall);

	// ����������� ���������� 
	Bill(const Bill& bill) = default;

	// ����������
	~Bill() = default;

	// ���������� �������� ������������
	Bill& operator=(const Bill& bill) = default;

#pragma endregion

#pragma region ������� � �������

	// ������ ������� ������� 
	void setTime(DateTime startCall, DateTime endCall);

	// ������ startCall_
	DateTime& getStartCall();

	// ������ endCall_
	DateTime& getEndCall();

#pragma endregion

#pragma region ������

	// ���������� ����� � ������ �� ��������
	double pay(double rate, double discount);

	// ������ � �������� ����
	void write(fstream& fs);

	// ������ �� ��������� ����� 
	void read(fstream& fs);

	// ����� ��������� � �������
	time_t callTime();

	// ����� ����� �������
	static void showHead(double minutes);
	
	// ����� �������� �������
	void showElem(int index, double rate, double discount);

	// ����� �����������
	static void showLine();

	// ���������� �������� ���������
	bool operator<(const Bill& bill) const;
	bool operator<=(const Bill& bill) const;
	bool operator==(const Bill& bill) const;
	bool operator!=(const Bill& bill) const;
	bool operator>=(const Bill& bill) const;
	bool operator>(const Bill& bill) const;

#pragma endregion

#pragma region ������������� �������

	// ����� � ������
	friend ostream& operator<<(ostream& os, const Bill& bill);

#pragma endregion

};

