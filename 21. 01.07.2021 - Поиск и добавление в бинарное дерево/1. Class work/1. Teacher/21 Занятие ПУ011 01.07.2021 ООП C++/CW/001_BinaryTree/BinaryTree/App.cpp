#include "pch.h"
#include "Utils.h"
#include "App.h"

// добавить узел или значение в дерево
void App::demoAdd()
{
	showNavBarMessage(hintColor, "  Добавить узел или значение в дерево");

	cout << "\n\n\n\n";
	const int N = 5;
	for (int i = 0; i < N; i++) {
		int data = getRand(-10, 10);
		cout << "    Добавляем: " << setw(5) << data;

		intTree_.add(data);
		cout << ", добавлено. Дерево int: " << intTree_ << "\n";
	} // for i

	cout << "\n\n    Дерево intTree: " << intTree_ << endlm(3);
} // App::demoAdd


// показать данные дерева
void App::demoShowTree()
{
	showNavBarMessage(hintColor, "  Показать данные дерева");
	cout << "\n\n\n\n    Дерево intTree: " << intTree_ << endlm(3);

} // App::demoShowTree


// поиск в дереве
void App::demoFindTree()
{
	showNavBarMessage(hintColor, "  Поиск в дереве");
	cout << "\n\n\n    Дерево intTree: " << intTree_ << endlm(3);

	const int N = 5;
	for (int i = 0; i < N; i++) {
		int data = getRand(-10, 10);
		cout << "    Ищем: " << setw(3) << data << ", ";
		if (intTree_.find(data) != nullptr)
			cout << color(infoColor) << " нашли     :) " << color(mainColor);
		else
			cout << " не нашли  :(";
		cout << "\n";
	} // for i

} // App::demoFindTree


// вывод однострочного сообщения
void App::showMsg(const char* msg) const
{
	// MessageBoxA(nullptr, msg, "К сведению", MB_ICONINFORMATION | MB_OK);

	showNavBarMessage(hintColor, "  Нажмите любую клавишу для продолжения...");

	cout << pos(0, 5) << msg << endlm(4);
} // App::showMsg

