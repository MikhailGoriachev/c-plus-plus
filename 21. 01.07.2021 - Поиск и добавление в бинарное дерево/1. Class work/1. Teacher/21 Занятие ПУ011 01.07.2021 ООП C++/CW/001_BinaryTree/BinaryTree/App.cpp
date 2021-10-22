#include "pch.h"
#include "Utils.h"
#include "App.h"

// �������� ���� ��� �������� � ������
void App::demoAdd()
{
	showNavBarMessage(hintColor, "  �������� ���� ��� �������� � ������");

	cout << "\n\n\n\n";
	const int N = 5;
	for (int i = 0; i < N; i++) {
		int data = getRand(-10, 10);
		cout << "    ���������: " << setw(5) << data;

		intTree_.add(data);
		cout << ", ���������. ������ int: " << intTree_ << "\n";
	} // for i

	cout << "\n\n    ������ intTree: " << intTree_ << endlm(3);
} // App::demoAdd


// �������� ������ ������
void App::demoShowTree()
{
	showNavBarMessage(hintColor, "  �������� ������ ������");
	cout << "\n\n\n\n    ������ intTree: " << intTree_ << endlm(3);

} // App::demoShowTree


// ����� � ������
void App::demoFindTree()
{
	showNavBarMessage(hintColor, "  ����� � ������");
	cout << "\n\n\n    ������ intTree: " << intTree_ << endlm(3);

	const int N = 5;
	for (int i = 0; i < N; i++) {
		int data = getRand(-10, 10);
		cout << "    ����: " << setw(3) << data << ", ";
		if (intTree_.find(data) != nullptr)
			cout << color(infoColor) << " �����     :) " << color(mainColor);
		else
			cout << " �� �����  :(";
		cout << "\n";
	} // for i

} // App::demoFindTree


// ����� ������������� ���������
void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "� ��������", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  ������� ����� ������� ��� �����������...");

	cout << pos(0, 5) << msg << endlm(4);
} // App::showMsg

