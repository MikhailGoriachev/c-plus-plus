#pragma once
#include "List.h"
#include "pch.h"

// Изучение итераторов
class App
{
	// список для изучения
	List<char> list_;


public:
	App() {  }
	App(List<char> list): list_(list) {}
	App(const App& app) = default;
	~App() = default;
	App &operator=(const App& app) = default;
	
	// проверка работы методов списка
	void checkListMethods();

	// проверка работы итератора по списку List
	void checkListIterator();

	// проверка работы итератора по стеку Stack
	void checkStackIterator();
	
	// вывод сообщения в строку
	void showMsg(const char *msg = "\nРабота приложения...\n") const;

};

