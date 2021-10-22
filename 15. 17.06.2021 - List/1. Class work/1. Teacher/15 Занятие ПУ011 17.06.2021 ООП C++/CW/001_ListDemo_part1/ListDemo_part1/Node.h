#pragma once
#include "pch.h"

// Узел списка для хранения целых чисел
class Node
{
	int payload_;   // данные в узле списка
	Node* next_;    // указатель на следующий узел списка

public:
	Node():payload_(), next_() {  }
	Node(int payload): payload_(payload), next_() {}

	Node(const Node& node) = default;
	~Node() = default;
	Node& operator=(const Node& node) = default;

	int  getPayload() const { return payload_; }
	void setPayload(int value) { payload_  = value; }

	Node* getNext() const { return next_; }
	void setNext(Node *value) { next_ = value; }
	
	friend ostream& operator<<(ostream& os, const Node& node);
};

