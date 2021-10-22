#include "pch.h"
#include "Queue.h"


// добавление элемента в очередь 
void Queue::enqueue(int value)
{
    if (isFull())
        throw exception("Queue: очередь переполнена");

    data_[back_++] = value;
} // Queue::enqueue


// постановка массива в очередь
void Queue::enqueueAll(int* values, int n)
{
    for (int i = 0; i < n; ++i)
        enqueue(values[i]);
} // Queue::enqueueAll


// убрать элемент с головы очереди
int Queue::dequeue()
{
    if (isEmpty())
        throw exception("Queue: очередь пуста");

	// сохранить удаляемый элемент 
    int temp = data_[0];

	// сдвиг массива элементов очереди
    for (int i = 0; i < back_ - 1; ++i)
        data_[i] = data_[i + 1];

	// вернуть элемент с головы очерди
    back_--;
    return temp;
} // Queue::dequeue


// прочитать значение с головы очерди
int Queue::front()
{
    if (isEmpty())
        throw exception("Queue: очередь пуста");

    return data_[0];
} // Queue::front


// прочитать значение с хвоста очерди
int Queue::back()
{
    if (isEmpty())
        throw exception("Queue: очередь пуста");
	
    return data_[back_-1];
} // Queue::back


// очистка очереди 
void Queue::clear()
{
    back_ = 0;
} // Queue::clear

// перегрузка операции вывода
ostream& operator<<(ostream& os, const Queue& queue)
{
    if (queue.isEmpty())
        os << "Очередь пуста";
    else {
        // вывод элементов очереди 
        for (int i = 0; i < queue.back_; ++i) {
            os << setw(5) << queue.data_[i];
        } // for i
    } // if

    return os;
} // operator<<
