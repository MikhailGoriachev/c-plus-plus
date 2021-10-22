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
	
	// Проверка метода add()
	void testAdd();
	
	// Проверка метода insert()
	void testInsert();
	
	// Проверка методов get(), put()
	void testGetPut();
	
	// Проверка метода removeAt()
	void testRemoveAt();
	
	// Проверка метода clear()
	void testClear();
};

