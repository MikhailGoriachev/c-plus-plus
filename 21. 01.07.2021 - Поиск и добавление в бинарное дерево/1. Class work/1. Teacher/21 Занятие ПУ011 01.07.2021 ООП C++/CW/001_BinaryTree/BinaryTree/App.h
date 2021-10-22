#pragma once
#include "BinaryTree.h"
#include "pch.h"

// ������, ��������������� ������ � �������� �������
class App
{
	BinaryTree<int> intTree_;

public:
	App():intTree_() {  }

	// �������� ���� ��� �������� � ������
	void demoAdd();
	
	// �������� ������ ������
	void demoShowTree();
	
	// ����� � ������
	void demoFindTree();
	
	// ����� ������������� ���������
	void showMsg(const char *msg = "\n������ ����������...\n") const;

};

