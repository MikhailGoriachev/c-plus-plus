#include "App.h"


#include "Plane.h"
#include "Utils.h"

/*Ќапишите консольное многофайловое приложение с использованием ќќѕ по следующему заданию. 
 *	–азработайте класс Plane с пол€ми дл€ хранени€:
 *		Х	производител€ и типа самолета (например: »л-76, Boeing 747, Е) Ц char *
 *		Х	количества пассажирских мест (от 0 до 1000)- int
 *		Х	текущее количество пассажиров (от 0 до количества пассажирских мест)- int
 *		Х	расхода горючего за час полета (вещественное число, от 0.1 до 28600 кг/ч) - double
 *		Х	количества двигателей (от 1 до 8)Цint
 *		Х	названи€ авиакомпании Ц владельца Ц char *.
 *	¬ классеPlane разработать:
 *		Х	 онструкторы: по умолчанию, с параметрами, копирующий
 *		Х	ƒеструктор
 *		Х	√еттеры и сеттеры дл€ всех полей класса, в сеттерахвыбрасывать исключение при обнаружении
 *			некорректного значени€
 *		Х	ћетод, вычисл€ющий расход горючего за час полета на одно пассажирское место (поделить расход
 *			горючего за час на количество пассажирских мест)
 *		Х	ѕереопределить операции методами класса:
 *			o	+ добавление заданного количества пассажиров
 *			o	Цуменьшение количества пассажиров на заданное значение
 *			o	++префиксный, увеличение расхода горючего на 100 кг/ч
 *			o	--префиксный, уменьшение расхода горючего на 100 кг/ч	
 *			o	операции сравнени€: <<= == != >= > дл€ сравнени€ двух объектов по количеству пассажиров
 *	Ќа динамическом объекте класса Planeпродемонстрируйте работу геттеров, сеттеров, перегруженных операций
 *	 омментирование кода Ц об€зательное требование.
*/

void App::task1()
{
	cls();

	// установка цвета вывода
	setColor(headerColor);
	
#pragma region ¬ывод задани€

	cout << "\n\n\t\t\t\t«адание 1\n\n";

	cout << "\t\tЌапишите консольное многофайловое приложение с использованием ќќѕ по \n"
		<< "\t\tследующему заданию. \n\n"
		<< "\t\t–азработайте класс Plane с пол€ми дл€ хранени€:\n\n"
		<< "\t\t\tХ	производител€ и типа самолета (например: »л-76, Boeing 747, Е) Ц char *\n"
		<< "\t\t\tХ	количества пассажирских мест (от 0 до 1000)- int\n"
		<< "\t\t\tХ	текущее количество пассажиров (от 0 до количества пассажирских мест)- int\n"
		<< "\t\t\tХ	расхода горючего за час полета (вещественное число, от 0.1 до 28600 кг/ч) - double\n"
		<< "\t\t\tХ	количества двигателей (от 1 до 8)Цint\n"
		<< "\t\t\tХ	названи€ авиакомпании Ц владельца Ц char *.\n\n"
		<< "\t\t¬ классе Plane разработать:\n\n"
		<< "\t\t\tХ	 онструкторы: по умолчанию, с параметрами, копирующий\n"
		<< "\t\t\tХ	ƒеструктор\n"
		<< "\t\t\tХ	√еттеры и сеттеры дл€ всех полей класса, в сеттерах выбрасывать \n"
		<< "\t\t\t\tисключение при обнаружении некорректного значени€\n"
		<< "\t\t\tХ	ћетод, вычисл€ющий расход горючего за час полета на одно пассажирское \n"
		<< "\t\t\t\tместо (поделить расход горючего за час на количество пассажирских мест)\n\n"
		<< "\t\t\tХ	ѕереопределить операции методами класса:\n\n"
		<< "\t\t\to	+ добавление заданного количества пассажиров\n"
		<< "\t\t\to	Ц уменьшение количества пассажиров на заданное значение\n"
		<< "\t\t\to	++префиксный, увеличение расхода горючего на 100 кг/ч\n"
		<< "\t\t\to	--префиксный, уменьшение расхода горючего на 100 кг/ч	в\n"
		<< "\t\t\to	операции сравнени€: <<= == != >= > дл€ сравнени€ двух объектов по \n"
		<< "\t\t\t\tколичеству пассажиров\n\n"
		<< "\t\tЌа динамическом объекте класса Plane продемонстрируйте работу геттеров, \n"
		<< "\t\tсеттеров, перегруженных операций\n\n" << endl;

#pragma endregion 

	getKey();

	cls();

#pragma region ¬вод данных

	cout << "\n\n\t\t\t\t\t¬вод данных\n\n";

	// буфер дл€ ввода строк
	char* buf = new char[400]{ 0 };

	// переменна€ int
	int tmp_int;

	// переменна€ double
	double tmp_double;

	
	// переменна€ double
	
	// объект класса Plane
	Plane* p_plane = new Plane;

	Plane& plane = *p_plane;
	
	// объект класса Plane
	Plane* p_plane1 = new Plane;
	
	Plane& plane1 = *p_plane1;

#pragma region ¬вод данных в объект Plane
	// производитель и тип самолета(например : »л - 76, Boeing 747, Е) Ц char*
	// ввод model_
	cout << "\t\t\t¬ведите производител€ и тип самолета: ";
	cin.getline(buf, 400);

	plane.setModel(buf);

	cout << "\t\t\t¬ведите количество пассажирских мест: ";
	cin >> tmp_int;

	plane.setSeat(tmp_int);

	cout << "\t\t\t¬ведите текущее количество пассажиро: ";
	cin >> tmp_int;

	plane.setCount_passengers(tmp_int);

	cout << "\t\t\t¬ведите расход горючего за час полета: ";
	cin >> tmp_double;

	plane.setFuel(tmp_double);

	cout << "\t\t\t¬ведите количество двигателей: ";
	cin >> tmp_int;

	plane.setEngine(tmp_int);

	cout << "\t\t\t¬ведите название авиакомпании Ц владельца: ";
	cin.ignore();
	cin.getline(buf, 400);

	plane.setName_airline(buf);

	cout << "\n";
	
	getKey();


	
#pragma endregion

#pragma region ¬ывод данных

	cls();

	printPlane(plane);
	
	getKey();
	
#pragma endregion

	// ссылка
	
	
	cout << "\n\n\t\t\t\t»нкремент ++" << endl;

	++plane;

	printPlane(plane);

	cout << "\n\n\t\t\t\tƒекремент --" << endl;

	--plane;

	printPlane(plane);

	int num = getRand(2, 10);
	
	cout << "\n\n\t\t\t\tѕрибавлнение числа " << num << endl;

	plane = plane + num;

	printPlane(plane);

	num = getRand(2, 10);
	
	cout << "\n\n\t\t\t\t¬ычитание числа " << num << endl;

	plane = plane - num;

	printPlane(plane);

	
	// ввод дл€ сравнени€
	cout << "\n\n\t\t\t\t¬ведите данные дл€ сравнени€" << endl << endl;

	cout << "\t\t\t¬ведите производител€ и тип самолета: ";
	cin.getline(buf, 400);

	plane1.setModel(buf);

	cout << "\t\t\t¬ведите количество пассажирских мест: ";
	cin >> tmp_int;

	plane1.setSeat(tmp_int);

	cout << "\t\t\t¬ведите текущее количество пассажиро: ";
	cin >> tmp_int;

	plane1.setCount_passengers(tmp_int);

	cout << "\t\t\t¬ведите расход горючего за час полета: ";
	cin >> tmp_double;

	plane1.setFuel(tmp_double);

	cout << "\t\t\t¬ведите количество двигателей: ";
	cin >> tmp_int;

	plane1.setEngine(tmp_int);

	cout << "\t\t\t¬ведите название авиакомпании Ц владельца: ";
	cin.ignore();
	cin.getline(buf, 400);

	plane1.setName_airline(buf);

	cout << "\n";

	getKey();

	cls();

	cout << "\n\n\t\t\t\t—равнение\n\n";

	cout << "\n\n\t\tPlane 1" << endl;

	printPlane(plane);

	cout << "\n\n\t\tPlane 2" << endl;

	printPlane(plane1);


	// сравнени€

	cout << "\n\n\t\t\t\tPlane 1 < Plane 2 " << boolalpha << (plane < plane1) << "\n\n";
	cout << "\n\n\t\t\t\tPlane 1 <= Plane 2 " << boolalpha << (plane <= plane1) << endl;
	cout << "\n\n\t\t\t\tPlane 1 == Plane 2 " << boolalpha << (plane == plane1) << endl;
	cout << "\n\n\t\t\t\tPlane 1 >= Plane 2 " << boolalpha << (plane >= plane1) << endl;
	cout << "\n\n\t\t\t\tPlane 1 > Plane 2 " << boolalpha << (plane > plane1) << endl;

	getKey();
#pragma endregion

#pragma region ћетоды
	
#pragma endregion 
}

// вывод данных Plane
void App::printPlane(Plane& plane)
{
	cout << "\n\n\t\t\t\tƒанные\n\n";

	cout << "\t\tѕроизводитель и тип самолета: " << plane.getModel() << endl;

	cout << "\t\t оличество пассажирских мест: " << plane.getSeat() << endl;

	cout << "\t\t“екущее количество пассажиров: " << plane.getCount_passengers() << endl;

	cout << "\t\t–асход горючего за час полета: " << plane.getFuel() << endl;

	cout << "\t\t оличество двигателей: " << plane.getEngine() << endl;

	cout << "\t\tЌазвани€ авиакомпании Ц владельца: " << plane.getName_airline();

	cout << "\n";
}