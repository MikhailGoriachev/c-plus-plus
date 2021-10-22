#include "pch.h"
#include "Utils.h"
#include "App.h"

void App::checkEnqueue()
{
	showNavBarMessage(hintColor, "   Проверка операции enqueue()");

	cout << "\n\n\n\n    Очередь  " << queue_ << "\n";

	while (!queue_.isFull()) {
		int t = getRand(-100, 100);
		queue_.enqueue(t);
		cout << "    Очередь  " << queue_ << " | " << t << "\n";
	} // while

	cout << "    Очередь  " << queue_ << "\n";
}

void App::checkEnqueueAll()
{
	showNavBarMessage(hintColor, "   Проверка операции enqueueAll()");

	int data[]{ 33, 55, 66, 99, -100 };
	
	cout << "\n\n\n\n    Очередь  " << queue_ << "\n";

	queue_.enqueueAll(data, sizeof(data)/sizeof(int));

	cout << "    Очередь  " << queue_ << "\n";
}


// Проверка операции dequeue()
void App::checkDequeue()
{
	showNavBarMessage(hintColor, "   Проверка операции dequeue()");

	cout << "\n\n\n\n    Очередь  " << queue_ << "\n";

	while(!queue_.isEmpty()) {
		int t = queue_.dequeue();
		cout << "    Очередь  " << queue_ << " | " << t << "\n";
	} // while
	
	cout << "    Очередь  " << queue_ << "\n";
}

void App::checkMisc()
{
	showNavBarMessage(hintColor, "   Проверка операций front(), back()");

	cout << "\n\n\n\n    Очередь  " << queue_ << "\n";

	int f = queue_.front();
	int b = queue_.back();

	cout << "    Первый  " << f << ", последний " << b << "\n";
}

// проверка очистки очереди
void App::checkClear()
{
	showNavBarMessage(hintColor, "   Проверка операции checkClear()");
	
	cout << "\n\n\n\n    Очередь до очистки    " << queue_ << "\n";
	queue_.clear();
	cout << "    Очередь после очистки " << queue_ << "\n";
}

void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "К сведению", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  Нажмите любую клавишу для продолжения...");

	cout << "\n\n\n\n" << msg << "\n\n\n\n";
} // App::showMsg

