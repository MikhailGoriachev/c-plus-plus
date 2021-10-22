#include "App.h"

// ����������� �� ��������� 
App::App()
{
	air = Airline("�������� � ���������� ���������", 5);

	// ������������� 
	air[0] = Plane("Airbus �380", 525, 345, 12000, 275'000'000, 15000, "F - WWOW");
	air[1] = Plane("Boeing 747", 452, 400, 10700, 266'000'000, 12000, "B - 18215");
	air[2] = Plane("Boeing 777", 550, 500, 13500, 280'000'000, 13000, "G - YMMM");
	air[3] = Plane("Airbus A320", 150, 115, 2100, 93'900'000, 10000, "F - GFKC");
	air[4] = Plane("Airbus A318", 132, 86, 2150, 65'000'000, 11000, "D - APWG");
}

// ����� �������
void App::outPlanes()
{
	cls();

	cout << air << "\n\n\n";

	getKey();
}

// ����� ������� �� �������
void App::outPlaneIndex()
{
	cls();

	// ������
	int index;

	// ���� ������� 
	cout << "\n\n\t\t������� ������ [0 ... " << air.getCountPlane() - 1 << "]: ";
	cin >> index;

	// ����� 
	cout << showOnePlaneTable(air[index]) << "\n";

	getKey();
}

// ���������� ������� �� �������� ���������� ����������
void App::sortByCountPassangers()
{
	cls();

	// ����� ������ �������� �� ����������
	cout << "\n\t\t\t\t\t�� ����������\n" << air << "\n\n\n\n";

	getKey();

	// ���������� 
	air = air * compareByCount_passengers;

	cls();

	// ����� ������ �������� ����� ����������
	cout << "\n\t\t\t\t\t��������������� ������ ��������\n" << air << "\n\n\n\n";

	getKey();
}

// ���������� ������� �� ���������������� ������
void App::sortByNumber()
{
	cls();

	// ����� ������ �������� �� ����������
	cout << "\n\t\t\t\t\t�� ����������\n" << air << "\n\n\n\n";

	getKey();

	// ���������� 
	air = air * compareByNumber;

	cls();

	// ����� ������ �������� ����� ����������
	cout << "\n\t\t\t\t\t��������������� ������ ��������\n" << air << "\n\n\n\n";

	getKey();
}

// ���������� ������� �� �������� ������� ��������
void App::sortByFuel()
{
	cls();

	// ����� ������ �������� �� ����������
	cout << "\n\t\t\t\t\t�� ����������\n" << air << "\n\n\n\n";

	getKey();

	// ���������� 
	air = air * compareByFuel;

	cls();

	// ����� ������ �������� ����� ����������
	cout << "\n\t\t\t\t\t��������������� ������ ��������\n" << air << "\n\n\n\n";

	getKey();
}

// ���������� ������� �� ��������� �����
void App::sortByDistance()
{
	cls();

	// ����� ������ �������� �� ����������
	cout << "\n\t\t\t\t\t�� ����������\n" << air << "\n\n\n\n";

	getKey();

	// ���������� 
	air = *air;

	cls();

	// ����� ������ �������� ����� ����������
	cout << "\n\t\t\t\t\t��������������� ������ ��������\n" << air << "\n\n\n\n";

	getKey();
}

// ���������� ��������� �� �������� ���������� ����������
int App::compareByCount_passengers(const Plane& pl1, const Plane& pl2)
{
	int pl_1 = pl1.getCount_passengers();
	int pl_2 = pl2.getCount_passengers();

	return  pl_1 > pl_2 ? 1 : pl_1 < pl_2 ? -1 : 0;
}

/// ���������� ��������� �� ���������������� ������
int App::compareByNumber(const Plane& pl1, const Plane& pl2)
{
	// ��������� ���� ����� ���� char*
	return strcmp(pl1.getNumber(), pl2.getNumber());
}

/// ���������� ��������� �� �������� ������� ��������
int App::compareByFuel(const Plane& pl1, const Plane& pl2)
{
	int pl_1 = pl1.getFuel();
	int pl_2 = pl2.getFuel();

	return  pl_1 > pl_2 ? 1 : pl_1 < pl_2 ? -1 : 0;
}

// ���������� ������� � ������
void App::addPlane()
{
	cls();

	cout << "\n\t\t\t\t\t���������� �������. ��:" << air << "\n\n\n\n";

	getKey();

	// ����� ������ Plane
	Plane newPlane("Boeing 739", 413, 124, 11400, 243'000'000, 19000, "Z - 18215");

	// ���������� 
	air = air & newPlane;
	
	cls();

	cout << "\n\t\t\t\t\t���������� �������. ��:" << air << "\n\n\n\n";

	getKey();
}

// ����� ������ ������������ � ��������� ���� � ���������� ������
// ��������� � ������������ � ����������� ����������� ������
void App::outTableColor()
{
	cout << "\t\t\t\t\t" << air.getNameCompany() << "\n"
		<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n"
		<< "|     ������    |  ��������. | ���������� | ����. �������� |     ���������     |  ��������� ����� |  ���������. ����� |\n"
		<< "|               |    ����    |            |     ��/�       |      �������     |      �������     |      �������     |\n"
		<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

	// ���� � �������� ��� ��������
	if (air.getCountPlane() == 0)
	{
		cout << "|                                                    ��� ����˨���                                                     |\n"
			// ������ ������ 
			<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}

	// ������� ����
	const short cl = getColor();

	// ����� ��������
	for (int i = 0; i < air.getCountPlane(); i++)
	{
		// ������ � ����������� ���������� �����
		Plane minDist = -air;

		// ������ � ����������� ���������� �����
		Plane maxDist = !air;

		// ���� ������ �������� �������
		setColor((air.getPlanes())[i] == minDist ? errColor : (air.getPlanes())[i] == maxDist ? infoColor : cl);

		// ����� � �����
		cout << air[i];

		setColor(cl);

		// ������ ������ 
		cout << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}

	cout << "\n\n" << color(errColor) << "����������� ��������� �����\n\n" << color(infoColor)
		<< "������������ ��������� �����\n\n" << color(cl);

	getKey();
}