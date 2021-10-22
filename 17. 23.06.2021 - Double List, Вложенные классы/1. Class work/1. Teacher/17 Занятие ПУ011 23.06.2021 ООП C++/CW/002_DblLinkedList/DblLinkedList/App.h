#pragma once
#include "DblList.h"

class App
{
	DblList<int> dblList_;

public:
	App() = default;
	App(const App &app) = default;
	~App() = default;
	App& operator=(const App& app) = default;
	
	// �������� ������ add()
	void testAdd();
	
	// �������� ������ insert()
	void testInsert();
	
	// �������� ������� get(), put()
	void testGetPut();
	
	// �������� ������ removeAt()
	void testRemoveAt();
	
	// �������� ������ clear()
	void testClear();
};

