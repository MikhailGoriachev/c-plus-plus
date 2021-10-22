// класс Cylinder
#include "Cylinder.h"

// генерация данных цилиндра
void generCylinder(Cylinder* Cyl, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// заполнение поля высоты случайным числом
		Cyl[i].setHeight(getRand(1., 10.0));

		// заполнение поля радиуса случайным числом
		Cyl[i].setRadius(getRand(1., 10.0));
	}
}

// максимальное число
inline bool maxNumber(double a, double b)
{
	return a > b;
}

// нахождение максимального объёма цилиндра
int maximumIndex(Cylinder** Cyl, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		maxNumber(Cyl[max][0].MathV(), Cyl[i + 1][0].MathV()) ? false : max = i + 1;
	}

	return max;
}

// суммарный объём цилиндров
double summV(Cylinder** Cyl, size_t size)
{
	double summ = 0.0;

	for (Cylinder** Cyl_p = Cyl; Cyl_p < Cyl + size; Cyl_p++)
	{
		summ += (**Cyl_p).MathV();
	}

	return summ;
}

// сумма площади цилиндров
double summS(Cylinder** сylinder, size_t size)
{
	double summ = 0.0;

	for (Cylinder** сylinder_p = сylinder; сylinder_p < сylinder + size; сylinder_p++)
	{
		summ += (**сylinder).MathS();
	}

	return summ;
}

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void showTableCylinder(const char* title, Cylinder** cylinders, int n, int maxIndex)
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
		setColor(cylinders[i][0].MathV() == cylinders[maxIndex][0].MathV() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i][0].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +—————+—————————————————+————————————————+—————————————————————————————————+\n";
} // showTable

// перегрузка операции прибавления числа к цилиндру
Cylinder* operator+(Cylinder cyl, double num)
{
	// создание цилиндра на куче
	Cylinder* cylinder = new Cylinder();

	// прибавление к радиусу числа
	cylinder->setRadius(cyl.getRadius() + num);

	// прибавление к высоте числа
	cylinder->setHeight(cyl.getHeight() + num);

	return cylinder;
}

// перегрузка операции деления цилиндра на число
Cylinder* operator/(Cylinder cyl, double num)
{
	// создание цилиндра на куче
	Cylinder* cylinder = new Cylinder;

	// деление радиуса на число
	cylinder->setRadius(cyl.getRadius() / num);

	// деление высоты на число
	cylinder->setHeight(cyl.getHeight() / num);

	return cylinder;
}