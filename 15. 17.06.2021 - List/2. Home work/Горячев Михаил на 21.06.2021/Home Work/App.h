#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "List.h"
#include "Plane.h"
#include "ListPlane.h"

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
public:

#pragma region Задание 1

	// меню задания 1
	void task1();
	
	// Вставка элемента в список перед позицией 
	void task1Insert();

	// предикатор для вывода в цвете для вставки
	friend bool task1InsertPred(int currentPosition, int* posArr, int sizePosArr);

	// Возвращение значения элемента списка по заданной позиции
	void task1Get();
	
	// Запись значение в заданную позицию списка
	void task1Put();

	// Добавление массива в конец списка
	void task1AddAll();

	// Вставка массива перед позицией 
	void task1InsertAll();

	// генерация массива (int)
	int* getArrayRandom(int size, int min, int max);

	// перегрузка функции вывода для массива (int)
	void showArrInt(int* arr, int size);

#pragma endregion

#pragma region Задание 2

	// меню задания 2
	void task2();

	// Вставка элемента в список перед позицией 
	void task2Insert();

	// Возвращение значения элемента списка по заданной позиции
	void task2Get();

	// Запись значение в заданную позицию списка
	void task2Put();

	// Добавление массива в конец списка
	void task2AddAll();

	// Вставка массива перед позицией 
	void task2InsertAll();

	// генерация самолёта 
	Plane genPlane();

	// создание заполнение массива (Plane)
	Plane* fillArrPlane(int size);

#pragma endregion



};

