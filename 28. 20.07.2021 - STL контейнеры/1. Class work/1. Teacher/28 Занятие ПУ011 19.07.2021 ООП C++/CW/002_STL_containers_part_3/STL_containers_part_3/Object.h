#pragma once
#include "pch.h"

// ������� ����� ��� ����������� ������ 
// ���� ����������� ������� 
class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

	virtual string toString() = 0;
};

