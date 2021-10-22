#pragma once
#include "pch.h"
#include "Cylinder.h"
#include "Utils.h"

// �����-���������, �������� ������������ ������ ���������
class ArrayCylinders
{
	// ��������� ����
    int length_;           // ������ �������
    Cylinder *cylinders_;  // ������ �������


public:
    ArrayCylinders():length_(10), cylinders_()
    {
        createAndFill(10, 3., 10.);
    }


    ArrayCylinders(int length)
        : length_(length), cylinders_()
    {
        createAndFill(length_, -10., 10.);
    } // ArrayCylinders

    // �������� � ���������� ������������� ������� ���������
    void createAndFill(int n, double lo, double hi)
    {
        // ������ ������������ - ��������
        // ��� *��� = new  ���[����������������];
        cylinders_ = new Cylinder[n];

        // ���������� �������� � ���� ��������� - ��������� �������
        for (int i = 0; i < n; ++i) {
            cylinders_[i].setR(getRand(lo, hi));
            cylinders_[i].setH(getRand(lo, hi));
        } // for i
    } // createAndFill

    // ����� ������ � ��������� � �������, title - ���������,
	// ��������� ����� ��������
    void show(const char *title)
    {
        cout<< title << fixed << setprecision(3)
            << "\t+�������+����������+����������+����������+����������+\n"
            << "\t| N �/� |     r    |     h    |  ������� |   �����  |\n"
            << "\t+�������+����������+����������+����������+����������+\n";
             
        for (int i = 0; i < length_; ++i) {
            cout<< "\t| " << setw(5) << i
                << cylinders_[i].toString()
                << " | " << setw(8) << cylinders_[i].area()
                << " | " << setw(8) << cylinders_[i].volume() << " |\n";
        } // for i
        cout<< "\t+�������+����������+����������+����������+����������+\n";
    } // showCylinders

    // ���������� ������ �������� � ����������� ������� � �������
    int findIndexMinVolume() const {
        int imin = 0;
        double minVolume = cylinders_[imin].volume();

    	// ������� �������� ������ ������������ ��������
        for (int i = 1; i < length_; ++i) {
        	// ��� ��������� ������ - ���������� ��������� ����� ��������
            double volume = cylinders_[i].volume();
            if (volume < minVolume) {
                imin = i;
                minVolume = volume;
            } // if
        } // for i

        return imin;
    } // findIndexMinVolume

    // ��� ������ ������� � �������� ������� - ������������ �������
    Cylinder at(int index) const { return cylinders_[index]; }  // ������
    void put(int index, const Cylinder &cylinder) {             // ������
        cylinders_[index] = cylinder;
    } // put


    // ���������� �������� ��������������
    Cylinder &operator[](int index)
    {
        // ������ ������ �������������� ���������
        if (index < 0) index = 0;
        if (index >= length_) index = length_ - 1;

        return cylinders_[index];
    } // operator[]

    // ���������� �������� �������������� - ���-�� ������� :) 
    const char *operator[](const char *word)
    {
        if (strcmp(word, "hello") == 0) return "������!";    
        if (strcmp(word, "hi") == 0) return "����!";    
        if (strcmp(word, "good morning") == 0) return "������ ����!";

    	return "��� ���� �� �������";
    } // *operator[]

    // ������� ������ ������� ���������
    int length() const { return  length_; }
};

