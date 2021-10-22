#pragma once

#include "pch.h"

// Класс узла списка (int)
class Node
{
	// значение 
	int payload_;

	// указатель на следующий узел списка 
	Node* next_;

public:

	// конструктор по умолчанию 
	Node() : payload_(), next_() { }

	// конструктор инициализирующий 
	Node(int payload, Node* node = nullptr) : next_(node)
	{
		payload_ = payload;
	}

	// копирующий конструктор 
	Node(const Node& node) = default;

	// деструктор
	~Node() = default;

	// перегрузка операции присваивания
	Node& operator=(const Node& node) = default;

	// сеттер payload_
	void setPayload(int value) { payload_ = value; }

	// геттер payload_
	int getPayload() const { return payload_; }

	// сеттер next_
	void setNext(Node* nextNode) { next_ = nextNode; }

	// геттер next_
	Node* getNext() const { return next_; }

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, Node& node);
};

