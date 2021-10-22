#include "pch.h"
#include "Utils.h"
#include "List.h"
#include "App.h"

#include "Stack.h"

// �������� ������ ������� ������
void App::checkListMethods()
{
	showNavBarMessage(hintColor, "  ������ � ������� List<char>");
	cout << "\n\n\n\n    ������ char: " << list_ << "\n\n\n";

	list_.add('~');
	cout << "    � ����� �������� ~\n"
		<< "    ������ char: " << list_ << "\n\n";

	list_.insert(0, '>');
	cout << "    � ������ �������� >\n"
		<< "    ������ char: " << list_ << "\n\n";

	list_.removeAt(0);
	cout << "    �� ������ ������� >\n"
		<< "    ������ char: " << list_ << "\n\n";
} // App::checkListMethods

// �������� ������ ���������
void App::checkListIterator()
{
	showNavBarMessage(hintColor, "  ������ � ���������� ������ List");
	cout << "\n\n\n\n\n    ������ char: " << list_ << "\n";

	// �������� ������ � ����������
	// ������� ��������
	// for (���������� �������� � ������ ������; �� ��������� ����� ������?; ������� � ���������� ��������) {
	// 	   cout << �������� ������� �� ��������� << " ";
	// } // for p

	cout << "    ��������   : ";
	// ������� ��������
	List<char>::Iterator<char> iterator(list_);

	// �������� �� ������, ������ ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
		cout << *iterator << " ==> ";
	cout << "X\n";

	// �������� �� ������, ������ ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
		// *iterator = char(getRand('�', '�'));
		// *iterator = (char)getRand('�', '�');
		*iterator = static_cast<char>(getRand('�', '�'));

	cout << "    ��������   : ";
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
		cout << *iterator << " ==> ";
	cout << "X\n";
} // checkListIterator

// �������� ������ ��������� �� ����� Stack
void App::checkStackIterator()
{
	showNavBarMessage(hintColor, "  ������ � ���������� ������ Stack");
	int arr[] = { 20, 30, 40, 50, 60 };
	Stack<int> stack(arr, 5);
	cout << "\n\n\n\n    ����    : " << stack << "\n";
	
	Stack<int>::Iterator<int> iterator(stack);

	cout << "\n\n    ��������: ";
	for (iterator.begin(); !iterator.end(); ++iterator)
		cout << setw(5) << *iterator;
	cout << "\n";

	// ������ 	*iterator = 1000;  �������� ������ ����������, ��� � ���������
	// for (iterator.begin(); !iterator.end(); ++iterator)
	// 	   *iterator = 1000;
	
	cout << "\n\n    ��������: ";
	for (iterator.begin(); !iterator.end(); ++iterator)
		cout << setw(5) << *iterator;
	cout << "\n";

}


void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "� ��������", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  ������� ����� ������� ��� �����������...");

	cout << pos(0, 5) << msg << endlm(4);
} // App::showMsg

