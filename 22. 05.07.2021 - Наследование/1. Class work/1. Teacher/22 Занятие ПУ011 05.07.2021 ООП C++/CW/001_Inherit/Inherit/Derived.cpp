#include "Derived.h"

// ������������� �������� ����� ��� ������������ ������
ostream& operator<<(ostream& os, const Derived& derived)
{
	// ����� ������������ ������, ����� ����� ����/�����
	// ������������ ������
	// ������� ����������� ������ (������� ������)
	// ������ ����������� ������ ����� ������������ ������� 
	os << (const Base &)derived << ", derived.c_ = " << derived.c_;
	// os << static_cast<const Base&>(derived) << ", derived.c_ = " << derived.c_;
	return os;
} // operator<<