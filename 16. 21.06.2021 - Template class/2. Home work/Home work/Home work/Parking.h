#pragma once

#include "Stack.h"
#include "Car.h"
/*
	��� ������ ���������� ������ Stack (� ������������ �� ������� ������
	������� �� 12 ���������) ��� ������������� ����� ��������, ������ ������
	������������� �������� ����������� � ��������, � ������� � ������������ �����.
	 
	���������� ����� ��������� �� �������� ������ � ������ ����������� ������,
	���������� ����� ���������� � �������������� � ������ ������. �� ��������� 
	����� �������� ���������� � ������������ �������. ��� ����� ������ � ������ 
	����������� ������ ������������ �� ���������� ������, �� ������, ������� 
	��������� �������. ��� ������ �������� ����������� ������, ����� ������ � 
	���������� ������ ������������ �� �����������. 

	� ������ Parking ���������� ������ ���������� ���������� �� ��������,
	������� ������������� ���������� � ��������.
*/

// ����� ��������
class Parking
{
public:

	// ���������� ���� ��� ��������
	static const int PARK_PLACE_MAX = 12;

private:

	// ������ ��������
	Stack<Car> parkLane_;

	// ������ ��������
	Stack<Car> manLane_;

public:

#pragma region ������������, ���������� � �������� ������������

	// ����������� �� ���������
	Parking() = default;

	// ����������� ���������������� (�� ���� ������� Car)
	Parking(Car* car, int n)
	{
		// ���� ����� ������� ������ ��� ����� ����
		if (n <= 0)
			throw exception("Parking: ������ ������� ����������� ������ ���� ������ ����!");

		parkLane_.pushAll(car, n);
	}

	// ����������� ����������
	Parking(const Parking& parking) = default;

	// ���������� 
	~Parking() = default;

	// ���������� �������� ������������
	Parking& operator=(Parking& parking) = default;

#pragma endregion

#pragma region ������

	// �������� ����������
	void push(Car car);
	
	// �������� ������ �����������
	void pushAll (Car* car, int n);

	// ������� ��������� ����������
	Car pop();

	// ������� ����� ���������� 
	Car popAny(int index);

	// ������� ��� ����������
	void clear();

	// ����� ����������� � �����
	void showColor();

	// ����� ����� ���������� � ���� �� �������� ����� 
	short colorCar(char* color);

	// ���������� ����� �� ������ ��������
	int getCounterPark() { return parkLane_.getCounter(); }

	// ���������� ����� �� ������ ��������������
	int getCounterMan() { return manLane_.getCounter(); }

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, Parking& park);

#pragma endregion
};
