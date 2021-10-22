#pragma once
#include "Palette.h"
// ����� �������� �������� � �������

// ���� �������������� ������
const int K_F1 = 59, K_F2 = 60, K_F3 = 61, K_F4 = 62;
const int K_F5 = 63, K_F6 = 64, K_F7 = 65, K_F8 = 66;
const int K_F9 = 67, K_F10 = 68, K_F11 = 133, K_F12 = 134;

// ��������� ���������� ������� � ������ ����������
void init(const wchar_t *title);

// ��������� ���� ������� �������
int getKey(const char *message = "\t    ������� ����� ������� ��� �����������...");

// ��������� ���������� �����
int    getRand(int low, int high);
double getRand(double low, double high);

// ������� ����� �������
void setColor(short color);

// ������� ���� �������
short getColor();


// ����� ������ ������� ������ ���� - ������ ��������� ��� ���������� �����
void showNavBarMessage(short hintColor, const char *message = " ������� ����� ������� ��� �����������..");

// ����� ���������� ���������
void showMessage(short x, short y, short width, const char* msg[], short msgColor);

// ����� ����������� �� �����, ������������� ������ �����, ���� �������������
// � �������� color
void showInputLine(const char* prompt, int n, short color);

// c ����������� �������� WinAPI -----------------------------------------
void gotoXY(short x, short y);
void setCursorVisible(bool mode);
void cls();

// ����� ������ � �������� �����
void cputs(const char* str, short color = mainColor);

// ����� ������ � �������� ����������� ���� �������
void writeXY(short x, short y, const char* str, short color = mainColor);
