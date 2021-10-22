#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <cstring>
#include <exception>

#include "pch.h"

using namespace std;

class Plane
{
public:

#pragma region Константы
	/// константы
	// максимальное количество пассажирских мест
	const int MAX_SEAT = 1000;

	// минмальное количество пассажирский мест
	const int MIN_SEAT = 0;

	// расхода горючего за час полета максимум кг / ч
	const double MAX_FUEL = 20000.;

	// расхода горючего за час полета минимум кг / ч
	const double MIN_FUEL = 0.1;

	// максимальная цена самолёта
	const int MAX_PRICE = 300000000;

	// минимальная цена самолёта
	const int MIN_PRICE = 1;

	// длина поля model_ по умолчанию
	const int MODEL_SIZE = 40;

	// длина поля number_ по умолчанию
	const int NUMBER_SIZE = 20;

	/// !константы

#pragma endregion

private:
	/*класс Plane с полями для хранения :
	•	производителя и типа самолета(например : Ил - 76, Boeing 747, …) – char*
	•	количества пассажирских мест(от 0 до 1000) - int
	•	текущее количество пассажиров(от 0 до количества пассажирских мест) - int
	•	расхода горючего за час полета(вещественное число, от 0.1 до 20000 кг / ч) - double
	•	стоимости самолета (от 1 до 300 000 000) - int
	•	регистрационный номер самолета (например: UR-DAD, UR-CCF, …). - char
	*/

	// производитель и тип самолета(например : Ил - 76, Boeing 747, …) – char*
	char* model_;

	// количество пассажирских мест(от 0 до 1000) - int
	int seat_;

	// текущее количество пассажиров(от 0 до количества пассажирских мест) - int
	int count_passengers_;

	// расхода горючего за час полета(вещественное число, от 0.1 до 28600 кг / ч) - double
	double fuel_;

	// стоимости самолета (от 1 до 300 000 000)
	int price_;

	// регистрационный номер самолета(например: UR - DAD, UR - CCF, …). - char
	char* number_;

public:

#pragma region Конструкторы и дестркутор

	// конструктор по умолчанию
	Plane() : seat_(), count_passengers_(),
		fuel_(), price_()
	{
		model_ = new char[MODEL_SIZE];

		number_ = new char[NUMBER_SIZE];

		// заполнение поля нулями
		memset(model_, 0, MODEL_SIZE);
		memset(number_, 0, NUMBER_SIZE);
	}

	// конструктор с параметрами
	Plane(const char* model, int seat, int count_passengers, double fuel, int price, const char* number)
	{
		// установка значений
		setSeat(seat);
		setCount_passengers(count_passengers);
		setPrice(price);
		setFuel(fuel);

		model_ = new char[MODEL_SIZE];

		number_ = new char[NUMBER_SIZE];

		setModel(model);
		setNumber(number);
	}

	// копирующий конструктор
	Plane(const Plane& plane): model_(new char[MODEL_SIZE]), seat_(plane.seat_), count_passengers_(plane.count_passengers_),
		fuel_(plane.fuel_), price_(plane.price_), number_(new char[NUMBER_SIZE])
	{
		// копирование динамических полей
		strcpy(model_, plane.model_);
		strcpy(number_, plane.number_);
	}
	
	// деструктор
	~Plane()
	{
		delete[]model_;
		delete[]number_;
	}
#pragma endregion

#pragma region Сеттеры и Геттеры
	// сеттер seat_
	void setSeat(int seat)
	{
		if (seat < MIN_SEAT || seat > MAX_SEAT)
		{
			throw exception("Введено некорректное значение количества пассажирских мест!");
		}

		seat_ = seat;
	}
	
	// геттер seat_
	int getSeat() const { return seat_; }

	// сеттер count_passengers_
	void setCount_passengers(int count_passengers)
	{
		// если значение меньше 0 и больше количества пассажирских мест
		if (count_passengers < 0 || count_passengers > seat_)
		{
			throw exception("Введено некорректное значение количества пассажиров!");
		}

		count_passengers_ = count_passengers;
	}

	// геттер count_passengers_
	int getCount_passengers() const { return count_passengers_; }

	// сеттер fuel_
	void setFuel(double fuel)
	{
		if (fuel < MIN_FUEL || fuel > MAX_FUEL)
		{
			throw exception("Введено некорректное значение расхода горючего за час полета!");
		}

		fuel_ = fuel;
	}

	// геттер fuel_
	double getFuel() const { return fuel_; }

	// сеттер price_
	void setPrice(int price)
	{
		/*if (price < MIN_PRICE || price > MAX_PRICE)
		{
			throw exception("Введено некорректное значение количества двигателей!");
		}*/

		price_ = price;
	}

	// геттер engine_
	int getPrice() const { return price_; }

	// сеттер model_
	void setModel(const char* model)
	{
		// если длина строки равна нулю
		if (strlen(model) == 0)
		{
			throw exception("Поле номера самолёта должно быть заполнено!");
		}

		// заполнение строки нулями
		memset(model_, 0, MODEL_SIZE);

		strcpy(model_, model);
	}

	// геттер model_
	char* getModel() const { return model_; }

	// сеттер number_
	void setNumber(const char* number)
	{
		// если длина строки равна нулю
		if (strlen(number) == 0)
		{
			throw exception("Поле номера самолёта должно быть заполнено!");
		}

		// заполнение строки нулями
		memset(number_, 0, NUMBER_SIZE);

		strcpy(number_, number);
	}

	// геттер number_
	char* getNumber() const { return number_; }

	
#pragma endregion

#pragma region Методы

	// Метод, вычисляющий расход горючего за час полета на одно пассажирское место
	// (поделить расход горючего за час на количество пассажирских мест)
	double fuelSeat() 
	{
		// если количество посадочных мест нулевое
		if (seat_ == 0)
		{
			return -1;
		}

		return fuel_ / seat_; 
	}

	// + добавление заданного количества пассажиров
	Plane& operator+(int count)
	{
		Plane* new_plane = new Plane(*this);

		new_plane->setCount_passengers(this->count_passengers_ + count);

		return *new_plane;
	}

	// – уменьшение количества пассажиров на заданное значение
	Plane& operator-(int count)
	{
		Plane* new_plane = new Plane(*this);

		new_plane->setCount_passengers(this->count_passengers_ - count);

		return *new_plane;
	}

	// ++префиксный, увеличение расхода горючего на 100 кг/ч
	Plane& operator++()
	{

		this->setFuel(this->fuel_ + 100.);

		return *this;

	}

	// --префиксный, уменьшение расхода горючего на 100 кг/ч	
	Plane& operator--()
	{

		this->setFuel(this->fuel_ - 100);

		return *this;
	}

	// операции сравнения : < для сравнения двух объектов по стоимости самолета
	bool operator<(Plane& planeRight) { return this->price_ < planeRight.price_; }

	// операции сравнения : <= для сравнения двух объектов по стоимости самолета
	bool operator<=(Plane& planeRight) { return this->price_ <= planeRight.price_; }

	// операции сравнения : ==  для сравнения двух объектов по стоимости самолета
	bool operator==(Plane& planeRight) { return this->price_ == planeRight.price_; }

	// операции сравнения : !=  для сравнения двух объектов по стоимости самолета
	bool operator!=(Plane& planeRight) { return !(this->price_ == planeRight.price_); }

	// операции сравнения : >	для сравнения двух объектов по стоимости самолета
	bool operator>(Plane& planeRight) { return !(this->price_ < planeRight.price_); }

	// операции сравнения : >=	для сравнения двух объектов по стоимости самолета
	bool operator>=(Plane& planeRight) { return !(this->price_ <= planeRight.price_); }

	// оператор присваивания
	void operator=(const Plane& planeRight)
	{
		// производитель и тип самолета(например : Ил - 76, Boeing 747, …) – char*
		memcpy(this->model_, planeRight.model_, MODEL_SIZE - 1);

		// количество пассажирских мест(от 0 до 1000) - int
		this->seat_ = planeRight.seat_;

		// текущее количество пассажиров(от 0 до количества пассажирских мест) - int
		this->count_passengers_ = planeRight.count_passengers_;

		// расхода горючего за час полета(вещественное число, от 0.1 до 28600 кг / ч) - double
		this->fuel_ = planeRight.fuel_;

		// стоимости самолета (от 1 до 300 000 000)
		this->price_ = planeRight.price_;

		// регистрационный номер самолета(например: UR - DAD, UR - CCF, …). - char
		memcpy(this->number_, planeRight.number_, NUMBER_SIZE - 1);

	}
	
	// Метод, вычисляющий расход горючего за час полета на одно пассажирское место
	// (поделить расход горючего за час на количество пассажирских мест)
	double consumFuel() const { return count_passengers_ / seat_; }

#pragma endregion 

#pragma region Дружественные функции

	friend ostream& operator<<(ostream& os, Plane& plane)
	{
			os << "\t| " << setw(13) << plane.model_ << " | "
				<< setw(10) << plane.seat_ << " | "
				<< setw(10) << plane.count_passengers_ << " | "
				<< setw(14) << plane.fuel_<< " | "
				<< setw(17) << plane.price_ << " | "
				<< setw(17) << plane.number_ << " |\n";

			return os;
	}

#pragma endregion
};
