#pragma once
#include "Plane.h"
#include "pch.h"

/*
	Класс Airline, представляющий авиакомпанию. Поля класса:
	•	название компании
	•	динамический массив самолетов – объектов класса Plane
	•	количество самолетов в массиве
	Реализовать:
	•	инициализацию массива самолетов
	•	вывод данных авиакомпании в табличном формате – перегрузите операцию вывода <<
	•	добавьте по 10 пассажиров каждому самолету компании
	•	уменьшите количество пассажиров каждого самолета на 3
	•	методом класса перегрузите унарную операцию ! для поиска первого самолета с максимальной стоимостью
	•	дружественной функцией перегрузите унарную операцию – для поиска первого самолета с минимальной стоимостью
	•	методом класса перегрузите бинарную операцию * для увеличения стоимости самолетов на заданный коэффициент (положительный, например, 1.5 – удорожание в полтора раза)
	•	методом класса перегрузите операцию [] для доступа к элементам массива самолетов, продемонстрируйте работу этой операции

*/

class Airline
{
public:

#pragma region Константы
	// размер строки Название компании
	static const int NAME_COMP_SIZE = 51;
#pragma endregion 

private:
	// название компании
	char* nameCompany_;

	// динамический массив самолетов – объектов класса Plane
	Plane* planes_;

	// количество самолетов в массиве
	int countPlane_;

public:

#pragma region Конструкторы и деструктор

	// конструктор по умолчанию
	Airline() :nameCompany_(new char[NAME_COMP_SIZE] {0}), planes_(nullptr), countPlane_() {}

	// констурктор инициализирующий
	Airline(const char* nameCompany, int countPlane);

	// констурктор инициализирующий, принимающий массив самолётов
	Airline(const char* nameCompany, Plane* planes, int countPlane);

	// копирующий конструктор
	Airline(const Airline& air): nameCompany_(new char[NAME_COMP_SIZE])
	{
		// копирование названия компании
		memcpy(nameCompany_, air.nameCompany_, NAME_COMP_SIZE);

		// копирование количества самолётов
		countPlane_ = air.countPlane_;

		// выделение памяти под массив самолётов
		planes_ = new Plane[countPlane_];

		// копирование массива самолётов
		for (size_t i = 0; i < countPlane_; i++)
		{
			planes_[i] = air.planes_[i];
		}
	}

	// деструктор 
	~Airline()
	{
		delete[] nameCompany_;
		delete[] planes_;
	}

#pragma endregion

#pragma region Сеттеры и Геттеры

	// сеттер nameCompany_
	void setNameCompany(const char* nameCompany);

	// геттер nameCompany_
	char* getNameCompany()
	{
		/*char* str = new char[NAME_COMP_SIZE];
		memcpy(str, nameCompany_, NAME_COMP_SIZE - 1);
		return str;*/

		return nameCompany_;
	}

	// сеттер countPlane_
	void setCountPlane(int countPlane);

	// геттер countPlane_
	int getCountPlane() { return countPlane_; }

	// сеттер planes_
	void setPlanes(Plane* planes);

	// геттер planes_
	Plane* getPlanes() const { return planes_; }

#pragma endregion

#pragma region Методы

	// быстрая сортировка массива самолётов по дальности полёта самолёта
	void quickSort(Plane* planes, int start, int end);

	// быстрая сортировка массива самолётов по компаратору
	void quickSort(Plane* planes, int start, int end, int compare(const Plane& pl1, const Plane& pl2));

	// добавление самолёта (в конец массива)
	//Airline& operator&(Plane& newPlane);

#pragma region Пергрузка операторов

	// перегрузка операции [] для доступа к элементам массива самолетов
	Plane& operator[](int index);

	// перегрузка бинарной операции * для увеличения стоимости самолетов на заданный коэффициент (положительный)
	Airline& operator*(double coefficient);

	// перегрузка унарной операции – для поиска первого самолета с минимальной дальностью полета
	Plane& operator!();

	// перегрузка унарной операции – для поиска первого самолета с минимальной дальностью полета
	Plane& operator-();

	// перегрузка оператора присваивания
	Airline& operator=(const Airline& air);

	// методом класса перегрузите унарную операцию* для сортировки 
	// массива самолетов по дальности полёта самолёта
	Airline& operator*();

	// перегрузка бинарной операции *
	// сортировка по текущему количеству пассажиров
	Airline operator*(int comparer(const Plane& plane1, const Plane& plane2));

	// добавление самолёта (в конец массива)
	Airline& operator&(Plane& newPlane);

#pragma endregion

#pragma endregion

#pragma region Дружественные функции

	// вывод данных авиакомпании в табличном формате – перегрузка операции вывода <<
	friend ostream& operator<<(ostream& os, Airline air);

#pragma endregion
};



