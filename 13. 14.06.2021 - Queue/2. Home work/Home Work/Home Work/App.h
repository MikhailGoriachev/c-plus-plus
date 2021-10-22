#pragma once
#include "pch.h"
#include "Utils.h"
#include "QueueDbl.h"
#include "QueuePlane.h"
#include "Plane.h"

/*
	����������� ���������� � �������������� ���� ��� ����������� ������ � ��������.
	������������ ����� ������� QueueDbl (�� ������ ������ Queue� ��������� �������,
	�� �������� ������) ��� �������� ����� ���� double. ����� ������������ �����
	������� QueuePlane ��� �������� �������� ������ Plane. ����������� ������������
	������ ��� ���������� ������, ������ ������� �������� � ������������ � ��
	�������� �� ����� ������.
	�	������ 1. ���� ��� �������� ������� ������������ (double) �����, �����������
		���������� ����������. ����������� ��� �������� �� ������ ������� �� ������
		(� ���������� �������� ������ ������� ����� ������������� �� ������ �������
		� �������� �������).
	�	������ 2. ���� ��� �������� ������� ������������ (double) �����, �����������
		���������� ����������. ���������� �������� �� ������ ������� �� ������, ����
		�������� ������� �������� ������ ������� �� ������ �������������
		(������������ �������� ������ ������� ����� ������������� �� ������ �������
		� �������� �������). ���� � ������ ������� ��� ��������� � ��������������
		����������, �� ����������� �� ������ ������� �� ������ ��� ��������.
	�	������ 3. ���� �������� ������� ������������ (double) �����, �����������
		���������� ����������. ������� ��� ����� �������, ���������� � ������ �� ���
		��� �������� �������� ������� � �������������� ����������, � �� ������ � �
		�������������� (�������� � ����� �������� ����� ������������� � ��������
		�������; ���� �� ���� �������� ����� ��������� ������).
	�	������ 4. ���� �������� ������� QueuePlane. ����������� �� ���� ������� �
		����� ������� ��� �������� � �������� � ���������� ���������� �������
		��������. �������� ������� �� ������ ����������.����� ������������
		��������������� ������� � ������������ ����������.
*/

class App
{
public:

#pragma region ������������, ���������� � ���������� �������� ������������

	// ����������� �� ���������
	App() = default;

	// ���������� ����������� 
	App(const App& app) = default;

	// ���������� 
	~App() = default;

	// ���������� �������� ������������
	App& operator=(const App& app) = default;

#pragma endregion

#pragma region ������� 

#pragma region ������� 1

	// ������ 1. ����������� ��������� �� ����� ������� �� ������
	void task1();
	
	// ����������� ��������� 
	void task1Insert(QueueDbl& source, QueueDbl& dest);

#pragma endregion

#pragma region ������� 2

	// ������ 2. ����������� �� �������������� ��������
	void task2();	

	// ����������� ��������� 
	void task2Insert(QueueDbl& source, QueueDbl& dest);

#pragma endregion

#pragma region ������� 3

	// ������ 3. ���������� ������� �� ������������� � �������������
	void task3();

	// ����������� ��������� � ��� �������: ������������� � �������������
	void task3Insert(QueueDbl& source, QueueDbl& neg, QueueDbl& pos);

#pragma endregion

#pragma region ������� 4
	// ������ 4. ����������� �������� �� ��������� ������� ��������
	void task4();

	// ����������� ��������� �� ��������� ��������� �����
	void task4Insert(QueuePlane& source, QueuePlane& dest, int min, int max);

#pragma endregion

#pragma endregion

#pragma region ������

	// ���������� ������� (double), n - ���������� ����������� ���������
	void fillQueueDbl(QueueDbl& queueDbl, int n);

	// ���������� ������� (Plane), n - ���������� ����������� ���������
	void fillQueuePlane(QueuePlane& queuePlane, int n);

	// ��������� ������� 
	Plane genPlane();

#pragma endregion
};
