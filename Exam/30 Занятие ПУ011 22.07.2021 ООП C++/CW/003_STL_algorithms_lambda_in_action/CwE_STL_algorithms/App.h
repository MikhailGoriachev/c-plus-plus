#pragma once
#include "pch.h"
#include "Utils.h"
#include <algorithm>

class App
{
	// вектор для обработки
    vector<double> data_;

public:
    
    App() = default;

    App(vector<double> &data): data_(data) {}
    virtual ~App() = default;

    // вариант 16 из сборника Павловской Т.А.,Щупака Ю.А.
    int variant16a();
    double variant16b();
    void variant16c();

    // вариант 19 из сборника Павловской Т.А.,Щупака Ю.А.
    double variant19a();
    double variant19b();
    void variant19c();

    void show(string title) const;
    void make();
};

