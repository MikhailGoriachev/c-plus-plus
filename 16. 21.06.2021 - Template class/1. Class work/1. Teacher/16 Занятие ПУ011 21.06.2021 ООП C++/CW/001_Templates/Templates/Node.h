#pragma once
#include "pch.h"

// шаблонный класс дл€ представлени€ узла списка
template <typename T>
class Node
{
    T    payload_;  // данные дл€ хранени€ - произвольный тип
    Node *next_;    // указатель на следующий узел списка

public:
    Node():payload_(), next_() {  }

	// требуем €вного вызова конструктора при объ€влении
	// объектов типа Node
    explicit Node(T data):next_()
    {
        payload_ = data;
    } // Node
    
    Node(const Node &) = default;
    ~Node() = default;

    // геттеры и сеттеры
    T getPayload() const { return payload_; }
    Node *getNext() const { return next_; }

    void setPayload(T data) { payload_ = data; }

    void setNext(Node *next) { next_ = next; }

    // перегруженнные операторы
	// присваивание - используем вариант по умолчанию
    Node &operator=(const Node&) = default;

	// перегрузка операции вывода дружественной функцией класса
    friend ostream &operator<<(ostream &os, const Node<T>& node)
    {
        os << node.payload_;
        return os;
    } // operator<<
};

