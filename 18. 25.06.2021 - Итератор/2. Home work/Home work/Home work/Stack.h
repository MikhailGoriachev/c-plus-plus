#pragma once
#include "pch.h"
#include "List.h"
#include "Node.h"

// ��������� ����� ���� �� ���� ���������� ������ - ������������ ������
template <typename T>
class Stack{

    // ��������� ������
    List<T> data_;

public:

    // �������� 26.06.2021
    class Iterator
    {
        // ����������� c����� ������
        const List<T>& list_;

        // �������
        int position_;

        // ��������� �� ������� ������
        Node* node_;

    public:

    #pragma region ������� ����

        // ����������� �� ���������
        Iterator() = default;

        // ����������� �� ���� �����
        Iterator(Stack<T>& stack) : list_(stack.data_), position_(), node_(list_.head_) {};

        // ���������� ����������� 
        Iterator(const Iterator& iterator) = default;

        // ���������� 
        ~Iterator() = default;

        // ���������� �������� ������������
        Iterator& operator=(const Iterator& iterator) = default;

    #pragma endregion

    #pragma region ������ ���������

        // ��������� � ������
        int begin()
        {
            // ��������� ��������� �� ������ ������� ������
            node_ = list_.head_;

            // ��������� �������
            position_ = 0;

            // ����������� �������
            return position_;
        }

        // ������� ����� ���������
        int end() { return list_.counter_; }

        // ����� ������
        T get()
        {
            // ���� ������� �����������
            if (position_ < 0 || position_ >= list_.data_.getCount())
                throw exception("Iterator: ������� �����������");

            return *node_->getPayload();
        }

        // ++����������
        Iterator& operator++()
        {
            // ���� ������� �����������
            if (position_ >= list_.getCount())
                throw exception("Iterator: ������� �����������");

            // ������� �� ��������� �������
            node_ = node_->getNext();

            return *this;
        }

        // *������������� 
        T operator*()
        {
            return get();
        }

        // ���������� �������� ���������
        bool operator==(int position) { return position_ == position; }

        // ���������� �������� �����������
        bool operator!=(int position) { return position_ != position; }

    #pragma endregion
    };

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
    friend ostream& operator<<(ostream& os, const Stack<TT>& stack)
    {
        {
            if (stack.isEmpty())
                os << "���� ����";
            else {
                int n = stack.data_.getCount();

                List::Node* node = stack.data_.getHead();

                for (int i = 0; i < n; ++i) {  // ���� �� �������� ����� ������
                    os << setw(5) << *node->getPayload();   // ������ ��������� �������
                    node = node->getNext();
                } // for
            } // if
            return os;
        } // operator<<
    }

    // -------------------------������ �������������---------------------------
    // ------------------------------------------------------------------------
    // ������ �������� �� ����� - ������ � �������� ����� ������ �� ������!!!
    // template <typename T>
    // class Iterator
    // {
    //     Node<T>* node_;    // ��������� �� ������� ����
    //     int     position_; // ������� ����, ������ ����
    //     const List<T>& list_; // ����������� ������ �� ������ �� �������� ������� ��������
    // 
    // public:
	// 	#pragma region ���� ���������� ������� ����
    //    // ������������ � ����������
    //    Iterator() = default;
    //
    //    Iterator(const Stack<T>& stack) :
    //        node_(stack.data_.getHead()),
    //        position_(),
    //        list_(stack.data_)
    //    {}
	//
    //    Iterator(const Iterator<T>& iterator) = default;
    //
    //    ~Iterator() = default;
    //	
    //    // ���������� �������� =
    //    Iterator& operator=(const Iterator<T>& iterator) = default;
	//	#pragma endregion 
    // 	
    //     // ������ � ������������� �������� ��� ������ ���������
    // 
    //     // ������� � ������ �����
    //     void begin()
    //     {
    //         node_ = list_.getHead();
    //         position_ = 0;
    //     } // begin
    // 
    // 	
    //     // ������� ������� �� ��������� ��������� �������� ������
    //     bool end() const { return  position_ == list_.getCount(); }
    // 
    // 	
    //     // ������� � ���������� ���� ������
    //     Iterator& operator++()
    //     {
    //     	// �������� ������������
    //         if (position_ >= list_.getCount())
    //             throw exception("Stack. ����� �� ������� �����");
    // 
    //         // ���������� ������� �� ��������� ����
    //         ++position_;
    //     	node_ = node_->getNext();
    //     	
    //         // ������� ������ �� ����
    //         return *this;
    //     } // operator++
    // 
    // 	
    //     // ���������� �������������, �������������� �������� ���������� �������� ���� ������
    // 	// ��� ������ �� ���������
    //     T operator*() const
    //     {
    //         if (position_ >= list_.getCount())
    //             throw exception("Stack. ����� �� ������� �����");
    // 
    //         return *node_->getPayload();
    //     } // operator*
    // };
};


// ���������� ��������� ������� - ���������� �������� ������
/*template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& stack)
{
    if (stack.isEmpty())
        os << "���� ����";
    else {
        int n = stack.data_.getCount();

        List<auto>::Node<auto>* node = stack.data_.getHead();

        for (int i = 0; i < n; ++i) {  // ���� �� �������� ����� ������
            os << setw(5) << *node->getPayload();   // ������ ��������� �������
            node = node->getNext();
        } // for
    } // if
    return os;
} // operator<<*/
