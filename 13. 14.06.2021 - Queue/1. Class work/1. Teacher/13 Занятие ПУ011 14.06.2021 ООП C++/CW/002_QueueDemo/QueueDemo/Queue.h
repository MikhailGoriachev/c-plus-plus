#pragma once
#include "pch.h"

class Queue
{
public:
    static const int SIZE_QUEUE = 10;

private:
    int counter_;            // счетчик элементов в очереди
    int front_;              // начало очереди
    int back_;                // хвост очереди
    int data_[SIZE_QUEUE];   // контейнер данных

public:
    // ансамбль конструкторов
    // по умолчанию
    Queue():counter_(), front_(), back_()
    {
        memset(data_, 0, SIZE_QUEUE * sizeof(int));
    } // Queue

    // с параметрами
    Queue(int data[], int n):
        counter_(), front_(), back_()
    {
        memset(data_, 0, SIZE_QUEUE * sizeof(int));
        enqueueAll(data, n);
    } // Queue

    // копирующий
    Queue(const Queue &queue):
        counter_(queue.counter_), front_(queue.front_), back_(queue.back_)
    {
        memset(data_, 0, SIZE_QUEUE * sizeof(int));
        
        // !!! “акое копирование работает только дл€ примитивных типов
        // !!! в массиве data_
        memcpy(data_, queue.data_, SIZE_QUEUE * sizeof(int));
    } // Queue

    // ƒеструктор - соглашаемс€ на стандартный деструктор 
    ~Queue() = default;

    // методы дл€ работы с очередью
    void enqueue(int value);                    // поставить элемент в очередь
    void enqueueAll(const int *arr, int n);     // поставить массив элементов в очередь
    int dequeue();                              // убрать элемент из очереди
    int front();                                // прочитать элемент в голове очереди

    // TODO: реализовать просмотр последнего элемента peekLast()
    // TODO: реализовать очистку очереди, как очистку стека

    // проверка очереди на пустоту
    bool isEmpty() const { return counter_ == 0; }

    // проверка очереди на переполнение
    bool isFull()  const { return counter_ >= SIZE_QUEUE; }

    // геттер
    int getCount() const { return counter_; }

    Queue &operator=(const Queue &queue);
    friend ostream &operator<<(ostream &os, const Queue &queue);
};