#include "pch.h"
#include "Deque.h"

// ������ � ������ ���� - "���������" ������
// �������� ������ � ������ ����
void Deque::shift(int value)
{
    if (isFull())
        throw exception("Deque: ��� ����������");

    // ����� ������ � ������� ������, ����� ���������� �����
    // ��� ������� ������ � 0-� ������� ������� - ����������
    // �������� ������
    for (int i = back_; i > 0; --i)
        data_[i] = data_[i-1];

    // ������ ������ �������� � ������ ����
    data_[0] = value;

    // ��������� ������ ���� � �������� ���������
    back_++;
} // Deque::shift

// ������ ������� ������ � ������ ����  "���������" ��������
void Deque::shiftAll(int values[], int n)
{
    for (int i = 0; i < n; i++)
        shift(values[i]);
} // Deque::shiftAll

// ������ �������� � "������" ���� - "���������" ��������
int Deque::unshift()
{
    if (isEmpty())
        throw exception("Deque: ��� ����");

    // ������ ���� ������ �� ������� 0
    int save = data_[0];

    // �������� ������ ����� - ����� ����������
    // "���������" ��������
    for(int i = 0; i < back_-1; ++i)
        data_[i] = data_[i+1];

    // ��������� ��������� ������
    back_--;

    // ������� ����������� ��������
    return save;    
} // Deque::unshift

// ���������� ������ ������ ���� ��� ����������� ����������,
// ���� ��� ����
int Deque::front()
{
    if (isEmpty())
        throw exception("Deque: ��� ����");

    // ������ ���� ������ �� ������� 0
    return data_[0];
} // Deque::front

// ������ � ������ ���� - "�������" ������

// ������ �������� � ����� ���� - "�������" �������� ������
void Deque::push(int value)
{
    if (isFull())
        throw exception("Deque: ��� ����������");

    // �������� ������� � ��������� ��������, ��� ���� back_
    // ��������� �� ������ ��������� ������ ������ ����
    data_[back_++] = value;
} // Deque::push

// ��������� ������ � ����� ����
void Deque::pushAll(int values[], int n)
{
    for (int i = 0; i < n; i++)
        push(values[i]);
} // Deque::pushAll

// ���������� ������ � ������ ���� - "�������" ��������
int Deque::pop()
{
    if (isEmpty())
        throw exception("Deque: ��� ����");

    // �� ����� ���� ��������� ������ back_, ���������
    // ���������� ������� �� ������� back_-1
    return data_[--back_];  // ������� �������� � ����������� ������� ������ ����
} // Deque::pop

// ���������� ��������� ������� ���� ��� ����������� ����������,
// ���� ��� ����
int Deque::back()
{
    if (isEmpty())
        throw exception("Deque: ��� ����");

    // �� ����� ���� ��������� ������ back_, ���������
    // ���������� ������� �� ������� back_-1
    return data_[back_-1];
} // Deque::back 


// ������� ����
void Deque::clear()
{
    back_ = 0;
} // Deque::clear


// ������������� ��������
Deque &Deque::operator=(const Deque &deque)
{
    if (&deque == this) return *this;
	
    // ���������� �������� ������� ������ � �������� ��������� ����
    back_ = deque.back_;

    // ����������� ��������� ����, ��������� �������� ������,
    // ���� � ���������� ������ ��� ����������, ������������
    // �����, ��������� �����
    // memcpy(data_, deque.data_, DEQUE_SIZE * sizeof(int));
    for (int i = 0; i < DEQUE_SIZE; ++i)
        data_[i] = deque.data_[i];

    return *this;    
} // Deque::operator=

// ���������� �������� ������ ��� ����
ostream &operator<<(ostream &os, const Deque &deque)
{
    if (deque.isEmpty())
        os << "��� ����";
    else {
        // ������� ������ �� ������ ���� �� ������
        for (int i = 0; i < deque.back_; ++i)
            os << setw(5) << deque.data_[i];
    } // if

    return os;
} // operator<<
