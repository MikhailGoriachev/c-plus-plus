#pragma once
#include "pch.h"
#include "Utils.h"

#include <functional>
#include <algorithm>
#include <numeric>
#include <iterator>

#include <vector>
#include <set>
#include <list>

#include "Task 2. Library/Library.h"
#include "Task 3. Mobile station/ListPayer.h"
#include "Task 3. Mobile station/Payer.h"
#include "Task 3. Mobile station/Bill.h"

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
	// ������� 1. ������
	vector<int> vec_;
	
	// ������� 1. �������� ��������� ����� ��� ���������� �������
	string nameFileVector_;

	// ������� 2. �������� ����� ��� ����������
	string nameFileLibrary_;

	// ������� 2. ���������� 
	Library library_;

	// ������� 3. �������� ����� ��� ���������� ����������� ������ 
	string nameFileResSearch_;

	// ������� 3. ������ ������������
	ListPayer listPayer_;

public:

#pragma region ������������, ���������� � ���������� �������� ������������

	// ����������� �� ��������� 
	App() : vec_(), nameFileVector_("Task 1. Vector/saveVector.bin"), nameFileLibrary_("Task 2. Library/saveLibrary.csv"),
		library_("��. ������, �. 84, �. ������", "����� ��������", nameFileLibrary_), 
		nameFileResSearch_("Task 3. Mobile station/saveSearch.bin")
	{
#pragma region ������� 2. ���������� 

		// ������� 2. ������������� ����������, ���� ��� ����� ��� ����������
		if (!checkFile(nameFileLibrary_))
		{
			// ������ � �������
			vector<Book> tempBookVec{
				Book("�������� �. �.",		"������� ����� �����",		1926,	getRand(20, 40)),
				Book("������� �. �.",		"����� � ���",				1996,	getRand(20, 40)),
				Book("���������� B. �.",	"�������",					1859,	getRand(20, 40)),
				Book("������ �. �.",		"�������",					1835,	getRand(20, 40)),
				Book("���� ����� ������",	"����� ������",				1959,	getRand(20, 40)),
				Book("����� ���������",		"�������. ����������",		2021,	getRand(20, 40)),
				Book("����� ������",		"� ������ ����� ���",		1932,	getRand(20, 40)),
				Book("������ �������",		"��� ���� �������",			2010,	getRand(20, 40)),
				Book("������ �. �.",		"̸����� ����",				1842,	getRand(20, 40)),
				Book("��� ��������",		"451 ������ �� ����������",	1953,	getRand(20, 40)),
				Book("������� �����",		"�������� � �����������",	1917,	getRand(20, 40)),
				Book("Ը��� �����������",	"������������ � ���������",	1866,	getRand(20, 40)),
				Book("������ ����",			"�����",					2021,	getRand(20, 40)),
				Book("������ �. �.",		"���� ��������",			2021,	getRand(20, 40)),
				Book("��-������ �����",		"��������� �� ����",		2021,	getRand(20, 40)),
				Book("��� ��������",		"����������� �������",		1950,	getRand(20, 40)),
			};

			// ������������� ����������
			library_.addAllBook(tempBookVec);

			// ���������� ���������� � ����
			library_.saveLibrary();
		}

		// ����� �������� �� �����
		else
			library_.loadLibrary();

#pragma endregion

#pragma region ������� 3. ������ ������������

		// ������������� ������ ������������ 
		auto getDate = []() { return genDateTime(12, 16, 8, 8, 2021, 2021, 0, 23, 0, 59, 0, 59); };
		
		// ������ � �������������
		vector<Payer> payers{
			// ����������� ���������������� 
			// string namePayer, string phoneNumber, double rate, double discount, DateTime datePay
			Payer("������� �. �.",		"0500162535", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("�������� �. �.",		"0503395393", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("������� �. �.",		"0501122942", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("������� �. �.",		"0502575942", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("���������� �. �.",	"0506921373", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("������� �. �.",		"0501324362", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("������ �. �.",		"0507577903", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("���������� �. �.",	"0505184613", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("������� �. �.",		"0500644371", getRand(0., 1.), getRand(0, 20), getDate()),
			Payer("��������� �. �.",	"0501394919", getRand(0., 1.), getRand(0, 20), getDate())
		};

		// ��������� ������ ����������
		auto getBills = [](Payer& payer) {

			// ������ �������� Bill
			vector<Bill> bills;

			// ������������ ���� � �����
			DateTime max = payer.getDatePay();

			// ������ ������� � ��������
			int size = getRand(1, 10);

			// ��������� ���������� � ��������� ������� ������
			DateTime start, end;

			for (int i = 0; i < size; i++)
			{
				do
				{
					end = DateTime(getRand(1, max.getDay()), max.getMonth(), max.getYear(),
						getRand(0, max.getHour()), getRand(0, max.getMinute()), getRand(0, max.getSecond()));

					start = DateTime(end.getDay(), end.getMonth(), end.getYear(),
						getRand(0, end.getHour()), getRand(0, end.getMinute()), getRand(0, end.getSecond()));
				}
				while(start >= end);

				// ���������� � ������
				bills.push_back(Bill(start, end));
			}

			return bills;
		};

		// ���������� ���������� ������������ 
		for_each(payers.begin(), payers.end(), [getBills](Payer& payer) { payer.setBills(getBills(payer)); });

		// ���������� ������ 
		listPayer_.addAllPayer(payers);

#pragma endregion 

	}

	// ����������� ����������
	App(const App& app) = default;

	// ���������� 
	~App() = default;

	// ���������� �������� ������������
	App& operator=(const App& app) = default;

#pragma endregion 

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

	// 1. ����� ������ ���������� � ��������� ���� � �������
	void showLibrary();

	// 2. ���������� �����
	void addBook();

	// 3. �������� ���� �� ��������������
	void deleteByID();
	
	// 4. ��������� ���������� ���� ��������� ������
	void editCountBooks();
	
	// 5. ����� ���� �� ���� �������
	void selectionByYear();
	
	// 6. ����� ���� �� ������
	void selectionByAuthor();
	
	// 7. ���������� ���� �� �������� ���������� ����
	void sortByCountBook();
	
	// 8. ���������� ���� �� ��������������
	void sortByBookID();
	
	// 9. ���������� ���� �� ��������
	void sortByNameBook();

#pragma endregion

#pragma region ������� 3. ���������� �������

	// ������� 3. ���������� �������
	void task3();

	// 1. ����� ������ ������������ 
	void showListPayer();

	// 2. ���������� ����������� � ������
	void addPayer();

	// 3. �������� ����������� �� ������
	void deletePayer();

	// ���������� �������� Payer � ������ 
	void readPayerFile(vector<Payer>& payers, string fileName);

	// 4. ����� ����������� �� ������ �������� � ����� �������
	void searchPayerByNumber();

	// 5. ����� ����������� �� ������� � ���������
	void searchPayerName();

	// 6. ������ ������������ �� ���� �������
	void searchPayerByDate();

	// 7. ���������� ������ ��������� �������� ����� ������
	void sumPay();

	// 8. ����������� �������
	void mergeListPayers();

	// ����� ��������� 
	void showElemPayerByList(list<Payer>& payers);

	// 9. ����������� �������
	void crossListPayers();

	// 10. ����� ������ �� ���� �������
	void selectionPayerByDate();

	// 11. ����� ������ �� ������ ��������
	void selectionPayerByNumber();

	// 12. ���������� �� ������ ��������
	void sortByNumber();

	// 13. ���������� �� �������� ����� � ������
	void sortByPay();

	// 14. ���������� �� �������� ������� ����������
	void sortByTime();

#pragma endregion

#pragma endregion

#pragma region ����� ������

	// �������� �� �������� �����
	bool checkFile(string fileName);

	// �������� ����
	static DateTime genDateTime(int minDay, int maxDay, int minMonth, int maxMonth, int minYear, int maxYear,
		int minHour, int maxHour, int minMinute, int maxMinute, int minSecond, int maxSecond);

	// �������� ���� 
	static DateTime genDate(DateTime dateTime, int minDay, int maxDay, int minMonth, int maxMonth, int minYear, int maxYear);

	// �������� ���� 
	static DateTime genTime(DateTime dateTime, int minHour, int maxHour, int minMinute, int maxMinute, int minSecond, int maxSecond);

#pragma endregion

};

