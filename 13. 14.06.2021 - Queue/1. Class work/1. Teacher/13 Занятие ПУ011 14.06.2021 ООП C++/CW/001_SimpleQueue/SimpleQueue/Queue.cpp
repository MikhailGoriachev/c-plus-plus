#include "pch.h"
#include "Queue.h"


// ���������� �������� � ������� 
void Queue::enqueue(int value)
{
    if (isFull())
        throw exception("Queue: ������� �����������");

    data_[back_++] = value;
} // Queue::enqueue


// ���������� ������� � �������
void Queue::enqueueAll(int* values, int n)
{
    for (int i = 0; i < n; ++i)
        enqueue(values[i]);
} // Queue::enqueueAll


// ������ ������� � ������ �������
int Queue::dequeue()
{
    if (isEmpty())
        throw exception("Queue: ������� �����");

	// ��������� ��������� ������� 
    int temp = data_[0];

	// ����� ������� ��������� �������
    for (int i = 0; i < back_ - 1; ++i)
        data_[i] = data_[i + 1];

	// ������� ������� � ������ ������
    back_--;
    return temp;
} // Queue::dequeue


// ��������� �������� � ������ ������
int Queue::front()
{
    if (isEmpty())
        throw exception("Queue: ������� �����");

    return data_[0];
} // Queue::front


// ��������� �������� � ������ ������
int Queue::back()
{
    if (isEmpty())
        throw exception("Queue: ������� �����");
	
    return data_[back_-1];
} // Queue::back


// ������� ������� 
void Queue::clear()
{
    back_ = 0;
} // Queue::clear

// ���������� �������� ������
ostream& operator<<(ostream& os, const Queue& queue)
{
    if (queue.isEmpty())
        os << "������� �����";
    else {
        // ����� ��������� ������� 
        for (int i = 0; i < queue.back_; ++i) {
            os << setw(5) << queue.data_[i];
        } // for i
    } // if

    return os;
} // operator<<
