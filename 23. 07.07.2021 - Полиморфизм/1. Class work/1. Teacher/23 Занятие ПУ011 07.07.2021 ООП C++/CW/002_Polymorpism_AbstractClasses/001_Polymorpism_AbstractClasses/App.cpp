#include "pch.h"
#include "Utils.h"
#include "App.h"

#include "Equilateral.h"
#include "Rectangular.h"
#include "TRectangular.h"
#include "Triangle.h"
#include "TSquare.h"

// ����������� ������
void App::point1()
{
	const int N_TRIANGLES = 7;
	// ������ ���������� �� ������� ����� - �����������
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


// ����������� ������
void App::point2()
{
	TSquare tSquare(10);
	cout<< "\n\n�������, ��� ���������� ���������� ������������ ������:\n"
	    << tSquare << "\n\n";

	TRectangular tRectangular(10., 20.);
	cout<< "�������������, ��� ���������� ���������� ������������ ������:\n"
	    << tRectangular << "\n\n";
} // App::point2


// ���������� ������� ������������ ������
void App::point3()
{

	// ������ ���������� �� ������� ����� - �����������
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

	// ���������� ������� ����������, �� � ����������� ���������� ��� �������
	// �� ��������� ��������
	qsort(triangles, N_TRIANGLES, sizeof(Triangle *), Triangle::compare);

	cout << "\n������������� �� ����������� �������� �������������:\n";
	for (int i = 0; i < N_TRIANGLES; ++i)
		triangles[i]->show();

	delete[] triangles;

	// ������ ���������� �� ����������� ����� - �����������
	TRect** trects = new TRect* [N_TRIANGLES] {
		new TSquare(3.),
		new TRectangular(7., 3.),
		new TSquare(12.),
		new TRectangular(7., 9.),
		new TSquare(2.),
		new TRectangular(8., 3.),
		new TRectangular(2., 3.)
	};

	// ���������� ������� ����������, �� � ����������� ���������� ��� �������
	// �� ��������� ��������
	qsort(trects, N_TRIANGLES, sizeof(TRect*), TRect::compare);

	cout << "\n������������� �� ����������� ��������:\n";
	for (int i = 0; i < N_TRIANGLES; ++i)
		trects[i]->show();

	delete[] trects;
} // App::point3

void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "� ��������", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  ������� ����� ������� ��� �����������...");

	cout << pos(0, 5) << msg << endlm(4);
} // App::showMsg

