#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include <functional>
#include <numeric>

#include "DateTime.h"
#include "Bill.h"
#include "Payer.h"

// ������������ ����� � ������ ������������ ListPayer. 
// ����� ��������:
//	- ������ ������������ �� ���������� ������
//	- ���� �������� ������
//	- ����� ������

//	����������� ��� ������ ListPayer :
//		�	����� ���������� ����������� � ������
//		�	����� �������� ����������� �� ������
//		�	����� ������ ����������� �� ������ ��������, ��������� ������ �������� � ��������� ���������,
//			��������� � �������� ������ ������
//		�	����� ������ ����������� �� ������� � ���������, ��������� ������ �������� � ���������
//			���������, ��������� � �������� ������ ������
//		�	����� ������ ������������ �� ���� �������, ��������� ������ �������� � ��������� ���������,
//			��������� � �������� ������ ������
//		�	����� ���������� ������ ��������� �������� ����� ������
//	����������� �������� �������� ListPayer, �������� ����������� � ����������� �������.
//		�	�������� ����������� ������ � �������� ��������, �� ������ �������� ������ �� ��������� ����
//			�������, ��� ����������.
//		�	�������� ����������� ������ � �������� ��������, �� ������ �������� ������ �� ���������
//			��������� � � ������, � �� ������ �������, ��� ����������.
//	����������� ����� ������ �� ������ ������������ :
//		�	�� ���� �������, ���������� �� ������ ��������
//		�	�� ������ ��������, ���������� �� ������ ��������
//	����������� ���������� ������ ������������ :
//		�	�� ������ ��������
//		�	�� �������� ����� � ������
//		�	�� �������� ������� ����������


// ����� ������ ������������
class ListPayer
{
	// ��������� ������ ��� ������ 
	static int numbersGen_;

	// ������ ������������ �� ���������� ������
	vector<Payer> payers_;
	
	// ���� �������� ������
	DateTime dateCreate_;
	
	// ����� ������
	int number_;

public:

#pragma region ������������, ���������� � ���������� �������� ������������ 

	// ����������� �� ���������
	ListPayer();

	// ����������� ����������
	ListPayer(const ListPayer& listPayer) = default;

	// ���������� 
	~ListPayer() = default;

	// ���������� �������� ������������
	ListPayer& operator=(const ListPayer& listPayer) = default;

#pragma endregion 

#pragma region ������� � �������

	// ������ payers_
	void setPayers(vector<Payer>& payers);

	// ������ payers_
	vector<Payer>& getPayers();

	// ������ dateCreate_
	const DateTime& getDateCreate();

#pragma endregion

#pragma region ������

	// �������� ������ �� ������������
	// true - ����� ������, false - ����� �� ������
	bool checkNumber(string& numberPayer);

	// ���������� ����������� � ������
	void addPayer(Payer& payer);

	// ���������� ������������ � ������
	void addAllPayer(vector<Payer>& payers);

	// �������� ����������� �� ������
	void delPayer(string& numberPayer);
	
	// ����� ����������� �� ������ ��������, ��������� � �������� ������ ������
	vector<Payer> searchByNumber(string& numberPayer, string nameSaveFile);
	
	// ����� ����������� �� ������� � ���������, ��������� � �������� ������ ������
	vector<Payer> searchByName(string& namePayer, string nameSaveFile);
	
	// ����� ������������ �� ���� �������, ��������� ������ ���������� � ��������� ���������,
	// ����������� � �������� ������ ������
	vector<Payer> searchByDate(DateTime& dateTime, string nameSaveFile);
	
	// ���������� ������ ��������� �������� ����� ������
	double payAll();

	// ���������� ������� ������� ���������� ����� ������ � �������
	time_t timeAll();

	// ���������� ������ ��������� �������� ����� ������
	static double payAll(vector<Payer> payers);

	// ���������� ��������� � ������ 
	int countPayer();

	// �������� ����� ��� ������ 
	fstream openFileWrite(string& nameFile);

	// �������� ����� ��� ������ 
	fstream openFileRead(string& nameFile);

	// �������� ����� ��� ������ � ����
	fstream openFileWriteRead(string& nameFile);

	// ����� ������ � ���� �������
	void showTable(string nameList = "������ ������������", string info = "������");

	// ����� ������ � ���� �������
	void showTableTime(string nameList = "������ ������������", string info = "������");

	// ����� ����� �������
	static void showHead(ListPayer& listPayer, string nameList = "������ ������������", string info = "������");

	// ����� ����� �������
	static void showHeadTime(ListPayer& listPayer, string nameList = "������ ������������", string info = "������");

	// ����� ��������� 
	static void showElem(vector<Payer> payers);

	// ����� ��������� 
	static void showElemTime(vector<Payer> payers);

	// ����� ����������� 
	static void showLine();

	// ����� ��������� �� ���������� ������
	static void showEmpty();

	// ����� ��������� �� ���������� ������
	static void showEmptyTime();

#pragma endregion

#pragma region ������������� ������� 

#pragma endregion

};

