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
	static const int MAX_SEAT = 1000;

	// минмальное количество пассажирский мест
	static const int MIN_SEAT = 0;

	// расхода горючего за час полета максимум кг / ч (вещественное число, от 0.1 до 28600 кг / ч)
	static const double MAX_FUEL;

	// расхода горючего за час полета минимум кг / ч (вещественное число, от 0.1 до 28600 кг / ч)
	static const double MIN_FUEL;

	// максимальная цена самолёта
	static const int MAX_PRICE = 300000000;

	// минимальная цена самолёта
	static const int MIN_PRICE = 1;

	// длина поля model_ по умолчанию
	static const int MODEL_SIZE = 41;

	// длина поля number_ по умолчанию
	static const int NUMBER_SIZE = 21;

	// минимальная дальность полета самолета 
	static const int MIN_DISTANCE = 1000;

	// максимальная дальность полета самолета 
	static const int MAX_DISTANCE = 20000;

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

	// дальность полета самолета (от 1000 до 20000 км)
	int distance_;

	// регистрационный номер самолета(например: UR - DAD, UR - CCF, …). - char
	char* number_;

public:

#pragma region Конструкторы и дестркутор

	// конструктор по умолчанию
	explicit Plane();
	
	// конструктор с параметрами
	explicit Plane(const char* model, int seat, int count_passengers, double fuel, int price, int distance, const char* number);

	// копирующий конструктор
	Plane(const Plane& plane);
	
	// деструктор
	~Plane()
	{
		delete[]model_;
		delete[]number_;
	}
#pragma endregion

#pragma region Сеттеры и Геттеры

	// сеттер seat_
	void setSeat(int seat);
	
	// геттер seat_
	int getSeat() const { return seat_; }

	// сеттер count_passengers_
	void setCount_passengers(int count_passengers);

	// геттер count_passengers_
	int getCount_passengers() const { return count_passengers_; }

	// сеттер fuel_
	void setFuel(double fuel);

	// геттер fuel_
	double getFuel() const { return fuel_; }

	// сеттер distance_
	void setDistance(int distance);

	// геттер distance_
	int getDistance() const { return distance_; }

	// сеттер price_
	void setPrice(int price);

	// геттер engine_
	int getPrice() const { return price_; }

	// сеттер model_
	void setModel(const char* model);

	// геттер model_
	char* getModel() const { return model_; }

	// сеттер number_
	void setNumber(const char* number);

	// геттер number_
	char* getNumber() const { return number_; }
	
#pragma endregion

#pragma region Методы

	// Метод, вычисляющий расход горючего за час полета на одно пассажирское место
	// (поделить расход горючего за час на количество пассажирских мест)
	double fuelSeat() const;

#pragma region Перезгрузка функций

	// + добавление заданного количества пассажиров
	Plane& operator+(int count);

	// – уменьшение количества пассажиров на заданное значение
	Plane& operator-(int count);

	// операции сравнения : < для сравнения двух объектов по дальности полета самолета
	bool operator<(Plane& planeRight) { return this->distance_ < planeRight.distance_; }

	// операции сравнения : <= для сравнения двух объектов по дальности полета самолета
	bool operator<=(Plane& planeRight) { return this->distance_ <= planeRight.distance_; }

	// операции сравнения : ==  для сравнения двух объектов по дальности полета самолета
	bool operator==(Plane& planeRight) { return this->distance_ == planeRight.distance_; }

	// операции сравнения : !=  для сравнения двух объектов по дальности полета самолета
	bool operator!=(Plane& planeRight) { return !(this->distance_ == planeRight.distance_); }

	// операции сравнения : >	для сравнения двух объектов по дальности полета самолета
	bool operator>(Plane& planeRight) { return !(this->distance_ < planeRight.distance_); }

	// операции сравнения : >=	для сравнения двух объектов по дальности полета самолета
	bool operator>=(Plane& planeRight) { return !(this->distance_ <= planeRight.distance_); }

	// оператор присваивания
	Plane& operator=(const Plane& planeRight);
	
#pragma endregion

#pragma endregion 

#pragma region Дружественные функции

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, Plane& plane);

#pragma endregion
};
