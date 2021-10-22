#pragma once
// ���� ����������� ������
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
    T* getPayload() { return &payload_; }
    void setPayload(T value) { payload_ = value; }

    Node<T>* getNext() const { return next_; }
    void setNext(Node<T>* value) { next_ = value; }

    Node<T>* getPrev() const { return prev_; }
    void setPrev(Node<T>* value) { prev_ = value; }

    // �������������� ���������
    Node& operator=(const Node&) = default;

    friend ostream& operator<<(ostream& os, const Node<T>& node)
    {
        os << node.payload_;
        return os;
    } // operator<<
};