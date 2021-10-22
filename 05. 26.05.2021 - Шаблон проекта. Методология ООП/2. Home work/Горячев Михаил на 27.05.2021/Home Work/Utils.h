#pragma once
#include "Palette.h"
// набор полезных констант и функций

// коды функциональных клавиш
const int K_F1 = 59, K_F2 = 60, K_F3 = 61, K_F4 = 62;
const int K_F5 = 63, K_F6 = 64, K_F7 = 65, K_F8 = 66;
const int K_F9 = 67, K_F10 = 68, K_F11 = 133, K_F12 = 134;

// процедура подготовки консоли к работе приложения
void init(const wchar_t *title);

// получение кода нажатой клавиши
int getKey(const char *message = "\t    Нажмите любую клавишу для продолжения...");

// генерация случайного числа
int    getRand(int low, int high);
double getRand(double low, double high);

// задание цвета консоли
void setColor(short color);

// вернуть цвет консоли
short getColor();


// вывод пустой верхней строки окна - строки навигации при исполнении задач
void showNavBarMessage(short hintColor, const char *message = " Нажмите любую клавишу для продолжения..");

// вывод текстового сообщения
void showMessage(short x, short y, short width, const char* msg[], short msgColor);

// вывод приглашения ко вводу, представления строки ввода, цвет переключается
// в заданный color
void showInputLine(const char* prompt, int n, short color);

// c применением структур WinAPI -----------------------------------------
void gotoXY(short x, short y);
void setCursorVisible(bool mode);
void cls();

// вывод строки в заданном цвете
void cputs(const char* str, short color = mainColor);

// вывод строки в заданных координатах окна консоли
void writeXY(short x, short y, const char* str, short color = mainColor);
