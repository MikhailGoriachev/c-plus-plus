#pragma once
#include "pch.h"
#include "NodeTree.h"

// �������� ������ ������
template <typename T>
class BinaryTree
{
	NodeTree<T>* root_; // ������ ������

	// ����� ������ ��� ������ ��� �����
	ostream& show(ostream& os, NodeTree<T>* node);

public:
	BinaryTree():root_() {  }
	
	// �������� � �������� ������� 
    // ���������� ����
    void add(T data);
	
    // ����� � ������
	NodeTree<T>* find(T key);
	
    // �������� ���� ������

	// ���������� �������� ������
	friend ostream &operator<<(ostream& os, BinaryTree<T> &binaryTree)
	{
        if (binaryTree.root_ == nullptr) {
            os << "��� ������ � ������";
            return  os;
        }
		else
			return binaryTree.show(os, binaryTree.root_);
	} // operator<<
};


// ���������� ���� � �������� ������ �� �������
// Li <= Root and Root > Ri  
template <typename T> void BinaryTree<T>::add(T data)
{
	// ������� ���� ��� ���������� � ������
	NodeTree<T> *newNode = new NodeTree<T>(data);

	// ���������� � ������ ������
	if (root_ == nullptr) {
		root_ = newNode;
		return;
	} // if

	// ���������� � �������� ������
	// ����� ����� ��� ����������
	NodeTree<T> *node = root_;
	while(true) {
		if (data <= node->getPayload()) {
			// ����� � ����� ���������:

			// ���� � ���������� ���� ��� ������ ������� - ����� �������
			// �������.
			// ��������� ����� ���� � ������� �� �����
			if (node->getLeft() == nullptr) {
				node->setLeft(newNode);
				break;
			} // if
			
			// ����� - ������� ������ �� ������ ���������
			node = node->getLeft();
		} else {
			// ����� � ������ ��������� - ���� �������� ������ ������ �������� � ����

			// ���� � ���������� ���� ��� ������� ������� - ����� �������
			// �������.
			// ��������� ����� ���� � ������� �� �����
			if (node->getRight() == nullptr) {
				node->setRight(newNode);
				break;
			} // if

			// ����� - ������� ������ �� ������� ���������
			node = node->getRight();	
		} // if
	} // while
} // BinaryTree<T>::add


// ����� ���� � ������ - ���������� ��������� �� ����, ���������������
// ����� ������ ��� nullptr, ���� ���� �� ������
template <typename T> NodeTree<T>* BinaryTree<T>::find(T key)
{
	// ������ ������
	if (root_ == nullptr) return nullptr;

    // ������ �� ������ - ����� �� �������� ��������� ������ 
    // ���� ���� < ���� ����� ���� �����
    // ���� ���� == ���� ����� ����� � ����� �� �����
    // ���� ���� > ���� ����� ���� ������
    // ����� ������ - ���� �������� nullptr
	NodeTree<T>* node = root_;
	while(node != nullptr) {
		T temp = node->getPayload();
		if (temp == key) break;

		node = key < temp ? node->getLeft() : node->getRight();
	} // while
	
    return node;
} // BiTree<T>::find


// ������ ����� ������ ��� ������ � ����� ������
// ����� ���������
// ������
// ������ ���������
template <typename T>
ostream& BinaryTree<T>::show(ostream& os, NodeTree<T>* node)
{
	// ����� �� �������� ��� ���������� ������� ����
	if (node == nullptr) return os;

	show(os, node->getLeft());       // ��������� ������ ���������
	os << setw(5) << node->getPayload();    // ��������� �����
	show(os, node->getRight());      // ��������� ������� ���������
	
    return os;  // ����� �� �������� ��� ���������� ������� ����
} // BinaryTree::show