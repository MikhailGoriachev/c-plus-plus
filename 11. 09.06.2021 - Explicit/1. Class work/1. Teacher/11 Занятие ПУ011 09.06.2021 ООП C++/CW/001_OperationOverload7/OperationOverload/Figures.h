#pragma once

#include "pch.h"
#include "Triangle.h"

// ������������ ����� Figures � ���������� ������
//     � ���������� �� ��� Triangle (�� ����������� �������) ��� �������� ��������� 
//       �� ������������ ������ �������� ���� Triangle
//     � ������������� ���� � ������� ������ ������������� ������� � ���������
// ������������ �������� �������������:
//     � �� ���������, ������� ������ ������ �� 5 �������� Triangle, ��������� 
//       ������������� �� ���������
//     � ����������� � ����������� � ����������� ������ �������� Triangle, ������ 
//       ����� �������
//     � ���������� �����������
// ������������ ����������, ������ ��� ����� ������� � ������ ��� ��������� ������ 
// ������� (� ������� ��� ��������� � ������ � ��� �����, ����������� ������ � ������, 
// �������� ����� ��������, �����). 
// ����������� ��������: 
//     � << ����� ������� �������������, �� ������ � ������
//     � = ������������
//     � ! ��� �������������� ������� ������������� � ��������� ������� ���������� ��������� 
//       �� ���������������, �������� ���������� ����� ����������� ������� Figures, �� ������ 
//       ������� ������ (� ������������ � ���������� ��������) 
//     � ~ ��� ���������� ��������� ������� ������������� �� ����������� ��������, �������� 
//       ���������� ����� ����������� ������� Figures, �� ������ ������� ������ (� ������������ 
//       � ���������� ��������). ������������ ������������� ����� ������� ����������, �� ��������� 
//       ����������� ����������, ���������� ������� ��� ���������� ���������
// ------------------------------------------------------------------------------------------------
// �������� & ��� ������� � ����� �������
//     figures & Triangle(3, 6, 5, "ABG");
// 	   Figures &operator&(const Triangle &triangle);
// 	 
// �������� | ��� �������� �������� �� �������
//     figures | 0
// 	   Figures &operator|(int index);
// 	   Figures &operator|(char *name);  // � ��������
// 	
// �������� ��� ������� �������� � �������� �������
// (�� ������� ��������� ����� ������������)
//     figures(0, Triangle(3, "KLM"));
//     Figures &operator()(int index, const Triangle &triangle);	

class Figures
{
    static const int N_DEF = 5;
    
    int      length_;
    Triangle *triangles_;  

    // ������ ��� ����������
    void swap(int i, int j) const;
    void quickSort(int start, int end);
    int  compareByArea(const Triangle &tr1, const Triangle &tr2);

public:
    // �� ��������� ������� ������ ������������� � ����������� �� ���������
    Figures(): length_(N_DEF), triangles_(new Triangle[length_])
    {
        for (int i = 0; i < length_; i++)
            triangles_[i] = Triangle();
    } // Figures

    // ����������� � ����������� - �������� �������������
    Figures(Triangle *triangles, int length): 
        length_(length), triangles_(new Triangle[length_])
    {
        for (int i = 0; i < length_; i++)
            triangles_[i] = triangles[i];        
    } // Figures

    // ���������� �����������
    Figures(const Figures &figures):
        length_(figures.length_), triangles_(new Triangle[length_])
    {
        for (int i = 0; i < length_; i++)
            triangles_[i] = figures.triangles_[i];  
    } // Figures

    // ��� ������� ������� ���������� ���� ���������� ���������� delete
    ~Figures() { delete[] triangles_; }

    // ������� � �������
    int getLegth() const { return length_; }
    void setData(Triangle *triangles, int length)
    {  
        // ����� ����� ������� �������������
        // TODO: ��������� ����� �� ������������: length > 1
        length_ = length;

        // ���������� ������, ���������� ��� ������, ��������
        // ����� ���� ������
        delete[] triangles_;
        triangles_ = new Triangle[length_];

        // ���������� ������ �� �������-��������� � ������ 
        // ������ Figures
        for (int i = 0; i < length_; ++i)
            triangles_[i] = triangles[i];
    } // setData

    Figures &operator=(const Figures &figures);

    Triangle &operator[](int index) const;

    // ��������� 30.05.2019 - �������������� �� ����� ������������
    // ������� �������� ������������ � ������ 
    // ��������� �������� - ������� �������� ����������� ����
    Triangle &operator[](char *name) const;


    // �������������� ������� ������������� - �������� 
    // ������ �� �������� - ���������� immutable
    Figures operator!() const;
    
    // ���������� ������� ������������� �� ����������� �������� - �������� 
    // ������ �� �������� - ���������� immutable
    Figures operator~() const;

    // ��������, ����������� �� ������� 30.05.2019
    Figures &operator&(const Triangle &triangle);
    Figures &operator|(int index);
    Figures &operator|(char *name);
    Figures &operator()(int index, const Triangle &triangle);

    friend ostream &operator<<(ostream &os, const Figures &figures);
};

