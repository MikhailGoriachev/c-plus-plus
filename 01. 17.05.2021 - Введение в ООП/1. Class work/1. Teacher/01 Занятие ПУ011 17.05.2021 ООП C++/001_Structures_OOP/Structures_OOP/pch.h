#ifndef PCH_H
#define PCH_H

// разрешение компиляции "классических" функций для работы со строками,
// файлами: str___(), f______()
#define _CRT_SECURE_NO_WARNINGS

// использование математических констант, современный стиль
#include <corecrt_math_defines.h>

#include <iostream>  // этот файл делает доступными инженерные функции  
#include <iomanip>   // для манипуляторов вывода setw(), setprecision()
#include <Windows.h>
#include <conio.h>
#include <sstream>   // для работы со строковым потоком вывода

using namespace std;

// объявление символической константы - кодовой страницы
#define CODE_PAGE 1251

#endif //PCH_H
