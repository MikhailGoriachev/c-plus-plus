#include "pch.h"
#include "Utils.h"
#include "App.h"

// �������� ������ add()
void App::testAdd()
{
	showNavBarMessage(hintColor, "  DblLinkedList: �������� ������ add()");
	static int i;
	cout << "\n\n\n\n";
	
	// �������� �������� � ����� ������
	for (int k = 0; k < 5; ++i, ++k)
		dblList_.add(i);
	cout << "    DblLyst: " << dblList_ << "\n\n\n";
	
} // App::testAdd

// �������� ������ insert()
void App::testInsert()
{
	showNavBarMessage(hintColor, "  DblLinkedList: �������� ������ insert()");
	cout << "\n\n\n\n";
	
	cout << "    DblLyst: " << dblList_ << "\n\n\n";
	int t = 73;
	dblList_.insert(0, t);
	cout << "    DblLyst: " << dblList_ << " | " << t << "\n";

	t = 42;
	int n = (dblList_.getCounter() - 1) / 2;
	dblList_.insert(n, t);
	cout << "    DblLyst: " << dblList_ << " | " << t << "\n";

	t = 88;
	n = dblList_.getCounter() - 1;
	dblList_.insert(n, t);
	cout << "    DblLyst: " << dblList_ << " | " << t << "\n\n\n";
} // App::testInsert

// �������� ������� get(), put()
void App::testGetPut()
{
	showNavBarMessage(hintColor, "  DblLinkedList: �������� ������� get(), put()");
	cout << "\n\n\n\n";
	
	cout << "    DblLyst: " << dblList_ << "\n\n\n";

	int n = dblList_.getCounter() - 1;
	cout<< "    t(0): " << dblList_.get(0)
		<< "    t(" << n << "): " << dblList_.get(n)
	    << "\n";

	dblList_.put(0, 11);
	dblList_.put(n, 99);
	cout << "    DblLyst: " << dblList_ << "\n\n\n";
} // App::testGetPut

// �������� ������ removeAt()
void App::testRemoveAt()
{
	showNavBarMessage(hintColor, "  DblLinkedList: �������� ������ removeAt()");
	cout << "\n\n\n\n";

	cout << "    DblLyst: " << dblList_ << "\n\n\n";

	int t = dblList_.removeAt(0);
	cout << "    DblLyst: " << dblList_ << " | " << t << "\n";

	int n = (dblList_.getCounter() - 1) / 2;
	t = dblList_.removeAt(n);
	cout << "    DblLyst: " << dblList_ << " | " << t << "\n";

	n = dblList_.getCounter() - 1;
	t = dblList_.removeAt(n);
	cout << "    DblLyst: " << dblList_ << " | " << t << "\n\n\n";
} // App::testRemoveAt

// �������� ������ clear()
void App::testClear()
{
	showNavBarMessage(hintColor, "  DblLinkedList: �������� ������ clear()");
	cout << "\n\n\n\n";

	
	cout << "    DblLyst: " << dblList_ << "\n";
	dblList_.clear();
	cout << "    DblLyst: " << dblList_ << "\n\n\n";
} // App::testClear
