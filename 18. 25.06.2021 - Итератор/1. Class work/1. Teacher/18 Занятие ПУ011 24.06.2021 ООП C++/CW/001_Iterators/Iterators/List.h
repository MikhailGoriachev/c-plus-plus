#pragma once
#include "pch.h"
#include "Node.h"

// ����������� ������ � ���������� ������� - ����������
template <typename T> 
class List
{
    Node<T> *head_;   // ��������� �� ������ (1� �������) ������
    int  counter_;    // ������� ��������� ������

public:
    List():head_(), counter_() {  }
    List(T *data, int n): head_(), counter_()
    {
        addAll(data, n);
    } // List

    List(const List& list) : head_(), counter_() {		
		Node<T>* node = list.head_;  // ����� ������� �������� �� ������ list
		while (node != nullptr) {    // ���� �� �������� ����� ������
			add(*node->getPayload());
			node = node->getNext();
		} // while
	}

    ~List() { clear(); }

    int getCount() const { return counter_; }

    // ���������� �������� � ����� ������
    void add(T payload);

    // ���������� ������� ��������� � ����� ������
    void addAll(T *payloads, int n);

    // ������� �������� ����� ��������� ��������
    void insert(int position, T payload);

    // ������� ������� ��������� ����� ��������� ��������
    void insertAll(int position, T *payloads, int n);

    // ��������� �������� �������� ������ � ������� position
    T get(int position) const;

    // �������� �������� value � ������� position
    void put(int position, T value);

    // ������������� �������� ��������������
    Node<T> &operator[](int index);

    // �������� �������� � �������� �������
    void removeAt(int position);

    void clear();

    List &operator=(const List& listGoods) {
        clear();

		Node<T>* node = listGoods.head_;  // ����� ������� �������� �� ������ listGoods
		while (node != nullptr) {  // ���� �� �������� ����� ������
			add(node->getPayload());
			node = node->getNext();
		} // while

		return *this;
	} // operator=

    // ��������������� ������
    // �������� ��������� �� ������ ������ - ��� ���������
    // ������� ������� �����
    Node<T> *getHead() const { return head_; } // getHead

    // �������� ������ �� �������
    bool isEmpty() const { return counter_ == 0; }

    // ���������� �������� ������
    friend ostream &operator<<(ostream &os, const List<T> &list)
    {
        if (list.counter_ == 0)
            os << "������ ����";
        else {
            Node<T> *node = list.head_;  // ����� ������� ��������
            while(node != nullptr) {  // ���� �� �������� ����� ������
                os << *node->getPayload() << " --> ";  // ������ ��������� �������
                node = node->getNext();               // ����� ���������� �������� ������ 
            } // while
            os << "X";
        } // if

        return os;
    } // operator<<

	// ------------------------------------------------------------------------
	// ������ ��������    
	template <typename T>
	class Iterator
    {
        Node<T> *node_;       // ��������� �� ������� ����
        int     position_;    // ������� ����, ������ ����
        const List<T>& list_; // ����������� ������ �� ������ �� �������� ������� ��������
    
    public:
    	// ������������ � ����������
        Iterator() = default;
        Iterator(const List<T>& list):
    	     node_(list.head_),
    	     position_(),
    	     list_(list)
        { }
        Iterator(const Iterator<T>& iterator) = default;
        ~Iterator() = default;
    	
    	// ���������� �������� =
    	Iterator &operator=(const Iterator<T>& iterator) = default;
    	
    	// ������ � ������������� �������� ��� ������ ���������

    	// ������� � ������ ������
    	int begin()
    	{
            node_ = list_.head_;
            position_ = 0;
    		
            return position_;
    	} // begin

    	// ������� ������� �� ��������� ��������� �������� ������
        int end() const { return list_.counter_; }

    	// �������� ���������
        bool operator!=(int position) const { return position_ != position; }
        bool operator==(int position) const { return position_ == position; }

    	// ������� � ���������� ���� ������
    	Iterator &operator++()
    	{
            if (position_ >= list_.counter_)
                throw exception("List. ����� �� ������� ������");

    		// ���������� ������� �� ��������� ����
            ++position_;
            node_ = node_->getNext();

    		// ������� ������ �� ����
            return *this;
    	} // operator++

    	// ���������� �������������, �������������� �������� ���������� ������ �� ���� ������
    	T &operator*()
    	{
            if (position_ >= list_.counter_)
                throw exception("List. ����� �� ������� ������");
    		
            return *node_->getPayload();
    	} // operator*
    };
}; // class List


#pragma region ���������� ��������
// ���������� �������� � ����� ������
template <typename T>
void List<T>::add(T payload)
{
    // ������� ����� ���� ��� ���������� � ������
    Node<T> *newNode = new Node<T>(payload);

    // ������ ������ - ���������� ������� �������� � ������
    if (counter_ == 0) {
        head_ = newNode;
        ++counter_;
        return;
    } // if

    // ������������ ��������� ������, ����� �� �����, �����
    // node ��������� �� ��������� ������� ������
    Node<T> *node = head_;
    while(node->getNext() != nullptr)
        node = node->getNext();

    // ���������� � ������
    node->setNext(newNode);
    ++counter_;
} // List::add

// ������� ������� ��������� � ����� ������ - ����������� ����������
template <typename T>
void List<T>::addAll(T *payloads, int n)
{
    // ������� � ����� ������� - node ����� ��������� �� ���������
    // ������� ������
   Node<T>*node = head_;

    // ������� � ����� ������ - ������ ���� ������ �� ������
    if (counter_ > 0)
        while(node->getNext() != nullptr)
            node = node->getNext();

    // ������� ������� � ����� ������
    for(int i = 0; i < n; ++i) {
       // ������� ����� ���� ������
       Node<T>*newNode = new Node<T>(payloads[i]);

        // ������ �������� - ���������� ������� � ������ ������
        // ���������� ��������� ������ ������
        if (counter_ == 0) {
            node = head_ = newNode;
        } // if

        // ��������� ���������� ������� � �����
        node->setNext(newNode);

        // ���������� � ���������� ����� - ����������� �������
        // ���������� ����� ��������� ��������� ������
        node = newNode;
        ++counter_;  // ��������� ����� ������ �� 1
    } // for i
} // List::addAll

// ������� �������� ����� ��������� ��������
template <typename T>
void List<T>::insert(int position, T payload)
{
    if (counter_ == 0)
        throw exception("List: ������ ����, �������� insert ��������� ����������");

    if (position < 0 || position >= counter_) 
        throw exception("List: ������������ ������� ������� ��������");

    // ����� �������
   Node<T>*newNode = new Node<T>(payload);

    // ������� ����� 0-� ���������
    if (position == 0) {
        newNode->setNext(head_); // ����� ������� ��������� �� ��������� ����� ������
        head_ = newNode;         // ���������� head_ ��������� �� ����� ������ ������� ������
        ++counter_;
        return;
    } // if

    // ����� ����� �  prev �������� ����� �������� ����� ��������
    // ���� ��������� ����� �������
   Node<T>*prev = head_;
    for (int i = 0; i < position-1; i++)
        prev = prev->getNext();

    // ���������� �������
    newNode->setNext(prev->getNext());  // ����������� ������� ��������� �� ���������
    prev->setNext(newNode);             // ��������� ���������� ������� �� �����������
    ++counter_;
} // insert

// ������� ������� ��������� ����� ��������� �������� - ����������� ����������
template <typename T>
void List<T>::insertAll(int position, T *payloads, int n)
{
    if (counter_ == 0)
        throw exception("List: ������ ����, �������� insert ��������� ����������");

    if (position < 0 || position >= counter_) 
        throw exception("List: ������������ ������� ������� ��������");

    // prev - ������� ����� ����������� ��������
    // next - ������� ����� ������������ �������
   Node<T>*prev = head_, *next;

    // ---> { prev } ---> { next } --->
    //                |
    //                +--> ��� ����� ��������� �������� �������

    // ������� ����� 0-� ���������
    if (position == 0)
        // ��� � ���� ���������� ����� ������ 
        next = head_;
    else {
        // ���� �� ������ �� ����� �������, ���������� prev, next
        for (int i = 0; i < position-1; ++i)
            prev = prev->getNext();

        // ��� � ���� ���������� ����� ������ 
        next = prev->getNext();
    } // if

    // ���������� ������� ������� ����� prev � next
   Node<T>*node = prev; // ������� ��� ���������, ����� ������������ prev
                        // �������� ���� ���������
    for (int i = 0; i < n; ++i) {
       Node<T>*newNode = new Node<T>(payloads[i]);

        if (position == 0 && i == 0)
            head_ = newNode;
        else
            node->setNext(newNode);

        // ���������� � ���������� �����
        node = newNode;
        ++counter_;
    } // for i

    // ������� ��������� ����������� ������� � ���������� ������ ������
    node->setNext(next);
} // List::insertAll

// ��������� �������� �������� ������ � ������� position
template <typename T>
T List<T>::get(int position) const
{
    if (counter_ == 0)
        throw exception("List: ������ ����");

    if (position < 0 || position >= counter_)
        throw exception("List: ������������ �������� ������� ��������");

    // ������� � ������ ������� ������
    Node<T>*node = head_;
    for (int i = 0; i < position; ++i)
        node = node->getNext();

    // ������� �������� �������� � ������� position
    return node->getPayload();
} // List::get

// �������� �������� value � ������� position
template <typename T>
void List<T>::put(int position, T value)
{
    if (counter_ == 0)
        throw exception("List: ������ ����");

    if (position < 0 || position >= counter_)
        throw exception("List: ������������ �������� ������� ��������");

    // ������� � ������ ������� ������
   Node<T>*node = head_;
    for (int i = 0; i < position; ++i)
        node = node->getNext();

    // �������� �������� value � ������� position
    node->setPayload(value);
} // List::put

// ������������� �������� ��������������
template <typename T>
Node<T> &List<T>::operator[](int index)
{
    if (counter_ == 0)
        throw exception("List: ������ ����");

    if (index < 0 || index >= counter_)
        throw exception("List: ������������ �������� ������� ��������");

    // ������� � ������ ������� ������
   Node<T>*node = head_;
    for (int i = 0; i < index; ++i)
        node = node->getNext();

    return *node;
} // List::operator []

// �������� �������� � �������� �������
template <typename T>
void List<T>::removeAt(int position)
{
    if (counter_ == 0)
        throw exception("List: ������ ����");

    if (position < 0 || position >= counter_)
        throw exception("List: ������������ �������� ������� ��������");

    // ������ ������ - �������� �������� � ������ ������
    if (position == 0) {
       Node<T>*temp = head_->getNext();  // �������� ����� ����� ������ ������
        delete head_;                   // ���������� ������, ������� ������ ������� ������
        head_ = temp;                   // ���������� ����� ����� ������ ������
        counter_--;                     // ��������� ����� ������
        return;
    } // if

    // ������� � ������ ������� ������
    Node<T>*node = head_, *prev = head_;
    for (int i = 0; i < position; ++i) {
        prev = node;            // ���������� ����
        node = node->getNext(); // ������� ����
    } // for i

    // node ��������� �� ��������� ������
    // ���������� ������� ������ ��������� �� ������� �� ���������
    // !!! ��������� ������� ������ �������������� ������������� - �.�.
    // ��� ���������� �������� getNext() ������ nullptr � ��� ��������
    // ���������� � ���������� �������
    prev->setNext(node->getNext());
    
    // ���������� ������, ������� ��������� ���������
    delete node;
    counter_--;
} // List::removeAt

// ������� ������

template <typename T>
void List<T>::clear()
{
    // ���� ������ ������, �� ��������� ������� ��������
    if (counter_ == 0) return;

    // �������� �� ������ � ����������� ������, ���������� ������� �������� ������
    Node<T>*node = head_;       // ����� ������� ��������
    while(node != nullptr) {  // ���� �� �������� ����� ������
       Node<T>*save = node->getNext(); // ��������� ����� ���������
        delete node;                  // ���������� ������, ���������� �������� ������
        node = save;                  // ����� ���������� �������� ������ 
    } // while

    // � ������ ��� ��������� - ��������������� ������� ���������
    counter_ = 0;
} // List::clear

#pragma endregion