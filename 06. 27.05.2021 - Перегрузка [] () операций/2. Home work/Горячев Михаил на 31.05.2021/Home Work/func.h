#pragma once

#include "Utils.h"
#include "pch.h"
#include "Conoid.h"
#include "ArrayConoid.h"
#include "App.h"


// ��������� �����
double allSummV(ArrayConoid& conoid);

// ��������� �������
double allSummS(ArrayConoid& conoid);

// ��������� Conoid ����������
Conoid& operator--(Conoid& con);

// ��������� Conoid �����������
Conoid& operator--(Conoid& con, int); 

// ��������� ������ ���������� ������
void generConoid(ArrayConoid& arr);