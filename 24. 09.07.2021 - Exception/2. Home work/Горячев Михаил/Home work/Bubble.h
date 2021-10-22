#pragma once

#include "pch.h"
#include "Container.h"
#include "ContainerException.h"
#include "Utils.h"


// � ����������� ����� Bubble.
// ���������� ����������� ������� ��������.
// ������������ ��������� � ���������� ����������� �����.

// ����������� ����� Bubble
class Bubble : public Container<double>
{
public:

	// ����������� �� ���������
	Bubble() = default;

	// ���������������� ����������� 
	Bubble(double* data, int n) : Container(data, n) {}

	// ���������� ����������� 
	Bubble(const Bubble& bubble) = default;

	// ���������� 
	virtual ~Bubble() override = default;

	// ���������� ����������� ������� ��������.
	virtual void sort() override 
	{
		// ���������� ��������� 
		for (int i = size_ - 1; i > 0; i--)
		{
			for (int k = 0; k < i; k++)
			{
				if (data_[k] > data_[k + 1])
					swap(data_[k], data_[k + 1]);
			}
		}
	}

	// ������������ ��������� � ���������� ����������� �����.
	virtual void foreach() override try 
	{
		for (int i = 0; i < size_; i++)
		{
			data_[i] = sqrtFunc(data_[i]);
		}
	} 
	// ��������� ����������
	catch (ContainerException<double>& ex) 
	{
		// ������� ����
		short cl = getColor();

		// ����� ����������
		cout << color(RED_ON_BLACK) << ex << color(cl); 
	}

	// ���������� ����������� �����
	double sqrtFunc(double value)
	{
		// ���� �������� ������ ����
		if (value < 0)
		{
			stringstream os;

			os.precision(3);

			// ������������ ������
			os << " | Bubble: �������� ������ ����!                    �������� �������� �������: " << right << setw(7) << value << setw(34) << " |\n";

			// �������� ������ � ContainerException
			throw ContainerException<double>(os.str().c_str());
		}
		return sqrt(value);

	}
};

