// Знакомство с динамическимим структурами данных
// Стек - stack на базе статического массива

#include "pch.h"
#include "Stack.h"
#include "Utils.h"

int main()
{
    init(L"Занятие 10.06.2021 - стек, доступ LIFO");

	// для вывода в строку средствами C++
	ostringstream oss;

	try {
		// экземпляр класса 
		Stack stack;

		// добавить элементы в стек
		cout << "Данные: ";
		for (int i = 101; i < 111; ++i) {
			cout << setw(5) << i;
			stack.push(i);
		}
		cout << "\n";
		
		cout << "Стек  : " << stack << "\n";

		// проверка операции pop()
		cout << "pop() : ";
		while (!stack.isEmpty())
			cout << setw(5) << stack.pop();
		cout << "\n\n";

	

		// массив для инициализации
		int data[] {1, 2, 3, 4, 5};
		stack.pushAll(data, sizeof(data) / sizeof(data[0]));
		cout << "Стек: " << stack << "\n";

		stack.clear();
		cout << "Стек: " << stack << "\n";
		
	} catch (exception &ex) {
		oss.str("");  // очистка строки - буфера вывода
		oss << "\n\t" << ex.what() << "\n";
		
		// вывод строки с сообщением об ошибке в цвете
		cputs(oss.str().c_str(), errColor);
	} // try-catch

	gotoXY(0, 23);
	getKey();
	
} // main
