#pragma once
#include "pch.h"
#include "NodeTree.h"

// бинарное дерево поиска
template <typename T>
class BinaryTree
{
	NodeTree<T>* root_; // корень дерева

	// обход дерева для вывода его узлов
	ostream& show(ostream& os, NodeTree<T>* node);

public:
	BinaryTree():root_() {  }
	
	// Операции с бинарным деревом 
    // добавление узла
    void add(T data);
	
    // поиск в дереве
	NodeTree<T>* find(T key);
	
    // удаление узла дерева

	// перегрузка операция вывода
	friend ostream &operator<<(ostream& os, BinaryTree<T> &binaryTree)
	{
        if (binaryTree.root_ == nullptr) {
            os << "Нет данных в дереве";
            return  os;
        }
		else
			return binaryTree.show(os, binaryTree.root_);
	} // operator<<
};


// добавление узла в бинарное дерево по правилу
// Li <= Root and Root > Ri  
template <typename T> void BinaryTree<T>::add(T data)
{
	// создать узел для добавления в дерево
	NodeTree<T> *newNode = new NodeTree<T>(data);

	// добавление в пустое дерево
	if (root_ == nullptr) {
		root_ = newNode;
		return;
	} // if

	// добавление в непустое дерево
	// найти место для добавления
	NodeTree<T> *node = root_;
	while(true) {
		if (data <= node->getPayload()) {
			// поиск в левом поддереве:

			// если у очередного узла нет левого потомка - место вставки
			// найдено.
			// Вставляем новый узел и выходим из цикла
			if (node->getLeft() == nullptr) {
				node->setLeft(newNode);
				break;
			} // if
			
			// иначе - переход дальше по левому поддереву
			node = node->getLeft();
		} else {
			// поиск в правом поддереве - если значение данные больше значения в узле

			// если у очередного узла нет правого потомка - место вставки
			// найдено.
			// Вставляем новый узел и выходим из цикла
			if (node->getRight() == nullptr) {
				node->setRight(newNode);
				break;
			} // if

			// иначе - переход дальше по правому поддереву
			node = node->getRight();	
		} // if
	} // while
} // BinaryTree<T>::add


// поиск узла в дереве - возвращаем указатель на узел, соответствующий
// ключу поиска или nullptr, если ключ не найден
template <typename T> NodeTree<T>* BinaryTree<T>::find(T key)
{
	// дерево пустое
	if (root_ == nullptr) return nullptr;

    // дерево не пустое - поиск по правилам бинарного дерева 
    // Если ключ < узла тогда идем влево
    // Если ключ == узлу тогда нашли и выход из цикла
    // Если ключ > узла тогда идем вправо
    // Конец поиска - если достигли nullptr
	NodeTree<T>* node = root_;
	while(node != nullptr) {
		T temp = node->getPayload();
		if (temp == key) break;

		node = key < temp ? node->getLeft() : node->getRight();
	} // while
	
    return node;
} // BiTree<T>::find


// прямой обход дерева для вывода в поток вывода
// левое поддерево
// корень
// правое поддерево
template <typename T>
ostream& BinaryTree<T>::show(ostream& os, NodeTree<T>* node)
{
	// выход из рекурсии при достижении пустого узла
	if (node == nullptr) return os;

	show(os, node->getLeft());       // посещение левого поддерева
	os << setw(5) << node->getPayload();    // посещение корня
	show(os, node->getRight());      // посещение правого поддерева
	
    return os;  // выход из рекурсии при достижении пустого узла
} // BinaryTree::show