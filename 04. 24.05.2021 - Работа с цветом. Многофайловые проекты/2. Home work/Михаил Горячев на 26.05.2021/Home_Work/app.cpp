#include "app.h"
#include "pch.h"
#include "task1.h"
#include "Conoid.h"

using namespace std;

void task1()
{
	setColor(mainColor);

	cls();

	setColor(headerColor);

	cout << "\n\n\t\t\t\t������� 1\n\n";

	cout << "\t\t�������� �����, ����������� ��������� ����� Conoid (���� ������\n"
		<< "\t\t������� ���������, ������ �������� ��������� � ������, ��� ����� � double). \n"
		<< "\t\t���������� ������������ (�� ���������, � ������������ � �������� \n"
		<< "\t\t������� � ������ ���������� ������), ���������� (��������� ��������� \n"
		<< "\t\t�Conoid: ������ ���������) ������� � ������� (����������� ���������� \n"
		<< "\t\t��� ������� ��� ������������� �������� ���������). ���������� ������, \n"
		<< "\t\t����������� � ������������ ������� � ����� ���������� ������, �����\n"
		<< "\t\t������ ������ ���������� ������ (������� � ������, ������� �����������\n"
		<< "\t\t� �����) � ���� ������ �������. \n\n"
		<< "\t\t�������� ������ �� 5� ��������� �������, ������� � ������ � ��������� �����. \n"
		<< "\t\t�������� ������ � ������� � ��������� ����: ������� � ������, ������� � \n"
		<< "\t\t�����. ��� ������ �������� �����/������ � �������� �����������, ������ \n"
		<< "\t\t������������, �������� ����� ��������� �������, ����� ��������� �������.\n\n"
		<< "\t\t����������� �������� �������� ������:\n\n"
		<< "\t\t\t�	+ �������� ���� �������, ��������� � �������� �������� � ����� ���� �������\n\n"
		<< "\t\t\t�	* ��������� �������� � ����� ������ �� ������������ �����\n\n"
		<< "\t\t\t�	>> �������� �����\n\n"
		<< "\t\t\t�	<< �������� ������ ������ ������ (������� � ������, ������� ����������� \n"
		<< "\t\t\t\t� �����) � ���� ������ ������� \n\n";
	
	setColor(headerColor);

	getKey();

	cls();

	// ���������� ���������
	int size;

	setCursorVisible(true);

	// ���� ���������� ����������� ��������� �������
	cout << "\n\n\t\t������� ��������� ��������� �������: ";

	cin >> size;

	if (size < 1)
	{
		// ��������� exception �� ��� ������, ���� ����� ������� ������������ ������
		throw exception("���������� ��������� ������� ������ ���� ������ ����!");
	}

	// �������� ������
	cls();

	// ������ ���������� �� ��������� �������
	Conoid** conoids = new Conoid * [size];

	// ���������� ��������� 
	for (Conoid** conoids_p = conoids; conoids_p < conoids + size; conoids_p++)
	{
		*conoids_p = new Conoid(getRand(1., 10.), getRand(1., 10.), getRand(1., 10.));
	}

	// ���������� �������
	setCursorVisible(false);

	char n;

	// ������� ��������������
	Conoid* res = new Conoid();

	// ���������� ��� �������� � ����������
	int a, b;
	double num;

	while (true)
	{
		cls();

		// ����� �������
		showTableConoids("\n\n\n\t\t\t\t\t�������\n", conoids, size, maximumIndex(conoids, size));

		setColor(headerColor);

		cout << setw(38) << " | " << setw(41) << right << "��������� �������: " << allSummS(conoids, size) << " |" << endl;

		cout << setw(38) << " | " << setw(41) << right << "��������� �����: " << allSummV(conoids, size) << " |" << endl;


		cout << "\n\n\n\n\t\t1. �������� ���� ������� (�������� ������)" << endl;
		cout << "\n\n\n\n\t\t2. ��������� ����� (�������� ������)" << endl;
		cout << "\n\n\n\n\t\t3. ���� ������� (������� ������ ����������)" << endl;
		cout << "\n\n\n\n\n\n\t\tESC �����" << endl;

		
		cout << "\n\n\n\t\t�������� �����...";

		// �������� ����� 
		while (true)
		{
			n = getKey("");

			// ���� �������� n ������ � ���� �� �������
			if (n < '4' && n > '0')
			{
				// ��������� �������
				setCursorVisible(true);

				cls();

				// ����� �������
				showTableConoids("\n\n\n\t\t\t\t\t�������\n", conoids, size, maximumIndex(conoids, size));
				
				setColor(headerColor);

				cout << setw(38) << " | " << setw(41) << right << "��������� �������: " << allSummS(conoids, size) << " |" << endl;

				cout << setw(38) << " | " << setw(41) << right << "��������� �����: " << allSummV(conoids, size) << " |" << endl;

				switch (n)
				{

				// 1. �������� ���� ������� (�������� ������)
				case '1':

					cout << "\n\n\t\t\t\t\t\t�������� ���� �������\n" << endl;

					cout << "\t�������� ������ �����: ";
					cin >> a;

					cout << endl;

					cout << "\t�������� ������ �����: ";
					cin >> b;

					// ��������� ������������ �������
					res = conoids[a - 1][0] + conoids[b - 1][0];

					cout << "\n\n\t\t\t\t��������� �������� ������ " << a << " � ������ " << b << endl;

					break;

				// 2. ��������� ����� (�������� ������)
				case '2':

					cout << "\n\n\t\t\t\t\t\t��������� ������ �� �����\n" << endl;

					cout << "\t�������� �����: ";
					cin >> a;

					cout << endl;

					cout << "\t������� ����� - ���������: ";
					cin >> num;

					// ��������� ������������ �������
					res = conoids[a - 1][0] * num;

					cout << "\n\n\t\t\t\t��������� ��������� ������ " << a << " �� ����� " << num << endl;

					break;

				// 3. ���� ������ (������� ������ ����������)
				case '3':

					cout << "\n\n\t\t\t\t\t\t���� ������\n" << endl;

					res = new Conoid;

					cin >> *res;

					cout << endl;

					cout << "\n\n\t\t\t\t��������� ����� ������" << endl;

					break;

				default:
					break;
				}

				cout << endl;

				showTableConoids("", &res, 1, 0);

				cout << endl;

				// �������� ��������
				delete res;

				getKey();

				// ���������� �������
				setCursorVisible(false);

				break;
			}

			if (n == 27)
			{
				// �������� ���������
				for (size_t i = 0; i < size; i++)
				{
					
					delete conoids[i];
				}

				delete[] conoids;

				return;
			}
		}
	}

}