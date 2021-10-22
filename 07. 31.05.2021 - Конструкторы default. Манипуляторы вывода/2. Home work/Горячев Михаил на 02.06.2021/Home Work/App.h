#pragma once
#include "pch.h"
#include "MatrixDouble.h"
#include "MatrixInt.h"

// структура данных о столбце матрицы
struct matrixIntCols_t
{
	// поле суммы отрицательных нечётных элементов по модулю
	int summerCols = 0;

	// индекс столбца
	int indexCols;
};

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
public:

	// задание 1
	void task1();

	// вывод матрицы (double)
	void printMatrix(MatrixDouble& mtx);
	
	// вывод матрицы (int)
	void printMatrix(MatrixInt& mtx);

	// заполнение матрицы случайными числа (double)
	void fillMatrix(MatrixDouble& mtx, double low, double high);

	// заполнение матрицы случайными числа (int)
	void fillMatrix(MatrixInt& mtx, int low, int high);

	// сумма элементов столбца, в котором есть отрицательные элементы (double)
	double sumElem(MatrixDouble& mtx);
	
	// сумма нечётных отрицательных элементов столбца по модулю
	matrixIntCols_t* sumIntCols(MatrixInt& mtx);

	// вывод сумм отрицательных нечетных значений элементов
	// столбцов матрицы
	void printSumCls(matrixIntCols_t* p_data, int size);

	// сортировка столбцов и перемещение их по порядку возростания
	// по сумме отрицательных нечётных элементов столбцов
	MatrixInt& moveColsMatrix(MatrixInt& mtx, matrixIntCols_t* p_data);

	// сортировка вставками
	void insertSort(matrixIntCols_t* p_data, int size);

	// проверка на принадлежность элемента к седловой точке матрицы
	bool SaddlePoint(MatrixInt& mtx, int rows, int cols);
};	

