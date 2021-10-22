#pragma once
#include "pch.h"

// ������ ������ � explicit-������������� 
class B
{
    int value_;

public:
    B(): value_() {}
	
    // explicit - ������ �������� ������ ������������
    // B b = 1; -- ����� ��������� �����������
    // B b(1);  -- ����� ��������� ��������, ����� ����� ������������
    explicit B(int value): value_(value) {}

    int  getValue() const { return value_; }
    void setValue(int value) { value_ = value; }

    friend ostream &operator<<(ostream &os, const B &b);
    friend istream &operator>>(istream &is, B &b);
};

