#pragma once
#include "pch.h"
#include "List.h"
#include "Node.h"

// ��������� ����� ���� �� ���� ���������� ������ - ������������ ������
template <typename T>
class Stack{

private:
    // ��������� ������
    List<T> data_;

public:
    // �������� �������������
    Stack() = default;
    Stack(T *data, int n){
        pushAll(data, n);
    } // Stack

    Stack(const Stack &stack)=default;

    // �������� ����� �� �������
    bool isEmpty() const { return data_.isEmpty(); }

    // �������� ������ � ����
    void push(T payload){
        if (data_.isEmpty())
            data_.add(payload);
        else
            data_.insert(0, payload);    
    } // push

    // �������� ������ � ����
    void pushAll(T *payloads, int n){

        for (int i = 0; i < n; i++)
            push(payloads[i]);
    } // pushAll
    
    // ������ ������ �� ����� - ������� ������� � �������
    T pop(){
        if (data_.isEmpty())
            throw exception("Stack: ���� ����");
        
        T value = data_.get(0);
        data_.removeAt(0);
        return value;
    } // pop

    // ��������� ������� �� ������� �����
    T peek()
    {
        if (data_.isEmpty())
            throw exception("Stack: ���� ����");
        return data_.get(0);
    } // peek

    // ������� �����
    void clear() { data_.clear(); }

    // ���������� ��������� ������������
    Stack &operator=(const Stack &stack)=default;

    // ���������� ��������� ������
	template <typename TT>
    friend ostream& operator<<(ostream& os, const Stack<TT>& stack);

    // ------------------------------------------------------------------------
    // ������ �������� �� ����� - ������ � �������� ����� ������ �� ������!!!
    template <typename T>
    class Iterator
    {
        Node<T>* node_;    // ��������� �� ������� ����
        int     position_; // ������� ����, ������ ����
        const List<T>& list_; // ����������� ������ �� ������ �� �������� ������� ��������

    public:
		#pragma region ���� ���������� ������� ����
        // ������������ � ����������
        Iterator() = default;

        Iterator(const Stack<T>& stack) :
            node_(stack.data_.getHead()),
            position_(),
            list_(stack.data_)
        {}
	
        Iterator(const Iterator<T>& iterator) = default;

        ~Iterator() = default;
    	
        // ���������� �������� =
        Iterator& operator=(const Iterator<T>& iterator) = default;
		#pragma endregion 
    	
        // ������ � ������������� �������� ��� ������ ���������

        // ������� � ������ �����
        void begin()
        {
            node_ = list_.getHead();
            position_ = 0;
        } // begin

    	
        // ������� ������� �� ��������� ��������� �������� ������
        bool end() const { return  position_ == list_.getCount(); }

    	
        // ������� � ���������� ���� ������
        Iterator& operator++()
        {
        	// �������� ������������
            if (position_ >= list_.getCount())
                throw exception("Stack. ����� �� ������� �����");

            // ���������� ������� �� ��������� ����
            ++position_;
        	node_ = node_->getNext();
        	
            // ������� ������ �� ����
            return *this;
        } // operator++

    	
        // ���������� �������������, �������������� �������� ���������� �������� ���� ������
    	// ��� ������ �� ���������
        T operator*() const
        {
            if (position_ >= list_.getCount())
                throw exception("Stack. ����� �� ������� �����");

            return *node_->getPayload();
        } // operator*
    };
};


// ���������� ��������� ������� - ���������� �������� ������
template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& stack)
{
    if (stack.isEmpty())
        os << "���� ����";
    else {
        int n = stack.data_.getCount();
        Node<T>* node = stack.data_.getHead();

        for (int i = 0; i < n; ++i) {  // ���� �� �������� ����� ������
            os << setw(5) << *node->getPayload();   // ������ ��������� �������
            node = node->getNext();
        } // for
    } // if
    return os;
} // operator<<
