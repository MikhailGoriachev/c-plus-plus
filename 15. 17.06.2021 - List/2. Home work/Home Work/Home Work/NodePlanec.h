#pragma once

#include "Plane.h"

// ����� ���� ������ ListPlane (Plane)
class NodePlanec
{
	// ������ 
	Plane payload_;

	// ��������� �� ��������� ���� ������ 
	NodePlanec* next_;

public:

	// ����������� �� ���������
	NodePlanec() : next_() {}

	// ����������� ����������������
	NodePlanec(Plane payload, NodePlanec* next = nullptr) : payload_(payload), next_(next) {}

	// ���������� 
	~NodePlanec() = default;

	// ���������� �������� ������������ 
	NodePlanec& operator=(const NodePlanec& nodePlanec) = default;

	// ������ payload_
	Plane getPayload() const { return payload_; }
	
	// ������ payload_
	void setPayload(Plane& payload) { payload_ = payload; }

	// ������ payload_
	NodePlanec* getNext() const { return next_; }

	// ������ payload_
	void setNext(NodePlanec* next) { next_ = next; }

	// ���������� �������� ������
	friend ostream& operator<<(ostream& os, NodePlanec& nodePlanec);
};

