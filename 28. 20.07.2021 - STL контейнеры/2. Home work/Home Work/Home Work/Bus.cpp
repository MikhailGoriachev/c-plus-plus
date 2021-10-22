#include "Bus.h"

// перегрузка операции вывода 
ostream& operator<<(ostream& os, const Bus& bus)
{
	os << "Регистрационный номер: " << bus.number_
		<< "\nФамилия и инициалы водителя" << bus.name_
		<< "\nНазначенный номер маршрута" << bus.routApp_
		<< "\nФактический номер маршрута" << bus.routAct_;

	return os;
}

// запись в бинарный файл
void Bus::write(fstream& file)
{
	// буфер для строки
	char* buf = new char[1024]{ 0 };

	// номер
	strncpy(buf, number_.c_str(), N_NUMBER);
	file.write(buf, N_NUMBER);

	// имя 
	memset(buf, 0, N_NAME);
	strncpy(buf, name_.c_str(), N_NAME);
	file.write(buf, N_NAME);

	// установленный маршрут 
	memset(buf, 0, N_ROUT);
	strncpy(buf, routApp_.c_str(), N_ROUT);
	file.write(buf, N_ROUT);

	// имя 
	memset(buf, 0, N_ROUT);
	strncpy(buf, routAct_.c_str(), N_ROUT);
	file.write(buf, N_ROUT);

	delete[]buf;
}

// чтение из бинарного файла
void Bus::read(fstream& file)
{
	// буфер для строки
	char* buf = new char[1024]{ 0 };

	// номер
	file.read(buf, N_NUMBER);
	number_ = buf;

	// имя 
	memset(buf, 0, N_NAME);
	file.read(buf, N_NAME);
	name_ = buf;

	// установленный маршрут 
	memset(buf, 0, N_ROUT);
	file.read(buf, N_ROUT);
	routApp_ = buf;

	// имя 
	memset(buf, 0, N_ROUT);
	file.read(buf, N_ROUT);
	routAct_ = buf;

	delete[]buf;

}