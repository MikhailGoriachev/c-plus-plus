#include "pch.h"
#include "Utils.h"
#include "App.h"

#include "Stack.h"
#include "StackTiangle.h"

void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "К сведению", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  Нажмите любую клавишу для продолжения...");

	cout << "\n\n\n\n" << msg << "\n\n\n\n";
} // App::showMsg


// работа с объектом класса Stack
void App::checkStack()
{
	Stack stack;

	cout << "\n\n\n";
	stack.push(101);
	stack.push(-101);
	stack.push(99);
	cout << "    Стек: " << stack << "\n";

	int data[] = { 32, 7, 8, -1 };
	stack.pushAll(data, sizeof(data) / sizeof(int));
	cout << "    Стек: " << stack << "\n\n";

	int t = stack.peek();
	cout << "    peek: " << setw(8) << t << " | " << stack << "\n\n";

	while(!stack.isEmpty()) {
		int t = stack.pop();
		cout << "     pop: " << setw(8) << t << " | " << stack << "\n";
	} // while
	cout << "        :          | " << stack << "\n";

	cout << "\n    Очистка стека:\n";
	stack.pushAll(data, sizeof(data) / sizeof(int));
	cout << "    Стек: " << stack << "\n\n";
	stack.clear();
	cout << "    Стек: " << stack << "\n";
	
} // App::checkStack


// работа с объектом класса StackTriangle
void App::checkStackTriangle()
{
	StackTriangle stack;

	// Объект с массивом треугольников
	const int N_TRIANGLES = 6;
	Triangle triangles[N_TRIANGLES] = {
		Triangle(3, 4, 5),
		Triangle(12, "DEF"),
		Triangle(7, 8, 5, "ZXE"),
		Triangle(8, "WEB"),
		Triangle(3, "BRE"),
		Triangle(5, 8, 6, "JKL")
	};
	
	cout << "\n\n\n";
	stack.push(Triangle(8, "BYE"));
	stack.push(Triangle(18, "DRY"));
	stack.push(Triangle(21, "EYS"));
	cout << "    Стек:\n" << stack << "\n";

	stack.pushAll(triangles, N_TRIANGLES);
	cout << "    Стек:\n" << stack << "\n\n";

	Triangle t = stack.peek();
	cout << "    peek: " << t << "\n-----------" << stack << "\n\n";

	while (!stack.isEmpty()) {
		Triangle t = stack.pop();
		cout << "     pop: " << t << "\n" << stack << "\n===================\n";
	} // while
	cout << "        :          | " << stack << "\n";

	cout << "\n    Очистка стека:\n";
	stack.pushAll(triangles, N_TRIANGLES);
	cout << "    Стек:\n" << stack << "\n\n";
	stack.clear();
	cout << "    Стек:\n" << stack << "\n";

} // App::checkStack


// Пример решения задачи на стеках int
// Даны два непустsх стека int. Переместить из 1го стека во 2й
// числа до первого нечетного. Если в 1м стеке нет нечетных чисел,
// переместить все числа из 1го стека во 2й
void App::task()
{
	// массивы для заполнения стеков
	int data1[] = {2, 5, 4, 0, 6, 8};
	int data2[] = {11, 22, 33, 44};

	// стеки по заданию
	Stack stack1(data1, sizeof(data1)/sizeof(int));
	Stack stack2(data2, sizeof(data2) / sizeof(int));

	cout<< "    Стек1: " << stack1 << "\n"
		<< "    Стек2: " << stack2 << "\n"
		<< "\n=================================================\n";

	// перемещение данных из 1го стека во 2й
	// до первого нечетного числа в стеке или до опустошения 1го стека 
	while ((stack1.peek() & 1) == 0 && !stack1.isEmpty()) {
		cout<<"\n"
		    << "    Стек1: " << stack1 << "\n"
			<< "    Стек2: " << stack2 << "\n";

		int t = stack1.pop();
		stack2.push(t);
		// stack2.push(stack1.pop());
	} // while

	cout<< "\n=================================================\n"
	    << "    Стек1: " << stack1 << "\n"
		<< "    Стек2: " << stack2 << "\n";
	
} // App::task()
