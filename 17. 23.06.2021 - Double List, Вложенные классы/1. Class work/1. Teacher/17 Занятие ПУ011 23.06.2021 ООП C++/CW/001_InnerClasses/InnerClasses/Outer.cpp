#include "pch.h"
#include "Outer.h"

// ������������ ����������� ��������� �������� ������
// �� ����������
void Outer::Inner::foo()
{
    cout<< "    Outer::Inner::foo: outer.a = " << outer_->a_
	    << ", outer.b = " << outer_->b_ << "\n";
} // foo

// ���������� ������� ������ ��� ����������� ������
ostream& operator<<(ostream& os, Outer::Inner const& obj)
{
	os << "    Outer::Inner {c: " << obj.c_ << ", d: " << obj.d_ << "}";
	return os;
} // operator<<

// ������������ ������� � ����� ���������� ����������� ������
void Outer::bar()
{
	// ��� ������� ����������� ������ ��������� �������� �����
	Outer::Inner t;
	t.setC(23);
	t.setD(33.33);

	// � ������� � ������� ���� ������
	cout << "    t: " << t << "\n";
} // Outer::bar