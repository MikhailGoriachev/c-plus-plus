#include "App.h"

/*
	������ 1.
		���������� ����� Person, �������������� ������ � ������ ���������� ������,
		���� ������ �������, ���, �������� (��� ��� ���� ���� char *), ����� 
		����������� (��� double), ��� � ����������� (��� double), ����� ����������
		(��� char *).
		�������� ������ ��������� ������ ����������� ������ DblList<Person>, �� 
		����� 12 �����. ����������� ��������� (��� ������ ���������):
		�	�������� ��� ������� ������ �� ��������� ��������� �������� (��� �������
			������ �������� ����, �� �� ����� 0.5% �� ���� ������)
		�	����������� � ��������� ������ DblList<Person> ������� ��������� ������,
			�������� ������ ������� � ����������

	������ 2.
		� �������������� ���������� ������ ������� � ���������� ����������� �������
		����������� � ��������� �������� �������. ���������� ������� �� ��������, ��
		����� 10 ��������� � �������.
		������� ������� ������ ������� �������, ��� � �������� �����������, 
		���������� ������ �����, ������� �������� � �2, ���������� ������, ���� 
		���������� �� ���� (����, �����, �������� Date). ������� ����� ��������, 
		������ ��� ��������� ����� ��� ������.

		����������� ������������� �������� (��� ������ ����������):

		�	����������� � ���������� ������ (��������� ����� DblList<>�� ���������� 
			�������) ��� ������ ������������������ � ��������� �������� ������� � 
			�������� ����������� ������. ���������� ������ ������� � ����������
		�	����������� � ������ ������� ����������� � ��������� �������� ������� 
			������ �������� ������� � �������� ���������� ������� ��������. �������� 
			�������� ������� � ����������
*/

#pragma region ������ 1. ������ � ������ ������

/*
	������ 1.
		���������� ����� Person, �������������� ������ � ������ ���������� ������,
		���� ������ �������, ���, �������� (��� ��� ���� ���� char *), ���� �
		����������� (��� double), ��� � ����������� (��� double), ����� ����������
		(��� char *).
		�������� ������ ��������� ������ ����������� ������ DblList<Person>, ��
		����� 12 �����. ����������� ��������� (��� ������ ���������):
		�	�������� ��� ������� ������ �� ��������� ��������� �������� (��� �������
			������ �������� ����, �� �� ����� 0.5% �� ���� ������)
		�	����������� � ��������� ������ DblList<Person> ������� ��������� ������,
			�������� ������ ������� � ����������
*/

// ������ 1. ������ � ������ ������
void App::task1()
{
	init(L"������ 1. ������ � ������ ������");

	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// �������� ��� ������� ������ �� ��������� ��������� ��������
		CMD_ADD_WEIGHT,
		// ����������� � ��������� ������ ������� ��������� ������
		CMD_COPY_CITY,
	};

	// ���������� ������� ����
	const int N_MENU = 3;

	MenuItem items[N_MENU] = {
		MenuItem("�������� ��� ������� ������ �� ��������� ��������� ��������", CMD_ADD_WEIGHT),
		MenuItem("����������� � ��������� ������ ������� ��������� ������", CMD_COPY_CITY),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������ 1. ������ � ������ ������", items, N_MENU, palette, COORD{ 5, 5 });

	// ����������� ����������������
	// Person(const char* surname, const char* name, const char* patronymic, double height, double weight, const char* city)

	// ������������� ������ � �������� 
	// Person persons[12]
	// {
	// 	Person("������", "���������", "����������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "������"),
	// 	Person("���������", "��������", "���������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "�����"),
	// 	Person("��������", "�������", "���������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "��������"),
	// 	Person("�����", "�������", "��������������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "������"),
	// 	Person("������", "���������", "����������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "�����"),
	// 	Person("���������", "�������", "���������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "���������"),
	// 	Person("���������", "���", "��������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "��������"),
	// 	Person("������", "�������", "��������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "���������"),
	// 	Person("������", "�����", "����������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "������"),
	// 	Person("�������� ", "����", "������������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "��������"),
	// 	Person("�����������", "��������", "����������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "������"),
	// 	Person("��������", "���������", "��������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "���������")
	// };

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// �������� ��� ������� ������ �� ��������� ��������� ��������
			case CMD_ADD_WEIGHT:
				app.taskOneAddWeight();
				break;
				// ����������� � ��������� ������ ������� ��������� ������
			case CMD_COPY_CITY:
				app.taskOneCopyCity();
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


// �������� ��� ������� ������ �� ��������� ��������� ��������
void App::taskOneAddWeight()
{
	cls();

	showNavBarMessage(hintColor, "�������� ��� ������� ������ �� ��������� ��������� ��������");

	// �������� ������ 
	DblList<Person>::Iterator<Person> iterat(listPerson_);

	cputs("\n    ����������������������������������������������� �� ��������� �����������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �� ��������� ����
	printDblQueue(iterat);

	// ��������� ���� ������� ������ �� ��������� �������� �� 0,5% �� ��� �������� ����
	for (iterat.begin(); iterat != iterat.end(); ++iterat)
	{
		// ������ �� ������� ������ Person
		Person& tmp = *iterat;

		// ������� ��� 
		double weight = tmp.getWeight();

		// ��������� ���� �� ����� ��� �� 0,5%
		tmp.setWeight(weight + getRand(0., weight * 0.005));
	}

	cputs("\n    ��������������������������������������������� ����� ��������� ����������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� ����� ��������� ����
	printDblQueue(iterat);

	getKey();
}


// ����������� � ��������� ������ ������� ��������� ������
void App::taskOneCopyCity()
{
	cls();

	showNavBarMessage(hintColor, "�������� ��� ������� ������ �� ��������� ��������� ��������");

	// �������� ������ 
	DblList<Person>::Iterator<Person> iterat(listPerson_);

	// �������������� ������
	DblList<Person> result;

	cputs("\n    ���������������������������������������������� �������� ������ ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� ������
	printDblQueue(iterat);

	// �������� ������ ��� �����������
	char* city = new char[Person::CITY_MAX_SIZE + 1];

	// ��������� �������
	setCursorVisible(true);

	// ���� �������� ������
	cout << color(CYAN_ON_BLACK) << "\n\n\t������� �������� ������: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(city, Person::CITY_MAX_SIZE);

	// ���������� �������
	setCursorVisible(false);

	cout << "\n\n\n";

	cputs("\n    ������������������������������������������� �������������� ������ ������������������������������������������\n", YELLOW_ON_BLACK);

	// ��������� ��������������� ������
	selectionTaskOne(city, iterat, result);

	// �������� ��������������� ������ 
	DblList<Person>::Iterator<Person> iteratRes(result);

	// ����� ������
	printDblQueue(iteratRes);

	getKey();
}


// �������� ��������������� ������ �� �������� ������
// ���� ����� �� ������ � ������, �� ����� ��������� false
bool App::selectionTaskOne(char* city, DblList<Person>::Iterator<Person> iterat, DblList<Person>& result)
{
	bool flag = false;

	for (iterat.begin(); iterat != iterat.end(); ++iterat)
	{
		// ������� ������
		Person& tmp = *iterat;

		// ���� ���� ������ ������������� �������
		if (strcmp(city, tmp.getCity()) == 0)
		{
			flag = true;
			result.add(tmp);
		}
	}

	return flag;
}


// ����� �������
void App::printDblQueue(DblList<Person>::Iterator<Person> iterator)
{
	// Person(const char* surname, const char* name, const char* patronymic, double height, double weight, const char* city)
	// 	Person("������", "���������", "����������", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "������"),
	//        |  N | ������               | ���������            | ����������           | 172.12 | 171.64 |        ������        |
	cout<< " +����+����������������������+����������������������+����������������������+���������+���������+��������������������+\n"
		<< " |  N |        �������       |         ���          |       ��������       |   ����  |   ���   |        �����       |\n"
		<< " |    |                      |                      |                      |    ��   |    ��   |                    |\n"
		<< " +����+����������������������+����������������������+����������������������+���������+���������+��������������������+\n";
	if (iterator.end() == 0)
		cputs(" |                                                   ������� �����                                                  |\n", RED_ON_BLACK);

	// ����� ��������
	int i = 1;

	// ���� �� ���������
	short cl = getColor();

	// ���������� ������ ����� �����
	cout << fixed;
	cout.precision(2);

	// ����� � ������� ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		cout << " | " << color(CYAN_ON_BLACK) << setw(2) << i++
			<< left << color(cl) << " | "
			<< setw(Person::SURNAME_MAX_SIZE - 30) << color(YELLOW_ON_BLACK) << (*iterator).getSurname()
			<< color(cl) << " | "
			<< setw(Person::NAME_MAX_SIZE - 20) << color(YELLOW_ON_BLACK) << (*iterator).getName()
			<< color(cl) << " | "
			<< setw(Person::PATRONYMIC_MAX_SIZE - 30) << color(YELLOW_ON_BLACK) << (*iterator).getPatronymic()
			<< color(cl) << " | " << right
			<< setw(7) << color(GREEN_ON_BLACK) << (*iterator).getHeight()
			<< color(cl) << " | "
			<< setw(7) << color(GREEN_ON_BLACK) << (*iterator).getWeight()
			<< color(cl) << " | "
			<< setw(18) << color(GREEN_ON_BLACK) << (*iterator).getCity()
			<< color(cl) << " |\n";
	}

	cout << " +����+����������������������+����������������������+����������������������+���������+���������+��������������������+\n";
}

#pragma endregion

#pragma region ������ 2. ������� ����������� � ��������� �������� �������

/*
	������ 2.
		� �������������� ���������� ������ ������� � ���������� ����������� �������
		����������� � ��������� �������� �������. ���������� ������� �� ��������, ��
		����� 10 ��������� � �������.
		������� ������� ������ ������� �������, ��� � �������� �����������,
		���������� ������ �����, ������� �������� � �2, ���������� ������, ����
		���������� �� ���� (����, �����, �������� Date). ������� ����� ��������,
		������ ��� ��������� ����� ��� ������.

		����������� ������������� �������� (��� ������ ����������):

		�	����������� � ���������� ������ (��������� ����� DblList<>�� ����������
			�������) ��� ������ ������� ����������� � ��������� �������� ������� �
			�������� ����������� ������. ���������� ������ ������� � ����������
		�	����������� � ������ ������� ����������� � ��������� �������� �������
			������ �������� ������� � �������� ���������� ������� ��������. ��������
			�������� ������� � ����������
*/

// ������ 2. ������� ����������� � ��������� �������� �������
void App::task2()
{
	init(L"������ 2. ������� ����������� � ��������� �������� �������");

	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ����������� � ��������� ������ �� ��������� ���������� ������
		CMD_COPY_ROOM,
		// ����������� � ��������� ������ �� ��������� ��������� �������
		CMD_COPY_AREA,
	};

	// ���������� ������� ����
	const int N_MENU = 3;

	MenuItem items[N_MENU] = {
		MenuItem("����������� � ��������� ������ �� ��������� ���������� ������", CMD_COPY_ROOM),
		MenuItem("����������� � ��������� ������ �� ��������� ��������� �������", CMD_COPY_AREA),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������ 2. ������� ����������� � ��������� �������� �������", items, N_MENU, palette, COORD{ 5, 5 });


	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// ����������� � ��������� ������ ���� ����������� � �������� ����������� ������
			case CMD_COPY_ROOM:
				app.copyByRoom();
				break;
				// ����������� � ��������� ������ �� ��������� ��������� �������
			case CMD_COPY_AREA:
				app.copyByArea();
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


// ����������� � ��������� ������� ���� ����������� � �������� ����������� ������
void App::copyByRoom()
{
	cls();

	showNavBarMessage(hintColor, "����������� � ��������� ������ ���� ����������� � �������� ����������� ������");

	// �������� ��� �������� �������
	Queue<Form>::Iterator<Form> iterSource(forms_);

	// �������������� �������
	Queue<Form> result;

	// �������� ��� �������������� �������
	Queue<Form>::Iterator<Form> iterResult(result);

	cputs("\n    ��������������������������������������������� �������� ������� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������� �������
	printQueue(iterSource);

	// ��������
	int min, max;

	// ���� ���������
	cputs("\n\t������� �������� ���������� ������ (���/����): ", CYAN_ON_BLACK);
	setCursorVisible(true);
	min = getInt("");
	max = getInt("");
	setCursorVisible(false);

	// ���� �������� ������������� ��� ������� ������ ���������
	if (min < 0 or max < 0 or min > max)
		throw exception("App: ������������ �������� ������ ���������!");

	// ����������� ���� ����� �� ����������� ���������� ������
	copyResultByRoom(iterSource, result, min, max);

	cputs("\n    ������������������������������������������ �������������� ������� ������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������������� �������
	printQueue(iterResult);

	cout << "\n\n\n";

	getKey();
}


// ����������� � �������������� ������� �� ���������� ������
// ���������� false ���� ��� ����������
bool App::copyResultByRoom(Queue<Form>::Iterator<Form> iter, Queue<Form>& result, int min, int max)
{
	// ���� ���������� ���� �� ������ ���������������� �������
	bool flag = false;

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		// ������� ������
		Form tmp = *iter;

		// ������� ���������� ������
		int countRoom = tmp.getCountRoom();

		// ���� ���������� ������ ������ � ��������
		if (countRoom >= min and countRoom <= max)
		{
			result.enqueue(tmp);
			flag = true;
		}
	}

	return flag;
}


// ����������� � ��������� ������� �� ��������� ��������� �������
void App::copyByArea()
{
	cls();

	showNavBarMessage(hintColor, "����������� � ��������� ������� �� ��������� ��������� �������");

	// �������� ��� �������� �������
	Queue<Form>::Iterator<Form> iterSource(forms_);

	// �������������� �������
	Queue<Form> result;

	// �������� ��� �������������� �������
	Queue<Form>::Iterator<Form> iterResult(result);

	cputs("\n    ��������������������������������������������� �������� ������� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������� �������
	printQueue(iterSource);

	// ��������
	double min, max;

	// ���� ���������
	cputs("\n\t������� �������� ������� �������� (���/����): ", CYAN_ON_BLACK);
	setCursorVisible(true);
	//cin >> min >> max;
	min = getInt("");
	max = getInt("");
	setCursorVisible(false);

	// ���� �������� ������������� ��� ������� ������ ���������
	if (min < 0 or max < 0 or min > max)
		throw exception("App: ������������ �������� ������ ���������!");

	// ����������� ���� ����� �� ����������� �������
	copyResultByArea(iterSource, result, min, max);

	cputs("\n    ������������������������������������������ �������������� ������� ������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������������� �������
	printQueue(iterResult);

	cout << "\n\n\n";

	getKey();

}


// ����������� � �������������� ������� �� �������
// ���������� false ���� ��� ����������
bool App::copyResultByArea(Queue<Form>::Iterator<Form> iter, Queue<Form>& result, double min, double max)
{
	// ���� ���������� ���� �� ������ ���������������� �������
	bool flag = false;

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		// ������� ������
		Form tmp = *iter;

		// ������� ������� 
		int area = tmp.getArea();

		// ���� ������� ������ � ��������
		if (area >= min and area <= max)
		{
			result.enqueue(tmp);
			flag = true;
		}
	}

	return flag;
}


// ����� �������
void App::printQueue(Queue<Form>::Iterator<Form> iterator)
{
	// 		Person("�����������", "��������", "����������", 1, getRand(36., 42.), 3, Date(3, 7, 2005)),
	//       | ������               | ���������            | ����������           |   3    | 71.64068 | 15.12.2003 |
	cout << "\t+����+����������������������+����������������������+����������������������+��������+���������+������������+\n"
		<< "\t|  N |        �������       |         ���          |       ��������       |  ����� | ������� |    ����    |\n"
		<< "\t|    |                      |                      |                      |   ���. |   �2    |   �������. |\n"
		<< "\t+����+����������������������+����������������������+����������������������+��������+���������+������������+\n";
	if (iterator.end() == 0)
		cputs("\t|                                             ������� �����                                               |\n", RED_ON_BLACK);

	// ���� �� ���������
	short cl = getColor();

	// ����� ��������
	int i = 1;

	// ����� � ������� ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{

		cout << fixed;
		cout.precision(2);

		cout << "\t| " << color(CYAN_ON_BLACK) << setw(2) << i++
			<< left << color(cl) << " | " << setw(Person::SURNAME_MAX_SIZE - 30) 
			<< color(YELLOW_ON_BLACK) << (*iterator).getSurname() 
			<< color(cl) << " | "
			<< setw(Person::NAME_MAX_SIZE - 20) 
			<< color(YELLOW_ON_BLACK) << (*iterator).getName()
			<< color(cl) << " | "
			<< setw(Person::PATRONYMIC_MAX_SIZE - 30) 
			<< color(YELLOW_ON_BLACK) << (*iterator).getPatronymic()
			<< color(cl) << " | " << right
			<< setw(6) 
			<< color(GREEN_ON_BLACK) << (*iterator).getCountFamily() 
			<< color(cl) << " |   "
			<< setw(4) 
			<< color(GREEN_ON_BLACK) << (*iterator).getArea()
			<< color(cl) << " | "
			<< setw(15) 
			<< color(GREEN_ON_BLACK) << (*iterator).getDate()
			<< color(cl) << " |\n";

		// cputs(oss.str().c_str(), CYAN_ON_BLACK);
	}

	cout << "\t+����+����������������������+����������������������+����������������������+��������+���������+������������+\n";
}


#pragma endregion
