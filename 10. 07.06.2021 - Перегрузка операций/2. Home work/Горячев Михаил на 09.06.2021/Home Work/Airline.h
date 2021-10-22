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
	static const int NAME_COMP_SIZE = 51;
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
	Airline(const char* nameCompany, int countPlane);

	// ����������� ����������������, ����������� ������ ��������
	Airline(const char* nameCompany, Plane* planes, int countPlane);

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
	void setNameCompany(const char* nameCompany);

	// ������ nameCompany_
	char* getNameCompany()
	{
		/*char* str = new char[NAME_COMP_SIZE];
		memcpy(str, nameCompany_, NAME_COMP_SIZE - 1);
		return str;*/

		return nameCompany_;
	}

	// ������ countPlane_
	void setCountPlane(int countPlane);

	// ������ countPlane_
	int getCountPlane() { return countPlane_; }

	// ������ planes_
	void setPlanes(Plane* planes);

	// ������ planes_
	Plane* getPlanes() const { return planes_; }

#pragma endregion

#pragma region ������

	// ������� ���������� ������� �������� �� ��������� ����� �������
	void quickSort(Plane* planes, int start, int end);

	// ������� ���������� ������� �������� �� �����������
	void quickSort(Plane* planes, int start, int end, int compare(const Plane& pl1, const Plane& pl2));

	// ���������� ������� (� ����� �������)
	//Airline& operator&(Plane& newPlane);

#pragma region ��������� ����������

	// ���������� �������� [] ��� ������� � ��������� ������� ���������
	Plane& operator[](int index);

	// ���������� �������� �������� * ��� ���������� ��������� ��������� �� �������� ����������� (�������������)
	Airline& operator*(double coefficient);

	// ���������� ������� �������� � ��� ������ ������� �������� � ����������� ���������� ������
	Plane& operator!();

	// ���������� ������� �������� � ��� ������ ������� �������� � ����������� ���������� ������
	Plane& operator-();

	// ���������� ��������� ������������
	Airline& operator=(const Airline& air);

	// ������� ������ ����������� ������� ��������* ��� ���������� 
	// ������� ��������� �� ��������� ����� �������
	Airline& operator*();

	// ���������� �������� �������� *
	// ���������� �� �������� ���������� ����������
	Airline operator*(int comparer(const Plane& plane1, const Plane& plane2));

	// ���������� ������� (� ����� �������)
	Airline& operator&(Plane& newPlane);

#pragma endregion

#pragma endregion

#pragma region ������������� �������

	// ����� ������ ������������ � ��������� ������� � ���������� �������� ������ <<
	friend ostream& operator<<(ostream& os, Airline air);

#pragma endregion
};



