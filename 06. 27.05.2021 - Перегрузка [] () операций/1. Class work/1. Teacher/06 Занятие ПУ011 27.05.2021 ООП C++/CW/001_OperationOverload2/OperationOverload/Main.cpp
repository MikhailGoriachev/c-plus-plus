#include "pch.h"
#include "Utils.h"
#include "TRectangle.h"

// перегрузка операций
// В C++17 стандарт разрешает перегружать следующие операторы/операции:
//     ++  –-  +  -  *  /  %
//     <<  >>  ^   &   |   ~   ,   =   <   >   <=  >=   ==   !=  
//     !   &&  ||  +=  -=  /=  %=  ^=  &=  |=  *=  <<=  >>=  []  ()
//     ->  ->* 
//     new  new[]  delete  delete[]
// -----------------------------------------------------------------------
//
// Не перегужаются операции
//     .  .*  ?: ::

// перегрузка операций обычными функциями
TRectangle operator+(TRectangle rect1, TRectangle rect2);
TRectangle operator+(TRectangle rect1, double value);
TRectangle operator+(double value, TRectangle rect1);

TRectangle operator--(TRectangle &rect1);       // префиксный
TRectangle operator--(TRectangle &rect1, int);  // постфиксный

// ostream &operator<<(ostream &os,  const TRectangle &rect);

// функция, выполняющая ту же обработку, что и перегруженная операция +
TRectangle add(TRectangle rect1, TRectangle rect2);

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 20.05.2021 - перегрузка операций");
	
	TRectangle r(10., 15);
	TRectangle s(15., 10);

    TRectangle cc = add(r, s);
    // cc = operator+(r, s);
    cc = r + s;
    cout << r << "\n" << s << "\n" << cc << "\n\n";

    // использование перегруженной операции +
    // перегруженная операция "прямоугольник + число"
    cout << "\nr = " << r << "\n"; 
    r = r + 10;
    cout << "r + 10 = " << r << "\n";

    r = 10 + r;
    cout << "10 + r = " << r << "\n\n";
    
    r = r - s;
    cout << "r = " << r << ";   s = " << s << ";   rs = r - s = " << cc << "\n\n";

    s = s - 5;
    cout << "s - 5 = " << s << "\n";
    
    cout << "\n\n-----------------------------------------------\n\n";
    cout << "s   = " << s   << "\n";
    cout << "--s = " << --s << "\n";
    cout << "s   = " << s   << "\n";

    cout << "s-- = " << s-- << "\n";
    cout << "s   = " << s   << "\n";


    cout << "\n\n-----------------------------------------------\n\n";
    cout << "s   = " << s << "\n";
    cout << "++s = " << ++s << "\n";
    cout << "s   = " << s << "\n";

    cout << "s++ = " << s++ << "\n";
    cout << "s   = " << s << "\n";

	
	getKey();
	return 0;
} // main

// int operator +(int a, int b) { return a + b; }

TRectangle operator+(TRectangle rect1, TRectangle rect2)
{
    TRectangle *rect = new TRectangle();

    rect->setA(rect1.getA() + rect2.getA());
    rect->setB(rect1.getB() + rect2.getB());

    return *rect;
} // operator+ 


TRectangle operator+(TRectangle rect1, double value)
{
    TRectangle *rect = new TRectangle();
    rect->setA(rect1.getA() + value);
    rect->setB(rect1.getB() + value);
    return *rect;
}

// перегрузка операции при помощи перегруженной операции 
TRectangle operator+(double value, TRectangle rect1)
{
    return rect1 + value;
}


TRectangle add(TRectangle rect1, TRectangle rect2)
{
    TRectangle *rect = new TRectangle();

    rect->setA(rect1.getA() + rect2.getA());
    rect->setB(rect1.getB() + rect2.getB());

    return *rect;
}

// ostream &operator<<(ostream &os,  const TRectangle &rect)
// {
//     os << fixed << setw(6) << setprecision(3) 
//        << rect.getA() 
//        << " x " << rect.getB();
// 
//     return os;
// } // operator<<

 // префиксный
TRectangle operator--(TRectangle &rect1)
{
    rect1.setA(rect1.getA()-1);
    rect1.setB(rect1.getB()-1);

    return rect1;
} // operator--


// постфиксный - видно из использования второго, фиктивного аргумента
TRectangle operator--(TRectangle &rect1, int)
{
    TRectangle *temp = new TRectangle(rect1.getA(), rect1.getB());

    rect1.setA(rect1.getA()-1);
    rect1.setB(rect1.getB()-1);

    return *temp;
} // operator--