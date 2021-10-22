#pragma once
/*
 * ������������ ����� Plane � ������ ��� ��������:
 *     � ������������� � ���� �������� (��������: ��-76, Boeing 747, �)
 *     � ���������� ������������ ���� (�� 0 �� 1000)
 *     � ������� ���������� ���������� (�� 0 �� ���������� ������������ ����)
 *     � ������� �������� �� ��� ������ (������������ �����,
 *       �� 0.1 �� 20'000 ��/�)
 *     � ��������� ������ �������� (�� 1'000 �� 20'000 ��)
 *     � ��������������� ����� �������� (��������: UR-DAD, UR-CCF, �).
 * � ������ Plane �����������:
 *     � ������������: �� ���������, � �����������, ����������, ����������
 *     � ������� � ������� ��� ���� ����� ������, � �������� �����������
 *       ���������� ��� ����������� ������������� ��������
 *     � �����, ����������� ������ �������� �� ��� ������ �� ���� ������������
 *       ����� (�������� ������ �������� �� ��� �� ���������� ������������
 *       ����)
 *     � ����������� �������� ���������: < <= == != >= > ��� ��������� ����
 *       �������� �� ��������� ������ ��������
 *     � ����������� �������� ������ <<     
 */
#include "pch.h"

class Plane
{
public:
	// ����� ���� ���� �������� � �������� ��������-���������
	static const int N_AIRCRAFT_TYPE = 55, N_REG_NUMBER = 21;

	// ��������� ��������
	// ������ �������� - static � �����, �������� �� int ������ ������������ � ���������� ������
	static const double MIN_CONSAMPTION, MAX_CONSAMPTION;

	// �������� ��������� ������ ��������
	static const int MIN_RANGE = 1'000, MAX_RANGE = 20'000;

private:
	
	// ������������� � ��� �������� (��������: ��-76, Boeing 747, ��-124-100�2, Airbus 321 Neo-LX, �)
	char* aircraftType_;

	// ���������� ������������ ���� (�� 0 �� 1000)
	int seates_;

	// ������� ���������� ���������� (�� 0 �� ���������� ������������ ����)
	int passengers_;

	// ������ �������� �� ��� ������ (������������ �����, �� 0.1 �� 8600 ��/�)
	double consumption_;

	// ��������� ������ �������� (�� 1000 �� 20000 ��)
	int range_;

	// ��������������� ����� �������� (��������: UR-DAD, UR-CCF, �)
	char* regNumber_;

	// ����� ������ ������ � ��������� ������� � ��� �����
	char* buf_;
	const int N_LEN_BUF = 151;
	
public:
	// ����������� �� ���������
	Plane() :aircraftType_(new char[N_AIRCRAFT_TYPE] {0}), seates_(0), passengers_(0),
		consumption_(0.1), range_(MIN_RANGE), regNumber_(new char[N_REG_NUMBER] {0})
	{
		strcpy(aircraftType_, "��-2");
		strcpy(regNumber_, "UR-DAD");

		// ��������� ������ ��� ��������� �����
		buf_ = new char[N_LEN_BUF] {0};
	} // Plane

	// ������������ �����������
	explicit Plane(const char* aircraftType, int seates, int passengers, double consumption, 
		int range, const char* regNumber)
	{
		aircraftType_ = new char[N_AIRCRAFT_TYPE] {0};
		regNumber_ = new char[N_REG_NUMBER] {0};

		setAircraftType(aircraftType);
		setSeates(seates);
		setPassengers(passengers);
		setConsumption(consumption);
		setRange(range);
		setRegNumber(regNumber);

		// ��������� ������ ��� ��������� �����
		buf_ = new char[N_LEN_BUF] {0};
	} // Plane

	// ����������� �����������
	Plane(const Plane& plane)
	{
		aircraftType_ = new char[N_AIRCRAFT_TYPE] {0};
		regNumber_ = new char[N_REG_NUMBER] {0};

		strcpy(aircraftType_, plane.aircraftType_);
		seates_ = plane.seates_;
		passengers_ = plane.passengers_;
		consumption_ = plane.consumption_;
		range_ = plane.range_;
		strcpy(regNumber_, plane.regNumber_);

		// ��������� ������ ��� ��������� �����
		buf_ = new char[N_LEN_BUF] {0};
	} // Plane

	// ����������
	~Plane()
	{
		// ������������ ������, ���������� ��� ������������ ����
		delete[] aircraftType_;
		delete[] regNumber_;
		delete[] buf_;
	} // ~Plane

	// ������� � �������
	// ������������� � ��� ��������
	const char* getAircraftType() const { return aircraftType_; }
	void setAircraftType(const char* value)
	{
		if (strlen(value) == 0)
			throw exception("    Plane: �� ����� ������������� � ��� ��������");
		strncpy(aircraftType_, value, N_AIRCRAFT_TYPE);
	} // setAircraftType

	// ���������� ������������ ���� (�� 0 �� 1000)
	int getSeates() const { return seates_; }
	void setSeates(int value)
	{
		if (value < 0 || value > 1000)
			throw exception("    Plane: ������������ ���������� ������������ ����");

		seates_ = value;
	} // setSeates

	// ������� ���������� ���������� (�� 0 �� ���������� ������������ ����)
	int getPassengers() const { return passengers_;  }
	void setPassengers(int value)
	{
		if (value < 0 || value > seates_)
			throw exception("    Plane: ������������ ���������� ����������");

		passengers_ = value;
	} // setPassengers

	// ������ �������� �� ��� ������(������������ �����, �� 0.1 �� 20 000 ��/�)
	double getConsumption() const { return consumption_;  }
	void setConsumption(double value)
	{
		if (value < MIN_CONSAMPTION || value > MAX_CONSAMPTION)
			throw exception("    Plane: ������������ ������� ��������");

		consumption_ = value;
	} // setConsumption

	// ��������� ������ �������� (�� 1'000 �� 20'000)
	int getRange() const { return range_; }
	void setRange(int value)
	{
		if (value < MIN_RANGE || value > MAX_RANGE)
			throw exception("    Plane: ������������ ��������� ������");

		range_ = value;
	} // setRange

	// ��������������� ����� �������� (��������: UR-DAD, UR-CCF, �)
	const char* getRegNumber() const { return regNumber_; }
	void setRegNumber(const char* value)
	{
		if (strlen(value) == 0)
			throw exception("    Plane: �� ����� ��������������� �����");
		strncpy(regNumber_, value, N_REG_NUMBER);
	} // setRegNumber

	// �����, ����������� ������ �������� �� ��� ������ �� ���� ������������
	// ����� (�������� ������ �������� �� ��� �� ���������� ������������ ����)
	// ���������� -1 ��� ��������� ��� ������������ ����
	double consumptionPerSeat() const
	{
		return seates_ == 0? -1: consumption_ / seates_;
	} // consumptionPerSeat

	// ����� ������ ������� � ��������� �����
	const char *toString() const
	{
		// ������������ ���������� ������������� ��������
		// ������� �� ������������ �����
		double value = consumptionPerSeat();
		ostringstream oss;
		if (value > 0)
			oss << fixed << setprecision(2) << setw(15) << value;
		else
			oss << "�� ����������";

		// ������������ ���������� ������������� ������ �������
		sprintf(buf_, " | %-19s | %11d | %10d | %15.2lf | %15s | %10d | %-16s |", 
			aircraftType_, seates_, passengers_, consumption_, 
			oss.str().c_str(), 
			range_, regNumber_);
		return buf_;
	} // toString
	
	// ���������������� �������� -------------------------------------------------
	// ������������
	Plane &operator=(const Plane &plane)
	{
		// ������ �� ����������������
		if (&plane == this) return *this;

		// �.�. ��������� ���� ������������� ����� ������������ ������
		// � ��������� ������ ����� ������ �� ���������
		memcpy(aircraftType_, plane.aircraftType_, N_AIRCRAFT_TYPE);
		memcpy(regNumber_, plane.regNumber_, N_REG_NUMBER);

		seates_ = plane.seates_;
		passengers_ = plane.passengers_;
		consumption_ = plane.consumption_;
		range_ = plane.range_;
		
		return *this;
	} // operator=

	
	// �������� ��������� ��� ��������� ���� �������� �� ���������
	// ������ ��������
	bool operator<(const Plane& p)  const { return range_  < p.range_; }
	bool operator<=(const Plane& p) const { return range_ <= p.range_; }
	bool operator==(const Plane& p) const { return range_ == p.range_; }
	bool operator!=(const Plane& p) const { return !(*this == p); }
	bool operator>=(const Plane& p) const { return !(*this < p); }   //  !< 
	bool operator>(const Plane& p)  const { return !(*this <= p); }  //  !<=

	// ���������� �������� ������ ������������� ��������, ������� ������ �������
	friend ostream& operator<<(ostream& os, const Plane& plane);

	// ����� ����� ������� � ������
	static ostream& header(ostream& os);

	// ����� ������� ������� � ������
	static ostream& footer(ostream& os);
};

