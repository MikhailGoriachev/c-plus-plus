#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "TCylinder.h"     // для использования структуры TCylinder
#include "TConoid.h"

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void showTable(const char* title, CYLINDER* cylinders, int n, int maxIndex)
{
	cout << title
		<< "\t    +—————+—————————————————+————————————————+—————————————————————————————————+\n"
		<< "\t    |  N  |    Радиус, R    |    Высота, H   |   Площадь, S   |    Объем, V    |\n"
		<< "\t    +—————+—————————————————+————————————————+—————————————————————————————————+\n";

	// выводим строки таблицы цилиндров, с выделением цветом
	// строки с минимальным объемом, перед и после этой строки
	// выводим цветовые "хвостики"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(cylinders[i].MathV() == cylinders[maxIndex].MathV() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +—————+—————————————————+————————————————+—————————————————————————————————+\n";
} // showTable

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void showTableConoids(const char* title, CONOID* cylinders, int n, int minIndex)
{
	cout << title
		<< "\t    +—————+—————————————————+————————————————+————————————————+————————————————+————————————————+\n"
		<< "\t    |  N  |    Радиус, R    |    Радиус, r   |    Высота, H   |   Площадь, S   |    Объем, V    |\n"
		<< "\t    +—————+—————————————————+————————————————+————————————————+————————————————+————————————————+\n";

	// выводим строки таблицы цилиндров, с выделением цветом
	// строки с минимальным объемом, перед и после этой строки
	// выводим цветовые "хвостики"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(cylinders[i].MathS() == cylinders[minIndex].MathS() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +—————+—————————————————+————————————————+————————————————+————————————————+————————————————+\n";
} // showTable