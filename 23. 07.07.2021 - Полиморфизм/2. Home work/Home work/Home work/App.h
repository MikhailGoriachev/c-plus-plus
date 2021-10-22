#pragma once
#include "pch.h"
#include "Utils.h"
#include "Cylinder.h"
#include "Conoid.h"
#include "Cube.h"
#include "Sphere.h"
#include "Body.h"
#include "DblList.h"

/*
	*	Разработайте иерархию классов для представления объемных фигур. Базовый
			абстрактный класс Body с чистыми виртуальными методами для вычисления 
			площади поверхности, объема фигуры, вывода данных по фигуре и сравнения 
			фигур по объему.
	*	Реализуйте классы для представления сферы, куба, конуса и цилиндра. 
	*	Разместите объекты этих классов в массиве указателей на базовый класс.
			Отсортируйте массив стандартной функцией qsort() по убыванию объемов.
			Заполните шаблонный класс двусвязный список данными отсортированного 
			массива, в узлах списка храните указатели на базовый класс. Выведите 
			данные фигур из списка при помощи итератора.
*/

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
	// двусвязный список фигур
	DblList<Body*> list_;

	// массив фигур
	Body** figures_;

	// размер массива
	static const int SIZE_ARRAY = 8;

public:

	// конструктор по умолчанию
	App()
	{
		// массив фигур
		figures_ = new Body * [SIZE_ARRAY]
		{
			new Cylinder(getRand(10., 20.), getRand(1., 5.)),
			new Cube(getRand(10., 20.)),
			new Conoid(getRand(10., 20.), getRand(1., 5.)),
			new Sphere(getRand(10., 20.)),
			new Cube(getRand(10., 20.)),
			new Conoid(getRand(10., 20.), getRand(1., 5.)),
			new Sphere(getRand(10., 20.)),
			new Cylinder(getRand(10., 20.), getRand(1., 5.))
		};

		list_.addAll(figures_, SIZE_ARRAY);

		// отчистка памяти
		// for (int i = 0; i < SIZE_ARRAY; i++)
		// {
		// 	delete[] figures_[i];
		// }
	}

	// деструктор 
	~App()
	{
		// отчистка списка от прошлых данных
		list_.clear();

		// отчистка памяти
		for (int i = 0; i < SIZE_ARRAY; i++)
		{
			delete[] figures_[i];
		}

		delete[]figures_;
	}

#pragma region Задания

	// Генерация новых данных
	void genData();

	// Сортировка по убыванию объёмов 
	void sortByValume();

	// Вывод данных
	void printData();

	// вывод данных двусвязного списка в виде таблицы
	void showTable(const DblList<Body*>& list);

#pragma endregion

};

