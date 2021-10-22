#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "TCylinder.h"     // для использования структуры TCylinder
#include "head.h"

// генерация данных цилиндра
void generData(CYLINDER* clndr, size_t size)
{
	srand(time(0));

	// максимальное значение 
	const int max = 80;

	// число после запятой 
	double n;

	for (CYLINDER* clndr_p = clndr; clndr_p < clndr + size; clndr_p++)
	{
		// высота
		clndr_p->height = rand() % max;
		
		n = rand() % 1000;

		n /= 1000;

		clndr_p->height += n;

		// радиус
		clndr_p->radius = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		clndr_p->radius += n;
	}
}

// максимальное число
template <typename T>
inline bool maxNumber(T a, T b)
{
	return a > b;
}

// нахождение максимального объёма цилиндра
int maximumIndex(CYLINDER* clndr, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		maxNumber(clndr[max].MathV(), clndr[i + 1].MathV()) ? false : max = i + 1;
	}

	return max;
}

// компоратор сложения
template <typename T>
T compSumm(T a, T b)
{
	return a + b;
}

// суммарный объём цилиндров
double summV(CYLINDER* clndr, size_t size)
{
	double summ = 0.0;

	for (CYLINDER* clndr_p = clndr; clndr_p < clndr + size; clndr_p++)
	{
		summ += clndr_p->MathV();
	}

	return summ;
}

void task1()
{
	cls();

	gotoXY(50, 2);

	cout << "Задание 1" << endl << endl;

	cout << "\t\tСоздайте структуру, описывающую цилиндр TCylinder (поля радиус и высота,\n"
		<< "\t\tтип полей –double). Реализуйте методы, вычисляющие и возвращающие площадь\n"
		<< "\t\tи объем цилиндра, метод вывода радиуса и высоты цилиндра в консоль, метод\n"
		<< "\t\tвывода данных цилиндра (радиус, высоту, площадь поверхности и объем) в \n"
		<< "\t\tвиде строки таблицы.\n\n"
		<< "\t\tСоздайте массив из 8и цилиндров, радиус и высота – случайные числа. \n"
		<< "\t\tВыведите массив в консоль в табличном виде : радиус и высота цилиндра, \n"
		<< "\t\tплощадь и объем. При выводе выделите цилиндр / цилиндры с объемом, равным\n"
		<< "\t\tмаксимальному, выводите также суммарный объем цилиндров.\n";

	// количество цилиндров
	size_t n;

	// ввод количество цилиндров
	cout << "\n\n\tВведите количество цилиндров: ";
	cin >> n;

	// создание цилиндров
	CYLINDER* clndr = new CYLINDER[n];

	// генерирование случайных данных
	generData(clndr, n);

	// находение индекса цилиндра с максимальным объёмом
	int indexMax = maximumIndex(clndr, n);

	showTable("\t\t\t\t\tРЕЗУЛЬТАТ\n", clndr, n, indexMax);

	cout << "\t\t\t\t\t\t\t\tСуммарный объём: " << summV(clndr, n);

	delete[] clndr;

	_getch();
}