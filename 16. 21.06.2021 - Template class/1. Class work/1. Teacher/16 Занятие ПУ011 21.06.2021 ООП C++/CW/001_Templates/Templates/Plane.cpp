#include "pch.h"
#include "Plane.h"

// ������������� static-��������
const double Plane::MIN_CONSAMPTION = 0.1;
const double Plane::MAX_CONSAMPTION = 20'000.;


// ���������� �������� ������ ��� ������� ������ Plane - �����
// ����� ������ � �������� ������ ������ � ������� ������ �������
ostream& operator<<(ostream& os, const Plane& plane)
{
	// ������������ ���������� ������������� ��������
	// ������� �� ������������ �����
	double value = plane.consumptionPerSeat();
	ostringstream oss;
	if (value > 0)
		oss << fixed << setprecision(2) << setw(15) << value;
	else 
		oss << "  �� ����������";
	//if
	
	os  << " | " << setw(19) << left << plane.aircraftType_ << right
		<< " | " << setw(11) << plane.seates_
		<< " | " << setw(10) << plane.passengers_
		<< " | " << setw(15) << plane.consumption_
		<< " | " << setw(15) << oss.str()
		<< " | " << setw(10) << plane.range_
		<< " | " << setw(15) << left << plane.regNumber_ << right << " |";
	   
	return os;
} // operator<<


// ����� ��� ������ ����� � ������� �������
static char buf[511];

// ����������� - ������������� ���������� ���� ���������
static const char* line = "+�����+���������������������+�������������+������������+�����������������+�����������������+������������+�����������������+";


// ����� ����� ������� - ����������� �����
ostream & Plane::header(ostream &os)
{
	sprintf(buf,
	"    %s\n"
	"    |  N  | ��� � ������������� | ���������-  | ���������� | ������ �������� | ������ �������� | ���������  | ��������������� |\n"
	"    | �/� |       ��������      | ����������� | ���������� |      ��/���     |  ��/� �� �����  | ������, �� |      �����      |\n"
	"    %s", line, line);

	return os << buf;
} // Plane::showHead


// ����� ������� ������� - ����������� �����
ostream& Plane::footer(ostream& os)
{
	// ������������ ������� ������� � ���������
	sprintf(buf, "    %s\n", line);
	return os << buf;
} // Plane::showFoot