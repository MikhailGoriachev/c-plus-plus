#pragma once
#include "pch.h"

// Пример шаблонного класса

// template <class T, class V>
template <typename T, typename V>
class ClassA
{
	// пример полей класса
    T a_;
    V b_;
    T c_;
    bool flag_;

public:
	// Класс по умолчанию генерирует 4 метода:
    //     конструктор по умолчанию,
    //     конструктор копирования,
    //     оператор присваивания
    //     деструктор.
    // Данные методы не могут быть шаблонными.

	ClassA():a_(), b_(), c_() {  }
    ClassA(T a, V b, T c):a_(a), b_(b), c_(c) {  }
    ClassA(const ClassA &classA)=default;
    ~ClassA()=default;

    ClassA &operator=(const ClassA &classA)=default;

	// примеры методов класса с шаблонными параметрами
    T getA() const { return a_; }
    V getB() const { return b_; }
    T getC() const { return c_; }

    void setA(T value);
    void setB(V value) { b_ = value; }
    void setC(T value) { c_ = value; }

	// пример метода, определенного вне класса
    V bar();

	// 1й вариант реализации перегруженной операции ввода
    template <typename TT, typename VV>
    friend ostream &operator<<(ostream &os, const ClassA<TT, VV> &classA);

	// 2й вариант реализации перегруженной операции ввода
    // friend ostream &operator<<(ostream &os, const ClassA<T, V> &classA)
    // {
    //     os << classA.a_ << "; " << classA.b_ << "; " << classA.c_;
    //     return os;
    // } // operator<<
};   

// 1й вариант реализации перегруженной операции ввода
template <typename TT, typename VV>
ostream &operator<<(ostream &os, const ClassA<TT, VV> &classA)
{
    os << classA.a_ << "; " << classA.b_ << "; " << classA.c_;
    return os;
} // operator<<

// реализация метода класса вне объявления шаблона класса
template <typename T, typename V>
void ClassA<T, V>::setA(T value) { a_ = value; }


template <typename T, typename V>
V ClassA<T, V>::bar()
{
    return b_ / 2;  // !!! О смысле операций заботится программист !!!
}
// -------------------------------------------------