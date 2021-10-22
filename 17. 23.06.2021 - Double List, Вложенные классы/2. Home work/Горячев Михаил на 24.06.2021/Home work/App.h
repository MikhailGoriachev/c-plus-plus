#pragma once
#include "pch.h"
#include "Utils.h"
#include "Deque.h"
#include "Car.h"

/*
	По аналогии с шаблонным классом Deque из предыдущего задания (на базе односвязного
	списка –класса List) разработайте шаблонный класс Deque на базедвухсвязного списка
	DblList из классной работы.

	Разработайте консольное приложение, в котором продемонстрируйте все операции с этим
	деком для типов int, char, Car (из задачи о парковке, поля класса – регистрационный
	номер, цвет, бренд).
*/

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
public:

	// тест функций
	template<typename T>
	void demo(Deque<T> deq, T* arrFill, int sizeDillArr, T* arrAdd, int sizeAddArr, T add, T ins, T* arrIns, int sizeInsArr);

	void intDemo();
	void charDemo();
	void carDemo();

	// генерация автомобиля
	Car genCar();
};

