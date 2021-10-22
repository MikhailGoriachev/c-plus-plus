#include "pch.h"
#include "Utils.h"
#include "List.h"
#include "App.h"

#include "Stack.h"

// проверка работы методов списка
void App::checkListMethods()
{
	showNavBarMessage(hintColor, "  Работа с классом List<char>");
	cout << "\n\n\n\n    Список char: " << list_ << "\n\n\n";

	list_.add('~');
	cout << "    В конец добавили ~\n"
		<< "    Список char: " << list_ << "\n\n";

	list_.insert(0, '>');
	cout << "    В начало вставили >\n"
		<< "    Список char: " << list_ << "\n\n";

	list_.removeAt(0);
	cout << "    Из начала удалили >\n"
		<< "    Список char: " << list_ << "\n\n";
} // App::checkListMethods

// проверка работы итератора
void App::checkListIterator()
{
	showNavBarMessage(hintColor, "  Работа с итератором класса List");
	cout << "\n\n\n\n\n    Список char: " << list_ << "\n";

	// алгоритм работы с итератором
	// создать итератор
	// for (установить итератор в начало списка; не достигнут конец списка?; перейти к следующему элементу) {
	// 	   cout << получить элемент по итератору << " ";
	// } // for p

	cout << "    Итератор   : ";
	// создать итератор
	List<char>::Iterator<char> iterator(list_);

	// итерации по списку, чтение элементов
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
		cout << *iterator << " ==> ";
	cout << "X\n";

	// итерации по списку, запись элементов
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
		// *iterator = char(getRand('а', 'я'));
		// *iterator = (char)getRand('а', 'я');
		*iterator = static_cast<char>(getRand('а', 'я'));

	cout << "    Итератор   : ";
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
		cout << *iterator << " ==> ";
	cout << "X\n";
} // checkListIterator

// проверка работы итератора по стеку Stack
void App::checkStackIterator()
{
	showNavBarMessage(hintColor, "  Работа с итератором класса Stack");
	int arr[] = { 20, 30, 40, 50, 60 };
	Stack<int> stack(arr, 5);
	cout << "\n\n\n\n    Стек    : " << stack << "\n";
	
	Stack<int>::Iterator<int> iterator(stack);

	cout << "\n\n    Итератор: ";
	for (iterator.begin(); !iterator.end(); ++iterator)
		cout << setw(5) << *iterator;
	cout << "\n";

	// строка 	*iterator = 1000;  вызывает ошибку компиляции, что и требуется
	// for (iterator.begin(); !iterator.end(); ++iterator)
	// 	   *iterator = 1000;
	
	cout << "\n\n    Итератор: ";
	for (iterator.begin(); !iterator.end(); ++iterator)
		cout << setw(5) << *iterator;
	cout << "\n";

}


void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "К сведению", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  Нажмите любую клавишу для продолжения...");

	cout << pos(0, 5) << msg << endlm(4);
} // App::showMsg

