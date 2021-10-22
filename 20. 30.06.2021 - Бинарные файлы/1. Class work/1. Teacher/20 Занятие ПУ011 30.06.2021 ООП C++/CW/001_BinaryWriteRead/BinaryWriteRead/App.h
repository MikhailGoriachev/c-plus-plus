#pragma once
#include "pch.h"
#include "DblList.h"
#include "Utils.h"
#include "Person.h"

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
	DblList<Person> list_;

	

public:

	// TODO: убрать в рабочем проекте
	void task1();
	void task2();
	void ReadWritePersons();
};