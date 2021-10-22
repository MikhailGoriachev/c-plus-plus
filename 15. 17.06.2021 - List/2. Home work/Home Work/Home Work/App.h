#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "List.h"
#include "Plane.h"
#include "ListPlane.h"

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
public:

#pragma region ������� 1

	// ���� ������� 1
	void task1();
	
	// ������� �������� � ������ ����� �������� 
	void task1Insert();

	// ���������� ��� ������ � ����� ��� �������
	friend bool task1InsertPred(int currentPosition, int* posArr, int sizePosArr);

	// ����������� �������� �������� ������ �� �������� �������
	void task1Get();
	
	// ������ �������� � �������� ������� ������
	void task1Put();

	// ���������� ������� � ����� ������
	void task1AddAll();

	// ������� ������� ����� �������� 
	void task1InsertAll();

	// ��������� ������� (int)
	int* getArrayRandom(int size, int min, int max);

	// ���������� ������� ������ ��� ������� (int)
	void showArrInt(int* arr, int size);

#pragma endregion

#pragma region ������� 2

	// ���� ������� 2
	void task2();

	// ������� �������� � ������ ����� �������� 
	void task2Insert();

	// ����������� �������� �������� ������ �� �������� �������
	void task2Get();

	// ������ �������� � �������� ������� ������
	void task2Put();

	// ���������� ������� � ����� ������
	void task2AddAll();

	// ������� ������� ����� �������� 
	void task2InsertAll();

	// ��������� ������� 
	Plane genPlane();

	// �������� ���������� ������� (Plane)
	Plane* fillArrPlane(int size);

#pragma endregion



};

