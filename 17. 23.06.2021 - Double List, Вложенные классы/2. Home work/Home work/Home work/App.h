#pragma once
#include "pch.h"
#include "Utils.h"
#include "Deque.h"
#include "Car.h"

/*
	�� �������� � ��������� ������� Deque �� ����������� ������� (�� ���� ������������
	������ ������� List) ������������ ��������� ����� Deque �� ���������������� ������
	DblList �� �������� ������.

	������������ ���������� ����������, � ������� ����������������� ��� �������� � ����
	����� ��� ����� int, char, Car (�� ������ � ��������, ���� ������ � ���������������
	�����, ����, �����).
*/

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
public:

	// ���� �������
	template<typename T>
	void demo(Deque<T> deq, T* arrFill, int sizeDillArr, T* arrAdd, int sizeAddArr, T add, T ins, T* arrIns, int sizeInsArr);

	void intDemo();
	void charDemo();
	void carDemo();

	// ��������� ����������
	Car genCar();
};

