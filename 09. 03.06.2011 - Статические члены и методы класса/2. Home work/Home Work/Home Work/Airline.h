#pragma once
#include "Plane.h"
#include "pch.h"

/*
	����� Airline, �������������� ������������. ���� ������:
	�	�������� ��������
	�	������������ ������ ��������� � �������� ������ Plane
	�	���������� ��������� � �������
	�����������:
	�	������������� ������� ���������
	�	����� ������ ������������ � ��������� ������� � ����������� �������� ������ <<
	�	�������� �� 10 ���������� ������� �������� ��������
	�	��������� ���������� ���������� ������� �������� �� 3
	�	������� ������ ����������� ������� �������� ! ��� ������ ������� �������� � ������������ ����������
	�	������������� �������� ����������� ������� �������� � ��� ������ ������� �������� � ����������� ����������
	�	������� ������ ����������� �������� �������� * ��� ���������� ��������� ��������� �� �������� ����������� (�������������, ��������, 1.5 � ���������� � ������� ����)
	�	������� ������ ����������� �������� [] ��� ������� � ��������� ������� ���������, ����������������� ������ ���� ��������

*/

class Airline
{
public:

#pragma region ���������
	// ������ ������ �������� ��������
	const int NAME_COMP_SIZE = 50;
#pragma endregion 

private:
	// �������� ��������
	char* nameCompany_;

	// ������������ ������ ��������� � �������� ������ Plane
	Plane* planes_;

	// ���������� ��������� � �������
	int countPlane_;

public:

#pragma region ������������ � ����������

	// ����������� �� ���������
	Airline() :nameCompany_(new char[NAME_COMP_SIZE] {0}), planes_(nullptr), countPlane_() {}

	// ����������� ����������������
	Airline(const char* nameCompany, int countPlane) : nameCompany_(new char[NAME_COMP_SIZE])
	{
		// �������� ��������
		setNameCompany(nameCompany);

		// ���������� ��������
		setCountPlane(countPlane);

		// ���� ���������� �������� ������ ����
		if (countPlane_ != 0)
		{
			// ��������� ������ ��� ������� ��������
			planes_ = new Plane[5];
		}
	}

	// ���������� �����������
	Airline(const Airline& air): nameCompany_(new char[NAME_COMP_SIZE])
	{
		// ����������� �������� ��������
		memcpy(nameCompany_, air.nameCompany_, NAME_COMP_SIZE);

		// ����������� ���������� ��������
		countPlane_ = air.countPlane_;

		// ��������� ������ ��� ������ ��������
		planes_ = new Plane[countPlane_];

		// ����������� ������� ��������
		for (size_t i = 0; i < countPlane_; i++)
		{
			planes_[i] = air.planes_[i];
		}
	}

	// ���������� 
	~Airline()
	{
		delete[] nameCompany_;
		delete[] planes_;
	}

#pragma endregion

#pragma region ������� � �������

	// ������ nameCompany_
	void setNameCompany(const char* nameCompany)
	{
		// ���� ����� ������ ����� 0
		if (strlen(nameCompany) == 0)
		{
			throw exception("�������� �������� �� ������ ���� ������!");
		}

		strcpy(nameCompany_, nameCompany);
	}

	// ������ nameCompany_
	char* getNameCompany()
	{
		char* str = new char[NAME_COMP_SIZE];

		memcpy(str, nameCompany_, NAME_COMP_SIZE);

		return str;
	}

	// ������ countPlane_
	void setCountPlane(int countPlane)
	{
		if (countPlane < 0)
		{
			throw exception("���������� ��������� ������ ��������� ��� ���� ������ ����");
		}

		countPlane_ = countPlane;
	}

	// ������ countPlane_
	int getCountPlane() { return countPlane_; }


#pragma endregion

#pragma region ������

#pragma region ��������� ����������

	// ���������� �������� [] ��� ������� � ��������� ������� ���������
	Plane& operator[](int index)
	{
		if (index < 0 || index >= countPlane_)
			throw exception("������������ ������");

		return planes_[index];
	}

	// ���������� �������� �������� * ��� ���������� ��������� ��������� �� �������� ����������� (�������������)
	Airline& operator*(double coefficient)
	{
		// ���� ����������� ������������� 
		if (coefficient < 0)
			throw exception("����������� ������ ���� �������������");

		Airline* temp = new Airline(*this);

		// ���� ��������� ��������� ������� ������� �� ����������� 
		for (size_t i = 0; i < countPlane_; i++)
		{
			temp->planes_[i].setPrice(int(planes_[i].getPrice() * coefficient));
		}

		return *temp;
	}

	// ���������� ������� �������� ! ��� ������ ������� �������� � ������������ ����������
	Plane& operator!()
	{
		// ���� ��� ��������
		if (countPlane_ == 0)
		{
			throw exception("��� ��������!");
		}

		// ������� ������������ ���� 
		int maxPrice = planes_[0].getPrice();

		// ������ 
		int maxIndex = 0;

		// ���������� ������� ������� � ������������ ����������
		for (size_t i = 1; i < countPlane_; i++)
		{
			// ��������� �������� �������
			int price = planes_[i].getPrice();

			// ���� ������� ������������ ��������� ������, ��� ��������� �������� �������
			if (maxPrice < price)
			{
				maxPrice = price;
				maxIndex = i;
			}
		}

		return planes_[maxIndex];
	}

	// ���������� ��������� ������������
	void operator=(const Airline& air)
	{
		// �������� ��������
		strcpy(nameCompany_, air.nameCompany_);

		// ������������ ������ ��������� � �������� ������ Plane
		planes_ = new Plane[air.countPlane_];

		for (size_t i = 0; i < air.countPlane_; i++)
		{
			planes_[i] = air.planes_[i];
		}

		// ���������� ��������� � �������
		countPlane_ = air.countPlane_;

	}

#pragma endregion

#pragma endregion

#pragma region ������������� �������

	// ����� ������ ������������ � ��������� ������� � ���������� �������� ������ <<
	friend ostream& operator<<(ostream& os, Airline air)
	{
		os << "\t\t\t\t\t" << air.nameCompany_ << "\n"
			<< "\t+���������������+������������+������������+����������������+�������������������+�������������������+\n"
			<< "\t|     ������    |  ��������. | ���������� | ����. �������� |     ���������     |  ���������. ����� |\n"
			<< "\t|               |     ����   |            |     ��/�       |      �������     |      �������     |\n"
			<< "\t+���������������+������������+������������+����������������+�������������������+�������������������+\n";

		// ���� � �������� ��� ��������
		if (air.countPlane_ == 0)
		{
			os << "\t|                                         ��� ����˨���                                            |\n";
			// ������ ������ 
			os << "\t+���������������+������������+������������+����������������+�������������������+�������������������+\n";
		}

		// ����� ��������
		for (size_t i = 0; i < air.countPlane_; i++)
		{
			os << air[i];

			// ������ ������ 
			os << "\t+���������������+������������+������������+����������������+�������������������+�������������������+\n";
		}

		return os;
	}

	// ���������� ������� �������� � ��� ������ ������� �������� � ����������� ����������
	friend Plane& operator-(Airline& air)
	{
		// ���� ��� ��������
		if (air.countPlane_ == 0)
		{
			throw exception("��� ��������!");
		}

		// ������� ����������� ���� 
		int minPrice = air.planes_[0].getPrice();

		// ������ 
		int minIndex = 0;

		// ���������� ������� ������� � ����������� ����������
		for (size_t i = 1; i < air.countPlane_; i++)
		{
			// ��������� �������� �������
			int price = air.planes_[i].getPrice();

			// ���� ������� ����������� ��������� ������, ��� ��������� �������� �������
			if (minPrice > price)
			{
				minPrice = price;
				minIndex = i;
			}
		}

		return air.planes_[minIndex];
	}

#pragma endregion

};

