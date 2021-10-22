#include "App.h"
#include "pch.h"

/*
	������ 1.
	���������� ����� Television, �������������� ������ � ���������� � ��������� 
	����������.��������� ���� ������:
		�	������������� ���������� � char *
		�	������ ���������� � char *
		�	��������� ������ � ������ � double
		�	������ � ��������� ������� � char *
		�	������ � �������� � ���������� ������� � char *
		�	������ � �������� � ���������� ��������� � char *
		�	��������� ������� � ������ � int
	��� ������ ������������ ��������� (������� � �������), ������������ (� �.�. explicit 
	������������ �����������), ����������� �������� ������������, ����� � ������. 
	����������� �� ��������� ��������� ������ ���� � ��� ���������� �������� �������� 
	������� �������� �����������.
	�������� ������� �����������, ��������� ������� � ��������� ������ Queue<Television>,
	����������� ������� �� ����� ��� 12� ������������ �����������. ����������� ���������:
		�	�������� ������� � �������, � �������������� ��������� ��������� ������� � 
			�������� ���� � ������ televisions.bin, �������� �������, ��� ������������� 
			��������� ��������� ������ �� ��������� ����� televisions.bin � �������, ��������
			������� � �������
		�	����������� � ��������� ������� Queue<Television> ���������� ��������� �������. 
			������� � �������� ������� ������� � ����������. �������������� ������� ��������� 
			� �������� ���� � ������ selected.bin, �������� ������ �� ����� ����� � �������
*/

// ���������� � �������� ������ �� ��������� �����
void App::saveOnRead()
{
	cls();

	showNavBarMessage(hintColor, "���������� � �������� ������ �� ��������� �����");

	// �������� ����� 
	const char* nameFile = "televisions.bin";

	cputs("\n    ��������������������������������������������� �������� ������� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������
	printQueue(queTel_);

	// ����� ����� �����
	cputs("    ���� ��� ����������: ", GRAY_ON_BLACK);
	cputs(nameFile, GREEN_ON_BLACK);
	cout << "\n";

	// �������� ����� � ������ �������� ������
	FILE* file = fopen(nameFile, "wb");

	// ���� ���� ������ �������
	if (file != nullptr)
	{
		// ������ � ����
		writeQue(file, queTel_);
	}
	// ���� ���� ������ ��������� 
	else throw exception("App: �� ������� ������� ����");

	// �������� �����
	fclose(file);

	cputs("    ���� �������\n", GREEN_ON_BLACK);

	// �������� �������
	queTel_.clear();

	cputs("\n    ��������������������������������������������� ����� ���������� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������
	printQueue(queTel_);

	// �������� �� �����
	cputs("\n    �������������������������������������������� �������� �� ����� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// �������� ����� � ������ ��������� ������
	file = fopen(nameFile, "rb");

	// ���� ���� ������ �������
	if (file != nullptr)
	{
		// ������ �� �����
		readQue(file, queTel_);
	}
	// ���� ���� ������ ��������� 
	else throw exception("App: �� ������� ������� ����");

	// �������� �����
	fclose(file);

	cputs("\n    ���������������������������������������������� ����� �������� ����������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������
	printQueue(queTel_);

}

// ���������� ������� ��� ������ ������� � ��������� ����
void App::saveRepairer()
{
	cls();

	showNavBarMessage(hintColor, "���������� ������� ��� ������ ������� � ��������� ����");

	cputs("\n    ��������������������������������������������� �������� ������� ���������������������������������������������\n", YELLOW_ON_BLACK);

	// ����� �������
	printQueue(queTel_);

	// ������� � �������� �������
	char* repairer = new char[Television::REPAIRER_MAX_SIZE + 1];

	// ���� ������� � ��������� �������
	cputs("\n\n    ������� ������� � �������� �������: ", YELLOW_ON_BLACK);
	cin.ignore(cin.rdbuf()->in_avail());

	// ��������� �������
	setCursorVisible(true);

	cin.getline(repairer, Television::REPAIRER_MAX_SIZE);

	// ���������� �������
	setCursorVisible(false);

	// �������� ����� 
	char* nameFile = new char[Television::REPAIRER_MAX_SIZE + 5];

	strcpy(nameFile, repairer);
	strcat(nameFile, ".bin");

	// ����� ����� �����
	cputs("    ���� ��� ����������: ", YELLOW_ON_BLACK);
	cputs(nameFile, GREEN_ON_BLACK);
	cout << "\n";

	// �������� ����� � ������ �������� ������
	FILE* file = fopen(nameFile, "wb");

	// ���� ���� ������ ������
	if (file != nullptr)
	{
		// �������������� �������
		Queue<Television> result;

		// ������������� �������������� �������
		queByRepairer(repairer, result);

		// ������ � ����
		writeQue(file, result);

		// �������� ������
		result.clear();

		// �������� �����
		fclose(file);

		cputs("\n    ������������������������������������� �������������� ������� ��������� �������������������������������������\n", YELLOW_ON_BLACK);

		// ����� �������
		printQueue(result);

		// �������� �� �����
		cputs("\n    ������������������������������������� �������������� ������� �� ����� ��������������������������������������\n", YELLOW_ON_BLACK);

		// �������� ����� � ������ ��������� ������
		file = fopen(nameFile, "rb");

		// ���� ���� ������ �������
		if (file != nullptr)
		{
			// ������ �� �����
			readQue(file, result);
		}
		// ���� ���� ������ ��������� 
		else throw exception("App: �� ������� ������� ����");

		// �������� �����
		fclose(file);

		// ����� �������
		printQueue(result);

	}
	else throw exception("App: �� ������� ������� ����");
		
	fclose(file);
}

// ����� ������ � �����
void App::printQueue(Queue<Television>& queue)
{
	// ����� �������
	int size = queue.getCounter();

	// �������� 
	Queue<Television>::Iterator<Television> iter(queue);

	int i = 1;

	// ������� ����
	short cl = getColor();

	// ����� ���������
	showHead();

	// ����� ������� ����������� 
	for (iter.begin(); iter != iter.end(); ++iter, ++i)
	{
		// ������� ������� 
		Television tmp = *iter;

		cout << left << color(cl) << "    |     | ������������� ����������    |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getManufactures() << color(cl) << " |\n"
			 << color(cl) << "    |     | ������ ����������           |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getModel() << color(cl) << " |\n"
			 << color(cl) << "    |     | ��������� ������ (����)     |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getDiagonal() << color(cl) << " |\n"
			 << color(cl) << "    |  " << setw(2) << i << " | ��������� �������           |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getDefect() << color(cl) << " |\n"
			 << color(cl) << "    |     | ������                      |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getRepairer() << color(cl) << " |\n"
			 << color(cl) << "    |     | ��������                    |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getOwner() << color(cl) << " |\n"
			 << color(cl) << "    |     | ��������� ������� (���)     |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getPrice() << color(cl) << " |\n";

		// ����� ����
		showTail();
	}

	// ���� ������� �����
	if (queue.isEmpty())

	{
		cout<< color(RED_ON_BLACK)
			<< "    |                                                                                                          |\n"
			<< "    |                                               ������� �����                                              |\n"
			<< "    |                                                                                                          |\n"
			<< color(cl);

		// ����� ����
		showTail();
	}


}

// ����� ��������� ��� �������
void App::showHead()
{
	cout<< "    +�����+�����������������������������+����������������������������������������������������������������������+\n"
		<< "    |  N  |       ��������������        |                              ����������                              |\n"
		<< "    +�����+�����������������������������+����������������������������������������������������������������������+\n";
}

// ����� ����� �������
void App::showTail()
{
	cout << "    +�����+�����������������������������+����������������������������������������������������������������������+\n";
}

// ������ ������� � ����
void App::writeQue(FILE* file, Queue<Television>& queue)
{
	// �������� 
	Queue<Television>::Iterator<Television> iter(queue);

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		(*iter).write(file);
	}
}

// ���������� ������� �� �����
void App::readQue(FILE* file, Queue<Television>& queue)
{
	// ��������� ������� ������������ � �������� ������
	Television tmp;
	
	while (true)
	{
		// �����������
		tmp.read(file);

		// ���� �� �������� ����� �����
		if (feof(file))
			break;

		queue.enqueue(tmp);
	}
}

// �������� ������� �� �������� �� ������� 
bool App::queByRepairer(const char* repairer, Queue<Television>& result)
{
	// �������� �������� �������
	Queue<Television>::Iterator<Television> iter(queTel_);

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		Television tel = *iter;

		if (strcmp(tel.getRepairer(), repairer) == 0)
			result.enqueue(tel);
	}

	return !result.isEmpty();
}
