#include "pch.h"
#include "Plane.h"

// инициализация static-констант
const double Plane::MIN_CONSAMPTION = 0.1;
const double Plane::MAX_CONSAMPTION = 20'000.;


// перегрузка операции вывода для объекта класса Plane - вывод
// полей класса и значения метода класса в формате строки таблицы
ostream& operator<<(ostream& os, const Plane& plane)
{
	// формирование строкового представления часового
	// расхода на пассажирское место
	double value = plane.consumptionPerSeat();
	ostringstream oss;
	if (value > 0)
		oss << fixed << setprecision(2) << setw(15) << value;
	else 
		oss << "  не определено";
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


// буфер для вывода шапки и подвала таблицы
static char buf[511];

// оптимизация - компактизация выводимого кода заголовка
static const char* line = "+—————+—————————————————————+—————————————+————————————+—————————————————+—————————————————+————————————+—————————————————+";


// вывод шапки таблицы - статический метод
ostream & Plane::header(ostream &os)
{
	sprintf(buf,
	"    %s\n"
	"    |  N  | Тип и производитель | Пассажиро-  | Количество | Расход горючего | Расход горючего | Дальность  | Регистрационный |\n"
	"    | п/п |       самолета      | вместимость | пассажиров |      кг/час     |  кг/ч на место  | полета, км |      номер      |\n"
	"    %s", line, line);

	return os << buf;
} // Plane::showHead


// вывод подвала таблицы - статический метод
ostream& Plane::footer(ostream& os)
{
	// формирование подвала таблицы с отступами
	sprintf(buf, "    %s\n", line);
	return os << buf;
} // Plane::showFoot