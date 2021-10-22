#include "app.h"
#include "pch.h"
#include "task1.h"
#include "Conoid.h"

using namespace std;

void task1()
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
		*conoids_p = new Conoid(getRand(1., 10.), getRand(1., 10.), getRand(1., 10.));
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
		cout << "\n\n\n\n\n\n\t\tESC ВЫХОД" << endl;

		
		cout << "\n\n\n\t\tВыберите пункт...";

		// проверка ввода 
		while (true)
		{
			n = getKey("");

			// если значение n входит в один из пунктов
			if (n < '4' && n > '0')
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

					cin >> *res;

					cout << endl;

					cout << "\n\n\t\t\t\tРезультат ввода конуса" << endl;

					break;

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