#include "App.h"
#include "pch.h"
#include "Utils.h"
#include "MatrixDouble.h"
#include "MatrixInt.h"

#pragma region ������� 1

#pragma region ���� ������� 1
// ������� 1 
void App::task1()
{
	/*
	 * �������� ����� MatrixDouble �� ����������� ������� ��� �������� ������������ ����� (��� double).
	 * � ���������� ���������� �������� ������ App ���������� ��������� �� �������
	 *	�	��������� ������ ������ MatrixDouble �� ��������� ���������� ����� � �������� ���������� �������
	 *		���� double. ���������� ����� � ��������, �������� �������� ��� ���������� ��������� � ����������.
	 *	�	����� ����� ��������� � �������, ���������� ���� �� ���� ������������� �������
	 *	�	��������������� ������� ������������� ������� ������� ����� ������� ��� ������������� ��������
	 *		���������. ����������� ������� �������� �������, ����������� �� � ������������ � ������ �������������
	 *	�	������� � ����� �������� ����� �(i, j), ���� �(i, j)�������� ����������� ��������� � i-� ������
	 *		� ������������ � j-� �������. ������� � �������� ������ ��� �������� ����� �������
	 *
	 */

#pragma region ������� ������������ �����
	cls();

	// ���������� ����� � ��������
	int rows, cols;
	double lowDouble , highDouble;

	cout << "\n\n\t\t\t\t";
	cputs("�������� ������� ������������ �����\n\n", arrColor);

	// ���� ���������� �����
	cout << "\t\t������� ���������� �����: ";
	cin >> rows;

	// ���� ���������� ��������
	cout << "\n\n\t\t������� ���������� ��������: ";
	cin >> cols;

	cout << "\n\n\t\t\t\t";
	cputs("�������� ������� ����� ��������������\n\n", arrColor);
	
	// ���� ������������ �������� � ��������� ���������
	cout << "\n\n\t\t������� ����������� �������� ��������: ";
	cin >> lowDouble;

	// ���� ������������� �������� � ��������� ���������
	cout << "\n\n\t\t������� ������������ �������� ��������: ";
	cin >> highDouble;

	// ���� ����������� �������� ������ �������������
	if (lowDouble > highDouble)
		throw exception("����������� �������� ��������� ������ ���� ������ �������������!");

	getKey();
	
	cls();

	// ������ ������ MatrixDouble
	MatrixDouble* p_mtxDouble = new MatrixDouble(rows, cols);

	// ������ �� �������
	MatrixDouble& mtxDouble = *p_mtxDouble;
		
	// ����������������� ������� ���������� ����������
	// � ��������� ���������
	fillMatrix(mtxDouble, lowDouble, highDouble);

	cputs("\n\n\t\t\t\t\t������������ �������\n\n", arrColor);
	
	// ����� �������
	printMatrix(mtxDouble);

	cout << "\n\n\n";

	cout << "\t\t����� ��������� � ������� � �������������� ����������: " << sumElem(mtxDouble) << endl << endl;
	
	getKey();

	cls();
	
#pragma endregion 

#pragma region ������������� �������

	int lowInt, highInt;
	
	cout << "\n\n\n\t\t\t\t";

	cputs("������� �������������\n", arrColor);

	cout << "\n\n\t\t\t\t";
	cputs("�������� ������������� �������\n\n", arrColor);

	// ���� ���������� �����
	cout << "\t\t������� ���������� �����: ";
	cin >> rows;

	// ���� ���������� ��������
	cout << "\n\n\t\t������� ���������� ��������: ";
	cin >> cols;

	cout << "\n\n\t\t\t\t";
	cputs("�������� ������� ����� ��������������\n\n", arrColor);

	// ���� ������������ �������� � ��������� ���������
	cout << "\n\n\t\t������� ����������� �������� ��������: ";
	cin >> lowInt;

	// ���� ������������� �������� � ��������� ���������
	cout << "\n\n\t\t������� ������������ �������� ��������: ";
	cin >> highInt;

	// ���� ����������� �������� ������ �������������
	if (lowInt > highInt)
		throw exception("����������� �������� ��������� ������ ���� ������ �������������!");

	getKey();

	cls();

	// ������ ������ MatrixInt
	MatrixInt* p_mtxInt = new MatrixInt(rows, cols);

	// ������ �� �������
	MatrixInt& mtxInt = *p_mtxInt;

	// ����������������� ������� ���������� ����������
	// � ��������� ���������
	fillMatrix(mtxInt, lowInt, highInt);

	cputs("\n\n\t\t\t\t\t������������� �������\n\n", arrColor);

	// ����� �������
	printMatrix(mtxInt);

	// ��������� �� ������ �������� ������ �������� � �������
	matrixIntCols_t* p_data = sumIntCols(mtxInt);
	
	// ����� ���� ������������� �������� �������� ���������
	// �������� �������
	printSumCls(p_data, mtxInt.cols());

	cputs("\n\n\t\t\t\t\t������������ �������� �� ����������� �����\n\n", arrColor);
	
	// ���������� �������
	mtxInt = moveColsMatrix(mtxInt, p_data);
	
	// ����� �������
	printMatrix(mtxInt);

	// ����� ���� ������������� �������� �������� ���������
	// �������� �������
	printSumCls(p_data, mtxInt.cols());

	
	cout << "\n\n\n";

	getKey();
	
#pragma endregion 	
}

#pragma region ������ ������� 1

// ����� ������� � ���� ������� (double)
void App::printMatrix(MatrixDouble& mtx)
{
	// ����� �������
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		cout << "\t\t+";
		for (size_t i = 0; i < mtx.cols(); i++)
		{
			cout << "���������+";
		}

		cout << "\n\t\t";

		for (size_t k = 0; k < mtx.cols(); k++)
		{
			cout << "| " << setw(8) << mtx(i, k);

			// ���� ��� ��������� ������� �� ����� �������� �����
			if (k == mtx.cols() - 1)
			{
				cout << "|" << endl;
			}


		}
	}

	cout << "\t\t+";
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		cout << "���������+";
	}

}

// ����� ������� � ���� ������� (int)
void App::printMatrix(MatrixInt& mtx)
{
	// ����
	short cl = getColor();
	
	// ����� �������
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		cout << "\t\t+";
		for (size_t i = 0; i < mtx.cols(); i++)
		{
			cout << "���������+";
		}

		cout << "\n\t\t";

		for (size_t k = 0; k < mtx.cols(); k++)
		{
			// ���� ������� �������� �������� ������ 
			setColor(SaddlePoint(mtx, i, k) ? arrColor : cl);
			
			cout << "| " << setw(8) << mtx(i, k);

			// ���� ��� ��������� ������� �� ����� �������� �����
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
		cout << "���������+";
	}

}

// ���������� ������� ���������� ����� (double)
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

// ���������� ������� ���������� ����� (int)
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

// ����� ��������� �������, � ������� ���� ������������� ��������
double App::sumElem(MatrixDouble& mtx)
{
	// ����� ��������� 
	double sum = 0;
	
	// ����� �������
	double sumTmp = 0;

	// ���� ��������� �������������� �������� � ������
	bool flag = false;
	
	for (int i = 0; i < mtx.cols(); i++)
	{
		flag = false;
		
		for (int k = 0; k < mtx.rows(); k++)
		{
			sumTmp += mtx(k, i);
			
			// ���� ����� �������� �������������
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

// ����� �������� ������������� ��������� ������� �� ������
// ���������� ��������� �� ������ �������� ������ �������� � �������
matrixIntCols_t* App::sumIntCols(MatrixInt& mtx)
{
	matrixIntCols_t* p_data = new matrixIntCols_t[mtx.cols()];
	
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		// ������ �� ������� ������� � ������� �������� matrixIntCols_t
		matrixIntCols_t& data = p_data[i];

		data.indexCols = i;
		
		for (size_t k = 0; k < mtx.rows(); k++)
		{
			// ���� �������� �������� �������� � �������������
			if (k != 0 && mtx(k, i) % 2 == -1 /*&& mtx(k, i) < 0*/)
			{
				data.summerCols += -1 * mtx(k, i);
			}
		}
	}

	return p_data;
}

// ����� ���� ������������� �������� �������� ���������
// �������� �������
void App::printSumCls(matrixIntCols_t* p_data, int size)
{
	// ����� ���� ������������� �������� �������� ���������
	// �������� �������

	short int cl = getColor();
	
	setColor(headerColor);
	
	cout << "\n\t\t\t\t����� ������������� �������� ��������� �������\n";
	
	cout << "\t\t+";
	for (size_t i = 0; i < size; i++)
	{
		cout << "���������+";
	}

	cout << "\n\t\t";

	for (size_t k = 0; k < size; k++)
	{

		matrixIntCols_t& data = p_data[k];
		
		cout << "| " << setw(8) << data.summerCols;

		// ���� ��� ��������� ������� �� ����� �������� �����
		if (k == size - 1)
		{
			cout << "|" << endl;
		}


	}
	
	cout << "\t\t+";
	for (size_t i = 0; i < size; i++)
	{
		cout << "���������+";
	}

	setColor(cl);
}

// ���������� �������� � ����������� �� �� ������� �����������
// �� ����� ������������� �������� ��������� ��������
MatrixInt& App::moveColsMatrix(MatrixInt& mtx, matrixIntCols_t* p_data)
{
	// ����� ������� � ������� ����� �������� ����������� �������
	MatrixInt* p_matrixTemp = new MatrixInt(mtx.rows(), mtx.cols());

	// ������ �� ������ MatrixInt
	MatrixInt& matrixTemp = *p_matrixTemp;
	
	// ���������� ������� �������� matrixIntCols_t
	insertSort(p_data, mtx.cols());

	// ����������� ������� � ����� ������� � ������� �����������
	for (size_t i = 0; i < mtx.cols(); i++)
	{
		// ������ �� ������ matrixIntCols_t
		matrixIntCols_t& data = p_data[i];

		for (size_t k = 0; k < mtx.rows(); k++)
		{
			matrixTemp(k, i) = mtx(k, data.indexCols);
		}
	}

	// �������� ������ �� ��������������� �������
	//delete &mtx;
	
	return matrixTemp;
}

// ���������� ���������
void App::insertSort(matrixIntCols_t* p_data, int size)
{
	// ���������� ������ ������� ������� (����� ����������, �� ��� ����� ������������ � ���� �������, ����� �� �� ���� ���������)
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		// � ���������� smallestIndex �������� ������ ����������� ��������, ������� �� ����� � ���� ��������.
		// �������� � ����, ��� ���������� ������� � ���� �������� - ��� ������ ������� (������ 0)
		int smallestIndex = startIndex;

		// ����� ���� ������� �������� � ��������� ����� �������
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			// ���� �� ����� �������, ������� ������ ������ ����������� ��������,
			if (p_data[currentIndex].summerCols < p_data[smallestIndex].summerCols)
				// �� ���������� ���
				smallestIndex = currentIndex;
		}

		// smallestIndex ������ ���������� �������. 
				// ������ ������� ���� ��������� ���������� ����� � ���, ������� �� ����������
		swap(p_data[startIndex], p_data[smallestIndex]);
	}
}

// �������� �� �������������� �������� � �������� ����� �������
bool App::SaddlePoint(MatrixInt& mtx, int rows, int cols)
{
	// ������� �������
	int tmp = mtx(rows, cols);

	// �������� �� �����������
	for (int i = 0; i < mtx.cols(); i++)
	{
		if (tmp > mtx(rows, i))
			return false;
	}
	
	// �������� �� ���������
	for (size_t i = 0; i < mtx.rows(); i++)
	{
		if (tmp < mtx(i, cols))
			return false;
	}

	return true;
}

#pragma endregion