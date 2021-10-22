#pragma once
#include "pch.h"
#include "List.h"
//#include "Node.h"

// Ўаблонный класс стек на базе шаблонного класса - односв€зного списка
template <typename T>
class Stack
{
    // контейнер данных
    List<T> data_;

public:

    // »тератор 26.06.2021
    class Iterator
    {
        // константна€ cсылка список
        List<T>& list_;

        // позици€
        int position_;

        // указатель на текущий объект
        Node<T>* node_;

    public:

#pragma region ѕравило трех

        // конструктор по умолчанию
        Iterator() = default;

        // конструктор на базе стека
        Iterator(Stack<T>& stack) : list_(stack.data_), position_(), node_(list_.getHead()) {};

        // копирующий конструктор 
        Iterator(const Iterator& iterator) = default;

        // деструктор 
        ~Iterator() = default;

        // перегрузка операции присваивани€
        Iterator& operator=(const Iterator& iterator) = default;

#pragma endregion

#pragma region ћетоды итератора

        // установка в начало
        int begin()
        {
            // установка указател€ на первый элемент списка
            node_ = list_.getHead();

            // обнуление позиции
            position_ = 0;

            // возвращение позиции
            return position_;
        }

        // позици€ после последней
        int end() { return list_.getCount(); }

        // вз€ть данные
        T get()
        {
            // если позици€ некорректна
            if (position_ < 0 || position_ >= list_.getCount())
                throw exception("Iterator: ѕозици€ некорректна");

            return *node_->getPayload();
        }

        // ++инекремент
        Iterator& operator++()
        {
            // если позици€ некорректна
            if (position_ >= list_.getCount())
                throw exception("Iterator: ѕозици€ некорректна");

            position_++;

            // переход на следующую позицию
            node_ = node_->getNext();

            return *this;
        }

        // *разименование 
        T operator*()
        {
            return get();
        }

        // перегрузка операции равенства
        bool operator==(int position) { return position_ == position; }

        // перегрузка опеарции неравенства
        bool operator!=(int position) { return position_ != position; }

#pragma endregion
    };

    // ансамбль конструкторов
    Stack() = default;
    Stack(T* data, int n) {
        pushAll(data, n);
    } // Stack

    Stack(const Stack& stack) = default;

    // проверка стека на пустоту
    bool isEmpty() const { return data_.isEmpty(); }

    // помещаем данные в стек
    void push(T payload) {
        if (data_.isEmpty())
            data_.add(payload);
        else
            data_.insert(0, payload);
    } // push

    // добавить массив в стек
    void pushAll(T* payloads, int n) {

        for (int i = 0; i < n; i++)
            push(payloads[i]);
    } // pushAll

    // чтение данных из стека - забрать элемент с вершины
    T pop() {
        if (data_.isEmpty())
            throw exception("Stack: —тек пуст");

        T value = data_.get(0);
        data_.removeAt(0);
        return value;
    } // pop

    // проверить элемент на вершине стека
    T peek()
    {
        if (data_.isEmpty())
            throw exception("Stack: —тек пуст");
        return data_.get(0);
    } // peek

    // очистка стека
    void clear() { data_.clear(); }

    // перегрузка оператора присваивани€
    Stack& operator=(const Stack& stack) = default;

    // перегрузка оператора вывода
    template <typename TT>
    friend ostream& operator<<(ostream& os, const Stack<TT>& stack);
    /* {
        if (stack.isEmpty())
            os << "стек пуст";
        else {
            int n = stack.data_.getCount();

            List<T>::Node<T>*node = stack.data_.getHead();

            for (int i = 0; i < n; ++i) {  // пока не достигли конца списка
                os << setw(5) << *node->getPayload();   // вывели очередной элемент
                node = node->getNext();
            } // for
        } // if
        return os;
    } // operator<<
    */
};

// перегрузка оператора вывода
template <typename TT>
ostream& operator<<(ostream& os, const Stack<TT>& stack)
{
    if (stack.isEmpty())
        os << "стек пуст";
    else {
        int n = stack.data_.getCount();

        Node<TT>* node = stack.data_.getHead();

        for (int i = 0; i < n; ++i) {  // пока не достигли конца списка
            os << setw(5) << *node->getPayload();   // вывели очередной элемент
            node = node->getNext();
        } // for
    } // if
    return os;
} // operator<<
