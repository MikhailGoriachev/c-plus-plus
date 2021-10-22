#include "App.h"
#include "pch.h"


/*
	����������� ���������� � �������������� ���� ��� ����������� ������ �� ������, ��������.
	��� ������� ����� ������������ ������ StackDbl��� �������� ������ ���� double � ������������
	������� (������ ������� �������� � ������������ � � ���������� �� ��������, ������ ��
	��������� � 12 ���������), StackPlane ��� �������� ������ ���� Plane (����� �� �����������
	�������, ���� �� ���� ������������ �������, ������ 10 ���������).����� StackDbl, StackPlane
	���������� �� ������ ������ Stack�� �������� ������.
	������ 1.	���� ��� �������� ����� ������������ (double) �����. ����������� ��� �������� ��
		������� ����� �� ������ (� ���������� �������� ������� ����� ����� ������������� �� ������
		����� � �������, �������� ���������). ���� � ������ ����� ������� ����� ���������, ����������
		����������� �� ���������� ������� �����.
	������ 2.	���� ��� �������� ����� ������������ (double) �����. ���������� �������� �� �������
		����� �� ������, ���� �������� ������� ������� ����� �� ������ ������������� (������������ ��������
		������� ����� ����� ������������� �� ������ ����� � �������, �������� ���������). ���� � ������
		����� ��� ������������� ���������, �� ����������� �� ������� ����� �� ������ ��� ��������. ���� � ������ ����� ������� ����� ���������, ���������� ����������� �� ���������� ������� �����.
	������ 3.	��� �������� ���� ������������ (double) �����. ������� ��� ����� �����, ����������
		� ������ �� ��� ��� �������� ��������� ����� � �������������� ����������, � �� ������ � �
		�������������� (�������� � ����� ������ ����� ������������� � �������, �������� ���������; ����
		�� ���� ������ ����� ��������� ������).
	������ 4.	��� �������� ���� StackPlane. ����������� ������ �� �������� � �������� � ����������
		��������������� ������� � ����� ���� ���� StackPlane.
	������ 5.	�����������. ��� �������� ���� StackPlane.����������� �� ����� ����� � ����� ���� ���
		�������� � �������� � ���������� ���������� ��������� ������. �������� ���� �� ������ ����������.
		����� ������������ ��������������� ���� � ������������ ����������.
*/


#pragma region �������

#pragma region ������� 1
// ���� ������� 1
void App::task1()
{
	cls();

#pragma region ����� ���������� � �������

	cout << "\n\n\t\t\t\t������� 1\n\n\n";

	cout<< "\t���� ��� �������� ����� ������������ (double) �����. �����������\n"
		<< "\t��� �������� �� ������� ����� �� ������ (� ���������� ��������\n"
		<< "\t������� ����� ����� ������������� �� ������ ����� � �������, ��������\n"
		<< "\t���������). ���� � ������ ����� ������� ����� ���������, ����������\n"
		<< "\t����������� �� ���������� ������� �����.\n\n\n";

	getKey();

#pragma endregion

#pragma region �������� ������

	cls();

	// ����� ������� � ������� ����� 
	int sizeStackOne, sizeStackTwo, fillCountOne, fillCountTwo;

	// ���� ����� ������� �����
	cout << "\n\n\t\tStack 1: ������� �����: ";
	cin >> sizeStackOne;

	// ������ ������ Stack
	StackDbl stack_one = StackDbl(sizeStackOne);

	// ���� ����� ���������� ������� �����
	cout << "\n\n\t\tStack 1: ������� ����� ����������: ";
	cin >> fillCountOne;

	// ���� ����� ���������� ������ ������������� ������� ����� 
	if (fillCountOne > sizeStackOne || fillCountOne < 0)
		throw exception("����� ���������� ������ ���� ������ ��� ������ ������������ ����� �����");

	// ��������� ����� 
	fillStack(stack_one, fillCountOne);

	cout << "\n\t\tStack 1: ���� ������������";

	// ���� ����� ������� �����
	cout << "\n\n\t\tStack 2: ������� �����: ";
	cin >> sizeStackTwo;

	// ������ ������ Stack
	StackDbl stack_two = StackDbl(sizeStackTwo);

	// ���� ����� ���������� ������� �����
	cout << "\n\n\t\tStack 2: ������� ����� ����������: ";
	cin >> fillCountTwo;

	// ���� ����� ���������� ������ ������������� ������� ����� 
	if (fillCountTwo > sizeStackTwo || fillCountTwo < 0)
		throw exception("����� ���������� ������ ���� ������ ��� ������ ������������ ����� �����");

	// ��������� ����� 
	fillStack(stack_two, fillCountTwo);

	cout << "\n\t\tStack 2: ���� ������������\n\n\n";

	getKey();

#pragma endregion

#pragma region ������������ ���������� ������ 

	cls();

	cout << "\n\n\t\t\t\t���������� ������\n"
		<< "\tStack 1: " << stack_one << "\n\t������������ ������ �����: " << stack_one.getSize() << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\t������������ ������ �����: " << stack_two.getSize() << "\n\n";

#pragma endregion

#pragma region ����������� ���� ��������� �� ������� ����� �� ������
	
	cout << "Stack: ���� ����������� ������� ����� �� ������\n";

	int countElem = 0;

	// ����������� �� ������������ ������� �����
	while (!stack_two.isFull() && !stack_one.isEmpty())
	{
		countElem++;

		stack_two.push(stack_one.pop());
	}

	cout << "\n\t\tStack: ����������� ���������, ���� ���������� " << countElem << " ���������\n\n\n";

	getKey();

#pragma endregion

#pragma region ������������ ���������� ������ 

	cout << "\n\n\t\t\t\t���������� ������\n"
		<< "\tStack 1: " << stack_one << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\n";

#pragma endregion

	getKey();
}

#pragma endregion

#pragma region ������� 2
// ���� ������� 2
void App::task2()
{
#pragma region ����� ���������� � �������

	cls();

	cout << "\n\n\t\t\t\t������� 2\n\n\n";

	cout << "\t���� ��� �������� ����� ������������ (double) �����. ���������� ��������\n"
		<< "\t�� ������� ����� �� ������, ���� �������� ������� ������� ����� �� ������\n"
		<< "\t������������� (������������ �������� ������� ����� ����� ������������� ��\n"
		<< "\t������ ����� � �������, �������� ���������). ���� � ������ ����� ��� \n"
		<< "\t������������� ���������, �� ����������� �� ������� ����� �� ������ ��� ��������.\n"
		<< "\t���� � ������ ����� ������� ����� ���������, ���������� ����������� �� ����������\n"
		<< "\t������� �����.\n\n\n";

	getKey();

#pragma endregion

#pragma region �������� ������

	cls();

	// ����� ������� � ������� ����� 
	int sizeStackOne, sizeStackTwo, fillCountOne, fillCountTwo;

	// ���� ����� ������� �����
	cout << "\n\n\t\tStack 1: ������� �����: ";
	cin >> sizeStackOne;

	// ������ ������ Stack
	StackDbl stack_one = StackDbl(sizeStackOne);

	// ���� ����� ���������� ������� �����
	cout << "\n\n\t\tStack 1: ������� ����� ����������: ";
	cin >> fillCountOne;

	// ���� ����� ���������� ������ ������������� ������� ����� 
	if (fillCountOne > sizeStackOne || fillCountOne < 0)
		throw exception("����� ���������� ������ ���� ������ ��� ������ ������������ ����� �����");

	// ��������� ����� 
	fillStack(stack_one, fillCountOne);

	cout << "\n\t\tStack 1: ���� ������������";

	// ���� ����� ������� �����
	cout << "\n\n\t\tStack 2: ������� �����: ";
	cin >> sizeStackTwo;

	// ������ ������ Stack
	StackDbl stack_two = StackDbl(sizeStackTwo);

	// ���� ����� ���������� ������� �����
	cout << "\n\n\t\tStack 2: ������� ����� ����������: ";
	cin >> fillCountTwo;

	// ���� ����� ���������� ������ ������������� ������� ����� 
	if (fillCountTwo > sizeStackTwo || fillCountTwo < 0)
		throw exception("����� ���������� ������ ���� ������ ��� ������ ������������ ����� �����");

	// ��������� ����� 
	fillStack(stack_two, fillCountTwo);

	cout << "\n\t\tStack 2: ���� ������������\n\n\n";

	getKey();

#pragma endregion

#pragma region ������������ ���������� ������ 

	cls();

	cout << "\n\n\t\t\t\t���������� ������\n"
		<< "\tStack 1: " << stack_one << "\n\t������������ ������ �����: " << stack_one.getSize() << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\t������������ ������ �����: " << stack_two.getSize() << "\n\n";

#pragma endregion

#pragma region ����������� ���� ��������� �� ������� ����� �� ������

	cout << "Stack: ���� ����������� ������� ����� �� ������\n";

	int countElem = 0;

	// ����������� �� ������������ ������� �����
	while (!stack_two.isFull() && !stack_one.isEmpty())
	{
		// �������� ������
		double n = stack_one.peek();

		if (n < 0) break;

		// ���������� ������������ ���������
		countElem++;

		// ������ �� ������� ����� � ��������� �� ������ ���� ��������
		stack_two.push(stack_one.pop());
	}

	cout << "\n\t\tStack: ����������� ���������, ���� ���������� " << countElem << " ���������\n\n\n";

	getKey();

#pragma endregion

#pragma region ������������ ���������� ������ 

	cout << "\n\n\t\t\t\t���������� ������\n"
		<< "\tStack 1: " << stack_one << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\n";

#pragma endregion

	getKey();
}

#pragma endregion

#pragma region ������� 3
// ���� ������� 3
void App::task3()
{
#pragma region ����� ���������� � �������

	cls();

	cout << "\n\n\t\t\t\t������� 3\n\n\n";

	cout << "\t��� �������� ���� ������������ (double) �����. ������� ��� ����� �����,\n"
		<< "\t���������� � ������ �� ��� ��� �������� ��������� ����� � ��������������\n"
		<< "\t����������, � �� ������ � � �������������� (�������� � ����� ������ �����\n"
		<< "\t������������� � �������, �������� ���������; ���� �� ���� ������ ����� \n"
		<< "\t��������� ������).\n\n\n";

	getKey();

#pragma endregion

#pragma region �������� ������ 

	cls();

	// ����� ������� � ������� ����� 
	int sizeStack, fillCount;

	// ���� ����� ������� �����
	cout << "\n\n\t\tStack Main: ������� �����: ";
	cin >> sizeStack;

	// ������ ������ Stack
	StackDbl stackMain = StackDbl(sizeStack);

	// ���� ����� ���������� ������� �����
	cout << "\n\n\t\tStack Main: ������� ����� ����������: ";
	cin >> fillCount;

	// ���� ����� ���������� ������ ������������� ������� ����� 
	if (fillCount > sizeStack || fillCount < 0)
		throw exception("����� ���������� ������ ���� ������ ��� ������ ������������ ����� �����");

	// ��������� ����� 
	fillStack(stackMain, fillCount);

	cout << "\n\t\tStack Main: ���� ������������\n\n\n";

	// ��������������� �����
	StackDbl stackNegative = StackDbl(sizeStack);
	StackDbl stackPositive = StackDbl(sizeStack);

	cout << "\t\tStack Negative: ���� ��� ������������� ��������� ������\n\n"
		<< "\t\tStack Positive: ���� ��� ���������� ��������� ������\n\n\n\n";

	getKey();

#pragma endregion 

#pragma region ������������ ���������� ������ 

	cls();

	cout << "\n\n\t\t\t\t���������� ������\n"
		<< "\tStack Main: " << stackMain << "\n\t������������ ������ �����: " << stackMain.getSize() << "\n\n"
		<< "\tStack Negative: " << stackNegative << "\n\t������������ ������ �����: " << stackNegative.getSize() << "\n\n"
		<< "\tStack Positive: " << stackPositive << "\n\t������������ ������ �����: " << stackPositive.getSize() << "\n\n";

#pragma endregion

#pragma region ����������� ���� ��������� �� ������� ����� �� ������

	cout << "Stack: ���� ����������� ������� ����� �� ������\n";

	int countElemNegative = 0;
	int countElemPositive = 0;

	// ����������� �� ������������ ������� �����
	while (!stackNegative.isFull() && !stackPositive.isFull() && !stackMain.isEmpty())
	{
		double n = stackMain.pop();

		// ���� ������� ����������� ��� ������������� 
		n < 0 ? (stackNegative.push(n), countElemNegative++) : (stackPositive.push(n), countElemPositive++);
	}

	cout << "\n\t\tStack: ����������� ���������, ���� ����������: \n"
		<< "������������� ���������: " << countElemNegative << " ���������\n\n"
		<< "������������� ���������: " << countElemPositive << " ���������\n\n"
		<< "����� ���������: " << countElemNegative + countElemPositive << " ���������\n\n\n";

	getKey();

#pragma endregion

#pragma region ������������ ���������� ������ 

	cls();

	cout << "\n\n\t\t\t\t���������� ������\n"
		<< "\tStack Main: " << stackMain << "\n\t������������ ������ �����: " << stackMain.getSize() << "\n\n"
		<< "\tStack Negative: " << stackNegative << "\n\t������������ ������ �����: " << stackNegative.getSize() << "\n\n"
		<< "\tStack Positive: " << stackPositive << "\n\t������������ ������ �����: " << stackPositive.getSize() << "\n\n";

#pragma endregion

	getKey();
}

#pragma endregion

#pragma region ������� 4
// ���� ������� 4
void App::task4()
{
#pragma region ����� ���������� � �������

	cls();

	cout << "\n\n\t\t\t\t������� 4\n\n\n";

	cout << "\t��� �������� ���� StackPlane. ����������� ������ �� �������� � ��������\n"
		<< "\t� ���������� ��������������� ������� � ����� ���� ���� StackPlane.\n\n\n";

	getKey();

#pragma endregion

#pragma region ������������� ����� 

	cls();

	// ������ StackPlane
	StackPlane stackOne;

	// ������ ��������
	Plane* planes = new Plane[10]{
		Plane("Airbus �380", 525, 345, 12000, 275'000'000, 15000, "F - WWOW"),
		Plane("Boeing 747", 452, 400, 10700, 266'000'000, 12000, "B - 18215"),
		Plane("Boeing 777", 550, 500, 13500, 280'000'000, 13000, "G - YMMM"),
		Plane("Airbus A320", 150, 115, 2100, 93'900'000, 10000, "F - GFKC"),
		Plane("Airbus A318", 132, 86, 2150, 65'000'000, 11000, "D - APWG"),
		Plane("Airbus �380", 525, 123, 12000, 275'000'000, 15000, "Q - SAWD"),
		Plane("Boeing 747", 452, 324, 10700, 266'000'000, 12000, "J - 48914"),
		Plane("Boeing 777", 550, 453, 13500, 280'000'000, 13000, "G - PPDR"),
		Plane("Airbus A320", 150, 98, 2100, 93'900'000, 10000, "X - DFSE"),
		Plane("Airbus A318", 132, 73, 2150, 65'000'000, 11000, "P - VBXC")
	};

	// ���������� ����� ��������
	stackOne.pushAll(planes, StackPlane::SIZE_DEFAULT);

#pragma endregion

#pragma region ����������� �������� � ����

	// ����� ������� 
	char* number = new char[21];

	// ����� ����� 
	cout << "\n\n\t\t\t\t����\n\n"
		<< stackOne << "\n\n\n"
		<< "\t������� ����� �������: ";

	// ���� ������ �������
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(number, 20);

	getKey();

	cls();

	// ������ ����
	StackPlane stackTwo;

	// ����� ����� 
	cout << "\n\n\t\t\t\t���� 1: �� �����������\n\n"
		<< stackOne << "\n\n\n"
		<< "\n\n\t\t\t\t���� 2: �� �����������\n\n"
		<< stackTwo << "\n\n\n"
		<< "\t�������� �����: " << number << "\n\n";

	getKey();

	cls();

	// ����������� 
	while (!stackOne.isEmpty())
	{
		// �������� �������
		Plane temp = stackOne.peek();

		// ���� ����� ������� ������� ����� ��������� ������
		if (strcmp(number, temp.getNumber()) == 0)
			break;

		// ������ ������� �������
		temp = stackOne.pop();

		// ���������� ����� �������� 
		stackTwo.push(temp);
	}

	// ����� ����� 
	cout << "\n\n\t\t\t\t���� 1: ����� �����������\n\n"
		<< stackOne << "\n\n\n"
		<< "\n\n\t\t\t\t���� 2: ����� �����������\n\n"
		<< stackTwo << "\n\n\n" 
		<< "\t�������� �����: " << number << "\n\n";

	getKey();

#pragma endregion
}

#pragma endregion

#pragma region ������� 5
// ���� ������� 5
void App::task5()
{
#pragma region ����� ���������� � �������

	cls();

	cout << "\n\n\t\t\t\t������� 5\n\n\n";

	cout << "\t�����������. ��� �������� ���� StackPlane.����������� �� ����� �����\n"
		<< "\t� ����� ���� ��� �������� � �������� � ���������� ���������� ���������\n"
		<< "\t������. �������� ���� �� ������ ����������. ����� ������������ \n"
		<< "\t��������������� ���� � ������������ ����������.\n\n\n";

	getKey();

#pragma endregion

#pragma region ������������� �����

	cls();

	// ������ StackPlane
	StackPlane stackSource;

	// ������ ��������
	Plane* planes = new Plane[10]{
		Plane("Airbus �380", 525, 345, 12000, 275'000'000, 15000, "F - WWOW"),
		Plane("Boeing 747", 452, 400, 10700, 266'000'000, 12000, "B - 18215"),
		Plane("Boeing 777", 550, 500, 13500, 280'000'000, 13000, "G - YMMM"),
		Plane("Airbus A320", 150, 115, 2100, 93'900'000, 10000, "F - GFKC"),
		Plane("Airbus A318", 132, 86, 2150, 65'000'000, 11000, "D - APWG"),
		Plane("Airbus �380", 525, 123, 12000, 275'000'000, 15000, "Q - SAWD"),
		Plane("Boeing 747", 452, 324, 10700, 266'000'000, 12000, "J - 48914"),
		Plane("Boeing 777", 550, 453, 13500, 280'000'000, 13000, "G - PPDR"),
		Plane("Airbus A320", 150, 98, 2100, 93'900'000, 10000, "X - DFSE"),
		Plane("Airbus A318", 132, 73, 2150, 65'000'000, 11000, "P - VBXC")
	};

	// ���������� ����� ��������
	stackSource.pushAll(planes, StackPlane::SIZE_DEFAULT);

#pragma endregion

#pragma region ����������� �������� � ����

	// ����� ������� 
	int min, max;

	// ����� ����� 
	cout << "\n\n\t\t\t\t����\n\n"
		<< stackSource << "\n\n\n"

	// ���� ��������� ���������
		<< "\t������� �������� ��������� ����� ������� - �������: ";
	cin >> min;
	cout << "\t������� �������� ��������� ����� ������� - ��������: ";
	cin >> max;

	if (min > max)
		throw exception("����������� �������� ������ ���� ������ ��� ����� �������������!");

	cout << "\n\n\n";

	getKey();

	cls();

	// ������ ����
	StackPlane stackDestination;

	// ���� ���������
	StackPlane stackTmp = StackPlane(stackSource);

	// ����� ����� 
	cout << "\n\n\t\t\t\t���� 1: �� �����������\n\n"
		<< stackSource << "\n\n\n"
		<< "\n\n\t\t\t\t���� 2: �� �����������\n\n"
		<< stackDestination << "\n\n\n"
		<< "\t�������� ��������(��� - ��������): " << min << " - " << max << "\n\n";

	getKey();

	cls();

	// ����������� 
	while (!stackTmp.isEmpty())
	{
		// �������� �������
		Plane temp = stackTmp.pop();

		// ���� ��������� ����� ������� ������ � �������� ��������
		if (temp.getDistance() >= min && temp.getDistance() <= max)
		{
			// ���������� ����� �������� 
			stackDestination.push(temp);			
		}
	}

	// ����� ����� 
	cout << "\n\n\t\t\t\t���� 1: ����� �����������\n\n"
		<< stackSource << "\n\n\n"
		<< "\n\n\t\t\t\t���� 2: ����� �����������\n\n"
		<< stackDestination << "\n\n\n"
		<< "\t�������� ��������(��� - ��������): " << min << " - " << max << "\n\n";

	getKey();

#pragma endregion
}

#pragma endregion

#pragma region ����� ������

// ���������� ����� ������������� �������
void App::fillStack(StackDbl& stack, int size)
{
	for (size_t i = 0; i < size && !stack.isFull() ; i++)
	{
		stack.push(getRand(-9., 9.));
	}
	
}

#pragma endregion

#pragma endregion

