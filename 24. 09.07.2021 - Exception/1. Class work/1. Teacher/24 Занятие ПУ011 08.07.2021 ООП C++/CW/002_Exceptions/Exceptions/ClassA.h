#pragma once
#include "pch.h"
#include "Utils.h"

// ����� �� �������� ��������� - ������ ���������� ������
// ��� try-����� � ������ �������������
class ClassA
{
	int    size_;
	double *data_;

public:
	ClassA(): size_(10), data_(new double[size_]) {}

	// ���������(����������������) try: �������������������
	// {
	//    ��������� ������������
    // } 
	// catch (�������������1 ���1) { ���������1 }
	// catch (�������������2 ���2) { ���������2 }
	// ...
	// catch (�������������N ���N) { ���������N }
	ClassA(const double *data, int size) try: 
		size_(size > 0?size:throw exception("������������ ������ ����������")), 
		data_(new double[size_]) 
	{
		memcpy(data_, data, sizeof(double)*size_);
	} 
	catch (exception &ex) {
		cout << endlm(2) << "    " << ex.what() << endlm(2);
		// abort(); // �� �����������
	    throw; // �� �����������
	} // catch

};

