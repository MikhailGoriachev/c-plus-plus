#include "App.h"
#include "DblList.h"
#include "Person.h"
#include "Queue.h"

//#include 

/*
		������ 1.
	������������ ��������������� �������� ��� ������������ ������ � ���������� ������ 
	DblList �� ����������� �������. ����������������� ������ ���������, �� ���������� 
	����������� ������, ��������� ����� int.
	�������� ���������:
	�	begin()������� ��������� �� ������ ����������, ���������� 0
	�	end()������� ��������� � ����� ����������, ���������� �������, ��������� �� 
		��������� ��������� ��������
	�	*������������� ���������, ���������� ������ �� ��������, �������� � ��������,
		�� ������� ��������� ��������
	�	++ ������ ���������� ���������, ������� � ���������� �������� ����������
	�	-- ������ ���������� ���������, ������� � ����������� �������� ����������
	�	T get() ��������� ��������, ��������� � ��������, �� ������� ��������� ��������,
		������ �� ������
	�	void put(T value) ������ ������ �������� � ������� ����������, �� ������� 
		��������� ��������, ������ �� ������

		������ 2.
	� �������������� ���������� ������ ����� � ���������� ��������� ������������ 
	����������� ������ � ������ ��������.
	C����� ��������� �� ���������� �����, ����� ������ �� ��������� 80 �������� 
	(�� ������������ ������� ������� ������).� ����� �� ����� 3� �����.
	���� ������: () [] {}
	������ �����:
	( ��� ( ����� { ���� [](������������) ����� { �������� }[ �����]})) - ���������
	����������� ������
	({)[()]} � ����������� ����������� ������
	�������� ���������� � ������� � ������ ��� ���������, ���� � ������ � �������, 
	���������������� ��������, ����� ����������� ������ ������ ���������� �������� ^.

		������ 3.
	� �������������� ���������� ������ ������� � ���������� ����������� ������� 
	����������� � ��������� �������� �������. ���������� ������� �� ��������, �� 
	����� 10 ��������� � �������.
	������� ������� ������ ������� �������, ��� � �������� �����������, ����������
	������ �����, ������� �������� � �2, ���������� ������, ���� ���������� �� ����
	(����, �����, �������� Date). ������� ����� ��������, ������ ��� ��������� �����
	��� ������.
	����������� ������������� �������� (��� ������ ����������):
	�	����� � ������� �� ������� � ������� ������ ���������� �������, ��������� 
		������������� ������������
	�	����������� ���� �������� � ����� �������. �����������, ����������� � �����
		�������� �������� � �������� ������� ������ ���� ���.��� �������������� �������
		������ ����:����������� ��������1� � ��������2�.
*/


#pragma region ������ 1. ��������

/*
	������ 1.
	������������ ��������������� �������� ��� ������������ ������ � ���������� ������
	DblList �� ����������� �������.����������������� ������ ���������, �� ����������
	����������� ������, ��������� ����� int.
	�������� ��������� :
	�	begin()������� ��������� �� ������ ����������, ���������� 0
	�	end()������� ��������� � ����� ����������, ���������� �������, ��������� ��
	��������� ��������� ��������
	�* ������������� ���������, ���������� ������ �� ��������, �������� � ��������,
	�� ������� ��������� ��������
	�	++ ������ ���������� ���������, ������� � ���������� �������� ����������
	�	-- ������ ���������� ���������, ������� � ����������� �������� ����������
	�	T get() ��������� ��������, ��������� � ��������, �� ������� ��������� ��������,
	������ �� ������
	�	void put(T value) ������ ������ �������� � ������� ����������, �� �������
	��������� ��������, ������ �� ������
*/

// ������ 1. ��������
void App::task1()
{
	showNavBarMessage(infoColor, "������ 1. ��������");

	// ������ �������
	const int SIZE_ARRAY = 5;

	// ����������� ������ ��������
	int arr[SIZE_ARRAY] = { 11,22,33,44,55 };

	// ���������� ������ ��������
	list_.addAll(arr, SIZE_ARRAY);

	// �������� ��� ������ list_
	DblList<int>::Iterator<int> iterator(list_);

	// ������� ����
	short cl = getColor();

	// ����� ������
	cout << "\n         ����� ������               : " << color(YELLOW_ON_BLACK) << list_ << "\n" 
		 << color(cl)
		 << "\n         ����� ������ ����� ��������: " << color(GREEN_ON_BLACK);

	// ����� ������ ����� ��������
	printListIterator(iterator);

	// ����� ��� put()
	int n = 99;

	// �������� �������
	cout << color(cl)
		<< "\n         ++ ����������              : " << color(GREEN_ON_BLACK) << *(++iterator) << color(cl);
	cout << "\n         -- ���������               : " << color(GREEN_ON_BLACK) << *(--iterator) << color(cl);
	cout << "\n         begin() ���������� ������  : " << color(GREEN_ON_BLACK) << iterator.begin() << color(cl)
		 << "\n         end()   ���������� ������  : " << color(GREEN_ON_BLACK) << iterator.end() << color(cl)
		 << "\n         * �������������            : " << color(GREEN_ON_BLACK) << *iterator << color(cl)
		 << "\n         get()                      : " << color(GREEN_ON_BLACK) << iterator.get() << color(cl)
		 << "\n         ������ �������� ����� put(): �������� " << color(YELLOW_ON_BLACK) << n << color(cl)
		 << "\n         ������ �� put()            : " << color(GREEN_ON_BLACK) << list_ << color(cl);
	
	// put()
	iterator.put(n);

	cout << "\n         ������ ����� put()         : " << color(GREEN_ON_BLACK) << list_ << "\n\n\n" << color(cl);

	getKey();
}

// ����� ������ ����� ��������
void App::printListIterator(DblList<int>::Iterator<int> iterator)
{
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		cout << *iterator << " ";
	}
}

#pragma endregion 

#pragma region ������ 2. �������� ������ �� ������������

/*
			������ 2.
	� �������������� ���������� ������ ����� � ���������� ��������� ������������ 
	����������� ������ � ������ ��������.
	C����� ��������� �� ���������� �����, ����� ������ �� ��������� 80 �������� 
	(�� ������������ ������� ������� ������).� ����� �� ����� 3� �����.
	���� ������: () [] {}
	������ �����:
	( ��� ( ����� { ���� [](������������) ����� { �������� }[ �����]})) - ���������
	����������� ������
	({)[()]} � ����������� ����������� ������
	�������� ���������� � ������� � ������ ��� ���������, ���� � ������ � �������, 
	���������������� ��������, ����� ����������� ������ ������ ���������� �������� ^.
*/

// ������ 2. �������� ������ �� ������������
void App::task2()
{
	cls();

	short cl = getColor();

	showNavBarMessage(infoColor, "������ 2. �������� ������ �� ������������");

	// ��� �����
	char* fileName = new char[_MAX_FNAME + 1]{"test.txt"};

	// ���� ����� ����� 
	// cout << "\t|        ������� ��� �����: ";
	// cin.ignore(cin.rdbuf()->in_avail());
	// cin.getline(fileName, _MAX_FNAME);

	stringstream oss;
	oss << "\n\t\t******  " << "��� �����: " << fileName << "  ******" << "\n";

	cputs(oss.str().c_str(), CYAN_ON_BLACK);

	// �������� ����� � ������ ������
	FILE* file = fopen(fileName, "r");

	// ���� ���� ������ ��������
	if (file == nullptr)
	{
		// ������
		stringstream oss;

		oss << "App: �� ������� ������� ����" << fileName;

		throw exception(oss.str().c_str());
	}

	// ���������� ����� � �������� ����� �� �������
	scanFile(file);

	// �������� ������
	delete[] fileName;

	cout << "\n\n\n";

	getKey();
}

// �������� ����� � ���������� ����������� � ������
void App::scanFile(FILE* file)
{
	// ������ ������ ��� ������
	const int BUFFER_SIZE = 401;

	// ����� ��� ����� 
	char* buffer = new char[BUFFER_SIZE];

	// ������������ ����� ������
	const int MAX_SIZE_STR = 80;

	// ������� ������ � ������
	int errPosition;

	// ������� ���� �������
	short cl = getColor();

	// ����� ������ 
	int numStr = 0;

	// �������� ����� �� �������
	
	// ��������� ��������� � ����� ����� 
	fseek(file, 0, SEEK_END);

	// ���� ����� ����� ����� ����
	if (ftell(file) == 0)
		throw exception("���� ����!");

	// ��������� ��������� � ������ ����� 
	fseek(file, 0, SEEK_SET);

	// ���������� � �������� �����
	while (!feof(file))
	{
		numStr++;

		// �������� ������
		memset(buffer, 0, BUFFER_SIZE - 1);

		// ���������� ������ � �����
		fgets(buffer, BUFFER_SIZE, file);

		// ���� ����� ������ ������ 80
		if (strlen(buffer) > 80)
		{
			//cout << "\n" << buffer;

			cout << "\n" << setw(3) << color(RED_ON_BLACK) << numStr << " | " << buffer
				 << color(errColor) << (buffer[strlen(buffer) - 1] == '\n' ? "\t" : "\n\t")
				<< "App: ������ �� ����������, ��� ��� ������� 80 ��������!" << color(cl);
			continue;
		}

		// ���������� ������ �� ������� �������
		errPosition = searchErrorStr(buffer, BUFFER_SIZE - 1);

		// ����� ������ � ����� � ���������� ������
		printStrColor(buffer, errPosition, numStr);
	}

	// �������� �����
	fclose(file);

	// �������� ������
	delete[] buffer;
}

// ���������� ������ �� ������� �������
int App::searchErrorStr(char* buffer, int sizeStr)
{
	// ���� ��� ������ � �� �������
	Stack<BracketPosition> stackBracket;

	// ����� ������ �� ��������
	const int SIZE_BRACKET = 6;

	// ������ �� �������� 
	char cblBrackets[SIZE_BRACKET + 1] = { '(', ')', '[',']', '{', '}', '\0'};

	// ����� ������� ��������� 
	BracketPosition newPos;

	for (int i = 0; i < sizeStr; i++)
	{
		// ������� ������
		char tmp = buffer[i];

		// ������ ������ � ������� ������
		int indexCymbol = strChrIndex(cblBrackets, tmp);

		// ���� ��� ������
		if (indexCymbol != -1)
		{
			// ���� �� ����������� ������ �� � ������ ��������
			if ((indexCymbol & 1) == 1)
			{
				// ���� ��� ���� ���� �� �������� ���� ��� ���� ������ ������
				// ������� � ����� �� �������� �� ���� ������ ������� �����������
				if ((stackBracket.isEmpty() || strChrIndex(cblBrackets, stackBracket.peek().bracket) != indexCymbol - 1))
				{
					return i;
				}

				// ������� ������ � ������� �����
				stackBracket.pop();
			}

			// ���� ��� ����������� ������
			else
			{
				// ��������� ��������
				newPos.bracket = tmp;
				newPos.position = i;

				stackBracket.push(newPos);
			}
		}
	}

	// ���� ���� ������� �� ����
	if (!stackBracket.isEmpty())
		return stackBracket.peek().position;

	// ���� ������ �� ������� 
	return -1;
}

// ����� ������ � ����� � ���������� ������
void App::printStrColor(char* str, int errorPosition, int numberStr)
{
	// ����� ������ �� ��������
	const int SIZE_BRACKET = 6;

	// ������ �� �������� 
	char cblBrackets[SIZE_BRACKET] = { '(', ')', '[',']', '{', '}' };

	// ����� ����� ������
	// stringstream oss;

	// ����� ������
	int size = strlen(str);

	// ������� ����
	short cl = getColor();

	// ����� ������ ������, ���� ������� ������ -1, �� ������� ������, � ����� �������
	cout << "\n" << setw(3) << color(errorPosition == -1 ? CYAN_ON_BLACK : RED_ON_BLACK) << numberStr << " | " << color(cl);

	for (int i = 0; i < size; i++)
	{
		// ���� ����� �������� �������
		if (strChrIndex(cblBrackets, str[i]) != -1)
		{
			// ���� ��� ������ ������ 
			if (i == errorPosition)
				cout << color(RED_ON_BLACK);
			else
				cout << color(GREEN_ON_BLACK);

			cout << str[i] << color(cl);

			continue;
		}

		cout << str[i];
	}

	// ���� ��������� ������ ������ �� �������� �������� �������� '\n'
	if (str[size - 1] != '\n')
		cout << "\n";

	// ����� ������� '|', ���� ������� ������ -1, �� ������� ������, � ����� �������
	cout << color(errorPosition == -1 ? CYAN_ON_BLACK : RED_ON_BLACK) << "    | " << color(cl);

	// ����� ����� ^ ��� ��������� ������
	for (int i = 0; i < size; i++)
	{
		// ���� ����� �������� �������
		if (strChrIndex(cblBrackets, str[i]) != -1)
		{
			// ���� ��� ������ ������ 
			if (i == errorPosition)
				cout << color(RED_ON_BLACK) << "^";
			else
				cout << color(GREEN_ON_BLACK) << "*";

			cout << color(cl);

			continue;
		}

		cout << " ";

	}
}

// ������ ���������� ������� � ������
int App::strChrIndex(char* str, char value)
{
	// ��������� �� ��������� ������ � ����������� ������
	char* point = strchr(str, value);

	int size = strlen(str);

	// ���� ������ �� ������
	if (point == nullptr)
		return -1;

	// ������ ������� � ������
	int indexBracket = point - str;

	// ���� ������ 
	return indexBracket == size ? -1 : indexBracket;
}
#pragma endregion

#pragma region ������ 3. ������� ����������� � ��������� �������� �������

/*
			������ 3.
	� �������������� ���������� ������ ������� � ���������� ����������� ������� 
	����������� � ��������� �������� �������. ���������� ������� �� ��������, �� 
	����� 10 ��������� � �������.
	������� ������� ������ ������� �������, ��� � �������� �����������, ����������
	������ �����, ������� �������� � �2, ���������� ������, ���� ���������� �� ����
	(����, �����, �������� Date). ������� ����� ��������, ������ ��� ��������� �����
	��� ������.
	����������� ������������� �������� (��� ������ ����������):
	�	����� � ������� �� ������� � ������� ������ ���������� �������, ��������� 
		������������� ������������
	�	����������� ���� �������� � ����� �������. �����������, ����������� � �����
		�������� �������� � �������� ������� ������ ���� ���.��� �������������� �������
		������ ����:����������� ��������1� � ��������2�.
*/

// ������ 3. ������� ����������� � ��������� �������� �������
void App::task3()
{
	showNavBarMessage(infoColor, "������ 3. ������� ����������� � ��������� �������� �������");

	// ����� �������
	const int size = 10;

	// ������ ��� ���������� ������ �������
	Person personsOne[size]{
		Person("������", "���������", "����������", 3, getRand(68., 82.), 3, Date(15, 12, 2003)),
		Person("���������", "��������", "���������", 1, getRand(36., 42.), 2, Date(6, 4, 2010)),
		Person("��������", "�������", "���������", 2, getRand(54., 62.), 3, Date(30, 5, 2012)),
		Person("�����", "�������", "��������������", 3, getRand(68., 82.), 5, Date(28, 2, 2021)),
		Person("������", "���������", "����������", 2, getRand(54., 62.), 4, Date(29, 2, 2016)),
		Person("���������", "�������", "���������", 1, getRand(36., 42.), 1, Date(3, 1, 1999)),
		Person("���������", "���", "��������", 1, getRand(36., 42.), 3, Date(25, 6, 2001)),
		Person("������", "�������", "��������", 2, getRand(54., 62.), 4, Date(23, 7, 2006)),
		Person("������", "�����", "����������", 1, getRand(36., 42.), 3, Date(18, 3, 2004)),
		Person("�������� ", "����", "������������", 2, getRand(54., 62.), 2, Date(17, 5, 2002))
	};

	// ������ ��� ���������� ������ �������
	Person personsTwo[size]{
		Person("�����������", "��������", "����������", 1, getRand(36., 42.), 3, Date(3, 7, 2005)),
		Person("��������", "���������", "��������", 3, getRand(68., 82.), 2, Date(7, 4, 2004)),
		Person("�������", "����", "��������", 1, getRand(36., 42.), 3, Date(8, 1, 2000)),
		Person("������", "�������", "���������", 2, getRand(54., 62.), 5, Date(11, 2, 2007)),
		Person("���������", "�����", "���������", 2, getRand(54., 62.), 4, Date(17, 12, 2009)),
		Person("���������", "�������", "���������", 2, getRand(54., 62.), 1, Date(1, 6, 2004)),
		Person("���������", "���������", "����������", 1, getRand(36., 42.), 3, Date(12, 6, 2007)),
		Person("������", "�������", "��������", 2, getRand(54., 62.), 4, Date(7, 1, 2003)),
		Person("������", "�����", "����������", 1, getRand(36., 42.), 3, Date(5, 11, 2007)),
		Person("�������� ", "����", "������������", 2, getRand(54., 62.), 2, Date(10, 12, 2009))
	};
	
	// �������� ��� ������ �������
	Queue<Person>::Iterator<Person> iteratorOne(queueOne);

	// �������� ��� ������ �������
	Queue<Person>::Iterator<Person> iteratorTwo(queueTwo);

	// �������� ��� �������������� �������
	Queue<Person>::Iterator<Person> iteratorRes(queueResult);

	// ������������� ������ �������
	queueOne.enqueueAll(personsOne, size);
	
	// ������������� ������ �������
	queueTwo.enqueueAll(personsTwo, size);

	cputs("\n\t���������������������������������������������� �� ����������� ����������������������������������������������\n", YELLOW_ON_BLACK);
	
	// ������ �������
	cputs("\n\t\t\t\t\t\t������ �������: �� �����������\n", GREEN_ON_BLACK);

	// ����� �������
	printQueue(iteratorOne);

	cout << "\n\n\n";

	cputs("\t\t\t\t\t\t������ �������: �� �����������\n", GREEN_ON_BLACK);

	// ����� �������
	printQueue(iteratorTwo);

	cout << "\n\n\n";

	cputs("\t\t\t\t\t����������� ��������1� � ��������2�: �� �����������\n", GREEN_ON_BLACK);

	// ����� �������
	printQueue(iteratorRes);

	cputs("\n\t�������������������������������������������� ����� ����������� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����������� ��� �������� � ���� ����� ��������
	insertQueue(queueOne, queueTwo, queueResult);

	// ������ �������
	cputs("\n\t\t\t\t\t\t������ �������: ����� �����������\n", GREEN_ON_BLACK);

	// ����� �������
	printQueue(iteratorOne);

	cout << "\n\n\n";

	cputs("\t\t\t\t\t\t������ �������: ����� �����������\n", GREEN_ON_BLACK);

	// ����� �������
	printQueue(iteratorTwo);

	cout << "\n\n\n";

	cputs("\t\t\t\t\t����������� ��������1� � ��������2�: ����� �����������\n", GREEN_ON_BLACK);

	// ����� �������
	printQueue(iteratorRes);

	// -----------����� � ������� �� �������

	// ������� ��� ������
	char* surname = getSurname(queueResult);

	cputs("\n\t�������������������������������������������� ����� �� ������� ����������������������������������������������\n", YELLOW_ON_BLACK);

	// ���� �� ���������
	short cl = getColor();

	// ����� ������ � ������ ��������
	cout << color(CYAN_ON_BLACK) << "\n\t������� ��� ������: " << color(GREEN_ON_BLACK) << surname
		<< color(CYAN_ON_BLACK) << "\n\n\t\t��������� ������\n\n" << color(GREEN_ON_BLACK)
		<< search(iteratorRes, surname) << "\n" << color(cl);

	// �������� ������
	delete[]surname;

	getKey();
}

// ����� �������
void App::printQueue(Queue<Person>::Iterator<Person> iterator)
{
	// 		Person("�����������", "��������", "����������", 1, getRand(36., 42.), 3, Date(3, 7, 2005)),
	//       | ������               | ���������            | ����������           |   3    | 71.64068 | 15.12.2003 |
	cout << "\t+����+����������������������+����������������������+����������������������+��������+����������+������������+\n"
		<< "\t|  N |        �������       |         ���          |       ��������       |  ����� |  ������� |    ����    |\n"
		<< "\t|    |                      |                      |                      |   ���. |    �2    |   �������. |\n"
		 << "\t+����+����������������������+����������������������+����������������������+��������+����������+������������+\n";
	if (iterator.end() == 0)
		cputs("\t|                                             ������� �����                                                |\n", RED_ON_BLACK);

	// ����� ��������
	int i = 1;

	// ����� � ������� ���������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		stringstream oss;

		oss << fixed;
		oss.precision(5);

		oss << "\t| " << setw(2) << i++
			<< left << " | " << setw(Person::SURNAME_MAX_SIZE-30) << (*iterator).getSurname() << " | "
			<< setw(Person::NAME_MAX_SIZE-20) << (*iterator).getName() << " | "
			<< setw(Person::PATRONYMIC_MAX_SIZE - 30) << (*iterator).getPatronymic() << " | " << right
			<< setw(6) << (*iterator).getCountFamily() << " | "
			<< setw(3) << (*iterator).getArea() << " | "
			<< setw(15) << (*iterator).getDate() << " |\n";

		cputs(oss.str().c_str(), CYAN_ON_BLACK);
	}

	cout << "\t+����+����������������������+����������������������+����������������������+��������+����������+������������+\n";
}

// ����������� ��� �������� � ���� ����� ��������
void App::insertQueue(Queue<Person>& queueOne, Queue<Person>& queueTwo, Queue<Person>& queueResult)
{
	// �������� ��� ������ �������
	Queue<Person>::Iterator<Person> iteratorOne(queueOne);

	// �������� ��� ������ �������
	Queue<Person>::Iterator<Person> iteratorTwo(queueTwo);

	// ����������� ������ �������
	for (iteratorOne.begin(); iteratorOne != iteratorOne.end(); ++iteratorOne)
	{
		// ����� �������� �������� � �������������� �������
		if (checkQueue(queueResult, *iteratorOne))
			continue;

		// ������ � �������������� �������
		queueResult.enqueue(*iteratorOne);
	}

	// ����������� ������ �������
	for (iteratorTwo.begin(); iteratorTwo != iteratorTwo.end(); ++iteratorTwo)
	{
		// ����� �������� �������� � �������������� �������
		if (checkQueue(queueResult, *iteratorTwo))
			continue;

		// ������ � �������������� �������
		queueResult.enqueue(*iteratorTwo);
	}

	// �������� �������� ��������
	queueOne.clear();
	queueTwo.clear();
}

// �������� �� ������� Person �� ��� � �������
// true - ������� ������
// false - ������� �� ������
bool App::checkQueue(Queue<Person>& queue, Person& person)
{
	// �������� ��� �������
	Queue<Person>::Iterator<Person> iterator(queue);

	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// ������� �������
		Person select = *iterator;

		if (!strcmp(select.getSurname(), person.getSurname())
			&& !strcmp(select.getName(), person.getName())
			&& !strcmp(select.getPatronymic(), person.getPatronymic()))
			return true;
	}

	return false;
}

// ��������� ������� �� �������������� �������
char* App::getSurname(Queue<Person>::Iterator<Person> iterator)
{
	// ������ ��� �������
	char* surname = new char[Person::SURNAME_MAX_SIZE + 1];

	// ������ ���������� ��������
	int index = getRand(0, queueResult.getCounter() - 1);

	// ��������� ��������� �� ������ �������
	for (iterator.begin(); iterator != index; ++iterator) {}

	// ����������� ������ �������
	strcpy(surname, (*iterator).getSurname());

	return surname;
}

// ����� � ������� �� �������
Person App::search(Queue<Person>::Iterator<Person> iterator, char* surname)
{
	// ����� �� ������� � ������
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// ���� ������� � ������� ������� Person ������� � surname
		if (!strcmp(surname, (*iterator).getSurname()))
			return *iterator;
	}

	throw exception("App: ��� �������� � ����� ��������!");
}

#pragma endregion