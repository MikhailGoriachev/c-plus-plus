#pragma once
#include "pch.h"

/*

����������� ���������� C++

exception                 - ������� ����� ���������� 
    logic_error           - ������ � ������ ��������� (������������� ������)
        domain_error      - ����� ������
		invalid_argument  - ������������ ���������
		length_error      - ������������ ����� (������)
		out_of_range      - ����� �� �������
	runtime_error         - ������ ������� ����������
	    range_error       - ����� �� �������
		overflow_error    - ������������ ��� �����������
		underflow_error   - ������ ����������
	��������� 5 ������� - ����������� run-time ��������
	bad_alloc     - ������ ��������� ������ new, new[]
	bad_cast      - ������ ���������� ����,
	                ������  RTTI - Run-Time Type Identification
	bad_typeid    - ������ RTTI
	bad_exception - ��� ����������� ����������� ����������
	ios::failure  - ������ �����-������

    ����������� ���� ����� ���������� � ������������ ����� stdexcept, 
	�� ����������� ������ bad_alloc, ������� �������� � ����� new, � 
	������ bad_cast, ������� ��������� � ����� type_info.

 */
class MegaException :	public exception
{
public:
	MegaException(const char *msg):exception(msg) {  }
	// string - ��� �� STL (Standart Template Library)
	MegaException(const string &msg):exception(msg.c_str()) {  }
};

