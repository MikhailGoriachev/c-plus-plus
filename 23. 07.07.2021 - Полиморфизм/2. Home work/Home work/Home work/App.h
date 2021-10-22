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
	*	������������ �������� ������� ��� ������������� �������� �����. �������
			����������� ����� Body � ������� ������������ �������� ��� ���������� 
			������� �����������, ������ ������, ������ ������ �� ������ � ��������� 
			����� �� ������.
	*	���������� ������ ��� ������������� �����, ����, ������ � ��������. 
	*	���������� ������� ���� ������� � ������� ���������� �� ������� �����.
			������������ ������ ����������� �������� qsort() �� �������� �������.
			��������� ��������� ����� ���������� ������ ������� ���������������� 
			�������, � ����� ������ ������� ��������� �� ������� �����. �������� 
			������ ����� �� ������ ��� ������ ���������.
*/

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
	// ���������� ������ �����
	DblList<Body*> list_;

	// ������ �����
	Body** figures_;

	// ������ �������
	static const int SIZE_ARRAY = 8;

public:

	// ����������� �� ���������
	App()
	{
		// ������ �����
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

		// �������� ������
		// for (int i = 0; i < SIZE_ARRAY; i++)
		// {
		// 	delete[] figures_[i];
		// }
	}

	// ���������� 
	~App()
	{
		// �������� ������ �� ������� ������
		list_.clear();

		// �������� ������
		for (int i = 0; i < SIZE_ARRAY; i++)
		{
			delete[] figures_[i];
		}

		delete[]figures_;
	}

#pragma region �������

	// ��������� ����� ������
	void genData();

	// ���������� �� �������� ������� 
	void sortByValume();

	// ����� ������
	void printData();

	// ����� ������ ����������� ������ � ���� �������
	void showTable(const DblList<Body*>& list);

#pragma endregion

};

