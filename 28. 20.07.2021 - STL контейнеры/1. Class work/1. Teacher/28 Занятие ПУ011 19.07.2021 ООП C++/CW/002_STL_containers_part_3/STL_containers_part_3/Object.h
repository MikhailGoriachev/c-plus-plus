#pragma once
#include "pch.h"

// Базовый класс для организации вывода 
// всех производных классов 
class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

	virtual string toString() = 0;
};

