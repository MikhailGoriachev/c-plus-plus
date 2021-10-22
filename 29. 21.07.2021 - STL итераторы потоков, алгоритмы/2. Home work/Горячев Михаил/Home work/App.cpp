#include "App.h"

/*
*	������ 1. ��� ������ STL, � �������������� ����������, �������������� ��������,
*	��������� ���������� �������� ���������� ����������, �������������� ������� �� �������:
*	�	������������ ������ �� ��������� ������������ �����, �������� ���������
*		������� � ����������. ��������� ������ � ��������������� ������ ������ ��� ������
*		���������� ���������
*	�	��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
*		�������� ��� �������� ������� �� 2. ��������� ������ � ��������������� ������ ������
*		��� ������ ���������� ���������
*	�	��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
*		����������� ������ �� ������� � ������������� � ������ �������. ������� ������ �
*		�������� ���������� ������������� ���������
*	�	��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
*		����������� ������ �� ��������. ������� ������ � �������� ���������� �������������
*		���������
*
*	������ 2. �������� � ������ �������� ��������: ��������������� ����� ��������, �������
*	� ����������������, ����������� ����� ��������, ����������� ����� ��������.
*
*	���������� � ����� � ������ ������� � ������� �0�, � ������ ������ �������� ������ ���
*	�����, ��� � �����, �������� � �42�, �42�, �32�.��������� ������ ��������� �� ������
*	vector. ������� ��������� � ��������������� ������ ������, ������/������ ����� ����������
*	��� ������ ���������� ���������. ��� ������ ������� ���������� �������� ��������� ������
*	� ���� �� ������� ������������ ��������.
*
*	��������� ������ ������������ ����� � ������� ���� � ���������� ����� �� ��������� �������:
*	�	������ ������ �� ��������� � ��������� ���� (��������������� ����� ������)
*	�	������ ������ �� ��������� �� ���������� �����(���������������� ������ �����)
*	�	����� ������ �� ��������� ��� ������ ��������� for_each()� ���������� ��������
*	�	����������� ��������� ��������� �� ��������������� ������� ��� ������ ��������� sort()
*		� ���������� �������� � �����������;
*	�	����������� ��������� ��������� �� ������� � ��������� ����������� ������ ��������� sort()
*		� ���������� �������� � �����������;
*	������������ ������ � �������� ������������� ������ � ����������� ����������� ��������� STL.
*/


#pragma region ������� 

#pragma region ������� 1. ������������ ���������� �� �������

/*
*	������ 1. ��� ������ STL, � �������������� ����������, �������������� ��������,
*	��������� ���������� �������� ���������� ����������, �������������� ������� �� �������:
*	�	������������ ������ �� ��������� ������������ �����, �������� ���������
*		������� � ����������. ��������� ������ � ��������������� ������ ������ ��� ������
*		���������� ���������
*	�	��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
*		�������� ��� �������� ������� �� 2. ��������� ������ � ��������������� ������ ������
*		��� ������ ���������� ���������
*	�	��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
*		����������� ������ �� ������� � ������������� � ������ �������. ������� ������ �
*		�������� ���������� ������������� ���������
*	�	��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
*		����������� ������ �� ��������. ������� ������ � �������� ���������� �������������
*		���������
*/

// ������� 1. ������������ ���������� �� �������
void App::task1()
{
	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ����������� ������� ���������� ������������� ������� 
		CMD_FILL_VECTOR,
		// ��������� ��������� ������� �� 2
		CMD_POW_TWO,
		// ���������� ������� �� ������� - ������������� � ������ �������
		CMD_SORT_BY_POS,
		// ���������� ������� �� ��������
		CMD_SORT_BY_DECR
	};

	// ���������� ������� ����
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("����������� ������� ���������� ������������� �������", CMD_FILL_VECTOR),
		MenuItem("������ ������� �� ���������������� ������ ����� � ��������� �� 2", CMD_POW_TWO),
		MenuItem("���������� ������� �� ������� - ������������� � ������ �������", CMD_SORT_BY_POS),
		MenuItem("���������� ������� �� ��������", CMD_SORT_BY_DECR),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� 1. ������������ ���������� �� �������", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
			// ����������� ������� ���������� ������������� �������
			case CMD_FILL_VECTOR:
				app.fillVector();
				break;
			// ������ ������� �� ���������������� ������ ����� � ��������� �� 2
			case CMD_POW_TWO:
				app.posTwo();
				break;
			// �������������� ������� �� ������� - ������������� � ������ �������
			case CMD_SORT_BY_POS:
				app.sortByPos();
				break;			
			// ���������� ������� �� ��������
			case CMD_SORT_BY_DECR:
				app.sortByDecr();
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

// ����������� ������� ���������� ������������� �������
void App::fillVector()
{
	// ������������ ������ �� ��������� ������������ �����, �������� ���������
	// ������� � ����������.��������� ������ � ��������������� ������ ������ ��� ������
	// ���������� ���������

	showNavBarMessage(hintColor, "����������� ������� ���������� ������������� �������");

	// ����� ������� 
	showVector(sourceVec_, "������", "����� �����������", GREEN_ON_BLACK);

	// �������� �������� 
	double min, max;

	// ���� �� ���������
	short cl = getColor();

	setColor(YELLOW_ON_BLACK);

	// ���� ������� ������� 
	showInputLine("\n\n\t������� �������� �������� (�����������/������������): ", 10, hintColor);

	// �������� ������� 
	setCursorVisible(true);

	// ���� ������ 
	cin >> min >> max;

	// ��������� ����� 
	setColor(cl);

	// ���������� ������� 
	setCursorVisible(false);

	// ���� ������ �����������
	if (cin.fail())
	{
		// �������� ������ ����� 
		cin.rdbuf()->in_avail();

		throw exception("������ �����������!");
	}
	if (min > max)
	{
		throw exception("������ �����������!");
	}
	
	// ������ ������� 
	const int N_VECTOR = 14;

	// ��������� ������ ��� ����������� 
	sourceVec_ = vector<double>(N_VECTOR);

	// ����������� ������� 
	generate(sourceVec_.begin(), sourceVec_.end(), func_fill_vec(min, max));

	// ����� ������� 
	showVector(sourceVec_, "������", "����� �����������", GREEN_ON_BLACK);

	// ���������� � ���� 
	saveTextVector(sourceVec_, nameTextFile_);

	// �������� ������� �� ����� 
	loadTextVector(sourceVec_, nameTextFile_);

	// ����� ������� 
	showVector(sourceVec_, "������ �� �����"s + nameTextFile_, "����� �������� �� �����", GREEN_ON_BLACK);

	getKey();

} // App::fillVector()

// ������ ������� �� ���������������� ������ ����� � ��������� �� 2
void App::posTwo()
{
	// ��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
	// �������� ��� �������� ������� �� 2. ��������� ������ � ��������������� ������ ������
	// ��� ������ ���������� ���������

	showNavBarMessage(hintColor, "������ ������� �� ���������������� ������ ����� � ��������� �� 2");

	// �������� ����� 
	loadTextVector(sourceVec_, nameTextFile_);

	// ����� ������� 
	showVector(sourceVec_, "������ �� �����"s + nameTextFile_, "�� ���������", GREEN_ON_BLACK);

	// ��������� �������� ������� �� 2
	for_each(sourceVec_.begin(), sourceVec_.end(), func_power(2));

	cout << "\n\n\n";

	// ����������� � ��������� ���� 
	saveTextVector(sourceVec_, nameTextFile_);

	// �������� ����� 
	loadTextVector(sourceVec_, nameTextFile_);

	// ����� ������� 
	showVector(sourceVec_, "������ �� �����"s + nameTextFile_, "����� �����������", GREEN_ON_BLACK);

	getKey();

} // App::posTwo()

// �������������� ������� �� ������� - ������������� � ������ �������
void App::sortByPos()
{
	// ��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
	// ����������� ������ �� ������� � ������������� � ������ �������. ������� ������ �
	// �������� ���������� ������������� ���������

	showNavBarMessage(hintColor, "�������������� ������� �� ������� - ������������� � ������ �������");

	// �������� ����� 
	loadTextVector(sourceVec_, nameTextFile_);

	// ����� ������� 
	showVectorColor(sourceVec_, "������ �� ����� "s + nameTextFile_, "�� ����������", GREEN_ON_BLACK, RED_ON_BLACK);

	// ���������� ������� 
	// greater<double> pred;
	sort(sourceVec_.begin(), sourceVec_.end(), pred_positive_vector());

	// ���������� � ����
	saveTextVector(sourceVec_, nameTextFile_);

	// �������� ����� 
	loadTextVector(sourceVec_, nameTextFile_);

	cout << "\n\n\n";

	// ����� ������� 
	showVectorColor(sourceVec_, "������ �� ����� "s + nameTextFile_, "����� ����������", GREEN_ON_BLACK, RED_ON_BLACK);

	getKey();

} // App::sortByPos()

// ���������� ������� �� ��������
void App::sortByDecr()
{
	// ��������� ������ �� ���������������� ������ ����� ��� ������ ���������� ���������.
	// ����������� ������ �� ��������. ������� ������ � �������� ���������� �������������
	// ���������

	showNavBarMessage(hintColor, "���������� ������� �� ��������");

	// �������� ����� 
	loadTextVector(sourceVec_, nameTextFile_);

	// ����� ������� 
	showVectorColor(sourceVec_, "������ �� ����� "s + nameTextFile_, "�� ����������", RED_ON_BLACK, GREEN_ON_BLACK);

	// ���������� ������� 
	greater<double> pred_decr;
	sort(sourceVec_.begin(), sourceVec_.end(), pred_decr);

	// ���������� � ����
	saveTextVector(sourceVec_, nameTextFile_);

	// �������� ����� 
	loadTextVector(sourceVec_, nameTextFile_);

	cout << "\n\n\n";

	// ����� ������� 
	showVectorColor(sourceVec_, "������ �� ����� "s + nameTextFile_, "����� ����������", RED_ON_BLACK, GREEN_ON_BLACK);

	getKey();



} // App::sortByDecr()

// ���������� ������� � ��������� ����
void App::saveTextVector(vector<double>& vec, string nameFile)
{
	// ��������������� ����� ������
	ofstream file(nameFile, ios::out);

	// ���� ���� �� ������� �������
	if (!file.is_open())
		throw exception(("����"s + nameFile + "�� ������� �������!").c_str());

	// ���������� � ���� � ������� ��������� ������ ������
	ostream_iterator<double> stream(file, "\n");

	// ������ � ���� � ������� ��������� 
	for_each(vec.begin(), vec.end(), func_save_text_vec(stream));

	// �������� ������ ������ 
	file.close();
} // App::saveTextVector(vector<double>& vec, string nameFile)

// �������� ������� �� ���������� ����� 
void App::loadTextVector(vector<double>& vec, string nameFile)
{
	// �������� ������ ����� �� ����� 
	ifstream file(nameFile);

	// �������� �� ������ ����� 
	istream_iterator<double> it(file);

	// �������� ������� 
	sourceVec_.clear();

	// ���� �� ����� 
	while (!file.eof())
	{
		// ���������� �������� � ������ 
		vec.push_back(*it++);
	}

	// �������� ������ ����� 
	file.close();
} // loadTextVector(vector<double>& vec, string nameFile)

// ����� ������� � ���������� ������������� ���������
void App::showVector(vector<double>& vec, string name, string specific, short colorElem)
{
	// ������ ������� 
	int n = vec.size();

	// ������� ����
	short cl = getColor();

	cout << "    +������������+������������������������������������������������+������������������������������������������������+\n"
		<< "    | ������: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | ��� ������: " << left << color(YELLOW_ON_BLACK) << setw(34) << name << color(cl)
		<< " | ��������: " << color(YELLOW_ON_BLACK) << setw(36) << specific << color(cl) << right << " |\n";

	// ����� �������������� �����
	showLineVector();

	// ���� � ������� ��� ������
	if (vec.empty())
	{
		showEmptyVector();
		showLineVector();
		return;
	}

	cout << "    |  ��������  |";

	cout.precision(1);

	// ����� ��������� 
	for (auto item : vec)
	{
		// ����� �������� 
		cout << color(colorElem) << setw(5) << item << color(cl) << " |";
	}

	cout << "\n";

	// ����� �������������� �����
	showLineVector();
} // App::showVector(vector<double>& vec, string name, string specific, short colorElem)

// ����� ������� � ���������� ������������� ���������
void App::showVectorColor(vector<double>& vec, string name, string specific, short colorElem, short backlight)
{
	// ������ ������� 
	int n = vec.size();

	// ������� ����
	short cl = getColor();

	cout << "    +������������+������������������������������������������������+������������������������������������������������+\n"
		<< "    | ������: " << color(GREEN_ON_BLACK) << setw(2) << n << color(cl)
		<< " | ��� ������: " << left << color(YELLOW_ON_BLACK) << setw(34) << name << color(cl)
		<< " | ��������: " << color(YELLOW_ON_BLACK) << setw(36) << specific << color(cl) << right << " |\n";

	// ����� �������������� �����
	showLineVector();

	// ���� � ������� ��� ������
	if (vec.empty())
	{
		showEmptyVector();
		showLineVector();
		return;
	}

	cout << "    |  ��������  |";

	cout.precision(1);

	// ����� ��������� 
	for (auto item : vec)
	{
		// ���� ��� ������ 
		short colOut = item >= 0 ? backlight : colorElem;

		// ����� �������� 
		cout << color(colOut) << setw(5) << item << color(cl) << " |";
	}

	cout << "\n";

	// ����� �������������� �����
	showLineVector();
} // App::showVector(vector<double>& vec, string name, string specific, short colorElem)

// ����� ����� ��� �������
void App::showLineVector()
{
	cout << "    +������������+������+������+������+������+������+������+������+������+������+������+������+������+������+������+\n";
} // App::showLineVector()

// ����� ��������� �� �������� ������ ��� �������
void App::showEmptyVector()
{
	// ������� ����
	short cl = getColor();

	cout << "    |  " << color(LTRED_ON_BLACK)
		<< "                                                 ��� ������                                                "
		<< color(cl) << " | \n";
} // App::showEmptyVector()

#pragma endregion 

#pragma region ������� 2. ���������� ����

/*
*	������ 2. �������� � ������ �������� ��������: ��������������� ����� ��������, �������
*	� ����������������, ����������� ����� ��������, ����������� ����� ��������.
*
*	���������� � ����� � ������ ������� � ������� �0�, � ������ ������ �������� ������ ���
*	�����, ��� � �����, �������� � �42�, �42�, �32�.��������� ������ ��������� �� ������
*	vector. ������� ��������� � ��������������� ������ ������, ������/������ ����� ����������
*	��� ������ ���������� ���������. ��� ������ ������� ���������� �������� ��������� ������
*	� ���� �� ������� ������������ ��������.
*
*	��������� ������ ������������ ����� � ������� ���� � ���������� ����� �� ��������� �������:
*	�	������ ������ �� ��������� � ��������� ���� (��������������� ����� ������)
*	�	������ ������ �� ��������� �� ���������� ����� (���������������� ������ �����)
*	�	����� ������ �� ��������� ��� ������ ��������� for_each()� ���������� ��������
*	�	����������� ��������� ��������� �� ��������������� ������� ��� ������ ��������� sort()
*		� ���������� �������� � �����������;
*	�	����������� ��������� ��������� �� ������� � ��������� �������� ��� ������ ��������� sort()
*		� ���������� �������� � �����������;
*	������������ ������ � �������� ������������� ������ � ����������� ����������� ��������� STL.
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
		// ������ ������ �� ��������� � ��������� ����
		CMD_SAVE_FILE,
		// ������ ������ �� ��������� �� ���������� �����
		CMD_LOAD_FILE,
		// ����� ������ �� ���������
		CMD_PRINT_ALL,
		// ���������� ��������� ��������� �� ��������������� �������
		CMD_SORT_BY_NUMBER,
		// ���������� ��������� ��������� �� ������� � ��������� ��������
		CMD_SORT_BY_NAME
	};

	// ���������� ������� ����
	const int N_MENU = 7;

	MenuItem items[N_MENU] = {
		MenuItem("��������� ������������ ��������� ������ ��� ���� ���������", CMD_CREATE_PARK),
		MenuItem("������ ������ �� ��������� � ��������� ����", CMD_SAVE_FILE),
		MenuItem("������ ������ �� ��������� �� ���������� �����", CMD_LOAD_FILE),
		MenuItem("����� ������ �� ���������", CMD_PRINT_ALL),
		MenuItem("���������� ��������� ��������� �� ��������������� �������", CMD_SORT_BY_NUMBER),
		MenuItem("���������� ��������� ��������� �� ������� � ��������� ��������", CMD_SORT_BY_NAME),

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

				// ������ ������ �� ��������� � ��������� ����
			case CMD_SAVE_FILE:
				app.saveBusFile();
				break;

				// ������ ������ �� ��������� �� ���������� �����
			case CMD_LOAD_FILE:
				app.loadBusFile();
				break;

				// ����� �������� ��� ���� ���������
			case CMD_PRINT_ALL:
				app.printAll();
				break;

				// ���������� ��������� ��������� �� ��������������� �������
			case CMD_SORT_BY_NUMBER:
				app.sortByNumber();
				break;

				// ���������� ��������� ��������� �� ������� � ��������� ��������
			case CMD_SORT_BY_NAME:
				app.sortByName();
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
	showBus(buses_, "��� ��������", "�� ����������");

	// ���� ����� �� ���������� 
	if (!isFile(busText_))
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
		for_each(busList, busList + SIZE_ARR, func_fill_bus(buses_));

		// ���������� � ���� 
		saveBus(buses_, busText_);
	}

	// �������� �� �����
	loadBus(buses_, busText_);

	cout << endl;

	// ����� ���������
	showBus(buses_, "��� ��������", "����� �������� �����");

	cout << "\n\n\n";

	getKey();


} // App::createPark()

// ����� �������� ��� ���� ���������
void App::printAll()
{
	cls();

	showNavBarMessage(hintColor, "����� �������� ��� ���� ���������");

	// ����� ���������
	showBus(buses_, "��� ��������", "����� �������� �����");

	getKey();

} // App::printAll()

// ������ ������ �� ��������� � ��������� ����
void App::saveBusFile()
{
	cls();

	showNavBarMessage(hintColor, "������ ������ �� ��������� � ��������� ����");

	// ����� ���� ���������
	showBus(buses_, "������ ���������", "�� ���������� � ����");

	// ���������� � ����
	saveBus(buses_, busText_);

	// �������� �� �����  
	loadBus(buses_, busText_);

	cout << "\n\n\n";

	// ����� ���� ���������
	showBus(buses_, "������ ���������", "����� ����������");
	
	cout << "\n\n";

	getKey();
}

// ������ ������ �� ��������� �� ���������� �����
void App::loadBusFile()
{
	cls();

	showNavBarMessage(hintColor, "������ ������ �� ��������� � ��������� ����");

	// ����� ���� ���������
	showBus(buses_, "������ ���������", "�� �������� �����");

	// �������� �� �����  
	loadBus(buses_, busText_);

	cout << "\n\n\n";

	// ����� ���� ���������
	showBus(buses_, "������ ���������", "����� �������� �����");

	cout << "\n\n";

	getKey();

}

// ���������� ��������� ��������� �� ��������������� �������
void App::sortByNumber()
{
	cls();

	showNavBarMessage(hintColor, "���������� ��������� ��������� �� ��������������� �������");

	// ����� ���������
	showBus(buses_, "��� ��������", "�� ����������");

	cout << "\n\n\n";

	// ���������� 
	sort(buses_.begin(), buses_.end(), func_comp_by_number());

	// ���������� � ����
	saveBus(buses_, busText_);

	// �������� �� �����
	loadBus(buses_, busText_);

	// ����� ���������
	showBus(buses_, "��� ��������", "����� ����������");

	cout << "\n\n\n";


	getKey();

}

// ���������� ��������� ��������� �� ������� � ��������� ��������
void App::sortByName()
{
	cls();

	showNavBarMessage(hintColor, "���������� ��������� ��������� �� ������� � ��������� ��������");

	// ����� ���������
	showBus(buses_, "��� ��������", "�� ����������");

	// ���������� 
	sort(buses_.begin(), buses_.end(), func_comp_by_name());

	cout << "\n\n\n";

	// ���������� � ����
	saveBus(buses_, busText_);

	// �������� �� �����
	loadBus(buses_, busText_);

	// ����� ���������
	showBus(buses_, "��� ��������", "����� ����������");

	cout << "\n\n\n";

	getKey();

}

// ����� map ���������
void App::showBus(vector<Bus>& vecBus, string name, string specific)
{
	// ����� ����� �������
	showHeadBus(vecBus, name, specific);

	// ���� map ������ 
	if (vecBus.empty())
		showEmptyBus();

	// ����� ��������� 
	showBusElem(vecBus);

	// ����� ����� ����������� 
	showLineBus();

} // App::outBus()

// ����� ����� �������
void App::showHeadBus(vector<Bus>& vecBus, string name, string specific)
{
	// ������� ����
	short cl = getColor();

	cout << "    +������������+���������������������������������+���������������������������������+\n"
		<< "    | ������: " << left << color(GREEN_ON_BLACK) << setw(2) << vecBus.size()
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
void App::showBusElem(vector<Bus>& vecBus)
{
	// ����� ���� ��������� � ������� ���������� �������� � ����� for_each
	for_each(vecBus.begin(), vecBus.end(), func_out_bus());
} // showBusElem()

// ���������� vector � ���� 
void App::saveBus(vector<Bus>& vecBus, string nameFile)
{
	// ������� ����� � ������ �������� ������
	ofstream file(nameFile, ios::out);

	// ���������� � ����
	for_each(vecBus.begin(), vecBus.end(), func_save_bus(file));

	file.close();
}

// �������� vector �� ����� 
void App::loadBus(vector<Bus>& vecBus, string nameFile)
{
	vecBus.clear();

	// ������� ����� � ������ �������� ������
	ifstream file(nameFile);

	Bus temp;

	istream_iterator<Bus> it(file);

	while (!file.eof())
	{
		// ���������� � ����� ����
		vecBus.push_back(*it++);
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

#pragma endregion
