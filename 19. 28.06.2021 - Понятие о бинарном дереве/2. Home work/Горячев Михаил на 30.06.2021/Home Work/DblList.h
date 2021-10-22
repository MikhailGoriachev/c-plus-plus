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
        T* getPayload()          { return &payload_; }
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

    /*  ������� ��������� �� ������� �� 28.06.2021
    �	begin()������� ��������� �� ������ ����������, ���������� 0
    �	end()������� ��������� � ����� ����������, ���������� �������,
        ��������� �� ��������� ��������� ��������
    �	*������������� ���������, ���������� ������ �� ��������, ��������
        � ��������, �� ������� ��������� ��������
    �	++ ������ ���������� ���������, ������� � ���������� �������� ����������
    �	-- ������ ���������� ���������, ������� � ����������� �������� ����������
    �	T get() ��������� ��������, ��������� � ��������, �� ������� ���������
        ��������, ������ �� ������
    �	void put(T value) ������ ������ �������� � ������� ����������, �� �������
        ��������� ��������, ������ �� ������
    */

    // �������� 25.06.2021
    template <typename T>
    class Iterator
    {
        // ��������� �� ������� ������� ������
        Node<T>* node_;

        // ��������� �� ������
        const DblList<T>& list_;

        // ������ �������� � ������
        int position_;

    public:

        // ����������� �� ���������
        Iterator() = default;

        // ���������� ���������������� �� ���� ������
        Iterator(const DblList<T>& dblList) : list_(dblList)
        {
            // ��������� ��������� �� ������ ������� ������
            node_ = dblList.head_;

            // ��������� ������� �� ������� �������
            position_ = 0;

            // ��������� ��������� �� ������
            // list_ = dblList;
        }

        // ���������� ����������� 
        Iterator(const Iterator& iterator) = default;

        // ���������� 
        ~Iterator() = default;

        // ���������� �������� ������������
        Iterator& operator=(const Iterator& iterator) = default;

    public:


        // ������� ��������� �� ������ ����������, ���������� 0
        int begin()
        {
            // ��������� �� ������� �������
            node_ = list_.head_;

            position_ = 0;

            return position_;
        }


        // ������� ��������� � ����� ����������, ���������� �������,
        // ��������� �� ��������� ��������� ��������
        int end() { return list_.counter_; }


        // * ������������� ���������, ���������� ������ �� ��������, ��������
        // � ��������, �� ������� ��������� ��������
        T& operator*() 
        {
            // ���� ������� ������ ������� ��� ������ ��������� ����������  
            if (position_ < 0 && position_ >= list_.counter_)
                throw exception("List: ����� �� ������� ������!");

            return *node_->getPayload(); 
        }
        

        // ++ ������ ���������� ���������, ������� � ���������� �������� ����������
        Iterator& operator++()
        {
            // ���� ������� ��������� �� ������� ������
            if (position_ >= list_.counter_)
                throw exception("List: ����� �� ������� ������!");

            // ���������� �������
            position_++;

            // ������� �� ��������� ������� ������
            node_ = node_->getNext();

            return *this;
        }


        // -- ������ ���������� ���������, ������� � ����������� �������� ����������
        Iterator& operator--()
        {
            // ���� ������� ������ �������
            if (position_ < 0)
                throw exception("List: ����� �� ������� ������!");

            // ���������� �������
            position_--;

            // ������� �� ���������� �������
            node_ = node_->getPrev();

            return *this;
        }


        // ��������� ��������, ��������� � ��������, �� ������� ���������
        // ��������, ������ �� ������
        T get() 
        {
            return *node_->getPayload();
        }


        // ������ ������ �������� � ������� ����������, �� �������
        // ��������� ��������, ������ �� ������
        void put(T value)
        {
            node_->setPayload(value);
        }


        // ���������� �������� ==
        bool operator==(int position) { return position_ == position; }


        // ���������� �������� !=
        bool operator!=(int position) { return position_ != position; }
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
            add(*node->getPayload());
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
    void addAll(T* values, int n)
    {
        for (int i = 0; i < n; i++)
        {
            add(values[i]);
        }
    }

    void insert(int position, T value);
    void insertAll(int position, const T* values, int n)
    {
        for (int i = 0; i < n; i++)
        {
            insert(position, values[i]);
        }
    }

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
