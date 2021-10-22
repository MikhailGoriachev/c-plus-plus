#include "pch.h"
#include "App.h"
#include "ClassA.h"
#include "Utils.h"

// спецификаци€ исключений в функции
// тип им€‘ункции(список) throw(список»сключений¬ыбрасываемых‘ункций)
// тип им€‘ункции(список) throw(...) -  разрешено все
// тип им€‘ункции(список) throw()    -  нельз€ выбрасывать ни одно исключение
// !!! если исключение выброшено - вызываетс€ ф-€ void unexpected(), привод€ща€   
// к вызову ф-ии void terminate(), завершающей программу
// в обе эти функции могут быть программистом вставлены вызовы собственных
// функций:
// 	    set_unexpected(им€‘ункции);
//	    set_terminate(им€‘ункции);
void foo() throw(range_error, domain_error)
{
	int number = getRand(1, 100);
	if (number < 10) {
		cout << "    foo: number = " << number << ", все ок\n";
		return;
	} // if

	if (number >= 11 && number <= 50)
		throw range_error("    ¬ыброс исключени€ range_error");

	if (number > 50 && number <= 70)
		throw domain_error("    ¬ыброс исключени€ domain_error");

	// выброс непредусмотренного в заголовке функции исключени€
	throw out_of_range("    ¬ыброс непредусмотренного в заголовке функции исключени€");
} // foo

// ќбычна€ функци€ с функциональным try-блоком
void bar() try {
	int number = getRand(1, 100);

	// создание объекта, которое может и не завершитьс€ 
	ClassA classA(nullptr, -10);

	if (number <= 10) {
		cout << "    bar: number = " << number << ", все ок\n";
		return;
	} // if

	if (number >= 11 and number <= 40)
		throw invalid_argument("    bar: Ќедопустимое значение параметра, исключение invalid_argument");

	throw out_of_range("    bar: выброс исключени€ out_of_range");
} // bar-try
catch (exception& ex) {
	cout << endlm(2) << "    " << ex.what() << endlm(3);
	// throw; // не об€зательно
} // catch




