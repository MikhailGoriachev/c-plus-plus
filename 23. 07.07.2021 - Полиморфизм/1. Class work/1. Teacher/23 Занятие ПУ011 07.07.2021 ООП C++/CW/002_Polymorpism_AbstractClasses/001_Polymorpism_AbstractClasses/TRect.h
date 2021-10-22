#pragma once

// ����������� �����, ���������� ������ ����������� �������
class TRect
{
protected:  // ��������� ������
	double a_;
	double b_;

public:
	TRect() = default;
	TRect(double a, double b):a_(a), b_(b) {}
	TRect(const TRect& tRect) = default;
	virtual ~TRect() = 0 {}

	// ��������� ������
	// ������ ����������� ������� - �������� ��� ���� ����������� �������
	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual void show() = 0;

	// ���������� ��� ���������� ������������ ������� ��� ������
	// ������� qsort() ����������� ���������� 
	static int compare(void const* ob1, void const* ob2)
	{
		double area1 = (*(TRect**)ob1)->area();
		double area2 = (*(TRect**)ob2)->area();

		return area1 < area2 ? -1 : area1 > area2 ? 1 : 0;
	} // compare 
};

