#pragma once
#include "BinaryTree.h"
#include "pch.h"

// ћетоды, демонстрирующие работу с бинарным деревом
class App
{
	BinaryTree<int> intTree_;

public:
	App():intTree_() {  }

	// добавить узел или значение в дерево
	void demoAdd();
	
	// показать данные дерева
	void demoShowTree();
	
	// поиск в дереве
	void demoFindTree();
	
	// ¬ывод однострочного сообщени€
	void showMsg(const char *msg = "\n–абота приложени€...\n") const;

};

