#pragma once
#include "pch.h"

// Реализация структуры данных - дек (deque - Double Ended QUEue)
class Deque
{
public:
	// размер дека
    static const int DEQUE_SIZE = 10;

private:
    int back_;               // указатель на хвост дека
    int data_[DEQUE_SIZE];   // контейнер для хранения элементов дека

public:
    // ансамбль конструкторов
    // конструктор по умолчанию
    Deque():back_() { } // Deque

    // конструктор с параметрами
    Deque(int *data, int n): back_()
    {
    	// т.к. это быстрая операция
        pushAll(data, n);
    } // Deque

    // копирующий конструктор
    Deque(const Deque &deque): back_(deque.back_)
    {
        memcpy(data_, deque.data_, DEQUE_SIZE * sizeof(int));
    } // Deque

    // соглашаемся на деструктор по умолчанию
    ~Deque() = default;

    // методы, реализующие функционал дека

    // доступ к началу дека
    void shift(int value);               // вставка в начало
    void shiftAll(int values[], int n);  // вставка массива в начало
    int  unshift();                      // забрать данные из начала
    int  front();                        // читать голову дека

    // доступ к хвосту дека
    void push(int value);                // вставка в конец
    void pushAll(int values[], int n);   // вставка массива в конец
    int  pop();                          // забрать данные с конца
    int  back();                         // читать хвост дека 

    // очистка дека
    void clear();
    

    // проверка дека на переполнение
    bool isFull() const { return back_ == DEQUE_SIZE; }

    // проверка дека на опустошение
    bool isEmpty() const { return back_ == 0; }

    // перегруженные операции
    Deque &operator=(const Deque &deque);
    friend ostream &operator<<(ostream &os, const Deque &deque);

};

