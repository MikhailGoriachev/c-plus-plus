#pragma once
#include "Colors.h"
#include <climits>
#include <cfloat>

// коды функциональных клавиш
const int K_F1 = 59, K_F2 = 60, K_F3 = 61, K_F4 = 62;
const int K_F5 = 63, K_F6 = 64, K_F7 = 65, K_F8 = 66;
const int K_F9 = 67, K_F10 = 68, K_F11 = 133, K_F12 = 134;

const int MAX_SECONDS = 24 * 60 * 60;

// процедура подготовки консоли к работе приложения
void init(const wchar_t title[] = L"Заголовок приложения");

// получение кода нажатой клавиши
int getKey(const char *prompt = "\nНажмите любую клавишу для продолжения. . . ");

// генерация случайного числа
int    getRand(int low, int high);
double getRand(double low, double high);

// задание цвета консоли
void setColor(short color);

// ввод целого числа
int getInt(const char prompt[], int from = INT_MIN, int to = INT_MAX);

// ввод вещественного числа
double getDouble(const char *prompt, double from = -DBL_MAX, double to = DBL_MAX);

// вывод сообщения в цветную панель
void outText(const char text[], short panelColor = BLACK_ON_GRAY, short basicColor = GRAY_ON_LTBLACK);
int  outTextModal(const char text[], short panelColor = BLACK_ON_GRAY, short basicColor = GRAY_ON_LTBLACK);

// c применением структур WinAPI -----------------------------------------
void gotoXY(short x, short y);
void setCursorVisible(bool mode);
void cls();
