#pragma once
#include "pch.h"

template <typename T, typename V>
class TemplateOuter
{
public:
    // класс Inner имеет доступ ко всем полям и методам Outer
    // friend class Inner;

    // вложенный класс - ьоже шаблонный !!
    class Inner
    {
        // поля внутреннего класса
        T c_;
        V d_;
        TemplateOuter *outer_;  // синтаксис разрешает указатели на внешний класс

    public:
        Inner():c_(), d_(), outer_() {  }
        Inner(T c, V d, TemplateOuter<T, V> *outer)
            :c_(c), d_(d), outer_(outer) {  }
        ~Inner()=default;

        T getC() const { return c_; }
        V getD() const { return d_; }
        T getOuterA() const { return outer_->a_; }

        void setC(T value) { c_ = value; }
        void setD(V value) { d_ = value; }
        void setOuter(TemplateOuter *value) { outer_ = value; }

        // демонстрация доступности элементов внешнего класса
		// во внутреннем
        void foo()
        {
            cout << outer_->a_ << ", " << outer_->b_ << "\n";
        } // foo

        void bar();
    };

private:
    T a_;
    V b_;
    Inner inner_;

public:
    TemplateOuter():a_(), b_(), inner_(0, 0, this) {}
    TemplateOuter(T a, V b):a_(a), b_(b), inner_(0, 0, this) {}

    T getA() const { return a_; }
    V getB() const { return b_; }

    Inner getInner() const { return inner_; }
    void setInner(const Inner &inner)
    {
        inner_.setC(inner.getC());
        inner_.setD(inner.getD());
        inner_.setOuter(this);
    } // setInner

};


// демонстрация доступности элементов внешнего класса
// во внутреннем
template <typename  T, typename V>
void TemplateOuter<T, V>::Inner::bar()
{
    cout << outer_->a_ << ", " << outer_->b_ << "\n";
} // bar
