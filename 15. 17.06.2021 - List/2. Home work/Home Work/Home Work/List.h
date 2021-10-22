#pragma once

#include "Node.h" // ����� ���� ������ (int)

// ����� ������ (int)
class List
{
	// ������� ����� � ������ 
	int counter_;

	// ����� ���������� �������� ������ 
	Node* head_;

public:

#pragma region ������������ � ����������� 

	// ����������� �� ��������� 
	List() : counter_(), head_() { };

	// ����������� ����������������
	List(int counter);

	// ����������� ��������� ������ �� ���� ������� 
	List(int* arr, int counter);

	// ����������� ����������
	List(const List& list);

	// ���������� 
	~List() { clear(); }

#pragma endregion

	// ���������� �������� ������������ 
	List& operator=(const List& list);

	// ���������� ���� � ����� ������ 
	void add(int value);

	// ���������� ������� ����� � ����� ������ 
	void addAll(int* data, int n);

	// ������� ���� ����� ��������� ��������
	void insert(int position, int value);

	// ������� ������� ����� ����� ��������� ��������
	void insertAll(int position, int* data, int n);

	// ������ �������� ���� ������ �� ��������� �������
	int get(int position);

	// �������� �������� ���� ������ �� ��������� ������� 
	void put(int position, int value);

	// �������� ���� �� ������ �� ��������� ������� 
	void removeAt(int position);

	// �������� ������ 
	void clear();

	// ������ counter_
	int getCounter() { return counter_; }

	// ���������� �������� [] ��� ������� � ���� ������ �� �������
	Node* operator[](int position);

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, const List& list);

	// ����� ���������
	friend ostream& showElem(ostream& os, const List& list);

	// ����� �������������� �����
	friend ostream& showLine(ostream& os, const List& list);

	// ����� ������� ���������
	friend ostream& showIndex(ostream& os, const List& list);

	// ����� ���������� ���������
	friend ostream& showCounter(ostream& os, const List& list);

	// ����� ������ � �����
	void showListColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr);

private:
	// ����� ��������� � �����
	void showElemColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr);

public:

};

