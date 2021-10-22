#include "App.h"
#include "Subscriber.h"
#include "Utils.h"

/*
	������ 1. ������� ����� Pair (���� ������������ �����), ���������� ��������� �
		����� ���������� ������������ �����. ������� ����������� �� ������ Pair ����� 
		TRectangle (�������������) � ������ � ���������. ���������� ������ ���������� 
		��������� � �������. ������������������ ������ ������� �������� � ������������ 
		������� �� ����� � ������� �������������� (�� ����� 5 ���������).
	
	������ 2. ������� ����� Triad (��� ������������ �����), ���������� ��������� � 
		����� ���������� ����� �����. ������� ����������� �� ������ Triad����� Triangle 
		(�����������) � ������ � ���������. ���������� ������ ���������� ��������� � 
		�������. ������������������ ������ ��������������� � ������������ ������� �� 
		������ � ���������� ������ �������������� (�� ����� 5 ���������).
	
	������ 3. � �������������� ��������� ������ ������ ����������� ��������� 
		����������� � ��������� �������� �������. ��������� ���������� ��������� � �� 
		�������.
		������� ��������� ������ ������� �������, ��� � �������� �����������, ����������
		������ �����, ������� �������� � �2, ���������� ������, ���� ���������� �� ���� 
		(����, �����, �������� Date). ���������� � ��������� ����������� �� �������. 
		����������� ������������� ��������:
			�	����� � ��������� �� ������� � ������� ������ ���������� �������, ���������
			������������� ������������
			�	������ � �������� ���� ���� ��������� ��������� (� ����� ������ ����� 
			����������� �� ��������).
			�	��������� ������ ��������� � �������� ������ ������, ������� ������ ����� 
			������ �� �������� � �������, �������� �����������
	
	������ 4. ����������� ����� ��� ������������� �������� ���������� ������� � ������ 
		��� ��������:
			�	������� � ���������
			�	����������� ������
			�	������� ���������� (� �������) �� ��������� �����.
		����������� ����� ��� ������������� ���������� ������� � ������ ��� �������� 
		�������� ���������� ������� (��� ������� � ��� �������� �������), ������� ����� �� 
		������ ��������� ��������, ��������� ��������� � ���� ��������� ������ ������. ������
		��� ����� �������� ���������� ����� ��������.  
		������� ������ ���������� �������, ��������� ��������� �� ������� (�� ����� 10 �������),
		����������� ����� �� ����������� ������, ����� ���� � ������ � ������� ����������� 
		���������� �������, ������� ������ ��������� �� �������� ���������� �������.
*/

#pragma region ������� 1. ������������� 

/*
	������ 1. ������� ����� Pair (���� ������������ �����), ���������� ��������� �
		����� ���������� ������������ �����. ������� ����������� �� ������ Pair �����
		TRectangle (�������������) � ������ � ���������. ���������� ������ ����������
		��������� � �������. ������������������ ������ ������� �������� � ������������
		������� �� ����� � ������� �������������� (�� ����� 5 ���������).
*/

// ������� 1. �������������
void App::task1()
{
	cls();

	showNavBarMessage(hintColor, "������� 1. �������������");

	// ����� ��������������� � �����, �� ���������� � ������� � ���� ������� 
	cputs("\n\n                        ����\n", GREEN_ON_BLACK);

	showTableTRectangle(stackRectangle_);

	// ����� ��������������� � �������, �� ���������� � ������� � ���� ������� 
	cputs("\n\n                       �������\n", GREEN_ON_BLACK);

	showTableTRectangle(queueRectangle_);

	cout << "\n\n\n";

	getKey();
}

// ����� ���������������, �� ���������� � ������� � ���� ������� �� ���������
void App::showTableTRectangle(Stack<TRectangle>& stackTRectangle)
{
	Stack<TRectangle>::Iterator iterator(stackTRectangle);

	cout << "\t+������������+������������+������������+������������+\n"
		<< "\t| ������� A  | ������� B  |  ��������  |   �������  |\n"
		<< "\t+������������+������������+������������+������������+\n";

	// ���� �� ���������
	short cl = getColor();

	cout << fixed;
	cout.precision(2);

	// ����� ��������������� �� ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// ������� �������� ���������
		TRectangle tmp = *iterator;

		cout << right << "\t| " << color(YELLOW_ON_BLACK) << setw(10) << tmp.getA() << color(cl) << " | "
			<< color(YELLOW_ON_BLACK) << setw(10) << tmp.getB() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.perimeter() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.area() << color(cl) << " |\n";
	}

	cout << left;

	cout << "\t+������������+������������+������������+������������+\n";
}

// ����� ���������������, �� ���������� � ������� � ���� ������� �� ���������
void App::showTableTRectangle(Queue<TRectangle>& queueTRectangle)
{
	Queue<TRectangle>::Iterator<TRectangle> iterator(queueTRectangle);

	cout << "\t+������������+������������+������������+������������+\n"
		<< "\t| ������� A  | ������� B  |  ��������  |   �������  |\n"
		<< "\t+������������+������������+������������+������������+\n";

	// ���� �� ���������
	short cl = getColor();

	cout << fixed;
	cout.precision(2);

	// ����� ��������������� �� ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// ������� �������� ���������
		TRectangle tmp = *iterator;

		cout << right << "\t| " << color(YELLOW_ON_BLACK) << setw(10) << tmp.getA() << color(cl) << " | "
			<< color(YELLOW_ON_BLACK) << setw(10) << tmp.getB() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.perimeter() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.area() << color(cl) << " |\n";
	}

	cout << left;

	cout << "\t+������������+������������+������������+������������+\n";

}

#pragma endregion 

#pragma region ������� 2. �����������

/*
	������ 2. ������� ����� Triad (��� ������������ �����), ���������� ��������� �
		����� ���������� ����� �����. ������� ����������� �� ������ Triad ����� Triangle
		(�����������) � ������ � ���������. ���������� ������ ���������� ��������� �
		�������. ������������������ ������ ��������������� � ������������ ������� ��
		������ � ���������� ������ �������������� (�� ����� 5 ���������).
*/

// ������� 2. �����������
void App::task2()
{
	cls();

	showNavBarMessage(hintColor, "������� 1. �������������");

	// ����� ��������������� � �����, �� ���������� � ������� � ���� ������� 
	cputs("\n\n                        ������\n", GREEN_ON_BLACK);

	showTableTriangle(listTriangle_);

	// ����� ��������������� � �������, �� ���������� � ������� � ���� ������� 
	cputs("\n\n                  ���������� ������\n", GREEN_ON_BLACK);

	showTableTriangle(dblListTriangle_);

	cout << "\n\n\n";

	getKey();
}

// ����� ���������������, �� ���������� � ������� � ���� ������� �� ���������
void App::showTableTriangle(List<Triangle>& listTriangle)
{
	List<Triangle>::Iterator<Triangle> iterator(listTriangle);

	cout << "\t+������������+������������+������������+������������+������������+\n"
		<< "\t| ������� A  | ������� B  | ������� C  |  ��������  |   �������  |\n"
		<< "\t+������������+������������+������������+������������+������������+\n";

	// ���� �� ���������
	short cl = getColor();

	cout << fixed;
	cout.precision(2);

	// ����� ��������������� �� ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// ������� �������� ���������
		Triangle tmp = *iterator;

		cout << right << "\t| " << color(YELLOW_ON_BLACK) << setw(10) << tmp.getA() << color(cl) << " | "
			<< color(YELLOW_ON_BLACK) << setw(10) << tmp.getB() << color(cl) << " | "
			<< color(YELLOW_ON_BLACK) << setw(10) << tmp.getC() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.perimeter() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.area() << color(cl) << " |\n";
	}

	cout << left;

	cout << "\t+������������+������������+������������+������������+������������+\n";
}

// ����� ���������������, �� ���������� � ������� � ���� ������� �� ���������
void App::showTableTriangle(DblList<Triangle>& dbllistTriangle)
{
	DblList<Triangle>::Iterator<Triangle> iterator(dbllistTriangle);

	cout << "\t+������������+������������+������������+������������+������������+\n"
		<< "\t| ������� A  | ������� B  | ������� C  |  ��������  |   �������  |\n"
		<< "\t+������������+������������+������������+������������+������������+\n";

	// ���� �� ���������
	short cl = getColor();

	cout << fixed;
	cout.precision(2);

	// ����� ��������������� �� ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// ������� �������� ���������
		Triangle tmp = *iterator;

		cout << right << "\t| " << color(YELLOW_ON_BLACK) << setw(10) << tmp.getA() << color(cl) << " | "
			<< color(YELLOW_ON_BLACK) << setw(10) << tmp.getB() << color(cl) << " | "
			<< color(YELLOW_ON_BLACK) << setw(10) << tmp.getC() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.perimeter() << color(cl) << " | "
			<< color(GREEN_ON_BLACK) << setw(10) << tmp.area() << color(cl) << " |\n";
	}

	cout << left;

	cout << "\t+������������+������������+������������+������������+������������+\n";

}

#pragma endregion 

#pragma region ������� 3. ��������� ����������� � ��������� �������� �������
/*
	������ 3. � �������������� ��������� ������ ������ ����������� ���������
		����������� � ��������� �������� �������. ��������� ���������� ��������� � ��
		�������.
		������� ��������� ������ ������� �������, ��� � �������� �����������, ����������
		������ �����, ������� �������� � �2, ���������� ������, ���� ���������� �� ����
		(����, �����, �������� Date). ���������� � ��������� ����������� �� �������.
		����������� ������������� ��������:
			�	����� � ��������� �� ������� � ������� ������ ���������� �������, ���������
			������������� ������������
			�	������ � �������� ���� ���� ��������� ��������� (� ����� ������ �����
			����������� �� ��������).
			�	��������� ������ ��������� � �������� ������ ������, ������� ������ �����
			������ �� �������� � �������, �������� �����������
*/

// ������� 3. ��������� ����������� � ��������� �������� �������
void App::task3()
{
	init(L"������� 3. ��������� ����������� � ��������� �������� �������");

	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ����� � ��������� �� �������
		CMD_SEARCH_SURNAME,
		// ������ � �������� ���� ���� ��������� ���������
		CMD_TASK_TWO,
	};

	// ���������� ������� ����
	const int N_MENU = 3;

	MenuItem items[N_MENU] = {
		MenuItem("����� � ��������� �� �������", CMD_SEARCH_SURNAME),
		MenuItem("������ � �������� ���� ���� ��������� ���������", CMD_TASK_TWO),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� 1. ��������� ����������� � ��������� �������� �������", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// ����� � ��������� �� �������
			case CMD_SEARCH_SURNAME:
				app.searchSurname();
				break;
				// ������� 2
			case CMD_TASK_TWO:
				app.writeFormBinFile();
				break;
			} // switch (cmd)
		}
		catch (exception& ex) {
			oss.str("");  // ������� ������ - ������ ������
			oss << "\n\t" << ex.what() << "\n";

			// ����� ������ � ���������� �� ������ � �����
			cputs(oss.str().c_str(), errColor);

			getKey();
		} // try-catch
	}
} // main

// ����� � ��������� �� �������
void App::searchSurname()
{
	cls();

	// ����� ���������
	showNavBarMessage(hintColor, "����� � ��������� �� �������");

	cputs("     �����������������������������������������������������������������������������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� ��������� ������
	printBinaryTreeFormColor(forms_.getRoot());

	// ������� ��� ������
	char* surname = new char[Form::SURNAME_MAX_SIZE + 1];
	
	// ������� ����
	short cl = getColor();

	// ���� ������� ��� ������
	showInputLine("\n\n\n     ������� ������� ��� ������: ", Form::SURNAME_MAX_SIZE - 20, WHITE_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(surname, Form::SURNAME_MAX_SIZE);

	// ���������� �������
	setCursorVisible(false);

	// ��������� ����� �� ���������
	setColor(cl);

	// ��������� ������ Form ��� ������
	Form tmp;
	tmp.setSurname(surname);

	delete[] surname;

	// ����� ����������
	cputs("     �������������������������������������������� ��������� ������ ���������������������������������������������������\n", YELLOW_ON_BLACK);

	// ������������ Form
	BinaryTree<Form>::NodeTree<Form>* node = forms_.find(tmp);

	// ��������� �������
	cout << tmp.showHead();

	// ���� ������ �� ������
	if (node == nullptr)
		cout << "\t|                                           �� �������                                                    |\n";
	else
	{

		tmp = node->getData();

		// ����� �������� 
		tmp.showColor();
	}

	cout << tmp.showLine();

	getKey();
}

// ������ � �������� ���� ���� ��������� ���������
void App::writeFormBinFile()
{
	cls();

	// ����� ���������
	showNavBarMessage(hintColor, "������ � �������� ���� ���� ��������� ���������");

	// �������� ����� 
	const char* nameFile = "save.bin";

	cputs("\n    ��������������������������������������������� �������� ������ ����������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� ��������� ������
	printBinaryTreeFormColor(forms_.getRoot());

	// ����� ����� �����
	cputs("    ���� ��� ����������: ", GRAY_ON_BLACK);
	cputs(nameFile, GREEN_ON_BLACK);
	cout << "\n";

	// �������� ����� � ������ �������� ������
	FILE* file = fopen(nameFile, "wb");

	// ���� ���� ������ ��������� 
	if (file == nullptr)
	{
		throw exception("App: �� ������� ������� ����");

	}

	// ���� ���� ������ �������
	// ������ � ����
	forms_.write(file);

	// �������� �����
	fclose(file);

	cputs("    ���� �������\n", GREEN_ON_BLACK);


	cputs("\n    ��������������������������������������������� ����� ���������� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� ������ �������� ������
	BinaryTree<Form> newTree;

	// ����� ��������� ������
	printBinaryTreeFormColor(newTree.getRoot());

	// �������� �� �����
	cputs("\n    �������������������������������������������� �������� �� ����� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// �������� ����� � ������ ��������� ������
	file = fopen(nameFile, "rb");

	// ���� ���� ������ ��������� 
	if (file == nullptr)
	{
		
		throw exception("App: �� ������� ������� ����");

	}
	// ���� ���� ������ �������
	// ������ �� �����
	newTree.read(file);

	// �������� �����
	fclose(file);

	cputs("\n    ���������������������������������������������� ����� �������� ����������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������
	printBinaryTreeFormColorBack(newTree.getRoot());

	getKey();

}

// ����� ����� ������ ��� ������ � ����� �������� Form
void App::showFormColor(BinaryTree<Form>::NodeTree<Form>* node, short cl, int& i)
{
	// ���� ������� ���� �������� nullptr
	if (node == nullptr) return;

	// ����������� �� ������ ���������
	showFormColor(node->getLeft(), cl, i);

	// ������ ��������  �����
	node->getData().showColor(i++);

	// ����������� �� ������� ���������
	showFormColor(node->getRight(), cl, i);
}

// ����� ��������� ������ � ��������� Form � �����
void App::printBinaryTreeFormColor(BinaryTree<Form>::NodeTree<Form>* node)
{
	cout << Form::showHead();

	// ���� � ������ ��� ������
	if (node == nullptr)
		cputs("\t|                                               ��� ������                                                |\n", RED_ON_BLACK);

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		cout << fixed;
		cout.precision(2);

		// ����� ������ � �����
		showFormColor(node, cl, i);
	}

	cout << Form::showLine();

}

// ����� ����� ������ ��� ������ � ����� �������� Form
void App::showFormColorBack(BinaryTree<Form>::NodeTree<Form>* node, short cl, int& i)
{
	// ���� ������� ���� �������� nullptr
	if (node == nullptr) return;

	// ����������� �� ������ ���������
	showFormColorBack(node->getRight(), cl, i);

	// ������ ��������  �����
	node->getData().showColor(i++);

	// ����������� �� ������� ���������
	showFormColorBack(node->getLeft(), cl, i);
}

// ����� ��������� ������ � ��������� Form � �����
void App::printBinaryTreeFormColorBack(BinaryTree<Form>::NodeTree<Form>* node)
{
	cout << Form::showHead();

	// ���� � ������ ��� ������
	if (node == nullptr)
		cputs("\t|                                               ��� ������                                                |\n", RED_ON_BLACK);

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		cout << fixed;
		cout.precision(2);

		// ����� ������ � �����
		showFormColorBack(node, cl, i);
	}

	cout << Form::showLine();

}



#pragma endregion

#pragma region ������� 4. ���������� �������

/*
	������ 4. ����������� ����� ��� ������������� �������� ���������� ������� � ������
		��� ��������:
			�	������� � ���������
			�	����������� ������
			�	������� ���������� (� �������) �� ��������� �����.
		����������� ����� ��� ������������� ���������� ������� � ������ ��� ��������
		�������� ���������� ������� (��� ������� � ��� �������� �������), ������� ����� ��
		������ ��������� ��������, ��������� ��������� � ���� ��������� ������ ������. ������
		��� ����� �������� ���������� ����� ��������.
		������� ������ ���������� �������, ��������� ��������� �� ������� (�� ����� 10 �������),
		����������� ����� �� ����������� ������, ����� ���� � ������ � ������� �����������
		���������� �������, ������� ������ ��������� �� �������� ���������� �������.
*/

// ������� 4. ���������� �������
void App::task4()
{
	init(L"������� 4. ���������� �������");

	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ����� ������ ���������� ������� � �������� �������
		CMD_OUT_STATION,
		// ����� �� ����������� ������
		CMD_TASK_ONE,
		// ����� ���� � ������ � ������� ����������� ���������� �������
		CMD_TASK_TWO,
	}; // Commands

	// ���������� ������� ����
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("����� ������ ���������� ������� � �������� �������", CMD_OUT_STATION),
		MenuItem("����� �� ����������� ������", CMD_TASK_ONE),
		MenuItem("����� ���� � ������ � ������� ����������� ���������� �������", CMD_TASK_TWO),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	}; // MenuItem items

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� 4. ���������� �������", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// ����� ������ ���������� ������� � �������� �������
			case CMD_OUT_STATION:
				app.showStation();
				break;
				// ����� �� ����������� ������
			case CMD_TASK_ONE:
				app.searchNumber();
				break;
				// ����� ���� � ������ � ������� ����������� ���������� �������
			case CMD_TASK_TWO:
				app.showPay();
				break;
			} // switch (cmd)
		}
		catch (exception& ex) {
			oss.str("");  // ������� ������ - ������ ������
			oss << "\n\t" << ex.what() << "\n";

			// ����� ������ � ���������� �� ������ � �����
			cputs(oss.str().c_str(), errColor);

			getKey();
		} // try-catch
	} // while (true)
} // App::task2

// ����� �� ����������� ������
void App::searchNumber()
{
	cls();

	// ����� ���������
	showNavBarMessage(hintColor, "����� �������� �� ����������� ������");

	cputs("     �����������������������������������������������������������������������������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� ��������� ������
	station_.showTable();

	// ������� ��� ������
	char* number = new char[Subscriber::NUMBER_SIZE + 2];

	// ������� ����
	short cl = getColor();

	// ���� ������� ��� ������
	showInputLine("\n\n\n     ������� ����� ��� ������: ", Subscriber::NUMBER_SIZE + 2, WHITE_ON_CYAN);
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(number, Subscriber::NUMBER_SIZE + 1);

	// ���������� �������
	setCursorVisible(false);

	// ��������� ����� �� ���������
	setColor(cl);

	// ��������� ������ Form ��� ������
	Subscriber tmp;

	// ����� ����������
	cputs("     �������������������������������������������� ��������� ������ ���������������������������������������������������\n", YELLOW_ON_BLACK);

	// ������������ Form
	BinaryTree<Subscriber>::NodeTree<Subscriber>*node = station_.find(number);

	// ��������� �������
	tmp.showHead();

	// ���� ������ �� ������
	if (node == nullptr)
		tmp.showEmpty();
	else
	{
		tmp = node->getData();

		// ����� �������� 
		tmp.showElem();
	}

	tmp.showLine();

	delete[] number;

	getKey();

}

// ����� ������ ���������� ������� � �������� �������
void App::showStation()
{
	cls();

	// ����� ���������
	showNavBarMessage(hintColor, "������ ���������� ������� � �������� �������");

	cputs("     �����������������������������������������������������������������������������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� ��������� ������
	station_.showTableBack();

	getKey();

}

// ����� ���� � ������ � ������� ����������� ���������� �������
void App::showPay()
{
	cls();

	showNavBarMessage(hintColor, "����� � ������ ���������� �������");
	
	// ����� ����������� �����
	station_.showTablePrice();

	getKey();
}

#pragma endregion