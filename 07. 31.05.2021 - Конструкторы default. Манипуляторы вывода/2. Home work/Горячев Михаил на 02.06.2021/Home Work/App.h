#pragma once
#include "pch.h"
#include "MatrixDouble.h"
#include "MatrixInt.h"

// ��������� ������ � ������� �������
struct matrixIntCols_t
{
	// ���� ����� ������������� �������� ��������� �� ������
	int summerCols = 0;

	// ������ �������
	int indexCols;
};

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
public:

	// ������� 1
	void task1();

	// ����� ������� (double)
	void printMatrix(MatrixDouble& mtx);
	
	// ����� ������� (int)
	void printMatrix(MatrixInt& mtx);

	// ���������� ������� ���������� ����� (double)
	void fillMatrix(MatrixDouble& mtx, double low, double high);

	// ���������� ������� ���������� ����� (int)
	void fillMatrix(MatrixInt& mtx, int low, int high);

	// ����� ��������� �������, � ������� ���� ������������� �������� (double)
	double sumElem(MatrixDouble& mtx);
	
	// ����� �������� ������������� ��������� ������� �� ������
	matrixIntCols_t* sumIntCols(MatrixInt& mtx);

	// ����� ���� ������������� �������� �������� ���������
	// �������� �������
	void printSumCls(matrixIntCols_t* p_data, int size);

	// ���������� �������� � ����������� �� �� ������� �����������
	// �� ����� ������������� �������� ��������� ��������
	MatrixInt& moveColsMatrix(MatrixInt& mtx, matrixIntCols_t* p_data);

	// ���������� ���������
	void insertSort(matrixIntCols_t* p_data, int size);

	// �������� �� �������������� �������� � �������� ����� �������
	bool SaddlePoint(MatrixInt& mtx, int rows, int cols);
};	

