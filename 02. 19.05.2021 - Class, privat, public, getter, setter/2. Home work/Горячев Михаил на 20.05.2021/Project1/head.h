#pragma once

#include "Utils.h"
#include "pch.h"
#include "app.h"

#include "Cylinder.h"	// класс Cylinder
#include "Palette.h"	// палитра цветов

#include "task1.h"	// файла заголовкой Задания 1
#include "task2.h"	// файла заголовкой Задания 2

#include <exception>

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void showTableCylinder(const char* title, Cylinder* cylinders, int n, int maxIndex);

// меню
void menu();

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void showTableConoids(const char* title, Conoid* cylinders, int n, int minIndex);