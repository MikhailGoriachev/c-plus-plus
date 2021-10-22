#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "Palette.h"

#include "BinaryTree.h"
#include "Station.h"
#include "Subscriber.h"
#include "Date.h"
#include "Form.h"
#include "Stack.h"
#include "TRectangle.h"
#include "Queue.h"
#include "List.h"
#include "DblList.h"
#include "Triangle.h"

/*
	������ 1.
	� �������������� ��������� ������ ������ ����������� ��������� ����������� � 
	��������� �������� �������. ��������� ���������� ��������� � �� �������.
	������� ��������� ������ ������� �������, ��� � �������� �����������, ����������
	������ �����, ������� �������� � �2, ���������� ������, ���� ���������� �� ���� 
	(����, �����, �������� Date). ���������� � ��������� ����������� �� �������.
	����������� ������������� ��������:
		�	����� � ��������� �� ������� � ������� ������ ���������� �������, ��������� 
			������������� ������������
		�	������ � �������� ���� ���� ��������� ��������� (� ����� ������ ����� 
			����������� �� ��������).
	������ 2.
	����������� ����� ��� ������������� �������� ���������� ������� � ������ ��� 
	��������:
		�	������� � ���������
		�	����������� ������
		�	������� ���������� (� �������) �� ��������� �����.
	����������� ����� ��� ������������� ���������� ������� � ������ ��� ��������
	�������� ���������� ������� (��� ������� � ��� �������� �������), ������� �����
	�� ������ ��������� ��������, ��������� ��������� � ���� ��������� ������ ������.
	������ ��� ����� �������� ���������� ����� ��������.
	������� ������ ���������� �������, ��������� ��������� �� ������� (�� ����� 10 
	�������), ����������� ����� �� ����������� ������, ����� ���� � ������ � �������
	����������� ���������� �������.
*/

// TODO: ���������� ����� - �������� ������ ���������� - ������-������ ����������
class App
{
	// ��������� �� �������� ������ ����������� � ��������� �������� �������
	BinaryTree<Form> forms_;

	// ���������� �������
	Station station_;

	// ���� � ����������������
	Stack<TRectangle> stackRectangle_;

	// ������� � ����������������
	Queue<TRectangle> queueRectangle_;

	// ������ ������������� 
	List<Triangle> listTriangle_;

	// ���������� ������ � ��������������
	DblList<Triangle> dblListTriangle_;


public:

	// ����������� �� ���������
	App()
	{
		// ������ ����������� � ��������� �������� �������
		Form* form = new Form[10]{
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

		// ���������� ��������� ������
		forms_.addAll(form, 10);

		// �������� ������
		delete[] form;

		// ������ ���������� ���������
		Subscriber* subscribers = new Subscriber[10]
		{
			Subscriber("������ �.�.",  		"0714567842", getRand(0, 600)),
			Subscriber("��������� �.�.",	"0717865486", getRand(0, 600)),
			Subscriber("�������� �.�.",		"0714213548", getRand(0, 600)),
			Subscriber("����� �.�.",  		"0719872145", getRand(0, 600)),
			Subscriber("������ �.�.",  		"0710974569", getRand(0, 600)),
			Subscriber("��������� �.�.",  	"0717634765", getRand(0, 600)),
			Subscriber("��������� �.�.",	"0710347896", getRand(0, 600)),
			Subscriber("������ �.�.",  		"0719374345", getRand(0, 600)),
			Subscriber("������ �.�.",  		"0713638462", getRand(0, 600)),
			Subscriber("�������� �.�.", 	"0717565384", getRand(0, 600))
		};

		// ��������� ���� 
		station_.setName("071");

		// ���������� ��������� ������ ��������
		station_.setSubscribers(subscribers, 10);

		// ��������� ������
		station_.setRate((float)getRand(0.5, 5.5));

		// �������� ������
		delete[]subscribers;

		// ������ ���������������
		TRectangle* rectanglesByStack = new TRectangle[5]
		{
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
		};

		// ���������� ����� � ����������������
		stackRectangle_.pushAll(rectanglesByStack, 5);

		// ������ ���������������
		TRectangle* rectanglesByQueue = new TRectangle[5]
		{
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
		};

		// ���������� ����� � ����������������
		queueRectangle_.enqueueAll(rectanglesByQueue, 5);

		// ������ ������������� 
		Triangle* trianglesList = new Triangle[5]
		{
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.))
		};

		listTriangle_.addAll(trianglesList, 5);

		// ������ ������������� 
		Triangle* trianglesDblList = new Triangle[5]
		{
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.))
		};


		dblListTriangle_.addAll(trianglesDblList, 5);
	}

	// ���������� 
	~App() = default;

#pragma region �������

#pragma region ������� 1. �������������

	// ������� 1. �������������
	void task1();

	// ����� ��������������� �����, �� ���������� � ������� � ���� ������� �� ���������
	void showTableTRectangle(Stack<TRectangle>& stackTRectangle);

	// ����� ��������������� �������, �� ���������� � ������� � ���� ������� �� ���������
	void showTableTRectangle(Queue<TRectangle>& queueTRectangle);

#pragma endregion

#pragma region ������� 2. �����������

	// ������� 2. �����������
	void task2();

	// ����� ���������������, �� ���������� � ������� � ���� ������� �� ���������
	void showTableTriangle(List<Triangle>& listTriangle);

	// ����� ���������������, �� ���������� � ������� � ���� ������� �� ���������
	void showTableTriangle(DblList<Triangle>& dbllistTriangle);

#pragma endregion 

#pragma region ������� 3. ��������� ����������� � ��������� �������� �������
	// ������� 3. ��������� ����������� � ��������� �������� �������
	void task3();

	// ����� � ��������� �� �������
	void searchSurname();

	// ������ � �������� ����
	void writeFormBinFile();

	// ����� ��������� ������ � ��������� Form � �����
	void printBinaryTreeFormColorBack(BinaryTree<Form>::NodeTree<Form>* node);

	// ����� ��������� ������ � ��������� Form � �����
	void printBinaryTreeFormColor(BinaryTree<Form>::NodeTree<Form>* node);

	// ����� ����� ������ ��� ������ � ����� �������� Form
	void showFormColor(BinaryTree<Form>::NodeTree<Form>* node, short cl, int& i);

	// ����� ����� ������ ��� ������ � ����� �������� Form
	void showFormColorBack(BinaryTree<Form>::NodeTree<Form>* node, short cl, int& i);


#pragma endregion 

#pragma region ������� 4. ���������� �������

	// ������� 4. ���������� �������
	void task4();

	// ����� �� ����������� ������
	void searchNumber();

	// ����� ���� � ������ � ������� ����������� ���������� �������
	void showPay();

	// ����� ������ ���������� ������� � �������� �������
	void showStation();

#pragma endregion

#pragma endregion

};

