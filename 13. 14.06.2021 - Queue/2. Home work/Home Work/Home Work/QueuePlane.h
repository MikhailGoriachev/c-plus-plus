#pragma once

#include "pch.h"
#include "Plane.h"
#include "QueuePlane.h"

// ������� Plane
class QueuePlane
{
public:

	// ������ ������� �� ���������
	static const int SIZE_DEFAULT = 10;

private:

	// ������
	int front_;

	// �����
	int back_;

	// ������ ������� Plane
	int size_;

	// ������ Plane
	Plane* data_;

	// ������� ������ �������
	int counter_;

public:

#pragma region ������������ � ���������� 

	// ����������� �� ���������
	QueuePlane() : front_(), back_(), size_(SIZE_DEFAULT), data_(new Plane[SIZE_DEFAULT]), counter_() {};

	// ���������������� ����������� 
	explicit QueuePlane(int size);

	// ���������� �����������
	QueuePlane(const QueuePlane& queuePlane);

#pragma endregion

#pragma region ������� � �������

private:
	// ������ size_
	void setSize(int size);

public:

	// ������ size_
	int getSize() const;

	// ������ counter_
	int getCounter() const;

#pragma endregion

#pragma region ������

	// ���������� �������� ������������ 
	QueuePlane& operator=(const QueuePlane& queuePlane);

	// ���������� � ������� �������� 
	void enqueue(Plane plane);

	// ���������� � ������� ������� 
	void enqueueAll(Plane* planeArr, int size);

	// �������� ������ �������
	Plane front() const;

	// �������� ����� �������
	// Plane back() const;

	// ������ �������� � ������ �������
	Plane dequeue();

	// �������� �������
	void clear();

	// ����������� �������
	bool isEmpty() const;

	// ������������ �������
	bool isFull() const;

#pragma endregion

#pragma region ������������� �������

	// ���������� ������ 
	friend ostream& operator<<(ostream& os, QueuePlane& queuePlane);

#pragma endregion
};

