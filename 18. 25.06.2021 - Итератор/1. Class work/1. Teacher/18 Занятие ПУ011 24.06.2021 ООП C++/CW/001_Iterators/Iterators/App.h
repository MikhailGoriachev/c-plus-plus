#pragma once
#include "List.h"
#include "pch.h"

// �������� ����������
class App
{
	// ������ ��� ��������
	List<char> list_;


public:
	App() {  }
	App(List<char> list): list_(list) {}
	App(const App& app) = default;
	~App() = default;
	App &operator=(const App& app) = default;
	
	// �������� ������ ������� ������
	void checkListMethods();

	// �������� ������ ��������� �� ������ List
	void checkListIterator();

	// �������� ������ ��������� �� ����� Stack
	void checkStackIterator();
	
	// ����� ��������� � ������
	void showMsg(const char *msg = "\n������ ����������...\n") const;

};

