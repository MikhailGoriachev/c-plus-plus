#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <cstring>
#include <exception>

using namespace std;

class Plane
{

#pragma region Константы
	/// константы

	// максимальное количество пассажирских мест
	const int MAX_SEAT = 1000;

	// минмальное количество пассажирский мест
	const int MIN_SEAT = 0;

	// расхода горючего за час полета максимум кг / ч
	const double MAX_FUEL = 28600.;

	// расхода горючего за час полета минимум кг / ч
	const double MIN_FUEL = 0.1;

	// количество двигателей минимум
	const int MAX_ENGINE = 8;

	// количество двигателей минимум
	const int MIN_ENGINE = 1;

	// длина поля model_ по умолчанию
	const int MODEL_SIZE = 50;

	// длина поля name_airline_ по умолчанию
	const int NAME_AIRLINE_SIZE = 50;


	/// !константы
#pragma endregion

	/*класс Plane с полями для хранения :
	•	производителя и типа самолета(например : Ил - 76, Boeing 747, …) – char*
	•	количества пассажирских мест(от 0 до 1000) - int
	•	текущее количество пассажиров(от 0 до количества пассажирских мест) - int
	•	расхода горючего за час полета(вещественное число, от 0.1 до 28600 кг / ч) - double
	•	количества двигателей(от 1 до 8)–int
	•	названия авиакомпании – владельца – char* .
	*/

	// производитель и тип самолета(например : Ил - 76, Boeing 747, …) – char*
	char* model_;

	// количество пассажирских мест(от 0 до 1000) - int
	int seat_;

	// текущее количество пассажиров(от 0 до количества пассажирских мест) - int
	int count_passengers_;

	// расхода горючего за час полета(вещественное число, от 0.1 до 28600 кг / ч) - double
	double fuel_;

	// количества двигателей(от 1 до 8)–int
	int engine_;

	// названия авиакомпании – владельца – char*
	char* name_airline_;

public:

	// конструктор по умолчанию
	Plane() : model_(new char[MODEL_SIZE]), seat_(0), count_passengers_(0),
		fuel_(0), engine_(0), name_airline_(new char[NAME_AIRLINE_SIZE])
	{
		// заполнение поля нулями
		memset(model_, 0, 50);
		memset(name_airline_, 0, 50);
	}

	// конструктор с параметрами
	Plane(const char* model, int seat, int count_passengers, double fuel, int engine, const char* name_airline)
	{
		// установка значений
		setSeat(seat);
		setCount_passengers(count_passengers);
		setFuel(fuel);
		setEngine(engine);

		// размер строки model
		size_t size = strlen(model);

		// выделение памяти для строки model
		model_ = new char[size];

		// копирование
		strcpy(model_, model);

		// размер строки name_airline
		size = strlen(model);

		// выделение памяти для строки name_airline
		name_airline_ = new char[size];

		// копирование
		strcpy(name_airline_, name_airline);
	}

	// копирующий конструктор
	Plane(const Plane& plane): model_(new char[strlen(plane.model_)]), seat_(plane.seat_), count_passengers_(plane.count_passengers_),
		fuel_(plane.fuel_), engine_(plane.engine_), name_airline_(new char[strlen(plane.name_airline_)])
	{
		// копирование динамических полей
		strcpy(model_, plane.model_);
		strcpy(name_airline_, plane.name_airline_);
	}
	
	// деструктор
	~Plane()
	{
		delete[]model_;
		delete[]name_airline_;
	}
	
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
	void setFuel(int fuel)
	{
		if (fuel < MIN_FUEL || fuel > MAX_FUEL)
		{
			throw exception("Введено некорректное значение расхода горючего за час полета!");
		}

		fuel_ = fuel;
	}

	// геттер fuel_
	int getFuel() const { return fuel_; }

	// сеттер engine_
	void setEngine(int engine)
	{
		if (engine < MIN_ENGINE || engine > MAX_ENGINE)
		{
			throw exception("Введено некорректное значение количества двигателей!");
		}

		engine_ = engine;
	}

	// геттер engine_
	int getEngine() const { return engine_; }

	// сеттер model_
	void setModel(const char* model)
	{
		model_ = new char[strlen(model)];

		strcpy(model_, model);
	}

	// геттер model_
	char* getModel() const { return model_; }

	// сеттер name_airline_
	void setName_airline(const char* name_airline)
	{
		name_airline_ = new char[strlen(name_airline)];

		strcpy(name_airline_, name_airline);
	}

	// геттер name_airline_
	char* getName_airline() const { return name_airline_; }

	
#pragma endregion

#pragma region Методы
	// Метод, вычисляющий расход горючего за час полета на одно пассажирское место
	// (поделить расход горючего за час на количество пассажирских мест)
	double fuelSeat() { return fuel_ / seat_; }

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

		this->setFuel(this->fuel_ + 100);

		return *this;

	}

	// --префиксный, уменьшение расхода горючего на 100 кг/ч	
	Plane& operator--()
	{

		this->setFuel(this->fuel_ - 100);

		return *this;
	}

	// операции сравнения : < для сравнения двух объектов по количеству пассажиров
	bool operator<(Plane& planeRight) { return this->count_passengers_ < planeRight.count_passengers_; }

	// операции сравнения : <= для сравнения двух объектов по количеству пассажиров
	bool operator<=(Plane& planeRight) { return this->count_passengers_ <= planeRight.count_passengers_; }

	// операции сравнения : ==  для сравнения двух объектов по количеству пассажиров
	bool operator==(Plane& planeRight) { return this->count_passengers_ == planeRight.count_passengers_; }

	// операции сравнения : !=  для сравнения двух объектов по количеству пассажиров
	bool operator!=(Plane& planeRight) { return this->count_passengers_ != planeRight.count_passengers_; }

	// операции сравнения : >	для сравнения двух объектов по количеству пассажиров
	bool operator>(Plane& planeRight) { return this->count_passengers_ > planeRight.count_passengers_; }

	// операции сравнения : >=	для сравнения двух объектов по количеству пассажиров
	bool operator>=(Plane& planeRight) { return this->count_passengers_ >= planeRight.count_passengers_; }

	
	void operator=(Plane& planeRight)
	{
		// производитель и тип самолета(например : Ил - 76, Boeing 747, …) – char*
		this->model_ = new char[strlen(planeRight.model_)];

		strcpy(this->model_, planeRight.model_);

		// количество пассажирских мест(от 0 до 1000) - int
		this->seat_ = planeRight.seat_;

		// текущее количество пассажиров(от 0 до количества пассажирских мест) - int
		this->count_passengers_ = planeRight.count_passengers_;

		// расхода горючего за час полета(вещественное число, от 0.1 до 28600 кг / ч) - double
		this->fuel_ = planeRight.fuel_;

		// количества двигателей(от 1 до 8)–int
		this->engine_ = planeRight.engine_;

		// названия авиакомпании – владельца – char*
		this->name_airline_ = new char[strlen(planeRight.name_airline_)];

		strcpy(this->name_airline_, planeRight.name_airline_);
	}
	
#pragma endregion 
};
