#pragma once
#include "pch.h"

// ���� ������
//template <typename T>
//class Node
//{
//    T    payload_;  // ������ ��� �������� - ������������ ���
//    Node *next_;    // ��������� �� ��������� ���� ������
//
//public:
//    Node():payload_(), next_() {  }
//
//    explicit Node(T data):next_()
//    {
//        payload_ = data;
//    } // Node
//    
//    Node(const Node &) = default;
//    ~Node() = default;
//
//    // ������� � �������
//    T *getPayload() { return &payload_; }
//    Node *getNext() const { return next_;    }
//
//    void setPayload(T data)  { payload_ = data; }
//    void setNext(Node *next) { next_ = next;    }
//
//    // �������������� ���������
//    Node &operator=(const Node&) = default;
//    //Node &operator=(const T c) // ��������� ����� ��������
//    //{
//    //    payload_ = c;
//    //    return* this;
//    //}
//
//    friend ostream &operator<<(ostream &os, const Node<T>& node)
//    {
//        os << node.payload_;
//        return os;
//    } // operator<<
//};
//