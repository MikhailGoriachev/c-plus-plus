#include "pch.h"
#include "Conoid.h"

// генерация данных усечённого конуса
void generConoid(Conoid* conoid, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// высота
		conoid[i].setHeight(getRand(1., 50.));

		// радиус 1
		conoid[i].setRadius1(getRand(1., 50.));
		
		// радиус 2
		conoid[i].setRadius2(getRand(1., 50.));

		// если радиус 1 меньше радиуса 2
		if (conoid[i].getRadius1() < conoid[i].getRadius2())
		{
			double tmp = conoid[i].getRadius1();
			conoid[i].setRadius1(conoid[i].getRadius2());
			conoid[i].setRadius2(tmp);
		}
	}

}

// нахождение индекса конуса с максимальной площадью конуса
int maximumIndex(Conoid** conoid, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (conoid[max][0].MathS() < conoid[i + 1][0].MathS())
		{
			max = i + 1;
		}
	}

	return max;
}

// сумма объёма
double summV(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

// сумма площади
double summS(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void showTableConoids(const char* title, Conoid** conoids, int n, int maxIndex)
{
	setColor(headerColor);

	cout << title
		<< "\t    +—————+—————————————————+————————————————+————————————————+————————————————+————————————————+\n"
		<< "\t    |  N  |    Радиус, R    |    Радиус, r   |    Высота, H   |   Площадь, S   |    Объем, V    |\n"
		<< "\t    +—————+—————————————————+————————————————+————————————————+————————————————+————————————————+\n";

	setColor(mainColor);

	// выводим строки таблицы цилиндров, с выделением цветом
	// строки с минимальным объемом, перед и после этой строки
	// выводим цветовые "хвостики"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(conoids[i][0].MathS() == conoids[maxIndex][0].MathS() ? acctColor : mainColor);

		setColor(headerColor);

		cout << "    " << "| " << setw(3) << i + 1;	

		setColor(mainColor);

		// перегрузка вывода
		cout << conoids[i][0];

		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i

	setColor(headerColor);

	cout << "\t    +—————+—————————————————+————————————————+————————————————+————————————————+————————————————+\n";

	setColor(mainColor);
} // showTable

// дружественная функция класса Conoid. перегрузка операции вывода << 
ostream& operator<<(ostream& link, Conoid& con)
{
	link << " | " << setw(15) << con.radius1_
		<< " | " << setw(14) << con.radius2_
		<< " | " << setw(14) << con.height_
		<< " | " << setw(14) << con.MathS()
		<< " | " << setw(14) << con.MathV()
		<< " |";

	return link;
}

// дружественная функция класса Conoid. перегрузка операции ввода >> 
istream& operator>>(istream& link, Conoid& con)
{
	cout << "Введите высоту конуса: ";
	link >> con.height_;

	cout << endl;

	cout << "Введите радиус 1: ";

	cout << endl;

	link >> con.radius1_;

	cout << endl;

	cout << "Введите радиус 2: ";

	cout << endl;

	link >> con.radius2_;
	
	// если радиус 1 меньше радиуса 2
	if (con.radius1_ < con.radius2_)
	{
		double tmp = con.radius1_;
		con.radius1_ = con.radius2_;
		con.radius2_ = tmp;
	}

	return link;

}

// суммарная площадь
double allSummV(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathV();
	}

	return num;
}

// сумма площадь
double allSummS(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathS();
	}

	return num;
}