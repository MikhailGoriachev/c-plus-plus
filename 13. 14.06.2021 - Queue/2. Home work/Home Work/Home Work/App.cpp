#include "App.h"

/*
	����������� ���������� � �������������� ���� ��� ����������� ������ � ��������. 
	������������ ����� ������� QueueDbl (�� ������ ������ Queue� ��������� �������, 
	�� �������� ������) ��� �������� ����� ���� double. ����� ������������ ����� 
	������� QueuePlane ��� �������� �������� ������ Plane. ����������� ������������
	������ ��� ���������� ������, ������ ������� �������� � ������������ � �� 
	�������� �� ����� ������. 
	�	������ 1. ���� ��� �������� ������� ������������ (double) �����, �����������
		���������� ����������. ����������� ��� �������� �� ������ ������� �� ������ 
		(� ���������� �������� ������ ������� ����� ������������� �� ������ ������� 
		� �������� �������).
	�	������ 2. ���� ��� �������� ������� ������������ (double) �����, ����������� 
		���������� ����������. ���������� �������� �� ������ ������� �� ������, ����
		�������� ������� �������� ������ ������� �� ������ ������������� 
		(������������ �������� ������ ������� ����� ������������� �� ������ ������� 
		� �������� �������). ���� � ������ ������� ��� ��������� � �������������� 
		����������, �� ����������� �� ������ ������� �� ������ ��� ��������.
	�	������ 3. ���� �������� ������� ������������ (double) �����, ����������� 
		���������� ����������. ������� ��� ����� �������, ���������� � ������ �� ���
		��� �������� �������� ������� � �������������� ����������, � �� ������ � � 
		�������������� (�������� � ����� �������� ����� ������������� � �������� 
		�������; ���� �� ���� �������� ����� ��������� ������).
	�	������ 4. ���� �������� ������� QueuePlane. ����������� �� ���� ������� � 
		����� ������� ��� �������� � �������� � ���������� ���������� ������� 
		��������. �������� ������� �� ������ ����������.����� ������������ 
		��������������� ������� � ������������ ����������.
*/


#pragma region ������� 

#pragma region ������ 1. ����������� ��������� �� ����� ������� �� ������

/*		
	������ 1. ���� ��� �������� ������� ������������ (double) �����, �����������
		���������� ����������. ����������� ��� �������� �� ������ ������� �� ������
		(� ���������� �������� ������ ������� ����� ������������� �� ������ �������
		� �������� �������).
*/

// ������ 1. ����������� ��������� �� ����� ������� �� ������
void App::task1()
{
	cls();

	cout << "\n\n\t\t������� ������� 1\n" 
		<< "\t���� ��� �������� ������� ������������ (double) �����, �����������\n"
		<< "\t���������� ����������.����������� ��� �������� �� ������ ������� �� ������\n"
		<< "\t(� ���������� �������� ������ ������� ����� ������������� �� ������ �������\n"
		<< "\t� �������� �������).\n\n\n";

	// ������� ������ � ���� ��� �����������
	QueueDbl source(getRand(5, 10)), dest(getRand(5, 10));

	// ����������� �������� ���������� �������
	fillQueueDbl(source, getRand(2, source.getSize()));
	fillQueueDbl(dest, getRand(2, dest.getSize()));

	// ������������ �������� source, dest �� ����������� 
	cout << "\t������������ �������� �� �����������\n\n" 
		<< "\t\t������� 1\n" << source << "\n\n"
		<< "\t\t������� 2\n" << dest << "\n\n";
		
	// ����������� ���������
	task1Insert(source, dest);

	// ������������ �������� source, dest ����� ����������� 
	cout << "\t������������ �������� ����� �����������\n\n"
		<< "\t\t������� 1\n" << source << "\n\n"
		<< "\t\t������� 2\n" << dest << "\n\n";

	getKey();
}

// ����������� ��������� 
void App::task1Insert(QueueDbl& source, QueueDbl& dest)
{
	// ����������� ��������� �� ����������� ������� source
	while (!source.isEmpty() && !dest.isFull())
	{
		dest.enqueue(source.dequeue());
	}
}

#pragma endregion 

#pragma region ������ 2. ����������� �� �������������� ��������

/*
	������ 2. ���� ��� �������� ������� ������������ (double) �����, �����������
		���������� ����������. ���������� �������� �� ������ ������� �� ������, ����
		�������� ������� �������� ������ ������� �� ������ �������������
		(������������ �������� ������ ������� ����� ������������� �� ������ �������
		� �������� �������). ���� � ������ ������� ��� ��������� � ��������������
		����������, �� ����������� �� ������ ������� �� ������ ��� ��������.
*/

// ������ 2. ����������� �� �������������� ��������
void App::task2()
{
	cls();

	cout << "\n\n\t\t������� ������� 1\n"
		<< "\t���� ��� �������� ������� ������������ (double) �����, �����������\n"
		<< "\t���������� ����������. ���������� �������� �� ������ ������� �� ������, ����\n"
		<< "\t(������������ �������� ������ ������� ����� ������������� �� ������ �������\n"
		<< "\t� �������� �������). ���� � ������ ������� ��� ��������� � ��������������\n"
		<< "\t����������, �� ����������� �� ������ ������� �� ������ ��� ��������.\n\n\n";

	// ������� ������ � ���� ��� �����������
	QueueDbl source(getRand(5, 7)), dest(getRand(5, 7));

	// ����������� �������� ���������� �������
	fillQueueDbl(source, getRand(2, source.getSize()));
	fillQueueDbl(dest, getRand(2, dest.getSize()));

	// ������������ �������� source, dest �� ����������� 
	cout << "\t������������ �������� �� �����������\n\n"
		<< "\t\t������� 1\n" << source << "\n\n"
		<< "\t\t������� 2\n" << dest << "\n\n";

	// ����������� ���������
	task2Insert(source, dest);

	// ������������ �������� source, dest ����� ����������� 
	cout << "\t������������ �������� ����� �����������\n\n"
		<< "\t\t������� 1\n" << source << "\n\n"
		<< "\t\t������� 2\n" << dest << "\n\n";

	getKey();
}

// ����������� ��������� �� �������������� ��������
void App::task2Insert(QueueDbl& source, QueueDbl& dest)
{
	// ����������� ��������� �� ����������� ������� source
	while (!source.isEmpty() && !dest.isFull())
	{
		// �������� ������ �������
		double tmp = source.front();

		// ���� ������� tmp �������� �������������
		if (tmp < 0)
			break;

		// ����������� ��������
		dest.enqueue(source.dequeue());
	}
}


#pragma endregion

#pragma region ������ 3. ���������� ������� �� ������������� � �������������

/*
	������ 3. ���� �������� ������� ������������ (double) �����, �����������
			���������� ����������. ������� ��� ����� �������, ���������� � ������ �� ���
			��� �������� �������� ������� � �������������� ����������, � �� ������ � �
			�������������� (�������� � ����� �������� ����� ������������� � ��������
			�������; ���� �� ���� �������� ����� ��������� ������).
*/

// ������ 3. ���������� ������� �� ������������� � �������������
void App::task3()
{
	cls();

	cout << "\n\n\t\t������� ������� 3\n"
		<< "\t���� �������� ������� ������������ (double) �����, �����������\n"
		<< "\t���������� ����������. ������� ��� ����� �������, ���������� � ������ �� ���\n"
		<< "\t��� �������� �������� ������� � �������������� ����������, � �� ������ � �\n"
		<< "\t�������������� (�������� � ����� �������� ����� ������������� � ��������\n"
		<< "\t�������; ���� �� ���� �������� ����� ��������� ������).\n\n\n";

	// ������� ������, ������������� � �������������
	QueueDbl source(getRand(5, 7)), neg(source.getSize()), pos(source.getSize());

	// ����������� �������� ���������� �������
	fillQueueDbl(source, source.getSize());

	// ������������ �������� source, dest �� ����������� 
	cout << "\t������������ �������� �� �����������\n\n"
		<< "\t\t������� ������\n" << source << "\n\n"
		<< "\t\t������������� �������\n" << pos << "\n\n"
		<< "\t\t������������� �������\n" << neg << "\n\n";

	// ����������� ���������
	task3Insert(source, pos, neg);

	// ������������ �������� source, dest ����� ����������� 
	cout << "\t������������ �������� ����� �����������\n\n"
		<< "\t\t������� ������\n" << source << "\n\n"
		<< "\t\t������������� �������\n" << pos << "\n\n"
		<< "\t\t������������� �������\n" << neg << "\n\n";

	getKey();
}

// ����������� ��������� � ��� �������: ������������� � �������������
void App::task3Insert(QueueDbl& source, QueueDbl& pos, QueueDbl& neg)
{
	// ����������� ��������� �� ����������� ������� source
	while (!source.isEmpty())
	{
		// �������� ������ �������
		double tmp = source.dequeue();

		// ���� ������� tmp �������� ������������� ��� �������������
		tmp >= 0 ? pos.enqueue(tmp) : neg.enqueue(tmp);
	}
}

#pragma endregion

#pragma region ������ 4. ����������� �������� �� ��������� ������� ��������

/*
	 ������ 4. ���� �������� ������� QueuePlane. ����������� �� ���� ������� �
			����� ������� ��� �������� � �������� � ���������� ���������� �������
			��������. �������� ������� �� ������ ����������.����� ������������
			��������������� ������� � ������������ ����������.
*/

// ������ 4. ����������� �������� �� ��������� ������� ��������
void App::task4()
{
	cls();

	cout << "\n\n\t\t������� ������� 4\n"
		<< "\t���� �������� ������� QueuePlane. ����������� �� ���� ������� �\n"
		<< "\t����� ������� ��� �������� � �������� � ���������� ���������� �������\n"
		<< "\t��������. �������� ������� �� ������ ����������.����� ������������\n"
		<< "\t��������������� ������� � ������������ ����������.\n\n\n";

	// ������ QueuePlane
	QueuePlane source(getRand(3, 5)), dest(source.getSize());

	// ���������� source
	fillQueuePlane(source, source.getSize());

	// ����� source
	QueuePlane temp(source);

	// ��������
	int min, max;

	// ����� ����� 
	cout << "\n\n\t\t\t\t�������� ������� �� ���������\n\n"
		<< source << "\n\n\n"

	// ���� ��������� ��������� � ��������� �������
	<< "\t������� �������� ��������� ����� �������(������� - ��������): " << cursor_on;
	cin >> min >> max;

	// ����������� �������
	setCursorVisible(false);

	// ���� ������� ������ ���������
	if (min > max)
		throw exception("����������� �������� ������ ���� ������ ��� ����� �������������!");

	// ����������� 
	task4Insert(temp, dest, min, max);

	// ����� ����� 
	cout << "\n\n\t\t\t\t�������� ������� ����� ���������\n\n"
		<< source << "\n\n\n"
		<< "\n\n\t\t\t\t�������������� �������\n\n"
		<< dest << "\n\n\n"
		<< "\t�������� ��������(������� - ��������): " << min << " - " << max << "\n\n";

	getKey();
}

// ����������� ��������� �� ��������� ��������� �����
void App::task4Insert(QueuePlane& source, QueuePlane& dest, int min, int max)
{
	while (!source.isEmpty() && !dest.isFull())
	{
		// ������� �������
		Plane tmpPlane = source.dequeue();

		// ������� ��������� �����
		int tmpDist = tmpPlane.getDistance();

		// ���� ��������� ����� �������� ������� ������ � ��������
		if (tmpDist >= min && tmpDist <= max)
			dest.enqueue(tmpPlane);
	}
}

#pragma endregion

#pragma endregion

#pragma region ����� ������

// ���������� ������� (double), n - ���������� ����������� ���������
void App::fillQueueDbl(QueueDbl& queueDbl, int n)
{
	for (int i = 0; i < n; i++)
	{
		// ���������� ��������� ���������
		queueDbl.enqueue(getRand(-40., 99.));
	}
}

// ���������� ������� (Plane), n - ���������� ����������� ���������
void App::fillQueuePlane(QueuePlane& queuePlane, int n)
{
	for (size_t i = 0; i < n && !queuePlane.isFull(); i++)
	{
		queuePlane.enqueue(genPlane());
	}
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

#pragma endregion

