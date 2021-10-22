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
	const int NAME_COMP_SIZE = 50;
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
	Airline(const char* nameCompany, int countPlane) : nameCompany_(new char[NAME_COMP_SIZE])
	{
		// название компании
		setNameCompany(nameCompany);

		// количество самолётов
		setCountPlane(countPlane);

		// если количество самолётов больше нуля
		if (countPlane_ != 0)
		{
			// выделение памяти для массива самолётов
			planes_ = new Plane[5];
		}
	}

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
	void setNameCompany(const char* nameCompany)
	{
		// если длина строки равна 0
		if (strlen(nameCompany) == 0)
		{
			throw exception("Название компании не должно быть пустым!");
		}

		strcpy(nameCompany_, nameCompany);
	}

	// геттер nameCompany_
	char* getNameCompany()
	{
		char* str = new char[NAME_COMP_SIZE];

		memcpy(str, nameCompany_, NAME_COMP_SIZE);

		return str;
	}

	// сеттер countPlane_
	void setCountPlane(int countPlane)
	{
		if (countPlane < 0)
		{
			throw exception("Количество самолетов должно равняться или быть больше нуля");
		}

		countPlane_ = countPlane;
	}

	// геттер countPlane_
	int getCountPlane() { return countPlane_; }


#pragma endregion

#pragma region Методы

#pragma region Пергрузка операторов

	// перегрузка операции [] для доступа к элементам массива самолетов
	Plane& operator[](int index)
	{
		if (index < 0 || index >= countPlane_)
			throw exception("Некорректный индекс");

		return planes_[index];
	}

	// перегрузка бинарной операции * для увеличения стоимости самолетов на заданный коэффициент (положительный)
	Airline& operator*(double coefficient)
	{
		// если коэффициент отрицательный 
		if (coefficient < 0)
			throw exception("Коэффициент должен быть положительным");

		Airline* temp = new Airline(*this);

		// цикл умножения стоимости каждого самолёта на коеффициент 
		for (size_t i = 0; i < countPlane_; i++)
		{
			temp->planes_[i].setPrice(int(planes_[i].getPrice() * coefficient));
		}

		return *temp;
	}

	// перегрузка унарной операции ! для поиска первого самолета с максимальной стоимостью
	Plane& operator!()
	{
		// если нет самолётов
		if (countPlane_ == 0)
		{
			throw exception("Нет самолётов!");
		}

		// текущая максимальная цена 
		int maxPrice = planes_[0].getPrice();

		// индекс 
		int maxIndex = 0;

		// нахождение первого самолёта с максимальной стоимостью
		for (size_t i = 1; i < countPlane_; i++)
		{
			// стоимость текущего самолёта
			int price = planes_[i].getPrice();

			// если текущая максимальная стоимость меньше, чем стоимость текущего самолёта
			if (maxPrice < price)
			{
				maxPrice = price;
				maxIndex = i;
			}
		}

		return planes_[maxIndex];
	}

	// перегрузка оператора присваивания
	void operator=(const Airline& air)
	{
		// название компании
		strcpy(nameCompany_, air.nameCompany_);

		// динамический массив самолетов – объектов класса Plane
		planes_ = new Plane[air.countPlane_];

		for (size_t i = 0; i < air.countPlane_; i++)
		{
			planes_[i] = air.planes_[i];
		}

		// количество самолетов в массиве
		countPlane_ = air.countPlane_;

	}

#pragma endregion

#pragma endregion

#pragma region Дружественные функции

	// вывод данных авиакомпании в табличном формате – перегрузка операции вывода <<
	friend ostream& operator<<(ostream& os, Airline air)
	{
		os << "\t\t\t\t\t" << air.nameCompany_ << "\n"
			<< "\t+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+\n"
			<< "\t|     Модель    |  Пассажир. | Пассажиров | Расх. горючего |     Стоимость     |  Регистрис. номер |\n"
			<< "\t|               |     мест   |            |     кг/ч       |      самолёта     |      самолёта     |\n"
			<< "\t+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+\n";

		// если в компании нет самолётов
		if (air.countPlane_ == 0)
		{
			os << "\t|                                         НЕТ САМОЛЁТОВ                                            |\n";
			// нижняя строка 
			os << "\t+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+\n";
		}

		// вывод самолётов
		for (size_t i = 0; i < air.countPlane_; i++)
		{
			os << air[i];

			// нижняя строка 
			os << "\t+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+\n";
		}

		return os;
	}

	// перегрузка унарной операции – для поиска первого самолета с минимальной стоимостью
	friend Plane& operator-(Airline& air)
	{
		// если нет самолётов
		if (air.countPlane_ == 0)
		{
			throw exception("Нет самолётов!");
		}

		// текущая минимальная цена 
		int minPrice = air.planes_[0].getPrice();

		// индекс 
		int minIndex = 0;

		// нахождение первого самолёта с минимальной стоимостью
		for (size_t i = 1; i < air.countPlane_; i++)
		{
			// стоимость текущего самолёта
			int price = air.planes_[i].getPrice();

			// если текущая минимальная стоимость больше, чем стоимость текущего самолёта
			if (minPrice > price)
			{
				minPrice = price;
				minIndex = i;
			}
		}

		return air.planes_[minIndex];
	}

#pragma endregion

};

