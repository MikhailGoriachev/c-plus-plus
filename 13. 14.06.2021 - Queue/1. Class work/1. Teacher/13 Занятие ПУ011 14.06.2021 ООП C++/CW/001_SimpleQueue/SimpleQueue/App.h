#pragma once
#include "pch.h"
#include "Queue.h"

// Проверка очереди
class App
{
	Queue queue_;

public:
	
	void checkEnqueue();
	void checkEnqueueAll();
	void checkDequeue();
	void checkMisc();
	void checkClear();
	
	// 
	void showMsg(const char *msg = "\nРабота приложения...\n") const;

};

