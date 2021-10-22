#pragma once
#include "pch.h"
#include "List.h"
//#include "Node.h"

// ��������� ����� ���� �� ���� ���������� ������ - ������������ ������
template <typename T>
class Stack
{
    // ��������� ������
    List<T> data_;

public:

    // �������� 26.06.2021
    class Iterator
    {
        // ����������� c����� ������
        List<T>& list_;

        // �������
        int position_;

        // ��������� �� ������� ������
        Node<T>* node_;

    public:

#pragma region ������� ����

        // ����������� �� ���������
        Iterator() = default;

        // ����������� �� ���� �����
        Iterator(Stack<T>& stack) : list_(stack.data_), position_(), node_(list_.getHead()) {};

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
            node_ = list_.getHead();

            // ��������� �������
            position_ = 0;

            // ����������� �������
            return position_;
        }

        // ������� ����� ���������
        int end() { return list_.getCount(); }

        // ����� ������
        T get()
        {
            // ���� ������� �����������
            if (position_ < 0 || position_ >= list_.getCount())
                throw exception("Iterator: ������� �����������");

            return *node_->getPayload();
        }

        // ++����������
        Iterator& operator++()
        {
            // ���� ������� �����������
            if (position_ >= list_.getCount())
                throw exception("Iterator: ������� �����������");

            position_++;

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
    Stack(T* data, int n) {
        pushAll(data, n);
    } // Stack

    Stack(const Stack& stack) = default;

    // �������� ����� �� �������
    bool isEmpty() const { return data_.isEmpty(); }

    // �������� ������ � ����
    void push(T payload) {
        if (data_.isEmpty())
            data_.add(payload);
        else
            data_.insert(0, payload);
    } // push

    // �������� ������ � ����
    void pushAll(T* payloads, int n) {

        for (int i = 0; i < n; i++)
            push(payloads[i]);
    } // pushAll

    // ������ ������ �� ����� - ������� ������� � �������
    T pop() {
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
    Stack& operator=(const Stack& stack) = default;

    // ���������� ��������� ������
    template <typename TT>
    friend ostream& operator<<(ostream& os, const Stack<TT>& stack);
    /* {
        if (stack.isEmpty())
            os << "���� ����";
        else {
            int n = stack.data_.getCount();

            List<T>::Node<T>*node = stack.data_.getHead();

            for (int i = 0; i < n; ++i) {  // ���� �� �������� ����� ������
                os << setw(5) << *node->getPayload();   // ������ ��������� �������
                node = node->getNext();
            } // for
        } // if
        return os;
    } // operator<<
    */
};

// ���������� ��������� ������
template <typename TT>
ostream& operator<<(ostream& os, const Stack<TT>& stack)
{
    if (stack.isEmpty())
        os << "���� ����";
    else {
        int n = stack.data_.getCount();

        Node<TT>* node = stack.data_.getHead();

        for (int i = 0; i < n; ++i) {  // ���� �� �������� ����� ������
            os << setw(5) << *node->getPayload();   // ������ ��������� �������
            node = node->getNext();
        } // for
    } // if
    return os;
} // operator<<
