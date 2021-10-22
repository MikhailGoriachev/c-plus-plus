#include "pch.h"
#include "Stack.h"


// добавление элемента в стек
void Stack::push(int value)
{
    // при переполнении стека добавление не производим
    if (isFull())
        throw exception("Stack: стек переполнена");

    data_[top_] = value;
    top_++;
} // Stack::push


// извлечение данных из стека
int Stack::pop()
{
    // из пустого стека элемент не убираем
    if (isEmpty())
        throw exception("Stack: стек пуст");

    return data_[--top_];
} // Stack::pop


// читаем вершину стека
int Stack::peek()
{
    // из пустого стека элемент не убираем
    if (isEmpty())
        throw exception("Stack: стек пуст");

    return data_[top_-1];
} // Stack::peek


// запись массива в стек
void Stack::pushAll(const int* data, int n)
{
    for (int i = 0; i < n; ++i)
        push(data[i]);
} // Stack::pushAll


// очистка стека
void Stack::clear()
{
    top_ = 0;
} // Stack::clear


// перегрузка операции вывода
ostream& operator<<(ostream& os, const Stack& stack)
{
    if (stack.isEmpty())
        os << "Стек пуст";
    else {
        // вывод элементов стека 
        for (int i = stack.top_-1; i >= 0; --i) {
            os << setw(5) << stack.data_[i];
        } // for i
    } // if

    return os;
} // operator<<