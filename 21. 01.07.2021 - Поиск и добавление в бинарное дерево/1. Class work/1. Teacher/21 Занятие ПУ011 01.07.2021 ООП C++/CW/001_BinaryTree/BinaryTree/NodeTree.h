#pragma once
#include "pch.h"

// ���� ��������� ������ / �������������� ����� - ������� ��������� �� ���� ���
template <typename T>
class NodeTree {
	T    payload_;      // ������ ��� �������� - ������������ ���
	NodeTree* left_;    // ��������� �� ����� ���������
	NodeTree* right_;   // ��������� �� ������ ���������

public:
	NodeTree() :payload_(), left_(), right_() {  }

	explicit NodeTree(T data) :left_(), right_() {
		payload_ = data;
	} // Node

	NodeTree(const NodeTree&) = default;
	~NodeTree() = default;

	// ������� � �������
	T getPayload() { return payload_; }
	NodeTree* getLeft() const { return left_; }
	NodeTree* getRight() const { return right_; }

	void setPayload(T data) { payload_ = data; }

	void setLeft(NodeTree*  value) { left_  = value; }
	void setRight(NodeTree* value) { right_ = value; }

	// �������������� ���������
	NodeTree& operator=(const NodeTree&) = default;

	friend ostream& operator<<(ostream& os, const NodeTree<T>& node) {
		os << node.payload_;
		return os;
	} // operator<<
};