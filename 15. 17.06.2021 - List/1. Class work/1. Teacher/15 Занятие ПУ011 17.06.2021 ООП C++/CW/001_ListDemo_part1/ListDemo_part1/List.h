#pragma once
#include "pch.h"
#include "Node.h"

// односвязный список
class List
{
	Node* head_;    // указатель на голову списка
	int counter_;   // счетчик элементов в списке

public:
	List():head_(), counter_() {  }
	List(const List& list);
	~List() { clear(); }
	List& operator=(const List& list);
	
	
	// CRUD - create read update delete
	// C - create: добавление узла в список
	// добавление в конец списка
	void add(int value);
	
	// вставка перед заданной позицией
	void insert(int position, int value);

	// R - read: чтение значения узла списка
	int get(int position);
	
	// U - update: запись значения в узел списка
	void put(int position, int value);

	// D - delete: удаление узла списка
	void removeAt(int position);

	// ----------------------------------------
	int getCount() const { return counter_; }

	void clear();
	
	friend ostream& operator<<(ostream& os, const List& list);
};

