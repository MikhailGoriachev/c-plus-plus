#include "pch.h"
#include "Utils.h"
#include "App.h"

#include "Stack.h"
#include "StackTiangle.h"

void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "� ��������", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  ������� ����� ������� ��� �����������...");

	cout << "\n\n\n\n" << msg << "\n\n\n\n";
} // App::showMsg


// ������ � �������� ������ Stack
void App::checkStack()
{
	Stack stack;

	cout << "\n\n\n";
	stack.push(101);
	stack.push(-101);
	stack.push(99);
	cout << "    ����: " << stack << "\n";

	int data[] = { 32, 7, 8, -1 };
	stack.pushAll(data, sizeof(data) / sizeof(int));
	cout << "    ����: " << stack << "\n\n";

	int t = stack.peek();
	cout << "    peek: " << setw(8) << t << " | " << stack << "\n\n";

	while(!stack.isEmpty()) {
		int t = stack.pop();
		cout << "     pop: " << setw(8) << t << " | " << stack << "\n";
	} // while
	cout << "        :          | " << stack << "\n";

	cout << "\n    ������� �����:\n";
	stack.pushAll(data, sizeof(data) / sizeof(int));
	cout << "    ����: " << stack << "\n\n";
	stack.clear();
	cout << "    ����: " << stack << "\n";
	
} // App::checkStack


// ������ � �������� ������ StackTriangle
void App::checkStackTriangle()
{
	StackTriangle stack;

	// ������ � �������� �������������
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
	cout << "    ����:\n" << stack << "\n";

	stack.pushAll(triangles, N_TRIANGLES);
	cout << "    ����:\n" << stack << "\n\n";

	Triangle t = stack.peek();
	cout << "    peek: " << t << "\n-----------" << stack << "\n\n";

	while (!stack.isEmpty()) {
		Triangle t = stack.pop();
		cout << "     pop: " << t << "\n" << stack << "\n===================\n";
	} // while
	cout << "        :          | " << stack << "\n";

	cout << "\n    ������� �����:\n";
	stack.pushAll(triangles, N_TRIANGLES);
	cout << "    ����:\n" << stack << "\n\n";
	stack.clear();
	cout << "    ����:\n" << stack << "\n";

} // App::checkStack


// ������ ������� ������ �� ������ int
// ���� ��� ������s� ����� int. ����������� �� 1�� ����� �� 2�
// ����� �� ������� ���������. ���� � 1� ����� ��� �������� �����,
// ����������� ��� ����� �� 1�� ����� �� 2�
void App::task()
{
	// ������� ��� ���������� ������
	int data1[] = {2, 5, 4, 0, 6, 8};
	int data2[] = {11, 22, 33, 44};

	// ����� �� �������
	Stack stack1(data1, sizeof(data1)/sizeof(int));
	Stack stack2(data2, sizeof(data2) / sizeof(int));

	cout<< "    ����1: " << stack1 << "\n"
		<< "    ����2: " << stack2 << "\n"
		<< "\n=================================================\n";

	// ����������� ������ �� 1�� ����� �� 2�
	// �� ������� ��������� ����� � ����� ��� �� ����������� 1�� ����� 
	while ((stack1.peek() & 1) == 0 && !stack1.isEmpty()) {
		cout<<"\n"
		    << "    ����1: " << stack1 << "\n"
			<< "    ����2: " << stack2 << "\n";

		int t = stack1.pop();
		stack2.push(t);
		// stack2.push(stack1.pop());
	} // while

	cout<< "\n=================================================\n"
	    << "    ����1: " << stack1 << "\n"
		<< "    ����2: " << stack2 << "\n";
	
} // App::task()
