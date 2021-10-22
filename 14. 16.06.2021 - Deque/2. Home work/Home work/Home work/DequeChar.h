#pragma once
#include "pch.h"
#include "Colors.h"
#include "Utils.h"

// ��� - ������������ ������� (char)
class DequeChar
{
public:

	// ������ ���� �� ���������
	static const int SIZE_DEFAULT = 15;

private:

	// ������ �������-����������
	int size_;

	// ��������� �� ������-��������� (char)
	char* data_;

	// ����� ���� 
	int back_;

public:

#pragma region ������������ � ���������� 

	// ����������� �� ���������
	DequeChar() : size_(SIZE_DEFAULT), data_(new char[size_]), back_() {};

	// ����������� ����������������
	DequeChar(int size);

	// ���������� �� ������ ������� 
	DequeChar(char* arrChar, int size);

	// ���������� �����������
	DequeChar(const DequeChar& dequeChar);

	// ����������
	~DequeChar();

#pragma endregion

#pragma region ������

	// �������� � ������ ����
	void shift(char value);

	// ���������� ������� � ������ ���� 
	void shiftAll(char* arrChar, int size);

	// ���������� ��������� ������� ����
	char front() const;

	// ����� ������� � ������ ����
	char unshift();

	// �������� � ����� ����
	void push(char value);

	// ���������� ������� � ����� ����
	void pushAll(char* arrChar, int size);

	// ���������� ��������� ������� ����
	char back() const;

	// ����� ������� � ����� ����
	char pop();

	// �������� ����
	void clear();

	// ����������� ����
	bool isEmpty() const;

	// ������������ ����
	bool isFull() const;

	// ���������� ��������� � ����
	int counter() const;

	// ������ ����
	int size() const;

	// ���������� �������� ������������
	DequeChar& operator=(const DequeChar& dequeChar);

#pragma endregion

#pragma region ������������� ������� 

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, const DequeChar& dequeChar);

	// ����� �����, n - ���������� ���������
	friend ostream& showLine(ostream& os, int n);

#pragma endregion
};