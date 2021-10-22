#include "App.h"

/*
	����������� ���������� � �������������� ���� ��� ����������� ������ � �����, ����������� ����.

	�� ������ ������ Deque ����������� ����� DequeChar � ��� �������� (��� char) �� 
	������������ �������, ������ ������� �������� �������������. �� ��������� ������ � 15 ��������.
		� ������� 1. ���� ��� �������� ���� �������� (char), ���� ��������� �������� � ���������� ������� 
			������� ��������. ����������� ��� �������� �� ����� ������� ���� � ������ �������.
		� ������� 2. ���� ��� �������� ���� �������� (char), ���� ��������� �������� � ���������� ������� 
			������� ��������. ���������� �������� �� ����� ������� ���� � ����� �������, ���� � �����
			������� ���� �� �������� ������� ����� ���������� �����. ���� � ������ ���� ��� ������� 
			��������� ����, �� ����������� �� ������� ���� �� ������ ��� ��������.
		� ������� 3. ��� �������� ��� �������� (char), ��� �������� �������� � ���������� ������� ������� 
			��������. ������� ��� ����� ����, ���������� � ����� ��������� ���� � ������ ������� ��
			��� ��� ������� �����, � � ������ ������� � ��� ���������.
*/

#pragma region ������� 

#pragma region ������� 1 

/*
	������� 1. ���� ��� �������� ���� �������� (char), ���� ��������� �������� � ���������� �������
		������� ��������. ����������� ��� �������� �� ����� ������� ���� � ������ �������.
*/

// ������� 1. ����������� ���� ��������� �� ����� ������ � ������ ������ �������
void App::task1()
{
	cls();

	cout << "\n\n\t	������� 1. ���� ��� �������� ���� �������� (char), ���� ���������\n"
		<< "\t�������� � ���������� ������� ������� ��������.����������� ��� ��������\n"
		<< "\t�� ����� ������� ���� � ������ �������.\n\n\n";

	// ��� ������ � ������
	DequeChar deqOne(getRand(2, 6)), deqTwo(getRand(5, 7));

	// ���������� ����� 
	fillDequeChar(deqOne, getRand(2, deqOne.size()));
	fillDequeChar(deqTwo, getRand(2, deqTwo.size()));

	// ������������ �����
	cout << "\t\t��� 1 �� �����������\n"
		<< deqOne << "\n\n"
		<< "\t\t��� 2 �� �����������\n"
		<< deqTwo << "\n\n";

	// ����������� �� ����� ������� ���� � ������ �������
	task1Insert(deqTwo, deqOne);

	// ������������ �����
	cout << "\t\t��� 1 ����� �����������\n"
		<< deqOne << "\n\n"
		<< "\t\t��� 2 ����� �����������\n"
		<< deqTwo << "\n\n";

	getKey();
}

// ����������� ��������� �� ����� ������� ���� � ������ �������
void App::task1Insert(DequeChar& dest, DequeChar& source)
{
	// �� ��� ��� ���� �������������� ��� �� ���������� 
	// � ��������� ��� �� ���������
	while (!dest.isFull() && !source.isEmpty())
	{
		// ����������� �� ����� ������� ���� � ������ �������
		dest.push(source.pop());
	}
}

#pragma endregion

#pragma region ������� 2

/*
	������� 2. ���� ��� �������� ���� �������� (char), ���� ��������� �������� � ���������� ������� 
			������� ��������. ���������� �������� �� ����� ������� ���� � ����� �������, ���� � �����
			������� ���� �� �������� ������� ����� ���������� �����. ���� � ������ ���� ��� ������� 
			��������� ����, �� ����������� �� ������� ���� �� ������ ��� ��������.
*/

// ������� 2. ����������� �� ����� ������� � ����� ������� ���� �� ������� ��������� �����
void App::task2()
{
	cls();

	cout << "\n\n\t	������� 2. ���� ��� �������� ���� �������� (char), ���� ��������� �������� � ���������� ������� \n"
		<< "\t������� ��������. ���������� �������� �� ����� ������� ���� � ����� �������, ���� � �����\n"
		<< "\t������� ���� �� �������� ������� ����� ���������� �����. ���� � ������ ���� ��� ������� \n"
		<< "\t��������� ����, �� ����������� �� ������� ���� �� ������ ��� ��������.\n\n\n";

	// ��� ������ � ������
	DequeChar deqOne(getRand(2, 6)), deqTwo(getRand(5, 7));

	// ���������� ����� 
	fillDequeChar(deqOne, getRand(2, deqOne.size()));
	fillDequeChar(deqTwo, getRand(2, deqTwo.size()));

	// ������������ �����
	cout << "\t\t��� 1 �� �����������\n"
		<< deqOne << "\n\n"
		<< "\t\t��� 2 �� �����������\n"
		<< deqTwo << "\n\n";

	// ����������� �� ����� ������� ���� � ������ �������
	task1Insert(deqTwo, deqOne);

	// ������������ �����
	cout << "\t\t��� 1 ����� �����������\n"
		<< deqOne << "\n\n"
		<< "\t\t��� 2 ����� �����������\n"
		<< deqTwo << "\n\n";

	getKey();

}

// ����������� �� ����� ������� � ����� ������� ���� �� ������� ��������� �����
void App::task2Insert(DequeChar& dest, DequeChar& source)
{
	// ���������� �������� �� ����� ������� ���� � ����� �������, ���� � �����
	// ������� ���� �� �������� ������� ����� ���������� �����. 
	while (!dest.isFull() && !source.isEmpty())
	{
		// �������� ��������
		char tmp = source.back();

		// ������ ��������� ������� ����
		char vovel[6] = "eyuoa";

		// ���� ������ �������� ������� ������ ���������� ����� 
		for (int i = 0; i < 6; i++)
		{
			if (tmp == vovel[i])
				return;
		}

		// ����������� �� ����� ������� ���� � ������ �������
		dest.shift(source.pop());
	}
}

#pragma endregion

#pragma region ������� 3

/*
	������� 3. ��� �������� ��� �������� (char), ��� �������� �������� � ���������� ������� ������� 
			��������. ������� ��� ����� ����, ���������� � ����� ��������� ���� � ������ ������� ��
			��� ��� ������� �����, � � ������ ������� � ��� ���������.
*/

// ������� 3. ����������� � ��� ����: � ��������, � ����������
void App::task3()
{
	cls();

	cout << "\n\n\t	������� 3. ��� �������� ��� �������� (char), ��� �������� �������� � ���������� ������� ������� \n"
		<< "\t��������. ������� ��� ����� ����, ���������� � ����� ��������� ���� � ������ ������� ��\n"
		<< "\t��� ��� ������� �����, � � ������ ������� � ��� ���������.\n\n\n";

	// ����
	DequeChar source(getRand(4, 10)), vowel(source.size()), consonant(source.size());

	// ���������� ���������� ����
	fillDequeChar(source, source.size());

	// ������������ ���������� ����
	cout << "\t\t��� ������ �� �����������\n"
		<< source << "\n\n"
		<< "\t\t��� ������� �� �����������\n"
		<< vowel << "\n\n"
		<< "\t\t��� �������� �� �����������\n"
		<< consonant << "\n\n";

	// �����������
	task3Insert(vowel, consonant, source);

	// ������������ ���������� ����
	cout << "\t\t��� ������ ����� �����������\n"
		<< source << "\n\n"
		<< "\t\t��� ������� ����� �����������\n"
		<< vowel << "\n\n"
		<< "\t\t��� �������� ����� �����������\n"
		<< consonant << "\n\n";

	getKey();
}

// ����������� � ��� �������: � ��������, � ����������
void App::task3Insert(DequeChar & vowel, DequeChar & consonant, DequeChar & source)
{
	// ����������� �� ����������� ���������� ����
	while (!source.isEmpty())
	{
		// ���������� �������� 
		char tmp = source.pop();

		// ������ � �������� ������� ���������� � �������� ��������
		char vovelStr[16] = "eyuoa����������";

		// ���� �� ��������� ������� � ������ ������� ����
		bool flag = false;

		// ���� ����� �������� �������
		for (int i = 0; i < 16; i++)
		{
			if (tmp == vovelStr[i])
			{
				vowel.shift(tmp);

				flag = true;

				break;
			}
		}

		// ���� ������ ������� ������� ������
		if (flag) continue;

		// ���� ������ �������� ��������� ������
		consonant.shift(tmp);
	}
}


#pragma endregion

#pragma region ����� ������

// ���������� ������� (char), n - ���������� ��������� ��� ����������
void App::fillDequeChar(DequeChar& dequeChar, int n)
{
	// ���������� ���������
	for (int i = 0; i < n && !dequeChar.isFull(); i++)
	{
		int n = getRand(1, 2);

		// 1 - ��������� �����, 2 - ������� �����
		dequeChar.push(n == 1 ? getRand('a', 'z') : getRand('�', '�'));
	}
}

#pragma endregion


#pragma endregion