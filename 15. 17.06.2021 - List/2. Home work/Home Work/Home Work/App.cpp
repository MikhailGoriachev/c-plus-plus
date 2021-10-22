#include "App.h"


/*
	������� 1. ���������� ����� List ������������ ������ ����� �����.����������� �������� �����. 
		������������ ������������������ � ���������� ��������� ��������:

		�	insert(position, payload) � ��������� ������� � ������ ����� �������� position
			(��������� ������� ���������� � 0)
		�	get(postion)� ���������� �������� �������� ������ � �������� ������� (���������
			������� ���������� � 0)
		�	put(position, value) � ���������� �������� value � �������� ������� ������
			(��������� ������� ���������� � 0)
		�	����������� �������� [] ��� ������� � ��������� ������ �� ��������� �������� 
			������� position(��������� ������� ���������� � 0)
		�	addAll(data[], n)���������� ������� � ����� ������
		�	insertAll(position, data[], n)������� ������� data[] ����� �������� position
			(��������� ������� ���������� � 0)

	������� 2. �� ���� ������� List � Node ������������ ������ ListPlane � NodePlanec 
		��� �������� ������ �������� ������ Plane. ����������������� ������ ������� ������ ListPlane.

*/


#pragma region ������� 1

/*
	������� 1. ���������� ����� List ������������ ������ ����� �����.����������� �������� �����.
		������������ ������������������ � ���������� ��������� ��������:

		�	insert(position, payload) � ��������� ������� � ������ ����� �������� position
			(��������� ������� ���������� � 0)
		�	get(postion)� ���������� �������� �������� ������ � �������� ������� (���������
			������� ���������� � 0)
		�	put(position, value) � ���������� �������� value � �������� ������� ������
			(��������� ������� ���������� � 0)
		�	����������� �������� [] ��� ������� � ��������� ������ �� ��������� ��������
			������� position(��������� ������� ���������� � 0)
		�	addAll(data[], n)���������� ������� � ����� ������
		�	insertAll(position, data[], n)������� ������� data[] ����� �������� position
			(��������� ������� ���������� � 0)
*/

// ���� ������� 1
void App::task1()
{
	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ������� �������� � ������ ����� �������� 
		CMD_INSERT,
		// ����������� �������� �������� ������ �� �������� �������
		CMD_GET,
		// ������ �������� � �������� ������� ������
		CMD_PUT,
		// ���������� ������� � ����� ������
		CMD_ADD_ALL,
		// ������� ������� ����� �������� 
		CMD_INSERT_ALL
	};

	// ���������� ������� ����
	const int N_MENU = 6;

	MenuItem items[N_MENU] = {
		MenuItem("������� �������� � ������ ����� ��������", CMD_INSERT),
		MenuItem("����������� �������� �������� ������ �� �������� �������", CMD_GET),
		MenuItem("������ �������� � �������� ������� ������", CMD_PUT),
		MenuItem("���������� ������� � ����� ������", CMD_ADD_ALL),
		MenuItem("������� ������� ����� �������� ", CMD_INSERT_ALL),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� 1", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
			// ������� �������� � ������ ����� �������� 
			case CMD_INSERT:
				app.task1Insert();
				break;

			// ����������� �������� �������� ������ �� �������� �������
			case CMD_GET:
				app.task1Get();
				break;		

			// ������ �������� � �������� ������� ������
			case CMD_PUT:
				app.task1Put();
				break;		

			// ���������� ������� � ����� ������
			case CMD_ADD_ALL:
				app.task1AddAll();
				break;

			// ������� ������� ����� �������� 
			case CMD_INSERT_ALL:
				app.task1InsertAll();
				break;
			}
		}
		catch (exception& ex) {
			oss.str("");  // ������� ������ - ������ ������
			oss << "\n\t" << ex.what() << "\n";

			// ����� ������ � ���������� �� ������ � �����
			cputs(oss.str().c_str(), errColor);

			getKey();

		} // try-catch
	}
}

// ���������� ��� ������ � ����� ��� �������
bool task1InsertPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// ������� �������� � ������ ����� �������� 
// insert(position, payload) � ��������� ������� � ������ ����� �������� position
// (��������� ������� ���������� � 0)
void App::task1Insert()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 1. ������� �������� � ������ ����� ��������\n\n";

	// ������ ������������� �������
	int size = getRand(2, 8);

	// ��������� ������� (int) � ���������� ������ �������� 
	List list(getArrayRandom(size, -99, 99), size);
	
	// ����� ������ 
	cout << "\t������ �� ������� ��������:\n" << list << "\n\n";

	// ��������� ������� ��� �������
	int position = getRand(0, list.getCounter() - 1);

	// ��������� �������� ��� �������
	int value = getRand(-99, 99);

	// ������� �������� �� ��������� �������
	list.insert(position, value);

	// ����� ������ 
	cout << "\t������ �� ������� ��������:\n";

	// ����� ������� � �������� ��� ������� � �����
	list.showListColor(task1InsertPred, &position, 1);

	cout << "\n\n\t����������� �������:\n\n" << "\t\t��������: " << value << "\n\n\t\t�������: " << position << "\n\n";

	getKey();
}

// ���������� ��� ������ � ����� ��� ������� � �������� ������
bool task1GetPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// ����������� �������� �������� ������ �� �������� �������
// get(postion)� ���������� �������� �������� ������ � �������� ������� (���������
// ������� ���������� � 0)
void App::task1Get()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 1. ����������� �������� �������� ������ �� �������� �������\n\n";

	// ������ ������������� �������
	int size = getRand(2, 8);

	// ��������� ������� (int) � ���������� ������ �������� 
	List list(getArrayRandom(size, -99, 99), size);

	// ��������� �������
	int position = getRand(0, list.getCounter() - 1);

	cout << "\t������:\n";

	// ����� ������ � �����
	list.showListColor(task1GetPred, &position, 1);

	cout << "\n\n\t������� �� ������� [" << position << "]: " << *list[position] << "\n\n";

	getKey();
}

// ���������� ��� ������ � ����� ��� ������� � �������� ������
bool task1PutPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// ������ �������� � �������� ������� ������
// put(position, value) � ���������� �������� value � �������� ������� ������
// (��������� ������� ���������� � 0)
void App::task1Put()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 1. ������ �������� � �������� ������� ������\n\n";

	// ������ ������������� �������
	int size = getRand(2, 8);

	// ��������� ������� (int) � ���������� ������ �������� 
	List list(getArrayRandom(size, -99, 99), size);

	// ��������� ������� ��� ���������
	int position = getRand(0, list.getCounter() - 1);

	// ��������� �������� ��� ���������
	int value = getRand(-99, 99);

	// ����� ������ 
	cout << "\t������ �� ��������� ��������:\n";
	list.showListColor(task1PutPred, &position, 1);
	cout << "\n\n";

	// ��������� �������� �� ��������� �������
	list.put(position, value);

	// ����� ������ 
	cout << "\t������ ����� ��������� ��������:\n";

	// ����� ������� � �������� ��� ������� � �����
	list.showListColor(task1InsertPred, &position, 1);

	cout << "\n";

	cout << "\t����������� �������:\n\n" << "\t\t��������: " << value << "\n\n\t\t�������: " << position << "\n\n";

	getKey();
}

// ���������� ��� ������ � ����� ����� ���������� ������� � ����� ������
bool task1AddAllPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition >= posArr[0] && currentPosition < posArr[1];
}

// ���������� ������� � ����� ������
// addAll(data[], n)���������� ������� � ����� ������
void App::task1AddAll()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 1. ���������� ������� � ����� ������\n\n";

	// ������ ������������� ������� ��� �������� ������
	int size = getRand(2, 5);

	// ��������� ������� (int) � ���������� ������ �������� 
	List list(getArrayRandom(size, -99, 99), size);

	// ����� ������ �� ���������� ������� � �����
	int counter = list.getCounter();

	// ����� ������ 
	cout << "\t������ �� ������� ������� � �����:\n" << list << "\n\n";

	// ������ ������������� ������� ��� ������� � ����� ������
	size = getRand(2, 5);

	// ��������� �������� ��� ������� �������
	int* values = getArrayRandom(size, -99, 99);

	// ���������� ������� � ����� ������
	list.addAll(values, size);

	// ����� ������ 
	cout << "\t������ ����� ������� ������� � �����:\n";

	// ������ ������� (�� / ��) ������������ ������� ��� ������ � �����
	int* position = new int[2];

	// ���������� ������� ���������
	// ������ ������� ������������ ��������
	position[0] = counter;

	// ������ ���������� ������������ ��������
	position[1] = counter + size;

	// ����� ������� � �������� ��� ������� � �����
	list.showListColor(task1AddAllPred, position, 2);

	cout << "\n\n\t������ ����������� ���������:\n\n";

	showArrInt(values, size);

	cout << "\n\n";

	getKey();
}

// ������� ������� ����� �������� 
// insertAll(position, data[], n)������� ������� data[] ����� �������� position
// (��������� ������� ���������� � 0)
void App::task1InsertAll()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 1. ������� ������� ����� ��������� ��������\n\n";

	// ������ ������������� ������� ��� �������� ������
	int size = getRand(2, 5);

	// ��������� ������� (int) � ���������� ������ �������� 
	List list(getArrayRandom(size, -99, 99), size);

	// ����� ������ �� ���������� ������� � �����
	int counter = list.getCounter();

	// ����� ������ 
	cout << "\t������ �� ������� ������� �� ��������� �������:\n" << list << "\n\n";

	// ������ ������������� ������� ��� ������� ������� � ��������� �������
	size = getRand(2, 5);

	// ��������� �������� ��� ������� �������
	int* values = getArrayRandom(size, -99, 99);

	// ��������� ������� ��� �������
	int position = getRand(0, list.getCounter() - 1);

	// ������� ������� ������� � ��������� ������� ������
	list.insertAll(position, values, size);

	// ����� ������ 
	cout << "\t������ ����� ������� ������� �� ��������� �������:\n";

	// ������ ������� (�� / ��) ������������ ������� ��� ������ � �����
	int* positions = new int[2];

	// ���������� ������� ���������
	// ������ ������� ������������ ��������
	positions[0] = position;

	// ������ ���������� ������������ ��������
	positions[1] = position + size;

	// ����� ������� � �������� ��� ������� � �����
	list.showListColor(task1AddAllPred, positions, 2);

	cout << "\n\n\t������ ����������� ���������:\n\n";

	showArrInt(values, size);

	cout << "\n\n\t\t��������� ������� �������: " << position
		<< "\n\n\t\t��������� ������� �������: " << position + size - 1 << "\n\n";

	getKey();
}

// ��������� ������� (int)
int* App::getArrayRandom(int size, int min, int max)
{
	// ��������� ������ ��� ������ (int)
	int* arr = new int[size];

	// ���������� ������� ���������� ������� (int)
	for (int i = 0; i < size; i++)
	{
		arr[i] = getRand(min, max);
	}

	// ����������� ��������� �� ������
	return arr;
}

// ���������� ������� ������ ��� ������� (int)
void App::showArrInt(int* arr, int size)
{
	// ����� �������������� ��������

	cout << "\t+��������������������������+\n"
		<< "\t| ���������� ���������: " << setw(2) << size << " |\n";

	cout << "\t+�����������������+";
	for (size_t i = 0; i < size; i++)
	{
		cout << "��������+";
	}

	cout << "\n\t|      ������     |";

	for (size_t i = 0; i < size; i++)
	{
		cout << "   " << setw(3) << i << "  |";
	}

	// ���� ������� ����� 
	if (size == 0)
	{
		cout << "\t+��������������������������+\n"
			<< "\t|                          |\n"
			<< "\t|        ���� �����        |\n"
			<< "\t|                          |\n"
			<< "\t+��������������������������+\n";
	}

	else
	{

		cout << "\n\t+�����������������+";
		for (size_t i = 0; i < size; i++)
		{
			cout << "��������+";
		}

		cout << "\n\t|    ����������   |";

		for (size_t i = 0; i < size; i++)
		{
			cout << " " << setw(7) << arr[i] << "|";
		}

		cout << "\n\t+�����������������+";
		for (size_t i = 0; i < size; i++)
		{
			cout << "��������+";
		}

		cout << "\n";
	}
}

#pragma endregion

#pragma region ������� 2

/*
	������� 2. �� ���� ������� List � Node ������������ ������ ListPlane � NodePlanec
		��� �������� ������ �������� ������ Plane. ����������������� ������ ������� ������ ListPlane.
*/

// ���� ������� 2
void App::task2()
{
	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ������� �������� � ������ ����� �������� 
		CMD_INSERT,
		// ����������� �������� �������� ������ �� �������� �������
		CMD_GET,
		// ������ �������� � �������� ������� ������
		CMD_PUT,
		// ���������� ������� � ����� ������
		CMD_ADD_ALL,
		// ������� ������� ����� �������� 
		CMD_INSERT_ALL
	};

	// ���������� ������� ����
	// ���������� ������� ����
	const int N_MENU = 6;

	MenuItem items[N_MENU] = {
		MenuItem("������� �������� � ������ ����� ��������", CMD_INSERT),
		MenuItem("����������� �������� �������� ������ �� �������� �������", CMD_GET),
		MenuItem("������ �������� � �������� ������� ������", CMD_PUT),
		MenuItem("���������� ������� � ����� ������", CMD_ADD_ALL),
		MenuItem("������� ������� ����� �������� ", CMD_INSERT_ALL),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� 2", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// ������� �������� � ������ ����� �������� 
			case CMD_INSERT:
				app.task2Insert();
				break;

				// ����������� �������� �������� ������ �� �������� �������
			case CMD_GET:
				app.task2Get();
				break;

				// ������ �������� � �������� ������� ������
			case CMD_PUT:
				app.task2Put();
				break;

				// ���������� ������� � ����� ������
			case CMD_ADD_ALL:
				app.task2AddAll();
				break;

				// ������� ������� ����� �������� 
			case CMD_INSERT_ALL:
				app.task2InsertAll();
				break;
			}
		}
		catch (exception& ex) {
			oss.str("");  // ������� ������ - ������ ������
			oss << "\n\t" << ex.what() << "\n";

			// ����� ������ � ���������� �� ������ � �����
			cputs(oss.str().c_str(), errColor);

			getKey();

		} // try-catch
	}
}

// ���������� ��� ������ � ����� ��� �������
bool task2InsertPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// ������� �������� � ������ ����� �������� 
// insert(position, payload) � ��������� ������� � ������ ����� �������� position
// (��������� ������� ���������� � 0)
void App::task2Insert()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 2. ������� �������� � ������ ����� ��������\n\n";

	// ������ ������������� �������
	int size = getRand(2, 8);

	// ��������� ������� (Plane) � ���������� ������ �������� 
	ListPlane list(fillArrPlane(size), size);

	// ����� ������ 
	cout << "\t������ �� ������� ��������:\n" << list << "\n\n";

	// ��������� ������� ��� �������
	int position = getRand(0, list.getCounter() - 1);

	// ��������� �������� ��� �������
	Plane value = genPlane();

	// ������� �������� �� ��������� �������
	list.insert(position, value);

	// ����� ������ 
	cout << "\t������ �� ������� ��������:\n";

	// ����� ������� � �������� ��� ������� � �����
	list.showListPlaneColor(task1InsertPred, &position, 1);

	cout << "\n\n\t������ ������������ ��������: " << position << "\n\n";

	getKey();
}

// ���������� ��� ������ � ����� ��� ������� � �������� ������
bool task2GetPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// ����������� �������� �������� ������ �� �������� �������
// get(postion)� ���������� �������� �������� ������ � �������� ������� (���������
// ������� ���������� � 0)
void App::task2Get()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 2. ����������� �������� �������� ������ �� �������� �������\n\n";

	// ������ ������������� �������
	int size = getRand(2, 8);

	// ��������� ������� (Plane) � ���������� ������ �������� 
	ListPlane list(fillArrPlane(size), size);

	// ��������� �������
	int position = getRand(0, list.getCounter() - 1);

	cout << "\t������:\n";

	// ����� ������ � �����
	list.showListPlaneColor(task1GetPred, &position, 1);

	Plane plane = list.get(position);

	// ������� ����
	short cl = getColor();

	cout << color(GREEN_ON_BLACK)  << "\n\n\t������� �� ������� ["<< position << "]\n";

	plane.showPlaneTable();

	cout << color(cl);

	getKey();
}

// ���������� ��� ������ � ����� ��� ������� � �������� ������
bool task2PutPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition == *posArr;
}

// ������ �������� � �������� ������� ������
// put(position, value) � ���������� �������� value � �������� ������� ������
// (��������� ������� ���������� � 0)
void App::task2Put()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 2. ������ �������� � �������� ������� ������\n\n";

	// ������ ������������� �������
	int size = getRand(2, 8);

	// ��������� ������� (Plane) � ���������� ������ �������� 
	ListPlane list(fillArrPlane(size), size);

	// ��������� ������� ��� ���������
	int position = getRand(0, list.getCounter() - 1);

	// ��������� �������� ��� ���������
	Plane value = genPlane();

	// ����� ������ 
	cout << "\t������ �� ��������� ��������:\n";
	list.showListPlaneColor(task1PutPred, &position, 1);
	cout << "\n\n";

	// ��������� �������� �� ��������� �������
	list.put(position, value);

	// ����� ������ 
	cout << "\t������ ����� ��������� ��������:\n";

	// ����� ������� � �������� ��� ������� � �����
	list.showListPlaneColor(task1InsertPred, &position, 1);

	cout << "\n";

	cout << "\t������� ������������ ��������: " << position << "\n\n";

	getKey();
}

// ���������� ��� ������ � ����� ����� ���������� ������� � ����� ������
bool task2AddAllPred(int currentPosition, int* posArr, int sizePosArr = 1)
{
	return currentPosition >= posArr[0] && currentPosition < posArr[1];
}

// ���������� ������� � ����� ������
// addAll(data[], n)���������� ������� � ����� ������
void App::task2AddAll()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 2. ���������� ������� � ����� ������\n\n";

	// ������ ������������� ������� ��� �������� ������
	int size = getRand(2, 5);

	// ��������� ������� (Plane) � ���������� ������ �������� 
	ListPlane list(fillArrPlane(size), size);

	// ����� ������ �� ���������� ������� � �����
	int counter = list.getCounter();

	// ����� ������ 
	cout << "\t������ �� ������� ������� � �����:\n" << list << "\n\n";

	// ������ ������������� ������� ��� ������� � ����� ������
	size = getRand(2, 5);

	// ��������� �������� ��� ������� �������
	Plane* values = fillArrPlane(size);

	// ���������� ������� � ����� ������
	list.addAll(values, size);

	// ����� ������ 
	cout << "\t������ ����� ������� ������� � �����:\n";

	// ������ ������� (�� / ��) ������������ ������� ��� ������ � �����
	int* position = new int[2];

	// ���������� ������� ���������
	// ������ ������� ������������ ��������
	position[0] = counter;

	// ������ ���������� ������������ ��������
	position[1] = counter + size;

	// ����� ������� � �������� ��� ������� � �����
	list.showListPlaneColor(task1AddAllPred, position, 2);

	cout << "\n\n\t����� ������������ �������: " << size << "\n\n";

	getKey();
}

// ������� ������� ����� �������� 
// insertAll(position, data[], n)������� ������� data[] ����� �������� position
// (��������� ������� ���������� � 0)
void App::task2InsertAll()
{
	cls();

	// ����� ������� �������
	cout << "\n\n\t\t������� 2. ������� ������� ����� ��������� ��������\n\n";

	// ������ ������������� ������� ��� �������� ������
	int size = getRand(2, 5);

	// ��������� ������� (Plane) � ���������� ������ �������� 
	ListPlane list(fillArrPlane(size), size);

	// ����� ������ �� ���������� ������� � �����
	int counter = list.getCounter();

	// ����� ������ 
	cout << "\t������ �� ������� ������� �� ��������� �������:\n" << list << "\n\n";

	// ������ ������������� ������� ��� ������� ������� � ��������� �������
	size = getRand(2, 5);

	// ��������� �������� ��� ������� �������
	Plane* values = fillArrPlane(size);

	// ��������� ������� ��� �������
	int position = getRand(0, list.getCounter() - 1);

	// ������� ������� ������� � ��������� ������� ������
	list.insertAll(position, values, size);

	// ����� ������ 
	cout << "\t������ ����� ������� ������� �� ��������� �������:\n";

	// ������ ������� (�� / ��) ������������ ������� ��� ������ � �����
	int* positions = new int[2];

	// ���������� ������� ���������
	// ������ ������� ������������ ��������
	positions[0] = position;

	// ������ ���������� ������������ ��������
	positions[1] = position + size;

	// ����� ������� � �������� ��� ������� � �����
	list.showListPlaneColor(task1AddAllPred, positions, 2);

	cout << "\n\n\t����� ������� ����������� ���������: " << size
		<< "\n\n\t��������� ������� �������: " << position
		<< "\n\n\t��������� ������� �������: " << position + size - 1 << "\n\n";


	getKey();
}

// ��������� ������� 
Plane App::genPlane()
{
	// ������ ������� ��������
	const int size = 5;

	// ������ �������� ��������
	Plane planes[size]
	{
		Plane("Airbus �380", 525, 345, 12000, 275'000'000, 15000, "F - WWOW"),
		Plane("Boeing 747", 452, 400, 10700, 266'000'000, 12000, "B - 18215"),
		Plane("Boeing 777", 550, 500, 13500, 280'000'000, 13000, "G - YMMM"),
		Plane("Airbus A320", 150, 115, 2100, 93'900'000, 10000, "F - GFKC"),
		Plane("Airbus A318", 132, 86, 2150, 65'000'000, 11000, "D - APWG"),
	};

	// ����������� ���������� �������� �� ������� ��������
	Plane newPlane = planes[getRand(0, size - 1)];

	// ��������� ������

	// ���������� ����������
	int tmp = newPlane.getSeat();
	newPlane.setCount_passengers(getRand(0, tmp));

	// ��������� �����
	tmp = newPlane.getDistance();
	newPlane.setDistance(getRand(tmp - 1000, tmp + 1000));

	// ����
	tmp = newPlane.getPrice();
	newPlane.setPrice(getRand(tmp - 10'000'000, tmp + 10'000'000));

	// ����� �����
	char newNumber[Plane::NUMBER_SIZE + 1];

	// ����� ������ �������
	int len = strlen(newPlane.getNumber());

	strncpy(newNumber, newPlane.getNumber(), len);

	for (size_t i = 0; i < len; i++)
	{
		// ������� ������
		char ch = newNumber[i];

		// ���� ������� ������ �������� ������ 
		if (ch >= '0' && ch <= '9')
			ch = getRand('0', '9');

		// ���� ������� ������ �������� ������
		else if (ch >= 'A' && ch <= 'Z')
			ch = getRand('A', 'Z');

		newNumber[i] = ch;
	}

	newNumber[len] = 0;

	newPlane.setNumber(newNumber);

	return newPlane;
}

// �������� ���������� ������� (Plane)
Plane* App::fillArrPlane(int size)
{
	Plane* planes = new Plane[size];

	for (size_t i = 0; i < size; i++)
	{
		planes[i] = genPlane();
	}

	return planes;
}

#pragma endregion