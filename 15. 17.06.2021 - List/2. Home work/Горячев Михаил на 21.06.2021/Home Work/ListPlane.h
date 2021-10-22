#pragma once
#include "NodePlanec.h"


class ListPlane
{
	// ��������� ���� ������ 
	NodePlanec* head_;

	// ������� ���������� ����� ������ 
	int counter_;

public:

#pragma region ������������� � ���������� 

	// ����������� �� ���������
	ListPlane() : head_(), counter_() {}

	// ����������� ����������������
	ListPlane(int counter);

	// ����������� ��������� ������ �� ���� ������� 
	ListPlane(Plane* arr, int counter);

	// ����������� ����������
	ListPlane(const ListPlane& listPlane);

	// ���������� 
	~ListPlane() { clear(); }

#pragma endregion

#pragma region ������

	// ���������� ���� � ����� ������ 
	void add(Plane plane);

	// ���������� ������� � ����� ������ 
	void addAll(Plane* arrPlanes, int size);

	// ������� ����� ��������� ��������
	void insert(int position, Plane& plane);

	// ������� ������� ����� ��������� �������� 
	void insertAll(int position, Plane* arrPlanes, int size);

	// ��������� �������� ���������� ���� 
	void put(int position, Plane& plane);

	// ��������� �������� ���������� ���� 
	Plane get(int position);

	// �������� ���������� ���� �� ������ �� �������
	void removeAtt(int position);

	// �������� ������ 
	void clear();

	// ������ coutner_
	int getCounter() { return counter_; }

	// ���������� �������� []
	NodePlanec* operator[](int position);

	// ���������� ������������ 
	ListPlane& operator=(const ListPlane& listPlane);

#pragma endregion

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const ListPlane& listPlane);

	// ����� � �����
	void showListPlaneColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr);

};

