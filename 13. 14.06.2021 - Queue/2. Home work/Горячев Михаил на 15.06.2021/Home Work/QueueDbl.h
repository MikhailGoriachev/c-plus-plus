#pragma once

#include "pch.h"
#include "utils.h"

// ������� double 
class QueueDbl
{
public:

	// ����� ������� �� ���������
	static const int SIZE_DEFAULT = 10;

private:

	// ������ ������ 
	int front_;

	// ������ �����
	int back_;

	// ��������� �� ������ double 
	double* data_;

	// ������� ��������� � �������
	int counter_;

	// ����� ������� 
	int size_;

public:

#pragma region ������������ � ����������

	// ����������� �� ���������
	QueueDbl() :front_(), back_(), data_(new double[SIZE_DEFAULT]), counter_(), size_(SIZE_DEFAULT) {};

	// ����������� ����������������
	explicit QueueDbl(int size);

	// ���������� ����������� 
	QueueDbl(const QueueDbl& queueDbl);

	// ���������� 
	~QueueDbl();

#pragma endregion

#pragma region ������� � �������

private:

	// ������ size_
	void setSize(int size);

public:

	// ������ size_
	int getSize() const { return size_; }

	// ������ counter_
	int getCounter() const { return counter_; }

#pragma endregion

#pragma region ������ 

	// ���������� �������� ������������ 
	QueueDbl& operator=(const QueueDbl& queueDbl);

	// ���������� �������� � �������
	void enqueue(double value);

	// ���������� ������� � �������
	void enqueueAll(double* arr, int size);

	// �������� �������� ������� �������
	double front() const;

	// �������� �������� ����� �������
	double back() const;

	// ������ �������� �� �������
	double dequeue();

	// �������� �������
	void clear();

	// ����������� �������
	bool isEmpty() const;

	// ������������ �������
	bool isFull() const;

#pragma endregion

#pragma region ������������� �������
	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const QueueDbl& queueDbl);

	// ����� ���������
	friend ostream& showElem(ostream& os, const QueueDbl& queueDbl);

	// ����� �������������� �����
	friend ostream& showLine(ostream& os, const QueueDbl& queueDbl);

	// ����� ������� ���������
	friend ostream& showIndex(ostream& os, const QueueDbl& queueDbl);

	// ����� ������������� �������
	friend ostream& showSize(ostream& os, const QueueDbl& queueDbl);

	// ����� ���������� ���������
	friend ostream& showCounter(ostream& os, const QueueDbl& queueDbl);
#pragma endregion
};