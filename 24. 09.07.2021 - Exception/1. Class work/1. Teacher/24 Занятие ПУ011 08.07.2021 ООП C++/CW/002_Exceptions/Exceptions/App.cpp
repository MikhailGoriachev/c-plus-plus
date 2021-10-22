#include "pch.h"
#include "App.h"
#include "ClassA.h"
#include "Utils.h"

// ������������ ���������� � �������
// ��� ����������(������) throw(������������������������������������)
// ��� ����������(������) throw(...) -  ��������� ���
// ��� ����������(������) throw()    -  ������ ����������� �� ���� ����������
// !!! ���� ���������� ��������� - ���������� �-� void unexpected(), ����������   
// � ������ �-�� void terminate(), ����������� ���������
// � ��� ��� ������� ����� ���� ������������� ��������� ������ �����������
// �������:
// 	    set_unexpected(����������);
//	    set_terminate(����������);
void foo() throw(range_error, domain_error)
{
	int number = getRand(1, 100);
	if (number < 10) {
		cout << "    foo: number = " << number << ", ��� ��\n";
		return;
	} // if

	if (number >= 11 && number <= 50)
		throw range_error("    ������ ���������� range_error");

	if (number > 50 && number <= 70)
		throw domain_error("    ������ ���������� domain_error");

	// ������ ������������������ � ��������� ������� ����������
	throw out_of_range("    ������ ������������������ � ��������� ������� ����������");
} // foo

// ������� ������� � �������������� try-������
void bar() try {
	int number = getRand(1, 100);

	// �������� �������, ������� ����� � �� ����������� 
	ClassA classA(nullptr, -10);

	if (number <= 10) {
		cout << "    bar: number = " << number << ", ��� ��\n";
		return;
	} // if

	if (number >= 11 and number <= 40)
		throw invalid_argument("    bar: ������������ �������� ���������, ���������� invalid_argument");

	throw out_of_range("    bar: ������ ���������� out_of_range");
} // bar-try
catch (exception& ex) {
	cout << endlm(2) << "    " << ex.what() << endlm(3);
	// throw; // �� �����������
} // catch




