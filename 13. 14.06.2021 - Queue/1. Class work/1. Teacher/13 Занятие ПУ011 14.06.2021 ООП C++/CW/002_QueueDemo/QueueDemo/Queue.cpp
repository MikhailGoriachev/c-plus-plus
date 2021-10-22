#include "pch.h"
#include "Queue.h"

// методы
// Добавление элемента в очередь
void Queue::enqueue(int value)
{
    if (isFull()) 
        throw exception("Queue. Переполнение очереди");

    // запись элемента в массив
    data_[back_++] = value;

    // коррекция индекса по достижении конца массива 
    if (back_ >= SIZE_QUEUE) back_ = 0;

    // увеличиваем счетчик элементов в очерди
    ++counter_;
} // Queue::enqueue

// Добавление массива в очередь
void Queue::enqueueAll(const int *arr, int n)
{
    for (int i = 0; i < n; i++) 
        enqueue(arr[i]);
} // Queue::enqueueAll

// Убрать элемент из очереди
int Queue::dequeue()
{
    if (isEmpty())
        throw exception("Queue. Очередь пустая");

    // сохранить индекс для уменьшения количества копирований
    int indexItem = front_++;

    if (front_ >= SIZE_QUEUE) front_ = 0;
    counter_--;

    return data_[indexItem];
} // Queue::dequeue


// просмотр элемента в вершине очереди
int Queue::front()
{
    // пустую оочередь не обрабатываем
    if (isEmpty())
        throw exception("Queue. Очередь пустая");

    // вернуть элемент, размещенный на вершине очереди
    return data_[front_];
} // Queue::front

// Перегрузка операции присваивания
Queue &Queue::operator=(const Queue &queue)
{
    counter_ = front_ = back_ = 0;
    enqueueAll(queue.data_, queue.counter_);

    return *this;
} // Queue::operator=

// Перегрузка операции вывода
ostream &operator<<(ostream &os, const Queue &queue)
{
    if (queue.isEmpty())
        // особая обработка для пустой очереди
        os << "очередь пуста";
    else {
        // вывод не пустой очереди - выводим counter_ элементов
        for (int i = 0, k = queue.front_; i < queue.counter_; i++) {
            os << setw(5) << queue.data_[k++];
            if (k >= Queue::SIZE_QUEUE) k = 0;
        } // for i
    } // if

    return os;
} // operator<<