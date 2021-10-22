g#include "App.h"
#include "Utils.h"

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


// Генерация новых данных
void App::genData()
{
	cls();

	showNavBarMessage(hintColor, "Генерация новых данных");

	cputs("\n\t——————————————————————————————————————— НОВЫЕ ДАННЫЕ ——————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// отчистка списка от прошлых данных
	list_.clear();

	// отчистка памяти
	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		delete[] figures_[i];
	}

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

	// заполенение списка двумерным массивом для демонстрации 
	list_.addAll(figures_, SIZE_ARRAY);

	// вывод данных до сортировки
	showTable(list_);

	cout << "\n\n\n";

	getKey();
}

// вывод данных двусвязного списка в виде таблицы
void App::showTable(const DblList<Body*>& list)
{
	// вывод шапки таблицы
	Body::showHead();

	// если список пуст
	if (list.isEmpty())
		cout << "\t|                                        НЕТ ДАННЫХ                                         |\n";

	else
	{
		// итератор для списка 
		DblList<Body*>::Iterator<Body*> iterator(list);

		// вывод поэлементно в таблицу
		for (iterator.begin(); iterator != iterator.end(); ++iterator)
		{
			(*iterator)->show();
		}
	}
}

// Сортировка по убыванию объёмов 
void App::sortByValume()
{
	cls();

	showNavBarMessage(hintColor, "Сортировка по убыванию объёмов ");

	cputs("\n\t—————————————————————————————————————— ДО СОРТИРОВКИ ——————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод данных до сортировки
	showTable(list_);

	// сортировка массива
	qsort(figures_, SIZE_ARRAY, sizeof(Body*), Body::compare);

	// отчистка списка от прошлых данных
	list_.clear();

	// заполенение списка двумерным массивом для демонстрации 
	list_.addAll(figures_, SIZE_ARRAY);

	cputs("\n\t———————————————————————————————————— ПОСЛЕ СОРТИРОВКИ —————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод данных до сортировки
	showTable(list_);

	getKey();
}

// Вывод данных
void App::printData()
{
	cls();

	showNavBarMessage(hintColor, "Вывод данных");

	cputs("\n\t—————————————————————————————————————————— ДАННЫЕ —————————————————————————————————————————\n\n", YELLOW_ON_BLACK);

	// вывод данных до сортировки
	showTable(list_);

	cout << "\n\n\n";

	getKey();
}