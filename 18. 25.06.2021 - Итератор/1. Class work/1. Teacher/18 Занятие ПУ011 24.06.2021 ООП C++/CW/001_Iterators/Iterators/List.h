#pragma once
#include "pch.h"
#include "Node.h"

// Односвязный список с внутренним классом - итератором
template <typename T> 
class List
{
    Node<T> *head_;   // указатель на голову (1й элемент) списка
    int  counter_;    // счетчик элементов списка

public:
    List():head_(), counter_() {  }
    List(T *data, int n): head_(), counter_()
    {
        addAll(data, n);
    } // List

    List(const List& list) : head_(), counter_() {		
		Node<T>* node = list.head_;  // адрес первого элемента из списка list
		while (node != nullptr) {    // пока не достигли конца списка
			add(*node->getPayload());
			node = node->getNext();
		} // while
	}

    ~List() { clear(); }

    int getCount() const { return counter_; }

    // добавление элемента в конец списка
    void add(T payload);

    // добавление массива элементов в конец списка
    void addAll(T *payloads, int n);

    // вставка элемента перед указанной позицией
    void insert(int position, T payload);

    // вставка массива элементов перед указанной позицией
    void insertAll(int position, T *payloads, int n);

    // получение значения элемента списка в позиции position
    T get(int position) const;

    // записать значение value в позицию position
    void put(int position, T value);

    // перегруженная операция индексирования
    Node<T> &operator[](int index);

    // удаление элемента в заданной позиции
    void removeAt(int position);

    void clear();

    List &operator=(const List& listGoods) {
        clear();

		Node<T>* node = listGoods.head_;  // адрес первого элемента из списка listGoods
		while (node != nullptr) {  // пока не достигли конца списка
			add(node->getPayload());
			node = node->getNext();
		} // while

		return *this;
	} // operator=

    // вспомогательные методы
    // получить указатель на голову списка - для ускорения
    // доступа внешним кодом
    Node<T> *getHead() const { return head_; } // getHead

    // проверка списка на пустоту
    bool isEmpty() const { return counter_ == 0; }

    // перегрузка операции вывода
    friend ostream &operator<<(ostream &os, const List<T> &list)
    {
        if (list.counter_ == 0)
            os << "список пуст";
        else {
            Node<T> *node = list.head_;  // адрес первого элемента
            while(node != nullptr) {  // пока не достигли конца списка
                os << *node->getPayload() << " --> ";  // вывели очередной элемент
                node = node->getNext();               // адрес следующего элемента списка 
            } // while
            os << "X";
        } // if

        return os;
    } // operator<<

	// ------------------------------------------------------------------------
	// Прямой итератор    
	template <typename T>
	class Iterator
    {
        Node<T> *node_;       // указатель на текущий узел
        int     position_;    // позиция узла, индекс узла
        const List<T>& list_; // константная ссылка на список по которому ведется итерация
    
    public:
    	// конструкторы и деструктор
        Iterator() = default;
        Iterator(const List<T>& list):
    	     node_(list.head_),
    	     position_(),
    	     list_(list)
        { }
        Iterator(const Iterator<T>& iterator) = default;
        ~Iterator() = default;
    	
    	// перегрузка операции =
    	Iterator &operator=(const Iterator<T>& iterator) = default;
    	
    	// методы и перегруженные операции для работы итератора

    	// переход в начало списка
    	int begin()
    	{
            node_ = list_.head_;
            position_ = 0;
    		
            return position_;
    	} // begin

    	// вернуть позицию за последней доступной позицией списка
        int end() const { return list_.counter_; }

    	// операции сравнения
        bool operator!=(int position) const { return position_ != position; }
        bool operator==(int position) const { return position_ == position; }

    	// переход к следующему узлу списка
    	Iterator &operator++()
    	{
            if (position_ >= list_.counter_)
                throw exception("List. Выход за пределы списка");

    		// собственно переход на следующий узел
            ++position_;
            node_ = node_->getNext();

    		// вернуть ссылку на узел
            return *this;
    	} // operator++

    	// перегрузка разыменования, разыменованный итератор возвращает ссылку на узел списка
    	T &operator*()
    	{
            if (position_ >= list_.counter_)
                throw exception("List. Выход за пределы списка");
    		
            return *node_->getPayload();
    	} // operator*
    };
}; // class List


#pragma region реализация шаблонов
// добавление элемента в конец списка
template <typename T>
void List<T>::add(T payload)
{
    // Создать новый узел для добавления в список
    Node<T> *newNode = new Node<T>(payload);

    // особый случай - добавление первого элемента в список
    if (counter_ == 0) {
        head_ = newNode;
        ++counter_;
        return;
    } // if

    // сканирование элементов списка, выход из цикла, когда
    // node указывает на последний элемент списка
    Node<T> *node = head_;
    while(node->getNext() != nullptr)
        node = node->getNext();

    // добавление в список
    node->setNext(newNode);
    ++counter_;
} // List::add

// вставка массива элементов в конец списка - эффективная реализация
template <typename T>
void List<T>::addAll(T *payloads, int n)
{
    // перейти в конец массива - node будет указывать на последний
    // элемент списка
   Node<T>*node = head_;

    // Переход в конец списка - только если список не пустой
    if (counter_ > 0)
        while(node->getNext() != nullptr)
            node = node->getNext();

    // Вставка массива в конец списка
    for(int i = 0; i < n; ++i) {
       // Создать новый узел списка
       Node<T>*newNode = new Node<T>(payloads[i]);

        // особая ситуация - добавление массива в пустой список
        // необходимо настроить голову списка
        if (counter_ == 0) {
            node = head_ = newNode;
        } // if

        // связываем предыдущий элемент с новым
        node->setNext(newNode);

        // подготовка к следующему циклу - добавленный элемент
        // становится новым последним элементом списка
        node = newNode;
        ++counter_;  // элементов стало больше на 1
    } // for i
} // List::addAll

// вставка элемента перед указанной позицией
template <typename T>
void List<T>::insert(int position, T payload)
{
    if (counter_ == 0)
        throw exception("List: список пуст, операцию insert выполнить невозможно");

    if (position < 0 || position >= counter_) 
        throw exception("List: недопустимая позиция вставки элемента");

    // Новый элемент
   Node<T>*newNode = new Node<T>(payload);

    // вставка перед 0-м элементом
    if (position == 0) {
        newNode->setNext(head_); // новый элемент указывает на остальную часть списка
        head_ = newNode;         // переменная head_ указывает на новый первый элемент списка
        ++counter_;
        return;
    } // if

    // после цикла в  prev хранится адрес элемента после которого
    // надо вставлять новый элемент
   Node<T>*prev = head_;
    for (int i = 0; i < position-1; i++)
        prev = prev->getNext();

    // собственно вставка
    newNode->setNext(prev->getNext());  // вставляемый элемент связываем со следующим
    prev->setNext(newNode);             // связываем предыдущий элемент со вставляемым
    ++counter_;
} // insert

// вставка массива элементов перед указанной позицией - эффективная реализация
template <typename T>
void List<T>::insertAll(int position, T *payloads, int n)
{
    if (counter_ == 0)
        throw exception("List: список пуст, операцию insert выполнить невозможно");

    if (position < 0 || position >= counter_) 
        throw exception("List: недопустимая позиция вставки элемента");

    // prev - элемент перед вставляемым массивом
    // next - элемент после вставляемого массива
   Node<T>*prev = head_, *next;

    // ---> { prev } ---> { next } --->
    //                |
    //                +--> тут будут вставлены элементы массива

    // вставка перед 0-м элементом
    if (position == 0)
        // это и есть оставшаяся часть списка 
        next = head_;
    else {
        // идем по списку до места вставки, определяем prev, next
        for (int i = 0; i < position-1; ++i)
            prev = prev->getNext();

        // это и есть оставшаяся часть списка 
        next = prev->getNext();
    } // if

    // собственно вставка массива между prev и next
   Node<T>*node = prev; // создана для понимания, можно использовать prev
                        // экономия враг понимания
    for (int i = 0; i < n; ++i) {
       Node<T>*newNode = new Node<T>(payloads[i]);

        if (position == 0 && i == 0)
            head_ = newNode;
        else
            node->setNext(newNode);

        // подготовка к следующему циклу
        node = newNode;
        ++counter_;
    } // for i

    // связать послдений вставленный элемент с оставшейся частью списка
    node->setNext(next);
} // List::insertAll

// получение значения элемента списка в позиции position
template <typename T>
T List<T>::get(int position) const
{
    if (counter_ == 0)
        throw exception("List: список пуст");

    if (position < 0 || position >= counter_)
        throw exception("List: недопустимое значение индекса элемента");

    // переход в нужную позицию списка
    Node<T>*node = head_;
    for (int i = 0; i < position; ++i)
        node = node->getNext();

    // вернуть значение элемента в позиции position
    return node->getPayload();
} // List::get

// записать значение value в позицию position
template <typename T>
void List<T>::put(int position, T value)
{
    if (counter_ == 0)
        throw exception("List: список пуст");

    if (position < 0 || position >= counter_)
        throw exception("List: недопустимое значение индекса элемента");

    // переход в нужную позицию списка
   Node<T>*node = head_;
    for (int i = 0; i < position; ++i)
        node = node->getNext();

    // записать значение value в позицию position
    node->setPayload(value);
} // List::put

// перегруженная операция индексирования
template <typename T>
Node<T> &List<T>::operator[](int index)
{
    if (counter_ == 0)
        throw exception("List: список пуст");

    if (index < 0 || index >= counter_)
        throw exception("List: недопустимое значение индекса элемента");

    // переход в нужную позицию списка
   Node<T>*node = head_;
    for (int i = 0; i < index; ++i)
        node = node->getNext();

    return *node;
} // List::operator []

// удаление элемента в заданной позиции
template <typename T>
void List<T>::removeAt(int position)
{
    if (counter_ == 0)
        throw exception("List: список пуст");

    if (position < 0 || position >= counter_)
        throw exception("List: недопустимое значение индекса элемента");

    // особый случай - удаление элемента в голове списка
    if (position == 0) {
       Node<T>*temp = head_->getNext();  // получили адрес новой головы списка
        delete head_;                   // освободили память, занятую старой головой списка
        head_ = temp;                   // установили адрес новой головы списка
        counter_--;                     // элементов стало меньше
        return;
    } // if

    // переход в нужную позицию списка
    Node<T>*node = head_, *prev = head_;
    for (int i = 0; i < position; ++i) {
        prev = node;            // предыдущий узел
        node = node->getNext(); // текущий узел
    } // for i

    // node указывает на удаляемый объект
    // предыдущий элемент теперь указывает на элемент за удаляемым
    // !!! последний элемент списка обрабатывается автоматически - т.е.
    // для последнего элемение getNext() вернет nullptr и это значение
    // запомнится в предыдущем элемнте
    prev->setNext(node->getNext());
    
    // освободить память, занятую удаляемым элементом
    delete node;
    counter_--;
} // List::removeAt

// очистка списка

template <typename T>
void List<T>::clear()
{
    // если список пустой, не выполняем никаких действий
    if (counter_ == 0) return;

    // проходим по списку и освобождаем память, выделенную каждому элементу списка
    Node<T>*node = head_;       // адрес первого элемента
    while(node != nullptr) {  // пока не достигли конца списка
       Node<T>*save = node->getNext(); // сохранить адрес следующей
        delete node;                  // освободить память, выделенную элементу списка
        node = save;                  // адрес следующего элемента списка 
    } // while

    // в списке нет элементов - скорректировать счетчик элементов
    counter_ = 0;
} // List::clear

#pragma endregion