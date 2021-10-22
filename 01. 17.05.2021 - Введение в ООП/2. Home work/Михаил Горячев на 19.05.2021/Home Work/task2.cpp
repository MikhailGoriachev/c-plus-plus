#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "head.h"
#include "TConoid.h"

// генерация данных усечённого конуса
void generData(CONOID* conoid, size_t size)
{
	srand(time(0));

	// максимальное значение 
	const int max = 80;

	// число после запятой 
	double n;

	for (CONOID* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		// высота
		conoid_p->height = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		conoid_p->height += n;

		// радиус 1
		conoid_p->radius1 = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		conoid_p->radius1 += n;

		// радиус 2
		conoid_p->radius2 = rand() % max;

		n = rand() % 1000;

		n /= 1000;

		conoid_p->radius2 += n;

		// если радиус 1 меньше радиуса 2
		conoid_p->radius1 < conoid_p->radius2 ? swap(conoid_p->radius1, conoid_p->radius2) : (void)false;
	}
}

// минимальное число
template <typename T>
inline bool minNumber(T a, T b)
{
	return a < b;
}

// нахождение минимальной площади конуса
int minimumIndex(CONOID* conoid, size_t size)
{
	int min = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		minNumber(conoid[min].MathS(), conoid[i + 1].MathS()) ? false : min = i + 1;
	}

	return min;
}

double summV(CONOID* conoid, size_t size)
{
	double summ = 0.0;

	for (CONOID* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

double summS(CONOID* conoid, size_t size)
{
	double summ = 0.0;

	for (CONOID* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}

void task2()
{
	cls();

	gotoXY(50, 2);

	cout << "Задание 2" << endl;

	cout << "\t\tСоздайте структуру, описывающую усеченный конус TConoid (поля радиус\n"
		<< "\t\tнижнего основания, радиус верхнего основания и высота, тип полей – double).\n"
		<< "\t\tРеализуйте методы, вычисляющие и возвращающиеплощадь и объемусеченного конуса,\n"
		<< "\t\tметод вывода данных усеченного конуса (радиусы и высота, площадь поверхности и \n"
		<< "\t\tобъем) в виде строки таблицы.\n\n"
		<< "\t\tСоздайте массив из 5и усеченных конусов, радиусы и высота – случайные числа.\n"
		<< "\t\tВыведите массив в консоль в табличном виде : радиусы и высота, площадь и объем.При\n"
		<< "\t\tвыводе выделитеконус / конусы с площадью поверхности, равной минимальной, выводите \n"
		<< "\t\tтакже суммарную площадь, объем усеченных конусов.\n\n";

	// количество конусов
	int n;

	// ввод количества конусов
	cout << "\n\n\tВведите количество усечённых конусов: ";
	cin >> n;

	// массив структур конусов
	CONOID* cons = new CONOID[n];

	generData(cons, n);

	showTableConoids("\t\t\t\t\tРЕЗУЛЬТАТ\n", cons, n, minimumIndex(cons, n));

	cout << "\t\t\t\t\t\t\t\tСуммарный объём: " << summV(cons, n) << endl << endl;
	cout << "\t\t\t\t\t\t\t\tСуммарная площадь: " << summS(cons, n) << endl << endl;

	delete[] cons;

	_getch();
}