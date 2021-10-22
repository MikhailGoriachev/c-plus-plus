g#include "App.h"
#include "Utils.h"

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


// ��������� ����� ������
void App::genData()
{
	cls();

	showNavBarMessage(hintColor, "��������� ����� ������");

	cputs("\n\t��������������������������������������� ����� ������ ��������������������������������������\n\n", YELLOW_ON_BLACK);

	// �������� ������ �� ������� ������
	list_.clear();

	// �������� ������
	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		delete[] figures_[i];
	}

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

	// ����������� ������ ��������� �������� ��� ������������ 
	list_.addAll(figures_, SIZE_ARRAY);

	// ����� ������ �� ����������
	showTable(list_);

	cout << "\n\n\n";

	getKey();
}

// ����� ������ ����������� ������ � ���� �������
void App::showTable(const DblList<Body*>& list)
{
	// ����� ����� �������
	Body::showHead();

	// ���� ������ ����
	if (list.isEmpty())
		cout << "\t|                                        ��� ������                                         |\n";

	else
	{
		// �������� ��� ������ 
		DblList<Body*>::Iterator<Body*> iterator(list);

		// ����� ����������� � �������
		for (iterator.begin(); iterator != iterator.end(); ++iterator)
		{
			(*iterator)->show();
		}
	}
}

// ���������� �� �������� ������� 
void App::sortByValume()
{
	cls();

	showNavBarMessage(hintColor, "���������� �� �������� ������� ");

	cputs("\n\t�������������������������������������� �� ���������� ��������������������������������������\n\n", YELLOW_ON_BLACK);

	// ����� ������ �� ����������
	showTable(list_);

	// ���������� �������
	qsort(figures_, SIZE_ARRAY, sizeof(Body*), Body::compare);

	// �������� ������ �� ������� ������
	list_.clear();

	// ����������� ������ ��������� �������� ��� ������������ 
	list_.addAll(figures_, SIZE_ARRAY);

	cputs("\n\t������������������������������������ ����� ���������� �������������������������������������\n\n", YELLOW_ON_BLACK);

	// ����� ������ �� ����������
	showTable(list_);

	getKey();
}

// ����� ������
void App::printData()
{
	cls();

	showNavBarMessage(hintColor, "����� ������");

	cputs("\n\t������������������������������������������ ������ �����������������������������������������\n\n", YELLOW_ON_BLACK);

	// ����� ������ �� ����������
	showTable(list_);

	cout << "\n\n\n";

	getKey();
}