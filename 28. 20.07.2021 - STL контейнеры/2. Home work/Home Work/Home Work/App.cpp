#include "App.h"

/*
 * ������ 1.�������� ������� ����� ��� �������� ������� ������ � �������������
 * �������� STL.��� ������, ������� �������������� � ������� �int, ���������
 * ��������� ���������� �������:
 * �	��� �������� ����. ������� ��� ����� �����, ���������� � ������ �� ��� ���
 *		�������� ��������� ����� � ������� ����������, � �� ������ � � ���������
 *		(�������� � ����������� ����� ������������� � �������, �������� ���������;
 *		���� �� ���������� ����� ��������� ������). ������� ����� �� � ����� ���������.
 * �	���� ��� �������� �������. ���������� �������� �� ������ ������ ������� � �����
 *		������, ���� �������� ���������� �������� ������ ������� �� ������ ������ (����
 *		 ������ ������� �� �������� ������ ���������,�� ����������� �� ������ ������� ��
 *		 ������ ��� ��������). ������� ������� �� � ����� ���������.
 * �	��� ���������� ������, ���������� �� ����� ���� ���������. ������� ���� ������.
 *		�������������� � ������ ������ � ��������� �������� (����� �������� ���������
 *		����� ������������� ����������),������� ��������������� ������.
 *
 * ������ 2. �������� � ������ �������� ��������: ��������������� ����� ��������,
 * ������� � �������� ��������, ����������� ����� ��������, ����������� ����� ��������.
 *
 * ���������� � ����� � ������ ������� � ������� �0�, � ������ ������ �������� ������
 * ��� �����, ��� � �����, �������� � �42�, �42�, �32�.�������� ���� ����������� ���������
 * ������������ � ����������� ������������� ������ map. � �������� ����� ������������ ��������
 * ���� ���������������� ����� ��������, � �������� �������� � ���������� ������ ��������
 * (�.�. map<string, Bus>).
 *
 * ���������� ������ ������������ ����� � ������� ���� � ���������� ����� ����������� �������:
 * �	��������� ������������ ��������� ������ ��� ���� ���������, ����������� ���� ���������
 *		� ��������� ���������, ����������� � �����, ����������� �� ��������, ���������� ���������
 *		���� ��������� � �������� ����� (���� ������ ����� ���) � ������ ������ � ��������� ��
 *		��������� ����� (���� ����� ���� ����);
 * �	�������� ������ �������� �� �����: �������� ����� ��������; ��������� ������ �� ����
 *		�������� �� ��������� ���������, ����������� � �����, � ���������� ��� ������ � ���������
 *		���������, ����������� �� ���������; ��������� ������ ��������� � ����� � �� ��������;
 *		�������������� ������ � ��������� ���� ���������, ���������� ������ ����������� � ��������
 *		 �����
 * �	�������� ������ �������� � ����: �������� ����� ��������; ��������� ������ �� ���� ��������
 *		�� ��������� ���������, ����������� �� ���������, � ������������ ��� ������ � ���������
 *		���������, ����������� � �����;��������� ������ ��������� � ����� � �� ��������;
 *		�������������� ������ � ��������� ���� ���������, ���������� ������ ����������� � ��������
 *		�����
 * �	����� �������� ��� ���� ���������, �� ���������, ����������� � �����, � �� ���������,
 *		����������� �� ���������, ������������� �� ������� ���������.
*/


#pragma region ������� 1. ������ � ������������

/*
 * ������ 1.�������� ������� ����� ��� �������� ������� ������ � �������������
 * �������� STL.��� ������, ������� �������������� � ������� �int, ���������
 * ��������� ���������� �������:
 * �	��� �������� ����. ������� ��� ����� �����, ���������� � ������ �� ��� ���
 *		�������� ��������� ����� � ������� ����������, � �� ������ � � ���������
 *		(�������� � ����������� ����� ������������� � �������, �������� ���������;
 *		���� �� ���� ������ ����� ��������� ������). ������� ����� �� � ����� ���������.
 * �	���� ��� �������� �������. ���������� �������� �� ������ ������ ������� � �����
 *		������, ���� �������� ���������� �������� ������ ������� �� ������ ������ (����
 *		������ ������� �� �������� ������ ���������,�� ����������� �� ������ ������� ��
 *		������ ��� ��������). ������� ������� �� � ����� ���������.
 * �	��� ���������� ������, ���������� �� ����� ���� ���������. ������� ���� ������.
 *		�������������� � ������ ������ � ��������� �������� (����� �������� ���������
 *		����� ������������� ����������),������� ��������������� ������.
*/

// ������� 1. ������ � ������������
void App::task1()
{
	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ���������� ����� �� ���� � �������������� � �������������� ����������
		CMD_STACK,
		// ����������� ��������� �� �������� ������� �� ������� ��������
		CMD_QUEUE,
		// ������������ ������� � ���������� ��������� � ���������� ������
		CMD_LIST
	};

	// ���������� ������� ����
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("���������� ����� �� ���� � �������������� � �������������� ����������", CMD_STACK),
		MenuItem("����������� ��������� �� �������� ������� �� ������� ��������", CMD_QUEUE),
		MenuItem("������������ ������� � ���������� ��������� � ���������� ������", CMD_LIST),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� 1. ������ � ������������", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// ���������� ����� �� ���� � �������������� � �������������� ����������
			case CMD_STACK:
				app.stackDemo();
				break;
				// ����������� ��������� �� �������� ������� �� ������� ��������
			case CMD_QUEUE:
				app.queueDemo();
				break;	
				// ������������ ������� � ���������� ��������� � ���������� ������
			case CMD_LIST:
				app.listDemo();
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
} // App::task1()

// ����� ����� ��� �������
void App::showLine()
{
	cout << "    +������������+������+������+������+������+������+������+������+������+������+������+������+������+������+������+\n";
} // App::showLine()

// ����� ��������� �� �������� ������ ��� �������
void App::showEmpty()
{
	// ������� ����
	short cl = getColor();

	cout << "    |  " << color(LTRED_ON_BLACK)
		<< "                                                 ��� ������                                                "
		<< color(cl) << " | \n";
} // App::showEmpty()

#pragma region Stack

// ���������� ����� �� ����� � �������������� � �������������� ����������
void App::stackDemo()
{
	cls();

	showNavBarMessage(hintColor, "���������� ����� �� ����� � �������������� � �������������� ����������");

	// �������� ���� 
	stack<int> source;

	// ���������� ����� 
	fillStack(source, 10);

	// ����� ��������� ����� �� ����������
	outStack(source, "�������� ����", "�� ����������", LTGREEN_ON_BLACK);

	cputs("\n ���������������������������������������������������������������������������������������������������������������� \n\n", YELLOW_ON_BLACK);

	// ����� ��� ������������� � ������������� ���������
	stack<int> pos, neg;

	// ���������� ����� �� ����� � �������������� � �������������� ����������
	separationStack(source, neg, pos);

	// ����� ��������� ����� ����� ���������
	outStack(source, "�������� ����", "����� ����������", LTGREEN_ON_BLACK);

	cout << "\n\n";

	// ����� ����� � �������������� ����������
	outStack(pos, "���� � �������������� ����������", "����� ����������", LTRED_ON_BLACK);

	// ����� ����� � �������������� ����������
	outStack(neg, "���� � �������������� ����������", "����� ����������", LTCYAN_ON_BLACK);

	getKey();

} // App::stackDemo()

// ���������� ����� 
void App::fillStack(stack<int>& source, int n)
{
	for (int i = 0; i < n; i++)
	{
		source.push(getRand(-10, 10));
	}
} // App::fillStack()

// ���������� ����� �� ����� � �������������� � �������������� ���������� �� �������
void App::separationStack(stack<int>& source, stack<int>& neg, stack<int>& pos)
{
	// ������ �������� ����� 
	int n = source.size();

	// ���������� �������� ����� 
	for (int i = 0; i < n; i++)
	{
		// �������
		int val = source.top();

		// �������� �������� 
		source.pop();

		// ���� �������� ������������� 
		if (val >= 0)
			pos.push(val);
		// ����� 
		else
			neg.push(val);
	}
} // App::separationStack()

// ����� ����� 
void App::outStack(stack<int> source, string type, string descript, short colorElem)
{
	// ������ ����� 
	int n = source.size();

	// ������� ����
	short cl = getColor();

	cout<< "    +������������+������������������������������������������������+������������������������������������������������+\n"
		<< "    | ������: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | ��� ������: " << left << color(YELLOW_ON_BLACK) << setw(34) << type << color(cl)
		<< " | ��������: " << color(YELLOW_ON_BLACK) << setw(36) << descript << color(cl) << right << " |\n";

	// ����� �������������� �����
	showLine();

	// ���� � ����� ��� ������
	if (source.empty())
	{
		showEmpty();
		showLine();
		return;
	}

	cout << "    |  ��������  | ";

	// ����� ��������� 
	for (int i = 0; i < n; i++)
	{
		// ����� �������� 
		cout << color(colorElem) << setw(4) << source.top() << color(cl) << " | ";

		source.pop();
	}

	cout << "\n";

	// ����� �������������� �����
	showLine();

} // outStack()

#pragma endregion

#pragma region Queue

// ����������� ��������� �� �������� ������� �� ������� ��������
void App::queueDemo()
{
	cls();

	showNavBarMessage(hintColor, "����������� ��������� �� �������� ������� �� ������� ��������");

	// �������� ������� 
	queue<int> source;

	// ���������� ������� 
	fillQueue(source, 10);

	// ����� �������� ������� �� �����������
	outQueue(source, "�������� ������", "�� �����������", LTGREEN_ON_BLACK);

	cputs("\n ���������������������������������������������������������������������������������������������������������������� \n\n", YELLOW_ON_BLACK);

	// ������� ��� ����������� 
	queue<int> result;

	// ����������� ��������� �� �������� ������� �� ������� ��������
	movingQueue(source, result);

	// ����� ��������� ����� ����� ���������
	outQueue(source, "�������� ������", "����� �����������", LTGREEN_ON_BLACK);

	cout << "\n\n";

	// ����� �������������� ������� ����� �����������
	outQueue(result, "�������������� �������", "����� �����������", LTGREEN_ON_BLACK);

	getKey();

} // App::queueDemo()

// ����������� ��������� �� �������� ������� �� ������� �������� �� ������� 
void App::movingQueue(queue<int>& source, queue<int>& dest)
{
	// ������ �������� �������
	int n = source.size();

	for (int i = 0; i < n; i++ )
	{
		// ������� �������
		int item = source.front();

		// ���� �������� ������������� 
		if (item < 0)
			return;

		// ���������� �������� � �������
		dest.push(item);

		// �������� �������� �� �������� �������
		source.pop();
	}
} // App::movingQueue()

// ���������� �������
void App::fillQueue(queue<int>& source, int n)
{
	for (int i = 0; i < n; i++)
	{
		source.push(getRand(-10, 10));
	}

} // App::fillQueue()

// ����� �������
void App::outQueue(queue<int> source, string type, string descript, short colorElem)
{
	// ������ ������� 
	int n = source.size();

	// ������� ����
	short cl = getColor();

	cout << "    +������������+������������������������������������������������+������������������������������������������������+\n"
		<< "    | ������: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | ��� ������: " << left << color(YELLOW_ON_BLACK) << setw(34) << type << color(cl)
		<< " | ��������: " << color(YELLOW_ON_BLACK) << setw(36) << descript << color(cl) << right << " |\n";

	// ����� �������������� �����
	showLine();

	// ���� � ����� ��� ������
	if (source.empty())
	{
		showEmpty();
		showLine();
		return;
	}

	cout << "    |  ��������  | ";

	// ����� ��������� 
	for (int i = 0; i < n; i++)
	{
		// ����� �������� 
		cout << color(colorElem) << setw(4) << source.front() << color(cl) << " | ";

		source.pop();
	}

	cout << "\n";

	// ����� �������������� �����
	showLine();

} // App::outQueue()

#pragma endregion

#pragma region List

// ������������ ������� � ���������� ��������� � ���������� ������
void App::listDemo()
{
	cls();

	showNavBarMessage(hintColor, "������������ ������� � ���������� ��������� � ���������� ������");

	// �������� ������
	list<int> source;

	// ���������� ������ 
	fillList(source, 10);

	// ����� ��������� ������ �� ����������
	outList(source, "�������� ������", "�� ����������", LTGREEN_ON_BLACK);

	cputs("\n ���������������������������������������������������������������������������������������������������������������� \n\n", YELLOW_ON_BLACK);

	// ������������ ������� � ���������� ��������� � ���������� �������
	dublicationList(source);

	// ����� ��������� ������ ����� ���������
	outList(source, "�������� ������", "����� ����������", LTGREEN_ON_BLACK);

	cout << "\n\n";

	getKey();

} // App::listDemo()

// ������������ ������� � ���������� ��������� � ���������� ������ �� �������
void App::dublicationList(list<int>& source)
{
	// ���� ������ ���� 
	if (source.empty())
		throw exception("App: ������ ����");

	source.insert(source.begin(), source.front());
	source.insert(source.end(), source.back());
}

// ���������� ������
void App::fillList(list<int>& source, int n)
{
	for (int i = 0; i < n; i++)
	{
		source.push_back(getRand(-10, 10));
	}
}

// ����� ������
void App::outList(list<int> source, string type, string descript, short colorElem)
{
	// ������ ������ 
	int n = source.size();

	// ������� ����
	short cl = getColor();

	cout << "    +������������+������������������������������������������������+������������������������������������������������+\n"
		<< "    | ������: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | ��� ������: " << left << color(YELLOW_ON_BLACK) << setw(34) << type << color(cl)
		<< " | ��������: " << color(YELLOW_ON_BLACK) << setw(36) << descript << color(cl) << right << " |\n";

	// ����� �������������� �����
	showLine();

	// ���� � ����� ��� ������
	if (source.empty())
	{
		showEmpty();
		showLine();
		return;
	}

	cout << "    |  ��������  | ";

	// ����� ��������� 
	for (auto item: source)
	{
		// ����� �������� 
		cout << color(colorElem) << setw(4) << item << color(cl) << " | ";
	}

	cout << "\n";

	// ����� �������������� �����
	showLine();
}

#pragma endregion

#pragma endregion 

#pragma region ������� 2. ���������� ����

/*
 * ������ 2. �������� � ������ �������� ��������: ��������������� ����� ��������,
 * ������� � �������� ��������, ����������� ����� ��������, ����������� ����� ��������.
 *
 * ���������� � ����� � ������ ������� � ������� �0�, � ������ ������ �������� ������
 * ��� �����, ��� � �����, �������� � �42�, �42�, �32�.�������� ���� ����������� ���������
 * ������������ � ����������� ������������� ������ map. � �������� ����� ������������ ��������
 * ���� ���������������� ����� ��������, � �������� �������� � ���������� ������ ��������
 * (�.�. map<string, Bus>).
 *
 * ���������� ������ ������������ ����� � ������� ���� � ���������� ����� ����������� �������:
 * �	��������� ������������ ��������� ������ ��� ���� ���������, ����������� ���� ���������
 *		� ��������� ���������, ����������� � �����, ����������� �� ��������, ���������� ���������
 *		���� ��������� � �������� ����� (���� ������ ����� ���) � ������ ������ � ��������� ��
 *		��������� ����� (���� ����� ���� ����);
 * �	�������� ������ �������� �� �����: �������� ����� ��������; ��������� ������ �� ����
 *		�������� �� ��������� ���������, ����������� � �����, � ���������� ��� ������ � ���������
 *		���������, ����������� �� ���������; ��������� ������ ��������� � ����� � �� ��������;
 *		�������������� ������ � ��������� ���� ���������, ���������� ������ ����������� � ��������
 *		�����
 * �	�������� ������ �������� � ����: �������� ����� ��������; ��������� ������ �� ���� ��������
 *		�� ��������� ���������, ����������� �� ���������, � ������������ ��� ������ � ���������
 *		���������, ����������� � �����;��������� ������ ��������� � ����� � �� ��������;
 *		�������������� ������ � ��������� ���� ���������, ���������� ������ ����������� � ��������
 *		�����
 * �	����� �������� ��� ���� ���������, �� ���������, ����������� � �����, � �� ���������,
 *		����������� �� ���������, ������������� �� ������� ���������.
*/

// ������� 2. ���������� ����
void App::task2()
{
	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ��������� ������������ ��������� ������ ��� ���� ���������
		CMD_CREATE_PARK,
		// ����� �������� �� �����
		CMD_EXIT,
		// ������ �������� � ����
		CMD_ENTRY,
		// ����� �������� ��� ���� ���������
		CMD_PRINT_ALL
	};

	// ���������� ������� ����
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("��������� ������������ ��������� ������ ��� ���� ���������", CMD_CREATE_PARK),
		MenuItem("����� �������� �� �����", CMD_EXIT),
		MenuItem("������ �������� � ����", CMD_ENTRY),
		MenuItem("����� �������� ��� ���� ���������", CMD_PRINT_ALL),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� 2. ���������� ����", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
			// ��������� ������������ ��������� ������ ��� ���� ���������
			case CMD_CREATE_PARK:
				app.createPark();
				break;
			// ����� �������� �� �����
			case CMD_EXIT:
				app.exitBus();
				break;
			
			// ������ �������� � ����
			case CMD_ENTRY:
				app.entryBus();
				break;
				
			// ����� �������� ��� ���� ���������
			case CMD_PRINT_ALL:
				app.printAll();
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

} // App::task2()

// ��������� ������������ ��������� ������ ��� ���� ���������
void App::createPark()
{
	cls();

	showNavBarMessage(hintColor, "��������� ������������ ��������� ������ ��� ���� ���������");

	const int SIZE_ARR = 12;

	// ����� ���������
	showBus(mapBus_, "��� ��������", "�� ����������");

	// ���� ����� �� ���������� 
	if (!isFile(busFile_))
	{
		// ������ ���������
		Bus* busList = new Bus[SIZE_ARR + 1]
		{
			Bus("�227��", "������ �.�",    "42�", "0"),
			Bus("�754��", "������ �.�",    "41�", "41�"),
			Bus("�245��", "������� �.�",   "76", "76"),
			Bus("�984��", "������� �.�",   "41�", "41�"),
			Bus("�425��", "������ �.�",    "42�", "42�"),
			Bus("�465��", "������� �.�",   "41�", "0"),
			Bus("�691��", "��������� �.�", "76", "76"),
			Bus("�943��", "������� �.�",   "41�", "41�"),
			Bus("�698��", "������� �.�",   "42�", "0"),
			Bus("�789��", "������� �.�",   "76", "76"),
			Bus("�438��", "�������� �.�",  "42�", "42�"),
			Bus("�879��", "������� �.�",   "41�", "0")
		};

		// ���������� ����������
		for (int i = 0; i < SIZE_ARR; i++)
		{
			mapBus_[busList[i].getName()] = busList[i];
		}

		// ���������� � ���� 
		saveMap(mapBus_, busFile_);
	}

	// �������� �� �����
	loadMap(mapBus_, busFile_);

	cout << endl;

	// ����� ���������
	showBus(mapBus_, "��� ��������", "����� �������� �����");

	cout << "\n\n\n";

	// ����� ��������� � ����� 
	showBus(mapPark_, "�������� � �����", "����� �������� �����");

	cout << "\n\n\n";

	// ����� ��������� �� �����  
	showBus(mapVoy_, "�������� �� �����", "����� �������� �����");

	cout << "\n\n\n";

	getKey();


} // App::createPark()

// ����� �������� �� �����
void App::exitBus()
{
	cls();

	showNavBarMessage(hintColor, "����� �������� �� �����");

	// �������� �� ����� 
	loadMap(mapBus_, busFile_);

	// ����� ��������� � ����� 
	showBus(mapPark_, "�������� � �����", "����� �������� �����");

	cout << "\n";

	// ����� ��������� �� �����  
	showBus(mapVoy_, "�������� �� �����", "����� �������� �����");

	cout << "\n\n";

	// ����� �������� 
	string number;

	// ������� ���� 
	short cl = getColor();

	// ���� ������ �������� 
	setCursorVisible(true);
	showInputLine("������� ����� ��������: ", 12, hintColor);

	getline(cin, number);

	setCursorVisible(false);
	setColor(cl);

	// ����� �������� 
	exitBusMap(mapBus_, mapPark_, mapVoy_, number);

	// ����� �� ���������� � ���� 
	showBus(mapBus_, "��� ��������", "�� ���������� � ����");

	cout << "\n";

	// ����� ��������� � ����� 
	showBus(mapPark_, "�������� � �����", "�� ���������� � ����");

	cout << "\n";

	// ����� ��������� �� �����  
	showBus(mapVoy_, "�������� �� �����", "�� ���������� � ����");

	cout << "\n";

	// ���������� � ����
	saveMap(mapBus_, busFile_);

	cputs("\t������ ������� ���������!", GREEN_ON_BLACK);

	cout << "\n\n";

	getKey();

} // App::exitBus()

// ����� �������� 
void App::exitBusMap(map<string, Bus>& mapBus, map<string, Bus>& mapPark, map<string, Bus>& mapVoy, string number)
{
	// �����
	auto res = mapBus.find(number);

	// ���� ����� ����� �� ������
	if (res == mapBus.end())
		throw exception("����� ����� �� ������!");

	// ������� 
	Bus& bus = (*res).second;

	// ���� ������� ��������� �� ����� 
	if (bus.getRoutAct() != "0")
		throw exception("������� ��� �� �����!");

	// ��������� �������� 
	bus.setRoutAct(bus.getRoutApp());

	// �������� �� ���� ��������� � ����� 
	mapPark.erase(number);

	// ���������� � ���� ��������� �� ����� 
	mapVoy[number] = bus;
}

// ����� �������� � ����
void App::entryBus()
{
	cls();

	showNavBarMessage(hintColor, "����� �������� � ����");

	// �������� �� ����� 
	loadMap(mapBus_, busFile_);

	// ����� ��������� �� �����  
	showBus(mapVoy_, "�������� �� �����", "����� �������� �����");

	cout << "\n";

	// ����� ��������� � ����� 
	showBus(mapPark_, "�������� � �����", "����� �������� �����");

	cout << "\n\n";

	// ����� �������� 
	string number;

	// ������� ���� 
	short cl = getColor();

	// ���� ������ �������� 
	setCursorVisible(true);
	showInputLine("������� ����� ��������: ", 12, hintColor);

	getline(cin, number);

	setCursorVisible(false);
	setColor(cl);

	// ����� �������� 
	entryBussMap(mapBus_, mapPark_, mapVoy_, number);

	// ����� �� ���������� � ���� 
	showBus(mapBus_, "��� ��������", "�� ���������� � ����");

	cout << "\n";

	// ����� ��������� �� �����  
	showBus(mapVoy_, "�������� �� �����", "�� ���������� � ����");

	cout << "\n";

	// ����� ��������� � ����� 
	showBus(mapPark_, "�������� � �����", "�� ���������� � ����");

	cout << "\n";

	// ���������� � ����
	saveMap(mapBus_, busFile_);

	cputs("\t������ ������� ���������!", GREEN_ON_BLACK);

	cout << "\n\n";

	getKey();


} // App::entryBus()

// ����� �������� 
void App::entryBussMap(map<string, Bus>& mapBus, map<string, Bus>& mapPark, map<string, Bus>& mapVoy, string number)
{
	// �����
	auto res = mapBus.find(number);

	// ���� ����� ����� �� ������
	if (res == mapBus.end())
		throw exception("����� ����� �� ������!");

	// ������� 
	Bus& bus = (*res).second;

	// ���� ������� ��������� � ����� 
	if (bus.getRoutAct() == "0")
		throw exception("������� ��� � �����!");

	// ��������� �������� 
	bus.setRoutAct("0");

	// �������� �� ���� ��������� �� ����� 
	mapVoy.erase(number);

	// ���������� � ���� ��������� � ����� 
	mapPark[number] = bus;
}

// ����� �������� ��� ���� ���������
void App::printAll()
{
	cls();


	showNavBarMessage(hintColor, "����� �������� ��� ���� ���������");

	// �������� �� �����
	loadMap(mapBus_, busFile_);

	// ��� ������ 
	multimap<string, Bus> muBus, muPark, muVoy;

	for (auto item : mapBus_)
	{
		// ������� �������
		auto p = item.second;

		muBus.emplace(p.getRoutApp(), p);
	}

	for (auto item : mapPark_)
	{
		// ������� �������
		auto p = item.second;

		muPark.emplace(p.getRoutApp(), p);
	}

	for (auto item : mapVoy_)
	{
		// ������� �������
		auto p = item.second;

		muVoy.emplace(p.getRoutApp(), p);
	}


	cout << endl;

	// ����� ���������
	showBus(muBus, "��� ��������", "����� �������� �����");

	cout << "\n";

	// ����� ��������� � ����� 
	showBus(muPark, "�������� � �����", "����� �������� �����");

	cout << "\n";

	// ����� ��������� �� �����  
	showBus(muVoy, "�������� �� �����", "����� �������� �����");

	cout << "\n";

	getKey();


	
} // App::printAll()

// ����� map ���������
void App::showBus(map<string, Bus>& mapBus, string name, string specific)
{
	// ����� ����� �������
	showHeadBus(mapBus, name, specific);

	// ���� map ������ 
	if (mapBus.empty())
		showEmptyBus();

	// ����� ��������� 
	showBusElem(mapBus);

	// ����� ����� ����������� 
	showLineBus();

} // App::outBus()

// ����� ����� �������
void App::showHeadBus(map<string, Bus>& mapBus, string name, string specific)
{
	// ������� ����
	short cl = getColor();

	cout << "    +������������+���������������������������������+���������������������������������+\n"
		<< "    | ������: " << left << color(GREEN_ON_BLACK) << setw(2) << mapBus.size()
		<< color(cl) << " | ������: " << color(GREEN_ON_BLACK) << setw(23) << name
		<< color(cl) << " | ��������: " << color(GREEN_ON_BLACK) << setw(21) << specific
		<< color(cl) << " |\n" << right
		<< "    +������+�����+��������+������������������+�����+����������������+����������������+\n"
		<< "    |  N   |    �����     |           ���          | ����. �������  | ����. �������  |\n"
		<< "    +������+��������������+������������������������+����������������+����������������+\n";
} // App::showHeadBus()

// ����� �����-�����������
void App::showLineBus()
{
	cout << "    +������+��������������+������������������������+����������������+����������������+\n";
}

// ����� "�������" 
void App::showEmptyBus()
{
	// ������� ����
	short cl = getColor();

	cout << "    | " << color(LTRED_ON_BLACK)
		<< "                                    ��� ������                                "
		<< color(cl) << " |\n";
}

// ����� �������� ��� �������
void App::showBusElem(map<string, Bus>& mapBus)
{
	short cl = getColor();

	int i = 1;

	for (auto item: mapBus)
	{
		// ������� �������� 
		Bus p = item.second;

		cout << "    | " << setw(4) << i++ << " | " << left
			<< color(LTYELLOW_ON_BLACK) << setw(12) << p.getNumber()
			<< color(cl) << " | " 
			<< color(LTYELLOW_ON_BLACK) << setw(22) << p.getName()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutApp()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutAct()
			<< color(cl) << " | " << right << endl;
	}

} // showBusElem()

// ����� map ���������
void App::showBus(multimap<string, Bus>& mapBus, string name, string specific)
{
	// ����� ����� �������
	showHeadBus(mapBus, name, specific);

	// ���� map ������ 
	if (mapBus.empty())
		showEmptyBus();

	// ����� ��������� 
	showBusElem(mapBus);

	// ����� ����� ����������� 
	showLineBus();

} // App::outBus()

// ����� ����� �������
void App::showHeadBus(multimap<string, Bus>& mapBus, string name, string specific)
{
	// ������� ����
	short cl = getColor();

	cout << "    +������������+���������������������������������+���������������������������������+\n"
		<< "    | ������: " << left << color(GREEN_ON_BLACK) << setw(2) << mapBus.size()
		<< color(cl) << " | ������: " << color(GREEN_ON_BLACK) << setw(23) << name
		<< color(cl) << " | ��������: " << color(GREEN_ON_BLACK) << setw(21) << specific
		<< color(cl) << " |\n" << right
		<< "    +������+�����+��������+������������������+�����+����������������+����������������+\n"
		<< "    |  N   |    �����     |           ���          | ����. �������  | ����. �������  |\n"
		<< "    +������+��������������+������������������������+����������������+����������������+\n";
} // App::showHeadBus()

// ����� �������� ��� �������
void App::showBusElem(multimap<string, Bus>& mapBus)
{
	short cl = getColor();

	int i = 1;

	for (auto item : mapBus)
	{
		// ������� �������� 
		Bus p = item.second;

		cout << "    | " << setw(4) << i++ << " | " << left
			<< color(LTYELLOW_ON_BLACK) << setw(12) << p.getNumber()
			<< color(cl) << " | "
			<< color(LTYELLOW_ON_BLACK) << setw(22) << p.getName()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutApp()
			<< color(cl) << " | "
			<< color(LTGREEN_ON_BLACK) << setw(14) << p.getRoutAct()
			<< color(cl) << " | " << right << endl;
	}

} // showBusElem()


// ���������� map � ���� 
void App::saveMap(map<string, Bus>& mapBus, string nameFile)
{
	// ������� ����� � ������ �������� ������
	fstream file(nameFile, ios::binary | ios::out);

	for (auto p: mapBus)
	{

		p.second.write(file);
	}

	file.close();
}

// �������� map �� ����� 
void App::loadMap(map<string, Bus>& mapBus, string nameFile)
{
	mapBus.clear();

	// ������� ����� � ������ �������� ������
	fstream file(nameFile, ios::binary | ios::in);

	Bus temp;

	while (!file.eof())
	{
		// ����������� �� �����
		temp.read(file);

		// ����� �������� �������� 
		string number = temp.getNumber();

		// ���� ��������� ����� ����� 
		if (file.eof()) break;

		// ���������� � ����� ����
		mapBus[number] = temp;

		// ���� ������� � ����� 
		if (temp.getRoutAct() == "0")
			mapPark_[number] = temp;

		// ���� ������� �� ����� 
		else
			mapVoy_[number] = temp;
	}

	file.close();
}

// �������� �� ������� ����� 
bool App::isFile(string nameFile)
{
	fstream file(nameFile, ios::in);

	bool flag = file.is_open();

	file.close();

	return flag;
}

#pragma endregion 
