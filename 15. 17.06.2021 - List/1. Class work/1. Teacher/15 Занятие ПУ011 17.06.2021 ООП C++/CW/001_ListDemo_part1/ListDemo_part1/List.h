#pragma once
#include "pch.h"
#include "Node.h"

// ����������� ������
class List
{
	Node* head_;    // ��������� �� ������ ������
	int counter_;   // ������� ��������� � ������

public:
	List():head_(), counter_() {  }
	List(const List& list);
	~List() { clear(); }
	List& operator=(const List& list);
	
	
	// CRUD - create read update delete
	// C - create: ���������� ���� � ������
	// ���������� � ����� ������
	void add(int value);
	
	// ������� ����� �������� ��������
	void insert(int position, int value);

	// R - read: ������ �������� ���� ������
	int get(int position);
	
	// U - update: ������ �������� � ���� ������
	void put(int position, int value);

	// D - delete: �������� ���� ������
	void removeAt(int position);

	// ----------------------------------------
	int getCount() const { return counter_; }

	void clear();
	
	friend ostream& operator<<(ostream& os, const List& list);
};

