#pragma once
#include "pch.h"
#include "DblList.h"


template <typename T>
class Queue
{

public:
    static const int SIZE_QUEUE = 10;
    friend class Iterator;
    

private:
   
    DblList<T> data_;   // контейнер данных

public:
    // ансамбль конструкторов
    // по умолчанию
    Queue()  {
       
    } // Queue

    // с параметрами
    Queue(T* data, int n)        
    {
       enqueueAll(data, n);
    } // Queue

    // с параметрами
    Queue(DblList<T> data)
    {
        data_ = data;
    } // Queue

    // копирующий
    Queue(const Queue& queue) :
        data_(queue.data_)
    {
       
    } // Queue

    // Деструктор - соглашаемся на стандартный деструктор 
    ~Queue() = default;

    // методы для работы с очередью
    void enqueue(T value);                    // поставить элемент в очередь
    void enqueueAll(const T* arr, int n);     // поставить массив элементов в очередь
    T dequeue();                              // убрать элемент из очереди
    T front();                                // прочитать элемент в голове очереди

    // TODO: реализовать просмотр последнего элемента peekLast()
    // TODO: реализовать очистку очереди, как очистку стека

    // проверка очереди на пустоту
    bool isEmpty() const { return data_.isEmpty(); }
     

    Queue& operator=(const Queue & queue);
    friend ostream& operator<<(ostream & os, const Queue & queue) 
    {
        if (queue.isEmpty())
            // особая обработка для пустой очереди
            os << "очередь пуста";
        else {
            
            os << queue.data_;

        } // if

        return os;
    } // operator<<


    // Прямой итератор по стеку - доступ к элеменам стека только по чтению!!!
    template <typename T>
    class Iterator
    {
        Node<T>* node_;    // указатель на текущий узел
        int     position_; // позиция узла, индекс узла
        const DblList<T>& list_; // константная ссылка на список по которому ведется итерация

    public:
#pragma region Блок реализации правила трех
        // конструкторы и деструктор
        Iterator() = default;

        Iterator(const Queue<T>& queue) :
            node_(queue.data_.getHead()),
            position_(),
            list_(queue.data_)
        {}

        Iterator(const Iterator<T>& iterator) = default;

        ~Iterator() = default;

        // перегрузка операции =
        Iterator& operator=(const Iterator<T>& iterator) = default;
#pragma endregion 

        // методы и перегруженные операции для работы итератора

        // переход в начало стека
        void begin()
        {
            node_ = list_.getHead();
            position_ = 0;
        } // begin


        // вернуть позицию за последней доступной позицией списка
        bool end() const { return  position_ == list_.getCount(); }


        // переход к следующему узлу списка
        Iterator& operator++()
        {
            // проверка корректности
            if (position_ >= list_.getCount())
                throw exception("List. Выход за пределы стека");

            // собственно переход на следующий узел
            ++position_;
            node_ = node_->getNext();

            // вернуть ссылку на узел
            return *this;
        } // operator++

        Iterator& operator--()
        {
            if (position_ < 0)
                throw exception("List. Выход за пределы списка");

            // собственно переход на следующий узел
            --position_;
            node_ = node_->getPrev();

            // вернуть ссылку на узел
            return *this;
        } // operator++

        // перегрузка разыменования, разыменованный итератор возвращает значение узла списка
        // для защиты от изменения
        T operator*() const
        {
            if (position_ >= list_.getCount())
                throw exception("List. Выход за пределы стека");

            return *node_->getPayload();
        } // operator*
    };


};


// методы
// Добавление элемента в очередь
template <typename T>
void Queue<T>::enqueue(T value)
{
    // запись элемента 
    data_.add(value);

} // Queue::enqueue

// Добавление массива в очередь
template <typename T>
void Queue<T>::enqueueAll(const T* arr, int n)
{
    for (int i = 0; i < n; i++)
        enqueue(arr[i]);
} // Queue::enqueueAll

// Убрать элемент из очереди
template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
        throw exception("Queue. Очередь пустая");

    T save = data_.get(0);
    data_.removeAt(0);

    return save;
} // Queue::dequeue


// просмотр элемента в вершине очереди
template <typename T>
T Queue<T>::front()
{
    // пустую оочередь не обрабатываем
    if (isEmpty())
        throw exception("Queue. Очередь пустая");

    // вернуть элемент, размещенный на вершине очереди
    return data_.get(data_.getCount() - 1);
} // Queue::front

// Перегрузка операции присваивания
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
    data_ = queue.data_;

    return *this;
} // Queue::operator=



