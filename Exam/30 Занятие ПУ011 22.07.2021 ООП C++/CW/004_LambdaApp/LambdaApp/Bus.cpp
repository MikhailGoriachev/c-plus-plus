#include "pch.h"
#include "Bus.h"

// ����� ����� �������
ostream& Bus::header(ostream& os)
{
	os  << "    +�����+�����������+����������������������+�������������+�������������+\n"
		<< "    |  N  | ���. ���. |     ������� �.�.     | ����������� | ����������� |\n"
		<< "    | �/� | ��������  |       ��������       |   �������   |   �������   |\n"
		<< "    +�����+�����������+����������������������+�������������+�������������+\n";
	return os;
} // Bus::header

// ����� ������� �������
ostream& Bus::footer(ostream& os)
{
	os << "    +�����+�����������+����������������������+�������������+�������������+\n";
	return os;
} // Bus::footer

// ����� ������ �������
string Bus::toTableRow(int row) const
{
	ostringstream oss;
	oss << " | " << setw(3) << row
	    << " | " << left << setw(9) << regNum_
		<< " | " << setw(20) << left << fullName_ << right
		<< " | " << setw(8) << orderedRoute_ << "   "
		<< " | " << setw(8) << actualRoute_ << "    |";
	return oss.str();
}

// ������������� �������� ������ ����� �������������� ���
// ������ ������ � ��������������� ����� ������
ostream& operator<<(ostream& os, const Bus& bus)
{
	os << bus.regNum_       << endl
	   << bus.fullName_     << endl
	   << bus.orderedRoute_ << endl
	   << bus.actualRoute_  << endl;
	return os;
} // operator<<

// ������������� �������� ����� ����� �������������� ���
// ����� ������ �� ���������������� ������ �����
istream& operator>>(istream& is, Bus& bus)
{
	getline(is, bus.regNum_);
	getline(is, bus.fullName_);
	getline(is, bus.orderedRoute_);
	getline(is, bus.actualRoute_);
	return is;
} // operator>>


// ������ �� ��������� �����
void Bus::read(fstream& fs)
{
	// ��������� ������ ��� ����� ������
	char* buf = new char[max(N_REG_NUMBER, max(N_FULL_NAME, N_ROUTE))];
	
	fs.read(buf, N_REG_NUMBER);
	regNum_ = buf;
	
	fs.read(buf, N_FULL_NAME);
	fullName_ = buf;
	
	fs.read(buf, N_ROUTE);
	orderedRoute_ = buf;
	
	fs.read(buf, N_ROUTE);
	actualRoute_ = buf;
	
	delete[] buf;
} // Bus::read


// ������ � �������� ����
void Bus::write(fstream& fs)
{
	// ����� ��� ������ �����
	char* buf = new char[max(N_REG_NUMBER, max(N_FULL_NAME, N_ROUTE))] {0};

	strncpy(buf, regNum_.c_str(), N_REG_NUMBER-1);
	fs.write(buf, N_REG_NUMBER);

	// ������ ����� ��� ������������ ������ � ����
	memset(buf, 0, N_FULL_NAME);
	strncpy(buf, fullName_.c_str(), N_FULL_NAME - 1);
	fs.write(buf, N_FULL_NAME);

	memset(buf, 0, N_ROUTE);
	strncpy(buf, orderedRoute_.c_str(), N_ROUTE - 1);
	fs.write(buf, N_ROUTE);

	memset(buf, 0, N_ROUTE);
	strncpy(buf, actualRoute_.c_str(), N_ROUTE - 1);
	fs.write(buf, N_ROUTE);
	
	delete[] buf;
} //  Bus::write
