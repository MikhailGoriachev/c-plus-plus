#pragma once
#include "pch.h"

// обычный класс
class Outer
{
public:
    // класс Inner имеет доступ ко всем полям и методам Outer
    // friend class Inner;

    // вложенный класс
    class Inner
    {
        // поля внутреннего класса
        int c_;
        double d_;
        Outer *outer_;  // синтаксис разрешает указатели на внешний класс

    public:
        Inner():c_(), d_(), outer_() {  }
        Inner(int c, double d, Outer *outer)
            :c_(c), d_(d), outer_(outer) {  }
        ~Inner()=default;

        int getC() const { return c_; }
        double getD() const { return d_; }
        int getOuterA() const { return outer_->a_; }

        void setC(int value) { c_ = value;  }
        void setD(double value) { d_ = value; }
        void setOuter(Outer *value) { outer_ = value; }

    	// определение метода - в Outer.cpp
        void foo();

    	// определение функции - в Outer.cpp
        friend ostream& operator<<(ostream& os, Outer::Inner const& obj);
    };

private:
    int a_;
    double b_;
    Inner inner_;

public:
    Outer():a_(), b_(), inner_(0, 0, this) {}
    Outer(int a, double b):a_(a), b_(b), inner_(0, 0, this) {}

    int  getA() const { return a_; }
    void setA(int value) { a_ = value; }

    double getB() const { return b_; }
    void   setB(double value) { b_ = value; }
	
    Inner getInner() const { return inner_; }
    void setInner(const Inner &inner)
    {
        inner_.setC(inner.getC());
        inner_.setD(inner.getD());
        inner_.setOuter(this);

    	// после добавления friend
        // inner_.c_ = 1;
    } // setInner

	// демонстрация доступа к полям экземпляра внутреннего класса
    void bar();

};

