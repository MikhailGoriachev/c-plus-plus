#pragma once
#include "pch.h"

// полиморфные классы, абстрактные классы
class App
{
public:

	// полимофрные классы
	void point1();

	// абстрактные классы
	void point2();

	// сортировка массива полиморфного класса
	void point3();

	// сообщение в строку
	void showMsg(const char *msg = "\nРабота приложения...\n") const;

};

