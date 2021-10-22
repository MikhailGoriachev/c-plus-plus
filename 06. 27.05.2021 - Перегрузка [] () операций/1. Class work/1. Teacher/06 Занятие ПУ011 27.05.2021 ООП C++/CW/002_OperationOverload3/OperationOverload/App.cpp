#include"pch.h"
#include "App.h"
#include "Utils.h"
#include "Cylinder.h"
#include "ArrayCylinders.h"

// �������, ������������ ������������� �������� [] ������ ArrayCylinders
// ���� � ���������� �������� � ����������� ������� 
void showMinVolumeCylinder(ArrayCylinders &arrayCylinders) {
    int imin = arrayCylinders.findIndexMinVolume();
	
    cout<< "\n\t�������/�������� � ����������� �������:\n"
        << fixed << setprecision(3)
        << "\t+�������+����������+����������+����������+����������+\n"
        << "\t| N �/� |     r    |     h    |  ������� |   �����  |\n"
        << "\t+�������+����������+����������+����������+����������+\n";
    // double minVolume = arrayCylinders.at(imin).volume();
    double minVolume = arrayCylinders[imin].volume();

    for (int i = imin; i < arrayCylinders.length(); ++i) {
        // ��� ��������� ������� ��������� ����������� �����
    	// ������� ��������
    	double volume = arrayCylinders[i].volume();
    	
        if (volume == minVolume) {
           cout<< "\t| " << setw(5) << i
               << arrayCylinders[i].toString()
               << " | " << setw(8) << arrayCylinders[i].area()
               << " | " << setw(8) << volume << " |\n";
        } // if
    } // for i

    cout<< "\t+�������+����������+����������+����������+����������+\n";
}