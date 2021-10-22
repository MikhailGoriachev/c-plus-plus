#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS
#include <corecrt_math_defines.h>
#include <iostream>  // этот файл делает доступными инженерные функции  
#include <iomanip>   // для манипуляторов вывода setw(), setprecision()
#include <sstream>   // для работы со строковым потоком вывода
#include <Windows.h>
#include <conio.h>

using namespace std;

// объявление символической константы - кодовой страницы
#define CODE_PAGE 1251
#endif //PCH_H
