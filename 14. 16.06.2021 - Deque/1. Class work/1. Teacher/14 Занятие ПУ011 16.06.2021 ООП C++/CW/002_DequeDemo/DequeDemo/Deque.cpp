#include "pch.h"
#include "Deque.h"

// доступ к началу дека - "медленный" доступ
// добавить данные в голову дека
void Deque::shift(int value)
{
    if (isFull())
        throw exception("Deque: дек переполнен");

    // сдвиг данных в массиве вправо, чтобы освободить место
    // для вставки данных в 0-й элемент массива - контейнера
    // хранения данных
    for (int i = back_; i > 0; --i)
        data_[i] = data_[i-1];

    // запись нового элемента в голову дека
    data_[0] = value;

    // коррекция хвоста дека и счетчика элементов
    back_++;
} // Deque::shift

// запись массива данных в начало дека  "медленная" операция
void Deque::shiftAll(int values[], int n)
{
    for (int i = 0; i < n; i++)
        shift(values[i]);
} // Deque::shiftAll

// чтение элемента с "головы" дека - "медленная" операция
int Deque::unshift()
{
    if (isEmpty())
        throw exception("Deque: дек пуст");

    // начало дека всегда по индексу 0
    int save = data_[0];

    // сдвигаем данные влево - таков функционал
    // "медленной" операции
    for(int i = 0; i < back_-1; ++i)
        data_[i] = data_[i+1];

    // коррекция указателя хвоста
    back_--;

    // вернуть сохраненное значение
    return save;    
} // Deque::unshift

// возвращает первый символ дека или выбрасывает исключение,
// если дек пуст
int Deque::front()
{
    if (isEmpty())
        throw exception("Deque: дек пуст");

    // начало дека всегда по индексу 0
    return data_[0];
} // Deque::front

// доступ к хвосту дека - "быстрый" доступ

// запись элемента в хвост дека - "быстрая" операция записи
void Deque::push(int value)
{
    if (isFull())
        throw exception("Deque: дек переполнен");

    // записать элемент в контейнер хранения, при этом back_
    // указывает на первую свободную ячейку хвоста дека
    data_[back_++] = value;
} // Deque::push

// групповая запись в хвост дека
void Deque::pushAll(int values[], int n)
{
    for (int i = 0; i < n; i++)
        push(values[i]);
} // Deque::pushAll

// извлечение данных с хвоста дека - "быстрая" операция
int Deque::pop()
{
    if (isEmpty())
        throw exception("Deque: дек пуст");

    // на хвост дека указывает индекс back_, последний
    // записанный элемент по индексу back_-1
    return data_[--back_];  // возврат элемента и модификация индекса хвоста дека
} // Deque::pop

// возвращает последний элемент дека или выбрасывает исключение,
// если дек пуст
int Deque::back()
{
    if (isEmpty())
        throw exception("Deque: дек пуст");

    // на хвост дека указывает индекс back_, последний
    // записанный элемент по индексу back_-1
    return data_[back_-1];
} // Deque::back 


// очистка дека
void Deque::clear()
{
    back_ = 0;
} // Deque::clear


// перегруженные операции
Deque &Deque::operator=(const Deque &deque)
{
    if (&deque == this) return *this;
	
    // копировать значения индекса хвоста и счетчика элементов дека
    back_ = deque.back_;

    // копирование элементов дека, коррекнто работает только,
    // если в копируемых данных нет указателей, динамических
    // полей, объектных типов
    // memcpy(data_, deque.data_, DEQUE_SIZE * sizeof(int));
    for (int i = 0; i < DEQUE_SIZE; ++i)
        data_[i] = deque.data_[i];

    return *this;    
} // Deque::operator=

// перегрузка операции вывода для дека
ostream &operator<<(ostream &os, const Deque &deque)
{
    if (deque.isEmpty())
        os << "дек пуст";
    else {
        // выводим данные от начала дека до хвоста
        for (int i = 0; i < deque.back_; ++i)
            os << setw(5) << deque.data_[i];
    } // if

    return os;
} // operator<<
