#include "pch.h"
#include "Utils.h"
#include "App.h"

void App::checkEnqueue()
{
	showNavBarMessage(hintColor, "   �������� �������� enqueue()");

	cout << "\n\n\n\n    �������  " << queue_ << "\n";

	while (!queue_.isFull()) {
		int t = getRand(-100, 100);
		queue_.enqueue(t);
		cout << "    �������  " << queue_ << " | " << t << "\n";
	} // while

	cout << "    �������  " << queue_ << "\n";
}

void App::checkEnqueueAll()
{
	showNavBarMessage(hintColor, "   �������� �������� enqueueAll()");

	int data[]{ 33, 55, 66, 99, -100 };
	
	cout << "\n\n\n\n    �������  " << queue_ << "\n";

	queue_.enqueueAll(data, sizeof(data)/sizeof(int));

	cout << "    �������  " << queue_ << "\n";
}


// �������� �������� dequeue()
void App::checkDequeue()
{
	showNavBarMessage(hintColor, "   �������� �������� dequeue()");

	cout << "\n\n\n\n    �������  " << queue_ << "\n";

	while(!queue_.isEmpty()) {
		int t = queue_.dequeue();
		cout << "    �������  " << queue_ << " | " << t << "\n";
	} // while
	
	cout << "    �������  " << queue_ << "\n";
}

void App::checkMisc()
{
	showNavBarMessage(hintColor, "   �������� �������� front(), back()");

	cout << "\n\n\n\n    �������  " << queue_ << "\n";

	int f = queue_.front();
	int b = queue_.back();

	cout << "    ������  " << f << ", ��������� " << b << "\n";
}

// �������� ������� �������
void App::checkClear()
{
	showNavBarMessage(hintColor, "   �������� �������� checkClear()");
	
	cout << "\n\n\n\n    ������� �� �������    " << queue_ << "\n";
	queue_.clear();
	cout << "    ������� ����� ������� " << queue_ << "\n";
}

void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "� ��������", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  ������� ����� ������� ��� �����������...");

	cout << "\n\n\n\n" << msg << "\n\n\n\n";
} // App::showMsg

