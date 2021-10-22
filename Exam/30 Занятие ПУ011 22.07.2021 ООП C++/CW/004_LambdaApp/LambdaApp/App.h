#pragma once
#include "pch.h"
#include "Bus.h"

// ��������� ������� ����� ����� � ������� ������ �� ����������
class App
{
	static void showVectorPositive(const string &title, const vector<double> &v);
	static void showVectorNegative(const string& title, const vector<double>& v);
	
	static void saveVector(const string &fileName, vector<double> &v);
	static void loadVector(const string &fileName, vector<double>& v);

	// ----------------------------------------------------------------------------------

	// ��������� ���������
	vector<Bus> buses_;

	// ��� ����� ��� ��������� ���������
	string fileName_;

	void showBuses(const vector<Bus>& buses, const string& title);

	// �������� ��������� ��������� �� ������
	void loadFromStream();

	// ���������� ��������� ��������� � �����
	void saveToStream();

	// ��������� ������������ ��������� ���������
	void initialize();

	// �������� ������������� �����
	static bool fileExists(const string& fileName);

public:
	App():App("buses.txt") {}
	App(const string& fileName)
	{
		fileName_ = fileName;
	} // App
	
	// ��������� ������� ��� ������ ��������� ���������
	void demoVector();
	
	// ������ ������ �� ��������� � ��������� ���� (��������������� ����� ������)
	void demoInitializeAndWrite();

	// ������ ������ �� ��������� �� ���������� ����� (���������������� ������ �����)
	void demoReadAndShow();

	// ����� ������ �� ��������� ��� ������ ��������� for_each() � ������-���������
	void demoShowBuses();
	
	// ����������� ��������� ��������� �� ��������������� �������, ������������ sort()
	void demoOrderByRegNumber();
	
	// ����������� ��������� ��������� �� ������� � ��������� ��������, ������������ sort()
	void demoOrderByFullName();



	
};

