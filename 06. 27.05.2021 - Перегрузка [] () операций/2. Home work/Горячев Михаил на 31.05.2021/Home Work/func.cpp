#include "Utils.h"
#include "pch.h"
#include "Conoid.h"
#include "ArrayConoid.h"
#include "App.h"

// ��������� �����
double allSummV(ArrayConoid& conoid)
{
	double num = 0;

	for (size_t i = 0; i < conoid.size(); i++)
	{
		num += conoid[i].MathV();
	}

	return num;
}

// ��������� �������
double allSummS(ArrayConoid& conoid)
{
	double num = 0;

	for (size_t i = 0; i < conoid.size(); i++)
	{
		num += conoid[i].MathS();
	}

	return num;
}

// ��������� Conoid ����������
Conoid& operator--(Conoid& con)
{
	// ���������� �� ���� ���� �����
	con.setHeight(con.height_ - 1);
	con.setRadius1(con.radius1_ - 1);
	con.setRadius2(con.radius2_ - 1);

	return con;
}

// ��������� Conoid �����������
Conoid& operator--(Conoid& con, int)
{
	Conoid* temp = new Conoid;

	*temp = con;

	// ���������� �� ���� ���� �����
	con.setHeight(con.height_ - 1);
	con.setRadius1(con.radius1_ - 1);
	con.setRadius2(con.radius2_ - 1);

	return *temp;
}

// ��������� ������ ���������� ������
void generConoid(ArrayConoid& arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		// ������
		arr[i].setHeight(getRand(1., 50.));

		// ������ 1
		arr[i].setRadius1(getRand(1., 50.));

		// ������ 2
		arr[i].setRadius2(getRand(1., 50.));

		// ���� ������ 1 ������ ������� 2
		if (arr[i].getRadius1() < arr[i].getRadius2())
		{
			double tmp = arr[i].getRadius1();
			arr[i].setRadius1(arr[i].getRadius2());
			arr[i].setRadius2(tmp);
		}
	}
}
