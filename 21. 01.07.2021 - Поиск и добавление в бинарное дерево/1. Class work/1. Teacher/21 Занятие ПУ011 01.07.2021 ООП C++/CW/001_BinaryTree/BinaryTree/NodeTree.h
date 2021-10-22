#pragma once
#include "pch.h"

// узел бинарного дерева / автореферентый класс - хранить указатель на свой тип
template <typename T>
class NodeTree {
	T    payload_;      // данные для хранения - произвольный тип
	NodeTree* left_;    // указатель на левое поддерево
	NodeTree* right_;   // указатель на правое поддерево

public:
	NodeTree() :payload_(), left_(), right_() {  }

	explicit NodeTree(T data) :left_(), right_() {
		payload_ = data;
	} // Node

	NodeTree(const NodeTree&) = default;
	~NodeTree() = default;

	// геттеры и сеттеры
	T getPayload() { return payload_; }
	NodeTree* getLeft() const { return left_; }
	NodeTree* getRight() const { return right_; }

	void setPayload(T data) { payload_ = data; }

	void setLeft(NodeTree*  value) { left_  = value; }
	void setRight(NodeTree* value) { right_ = value; }

	// перегруженнные операторы
	NodeTree& operator=(const NodeTree&) = default;

	friend ostream& operator<<(ostream& os, const NodeTree<T>& node) {
		os << node.payload_;
		return os;
	} // operator<<
};