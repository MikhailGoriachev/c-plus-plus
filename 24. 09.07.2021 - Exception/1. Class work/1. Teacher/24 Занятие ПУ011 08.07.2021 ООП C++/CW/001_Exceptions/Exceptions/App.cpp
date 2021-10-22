#include "pch.h"
#include "App.h"
#include "Utils.h"
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"


void zoo(int d);

// ��������� ���������� � �������
void bar()
{
	int d = getRand(-100, 100);
	
	try {
		zoo(d);
	} // try 
	
	catch (range_error &ex)
	{
		cout << "    bar: <<range_error>> " << ex.what() << "\n";
		throw;  // ��������� ������ ���������� range_error, 
		        // ex �� ��������, ���������� ������, ����������� ����
	} // catch

	cout << "\nd = " << d << "\n\n";
}

// ������ ���������� � �������
void zoo(int d)
{
	if (abs(d) > 10 && abs(d) < 60)
		throw  range_error("������������ ��������");
	cout<<"zoo: ���������� ������\n";
}


// ������ ������������� �������, �������������� �� ���������� ������
// Derived1 - ����������� �� Base<double>
// Derived2 - ����������� �� Base<int>
void templatesAndInherit() 
{
	cout << "\n    �� ����������� ������\n\n";

	// �� ����������� ������ - ��������� ����������
	Derived1 derived1(9.81, 3.12);
	derived1.foo();

	Derived2 derived2(-1, -2);
	derived2.foo();

	// ����������� ������ - ����� ����������� ������� ������������ ������
	// ��� ������ ��������� �� ������� �����

	cout << "\n\n    ����������� ������\n\n";

	// ��������� �� ������� �����, �������� ����� <double>
	Base<double> *ptrDerived1 = new Derived1(M_PI, M_E);
	ptrDerived1->foo(); // ����� ������������ ������ ���������� �� ��������� �� ������� �����
	delete ptrDerived1;

	// ��������� �� ������� �����, �������� ����� <int>
	Base<int> *ptrDerived2 = new Derived2(404, 500);
	ptrDerived2->foo();
	delete ptrDerived2;
} // templatesAndInherit
