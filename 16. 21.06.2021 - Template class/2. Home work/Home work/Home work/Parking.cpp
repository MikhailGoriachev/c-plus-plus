#include "Parking.h"
#include "Colors.h"
#include "Utils.h"

#pragma region Методы

// добавить автомобиль
void Parking::push(Car car)
{
	parkLane_.push(car);
}

// добавить массив автомобилей
void Parking::pushAll(Car* car, int n)
{
	parkLane_.pushAll(car, n);
}

// забрать последний автомобиль
Car Parking::pop()
{
	// если парковочная полоса пуста
	if (parkLane_.isEmpty())
	{
		Car car("ПАРКОВКА", "ПУСТА", "!");

		return car;
	}

	return parkLane_.pop();
}

// забрать любой автомобиль 
Car Parking::popAny(int index)
{
	// если значение index некорректно
	if (index < 0 && index >= getCounterPark())
		throw exception("Parking: Значение индекса некорректно!");

	// если парковочная полоса пуста
	if (parkLane_.isEmpty())
	{
		Car car("ПАРКОВКА", "ПУСТА", "!");

		return car;
	}

	// перенос автомобилей на манёвренную полосу до нужного автомобиля
	for (int i = getCounterPark() - 1; i > index; i--)
	{
		cls();

		// вывод парковки в цвете в виде схемы
		showColor();

		// вывод парковки в виде таблицы
		cout << *this;

		manLane_.push(parkLane_.pop());

		Sleep(400);
	}

	Car car = parkLane_.pop();

	while(!manLane_.isEmpty())
	{
		cls();

		// вывод парковки в цвете в виде схемы
		showColor();

		// вывод парковки в виде таблицы
		cout << *this;

		parkLane_.push(manLane_.pop());

		Sleep(400);
	}

	return car;
}

// забрать все автомобили
void Parking::clear()
{
	parkLane_.clear();
}

// вывод автомобилей в цвете
void Parking::showColor()
{
	cout << "\t+——————————————————————————————————————————————————————————————————————————————+\n"
		<< "\t|          ";

	// копия парковочного стека
	Stack<Car> tmp = parkLane_;

	short mainCl = getColor();

	// вывод в цвете машин парковочная полоса
	for (int i = 0; i < getCounterPark(); i++)
	{
		// текущий объект Car
		Car car = tmp.pop();

		// поиск цвета для вывода в базе 
		short cl = colorCar(car.getColor());

		cout << "  " << color(cl == -1 ? mainCl : cl) << setw(5) << left << " " << getCounterPark() - 1 - i
			<< color(mainCl);
	}

	cout << "\n\t+          ————————————————————————————————————————————————————————————————————+\n"
		 << "\t|          ";

	// копия парковочного стека
	tmp = manLane_;

	// вывод в цвете машин
	for (int i = 0; i < getCounterMan(); i++)
	{
		// текущий объект Car
		Car car = tmp.pop();

		// поиск цвета для вывода в базе 
		short cl = colorCar(car.getColor());

		cout << "  " << color(cl == -1 ? mainCl : cl) << setw(5) << left << " " << getCounterMan() - 1 - i
			<< color(mainCl);
	}

	cout << "\n\t+——————————————————————————————————————————————————————————————————————————————+\n";
}

// поиск цвета автомобиля в базе по названию цвета 
short Parking::colorCar(char* color)
{
	struct Color
	{
		// название цвета 
		char name[15];

		// код цвета
		short color;
	};

	const int size = 8;

	// массив цветов со значениями
	Color colors[size];

	// чёрный
	strcpy(colors[0].name, "Black");
	colors[0].color = WHITE_ON_BLACK;

	// синий
	strcpy(colors[1].name, "Blue");
	colors[1].color = BLACK_ON_BLUE;

	// зелёный
	strcpy(colors[2].name, "Green");
	colors[2].color = BLACK_ON_GREEN;

	// голубой
	strcpy(colors[3].name, "Cyan");
	colors[3].color = BLACK_ON_CYAN;

	// красный
	strcpy(colors[4].name, "Red");
	colors[4].color = BLACK_ON_RED;

	// лиловый
	strcpy(colors[5].name, "Magenta");
	colors[5].color = BLACK_ON_MAGENTA;

	// жёлтый
	strcpy(colors[6].name, "Yellow");
	colors[6].color = BLACK_ON_YELLOW;

	// серый 
	strcpy(colors[7].name, "Gray");
	colors[7].color = BLACK_ON_GRAY;

	// поиск цвета в базе 
	for (int i = 0; i < size; i++)
	{
		// если назавние цвета совпало с навзание в базе
		if (!strcmp(color, colors[i].name))
			return colors[i].color;
	}

	return -1;
}

// перегрузка операции вывода 
ostream& operator<<(ostream& os, Parking& park)
{
	cout<< "\t+—————+————————————————————+————————————————————+————————————————————+\n"
		<< "\t| Ind |       Номер        |        Цвет        |        Марка       |\n"
		<< "\t+—————+————————————————————+————————————————————+————————————————————+\n"
		<< "\t|                       ПАРКОВОЧНАЯ ПОЛОСА                           |\n";

	// копия парковочного стека
	Stack<Car> tmp = park.parkLane_;

	// вывод машин парковочная полоса
	for (int i = 0; i < park.getCounterPark(); i++)
	{
		// текущий объект Car
		Car car = tmp.pop();

		cout << "\t| " << setw(3) << i << " | "
			<< setw(18) << left << car.getNumber() << " | "
			<< setw(18) << car.getColor() << " | "
			<< setw(18) << car.getBrand() << " |\n";
	}

	cout<< "\t+—————+————————————————————+————————————————————+————————————————————+\n"
		<< "\t|                       ПОЛОСА МАНЕВРИРОВАНИЯ                        |\n";

	// копия парковочного стека
	tmp = park.manLane_;

	// вывод машин парковочная полоса
	for (int i = 0; i < park.getCounterMan(); i++)
	{
		// текущий объект Car
		Car car = tmp.pop();

		cout << "\t| " << setw(3) << i << " | "
			<< setw(18) << left << car.getNumber() << " | "
			<< setw(18) << car.getColor() << " | "
			<< setw(18) << car.getBrand() << " |\n";
	}

	cout << "\t+—————+————————————————————+————————————————————+————————————————————+\n";



	/*cout << "\t+——————————————————————————————————————————————————————————————————————————————+\n"
		<< "\t|          ";

	// копия парковочного стека
	Stack<Car> tmp = park.parkLane;

	// вывод в цвете машин парковочная полоса
	for (int i = 0; i < park.counter_; i++)
	{
		// текущий объект Car
		Car car = tmp.pop();

		cout << "  "  << setw(5) << left << " " << park.counter_ - 1 - i;
	}

	cout << "\t\n+          ————————————————————————————————————————————————————————————————————+\n"
		<< "\t|          ";

	// копия парковочного стека
	Stack<Car> tmp = park.manLane;

	// вывод в цвете машин
	for (int i = 0; i < park.counter_; i++)
	{
		// текущий объект Car
		Car car = tmp.pop();

		// поиск цвета для вывода в базе 
		short cl = colorCar(car.getColor());

		cout << "  " << setw(5) << left << " " << park.counter_ - 1 - i;
	}

	cout << "\t+——————————————————————————————————————————————————————————————————————————————+\n";
	*/

	return os;
}

#pragma endregion
