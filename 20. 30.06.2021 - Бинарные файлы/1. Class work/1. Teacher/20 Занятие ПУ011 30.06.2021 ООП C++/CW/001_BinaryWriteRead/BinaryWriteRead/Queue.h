#pragma once
#include "pch.h"
#include "DblList.h"


template <typename T>
class Queue
{

public:
    static const int SIZE_QUEUE = 10;
    friend class Iterator;
    

private:
   
    DblList<T> data_;   // ��������� ������

public:
    // �������� �������������
    // �� ���������
    Queue()  {
       
    } // Queue

    // � �����������
    Queue(T* data, int n)        
    {
       enqueueAll(data, n);
    } // Queue

    // � �����������
    Queue(DblList<T> data)
    {
        data_ = data;
    } // Queue

    // ����������
    Queue(const Queue& queue) :
        data_(queue.data_)
    {
       
    } // Queue

    // ���������� - ����������� �� ����������� ���������� 
    ~Queue() = default;

    // ������ ��� ������ � ��������
    void enqueue(T value);                    // ��������� ������� � �������
    void enqueueAll(const T* arr, int n);     // ��������� ������ ��������� � �������
    T dequeue();                              // ������ ������� �� �������
    T front();                                // ��������� ������� � ������ �������

    // TODO: ����������� �������� ���������� �������� peekLast()
    // TODO: ����������� ������� �������, ��� ������� �����

    // �������� ������� �� �������
    bool isEmpty() const { return data_.isEmpty(); }
     

    Queue& operator=(const Queue & queue);
    friend ostream& operator<<(ostream & os, const Queue & queue) 
    {
        if (queue.isEmpty())
            // ������ ��������� ��� ������ �������
            os << "������� �����";
        else {
            
            os << queue.data_;

        } // if

        return os;
    } // operator<<


    // ������ �������� �� ����� - ������ � �������� ����� ������ �� ������!!!
    template <typename T>
    class Iterator
    {
        Node<T>* node_;    // ��������� �� ������� ����
        int     position_; // ������� ����, ������ ����
        const DblList<T>& list_; // ����������� ������ �� ������ �� �������� ������� ��������

    public:
#pragma region ���� ���������� ������� ����
        // ������������ � ����������
        Iterator() = default;

        Iterator(const Queue<T>& queue) :
            node_(queue.data_.getHead()),
            position_(),
            list_(queue.data_)
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
                throw exception("List. ����� �� ������� �����");

            // ���������� ������� �� ��������� ����
            ++position_;
            node_ = node_->getNext();

            // ������� ������ �� ����
            return *this;
        } // operator++

        Iterator& operator--()
        {
            if (position_ < 0)
                throw exception("List. ����� �� ������� ������");

            // ���������� ������� �� ��������� ����
            --position_;
            node_ = node_->getPrev();

            // ������� ������ �� ����
            return *this;
        } // operator++

        // ���������� �������������, �������������� �������� ���������� �������� ���� ������
        // ��� ������ �� ���������
        T operator*() const
        {
            if (position_ >= list_.getCount())
                throw exception("List. ����� �� ������� �����");

            return *node_->getPayload();
        } // operator*
    };


};


// ������
// ���������� �������� � �������
template <typename T>
void Queue<T>::enqueue(T value)
{
    // ������ �������� 
    data_.add(value);

} // Queue::enqueue

// ���������� ������� � �������
template <typename T>
void Queue<T>::enqueueAll(const T* arr, int n)
{
    for (int i = 0; i < n; i++)
        enqueue(arr[i]);
} // Queue::enqueueAll

// ������ ������� �� �������
template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
        throw exception("Queue. ������� ������");

    T save = data_.get(0);
    data_.removeAt(0);

    return save;
} // Queue::dequeue


// �������� �������� � ������� �������
template <typename T>
T Queue<T>::front()
{
    // ������ �������� �� ������������
    if (isEmpty())
        throw exception("Queue. ������� ������");

    // ������� �������, ����������� �� ������� �������
    return data_.get(data_.getCount() - 1);
} // Queue::front

// ���������� �������� ������������
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
    data_ = queue.data_;

    return *this;
} // Queue::operator=



