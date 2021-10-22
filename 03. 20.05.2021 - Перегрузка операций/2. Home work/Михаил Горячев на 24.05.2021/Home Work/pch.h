#ifndef PCH_H
#define PCH_H

// TODO: add headers that you want to pre-compile here
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>  // этот файл делает доступными инженерные функции  
#include <iomanip>   // для манипуляторов вывода setw(), setprecision()
#include <Windows.h>
#include <conio.h>
#include <sstream>   // для работы со строковым потоком вывода
#include "Palette.h"
#include "Utils.h"

using namespace std;

// объявление символической константы - кодовой страницы
#define CODE_PAGE 1251

#include <math.h>

// команда очистки консоли
#define CLEAR "cls"

#endif //PCH_H
