#pragma once
#include "pch.h"
#include "Base.h"

// ����������� �� Base ����� - �����, ��������� Base, �������, �������� �����

// ��������� ������������
// class ���������: �����1 �������1, �����2 �������2, ..., �����N �������N
// ������ ������������
//              �������     �����������
// public       private     �� ��������
//              protected   protected
//              public      public
// ����������������������������������������
// protected    private     �� ��������
//              protected   protected
//              public      protected
// ����������������������������������������
// private      private     �� ��������
//              protected   private
//              public      private
class Derived :public Base  // ����� Derived � �������� ����������� �� Base  
{
protected:
	int c_;

public:
	// ������������
	Derived() :/* Base(), */ c_() { cout << "Derived: ����������� �� ���������\n"; }

	// ��������� ������������ � �����������
	// ������� ������: ������� ����� -> ����������� �����
	Derived(int a, int b, int c):Base(a, b), c_(c) { cout << "Derived: ����������� � �����������\n"; }

	// ������� ������: ����������� ����� -> ������� �����
	~Derived() { cout << "Derived: ���������\n"; }

	int getC() const { return c_; }
	void setC(int value)  { c_ = value; }

	friend ostream& operator<<(ostream &os, const Derived &derived);
};

