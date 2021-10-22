#include "App.h"
#include "pch.h"
#include "Conoid.h"

/*
*	�������� �����, ����������� ��������� ����� Conoid (���� ������ ������� ���������, ������
*	�������� ��������� � ������, ��� ����� � double). ���������� ������������ (�� ���������,
*	� ������������ � �������� ������� � ������ ���������� ������), ���������� (���������
*	��������� �Conoid: ������ ���������) ������� � ������� (����������� ���������� ��� �������
*	��� ������������� �������� ���������). ���������� ������, ����������� � ������������ �������
*	� ����� ���������� ������, ����� ������ ������ ���������� ������ (������� � ������, �������
*	����������� � �����) � ���� ������ �������.
*	�������� ������������ ������ �� n ��������� �������, ������� � ������ � ��������� �����.
*	������ ������� ������� � ����������.
*	�������� ������ � ������� � ��������� ����: ������� � ������, ������� � �����. ��� ������
*	�������� �����/������ � �������� �����������, ������������������, �������� ����� ���������
*	�������, � ��������� ����� ��������� �������.
*	����������� �������� �������� ������:
*	�	+ �������� ���� �������, ��������� � �������� �������� � ����� ���� �������
*	�	* ��������� �������� � ����� ������ �� ������������ �����, ����������� ���������� ���
*		������������ ��������
*	�	� ��������� ������������� ����� �� �������� � ������ �������, ����������� ����������
*		��� ������������ ��������
*	����������� �������� �������������� ��������� ������:
*	�	>> �������� �����
*	�	<< �������� ������ ������ ������ (������� � ������, ������� ����������� � �����) �
*		���� ������ �������
*	����������������� �������� ����� � �������� ��� ���� �������.
*	��������� ��������� �������� �� ����� ���������� ������������� ������� �������.
*
*/


// ��������� ������ ���������� ������
void App::generConoid(Conoid* conoid, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		// ������
		conoid[i].setHeight(getRand(1., 50.));

		// ������ 1
		conoid[i].setRadius1(getRand(1., 50.));

		// ������ 2
		conoid[i].setRadius2(getRand(1., 50.));

		// ���� ������ 1 ������ ������� 2
		if (conoid[i].getRadius1() < conoid[i].getRadius2())
		{
			double tmp = conoid[i].getRadius1();
			conoid[i].setRadius1(conoid[i].getRadius2());
			conoid[i].setRadius2(tmp);
		}
	}

}

// ���������� ������� ������ � ������������ �������� ������
int App::maximumIndex(Conoid** conoid, size_t size)
{
	int max = 0;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (conoid[max][0].MathS() < conoid[i + 1][0].MathS())
		{
			max = i + 1;
		}
	}

	return max;
}

// ����� ������
double App::summV(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathV();
	}

	return summ;
}

// ����� �������
double App::summS(Conoid* conoid, size_t size)
{
	double summ = 0.0;

	for (Conoid* conoid_p = conoid; conoid_p < conoid + size; conoid_p++)
	{
		summ += conoid->MathS();
	}

	return summ;
}

// ����� ������� ��������� � ��������� �������, �������������� �����: � Alt+0151
void App::showTableConoids(const char* title, Conoid** conoids, int n, int maxIndex)
{
	setColor(headerColor);

	cout << title
		<< "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n"
		<< "\t    |  N  |    ������, R    |    ������, r   |    ������, H   |   �������, S   |    �����, V    |\n"
		<< "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n";

	setColor(mainColor);

	// ������� ������ ������� ���������, � ���������� ������
	// ������ � ����������� �������, ����� � ����� ���� ������
	// ������� �������� "��������"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(conoids[i][0].MathS() == conoids[maxIndex][0].MathS() ? acctColor : mainColor);

		setColor(headerColor);

		cout << "    " << "| " << setw(3) << i + 1;

		setColor(mainColor);

		// ���������� ������
		cout << conoids[i][0];

		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i

	setColor(headerColor);

	cout << "\t    +�����+�����������������+����������������+����������������+����������������+����������������+\n";

	setColor(mainColor);
} // showTable

// ������������� ������� ������ Conoid. ���������� �������� ������ << 
ostream& operator<<(ostream& link, Conoid& con)
{
	link << " | " << setw(15) << con.radius1_
		<< " | " << setw(14) << con.radius2_
		<< " | " << setw(14) << con.height_
		<< " | " << setw(14) << con.MathS()
		<< " | " << setw(14) << con.MathV()
		<< " |";

	return link;
}

// ������������� ������� ������ Conoid. ���������� �������� ����� >> 
istream& operator>>(istream& link, Conoid& con)
{
	link >> con.height_ >> con.radius1_ >> con.radius2_;

	// ���� ������ ������ ��� ����� ����
	if (con.height_ <= 0)
	{
		throw exception("�������� ������ ������ ���� ������ ����!");
	}

	// ���� ������ ��������� ������ ������� �������
	if (con.radius1_ < con.radius2_)
	{
		throw exception("������ ��������� ������ ���� ������ ������� �������!");
	}

	return link;
}

// ��������� �����
double App::allSummV(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathV();
	}

	return num;
}

// ��������� �������
double App::allSummS(Conoid** conoid, size_t size)
{
	double num = 0;

	for (size_t i = 0; i < size; i++)
	{
		num += conoid[i][0].MathS();
	}

	return num;
}

// ������� 1
void App::task1()
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
		<< "\t\t\t�	� ��������� ������������� ����� �� �������� � ������ �������, ����������� \n"
		<< "\t\t\t\t���������� ��� ������������ ��������\n\n"
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
		double temp = getRand(1.7, 5.);

		*conoids_p = new Conoid(getRand(1.7, 5.), temp + getRand(1.7, 5.), temp);
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
		cout << "\n\n\n\n\t\t4. ��������� ����� (�������� ������)" << endl;
		cout << "\n\n\n\n\n\n\t\tESC �����" << endl;


		cout << "\n\n\n\t\t�������� �����...";

		// �������� ����� 
		while (true)
		{
			n = getKey("");

			// ���� �������� n ������ � ���� �� �������
			if (n < '5' && n > '0')
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

					cout << "������� ������ ������(������(H), ������ ���������(R), ������ �������(r)): ";
					cin >> *res;

					cout << endl;

					cout << "\n\n\t\t\t\t��������� ����� ������" << endl;

					break;

				case '4':

					cout << "\n\n\t\t\t\t\t\t��������� �� ������ �����\n" << endl;

					cout << "\t�������� �����: ";
					cin >> a;

					cout << endl;

					cout << "\t������� ���������� �����: ";
					cin >> num;

					// ��������� ������������ �������
					res = conoids[a - 1][0] - num;

					cout << "\n\n\t\t\t\t��������� ��������� �� ������ " << a << " ����� " << num << endl;



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

