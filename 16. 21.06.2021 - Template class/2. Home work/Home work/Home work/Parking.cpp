#include "Parking.h"
#include "Colors.h"
#include "Utils.h"

#pragma region ������

// �������� ����������
void Parking::push(Car car)
{
	parkLane_.push(car);
}

// �������� ������ �����������
void Parking::pushAll(Car* car, int n)
{
	parkLane_.pushAll(car, n);
}

// ������� ��������� ����������
Car Parking::pop()
{
	// ���� ����������� ������ �����
	if (parkLane_.isEmpty())
	{
		Car car("��������", "�����", "!");

		return car;
	}

	return parkLane_.pop();
}

// ������� ����� ���������� 
Car Parking::popAny(int index)
{
	// ���� �������� index �����������
	if (index < 0 && index >= getCounterPark())
		throw exception("Parking: �������� ������� �����������!");

	// ���� ����������� ������ �����
	if (parkLane_.isEmpty())
	{
		Car car("��������", "�����", "!");

		return car;
	}

	// ������� ����������� �� ���������� ������ �� ������� ����������
	for (int i = getCounterPark() - 1; i > index; i--)
	{
		cls();

		// ����� �������� � ����� � ���� �����
		showColor();

		// ����� �������� � ���� �������
		cout << *this;

		manLane_.push(parkLane_.pop());

		Sleep(400);
	}

	Car car = parkLane_.pop();

	while(!manLane_.isEmpty())
	{
		cls();

		// ����� �������� � ����� � ���� �����
		showColor();

		// ����� �������� � ���� �������
		cout << *this;

		parkLane_.push(manLane_.pop());

		Sleep(400);
	}

	return car;
}

// ������� ��� ����������
void Parking::clear()
{
	parkLane_.clear();
}

// ����� ����������� � �����
void Parking::showColor()
{
	cout << "\t+������������������������������������������������������������������������������+\n"
		<< "\t|          ";

	// ����� ������������ �����
	Stack<Car> tmp = parkLane_;

	short mainCl = getColor();

	// ����� � ����� ����� ����������� ������
	for (int i = 0; i < getCounterPark(); i++)
	{
		// ������� ������ Car
		Car car = tmp.pop();

		// ����� ����� ��� ������ � ���� 
		short cl = colorCar(car.getColor());

		cout << "  " << color(cl == -1 ? mainCl : cl) << setw(5) << left << " " << getCounterPark() - 1 - i
			<< color(mainCl);
	}

	cout << "\n\t+          ��������������������������������������������������������������������+\n"
		 << "\t|          ";

	// ����� ������������ �����
	tmp = manLane_;

	// ����� � ����� �����
	for (int i = 0; i < getCounterMan(); i++)
	{
		// ������� ������ Car
		Car car = tmp.pop();

		// ����� ����� ��� ������ � ���� 
		short cl = colorCar(car.getColor());

		cout << "  " << color(cl == -1 ? mainCl : cl) << setw(5) << left << " " << getCounterMan() - 1 - i
			<< color(mainCl);
	}

	cout << "\n\t+������������������������������������������������������������������������������+\n";
}

// ����� ����� ���������� � ���� �� �������� ����� 
short Parking::colorCar(char* color)
{
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

	// ����� ����� � ���� 
	for (int i = 0; i < size; i++)
	{
		// ���� �������� ����� ������� � �������� � ����
		if (!strcmp(color, colors[i].name))
			return colors[i].color;
	}

	return -1;
}

// ���������� �������� ������ 
ostream& operator<<(ostream& os, Parking& park)
{
	cout<< "\t+�����+��������������������+��������������������+��������������������+\n"
		<< "\t| Ind |       �����        |        ����        |        �����       |\n"
		<< "\t+�����+��������������������+��������������������+��������������������+\n"
		<< "\t|                       ����������� ������                           |\n";

	// ����� ������������ �����
	Stack<Car> tmp = park.parkLane_;

	// ����� ����� ����������� ������
	for (int i = 0; i < park.getCounterPark(); i++)
	{
		// ������� ������ Car
		Car car = tmp.pop();

		cout << "\t| " << setw(3) << i << " | "
			<< setw(18) << left << car.getNumber() << " | "
			<< setw(18) << car.getColor() << " | "
			<< setw(18) << car.getBrand() << " |\n";
	}

	cout<< "\t+�����+��������������������+��������������������+��������������������+\n"
		<< "\t|                       ������ ��������������                        |\n";

	// ����� ������������ �����
	tmp = park.manLane_;

	// ����� ����� ����������� ������
	for (int i = 0; i < park.getCounterMan(); i++)
	{
		// ������� ������ Car
		Car car = tmp.pop();

		cout << "\t| " << setw(3) << i << " | "
			<< setw(18) << left << car.getNumber() << " | "
			<< setw(18) << car.getColor() << " | "
			<< setw(18) << car.getBrand() << " |\n";
	}

	cout << "\t+�����+��������������������+��������������������+��������������������+\n";



	/*cout << "\t+������������������������������������������������������������������������������+\n"
		<< "\t|          ";

	// ����� ������������ �����
	Stack<Car> tmp = park.parkLane;

	// ����� � ����� ����� ����������� ������
	for (int i = 0; i < park.counter_; i++)
	{
		// ������� ������ Car
		Car car = tmp.pop();

		cout << "  "  << setw(5) << left << " " << park.counter_ - 1 - i;
	}

	cout << "\t\n+          ��������������������������������������������������������������������+\n"
		<< "\t|          ";

	// ����� ������������ �����
	Stack<Car> tmp = park.manLane;

	// ����� � ����� �����
	for (int i = 0; i < park.counter_; i++)
	{
		// ������� ������ Car
		Car car = tmp.pop();

		// ����� ����� ��� ������ � ���� 
		short cl = colorCar(car.getColor());

		cout << "  " << setw(5) << left << " " << park.counter_ - 1 - i;
	}

	cout << "\t+������������������������������������������������������������������������������+\n";
	*/

	return os;
}

#pragma endregion
