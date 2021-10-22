#include "App.h"
#include "pch.h"
#include "Utils.h"
#include "MatrixDouble.h"
#include "MatrixInt.h"

#pragma region Задание 1

#pragma region Тело Задания 1
// Задание 1 
void App::task1()
{
	/*
	 * Измените класс MatrixDouble из предыдущего задания для хранения вещественных чисел (тип double).
	 * В консольном приложении методами класса App реализуйте обработки по заданию
	 *	•	Заполните объект класса MatrixDouble из заданного количества строк и столбцов случайными числами
	 *		типа double. Количество строк и столбцов, диапазон значений для заполнения задавайте с клавиатуры.
	 *	•	Найти сумму элементов в строках, содержащих хотя бы один отрицательный элемент
	 *	•	Характеристикой столбца целочисленной матрицы назовем сумму модулей его отрицательных нечетных
	 *		элементов. Переставляя столбцы заданной матрицы, расположите их в соответствии с ростом характеристик
	 *	•	Матрица А имеет седловую точку А(i, j), если А(i, j)является минимальным элементом в i-й строке
	 *		и максимальным в j-м столбце. Найдите и выделите цветом все седловые точки матрицы
	 *
	 */

#pragma region Матрица вещественных чисел
	cls();

	// количество строк и столбцов
	int rows, cols;
	double lowDouble , highDouble;

	cout << "\n\n\t\t\t\t";
	cputs("Создание матрицы вещественных чисел\n\n", arrColor);

	// ввод количества строк
	cout << "\t\tВведите количество строк: ";
	cin >> rows;

	// ввод количества столбцов
	cout << "\n\n\t\tВведите количество столбцов: ";
	cin >> cols;

	cout << "\n\n\t\t\t\t";
	cputs("Значения матрицы будут сгенерированны\n\n", arrColor);
	
	// ввод минимального значения в диапазоне элементов
	cout << "\n\n\t\tВведите минимальное значение элемента: ";
	cin >> lowDouble;

	// ввод максимального значения в диапазоне элементов
	cout << "\n\n\t\tВведите максимальное значение элемента: ";
	cin >> highDouble;

	// если минимальное значение больше максимального
	if (lowDouble > highDouble)
		throw exception("Минимальное значение диапазона должно быть меньше максимального!");

	getKey();
	
	cls();

	// объект класса MatrixDouble
	MatrixDouble* p_mtxDouble = new MatrixDouble(rows, cols);

	// ссылка на матрицу
	MatrixDouble& mtxDouble = *p_mtxDouble;
		
	// инициализирование матрицы случайными элементами
	// в указанном диапазоне
	fillMatrix(mtxDouble, lowDouble, highDouble);

	cputs("\n\n\t\t\t\t\tВещественная матрица\n\n", arrColor);
	
	// вывод матрицы
	printMatrix(mtxDouble);

	cout << "\n\n\n";

	cout << "\t\tСумма элементов в строках с отрицательными элементами: " << sumElem(mtxDouble) << endl << endl;
	
	getKey();

	cls();
	
#pragma endregion 

#pragma region Целочисленная матрица

	int lowInt, highInt;
	
	cout << "\n\n\n\t\t\t\t";

	cputs("Матрица целочисленная\n", arrColor);

	cout << "\n\n\t\t\t\t";
	cputs("Создание целочисленной матрицы\n\n", arrColor);

	// ввод количества строк
	cout << "\t\tВведите количество строк: ";
	cin >> rows;

	// ввод количества столбцов
	cout << "\n\n\t\tВведите количество столбцов: ";
	cin >> cols;

	cout << "\n\n\t\t\t\t";
	cputs("Значения матрицы будут сгенерированны\n\n", arrColor);

	// ввод минимального значения в диапазоне элементов
	cout << "\n\n\t\tВведите минимальное значение элемента: ";
	cin >> lowInt;

	// ввод максимального значения в диапазоне элементов
	cout << "\n\n\t\tВведите максимальное значение элемента: ";
	cin >> highInt;

	// если минимальное значение больше максимального
	if (lowInt > highInt)
		throw exception("Минимальное значение диапазона должно быть меньше максимального!");

	getKey();

	cls();

	// объект класса MatrixInt
	MatrixInt* p_mtxInt = new MatrixInt(rows, cols);

	// ссылка на матрицу
	MatrixInt& mtxInt = *p_mtxInt;

	// инициализирование матрицы случайными элементами
	// в указанном диапазоне
	fillMatrix(mtxInt, lowInt, highInt);

	cputs("\n\n\t\t\t\t\tЦелочисленная матрица\n\n", arrColor);

	// вывод матрицы
	printMatrix(mtxInt);

	// указатель на массив структур данных столбцах о матрице
	matrixIntCols_t* p_data = sumIntCols(mtxInt);
	
	// вывод сумм отрицательных нечетных значений элементов
	// столбцов матрицы
	printSumCls(p_data, mtxInt.cols());

	cputs("\n\n\t\t\t\t\tПерестановка столбцов по возростанию суммы\n\n", arrColor);
	
	// сортировка матрицы
	mtxInt = moveColsMatrix(mtxInt, p_data);
	
	// вывод матрицы
	printMatrix(mtxInt);

	// вывод сумм отрицательных нечетных значений элементов
	// столбцов матрицы
	printSumCls(p_data, mtxInt.cols());

	
	cout << "\n\n\n";

	getKey();
	
#pragma endregion 	
}

#pragma region Методы Задания 1

// вывод матрицы в виде таблицы (double)
void App::printMatrix(MatrixDouble& mtx)
{
	// вывод матрицы
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		cout << "\t\t+";
		for (size_t i = 0; i < mtx.cols(); i++)
		{
			cout << "—————————+";
		}

		cout << "\n\t\t";

		for (size_t k = 0; k < mtx.cols(); k++)
		{
			cout << "| " << setw(8) << mtx(i, k);

			// если это последний элемент то будет выведена линия
			if (k == mtx.cols() - 1)
			{
				cout << "|" << endl;
			}


		}
	}

	cout << "\t\t+";
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		cout << "—————————+";
	}

}

// вывод матрицы в виде таблицы (int)
void App::printMatrix(MatrixInt& mtx)
{
	// цвет
	short cl = getColor();
	
	// вывод матрицы
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		cout << "\t\t+";
		for (size_t i = 0; i < mtx.cols(); i++)
		{
			cout << "—————————+";
		}

		cout << "\n\t\t";

		for (size_t k = 0; k < mtx.cols(); k++)
		{
			// если элемент является седловой точкой 
			setColor(SaddlePoint(mtx, i, k) ? arrColor : cl);
			
			cout << "| " << setw(8) << mtx(i, k);

			// если это последний элемент то будет выведена линия
			if (k == mtx.cols() - 1)
			{
				cout << "|" << endl;
			}
		}
	}

	setColor(cl);
	
	cout << "\t\t+";
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		cout << "—————————+";
	}

}

// заполнение матрицы случайными числа (double)
void App::fillMatrix(MatrixDouble& mtx, double low, double high)
{
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		for (size_t k = 0; k < mtx.cols(); k++)
		{
			mtx(i, k) = getRand(low, high);
		}
	}
}

// заполнение матрицы случайными числа (int)
void App::fillMatrix(MatrixInt& mtx, int low, int high)
{
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		for (size_t k = 0; k < mtx.cols(); k++)
		{
			mtx(i, k) = getRand(low, high);
		}
	}
}

// сумма элементов столбца, в котором есть отрицательные элементы
double App::sumElem(MatrixDouble& mtx)
{
	// сумма элементов 
	double sum = 0;
	
	// сумма столбца
	double sumTmp = 0;

	// флаг вхождения отрицательного элемента в строку
	bool flag = false;
	
	for (int i = 0; i < mtx.cols(); i++)
	{
		flag = false;
		
		for (int k = 0; k < mtx.rows(); k++)
		{
			sumTmp += mtx(k, i);
			
			// если число является положительным
			if (mtx(k, i) <= 0)
			{
				flag = true;
			}
		}

		flag ? sum += sumTmp : sumTmp = 0;

		sumTmp = 0;
	}

	return sum;
}

// сумма нечётных отрицательных элементов столбца по модулю
// возвращает указатель на массив структур данных столбцах о матрице
matrixIntCols_t* App::sumIntCols(MatrixInt& mtx)
{
	matrixIntCols_t* p_data = new matrixIntCols_t[mtx.cols()];
	
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		// ссылка на текущий элемент в массиве структур matrixIntCols_t
		matrixIntCols_t& data = p_data[i];

		data.indexCols = i;
		
		for (size_t k = 0; k < mtx.rows(); k++)
		{
			// если значение элемента нечётное и отрицательное
			if (k != 0 && mtx(k, i) % 2 == -1 /*&& mtx(k, i) < 0*/)
			{
				data.summerCols += -1 * mtx(k, i);
			}
		}
	}

	return p_data;
}

// вывод сумм отрицательных нечетных значений элементов
// столбцов матрицы
void App::printSumCls(matrixIntCols_t* p_data, int size)
{
	// вывод сумм отрицательных нечетных значений элементов
	// столбцов матрицы

	short int cl = getColor();
	
	setColor(headerColor);
	
	cout << "\n\t\t\t\tСумма отрицательных нечётных элементов столбца\n";
	
	cout << "\t\t+";
	for (size_t i = 0; i < size; i++)
	{
		cout << "—————————+";
	}

	cout << "\n\t\t";

	for (size_t k = 0; k < size; k++)
	{

		matrixIntCols_t& data = p_data[k];
		
		cout << "| " << setw(8) << data.summerCols;

		// если это последний элемент то будет выведена линия
		if (k == size - 1)
		{
			cout << "|" << endl;
		}


	}
	
	cout << "\t\t+";
	for (size_t i = 0; i < size; i++)
	{
		cout << "—————————+";
	}

	setColor(cl);
}

// сортировка столбцов и перемещение их по порядку возростания
// по сумме отрицательных нечётных элементов столбцов
MatrixInt& App::moveColsMatrix(MatrixInt& mtx, matrixIntCols_t* p_data)
{
	// новая матрица в которую будет перенена перенесённая матрица
	MatrixInt* p_matrixTemp = new MatrixInt(mtx.rows(), mtx.cols());

	// ссылка на объект MatrixInt
	MatrixInt& matrixTemp = *p_matrixTemp;
	
	// сортировка массива объектов matrixIntCols_t
	insertSort(p_data, mtx.cols());

	// копирование матрицы в новую матрицу в порядке возростания
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		// ссылка на объект matrixIntCols_t
		matrixIntCols_t& data = p_data[i];

		for (size_t k = 0; k < mtx.rows(); k++)
		{
			matrixTemp(k, i) = mtx(k, data.indexCols);
		}
	}

	// отчистка памяти от несортированной матрицы
	//delete &mtx;
	
	return matrixTemp;
}

// сортировка вставками
void App::insertSort(matrixIntCols_t* p_data, int size)
{
	// Перебираем каждый элемент массива (кроме последнего, он уже будет отсортирован к тому времени, когда мы до него доберемся)
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации.
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int smallestIndex = startIndex;

		// Затем ищем элемент поменьше в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			// Если мы нашли элемент, который меньше нашего наименьшего элемента,
			if (p_data[currentIndex].summerCols < p_data[smallestIndex].summerCols)
				// то запоминаем его
				smallestIndex = currentIndex;
		}

		// smallestIndex теперь наименьший элемент. 
				// Меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
		swap(p_data[startIndex], p_data[smallestIndex]);
	}
}

// проверка на принадлежность элемента к седловой точке матрицы
bool App::SaddlePoint(MatrixInt& mtx, int rows, int cols)
{
	// текущий элемент
	int tmp = mtx(rows, cols);

	// проверка по горизонтали
	for (int i = 0; i < mtx.cols(); i++)
	{
		if (tmp > mtx(rows, i))
			return false;
	}
	
	// проверка по вертикали
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		if (tmp < mtx(i, cols))
			return false;
	}

	return true;
}

#pragma endregion