#include "App.h"
#include "pch.h"


/*
	Разработать приложение с использованием меню для закрепления работы со стеком, очередью.
	Для решения задач разработайте классы StackDblдля хранения данных типа double в динамическом
	массиве (размер массива задается в конструкторе и в дальнейшем не меняется, размер по
	умолчанию – 12 элементов), StackPlane для хранения данных типа Plane (класс из предыдущего
	задания, стек на базе статического массива, размер 10 элементов).Стеки StackDbl, StackPlane
	реализуйте на основе класса Stackиз классной работы.
	Задача 1.	Даны два непустых стека вещественных (double) чисел. Переместить все элементы из
		первого стека во второй (в результате элементы первого стека будут располагаться во втором
		стеке в порядке, обратном исходному). Если в первом стеке слишком много элементов, выполняйте
		перемещение до заполнения второго стека.
	Задача 2.	Даны два непустых стека вещественных (double) чисел. Перемещать элементы из первого
		стека во второй, пока значение вершины первого стека не станет отрицательным (перемещенные элементы
		первого стека будут располагаться во втором стеке в порядке, обратном исходному). Если в первом
		стеке нет отрицательных элементов, то переместить из первого стека во второй все элементы. Если в первом стеке слишком много элементов, выполняйте перемещение до заполнения второго стека.
	Задача 3.	Дан непустой стек вещественных (double) чисел. Создать два новых стека, переместив
		в первый из них все элементы исходного стека с положительными значениями, а во второй — с
		отрицательными (элементы в новых стеках будут располагаться в порядке, обратном исходному; один
		из этих стеков может оказаться пустым).
	Задача 4.	Дан непустой стек StackPlane. Переместить данные до самолета с заданным с клавиатуры
		регистрационным номером в новый стек типа StackPlane.
	Задача 5.	Усложненное. Дан непустой стек StackPlane.Переместить из этого стека в новый стек все
		самолеты с заданным с клавиатуры диапазоном дальности полета. Исходный стек не должен измениться.
		Можно использовать вспомогательный стек – динамическую переменную.
*/


#pragma region Задания

#pragma region Задание 1
// тело задания 1
void App::task1()
{
	cls();

#pragma region Вывод информации о задании

	cout << "\n\n\t\t\t\tЗадание 1\n\n\n";

	cout<< "\tДаны два непустых стека вещественных (double) чисел. Переместить\n"
		<< "\tвсе элементы из первого стека во второй (в результате элементы\n"
		<< "\tпервого стека будут располагаться во втором стеке в порядке, обратном\n"
		<< "\tисходному). Если в первом стеке слишком много элементов, выполняйте\n"
		<< "\tперемещение до заполнения второго стека.\n\n\n";

	getKey();

#pragma endregion

#pragma region Создание стеков

	cls();

	// длина первого и второго стека 
	int sizeStackOne, sizeStackTwo, fillCountOne, fillCountTwo;

	// ввод длины первого стека
	cout << "\n\n\t\tStack 1: Введите длину: ";
	cin >> sizeStackOne;

	// объект класса Stack
	StackDbl stack_one = StackDbl(sizeStackOne);

	// ввод длины заполнения первого стека
	cout << "\n\n\t\tStack 1: Введите длину заполнения: ";
	cin >> fillCountOne;

	// если длина заполнения больше максимального размера стека 
	if (fillCountOne > sizeStackOne || fillCountOne < 0)
		throw exception("Длина заполнения должна быть равной или меньше максимальной длины стека");

	// генерация стека 
	fillStack(stack_one, fillCountOne);

	cout << "\n\t\tStack 1: Стек сгенерирован";

	// ввод длины первого стека
	cout << "\n\n\t\tStack 2: Введите длину: ";
	cin >> sizeStackTwo;

	// объект класса Stack
	StackDbl stack_two = StackDbl(sizeStackTwo);

	// ввод длины заполнения первого стека
	cout << "\n\n\t\tStack 2: Введите длину заполнения: ";
	cin >> fillCountTwo;

	// если длина заполнения больше максимального размера стека 
	if (fillCountTwo > sizeStackTwo || fillCountTwo < 0)
		throw exception("Длина заполнения должна быть равной или меньше максимальной длины стека");

	// генерация стека 
	fillStack(stack_two, fillCountTwo);

	cout << "\n\t\tStack 2: Стек сгенерирован\n\n\n";

	getKey();

#pragma endregion

#pragma region Демонстрация содержания стеков 

	cls();

	cout << "\n\n\t\t\t\tСодержание стеков\n"
		<< "\tStack 1: " << stack_one << "\n\tМаксимальный размер стека: " << stack_one.getSize() << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\tМаксимальный размер стека: " << stack_two.getSize() << "\n\n";

#pragma endregion

#pragma region Перемещение всех элементов из первого стека во второй
	
	cout << "Stack: Идет перемещение первого стека во второй\n";

	int countElem = 0;

	// перемещение до переполнения первого стека
	while (!stack_two.isFull() && !stack_one.isEmpty())
	{
		countElem++;

		stack_two.push(stack_one.pop());
	}

	cout << "\n\t\tStack: Перемещение завершено, было перемещено " << countElem << " элементов\n\n\n";

	getKey();

#pragma endregion

#pragma region Демонстрация содержания стеков 

	cout << "\n\n\t\t\t\tСодержание стеков\n"
		<< "\tStack 1: " << stack_one << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\n";

#pragma endregion

	getKey();
}

#pragma endregion

#pragma region Задание 2
// тело задания 2
void App::task2()
{
#pragma region Вывод информации о задании

	cls();

	cout << "\n\n\t\t\t\tЗадание 2\n\n\n";

	cout << "\tДаны два непустых стека вещественных (double) чисел. Перемещать элементы\n"
		<< "\tиз первого стека во второй, пока значение вершины первого стека не станет\n"
		<< "\tотрицательным (перемещенные элементы первого стека будут располагаться во\n"
		<< "\tвтором стеке в порядке, обратном исходному). Если в первом стеке нет \n"
		<< "\tотрицательных элементов, то переместить из первого стека во второй все элементы.\n"
		<< "\tЕсли в первом стеке слишком много элементов, выполняйте перемещение до заполнения\n"
		<< "\tвторого стека.\n\n\n";

	getKey();

#pragma endregion

#pragma region Создание стеков

	cls();

	// длина первого и второго стека 
	int sizeStackOne, sizeStackTwo, fillCountOne, fillCountTwo;

	// ввод длины первого стека
	cout << "\n\n\t\tStack 1: Введите длину: ";
	cin >> sizeStackOne;

	// объект класса Stack
	StackDbl stack_one = StackDbl(sizeStackOne);

	// ввод длины заполнения первого стека
	cout << "\n\n\t\tStack 1: Введите длину заполнения: ";
	cin >> fillCountOne;

	// если длина заполнения больше максимального размера стека 
	if (fillCountOne > sizeStackOne || fillCountOne < 0)
		throw exception("Длина заполнения должна быть равной или меньше максимальной длины стека");

	// генерация стека 
	fillStack(stack_one, fillCountOne);

	cout << "\n\t\tStack 1: Стек сгенерирован";

	// ввод длины первого стека
	cout << "\n\n\t\tStack 2: Введите длину: ";
	cin >> sizeStackTwo;

	// объект класса Stack
	StackDbl stack_two = StackDbl(sizeStackTwo);

	// ввод длины заполнения первого стека
	cout << "\n\n\t\tStack 2: Введите длину заполнения: ";
	cin >> fillCountTwo;

	// если длина заполнения больше максимального размера стека 
	if (fillCountTwo > sizeStackTwo || fillCountTwo < 0)
		throw exception("Длина заполнения должна быть равной или меньше максимальной длины стека");

	// генерация стека 
	fillStack(stack_two, fillCountTwo);

	cout << "\n\t\tStack 2: Стек сгенерирован\n\n\n";

	getKey();

#pragma endregion

#pragma region Демонстрация содержания стеков 

	cls();

	cout << "\n\n\t\t\t\tСодержание стеков\n"
		<< "\tStack 1: " << stack_one << "\n\tМаксимальный размер стека: " << stack_one.getSize() << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\tМаксимальный размер стека: " << stack_two.getSize() << "\n\n";

#pragma endregion

#pragma region Перемещение всех элементов из первого стека во второй

	cout << "Stack: Идет перемещение первого стека во второй\n";

	int countElem = 0;

	// перемещение до переполнения первого стека
	while (!stack_two.isFull() && !stack_one.isEmpty())
	{
		// просмотр вершин
		double n = stack_one.peek();

		if (n < 0) break;

		// количество перемещённых элементов
		countElem++;

		// взятие из первого стека и помещение во второй стек элемента
		stack_two.push(stack_one.pop());
	}

	cout << "\n\t\tStack: Перемещение завершено, было перемещено " << countElem << " элементов\n\n\n";

	getKey();

#pragma endregion

#pragma region Демонстрация содержания стеков 

	cout << "\n\n\t\t\t\tСодержание стеков\n"
		<< "\tStack 1: " << stack_one << "\n\n"
		<< "\tStack 2: " << stack_two << "\n\n";

#pragma endregion

	getKey();
}

#pragma endregion

#pragma region Задание 3
// тело задания 3
void App::task3()
{
#pragma region Вывод информации о задании

	cls();

	cout << "\n\n\t\t\t\tЗадание 3\n\n\n";

	cout << "\tДан непустой стек вещественных (double) чисел. Создать два новых стека,\n"
		<< "\tпереместив в первый из них все элементы исходного стека с положительными\n"
		<< "\tзначениями, а во второй — с отрицательными (элементы в новых стеках будут\n"
		<< "\tрасполагаться в порядке, обратном исходному; один из этих стеков может \n"
		<< "\tоказаться пустым).\n\n\n";

	getKey();

#pragma endregion

#pragma region Создание стеков 

	cls();

	// длина первого и второго стека 
	int sizeStack, fillCount;

	// ввод длины первого стека
	cout << "\n\n\t\tStack Main: Введите длину: ";
	cin >> sizeStack;

	// объект класса Stack
	StackDbl stackMain = StackDbl(sizeStack);

	// ввод длины заполнения первого стека
	cout << "\n\n\t\tStack Main: Введите длину заполнения: ";
	cin >> fillCount;

	// если длина заполнения больше максимального размера стека 
	if (fillCount > sizeStack || fillCount < 0)
		throw exception("Длина заполнения должна быть равной или меньше максимальной длины стека");

	// генерация стека 
	fillStack(stackMain, fillCount);

	cout << "\n\t\tStack Main: Стек сгенерирован\n\n\n";

	// вспомогательные стеки
	StackDbl stackNegative = StackDbl(sizeStack);
	StackDbl stackPositive = StackDbl(sizeStack);

	cout << "\t\tStack Negative: стек для отрицательных элементов создан\n\n"
		<< "\t\tStack Positive: стек для позитивных элементов создан\n\n\n\n";

	getKey();

#pragma endregion 

#pragma region Демонстрация содержания стеков 

	cls();

	cout << "\n\n\t\t\t\tСодержание стеков\n"
		<< "\tStack Main: " << stackMain << "\n\tМаксимальный размер стека: " << stackMain.getSize() << "\n\n"
		<< "\tStack Negative: " << stackNegative << "\n\tМаксимальный размер стека: " << stackNegative.getSize() << "\n\n"
		<< "\tStack Positive: " << stackPositive << "\n\tМаксимальный размер стека: " << stackPositive.getSize() << "\n\n";

#pragma endregion

#pragma region Перемещение всех элементов из первого стека во второй

	cout << "Stack: Идет перемещение первого стека во второй\n";

	int countElemNegative = 0;
	int countElemPositive = 0;

	// перемещение до переполнения первого стека
	while (!stackNegative.isFull() && !stackPositive.isFull() && !stackMain.isEmpty())
	{
		double n = stackMain.pop();

		// если элемент отрительный или положительный 
		n < 0 ? (stackNegative.push(n), countElemNegative++) : (stackPositive.push(n), countElemPositive++);
	}

	cout << "\n\t\tStack: Перемещение завершено, было перемещено: \n"
		<< "Отрицательных элементов: " << countElemNegative << " элементов\n\n"
		<< "Положительных элементов: " << countElemPositive << " элементов\n\n"
		<< "Всего элементов: " << countElemNegative + countElemPositive << " элементов\n\n\n";

	getKey();

#pragma endregion

#pragma region Демонстрация содержания стеков 

	cls();

	cout << "\n\n\t\t\t\tСодержание стеков\n"
		<< "\tStack Main: " << stackMain << "\n\tМаксимальный размер стека: " << stackMain.getSize() << "\n\n"
		<< "\tStack Negative: " << stackNegative << "\n\tМаксимальный размер стека: " << stackNegative.getSize() << "\n\n"
		<< "\tStack Positive: " << stackPositive << "\n\tМаксимальный размер стека: " << stackPositive.getSize() << "\n\n";

#pragma endregion

	getKey();
}

#pragma endregion

#pragma region Задание 4
// тело задания 4
void App::task4()
{
#pragma region Вывод информации о задании

	cls();

	cout << "\n\n\t\t\t\tЗадание 4\n\n\n";

	cout << "\tДан непустой стек StackPlane. Переместить данные до самолета с заданным\n"
		<< "\tс клавиатуры регистрационным номером в новый стек типа StackPlane.\n\n\n";

	getKey();

#pragma endregion

#pragma region Инициализация стека 

	cls();

	// объект StackPlane
	StackPlane stackOne;

	// массив самолётов
	Plane* planes = new Plane[10]{
		Plane("Airbus А380", 525, 345, 12000, 275'000'000, 15000, "F - WWOW"),
		Plane("Boeing 747", 452, 400, 10700, 266'000'000, 12000, "B - 18215"),
		Plane("Boeing 777", 550, 500, 13500, 280'000'000, 13000, "G - YMMM"),
		Plane("Airbus A320", 150, 115, 2100, 93'900'000, 10000, "F - GFKC"),
		Plane("Airbus A318", 132, 86, 2150, 65'000'000, 11000, "D - APWG"),
		Plane("Airbus А380", 525, 123, 12000, 275'000'000, 15000, "Q - SAWD"),
		Plane("Boeing 747", 452, 324, 10700, 266'000'000, 12000, "J - 48914"),
		Plane("Boeing 777", 550, 453, 13500, 280'000'000, 13000, "G - PPDR"),
		Plane("Airbus A320", 150, 98, 2100, 93'900'000, 10000, "X - DFSE"),
		Plane("Airbus A318", 132, 73, 2150, 65'000'000, 11000, "P - VBXC")
	};

	// заполнение стека массивом
	stackOne.pushAll(planes, StackPlane::SIZE_DEFAULT);

#pragma endregion

#pragma region Перемещение самолётов в стек

	// номер самолёта 
	char* number = new char[21];

	// вывод стека 
	cout << "\n\n\t\t\t\tСтек\n\n"
		<< stackOne << "\n\n\n"
		<< "\tВведите номер самолёта: ";

	// ввод номера самолёта
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(number, 20);

	getKey();

	cls();

	// второй стек
	StackPlane stackTwo;

	// вывод стека 
	cout << "\n\n\t\t\t\tСтек 1: До перемещения\n\n"
		<< stackOne << "\n\n\n"
		<< "\n\n\t\t\t\tСтек 2: До перемещения\n\n"
		<< stackTwo << "\n\n\n"
		<< "\tВведённый номер: " << number << "\n\n";

	getKey();

	cls();

	// перемещение 
	while (!stackOne.isEmpty())
	{
		// просмотр вершины
		Plane temp = stackOne.peek();

		// если номер самолёта вершины равен введённому номеру
		if (strcmp(number, temp.getNumber()) == 0)
			break;

		// взятие объекта вершины
		temp = stackOne.pop();

		// заполнение стека объектом 
		stackTwo.push(temp);
	}

	// вывод стека 
	cout << "\n\n\t\t\t\tСтек 1: После перемещения\n\n"
		<< stackOne << "\n\n\n"
		<< "\n\n\t\t\t\tСтек 2: После перемещения\n\n"
		<< stackTwo << "\n\n\n" 
		<< "\tВведённый номер: " << number << "\n\n";

	getKey();

#pragma endregion
}

#pragma endregion

#pragma region Задание 5
// тело задания 5
void App::task5()
{
#pragma region Вывод информации о задании

	cls();

	cout << "\n\n\t\t\t\tЗадание 5\n\n\n";

	cout << "\tУсложненное. Дан непустой стек StackPlane.Переместить из этого стека\n"
		<< "\tв новый стек все самолеты с заданным с клавиатуры диапазоном дальности\n"
		<< "\tполета. Исходный стек не должен измениться. Можно использовать \n"
		<< "\tвспомогательный стек – динамическую переменную.\n\n\n";

	getKey();

#pragma endregion

#pragma region Инициализация стека

	cls();

	// объект StackPlane
	StackPlane stackSource;

	// массив самолётов
	Plane* planes = new Plane[10]{
		Plane("Airbus А380", 525, 345, 12000, 275'000'000, 15000, "F - WWOW"),
		Plane("Boeing 747", 452, 400, 10700, 266'000'000, 12000, "B - 18215"),
		Plane("Boeing 777", 550, 500, 13500, 280'000'000, 13000, "G - YMMM"),
		Plane("Airbus A320", 150, 115, 2100, 93'900'000, 10000, "F - GFKC"),
		Plane("Airbus A318", 132, 86, 2150, 65'000'000, 11000, "D - APWG"),
		Plane("Airbus А380", 525, 123, 12000, 275'000'000, 15000, "Q - SAWD"),
		Plane("Boeing 747", 452, 324, 10700, 266'000'000, 12000, "J - 48914"),
		Plane("Boeing 777", 550, 453, 13500, 280'000'000, 13000, "G - PPDR"),
		Plane("Airbus A320", 150, 98, 2100, 93'900'000, 10000, "X - DFSE"),
		Plane("Airbus A318", 132, 73, 2150, 65'000'000, 11000, "P - VBXC")
	};

	// заполнение стека массивом
	stackSource.pushAll(planes, StackPlane::SIZE_DEFAULT);

#pragma endregion

#pragma region Перемещение самолётов в стек

	// номер самолёта 
	int min, max;

	// вывод стека 
	cout << "\n\n\t\t\t\tСтек\n\n"
		<< stackSource << "\n\n\n"

	// ввод диапазона дальности
		<< "\tВведите диапазон дальности полёта самолёта - минимум: ";
	cin >> min;
	cout << "\tВведите диапазон дальности полёта самолёта - максимум: ";
	cin >> max;

	if (min > max)
		throw exception("Минимальный диапазон должен быть меньше или равен максимальному!");

	cout << "\n\n\n";

	getKey();

	cls();

	// второй стек
	StackPlane stackDestination;

	// стек временный
	StackPlane stackTmp = StackPlane(stackSource);

	// вывод стека 
	cout << "\n\n\t\t\t\tСтек 1: До перемещения\n\n"
		<< stackSource << "\n\n\n"
		<< "\n\n\t\t\t\tСтек 2: До перемещения\n\n"
		<< stackDestination << "\n\n\n"
		<< "\tВведённый диапазон(мин - максимум): " << min << " - " << max << "\n\n";

	getKey();

	cls();

	// перемещение 
	while (!stackTmp.isEmpty())
	{
		// просмотр вершины
		Plane temp = stackTmp.pop();

		// если дальность полёта самолёта входит в введённый диапазон
		if (temp.getDistance() >= min && temp.getDistance() <= max)
		{
			// заполнение стека объектом 
			stackDestination.push(temp);			
		}
	}

	// вывод стека 
	cout << "\n\n\t\t\t\tСтек 1: После перемещения\n\n"
		<< stackSource << "\n\n\n"
		<< "\n\n\t\t\t\tСтек 2: После перемещения\n\n"
		<< stackDestination << "\n\n\n"
		<< "\tВведённый диапазон(мин - максимум): " << min << " - " << max << "\n\n";

	getKey();

#pragma endregion
}

#pragma endregion

#pragma region Общие методы

// заполнение стека вещественными числами
void App::fillStack(StackDbl& stack, int size)
{
	for (size_t i = 0; i < size && !stack.isFull() ; i++)
	{
		stack.push(getRand(-9., 9.));
	}
	
}

#pragma endregion

#pragma endregion

