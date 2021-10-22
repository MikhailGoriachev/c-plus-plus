#pragma once
#include "pch.h"
#include "List.h"
#include "Node.h"

// Шаблонный класс стек на базе шаблонного класса - односвязного списка
template <typename T>
class Stack{

private:
    // контейнер данных
    List<T> data_;

public:
    // ансамбль конструкторов
    Stack() = default;
    Stack(T *data, int n){
        pushAll(data, n);
    } // Stack

    Stack(const Stack &stack)=default;

    // проверка стека на пустоту
    bool isEmpty() const { return data_.isEmpty(); }

    // помещаем данные в стек
    void push(T payload){
        if (data_.isEmpty())
            data_.add(payload);
        else
            data_.insert(0, payload);    
    } // push

    // добавить массив в стек
    void pushAll(T *payloads, int n){

        for (int i = 0; i < n; i++)
            push(payloads[i]);
    } // pushAll
    
    // чтение данных из стека - забрать элемент с вершины
    T pop(){
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

    // очистка стека
    void clear() { data_.clear(); }

    // перегрузка оператора присваивания
    Stack &operator=(const Stack &stack)=default;

    // перегрузка оператора вывода
	template <typename TT>
    friend ostream& operator<<(ostream& os, const Stack<TT>& stack);

    // ------------------------------------------------------------------------
    // Прямой итератор по стеку - доступ к элеменам стека только по чтению!!!
    template <typename T>
    class Iterator
    {
        Node<T>* node_;    // указатель на текущий узел
        int     position_; // позиция узла, индекс узла
        const List<T>& list_; // константная ссылка на список по которому ведется итерация

    public:
		#pragma region Блок реализации правила трех
        // конструкторы и деструктор
        Iterator() = default;

        Iterator(const Stack<T>& stack) :
            node_(stack.data_.getHead()),
            position_(),
            list_(stack.data_)
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
                throw exception("Stack. Выход за пределы стека");

            // собственно переход на следующий узел
            ++position_;
        	node_ = node_->getNext();
        	
            // вернуть ссылку на узел
            return *this;
        } // operator++

    	
        // перегрузка разыменования, разыменованный итератор возвращает значение узла списка
    	// для защиты от изменения
        T operator*() const
        {
            if (position_ >= list_.getCount())
                throw exception("Stack. Выход за пределы стека");

            return *node_->getPayload();
        } // operator*
    };
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
            os << setw(5) << *node->getPayload();   // вывели очередной элемент
            node = node->getNext();
        } // for
    } // if
    return os;
} // operator<<
