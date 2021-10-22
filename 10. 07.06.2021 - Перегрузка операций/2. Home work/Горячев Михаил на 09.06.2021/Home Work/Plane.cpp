#include "Plane.h"

#pragma region Конструкторы

// конструктор по умолчанию
Plane::Plane() : seat_(), count_passengers_(),
fuel_(), price_(), distance_(),
model_(new char[MODEL_SIZE]),
number_(new char[NUMBER_SIZE])
{
	// заполнение поля нулями
	memset(model_, 0, MODEL_SIZE);
	memset(number_, 0, NUMBER_SIZE);
}

// конструктор с параметрами
Plane::Plane(const char* model, int seat, int count_passengers, double fuel, int price, int distance, const char* number)
{
	// установка значений
	setSeat(seat);
	setCount_passengers(count_passengers);
	setPrice(price);
	setFuel(fuel);
	setDistance(distance);

	model_ = new char[MODEL_SIZE];
	number_ = new char[NUMBER_SIZE];

	setModel(model);
	setNumber(number);
}

// копирующий конструктор
Plane::Plane(const Plane& plane) : model_(new char[MODEL_SIZE]), seat_(plane.seat_), count_passengers_(plane.count_passengers_),
fuel_(plane.fuel_), price_(plane.price_), distance_(plane.distance_), number_(new char[NUMBER_SIZE])
{
	// копирование динамических полей
	memcpy(model_, plane.model_, MODEL_SIZE - 1);
	memcpy(number_, plane.number_, NUMBER_SIZE - 1);
}

#pragma endregion

#pragma region Сеттеры

// сеттер seat_
void Plane::setSeat(int seat)
{
	// если значение некорректно
	if (seat < MIN_SEAT || seat > MAX_SEAT)
	{
		throw exception("Введено некорректное значение количества пассажирских мест!");
	}

	// копирование
	seat_ = seat;
}

// сеттер count_passengers_
void Plane::setCount_passengers(int count_passengers)
{
	// если значение меньше 0 и больше количества пассажирских мест
	if (count_passengers < 0 || count_passengers > seat_)
	{
		throw exception("Введено некорректное значение количества пассажиров!");
	}

	// копирование
	count_passengers_ = count_passengers;
}

// сеттер fuel_
void Plane::setFuel(double fuel)
{
	// если значение некорректно
	if (fuel < MIN_FUEL || fuel > MAX_FUEL)
	{
		throw exception("Введено некорректное значение расхода горючего за час полета!");
	}

	// копирование
	fuel_ = fuel;
}

// сеттер distance_
void Plane::setDistance(int distance)
{
	// если значение некорректно
	if (distance < MIN_DISTANCE || distance > MAX_DISTANCE)
	{
		throw exception("Некорректные данные в поле дальности полёта!");
	}

	// копирование 
	distance_ = distance;
}

// сеттер price_
void Plane::setPrice(int price)
{
	// если значение некорректно
	if (price < MIN_PRICE || price > MAX_PRICE)
	{
		throw exception("Введено некорректное значение цены!");
	}

	// копирование
	price_ = price;
}

// сеттер model_
void Plane::setModel(const char* model)
{
	// если длина строки равна нулю
	if (strlen(model) == 0)
	{
		throw exception("Поле модели самолёта должно быть заполнено!");
	}

	// заполнение строки нулями
	memset(model_, 0, MODEL_SIZE);

	// копирование
	memcpy(model_, model, MODEL_SIZE - 1);
}

// сеттер number_
void Plane::setNumber(const char* number)
{
	// если длина строки равна нулю
	if (strlen(number) == 0)
	{
		throw exception("Поле номера самолёта должно быть заполнено!");
	}

	// заполнение строки нулями
	memset(number_, 0, NUMBER_SIZE);

	// копирование
	memcpy(number_, number, NUMBER_SIZE - 1);
}

#pragma endregion

#pragma region Методы

// Метод, вычисляющий расход горючего за час полета на одно пассажирское место
// (поделить расход горючего за час на количество пассажирских мест)
double Plane::fuelSeat() const
{
	// если количество посадочных мест нулевое
	if (seat_ == 0)
	{
		return -1;
	}

	return fuel_ / seat_;
}

#pragma region Перегрузка функций

// + добавление заданного количества пассажиров
Plane& Plane::operator+(int count)
{
	Plane* new_plane = new Plane(*this);

	new_plane->setCount_passengers(this->count_passengers_ + count);

	return *new_plane;
}

// – уменьшение количества пассажиров на заданное значение
Plane& Plane::operator-(int count)
{
	Plane* new_plane = new Plane(*this);

	new_plane->setCount_passengers(this->count_passengers_ - count);

	return *new_plane;
}

// оператор присваивания
Plane& Plane::operator=(const Plane& planeRight)
{
	// защита от самоприсваивания
	if (this == &planeRight) { return *this; }

	// копирование строк
	memcpy(this->model_, planeRight.model_, MODEL_SIZE - 1);
	memcpy(this->number_, planeRight.number_, NUMBER_SIZE - 1);

	// копирование 
	this->seat_ = planeRight.seat_;
	this->count_passengers_ = planeRight.count_passengers_;
	this->fuel_ = planeRight.fuel_;
	this->price_ = planeRight.price_;
	this->distance_ = planeRight.distance_;

	return *this;
}

#pragma endregion

#pragma endregion 

#pragma region Дружественные функции

ostream& operator<<(ostream& os, Plane& plane)
{
	os << "| " << setw(13) << plane.model_ << " | "
		<< setw(10) << plane.seat_ << " | "
		<< setw(10) << plane.count_passengers_ << " | "
		<< setw(14) << plane.fuel_ << " | "
		<< setw(17) << plane.price_ << " | "
		<< setw(17) << plane.distance_ << " | "
		<< setw(17) << plane.number_ << " |\n";

	return os;
}

#pragma endregion
