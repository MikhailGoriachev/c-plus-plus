// #pragma once

// #include "Form.h"
// #include "Subscriber.h"
// // ����/���� ������
// template <typename T>
// class NodeTree
// {
// 	// ������ 
// 	T data_;
// 
// 	// ��������� �� ����� �����
// 	NodeTree* left_;
// 
// 	// ��������� �� ������ �����
// 	NodeTree* right_;
// 
// public:
// 
// 	// ����������� �� ���������
// 	NodeTree() = default;
// 
// 	// ����������� ���������������
// 	NodeTree(T data) : data_(data) {}
// 
// 	// ����������� ����������
// 	NodeTree(const NodeTree& node) = default;
// 
// 	// ���������� 
// 	~NodeTree() = default;
// 
// 	// ���������� �������� ������������
// 	NodeTree<T>& operator=(const NodeTree& node) = default;
// 
// 	// ������ data_ 
// 	void setData(T data) { data_ = data; }
// 
// 	// ������ data_ 
// 	T getData() { return data_; }
// 
// 	// ������ left_
// 	void setLeft(NodeTree* left) { left_ = left; }
// 
// 	// ������ left_ 
// 	NodeTree* getLeft() { return left_; }
// 
// 	// ������ right_ 
// 	void setRight(NodeTree* right) { right_ = right; }
// 
// 	// ������ right_ 
// 	NodeTree* getRight() { return right_; }
// 
// 	// ���������� �������� ������ 
// 	friend ostream& operator<<(ostream& os, NodeTree& node)
// 	{
// 		os << node.data_;
// 	}
// };
// 

