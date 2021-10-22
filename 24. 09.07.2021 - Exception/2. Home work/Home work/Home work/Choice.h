#pragma once

#include "pch.h"
#include "Container.h"
#include "ContainerException.h"
#include "Utils.h"


// � ����������� ������ Choice ���������� ����������� ������� ������, 
// ������������ ��������� � ���������� ������������ ��������� log().

// ����������� ����� Bubble
class Choice : public Container<double>
{
public:

	// ����������� �� ���������
	Choice() = default;

	// ���������������� ����������� 
	Choice(double* data, int n) : Container(data, n) {}

	// ���������� ����������� 
	Choice(const Choice & choice) = default;

	// ���������� 
	virtual ~Choice() override = default;

	// ���������� ����������� ������� ������ (�������� http://algolist.ru/sort/select_sort.php) 
	virtual void sort() override
	{
		double x;

		for (int i = 0, k; i < size_; i++) {   	// i - ����� �������� ����
			k = i; x = data_[i];

			for (int j = i + 1; j < size_; j++)	// ���� ������ ����������� ��������
				if (data_[j] < x) {
					k = j; x = data_[j];	        // k - ������ ����������� ��������
				}

			data_[k] = data_[i]; data_[i] = x;   	// ������ ������� ���������� � data_[i]
		}
	}

	// ������������ ��������� � ���������� ������������ ��������� log()
	virtual void foreach() override try 
	{ 
		for (int i = 0; i < size_; i++)
		{
			data_[i] = logFunc(data_[i]);
		}
	}
	catch (ContainerException<double>& ex)
	{
		// ������� ����
		short cl = getColor();

		// ����� ����������
		cout << color(RED_ON_BLACK) << ex << color(cl);
	}

	// ���������� ������������ ��������� log()
	double logFunc(double value)
	{
		// ���� �������� ������ ����
		if (value <= 0)
		{
			stringstream os;

			os.precision(3);

			// ������������ ������
			os << " | Choice: �������� ������ ��� ����� ����!           �������� �������� �������: " << right << setw(7) << value << setw(33) << " |\n";

			// �������� ������ � ContainerException
			throw ContainerException<double>(os.str().c_str());
		}
		return log(value);

	}
};

