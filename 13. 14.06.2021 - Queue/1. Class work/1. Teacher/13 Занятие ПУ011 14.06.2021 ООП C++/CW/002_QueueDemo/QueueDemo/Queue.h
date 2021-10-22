#pragma once
#include "pch.h"

class Queue
{
public:
    static const int SIZE_QUEUE = 10;

private:
    int counter_;            // ������� ��������� � �������
    int front_;              // ������ �������
    int back_;                // ����� �������
    int data_[SIZE_QUEUE];   // ��������� ������

public:
    // �������� �������������
    // �� ���������
    Queue():counter_(), front_(), back_()
    {
        memset(data_, 0, SIZE_QUEUE * sizeof(int));
    } // Queue

    // � �����������
    Queue(int data[], int n):
        counter_(), front_(), back_()
    {
        memset(data_, 0, SIZE_QUEUE * sizeof(int));
        enqueueAll(data, n);
    } // Queue

    // ����������
    Queue(const Queue &queue):
        counter_(queue.counter_), front_(queue.front_), back_(queue.back_)
    {
        memset(data_, 0, SIZE_QUEUE * sizeof(int));
        
        // !!! ����� ����������� �������� ������ ��� ����������� �����
        // !!! � ������� data_
        memcpy(data_, queue.data_, SIZE_QUEUE * sizeof(int));
    } // Queue

    // ���������� - ����������� �� ����������� ���������� 
    ~Queue() = default;

    // ������ ��� ������ � ��������
    void enqueue(int value);                    // ��������� ������� � �������
    void enqueueAll(const int *arr, int n);     // ��������� ������ ��������� � �������
    int dequeue();                              // ������ ������� �� �������
    int front();                                // ��������� ������� � ������ �������

    // TODO: ����������� �������� ���������� �������� peekLast()
    // TODO: ����������� ������� �������, ��� ������� �����

    // �������� ������� �� �������
    bool isEmpty() const { return counter_ == 0; }

    // �������� ������� �� ������������
    bool isFull()  const { return counter_ >= SIZE_QUEUE; }

    // ������
    int getCount() const { return counter_; }

    Queue &operator=(const Queue &queue);
    friend ostream &operator<<(ostream &os, const Queue &queue);
};