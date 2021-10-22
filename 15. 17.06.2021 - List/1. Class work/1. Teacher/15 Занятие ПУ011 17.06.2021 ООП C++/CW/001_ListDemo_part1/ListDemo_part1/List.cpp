#include "List.h"

List::List(const List& list)
{
	
} // List::List

List& List::operator=(const List& list)
{
	return *this;
} // List::operator=


// CRUD - create read update delete
// C - create: ���������� ���� � ������
// ���������� � ����� ������
void List::add(int value)
{
	// ����� ���� ������
	Node* newNode = new Node(value);
	
	// ���������� � ������ ������
	if (counter_ == 0) {
		head_ = newNode;  // ��������� ������ �� ����� ����
		counter_++;
		return;
	} // if
	
	// ���������� � �� ������ ������
	// ����� �� ���������� ���� � ������ (� ���� next_ == nuulptr)
	Node* node = head_;
	while (node->getNext() != nullptr)
		node = node->getNext();

	// ��������� ��������� ���� - �� ����� ��������� �� ����� ����
	node->setNext(newNode);
	counter_++;
} // List::add

// ������� ����� �������� ��������
void List::insert(int position, int value)
{
	
} // List::insert

// R - read: ������ �������� ���� ������
int List::get(int position)
{
	if (counter_ == 0 || position > counter_)
		throw exception("������������ �������");

	// ������� � �������� �������
	Node* node = head_;
	for (int i = 0; i < position; ++i) {
		node = node->getNext();
	}

	// ������� �������� �� ���� �������
	return node->getPayload();
} // List::get

// U - update: ������ �������� � ���� ������
void List::put(int position, int value)
{
	if (counter_ == 0 || position > counter_)
		throw exception("������������ �������");

	// ������� � �������� �������
	Node* node = head_;
	for (int i = 0; i < position; ++i) {
		node = node->getNext();
	}

	// �������� �������� � �������
	node->setPayload(value);
} // List::put

// D - delete: �������� ���� ������
void List::removeAt(int position)
{
	if (counter_ == 0 || position > counter_)
		throw exception("������������ �������");

	// ������� � �������, ����� ��������
	Node* node = head_;
	for (int i = 0; i < position-1; ++i) {
		node = node->getNext();
	}

	// ����� ���������� ��������
	Node* temp = node->getNext();

	// ����� �������� ����� ��������� � ��������� �����
	// ����������
	node->setNext(temp->getNext());

	// �������� �������� � �������� �������
	delete temp;
} // List::removeAt


// ������� ������
void List::clear()
{
	if (counter_ == 0) return;

	Node* node = head_;
	while (node != nullptr) {
		Node* next = node->getNext();
		delete node;
		node = next;
	} // while

	counter_ = 0;
	head_ = nullptr;
} // List::clear

// ����� ������
ostream& operator<<(ostream& os, const List& list)
{
	if (list.counter_ == 0)
		os << "������ ����";
	else {
		// ������� ��� ���� ������
		Node* node = list.head_;
		while (node != nullptr) {
			os << setw(3) << node->getPayload() << " --> ";
			node = node->getNext();
		} // while
		os << "X";
	} // if

	return os;
} // operator<<