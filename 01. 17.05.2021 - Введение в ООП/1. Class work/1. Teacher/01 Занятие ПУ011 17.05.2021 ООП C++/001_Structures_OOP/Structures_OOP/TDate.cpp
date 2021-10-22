#include "pch.h"
#include "TDate.h"

// ������ ����������� ������ ��������� ��� ����������� ���������
// ����������� ������������::���������(���������) { ���� ������ }
//
// ����� ��������� � 
void TDate::Output()
{
	cout<< setfill('0')
	    << setw(2) << Day << "/" << setw(2) << Month << "/" << setw(4) << Year
	    << setfill(' ');
} // TDate::Output


// ������ ����������� ������ ��������� ��� ����������� ���������
// ����������� 
bool TDate::LeapYear()
{
	if (Year % 4 != 0) return false;

	if (Year % 100 == 0 && Year % 400 != 0) return false;

	return true;
} // TDate::LeapYear


