#pragma once
#include "pch.h"

// ���������� ��������� ������ - ��� (deque - Double Ended QUEue)
class Deque
{
public:
	// ������ ����
    static const int DEQUE_SIZE = 10;

private:
    int back_;               // ��������� �� ����� ����
    int data_[DEQUE_SIZE];   // ��������� ��� �������� ��������� ����

public:
    // �������� �������������
    // ����������� �� ���������
    Deque():back_() { } // Deque

    // ����������� � �����������
    Deque(int *data, int n): back_()
    {
    	// �.�. ��� ������� ��������
        pushAll(data, n);
    } // Deque

    // ���������� �����������
    Deque(const Deque &deque): back_(deque.back_)
    {
        memcpy(data_, deque.data_, DEQUE_SIZE * sizeof(int));
    } // Deque

    // ����������� �� ���������� �� ���������
    ~Deque() = default;

    // ������, ����������� ���������� ����

    // ������ � ������ ����
    void shift(int value);               // ������� � ������
    void shiftAll(int values[], int n);  // ������� ������� � ������
    int  unshift();                      // ������� ������ �� ������
    int  front();                        // ������ ������ ����

    // ������ � ������ ����
    void push(int value);                // ������� � �����
    void pushAll(int values[], int n);   // ������� ������� � �����
    int  pop();                          // ������� ������ � �����
    int  back();                         // ������ ����� ���� 

    // ������� ����
    void clear();
    

    // �������� ���� �� ������������
    bool isFull() const { return back_ == DEQUE_SIZE; }

    // �������� ���� �� �����������
    bool isEmpty() const { return back_ == 0; }

    // ������������� ��������
    Deque &operator=(const Deque &deque);
    friend ostream &operator<<(ostream &os, const Deque &deque);

};

