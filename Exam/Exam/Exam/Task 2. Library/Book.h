#pragma once

#include "..\pch.h"
#include "..\Utils.h"

#include <ctime>
#include <set>

/*
	�������� � ������ �������� :
		� �������������(������� ����� ������� ��������)
		� ������� � �������� ������
		� �������� ����� ��� �������
		� ���������� ����������� ������ ����� � ����������
*/

// ����� �����
class Book
{
public:

#pragma region ��������� 

	// ������ ������ �������������� 
	static const int N_ID = 10;

	// ����������� ������ ���� nameAuthor_
	static const int N_MIN_NAME_AUTHOR = 1;

	// ������������ ������ ���� nameAuthor_
	static const int N_MAX_NAME_AUTHOR = 20;

	// ����������� ������ ���� nameBook_ 
	static const int N_MIN_NAME_BOOK = 1;

	// ������������ ������ ���� nameBook_
	static const int N_MAX_NAME_BOOK = 30;

	// ����������� �������� ���� year_
	static const int V_MIN_YEAR = 1;

	// ����������� �������� ���� countBook_
	static const int V_MIN_COUNT_BOOK = 0;

	// ������������ �������� ���� countBook_
	static const int V_MAX_COUNT_BOOK = INT_MAX;
	
#pragma endregion 

private:

	// �������������(������� ����� ������� ��������)
	string id_;

	// ������� � �������� ������
	string nameAuthor_;
	
	// �������� ����� 
	string nameBook_;

	// ��� �������
	int year_;
	
	// ���������� ����������� ������ ����� � ����������
	int countBook_;

public:

#pragma region ������������, ���������� � ���������� �������� ������������

	// ����������� �� �������
	Book() = default;

	// ����������� ���������������� ������������ ID
	Book(string nameAuthor, string nameBook, int year, int countBook);

	// ����������� ���������������� ����������� ID
	Book(string id, string nameAuthor, string nameBook, int year, int countBook);

	// ����������� ����������
	Book(const Book& book) = default;

	// ����������� 
	~Book();

	// ���������� �������� ������������
	Book& operator=(const Book& book) = default;

#pragma endregion 

#pragma region ������� � �������

	// ������ id_
	void setId(string id);

	// ������ id_
	string getId();

	// ������ nameAuthor_ 
	void setNameAuthor(string nameAuthor);

	// ������ nameAuthor_
	string getNameAuthor();

	// ������ nameBook_
	void setNameBook(string nameBook);

	// ������ nameBook_
	string getNameBook();

	// ������ year_
	void setYear(int year);

	// ������ year_
	int getYear();

	// ������ countBook_
	void setCountBook(int countBook);

	// ������ countBook_
	int getCountBook();

#pragma endregion 

#pragma region ������ 

	// ��������� ��������������
	static string genId();

#pragma endregion

#pragma region ������������� ������� 
	
	// ���������� �������� ������ � ������� 
	friend ostream& operator<<(ostream& os, const Book& book);

	// ���������� �������� ������ � ��������� ���� 
	friend ofstream& operator<<(ofstream& ofs, const Book& book);
	friend fstream& operator<<(fstream& fs, const Book& book);

	// ���������� �������� ����� �� istream
	friend istream& operator>>(istream & is, Book & book);

	// ���������� �������� ����� �� ���������� �����
	friend ifstream& operator>>(ifstream& ifs, Book& book);
	friend fstream& operator>>(fstream& fs, Book& book);

#pragma endregion

};

