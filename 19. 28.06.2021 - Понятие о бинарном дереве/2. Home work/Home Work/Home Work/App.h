#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"
#include "Palette.h"

#include "DblList.h"
#include "Person.h"

#include "Form.h"
#include "Queue.h"
/*
	������ 1.
		���������� ����� Person, �������������� ������ � ������ ���������� ������,
		���� ������ �������, ���, �������� (��� ��� ���� ���� char *), �����
		����������� (��� double), ��� � ����������� (��� double), ����� ����������
		(��� char *).
		�������� ������ ��������� ������ ����������� ������ DblList<Person>, ��
		����� 12 �����. ����������� ��������� (��� ������ ���������):
		�	�������� ��� ������� ������ �� ��������� ��������� �������� (��� �������
			������ �������� ����, �� �� ����� 0.5% �� ���� ������)
		�	����������� � ��������� ������ DblList<Person>������� ��������� ������,
			�������� ������ ������� � ����������

	������ 2.
		� �������������� ���������� ������ ������� � ���������� ����������� �������
		����������� � ��������� �������� �������. ���������� ������� �� ��������, ��
		����� 10 ��������� � �������.
		������� ������� ������ ������� �������, ��� � �������� �����������,
		���������� ������ �����, ������� �������� � �2, ���������� ������, ����
		���������� �� ���� (����, �����, �������� Date). ������� ����� ��������,
		������ ��� ��������� ����� ��� ������.

		����������� ������������� �������� (��� ������ ����������):

		�	����������� � ���������� ������ (��������� ����� DblList<>�� ����������
			�������) ��� ������ ������������������ � ��������� �������� ������� �
			�������� ����������� ������. ���������� ������ ������� � ����������
		�	����������� � ������ ������� ����������� � ��������� �������� �������
			������ �������� ������� � �������� ���������� ������� ��������. ��������
			�������� ������� � ����������
*/


// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
	// ������� 1. ���������� ������ ������� ������
	DblList<Person> listPerson_;

	// ������� 2. ������� ����������� � ��������� �������� �������
	Queue<Form> forms_;

public:

	// ������������ �� ��������� 
	App()
	{
		// ������������� ������ � �������� 
		Person persons[12]
		{
			Person("������", "���������", "����������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "������"),
			Person("���������", "��������", "���������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "�����"),
			Person("��������", "�������", "���������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "��������"),
			Person("�����", "�������", "��������������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "������"),
			Person("������", "���������", "����������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "�����"),
			Person("���������", "�������", "���������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "���������"),
			Person("���������", "���", "��������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "��������"),
			Person("������", "�������", "��������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "���������"),
			Person("������", "�����", "����������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "������"),
			Person("�������� ", "����", "������������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "��������"),
			Person("�����������", "��������", "����������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "������"),
			Person("��������", "���������", "��������", getRand(140., Person::HEIGHT_MAX - 100), getRand(40., Person::WEIGHT_MAX - 170), "���������")
		};

		listPerson_.addAll(persons, 12);

		// ������������� ������� ����������� � ��������� �������� �������
		Form tmpForm[10]{
			Form("������", "���������", "����������", 3, getRand(68., 82.), 3, Date(15, 12, 2003)),
			Form("���������", "��������", "���������", 1, getRand(36., 42.), 2, Date(6, 4, 2010)),
			Form("��������", "�������", "���������", 2, getRand(54., 62.), 3, Date(30, 5, 2012)),
			Form("�����", "�������", "��������������", 3, getRand(68., 82.), 5, Date(28, 2, 2021)),
			Form("������", "���������", "����������", 2, getRand(54., 62.), 4, Date(29, 2, 2016)),
			Form("���������", "�������", "���������", 1, getRand(36., 42.), 1, Date(3, 1, 1999)),
			Form("���������", "���", "��������", 1, getRand(36., 42.), 3, Date(25, 6, 2001)),
			Form("������", "�������", "��������", 2, getRand(54., 62.), 4, Date(23, 7, 2006)),
			Form("������", "�����", "����������", 1, getRand(36., 42.), 3, Date(18, 3, 2004)),
			Form("�������� ", "����", "������������", 2, getRand(54., 62.), 2, Date(17, 5, 2002))
		};

		forms_.enqueueAll(tmpForm, 10);
	}

	// ����������� ����������
	App(const App& app) : App() {}

	// ���������� 
	~App() = default;
	
	// ���������� �������� ������������
	App& operator=(const App& app) = default;

#pragma region ������ 1. ������ � ������ ������

	// ������ 1. ������ � ������ ������
	void task1();

private:

	// �������� ��� ������� ������ �� ��������� ��������� ��������
	void taskOneAddWeight();

	// ����������� � ��������� ������ ������� ��������� ������
	void taskOneCopyCity();

	// ����� �������
	void printDblQueue(DblList<Person>::Iterator<Person> iterator);

	// �������� ��������������� ������ �� ������
	bool selectionTaskOne(char* city, DblList<Person>::Iterator<Person> iterat, DblList<Person>& result);

public:

#pragma endregion

#pragma region ������ 2. ������� ����������� � ��������� �������� �������

	// ������ 2. ������� ����������� � ��������� �������� �������
	void task2();

private:

	// ����������� � ��������� ������ ���� ����������� � �������� ����������� ������
	void copyByRoom();

	// ����������� � ��������� ������ �� ��������� ��������� �������
	void copyByArea();

	// ����� �������
	void printQueue(Queue<Form>::Iterator<Form> iterator);

	// ����������� � �������������� ������� �� ���������� ������
	// ���������� false ���� ��� ����������
	bool copyResultByRoom(Queue<Form>::Iterator<Form> iter, Queue<Form>& result, int min, int max);

	// ����������� � �������������� ������� �� �������
	// ���������� false ���� ��� ����������
	bool copyResultByArea(Queue<Form>::Iterator<Form> iter, Queue<Form>& result, double min, double max);


public:
#pragma endregion
};

