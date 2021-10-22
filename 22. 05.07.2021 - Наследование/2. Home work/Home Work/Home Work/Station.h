#pragma once

#include "pch.h"
#include "Utils.h"
#include "BinaryTree.h"
#include "Subscriber.h"


// �������� ������
// template <typename T>
// class BinaryTree;

// ����� ����������� ��������
// class Subscriber;


// ����������� ����� ��� ������������� ���������� ������� � ������ ��� ��������
// �������� ���������� �������(��� ������� � ��� �������� �������), ������� �����
// �� ������ ��������� ��������, ��������� ��������� � ���� ��������� ������ ������.
// ������ ��� ����� �������� ���������� ����� ��������.
// 

// ����� ���������� ������� 
class Station
{
public:


	// ������ ���� �������� ���������� �������
	static const int NAME_SIZE = 3;

	// ������������ ����� �� ������ ���������
	static const float RATE_MAX;

	// ����������� ����� �� ������ ���������
	static const float RATE_MIN;

private:

	// �������� ���������� ������� (��� ������� � ��� �������� �������)
	char* name_;

	// ������� ����� �� ������ ��������� ��������
	float rate_;

	// ��������� ��������� � ���� ��������� ������ ������
	BinaryTree<Subscriber> subscribers_;

public:

#pragma region ������������, ����������, ���������� �������� ������������

	// ����������� �� ���������
	Station() : Station("000", 0, nullptr, 0) {}

	// ���������������� �����������
	Station(const char* name, float rate, Subscriber* arr, int n) :
		name_(new char[NAME_SIZE + 1]{ 0 })
	{
		setName(name);
		setRate(rate);

		subscribers_.addAll(arr, n);
	}

	// ���������� �����������
	// !!! ������������ �������, ��� ��� ��� �� ����� ���������� ����������� 
	// ��������� ������ - ���������� ����������� ���������� !!!
	Station(const Station& station) = default;

	// ����������
	~Station()
	{
		delete[]name_;
	}

	// ���������� �������� �����������
	// !!! ������������ �������, ��� ��� ��� �� ������ �������� ������������
	// ��������� ������ - ���������� ������������ ���������� !!!
	Station& operator=(const Station& station) = default;

#pragma endregion

#pragma region ������� � �������

	// ������ name_;
	void setName(const char* name)
	{
		int size = strlen(name);

		// ���� ������ �����������
		if (size != NAME_SIZE)
			throw exception("Station: ������ �����������!");
		
		// �������� �� ��, ��� � ������ ������ �����
		for (int i = 0; i < NAME_SIZE; i++)
		{
			if (name[i] < '0' and name[i] > '9')
				throw exception("Station: ������ �����������!");
		}

		// ��������� ��������
		strncpy(name_, name, NAME_SIZE);
	}

	// ������ name_
	const char* getName() { return name_; }

	// ������ rate_
	void setRate(float rate)
	{
		// ���� ������ �����������
		if (rate < RATE_MIN and rate < RATE_MAX)
			throw exception("Station: ������ �����������!");

		rate_ = rate;
	}

	// ������ rate_
	float getRate() { return rate_; }

	// ������ subscribers_
	void setSubscribers(Subscriber* arr, int n)
	{
		subscribers_.addAll(arr, n);
	}

#pragma endregion

#pragma region ������

	// ����� �� ������
	BinaryTree<Subscriber>::NodeTree<Subscriber>* find(const char* number);

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream os, Station& station)
	{
		os << "��� �������: " << station.name_
			<< "\n�����: " << station.rate_
			<< "\n��������:\n" << station.subscribers_ << "\n";
	}

	// ����� � ���� ������� � �����
	void showTable()
	{
		// ������� ���� �� ���������
		short cl = getColor();

		
		cout << fixed;
		cout.precision(1);
		
		cout<< "\t+����������������������+\n"
			<< "\t|    ��� �������: " << color(GREEN_ON_BLACK) << right << setw(4) << name_
			<< color(cl) << " |\n"
			<< "\t+����������������������+\n"
			<< "\t| �����(���/���): " << color(GREEN_ON_BLACK) << setw(4) << rate_
			<< color(cl) << " |\n" << left;

		// ����� ��������� 
		printSubscriberColor();

	}

	// ����� � ���� ������� � ����� � �������� �������
	void showTableBack()
	{
		// ������� ���� �� ���������
		short cl = getColor();


		cout << fixed;
		cout.precision(1);

		cout << "\t+����������������������+\n"
			<< "\t|    ��� �������: " << color(GREEN_ON_BLACK) << right << setw(4) << name_
			<< color(cl) << " |\n"
			<< "\t+����������������������+\n"
			<< "\t| �����(���/���): " << color(GREEN_ON_BLACK) << setw(4) << rate_
			<< color(cl) << " |\n" << left;

		// ����� ��������� 
		printSubscriberColorBack();

	}


	// ����� � ���� ������� � ����� + ����� � ������
	void showTablePrice()
	{
		// ������� ���� �� ���������
		short cl = getColor();


		cout << fixed;
		cout.precision(1);

		cout << "\t+����������������������+\n"
			<< "\t|    ��� �������: " << color(GREEN_ON_BLACK) << right << setw(4) << name_
			<< color(cl) << " |\n"
			<< "\t+����������������������+\n"
			<< "\t| �����(���/���): " << color(GREEN_ON_BLACK) << setw(4) << rate_
			<< color(cl) << " |\n" << left;

		// ����� ��������� 
		printSubscriberColorPrice();

	}


	// ����� ��������� ������ � ��������� Subscriber � �����
	void printSubscriberColor();

	// ����� ����� ������ ��� ������ � ����� �������� Subscriber
	void showColor(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i);


	// ����� ��������� ������ � ��������� Subscriber � ����� � �������� �������
	void printSubscriberColorBack();

	// ����� ����� ������ ��� ������ � ����� �������� Subscriber � �������� �������
	void showColorBack(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i);



	// ����� ��������� ������ � ��������� Subscriber � �����
	// � ������ � ������
	void printSubscriberColorPrice();

	// ����� ����� ������ ��� ������ � ����� ���� � ������ �������� Subscriber
	void showColorPrice(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i, float& rate);


#pragma endregion

};

