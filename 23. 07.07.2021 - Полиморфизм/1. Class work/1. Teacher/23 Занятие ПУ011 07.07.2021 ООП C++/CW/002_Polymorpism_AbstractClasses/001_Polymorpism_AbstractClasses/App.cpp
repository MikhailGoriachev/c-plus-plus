#include "pch.h"
#include "Utils.h"
#include "App.h"

#include "Equilateral.h"
#include "Rectangular.h"
#include "TRectangular.h"
#include "Triangle.h"
#include "TSquare.h"

// полиморфные классы
void App::point1()
{
	const int N_TRIANGLES = 7;
	// массив указателей на базовый класс - полиморфный
	Triangle **triangles = new Triangle * [N_TRIANGLES]
	{
		new Triangle(3., 5., 6.),
		new Equilateral(3.),
		new Equilateral(5.),
		new Triangle(4., 7., 6.),
		new Triangle(8., 7., 3.),
		new Rectangular(8., 7.),
		new Rectangular(7., 3.)
	};

	for (int i = 0; i < N_TRIANGLES; ++i)
		triangles[i]->show();

	delete[] triangles;
} // App::point1


// абстрактные классы
void App::point2()
{
	TSquare tSquare(10);
	cout<< "\n\nКвадрат, как реализация наследника абстрактного класса:\n"
	    << tSquare << "\n\n";

	TRectangular tRectangular(10., 20.);
	cout<< "Прямоугольник, как реализация наследника абстрактного класса:\n"
	    << tRectangular << "\n\n";
} // App::point2


// сортировка массива полиморфного класса
void App::point3()
{

	// массив указателей на базовый класс - полиморфный
	const int N_TRIANGLES = 7;
	Triangle** triangles = new Triangle * [N_TRIANGLES] {
		new Triangle(3., 5., 6.),
		new Equilateral(3.),
		new Equilateral(5.),
		new Triangle(4., 7., 6.),
		new Triangle(8., 7., 3.),
		new Rectangular(8., 7.),
		new Rectangular(7., 3.)
	};

	// сортировка массива указателей, но в компараторе сравниваем два объекта
	// по заданному критерию
	qsort(triangles, N_TRIANGLES, sizeof(Triangle *), Triangle::compare);

	cout << "\nОтсортировано по возрастанию площадей треугольников:\n";
	for (int i = 0; i < N_TRIANGLES; ++i)
		triangles[i]->show();

	delete[] triangles;

	// массив указателей на абстрактный класс - полиморфный
	TRect** trects = new TRect* [N_TRIANGLES] {
		new TSquare(3.),
		new TRectangular(7., 3.),
		new TSquare(12.),
		new TRectangular(7., 9.),
		new TSquare(2.),
		new TRectangular(8., 3.),
		new TRectangular(2., 3.)
	};

	// сортировка массива указателей, но в компараторе сравниваем два объекта
	// по заданному критерию
	qsort(trects, N_TRIANGLES, sizeof(TRect*), TRect::compare);

	cout << "\nОтсортировано по возрастанию площадей:\n";
	for (int i = 0; i < N_TRIANGLES; ++i)
		trects[i]->show();

	delete[] trects;
} // App::point3

void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "К сведению", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  Нажмите любую клавишу для продолжения...");

	cout << pos(0, 5) << msg << endlm(4);
} // App::showMsg

