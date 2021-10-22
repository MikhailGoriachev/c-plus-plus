#pragma once
#include "pch.h"

template <typename  T>
class DblList
{
public:
    friend class Node;

	// ���� ������
	template <typename T>
    class Node
    {
        T    payload_;  // ������ ��� �������� - ������������ ���
        Node* next_;    // ��������� �� ��������� ���� ������
        Node* prev_;    // ��������� �� ����������� ���� ������

    public:
        Node() :payload_(), next_(), prev_() {  }

        explicit Node(T data) :next_(), prev_()
        {
            payload_ = data;
        } // Node

        Node(const Node&) = default;
        ~Node() = default;

        // ������� � �������
        T getPayload() const     { return payload_; }
        void setPayload(T value) { payload_ = value; }

        Node<T>* getNext() const     { return next_; }
        void setNext(Node<T> *value) { next_ = value; }

        Node<T>* getPrev() const     { return prev_; }
        void setPrev(Node<T> *value) { prev_ = value; }
		
        // �������������� ���������
        Node& operator=(const Node&) = default;

        friend ostream& operator<<(ostream& os, const Node<T>& node)
        {
            os << node.payload_;
            return os;
        } // operator<<
    };

private:
	
    Node<T> *head_;    // ������ ������
    Node<T> *tail_;    // ����� ������
    int     counter_;  // ���������� ��������� � ������

public:
    // �������� �������������
	DblList(): head_(), tail_(), counter_() {}
    DblList(const DblList& dblList) : head_(), tail_(), counter_()
	{
		// �������� �� ������ dblList, ���������
		// ��� ��� �������� � ����� ������ ������
        Node<T>* node = dblList.head_;
        while (node != nullptr) {
            add(node->getPayload());
            node = node->getNext();
        } // while
	} // DblList

    // ����������
    ~DblList() { clear(); }

    // �������� ������������
    DblList& operator=(const DblList& dblList)
	{
		// ������ �� ����������������
        if (&dblList == this) return *this;

		// ������ ��� ������
        clear();

		// ������ �� ������� ������� ������
        if (dblList.isEmpty()) return *this;

		// �������� �� ������ dblList, ���������
        // ��� ��� �������� � ����� ������ ������
        Node<T>* node = dblList.head_;
        while (node != nullptr) {
            add(node->getPayload());
            node = node->getNext();
        } // while

        return *this;
	} // operator=

    // �������� ������
    friend ostream& operator<<(ostream &os, const DblList<T> dblList)
    {
        if (dblList.isEmpty())
            os << "���������� ������ ����";
        else {
        	// ����� ������ ��� ������ ����� ������
            Node<T>* node = dblList.head_;
            while (node != nullptr) {
                os << setw(3) << *node;
                node = node->getNext();
            } // while
        } // if

        return os;
    } // operator<<


	
    // ������, ����������� ��� ������
    void add(T value);                      // ���������� �������� � ����� ������
    void insert(int position, T value);

    T    get(int position);
    void put(int position, T value);
    T removeAt(int position);

    void clear();

	// �������� �� ������ ������
    bool isEmpty() const { return counter_ == 0; }

    int getCounter() const { return counter_;  }

};

// ���������� �������� � ����� ������
template<typename T> void DblList<T>::add(T value)
{
    Node<T>* newNode = new Node<T>(value);
	
    // ���������� � ������ ������
	if (isEmpty()) {
        head_ = newNode;
        tail_ = newNode;
        ++counter_;
        return;
	} // if

	// ���������� � ����� ��������� ������
    newNode->setPrev(tail_);  // ����� ����� : ����� ���� ������� � ������ ���������
    tail_->setNext(newNode);  // ����� ������: ������ ��������� ���� ������� � ����� �����������
    tail_ = newNode;          // ����� ��������� �� ����� ����
    ++counter_;               // ��������������� �������
} // DblList<T>::add


// ������� � �������� �������
template<typename T> void DblList<T>::insert(int position, T value)
{
	if (position < 0 || position > counter_-1)
        throw exception("������������ ������� ������� ��������");

	// ������� ����� ������� 
    Node<T>* newNode = new Node<T>(value);
	
	// ������� ����� ������ ���������
	if (position == 0) {
        newNode->setNext(head_);
        head_->setPrev(newNode);
        head_ = newNode;
        ++counter_;
        return;
	} // if
	
	// ������� ����� ��������� ���������
    if (position == counter_-1) {
        Node<T>* node = tail_->getPrev();
        node->setNext(newNode);
        newNode->setPrev(node);
        newNode->setNext(tail_);
        tail_->setPrev(newNode);
        ++counter_;
    	return;
    } // if

	// ������� ����� ���������� �� ��������� 1 .. counter_-2
	// ����� �� ������� ��������
    // ���������� �������� ������ �� position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // for

	// ���������� ������� - ��������� ������ ����� � ������ ���
	// ����� ������������ ��������
    newNode->setPrev(node->getPrev());
    newNode->setNext(node);

	// ����� ����������� �������� � �����
    Node<T>* prev = node->getPrev();
    prev->setNext(newNode);

	// ����� �������� �������� � �����
    node->setPrev(newNode);
    ++counter_;
} // DblList<T>::insert


// �������� ������ � ������� position 
template<typename T> T DblList<T>::get(int position)
{
    if (isEmpty() || position >= counter_)
        throw exception("������������ ������� ��������");

    // ���������� �������� ������ �� position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // while

	// ������� ��������� �������
    return node->getPayload();
} // DblList<T>::get

// �������� ������ � ������� position
template<typename T> void DblList<T>::put(int position, T value)
{
    if (isEmpty() || position >= counter_)
        throw exception("������������ ������� ��������");

    // ���������� �������� ������ �� position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // while

    // �������� ��������� �������
	node->setPayload(value);
} // DblList<T>::put


// �������� �������� � ������� position
template<typename T> T DblList<T>::removeAt(int position)
{
    if (isEmpty() || position >= counter_)
        throw exception("������������ ������� ��������");

	// �������� ������������� �������� ������
	if (counter_ == 1) {
        T temp = head_->getPayload();
        delete head_;
        head_ = tail_ = nullptr;
        --counter_;
        return temp;
	} // if

	// �������� �������
	if (position == 0) {
        // ��������� ��������
		T temp = head_->getPayload();

		// ������ ������ ��������� �� ��������� �������
        head_ = head_->getNext();

		// ����������� ������, ���������� ������� ������� ��������
        delete head_->getPrev();

		// ������ ���� ����������� - �.�. � ������� �������� ���
		// ���� ������ ���� ������
        head_->setPrev(nullptr);
		
        --counter_;
        return temp;
	} // if

	// �������� ����������
	if (position == counter_-1) {
		// ��������� ������������ ��������
        T temp = tail_->getPayload();

		// ���������� ����� �� ����� �������
        tail_ = tail_->getPrev();
		
		// ���������� ������, ������� ��������� ���������
        delete tail_->getNext();

		// ��������� ���� next_ ���������� ��������
        tail_->setNext(nullptr);

		// ��������������� �������
        --counter_;
        return temp;
 	} // if

	// �������� ��� position = 1..counter_-2
    // ���������� �������� ������ �� position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // while

	// node - ��������� �������, ��� ��������� �������� ���������
	// �� ���������� � ��������� ����
    Node<T>* prev = node->getPrev();
    Node<T>* next = node->getNext();

	// ����� ���������� � ����������, ����� node
    next->setPrev(prev);
    prev->setNext(next);

	// ��������� �������� ����, ������� ����, ���������������
	// ������� ���������, ������� ��������
    T temp = node->getPayload();
    delete node;
    --counter_;
	
	return temp;
} // DblList<T>::removeAt

// ������� ������
template<typename T> void DblList<T>::clear()
{
	// ��������� ������� �� ��������� 
    if (isEmpty()) return;
	
	// ���������� ��� �������� ������
    Node<T> *node = head_;
	while (node != nullptr) {
		// ������� ������� ������
        Node<T>* temp = node->getNext();
        delete node;
        node = temp;
	} // while

    counter_ = 0;
	// TODO: ������ ��� ��������������� ��������� ������ clear() ������?
    head_ = tail_ = nullptr;
} // DblList<T>::clear
