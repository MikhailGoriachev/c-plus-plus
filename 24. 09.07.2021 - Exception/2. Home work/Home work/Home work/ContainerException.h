#pragma once

#include "pch.h"

/*
	������������ ����������� ����� ����������, �������������� �� ������
	exception. ���������� � ����������: ��������� �� ������, �������� ��������
	�������, ��� ��������� ���������� ��� ������� ������� �� ������.
*/

// ����� ���������� �� ���� ������ exception
template<typename T>
class ContainerException : public exception
{
public:

	// ����������� �� ���������
	ContainerException() {}

	// ����������� ����������������
	ContainerException(const char* message) : exception(message) {}

	// ���������� ����������� 
	ContainerException(const ContainerException<T>& �ontainerException) {};

	// ���������� �������� ������������
	ContainerException& operator=(const ContainerException<T>& containerException) = default;

	// ���������� 
	virtual ~ContainerException() override = default;

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const ContainerException& containerException)
	{
		return os << containerException.what();
	}
};

