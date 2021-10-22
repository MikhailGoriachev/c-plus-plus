#pragma once

#include "pch.h"
#include "Container.h"
#include "ContainerException.h"
#include "Utils.h"

// � ����������� ������ QSort ���������� ����������� ������� ������� ����������,
// ������� ������� qsort(), ������������ ��������� � ���������� �����������
// ��������� log10().

// ����������� ����� Bubble
class QSort : public Container<double>
{
public:

	// ����������� �� ���������
	QSort() = default;

	// ���������������� ����������� 
	QSort(double* data, int n) : Container(data, n) {}

	// ���������� ����������� 
	QSort(const QSort & QSort) = default;

	// ���������� 
	virtual ~QSort() override = default;

private:

	// ���������� ��� ����������
	static int compar(const void* val1, const void* val2)
	{
		double value1 = *(double*)val1;
		double value2 = *(double*)val2;

		return value1 > value2 ? 1 : value1 < value2 ? -1 : 0;
	}

public:

	// ���������� ����������� ������� ������� ����������
	virtual void sort() override
	{
		// ������� ����������
		qsort(data_, size_, sizeof(double), compar);
	}

	// ������������ ��������� � ���������� ����������� ��������� log10()
	virtual void foreach() override try
	{ 
		for (int i = 0; i < size_; i++)
		{
			data_[i] = log10Func(data_[i]);
		}
	}
	catch (ContainerException<double>& ex)
	{
		// ������� ����
		short cl = getColor();

		// ����� ����������
		cout << color(RED_ON_BLACK) << ex << color(cl);
	}

	// ���������� ����������� ��������� log10()
	double log10Func(double value)
	{
		// ���� �������� ������ ����
		if (value <= 0)
		{
			stringstream os;

			os.precision(3);

			// ������������ ������
			os << " | QSort: �������� ������ ��� ����� ����!           �������� �������� �������: " << right << setw(7) << value << setw(34) << " |\n";
			// �������� ������ � ContainerException
			throw ContainerException<double>(os.str().c_str());
		}

		return log10(value);

	}
};

