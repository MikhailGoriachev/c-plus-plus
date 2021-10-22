#pragma once
// узел двусвязного списка
template <typename T>
class Node
{
    T    payload_;  // данные для хранения - произвольный тип
    Node* next_;    // указатель на следующий узел списка
    Node* prev_;    // указатель на предыдующий узел списка

public:
    Node() :payload_(), next_(), prev_() {  }

    explicit Node(T data) :next_(), prev_()
    {
        payload_ = data;
    } // Node

    Node(const Node&) = default;
    ~Node() = default;

    // геттеры и сеттеры
    T* getPayload() { return &payload_; }
    void setPayload(T value) { payload_ = value; }

    Node<T>* getNext() const { return next_; }
    void setNext(Node<T>* value) { next_ = value; }

    Node<T>* getPrev() const { return prev_; }
    void setPrev(Node<T>* value) { prev_ = value; }

    // перегруженнные операторы
    Node& operator=(const Node&) = default;

    friend ostream& operator<<(ostream& os, const Node<T>& node)
    {
        os << node.payload_;
        return os;
    } // operator<<
};