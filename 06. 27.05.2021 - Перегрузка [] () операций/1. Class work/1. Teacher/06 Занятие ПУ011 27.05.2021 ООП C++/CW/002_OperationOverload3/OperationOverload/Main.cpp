
#include "pch.h"
#include "Utils.h"
#include "Cylinder.h"
#include "ArrayCylinders.h"
#include "App.h"
#include "Matrix.h"

// функции, демонстрирующие перегрузку операций
void demoSquars();    // операция []
void demoRounds();    // операция ()

int main()
{
	// настройка вывода в консоль
	init(L"19.05.2021 - перегрузка операций [], ()");

    //demoSquars();
	
	demoRounds();
    
    getKey();
	return 0;
} // main


// демонстарция перегрузки операции []
void demoSquars()
{
    cls();
	
    // класс-контейнер для демонстрации перегрузки операции []
    ArrayCylinders arrayCylinders;

    arrayCylinders.show("\n\n\tМассив цилиндров:\n");

    int iminVolume = arrayCylinders.findIndexMinVolume();
    cout << "\n\tИндекс элемента с минимальным объемом iminVolume = " << iminVolume << "\n"
        << "\tЧтение элемента методом at(" << iminVolume << "): " << arrayCylinders.at(iminVolume).volume() << "\n"
        << "\tчтение элемента операцией [" << iminVolume << "]: " << arrayCylinders[iminVolume].volume() << "\n";

    arrayCylinders.put(iminVolume, Cylinder(1, 10));
    arrayCylinders.show("\n\n\tМассив цилиндров, запись элемента методом put():\n");

    arrayCylinders[100 * (iminVolume + 1)] = Cylinder(10, 1);
    arrayCylinders.show("\n\n\tМассив цилиндров, запись элемента операцией []:\n");

    // просто для проверки
    arrayCylinders[getRand(0, arrayCylinders.length() - 1)] = arrayCylinders[iminVolume];
    arrayCylinders[getRand(0, arrayCylinders.length() - 1)] = arrayCylinders[iminVolume];

    // метод, использующий перегруженную операцию []
    showMinVolumeCylinder(arrayCylinders);

    // демонстрация еще одной перегрузки операции []
    // индексирование строкой - сдлаем такой как-бы словарь
    cout << "\n\tДемонстрация еще одной перегрузки операции []:\n"
        << "\thello        -> " << arrayCylinders["hello"] << "\n"
        << "\thi           -> " << arrayCylinders["hi"] << "\n"
        << "\tgood morning -> " << arrayCylinders["бодрое утро"] << "\n";

    // ожидание нажатия любой клавиши
    getKey();
} // demoSquars


// демонстарция перегрузки операции ()
void demoRounds()
{
    cls();
	
	// объявление объекта класса Matrix
    Matrix matrix;

    cout << "\n\nПерегрузка операции () на примере класса Matrix:\n";
	
	// демонстрация операции () для записи в элементы матрицы
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.cols(); j++)
            // перегруженная операция () для доступа 
            // к элементам матрицы по записи
            matrix(i, j) = 10 * i + j;
    } // for i

    // демонстрация операции () для чтения элементов из матрицы
    for (int i = 0; i < matrix.rows(); i++) {
        for (int j = 0; j < matrix.cols(); j++)
            // перегруженная операция () для доступа 
			// к элементам матрицы по чтению
            cout << setw(7) << matrix(i, j);
        cout << "\n";
    } // for i

    // ожидание нажатия любой клавиши
    gotoXY(12, 30);
    getKey();
} // demoRounds