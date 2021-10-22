#pragma once
#include "pch.h"
#include "Utils.h"
#include <algorithm>

class App
{
	// ������ ��� ���������
    vector<double> data_;

public:
    
    App() = default;

    App(vector<double> &data): data_(data) {}
    virtual ~App() = default;

    // ������� 16 �� �������� ���������� �.�.,������ �.�.
    int variant16a();
    double variant16b();
    void variant16c();

    // ������� 19 �� �������� ���������� �.�.,������ �.�.
    double variant19a();
    double variant19b();
    void variant19c();

    void show(string title) const;
    void make();
};

