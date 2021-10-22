#pragma once

#include "pch.h"

// ����� ���� ������ (int)
class Node
{
	// �������� 
	int payload_;

	// ��������� �� ��������� ���� ������ 
	Node* next_;

public:

	// ����������� �� ��������� 
	Node() : payload_(), next_() { }

	// ����������� ���������������� 
	Node(int payload, Node* node = nullptr) : next_(node)
	{
		payload_ = payload;
	}

	// ���������� ����������� 
	Node(const Node& node) = default;

	// ����������
	~Node() = default;

	// ���������� �������� ������������
	Node& operator=(const Node& node) = default;

	// ������ payload_
	void setPayload(int value) { payload_ = value; }

	// ������ payload_
	int getPayload() const { return payload_; }

	// ������ next_
	void setNext(Node* nextNode) { next_ = nextNode; }

	// ������ next_
	Node* getNext() const { return next_; }

	// ���������� �������� ������ 
	friend ostream& operator<<(ostream& os, Node& node);
};

