#include "Bus.h"

// ���������� �������� ������ 
ostream& operator<<(ostream& os, const Bus& bus)
{
	os << bus.number_
		<< "\n" << bus.name_
		<< "\n" << bus.routApp_
		<< "\n" << bus.routAct_
		<< "\n";

	return os;
}

// ���������� �������� ����� 
istream& operator>>(istream& is, Bus& bus)
{
 	getline(is, bus.number_);
	getline(is, bus.name_);
	getline(is, bus.routApp_);
	getline(is, bus.routAct_);

	return is;
}

// ������ � �������� ����
void Bus::write(fstream& file)
{
	// ����� ��� ������
	char* buf = new char[1024]{ 0 };

	// �����
	strncpy(buf, number_.c_str(), N_NUMBER);
	file.write(buf, N_NUMBER);

	// ��� 
	memset(buf, 0, N_NAME);
	strncpy(buf, name_.c_str(), N_NAME);
	file.write(buf, N_NAME);

	// ������������� ������� 
	memset(buf, 0, N_ROUT);
	strncpy(buf, routApp_.c_str(), N_ROUT);
	file.write(buf, N_ROUT);

	// ��� 
	memset(buf, 0, N_ROUT);
	strncpy(buf, routAct_.c_str(), N_ROUT);
	file.write(buf, N_ROUT);

	delete[]buf;
}

// ������ �� ��������� �����
void Bus::read(fstream& file)
{
	// ����� ��� ������
	char* buf = new char[1024]{ 0 };

	// �����
	file.read(buf, N_NUMBER);
	number_ = buf;

	// ��� 
	memset(buf, 0, N_NAME);
	file.read(buf, N_NAME);
	name_ = buf;

	// ������������� ������� 
	memset(buf, 0, N_ROUT);
	file.read(buf, N_ROUT);
	routApp_ = buf;

	// ��� 
	memset(buf, 0, N_ROUT);
	file.read(buf, N_ROUT);
	routAct_ = buf;

	delete[]buf;

}

// ������ � ��������� ���� �� ���������
void Bus::writeText(ostream_iterator<Bus>& it)
{
	*it = *this;
}

// ������ �� ��������� ���� �� ���������
void Bus::readText(istream_iterator<Bus>& it)
{
	*this = *it;
}

// ���������� �������� ����� 
