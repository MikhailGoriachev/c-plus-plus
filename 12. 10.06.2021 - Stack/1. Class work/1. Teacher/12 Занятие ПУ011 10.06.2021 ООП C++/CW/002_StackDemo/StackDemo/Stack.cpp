#include "pch.h"
#include "Stack.h"


// ���������� �������� � ����
void Stack::push(int value)
{
    // ��� ������������ ����� ���������� �� ����������
    if (isFull())
        throw exception("Stack: ���� �����������");

    data_[top_] = value;
    top_++;
} // Stack::push


// ���������� ������ �� �����
int Stack::pop()
{
    // �� ������� ����� ������� �� �������
    if (isEmpty())
        throw exception("Stack: ���� ����");

    return data_[--top_];
} // Stack::pop


// ������ ������� �����
int Stack::peek()
{
    // �� ������� ����� ������� �� �������
    if (isEmpty())
        throw exception("Stack: ���� ����");

    return data_[top_-1];
} // Stack::peek


// ������ ������� � ����
void Stack::pushAll(const int* data, int n)
{
    for (int i = 0; i < n; ++i)
        push(data[i]);
} // Stack::pushAll


// ������� �����
void Stack::clear()
{
    top_ = 0;
} // Stack::clear


// ���������� �������� ������
ostream& operator<<(ostream& os, const Stack& stack)
{
    if (stack.isEmpty())
        os << "���� ����";
    else {
        // ����� ��������� ����� 
        for (int i = stack.top_-1; i >= 0; --i) {
            os << setw(5) << stack.data_[i];
        } // for i
    } // if

    return os;
} // operator<<