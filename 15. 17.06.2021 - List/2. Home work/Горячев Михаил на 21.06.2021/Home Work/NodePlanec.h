#pragma once

#include "Plane.h"

// класс узла списка ListPlane (Plane)
class NodePlanec
{
	// данные 
	Plane payload_;

	// указатель на следующий узел списка 
	NodePlanec* next_;

public:

	// конструктор по умолчанию
	NodePlanec() : next_() {}

	// конструктор инициализирующий
	NodePlanec(Plane payload, NodePlanec* next = nullptr) : payload_(payload), next_(next) {}

	// деструктор 
	~NodePlanec() = default;

	// перегрузка операции присваивания 
	NodePlanec& operator=(const NodePlanec& nodePlanec) = default;

	// геттер payload_
	Plane getPayload() const { return payload_; }
	
	// сеттер payload_
	void setPayload(Plane& payload) { payload_ = payload; }

	// геттер payload_
	NodePlanec* getNext() const { return next_; }

	// сеттер payload_
	void setNext(NodePlanec* next) { next_ = next; }

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, NodePlanec& nodePlanec);
};

