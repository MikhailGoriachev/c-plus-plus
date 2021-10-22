#pragma once

#include "pch.h"
#include "Plane.h"
// ����� ������ ������� 
class showOnePlaneTable
{
	Plane plane_;

public:
	explicit showOnePlaneTable() = default;

	explicit showOnePlaneTable(Plane plane) :plane_(plane) {}

	~showOnePlaneTable() = default;

	friend ostream& operator<<(ostream& os, showOnePlaneTable show)
	{
		os << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n"
			<< "|     ������    |  ��������. | ���������� | ����. �������� |     ���������     |  ��������� ����� |  ���������. ����� |\n"
			<< "|               |    ����    |            |     ��/�       |      �������     |      �������     |      �������     |\n"
			<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n"
			<< show.plane_
			<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

		return os;
	}
};
