#pragma once

#include "Utils.h"
#include "pch.h"
#include "Conoid.h"
#include "ArrayConoid.h"
#include "App.h"


// суммарный объём
double allSummV(ArrayConoid& conoid);

// суммарная площадь
double allSummS(ArrayConoid& conoid);

// декремент Conoid префиксный
Conoid& operator--(Conoid& con);

// декремент Conoid постфиксный
Conoid& operator--(Conoid& con, int); 

// генерация данных усечённого конуса
void generConoid(ArrayConoid& arr);