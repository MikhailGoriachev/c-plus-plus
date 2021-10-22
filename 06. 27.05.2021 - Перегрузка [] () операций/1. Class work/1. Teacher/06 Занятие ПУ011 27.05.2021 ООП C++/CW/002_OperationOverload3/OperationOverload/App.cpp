#include"pch.h"
#include "App.h"
#include "Utils.h"
#include "Cylinder.h"
#include "ArrayCylinders.h"

// функция, использующая перегруженную операцию [] класса ArrayCylinders
// ищет и показывает цилиндры с минимальным объемом 
void showMinVolumeCylinder(ArrayCylinders &arrayCylinders) {
    int imin = arrayCylinders.findIndexMinVolume();
	
    cout<< "\n\tЦилиндр/цилиндры с минимальным объемом:\n"
        << fixed << setprecision(3)
        << "\t+———————+——————————+——————————+——————————+——————————+\n"
        << "\t| N п/п |     r    |     h    |  площадь |   объем  |\n"
        << "\t+———————+——————————+——————————+——————————+——————————+\n";
    // double minVolume = arrayCylinders.at(imin).volume();
    double minVolume = arrayCylinders[imin].volume();

    for (int i = imin; i < arrayCylinders.length(); ++i) {
        // для ускорения доступа сохраняем вычисленный объем
    	// текущго цилиндра
    	double volume = arrayCylinders[i].volume();
    	
        if (volume == minVolume) {
           cout<< "\t| " << setw(5) << i
               << arrayCylinders[i].toString()
               << " | " << setw(8) << arrayCylinders[i].area()
               << " | " << setw(8) << volume << " |\n";
        } // if
    } // for i

    cout<< "\t+———————+——————————+——————————+——————————+——————————+\n";
}