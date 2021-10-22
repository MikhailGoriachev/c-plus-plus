#include "App.h"
#include "pch.h"
#include "Conoid.h"

/*
*	Создайте класс, описывающий усеченный конус Conoid (поля радиус нижнего основания, радиус
*	верхнего основания и высота, тип полей – double). Реализуйте конструкторы (по умолчанию,
*	и инициирующий – задающий радиусы и высоту усеченного конуса), деструктор (выводящий
*	сообщение «Conoid: Объект уничтожен») геттеры и сеттеры (выбрасывать исключение при нулевом
*	или отрицательном значении параметра). Реализуйте методы, вычисляющие и возвращающие площадь
*	и объем усеченного конуса, метод вывода данных усеченного конуса (радиусы и высота, площадь
*	поверхности и объем) в виде строки таблицы.
*	Создайте динамический массив из n усеченных конусов, радиусы и высота – случайные числа.
*	Размер массива вводите с клавиатуры.
*	Выведите массив в консоль в табличном виде: радиусы и высота, площадь и объем. При выводе
*	выделите конус/конусы с площадью поверхности, равноймаксимальной, выводите также суммарную
*	площадь, и суммарный объем усеченных конусов.
*	Перегрузите операции методами класса:
*	•	+ сложение двух конусов, состоящую в сложении радиусов и высот двух конусов
*	•	* умножение радиусов и высот конуса на вещественное число, выбрасывать исключение при
*		некорректной операции
*	•	– вычитание вещественного числа из радиусов и высоты конусов, выбрасывать исключение
*		при некорректной операции
*	Перегрузите операции дружественными функциями класса:
*	•	>> операция ввода
*	•	<< операция вывода данных конуса (радиусы и высота, площадь поверхности и объем) в
*		виде строки таблицы
*	Продемонстрируйте операцию ввода и сложения для двух конусов.
*	Выполните остальные операции со всеми элементами динамического массива конусов.
*
*/


// генерация данных усечённого конуса
void App::generConoid(Conoid* conoid, size_t size)
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
int App::maximumIndex(Conoid** conoid, size_t size)
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
double App::summV(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

// сумма площади
double App::summS(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}

// вывод массива цилиндров в табличном формате, горизонтальная линия: — Alt+0151
void App::showTableConoids(const char* title, Conoid** conoids, int n, int maxIndex)
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
	link >> con.height_ >> con.radius1_ >> con.radius2_;

	// если высота меньше или равна нулю
	if (con.height_ <= 0)
	{
		throw exception("Введённая высота должна быть больше нуля!");
	}

	// если радиус основания меньше радиуса вершины
	if (con.radius1_ < con.radius2_)
	{
		throw exception("Радиус основания должен быть больше радиуса вершины!");
	}

	return link;
}

// суммарный объём
double App::allSummV(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathV();
	}

	return num;
}

// суммарная площадь
double App::allSummS(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathS();
	}

	return num;
}

// Задание 1
void App::task1()
{
	setColor(mainColor);

	cls();

	setColor(headerColor);

	cout << "\n\n\t\t\t\tЗадание 1\n\n";

	cout << "\t\tСоздайте класс, описывающий усеченный конус Conoid (поля радиус\n"
		<< "\t\tнижнего основания, радиус верхнего основания и высота, тип полей – double). \n"
		<< "\t\tРеализуйте конструкторы (по умолчанию, и инициирующий – задающий \n"
		<< "\t\tрадиусы и высоту усеченного конуса), деструктор (выводящий сообщение \n"
		<< "\t\t«Conoid: Объект уничтожен») геттеры и сеттеры (выбрасывать исключение \n"
		<< "\t\tпри нулевом или отрицательном значении параметра). Реализуйте методы, \n"
		<< "\t\tвычисляющие и возвращающие площадь и объем усеченного конуса, метод\n"
		<< "\t\tвывода данных усеченного конуса (радиусы и высота, площадь поверхности\n"
		<< "\t\tи объем) в виде строки таблицы. \n\n"
		<< "\t\tСоздайте массив из 5и усеченных конусов, радиусы и высота – случайные числа. \n"
		<< "\t\tВыведите массив в консоль в табличном виде: радиусы и высота, площадь и \n"
		<< "\t\tобъем. При выводе выделите конус/конусы с площадью поверхности, равной \n"
		<< "\t\tмаксимальной, выводите также суммарную площадь, объем усеченных конусов.\n\n"
		<< "\t\tПерегрузите операции методами класса:\n\n"
		<< "\t\t\t•	+ сложение двух конусов, состоящую в сложении радиусов и высот двух конусов\n\n"
		<< "\t\t\t•	* умножение радиусов и высот конуса на вещественное число\n\n"
		<< "\t\t\t•	– вычитание вещественного числа из радиусов и высоты конусов, выбрасывать \n"
		<< "\t\t\t\tисключение при некорректной операции\n\n"
		<< "\t\t\t•	>> операция ввода\n\n"
		<< "\t\t\t•	<< операция вывода данных конуса (радиусы и высота, площадь поверхности \n"
		<< "\t\t\t\tи объем) в виде строки таблицы \n\n";

	setColor(headerColor);

	getKey();

	cls();

	// количество цилиндров
	int size;

	setCursorVisible(true);

	// ввод количества создаваемых усеченных конусов
	cout << "\n\n\t\tВведите колчество усеченных конусов: ";

	cin >> size;

	if (size < 1)
	{
		// сообщение exception на тот случай, если будут введены неправильные данные
		throw exception("Количество усеченных конусов должно быть больше нуля!");
	}

	// отчистка экрана
	cls();

	// массив указателей на усеченные конусов
	Conoid** conoids = new Conoid * [size];

	// заполнение цилиндров 
	for (Conoid** conoids_p = conoids; conoids_p < conoids + size; conoids_p++)
	{
		double temp = getRand(1.7, 5.);

		*conoids_p = new Conoid(getRand(1.7, 5.), temp + getRand(1.7, 5.), temp);
	}

	// выключение курсора
	setCursorVisible(false);

	char n;

	// цилиндр результирующий
	Conoid* res = new Conoid();

	// переменные для операций с цилиндрами
	int a, b;
	double num;

	while (true)
	{
		cls();

		// вывод таблицы
		showTableConoids("\n\n\n\t\t\t\t\tТаблица\n", conoids, size, maximumIndex(conoids, size));

		setColor(headerColor);

		cout << setw(38) << " | " << setw(41) << right << "Суммарная площадь: " << allSummS(conoids, size) << " |" << endl;

		cout << setw(38) << " | " << setw(41) << right << "Суммарный объём: " << allSummV(conoids, size) << " |" << endl;


		cout << "\n\n\n\n\t\t1. Сложение двух конусов (методами класса)" << endl;
		cout << "\n\n\n\n\t\t2. Умножение число (методами класса)" << endl;
		cout << "\n\n\n\n\t\t3. Ввод конукса (функции общего назначения)" << endl;
		cout << "\n\n\n\n\t\t4. Вычитание числа (методами класса)" << endl;
		cout << "\n\n\n\n\n\n\t\tESC ВЫХОД" << endl;


		cout << "\n\n\n\t\tВыберите пункт...";

		// проверка ввода 
		while (true)
		{
			n = getKey("");

			// если значение n входит в один из пунктов
			if (n < '5' && n > '0')
			{
				// включение курсора
				setCursorVisible(true);

				cls();

				// вывод таблицы
				showTableConoids("\n\n\n\t\t\t\t\tТаблица\n", conoids, size, maximumIndex(conoids, size));

				setColor(headerColor);

				cout << setw(38) << " | " << setw(41) << right << "Суммарная площадь: " << allSummS(conoids, size) << " |" << endl;

				cout << setw(38) << " | " << setw(41) << right << "Суммарный объём: " << allSummV(conoids, size) << " |" << endl;

				switch (n)
				{

					// 1. Сложение двух конусов (методами класса)
				case '1':

					cout << "\n\n\t\t\t\t\t\tСложение двух конусов\n" << endl;

					cout << "\tВыберите первый конус: ";
					cin >> a;

					cout << endl;

					cout << "\tВыберите второй конус: ";
					cin >> b;

					// указатель возвращаемый цилиндр
					res = conoids[a - 1][0] + conoids[b - 1][0];

					cout << "\n\n\t\t\t\tРезультат сложения конуса " << a << " и конуса " << b << endl;

					break;

					// 2. Умножение число (методами класса)
				case '2':

					cout << "\n\n\t\t\t\t\t\tУмножение конуса на число\n" << endl;

					cout << "\tВыберите конус: ";
					cin >> a;

					cout << endl;

					cout << "\tВведите число - множитель: ";
					cin >> num;

					// указатель возвращаемый цилиндр
					res = conoids[a - 1][0] * num;

					cout << "\n\n\t\t\t\tРезультат умножения конуса " << a << " на число " << num << endl;

					break;

					// 3. Ввод конуса (функции общего назначения)
				case '3':

					cout << "\n\n\t\t\t\t\t\tВвод конуса\n" << endl;

					res = new Conoid;

					cout << "Введите данные конуса(высота(H), радиус основания(R), радиус вершины(r)): ";
					cin >> *res;

					cout << endl;

					cout << "\n\n\t\t\t\tРезультат ввода конуса" << endl;

					break;

				case '4':

					cout << "\n\n\t\t\t\t\t\tВычитание из конуса числа\n" << endl;

					cout << "\tВыберите конус: ";
					cin >> a;

					cout << endl;

					cout << "\tВведите вычитаемое число: ";
					cin >> num;

					// указатель возвращаемый цилиндр
					res = conoids[a - 1][0] - num;

					cout << "\n\n\t\t\t\tРезультат вычитания из конуса " << a << " числа " << num << endl;



				default:
					break;
				}

				cout << endl;

				showTableConoids("", &res, 1, 0);

				cout << endl;

				// удаление цилиндра
				delete res;

				getKey();

				// выключение курсора
				setCursorVisible(false);

				break;
			}

			if (n == 27)
			{
				// удаление цилиндров
				for (size_t i = 0; i < size; i++)
				{

					delete conoids[i];
				}

				delete[] conoids;

				return;
			}
		}
	}

}

