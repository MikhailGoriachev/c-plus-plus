#pragma once
#include "head.h"

// ���� �������
void setColor(WORD wColor);

// �������� ���� �������
void tittleOut();

// �������� ������
void cls();

// ����� ������ 
void outText(WORD wColor, wchar_t* str);

// ��������� �������
void Cursor(SHORT Y, SHORT X);

// ����� ���� ������ ����
void outBackgr();

// ������ ����
void sizeWindow();