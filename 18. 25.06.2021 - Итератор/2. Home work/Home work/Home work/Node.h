#pragma once
#include "pch.h"

// узел списка
//template <typename T>
//class Node
//{
//    T    payload_;  // данные для хранения - произвольный тип
//    Node *next_;    // указатель на следующий узел списка
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
//    // геттеры и сеттеры
//    T *getPayload() { return &payload_; }
//    Node *getNext() const { return next_;    }
//
//    void setPayload(T data)  { payload_ = data; }
//    void setNext(Node *next) { next_ = next;    }
//
//    // перегруженнные операторы
//    Node &operator=(const Node&) = default;
//    //Node &operator=(const T c) // добавлена перед занятием
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