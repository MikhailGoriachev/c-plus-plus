#pragma once
#include "pch.h"
#include "Utils.h"

#include <algorithm>
#include <numeric>
#include <iterator>

#include <vector>

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
	// ������� 1. ������
	vector<int> vec_;

	// ������� 1. �������� ��������� ����� ��� ���������� �������
	string nameFileVector = "saveVector.bin";

public:

#pragma region ������ ������� ���������� 

	// ������ ������� ����������
	static void preview();

	// ���������� ������� ���� 
	static void fillBackground(int row, int col, short color, int time);
	
	// �������� ������ ������ 
	static void outText(string message, int time, short color, int x, int y);

	// �������� ������ �������� 
	static void loadingLine(int size, int time, int x, int y, short colorLoading = GREEN_ON_BLACK, short colorBackground = mainColor, short colorComplete = BLACK_ON_GREEN);

	// ����� �����
	static void outFrame(int hight, int width, int x, int y, short colorFrame = mainColor, short colorBackground = infoColor);


#pragma endregion 

#pragma region ������� 

#pragma region ������� 1. ������

	// ������� 1. ������
	void task1();

	// 1. ���������� ������� 
	void taskOneFillVector();

	// 2. ���������� ��������� �������, ������ 0
	void taskOneCountNull();

	// ����� ��������� � ���������� ��������� �� ��������� 0
	static void showElemVectorNull(vector<int> vec);

	// 3. ����� ��������� �������, ������������� ����� ������������ ��������
	void taskOneSummElem();

	// ����� ��������� � ���������� ������� ������������ �������� 
	static void showElemVectorMin(vector<int> vec);

	// 4. ������� ��������, ������������� ����� ���� ���
	void taskOneDeleteDouble();

	// ����� ��������� � ���������� ��������� ������������� ����� ���� ��� 
	static void showElemVectorRem(vector<int> vec);

	// 5. ����������� ������ �� ����������� ������� ���������
	void taskOneSortByModule();

	// 6. �������������� ������������� �������� �������
	void taskOneDoubleNegative();

	// ����� ��������� � ���������� ������������� ���������
	static void showElemVectorNegative(vector<int> vec);

	// 7. ��������� ������ � �������� ����� ��� ������ ������ ������
	void taskOneSaveBinFile();

	// ������ ������� �� �����
	void readVectorBinFile(string nameFile, vector<int>& vec);

	// ���������� ������� � ����
	void saveVectorBinFile(string nameFile, vector<int>& vec);

	// 8. ��������� ������ �� ��������� ����� ��� ������ ������ �����
	void taskOneLoadBinFile();

#pragma region ����� ������ 

	// ����� ������� 
	static void showVector(vector<int> vec, string messageName, string messageInfo, void showElemFunc(vector<int> vec) = showElemVector);

	// ����� ����� � �����������
	static void showHeadVector(vector<int> vec, string messageName, string messageInfo);

	// ����� ��������� 
	static void showElemVector(vector<int> vec);

	// ����� �������������� �����
	static void showLineVector();

#pragma endregion

#pragma endregion 

#pragma region ������� 2. ����������

	// ������� 2. ����������
	void task2();

#pragma endregion

#pragma region ������� 3. ���������� �������

	// ������� 3. ���������� �������
	void task3();

#pragma endregion

#pragma endregion

};

