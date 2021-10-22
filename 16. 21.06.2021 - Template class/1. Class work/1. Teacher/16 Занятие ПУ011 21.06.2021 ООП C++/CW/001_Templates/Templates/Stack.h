#pragma once
#include "pch.h"
#include "List.h"
#include "Node.h"

// ��������� ����� ���� �� ���� ���������� ������ - ������������ ������
template <typename T>
class Stack
{
    // ��������� ������
    List<T> data_;

public:
    // �������� �������������
    Stack() = default;
    Stack(T *data, int n)
    {
        data_.addAll(data, n);
    } // Stack

    Stack(const Stack &stack)=default;

    // �������� ����� �� �������
    bool isEmpty() const { return data_.isEmpty(); }

    // �������� ������ � ����
    void push(T payload)
    {
        if (data_.isEmpty())
            data_.add(payload);
        else
            data_.insert(0, payload);    
    } // push

    // �������� ������ � ����
    void pushAll(T *payloads, int n)
    {
        if (data_.isEmpty())
            data_.addAll(payloads, n);
        else {
            // ������������� ������, �������� ������ � �����, 
            // ���������� ������������������
            T *data = new T[n];
            for(int i = n-1; i >= 0; i--) data[i] = payloads[n-1 - i];
            data_.insertAll(0, data, n);
            delete[] data;
        } // if
    } // pushAll
    
    // ������ ������ �� ����� - ������� ������� � �������
    T pop()
    {
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

    // ������� ����� ������������ ������
    void clear() { data_.clear(); }

    // ���������� ��������� ������������
    Stack &operator=(const Stack &stack)=default;

    // ���������� ��������� ������
	template <typename TT>
    friend ostream& operator<<(ostream& os, const Stack<TT>& stack);
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
            os << setw(5) << node->getPayload();   // ������ ��������� �������
            node = node->getNext();
        } // for
    } // if
    return os;
} // operator<<
