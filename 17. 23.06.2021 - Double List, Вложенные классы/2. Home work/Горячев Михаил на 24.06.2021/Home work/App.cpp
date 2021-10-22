#include "App.h"

/*
	�� �������� � ��������� ������� Deque �� ����������� ������� (�� ���� ������������
	������ ������� List) ������������ ��������� ����� Deque �� ���������������� ������
	DblList �� �������� ������.

	������������ ���������� ����������, � ������� ����������������� ��� �������� � ����
	����� ��� ����� int, char, Car (�� ������ � ��������, ���� ������ � ���������������
	�����, ����, �����).
*/

// ����� ������� int
void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
// ����� ������� char
void printArr(char* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
// ����� ������� char
void printArr(Car* arr, int n)
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\t\t" << arr[i] << "\n";
	}
}

// ���� ������� add � insert
template<typename T>
void App::demo(Deque<T> deq, T* arrFill, int sizeDillArr, T* arrAdd, int sizeAddArr, T add, T ins, T* arrIns, int sizeInsArr)
{
	cls();

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\t\t������������ ������ ���������� Deque\n";


	cout << "\n\t�������� ��� Deque      : " << deq
		<< "\n\n\t���������� ���� ��������: ";

	// ���������� ���� ��������
	deq.pushAll(arrFill, sizeDillArr);

	T n;

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ������ Deque"
		<< "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� �������� � ������: " << ins;

	// ���������� �������� � ������ 
	deq.shift(ins);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � ������";

	// ������ �������� � ������ 
	n = deq.unshift();
	cout << "\n\tDeque                       : " << deq
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ������ ������� : ";

	printArr(arrIns, sizeInsArr);

	// ���������� � ������ �������
	deq.shiftAll(arrIns, sizeInsArr);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � ������"
		<< "\n\tDeque                       : " << deq;

	// �������� �������� � ������
	n = deq.front();

	cout << "\n\t������� � ������            : " << n;


	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ����� Deque"
		<< "\n\n\t���������� �������� � ����� : " << add;

	// ���������� �������� � �����
	deq.push(add);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � �����";

	// ������ �������� � �����
	n = deq.pop();

	cout << "\n\tDeque                       : " << deq
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ����� �������  : ";

	printArr(arrAdd, sizeAddArr);

	// ���������� � ����� �������
	deq.pushAll(arrAdd, sizeAddArr);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � �����"
		<< "\n\tDeque                       : " << deq;

	// �������� �������� � ������
	n = deq.back();

	cout << "\n\t������� � �����             : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n";

	cout << "\n\n\t�������� ����";

	deq.clear();

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n";

	getKey();
}

void App::intDemo()
{
	const int size = 3;

	int arrAdd[size] = { 1, 2, 3 };
	int arrIns[size] = { 11, 22, 33 };
	int arrFill[size] = { 9, 8, 7 };

	int add = 99;
	int ins = -99;

	Deque<int> deq;

	//demo(deqInt, arrFill, size1, arrAdd, size1, add, ins, arrIns, size1);
	demo(deq, arrFill, size, arrAdd, size, add, ins, arrIns, size);
}

void App::charDemo() 
{
	const int size = 3;

	char arrAdd[size] = { 'F', 'X', 'V' };
	char arrIns[size] = { 'S', 'T', 'W' };
	char arrFill[size] = { 'a', 'b', 'c' };

	char add = 'Z';
	char ins = 'P';

	Deque<char> deq;

	//demo(deqInt, arrFill, size1, arrAdd, size1, add, ins, arrIns, size1);
	demo(deq, arrFill, size, arrAdd, size, add, ins, arrIns, size);
}
void App::carDemo() 
{
	const int size = 3;

	Car arrAdd[size] = { Car(genCar()), Car(genCar()), Car(genCar()) };
	Car arrIns[size] = { Car(genCar()), Car(genCar()), Car(genCar()) };
	Car arrFill[size] = { Car(genCar()), Car(genCar()), Car(genCar()) };

	Car add = Car(genCar());
	Car ins = Car(genCar());

	Deque<Car> deq;

	//demo(deqInt, arrFill, size1, arrAdd, size1, add, ins, arrIns, size1);
	demo(deq, arrFill, size, arrAdd, size, add, ins, arrIns, size);

}


// ��������� ����������
Car App::genCar()
{
	char number[8] = "��1234\0";

	Car car;

	for (int i = 0; i < 7; i++)
	{
		if (number[i] >= '�' && number[i] <= '�')
			number[i] = getRand('�', '�');

		else if (number[i] >= '0' && number[i] <= '9')
			number[i] = getRand('0', '9');
	}

	car.setNumber(number);

	char** brand = new char* [5];

	for (int i = 0; i < 5; i++)
	{
		brand[i] = new char[10];
	}

	strcpy(brand[0], "BMW");
	strcpy(brand[1], "MERCEDES");
	strcpy(brand[2], "OPEL");
	strcpy(brand[3], "AUDI");
	strcpy(brand[4], "LADA");

	car.setBrand(brand[getRand(0, 4)]);

	struct Color
	{
		// �������� ����� 
		char name[15];

		// ��� �����
		short color;
	};

	const int size = 8;

	// ������ ������ �� ����������
	Color colors[size];

	// ������
	strcpy(colors[0].name, "Black");
	colors[0].color = WHITE_ON_BLACK;

	// �����
	strcpy(colors[1].name, "Blue");
	colors[1].color = BLACK_ON_BLUE;

	// ������
	strcpy(colors[2].name, "Green");
	colors[2].color = BLACK_ON_GREEN;

	// �������
	strcpy(colors[3].name, "Cyan");
	colors[3].color = BLACK_ON_CYAN;

	// �������
	strcpy(colors[4].name, "Red");
	colors[4].color = BLACK_ON_RED;

	// �������
	strcpy(colors[5].name, "Magenta");
	colors[5].color = BLACK_ON_MAGENTA;

	// �����
	strcpy(colors[6].name, "Yellow");
	colors[6].color = BLACK_ON_YELLOW;

	// ����� 
	strcpy(colors[7].name, "Gray");
	colors[7].color = BLACK_ON_GRAY;

	car.setColor(colors[getRand(0, 7)].name);

	return car;
}
