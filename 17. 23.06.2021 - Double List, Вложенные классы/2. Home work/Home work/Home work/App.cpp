#include "App.h"

/*
	По аналогии с шаблонным классом Deque из предыдущего задания (на базе односвязного
	списка –класса List) разработайте шаблонный класс Deque на базедвухсвязного списка
	DblList из классной работы.

	Разработайте консольное приложение, в котором продемонстрируйте все операции с этим
	деком для типов int, char, Car (из задачи о парковке, поля класса – регистрационный
	номер, цвет, бренд).
*/

// вывод массива int
void printArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
// вывод массива char
void printArr(char* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}
// вывод массива char
void printArr(Car* arr, int n)
{
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << "\t\t" << arr[i] << "\n";
	}
}

// тест функции add и insert
template<typename T>
void App::demo(Deque<T> deq, T* arrFill, int sizeDillArr, T* arrAdd, int sizeAddArr, T add, T ins, T* arrIns, int sizeInsArr)
{
	cls();

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\t\tДемонстрация работы шаблонного Deque\n";


	cout << "\n\tИсходный дек Deque      : " << deq
		<< "\n\n\tЗаполнение дека массивом: ";

	// заполнение дека массивом
	deq.pushAll(arrFill, sizeDillArr);

	T n;

	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для начала Deque"
		<< "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление элемента в начало: " << ins;

	// добавление элемента в начало 
	deq.shift(ins);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с начала";

	// взятие элемента с начала 
	n = deq.unshift();
	cout << "\n\tDeque                       : " << deq
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в начало массива : ";

	printArr(arrIns, sizeInsArr);

	// добавление в начало массива
	deq.shiftAll(arrIns, sizeInsArr);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с начала"
		<< "\n\tDeque                       : " << deq;

	// просмотр элемента с начала
	n = deq.front();

	cout << "\n\tЭлемент с начала            : " << n;


	cout << "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДемострация функций для конца Deque"
		<< "\n\n\tДобавление элемента в конец : " << add;

	// добавление элемента в конец
	deq.push(add);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tВзятие элемента с конца";

	// взятие элемента с конца
	n = deq.pop();

	cout << "\n\tDeque                       : " << deq
		<< "\n\tВзятый элемент              : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tДобавление в конец массива  : ";

	printArr(arrAdd, sizeAddArr);

	// добавление в конец массива
	deq.pushAll(arrAdd, sizeAddArr);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n"
		<< "\n\n\tПросмотр элемента с конца"
		<< "\n\tDeque                       : " << deq;

	// просмотр элемента с начала
	n = deq.back();

	cout << "\n\tЭлемент с конца             : " << n
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

	cout << "\n\n\tОтчистка дека";

	deq.clear();

	cout << "\n\tDeque                       : " << deq
		<< "\n\n——————————————————————————————————————————————————————————————————————————————\n\n";

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


// генерация автомобиля
Car App::genCar()
{
	char number[8] = "АН1234\0";

	Car car;

	for (int i = 0; i < 7; i++)
	{
		if (number[i] >= 'А' && number[i] <= 'Я')
			number[i] = getRand('А', 'Я');

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

	car.setColor(colors[getRand(0, 7)].name);

	return car;
}
