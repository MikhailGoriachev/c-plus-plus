#include "pch.h"
#include "Outer.h"

// демонстраци€ доступности элементов внешнего класса
// во внутреннем
void Outer::Inner::foo()
{
    cout<< "    Outer::Inner::foo: outer.a = " << outer_->a_
	    << ", outer.b = " << outer_->b_ << "\n";
} // foo

// перегрузка оперции вывода дл€ внутреннего класса
ostream& operator<<(ostream& os, Outer::Inner const& obj)
{
	os << "    Outer::Inner {c: " << obj.c_ << ", d: " << obj.d_ << "}";
	return os;
} // operator<<

// демонстраци€ доступа к пол€м экземпл€ра внутреннего класса
void Outer::bar()
{
	// дл€ объекта внутреннего класса установим значени€ полей
	Outer::Inner t;
	t.setC(23);
	t.setD(33.33);

	// и выведем в консоль этот объект
	cout << "    t: " << t << "\n";
} // Outer::bar