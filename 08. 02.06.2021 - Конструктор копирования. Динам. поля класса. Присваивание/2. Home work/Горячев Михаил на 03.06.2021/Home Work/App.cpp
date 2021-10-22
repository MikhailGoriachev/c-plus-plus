#include "App.h"


#include "Plane.h"
#include "Utils.h"

/*�������� ���������� ������������� ���������� � �������������� ��� �� ���������� �������. 
 *	������������ ����� Plane � ������ ��� ��������:
 *		�	������������� � ���� �������� (��������: ��-76, Boeing 747, �) � char *
 *		�	���������� ������������ ���� (�� 0 �� 1000)- int
 *		�	������� ���������� ���������� (�� 0 �� ���������� ������������ ����)- int
 *		�	������� �������� �� ��� ������ (������������ �����, �� 0.1 �� 28600 ��/�) - double
 *		�	���������� ���������� (�� 1 �� 8)�int
 *		�	�������� ������������ � ��������� � char *.
 *	� ������Plane �����������:
 *		�	������������: �� ���������, � �����������, ����������
 *		�	����������
 *		�	������� � ������� ��� ���� ����� ������, � ������������������� ���������� ��� �����������
 *			������������� ��������
 *		�	�����, ����������� ������ �������� �� ��� ������ �� ���� ������������ ����� (�������� ������
 *			�������� �� ��� �� ���������� ������������ ����)
 *		�	�������������� �������� �������� ������:
 *			o	+ ���������� ��������� ���������� ����������
 *			o	����������� ���������� ���������� �� �������� ��������
 *			o	++����������, ���������� ������� �������� �� 100 ��/�
 *			o	--����������, ���������� ������� �������� �� 100 ��/�	
 *			o	�������� ���������: <<= == != >= > ��� ��������� ���� �������� �� ���������� ����������
 *	�� ������������ ������� ������ Plane����������������� ������ ��������, ��������, ������������� ��������
 *	��������������� ���� � ������������ ����������.
*/

void App::task1()
{
	cls();

	// ��������� ����� ������
	setColor(headerColor);
	
#pragma region ����� �������

	cout << "\n\n\t\t\t\t������� 1\n\n";

	cout << "\t\t�������� ���������� ������������� ���������� � �������������� ��� �� \n"
		<< "\t\t���������� �������. \n\n"
		<< "\t\t������������ ����� Plane � ������ ��� ��������:\n\n"
		<< "\t\t\t�	������������� � ���� �������� (��������: ��-76, Boeing 747, �) � char *\n"
		<< "\t\t\t�	���������� ������������ ���� (�� 0 �� 1000)- int\n"
		<< "\t\t\t�	������� ���������� ���������� (�� 0 �� ���������� ������������ ����)- int\n"
		<< "\t\t\t�	������� �������� �� ��� ������ (������������ �����, �� 0.1 �� 28600 ��/�) - double\n"
		<< "\t\t\t�	���������� ���������� (�� 1 �� 8)�int\n"
		<< "\t\t\t�	�������� ������������ � ��������� � char *.\n\n"
		<< "\t\t� ������ Plane �����������:\n\n"
		<< "\t\t\t�	������������: �� ���������, � �����������, ����������\n"
		<< "\t\t\t�	����������\n"
		<< "\t\t\t�	������� � ������� ��� ���� ����� ������, � �������� ����������� \n"
		<< "\t\t\t\t���������� ��� ����������� ������������� ��������\n"
		<< "\t\t\t�	�����, ����������� ������ �������� �� ��� ������ �� ���� ������������ \n"
		<< "\t\t\t\t����� (�������� ������ �������� �� ��� �� ���������� ������������ ����)\n\n"
		<< "\t\t\t�	�������������� �������� �������� ������:\n\n"
		<< "\t\t\to	+ ���������� ��������� ���������� ����������\n"
		<< "\t\t\to	� ���������� ���������� ���������� �� �������� ��������\n"
		<< "\t\t\to	++����������, ���������� ������� �������� �� 100 ��/�\n"
		<< "\t\t\to	--����������, ���������� ������� �������� �� 100 ��/�	�\n"
		<< "\t\t\to	�������� ���������: <<= == != >= > ��� ��������� ���� �������� �� \n"
		<< "\t\t\t\t���������� ����������\n\n"
		<< "\t\t�� ������������ ������� ������ Plane ����������������� ������ ��������, \n"
		<< "\t\t��������, ������������� ��������\n\n" << endl;

#pragma endregion 

	getKey();

	cls();

#pragma region ���� ������

	cout << "\n\n\t\t\t\t\t���� ������\n\n";

	// ����� ��� ����� �����
	char* buf = new char[400]{ 0 };

	// ���������� int
	int tmp_int;

	// ���������� double
	double tmp_double;

	
	// ���������� double
	
	// ������ ������ Plane
	Plane* p_plane = new Plane;

	Plane& plane = *p_plane;
	
	// ������ ������ Plane
	Plane* p_plane1 = new Plane;
	
	Plane& plane1 = *p_plane1;

#pragma region ���� ������ � ������ Plane
	// ������������� � ��� ��������(�������� : �� - 76, Boeing 747, �) � char*
	// ���� model_
	cout << "\t\t\t������� ������������� � ��� ��������: ";
	cin.getline(buf, 400);

	plane.setModel(buf);

	cout << "\t\t\t������� ���������� ������������ ����: ";
	cin >> tmp_int;

	plane.setSeat(tmp_int);

	cout << "\t\t\t������� ������� ���������� ���������: ";
	cin >> tmp_int;

	plane.setCount_passengers(tmp_int);

	cout << "\t\t\t������� ������ �������� �� ��� ������: ";
	cin >> tmp_double;

	plane.setFuel(tmp_double);

	cout << "\t\t\t������� ���������� ����������: ";
	cin >> tmp_int;

	plane.setEngine(tmp_int);

	cout << "\t\t\t������� �������� ������������ � ���������: ";
	cin.ignore();
	cin.getline(buf, 400);

	plane.setName_airline(buf);

	cout << "\n";
	
	getKey();


	
#pragma endregion

#pragma region ����� ������

	cls();

	printPlane(plane);
	
	getKey();
	
#pragma endregion

	// ������
	
	
	cout << "\n\n\t\t\t\t��������� ++" << endl;

	++plane;

	printPlane(plane);

	cout << "\n\n\t\t\t\t��������� --" << endl;

	--plane;

	printPlane(plane);

	int num = getRand(2, 10);
	
	cout << "\n\n\t\t\t\t������������ ����� " << num << endl;

	plane = plane + num;

	printPlane(plane);

	num = getRand(2, 10);
	
	cout << "\n\n\t\t\t\t��������� ����� " << num << endl;

	plane = plane - num;

	printPlane(plane);

	
	// ���� ��� ���������
	cout << "\n\n\t\t\t\t������� ������ ��� ���������" << endl << endl;

	cout << "\t\t\t������� ������������� � ��� ��������: ";
	cin.getline(buf, 400);

	plane1.setModel(buf);

	cout << "\t\t\t������� ���������� ������������ ����: ";
	cin >> tmp_int;

	plane1.setSeat(tmp_int);

	cout << "\t\t\t������� ������� ���������� ���������: ";
	cin >> tmp_int;

	plane1.setCount_passengers(tmp_int);

	cout << "\t\t\t������� ������ �������� �� ��� ������: ";
	cin >> tmp_double;

	plane1.setFuel(tmp_double);

	cout << "\t\t\t������� ���������� ����������: ";
	cin >> tmp_int;

	plane1.setEngine(tmp_int);

	cout << "\t\t\t������� �������� ������������ � ���������: ";
	cin.ignore();
	cin.getline(buf, 400);

	plane1.setName_airline(buf);

	cout << "\n";

	getKey();

	cls();

	cout << "\n\n\t\t\t\t���������\n\n";

	cout << "\n\n\t\tPlane 1" << endl;

	printPlane(plane);

	cout << "\n\n\t\tPlane 2" << endl;

	printPlane(plane1);


	// ���������

	cout << "\n\n\t\t\t\tPlane 1 < Plane 2 " << boolalpha << (plane < plane1) << "\n\n";
	cout << "\n\n\t\t\t\tPlane 1 <= Plane 2 " << boolalpha << (plane <= plane1) << endl;
	cout << "\n\n\t\t\t\tPlane 1 == Plane 2 " << boolalpha << (plane == plane1) << endl;
	cout << "\n\n\t\t\t\tPlane 1 >= Plane 2 " << boolalpha << (plane >= plane1) << endl;
	cout << "\n\n\t\t\t\tPlane 1 > Plane 2 " << boolalpha << (plane > plane1) << endl;

	getKey();
#pragma endregion

#pragma region ������
	
#pragma endregion 
}

// ����� ������ Plane
void App::printPlane(Plane& plane)
{
	cout << "\n\n\t\t\t\t������\n\n";

	cout << "\t\t������������� � ��� ��������: " << plane.getModel() << endl;

	cout << "\t\t���������� ������������ ����: " << plane.getSeat() << endl;

	cout << "\t\t������� ���������� ����������: " << plane.getCount_passengers() << endl;

	cout << "\t\t������ �������� �� ��� ������: " << plane.getFuel() << endl;

	cout << "\t\t���������� ����������: " << plane.getEngine() << endl;

	cout << "\t\t�������� ������������ � ���������: " << plane.getName_airline();

	cout << "\n";
}