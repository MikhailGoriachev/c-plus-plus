#pragma once
#include "pch.h"
#include "DblList.h"
#include "Utils.h"
#include "Person.h"

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
	DblList<Person> list_;

	

public:

	// TODO: ������ � ������� �������
	void task1();
	void task2();
	void ReadWritePersons();
};