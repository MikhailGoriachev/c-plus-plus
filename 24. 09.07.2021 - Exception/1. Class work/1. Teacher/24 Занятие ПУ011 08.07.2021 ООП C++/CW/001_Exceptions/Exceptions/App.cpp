#include "pch.h"
#include "App.h"
#include "Utils.h"
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"


void zoo(int d);

// обработка исключения в функции
void bar()
{
	int d = getRand(-100, 100);
	
	try {
		zoo(d);
	} // try 
	
	catch (range_error &ex)
	{
		cout << "    bar: <<range_error>> " << ex.what() << "\n";
		throw;  // повторный выброс исключения range_error, 
		        // ex не меняется, передается дальше, раскручивая стек
	} // catch

	cout << "\nd = " << d << "\n\n";
}

// выброс исключения в функции
void zoo(int d)
{
	if (abs(d) > 10 && abs(d) < 60)
		throw  range_error("Недопустимое значение");
	cout<<"zoo: Нормальная работа\n";
}


// Пример использования классов, унаследованных от шаблонного класса
// Derived1 - унаследован от Base<double>
// Derived2 - унаследован от Base<int>
void templatesAndInherit() 
{
	cout << "\n    Не полиморфные вызовы\n\n";

	// не полиморфная работа - скалярные переменные
	Derived1 derived1(9.81, 3.12);
	derived1.foo();

	Derived2 derived2(-1, -2);
	derived2.foo();

	// полиморфная работа - вызов виртуальных методов производного класса
	// при помощи указателя на базовый класс

	cout << "\n\n    Полиморфные вызовы\n\n";

	// указатель на базовый класс, закрытый типом <double>
	Base<double> *ptrDerived1 = new Derived1(M_PI, M_E);
	ptrDerived1->foo(); // метод производного класса вызывается по указателю на базовый класс
	delete ptrDerived1;

	// указатель на базовый класс, закрытый типом <int>
	Base<int> *ptrDerived2 = new Derived2(404, 500);
	ptrDerived2->foo();
	delete ptrDerived2;
} // templatesAndInherit
