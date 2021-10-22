#include "pch.h"
#include "Queue.h"

// ������
// ���������� �������� � �������
void Queue::enqueue(int value)
{
    if (isFull()) 
        throw exception("Queue. ������������ �������");

    // ������ �������� � ������
    data_[back_++] = value;

    // ��������� ������� �� ���������� ����� ������� 
    if (back_ >= SIZE_QUEUE) back_ = 0;

    // ����������� ������� ��������� � ������
    ++counter_;
} // Queue::enqueue

// ���������� ������� � �������
void Queue::enqueueAll(const int *arr, int n)
{
    for (int i = 0; i < n; i++) 
        enqueue(arr[i]);
} // Queue::enqueueAll

// ������ ������� �� �������
int Queue::dequeue()
{
    if (isEmpty())
        throw exception("Queue. ������� ������");

    // ��������� ������ ��� ���������� ���������� �����������
    int indexItem = front_++;

    if (front_ >= SIZE_QUEUE) front_ = 0;
    counter_--;

    return data_[indexItem];
} // Queue::dequeue


// �������� �������� � ������� �������
int Queue::front()
{
    // ������ �������� �� ������������
    if (isEmpty())
        throw exception("Queue. ������� ������");

    // ������� �������, ����������� �� ������� �������
    return data_[front_];
} // Queue::front

// ���������� �������� ������������
Queue &Queue::operator=(const Queue &queue)
{
    counter_ = front_ = back_ = 0;
    enqueueAll(queue.data_, queue.counter_);

    return *this;
} // Queue::operator=

// ���������� �������� ������
ostream &operator<<(ostream &os, const Queue &queue)
{
    if (queue.isEmpty())
        // ������ ��������� ��� ������ �������
        os << "������� �����";
    else {
        // ����� �� ������ ������� - ������� counter_ ���������
        for (int i = 0, k = queue.front_; i < queue.counter_; i++) {
            os << setw(5) << queue.data_[k++];
            if (k >= Queue::SIZE_QUEUE) k = 0;
        } // for i
    } // if

    return os;
} // operator<<