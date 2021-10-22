#pragma once
#include "head.h"

// цвет консоли
void setColor(WORD wColor);

// название окна консоли
void tittleOut();

// отчистка экрана
void cls();

// вывод текста 
void outText(WORD wColor, wchar_t* str);

// установка курсора
void Cursor(SHORT Y, SHORT X);

// вывод фона экрана меню
void outBackgr();

// размер окна
void sizeWindow();