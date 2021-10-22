#pragma once
#include "pch.h"

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
public:

	// TODO: можете убрать в рабочем проекте
	void showMsg(const char *msg = "\nРабота приложения...\n") const;

	// проверяемые стеки 
	void checkStack();
	void checkStackTriangle();
	void task();
};

