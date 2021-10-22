#pragma once
#include "pch.h"
#include "List.h"
#include "Node.h"

// Шаблонный класс стек на базе шаблонного класса - односвязного списка
template <typename T>
class Stack
{
    // контейнер данных
    List<T> data_;

public:
    // ансамбль конструкторов
    Stack() = default;
    Stack(T *data, int n)
    {
        data_.addAll(data, n);
    } // Stack

    Stack(const Stack &stack)=default;

    // проверка стека на пустоту
    bool isEmpty() const { return data_.isEmpty(); }

    // помещаем данные в стек
    void push(T payload)
    {
        if (data_.isEmpty())
            data_.add(payload);
        else
            data_.insert(0, payload);    
    } // push

    // добавить массив в стек
    void pushAll(T *payloads, int n)
    {
        if (data_.isEmpty())
            data_.addAll(payloads, n);
        else {
            // реверсировать массив, добавить массив в такой, 
            // правильной последовательности
            T *data = new T[n];
            for(int i = n-1; i >= 0; i--) data[i] = payloads[n-1 - i];
            data_.insertAll(0, data, n);
            delete[] data;
        } // if
    } // pushAll
    
    // чтение данных из стека - забрать элемент с вершины
    T pop()
    {
        if (data_.isEmpty())
            throw exception("Stack: Стек пуст");
        
        T value = data_.get(0);
        data_.removeAt(0);
        return value;
    } // pop

    // проверить элемент на вершине стека
    T peek()
    {
        if (data_.isEmpty())
            throw exception("Stack: Стек пуст");
        return data_.get(0);
    } // peek

    // очистка стека делегируется списку
    void clear() { data_.clear(); }

    // перегрузка оператора присваивания
    Stack &operator=(const Stack &stack)=default;

    // перегрузка оператора вывода
	template <typename TT>
    friend ostream& operator<<(ostream& os, const Stack<TT>& stack);
};


// реализация шаблонной функции - перегрузки операции вывода
template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& stack)
{
    if (stack.isEmpty())
        os << "стек пуст";
    else {
        int n = stack.data_.getCount();
        Node<T>* node = stack.data_.getHead();

        for (int i = 0; i < n; ++i) {  // пока не достигли конца списка
            os << setw(5) << node->getPayload();   // вывели очередной элемент
            node = node->getNext();
        } // for
    } // if
    return os;
} // operator<<
