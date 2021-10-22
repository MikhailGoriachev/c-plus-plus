#pragma once
#include "pch.h"

template <typename  T>
class DblList
{
public:
    friend class Node;

	// узел списка
	template <typename T>
    class Node
    {
        T    payload_;  // данные для хранения - произвольный тип
        Node* next_;    // указатель на следующий узел списка
        Node* prev_;    // указатель на предыдующий узел списка

    public:
        Node() :payload_(), next_(), prev_() {  }

        explicit Node(T data) :next_(), prev_()
        {
            payload_ = data;
        } // Node

        Node(const Node&) = default;
        ~Node() = default;

        // геттеры и сеттеры
        T* getPayload()          { return &payload_; }
        void setPayload(T value) { payload_ = value; }

        Node<T>* getNext() const     { return next_; }
        void setNext(Node<T> *value) { next_ = value; }

        Node<T>* getPrev() const     { return prev_; }
        void setPrev(Node<T> *value) { prev_ = value; }
		
        // перегруженнные операторы
        Node& operator=(const Node&) = default;

        friend ostream& operator<<(ostream& os, const Node<T>& node)
        {
            os << node.payload_;
            return os;
        } // operator<<
    };

    /*  ФУНКЦИИ ИТЕРАТОРА ПО ЗАДАНИЮ НА 28.06.2021
    •	begin()переход итератора на начало контейнера, возвращает 0
    •	end()переход итератора в конец контейнера, возвращает позицию,
        следующую за последней доступной позицией
    •	*разыменование итератора, возвращает ссылку на значение, хранимое
        в элементе, на который указывает итератор
    •	++ только префиксный инкремент, переход к следующему элементу контейнера
    •	-- только префиксный декремент, переход к предыдущему элементу контейнера
    •	T get() получение значения, хранимого в элементе, на который указывает
        итератор, доступ по чтению
    •	void put(T value) запись нового значения в элемент контейнера, на который
        указывает итератор, доступ по записи
    */

    // итератор 25.06.2021
    template <typename T>
    class Iterator
    {
        // указатель на текущий элемент списка
        Node<T>* node_;

        // указатель на список
        const DblList<T>& list_;

        // индекс элемента в списке
        int position_;

    public:

        // конструктор по умолчанию
        Iterator() = default;

        // костркутор инициализирующий на базе списка
        Iterator(const DblList<T>& dblList) : list_(dblList)
        {
            // установка указателя на первый элемент списка
            node_ = dblList.head_;

            // установка позиции на нулевой элемент
            position_ = 0;

            // установка указателя на список
            // list_ = dblList;
        }

        // копирующий конструктор 
        Iterator(const Iterator& iterator) = default;

        // деструктор 
        ~Iterator() = default;

        // перегрузка операции присваивания
        Iterator& operator=(const Iterator& iterator) = default;

    public:


        // переход итератора на начало контейнера, возвращает 0
        int begin()
        {
            // установка на нулевую позицию
            node_ = list_.head_;

            position_ = 0;

            return position_;
        }


        // переход итератора в конец контейнера, возвращает позицию,
        // следующую за последней доступной позицией
        int end() { return list_.counter_; }


        // * разыменование итератора, возвращает ссылку на значение, хранимое
        // в элементе, на который указывает итератор
        T& operator*() 
        {
            // если позиция меньше нулевой или больше последней допустимой  
            if (position_ < 0 && position_ >= list_.counter_)
                throw exception("List: Выход за пределы списка!");

            return *node_->getPayload(); 
        }
        

        // ++ только префиксный инкремент, переход к следующему элементу контейнера
        Iterator& operator++()
        {
            // если позиция указывает за пределы списка
            if (position_ >= list_.counter_)
                throw exception("List: Выход за пределы списка!");

            // увеличение позиции
            position_++;

            // переход на следующий элемент списка
            node_ = node_->getNext();

            return *this;
        }


        // -- только префиксный декремент, переход к предыдущему элементу контейнера
        Iterator& operator--()
        {
            // если позиция меньше нулевой
            if (position_ < 0)
                throw exception("List: Выход за пределы списка!");

            // уменьшение позиции
            position_--;

            // переход на предыдущую позицию
            node_ = node_->getPrev();

            return *this;
        }


        // получение значения, хранимого в элементе, на который указывает
        // итератор, доступ по чтению
        T get() 
        {
            return *node_->getPayload();
        }


        // запись нового значения в элемент контейнера, на который
        // указывает итератор, доступ по записи
        void put(T value)
        {
            node_->setPayload(value);
        }


        // перегрузка операции ==
        bool operator==(int position) { return position_ == position; }


        // перегрузка операции !=
        bool operator!=(int position) { return position_ != position; }
    };

private:
	
    Node<T> *head_;    // голова списка
    Node<T> *tail_;    // хвост списка
    int     counter_;  // количество элементов в списке

public:
    // ансамбль конструкторов
	DblList(): head_(), tail_(), counter_() {}
    DblList(const DblList& dblList) : head_(), tail_(), counter_()
	{
		// проходим по списку dblList, добавляем
		// все его элементы в конец нашего списка
        Node<T>* node = dblList.head_;
        while (node != nullptr) {
            add(*node->getPayload());
            node = node->getNext();
        } // while
	} // DblList

    // деструктор
    ~DblList() { clear(); }

    // операция присваивания
    DblList& operator=(const DblList& dblList)
	{
		// защита от самоприсваивания
        if (&dblList == this) return *this;

		// чистим наш список
        clear();

		// защита от пустого второго списка
        if (dblList.isEmpty()) return *this;

		// проходим по списку dblList, добавляем
        // все его элементы в конец нашего списка
        Node<T>* node = dblList.head_;
        while (node != nullptr) {
            add(node->getPayload());
            node = node->getNext();
        } // while

        return *this;
	} // operator=

    // операция вывода
    friend ostream& operator<<(ostream &os, const DblList<T> dblList)
    {
        if (dblList.isEmpty())
            os << "двусвязный список пуст";
        else {
        	// вывод списка при помощи связи вперед
            Node<T>* node = dblList.head_;
            while (node != nullptr) {
                os << setw(3) << *node;
                node = node->getNext();
            } // while
        } // if

        return os;
    } // operator<<


	
    // методы, специфичные для списка
    void add(T value);                      // добавление элемента в конец списка
    void addAll(T* values, int n)
    {
        for (int i = 0; i < n; i++)
        {
            add(values[i]);
        }
    }

    void insert(int position, T value);
    void insertAll(int position, const T* values, int n)
    {
        for (int i = 0; i < n; i++)
        {
            insert(position, values[i]);
        }
    }

    T    get(int position);
    void put(int position, T value);
    T removeAt(int position);

    void clear();

	// проверка на пустой список
    bool isEmpty() const { return counter_ == 0; }

    int getCounter() const { return counter_;  }

};

// добавление элемента в конец списка
template<typename T> void DblList<T>::add(T value)
{
    Node<T>* newNode = new Node<T>(value);
	
    // добавление в пустой список
	if (isEmpty()) {
        head_ = newNode;
        tail_ = newNode;
        ++counter_;
        return;
	} // if

	// добавление в конец непустого списка
    newNode->setPrev(tail_);  // связь назад : новый узел связать с бывшим последним
    tail_->setNext(newNode);  // связь вперед: бывший последний узел связать с вновь добавленным
    tail_ = newNode;          // хвост указывает на новый узел
    ++counter_;               // скорректировать счетчик
} // DblList<T>::add


// вставка в заданную позицию
template<typename T> void DblList<T>::insert(int position, T value)
{
	if (position < 0 || position > counter_-1)
        throw exception("Некорректная позиция вставки элемента");

	// создать новый элемент 
    Node<T>* newNode = new Node<T>(value);
	
	// вставка перед первым элементом
	if (position == 0) {
        newNode->setNext(head_);
        head_->setPrev(newNode);
        head_ = newNode;
        ++counter_;
        return;
	} // if
	
	// вставка перед последним элементом
    if (position == counter_-1) {
        Node<T>* node = tail_->getPrev();
        node->setNext(newNode);
        newNode->setPrev(node);
        newNode->setNext(tail_);
        tail_->setPrev(newNode);
        ++counter_;
    	return;
    } // if

	// вставка перед элементами из диапазона 1 .. counter_-2
	// дойди до нужного элемента
    // перебираем элементы списка до position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // for

	// завершение вставки - настройка связей назад и вперед для
	// вновь добавленного элемента
    newNode->setPrev(node->getPrev());
    newNode->setNext(node);

	// связь предыдущего элемента с новым
    Node<T>* prev = node->getPrev();
    prev->setNext(newNode);

	// связь текущего элемента с новым
    node->setPrev(newNode);
    ++counter_;
} // DblList<T>::insert


// получить данные в позиции position 
template<typename T> T DblList<T>::get(int position)
{
    if (isEmpty() || position >= counter_)
        throw exception("Некорректная позиция элемента");

    // перебираем элементы списка до position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // while

	// вернуть найденный элемент
    return node->getPayload();
} // DblList<T>::get

// записать данные в позицию position
template<typename T> void DblList<T>::put(int position, T value)
{
    if (isEmpty() || position >= counter_)
        throw exception("Некорректная позиция элемента");

    // перебираем элементы списка до position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // while

    // записать найденный элемент
	node->setPayload(value);
} // DblList<T>::put


// Удаление элемента в позиции position
template<typename T> T DblList<T>::removeAt(int position)
{
    if (isEmpty() || position >= counter_)
        throw exception("Некорректная позиция элемента");

	// удаление единственного элемента списка
	if (counter_ == 1) {
        T temp = head_->getPayload();
        delete head_;
        head_ = tail_ = nullptr;
        --counter_;
        return temp;
	} // if

	// удаление первого
	if (position == 0) {
        // сохранить значение
		T temp = head_->getPayload();

		// голова должна указывать на следующий элемент
        head_ = head_->getNext();

		// освобождаем память, выделенную бывшему первому элементу
        delete head_->getPrev();

		// чистим поле предыдущего - т.к. у первого элемента это
		// поле должно быть пустым
        head_->setPrev(nullptr);
		
        --counter_;
        return temp;
	} // if

	// удаление последнего
	if (position == counter_-1) {
		// сохранить возвращаемое значение
        T temp = tail_->getPayload();

		// установить хвост на новый элемент
        tail_ = tail_->getPrev();
		
		// освободить память, занятую удаляемым элементом
        delete tail_->getNext();

		// настроить поле next_ последнего элемента
        tail_->setNext(nullptr);

		// скорректировать счетчик
        --counter_;
        return temp;
 	} // if

	// удаление при position = 1..counter_-2
    // перебираем элементы списка до position
    Node<T>* node = head_;
    for (int i = 0; i < position; ++i) {
        node = node->getNext();
    } // while

	// node - удаляемый элемент, для упрощения получаем указатели
	// на предыдущий и следующий узлы
    Node<T>* prev = node->getPrev();
    Node<T>* next = node->getNext();

	// связь следующего с предыдущим, минуя node
    next->setPrev(prev);
    prev->setNext(next);

	// сохранить значение узла, удалить узел, скорректировать
	// счетичк элементов, вернуть значение
    T temp = node->getPayload();
    delete node;
    --counter_;
	
	return temp;
} // DblList<T>::removeAt

// очистка списка
template<typename T> void DblList<T>::clear()
{
	// повторная очистка не требуется 
    if (isEmpty()) return;
	
	// перебираем все элементы списка
    Node<T> *node = head_;
	while (node != nullptr) {
		// удалить элемент списка
        Node<T>* temp = node->getNext();
        delete node;
        node = temp;
	} // while

    counter_ = 0;
	// TODO: почему при комментировании следующей строки clear() падает?
    head_ = tail_ = nullptr;
} // DblList<T>::clear
