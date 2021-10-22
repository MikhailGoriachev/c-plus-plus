#pragma once
/*
 * Разработайте класс Plane с полями для хранения:
 *     • производителя и типа самолета (например: Ил-76, Boeing 747, …)
 *     • количества пассажирских мест (от 0 до 1000)
 *     • текущее количество пассажиров (от 0 до количества пассажирских мест)
 *     • расхода горючего за час полета (вещественное число,
 *       от 0.1 до 20'000 кг/ч)
 *     • дальность полета самолета (от 1'000 до 20'000 км)
 *     • регистрационный номер самолета (например: UR-DAD, UR-CCF, …).
 * В классе Plane разработать:
 *     • Конструкторы: по умолчанию, с параметрами, копирующий, деструктор
 *     • Геттеры и сеттеры для всех полей класса, в сеттерах выбрасывать
 *       исключение при обнаружении некорректного значения
 *     • Метод, вычисляющий расход горючего за час полета на одно пассажирское
 *       место (поделить расход горючего за час на количество пассажирских
 *       мест)
 *     • Перегрузить операции сравнения: < <= == != >= > для сравнения двух
 *       объектов по дальности полета самолета
 *     • Перегрузить операцию вывода <<     
 */
#include "pch.h"

class Plane
{
public:
	// длина поля типа самолета и названия компании-воадельца
	static const int N_AIRCRAFT_TYPE = 55, N_REG_NUMBER = 21;

	// граничные значения
	// расход горючего - static с типом, отличным от int нельзя инициировать в объявлении класса
	static const double MIN_CONSAMPTION, MAX_CONSAMPTION;

	// диапазон дальности полета самолета
	static const int MIN_RANGE = 1'000, MAX_RANGE = 20'000;

private:
	
	// производитель и тип самолета (например: Ил-76, Boeing 747, Ан-124-100М2, Airbus 321 Neo-LX, …)
	char* aircraftType_;

	// количества пассажирских мест (от 0 до 1000)
	int seates_;

	// текущее количество пассажиров (от 0 до количества пассажирских мест)
	int passengers_;

	// расход горючего за час полета (вещественное число, от 0.1 до 8600 кг/ч)
	double consumption_;

	// дальность полета самолета (от 1000 до 20000 км)
	int range_;

	// регистрационный номер самолета (например: UR-DAD, UR-CCF, …)
	char* regNumber_;

	// буфер вывода данных в строковом формате и его длина
	char* buf_;
	const int N_LEN_BUF = 151;
	
public:
	// конструктор по умолчанию
	Plane() :aircraftType_(new char[N_AIRCRAFT_TYPE] {0}), seates_(0), passengers_(0),
		consumption_(0.1), range_(MIN_RANGE), regNumber_(new char[N_REG_NUMBER] {0})
	{
		strcpy(aircraftType_, "По-2");
		strcpy(regNumber_, "UR-DAD");

		// выделение памяти под служебный буфер
		buf_ = new char[N_LEN_BUF] {0};
	} // Plane

	// инициирующий конструктор
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

		// выделение памяти под служебный буфер
		buf_ = new char[N_LEN_BUF] {0};
	} // Plane

	// конструктор копирования
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

		// выделение памяти под служебный буфер
		buf_ = new char[N_LEN_BUF] {0};
	} // Plane

	// деструктор
	~Plane()
	{
		// освобождение памяти, выделенной под динамические поля
		delete[] aircraftType_;
		delete[] regNumber_;
		delete[] buf_;
	} // ~Plane

	// геттеры и сеттеры
	// производитель и тип самолета
	const char* getAircraftType() const { return aircraftType_; }
	void setAircraftType(const char* value)
	{
		if (strlen(value) == 0)
			throw exception("    Plane: не задан производитель и тип самолета");
		strncpy(aircraftType_, value, N_AIRCRAFT_TYPE);
	} // setAircraftType

	// количество пассажирских мест (от 0 до 1000)
	int getSeates() const { return seates_; }
	void setSeates(int value)
	{
		if (value < 0 || value > 1000)
			throw exception("    Plane: недопустимое количество пассажирских мест");

		seates_ = value;
	} // setSeates

	// текущее количество пассажиров (от 0 до количества пассажирских мест)
	int getPassengers() const { return passengers_;  }
	void setPassengers(int value)
	{
		if (value < 0 || value > seates_)
			throw exception("    Plane: недопустимое количество пассажиров");

		passengers_ = value;
	} // setPassengers

	// расход горючего за час полета(вещественное число, от 0.1 до 20 000 кг/ч)
	double getConsumption() const { return consumption_;  }
	void setConsumption(double value)
	{
		if (value < MIN_CONSAMPTION || value > MAX_CONSAMPTION)
			throw exception("    Plane: недопустимое расхода горючего");

		consumption_ = value;
	} // setConsumption

	// дальность полета самолета (от 1'000 до 20'000)
	int getRange() const { return range_; }
	void setRange(int value)
	{
		if (value < MIN_RANGE || value > MAX_RANGE)
			throw exception("    Plane: недопустимая дальность полета");

		range_ = value;
	} // setRange

	// регистрационный номер самолета (например: UR-DAD, UR-CCF, …)
	const char* getRegNumber() const { return regNumber_; }
	void setRegNumber(const char* value)
	{
		if (strlen(value) == 0)
			throw exception("    Plane: не задан регистрационный номер");
		strncpy(regNumber_, value, N_REG_NUMBER);
	} // setRegNumber

	// Метод, вычисляющий расход горючего за час полета на одно пассажирское
	// место (поделить расход горючего за час на количество пассажирских мест)
	// Возвращает -1 для самолетов без пассажирских мест
	double consumptionPerSeat() const
	{
		return seates_ == 0? -1: consumption_ / seates_;
	} // consumptionPerSeat

	// вывод данных объекта в строковый буфер
	const char *toString() const
	{
		// формирование строкового представления часового
		// расхода на пассажирское место
		double value = consumptionPerSeat();
		ostringstream oss;
		if (value > 0)
			oss << fixed << setprecision(2) << setw(15) << value;
		else
			oss << "не определено";

		// формирование строкового представления данных объекта
		sprintf(buf_, " | %-19s | %11d | %10d | %15.2lf | %15s | %10d | %-16s |", 
			aircraftType_, seates_, passengers_, consumption_, 
			oss.str().c_str(), 
			range_, regNumber_);
		return buf_;
	} // toString
	
	// переопределенные операции -------------------------------------------------
	// присваивание
	Plane &operator=(const Plane &plane)
	{
		// защита от самоприсваивания
		if (&plane == this) return *this;

		// т.к. строковые поля фиксированной длины освобождение памяти
		// и выделение нового блока памяти не требуется
		memcpy(aircraftType_, plane.aircraftType_, N_AIRCRAFT_TYPE);
		memcpy(regNumber_, plane.regNumber_, N_REG_NUMBER);

		seates_ = plane.seates_;
		passengers_ = plane.passengers_;
		consumption_ = plane.consumption_;
		range_ = plane.range_;
		
		return *this;
	} // operator=

	
	// операции сравнения для сравнения двух объектов по дальности
	// полета самолета
	bool operator<(const Plane& p)  const { return range_  < p.range_; }
	bool operator<=(const Plane& p) const { return range_ <= p.range_; }
	bool operator==(const Plane& p) const { return range_ == p.range_; }
	bool operator!=(const Plane& p) const { return !(*this == p); }
	bool operator>=(const Plane& p) const { return !(*this < p); }   //  !< 
	bool operator>(const Plane& p)  const { return !(*this <= p); }  //  !<=

	// перегрузка операции вывода дружественной функцией, выводим строку таблицы
	friend ostream& operator<<(ostream& os, const Plane& plane);

	// вывод шапки таблицы в строку
	static ostream& header(ostream& os);

	// вывод подвала таблицы в строку
	static ostream& footer(ostream& os);
};

