#pragma once
#include "..\\pch.h"
#include "..\\Utils.h"
#include "Book.h"
#include <vector>
#include <algorithm>

/*
	�������� � ����������:
		- ����� ����������
		- ������� � �������� ���������
		- ��������� ����
*/

// ����� ���������� 
class Library
{

#pragma region ���������

public:

	// ������������ ������ ���� address_
	static const int N_MAX_ADDRESS = 80;

	// ����������� ������ ���� address_
	static const int N_MIN_ADDRESS = 1;

	// ������������ ������ ���� nameDirector_
	static const int N_MAX_NAME_DIRECTOR = 40;

	// ����������� ������ ���� nameDirector_
	static const int N_MIN_NAME_DIRECTOR = 1;

	// ������������ ������ ���� fileName_
	static const int N_MAX_FILE_NAME = MAX_PATH;

	// ����������� ������ ���� fileName_
	static const int N_MIN_FILE_NAME = 0;

#pragma endregion

private:

	// ���� ������������� ����(������� �������)
	set<string> baseID_;

	// ����� ����������
	string address_;
	
	// ������� � �������� ���������
	string nameDirector_;
	
	// ��������� ����
	vector<Book> books_;
	
	// ��� ����� ��� ����������
	string fileName_;

public:

#pragma region ������������, ����������, ���������� �������� ������������ 

	// ����������� �� ���������
	Library() = default;

	// ����������� ���������������� 
	Library(string address, string nameDirector, string fileName);

	// ����������� ���������������� (�������� �� �����)
	Library(string fileName);

	// ����������� ���������������� (�������� �� ������� Book)
	Library(string address, string nameDirector, vector<Book>& books, string fileName);

	// ����������� ���������� 
	Library(const Library& library) = default;

	// ���������� 
	~Library() = default;

	// ���������� �������� ������������
	Library& operator=(const Library& library) = default;

#pragma endregion 

#pragma region ������� � �������

	// ������ address_
	void setAddress(string adress);

	// ������ address_
	const string& getAddress();

	// ������ nameDirector_
	void setNameDirector(string nameDirector);

	// ������ nameDirector_
	const string& getNameDirector();

	// ������ books_
	vector<Book>& getBooks();

	// ������ fileName_
	void setFileName(string fileName);

	// ������ fileName_
	const string& getFileName();

#pragma endregion

#pragma region ������ 

	// �������� �������������� �� ������������
	bool checkId(string id);

	// ��������� ��������������
	string genId();

	// ���������� ����� � ���������� 
	void addBook(Book& book);

	// ���������� ������� ���� � ����������
	void addAllBook(vector<Book> books);

	// �������� ����� �� ����������
	void removeBook(string id);

	// �������� ���������� �� ����
	void clear();

	// ��������� ����� �� ID
	Book& getBook(string id);

	// �������� ���������� �� ����� .csv - �� ���������
	void loadLibrary();

	// �������� ���������� �� ����� .csv - ���������� ����� 
	void loadLibrary(string fileName);

	// ���������� ���������� � ���� .csv - �� ���������
	void saveLibrary();

	// ���������� ���������� � ���� .csv - ���������� ����� 
	void saveLibrary(string fileName);

	// ���������� ���� � ���������� 
	int countBooks();

	// ����� ������ ���������� � ��������� ���� � �������
	void showLibrary(string nameLibrary = "����������", string info = "������ � ������");

	// ����� ����� ������� 
	static void showHead(int countElem, string nameLibrary = "����������", string infoLibrary = "������ � ������");

	// ����� ����� ������� 
	static void showHead(string address, string director, int countElem, string nameLibrary = "����������", string infoLibrary = "������ � ������");

	// ����� ��������� ����
	static void showElem(vector<Book> books, short colorLine = LTCYAN_ON_BLACK, short colorText1 = LTYELLOW_ON_BLACK, short colorText2 = LTGREEN_ON_BLACK);

	// ����� �����
	static void showElem(Book book, short colorLine = LTCYAN_ON_BLACK, short colorText1 = LTYELLOW_ON_BLACK, short colorText2 = LTGREEN_ON_BLACK);

	// ����� ����������� 
	static void showLine(short colorLine = LTCYAN_ON_BLACK);

	// ���������� �������� ��������������
	Book& operator[](int index);

#pragma endregion

#pragma region ������������� ������� 

	// ���������� �������� ������ � ������ ������� Book
	friend ostream& operator<<(ostream & os, const vector<Book>&books);

	// ���������� �������� ������ � ������
	friend ostream& operator<<(ostream & os, const Library & library);

	// ���������� �������� ������ � ����
	friend ofstream& operator<<(ofstream & os, const Library & library);

	// ���������� �������� ����� �� ������ � ������ Book
	friend istream& operator>>(istream & is, vector<Book>&books);

	// ��������� �������� ����� �� ������
	friend istream& operator>>(istream & os, Library & library);

	// ���������� �������� ����� �� ����� 
	friend ifstream& operator>>(ifstream & os, Library & library);

#pragma endregion 

#pragma region ����� ������

	// �������� �� �������� �����
	bool checkFile(string fileName);

#pragma endregion

};

