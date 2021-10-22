#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "Container.h"
#include "Bubble.h"
#include "Choice.h"
#include "QSort.h"

#include "BinaryTree.h"
#include "DblList.h"
#include "Person.h"

/*
	Задача 1. Разработайте иерархию классов для работы с массивами чисел.
	Базовый шаблонный абстрактный класс Container содержит чистые виртуальные
	методы sort(), foreach().
	Метод sort() будет использоваться для сортировки данных в контейнере,
	метод foreach() – для поэлементной обработки контейнера.
	Производные классы работают с данными типа double. При работе методов
	поэлементной обработки контролировать условия выполнимости операции. Если
	операция не выполнима – выбрасывать исключение, обрабатываемое в методе.
	Разработайте собственный класс исключения, унаследованный от класса
	exception.Передавать в исключение: сообщении об ошибке, значение элемента
	массива, при обработке исключения сам элемент массива не менять.
	В производном классе Bubble сортировка реализуется методом пузырька,
	поэлементная обработка – извлечение квадратного корня.
	В производном классе Choice сортировка реализуется методом выбора,
	поэлементная обработка – вычисление натурального логарифма log().
	В производном классе QSort сортировка реализуется методом быстрой сортировки,
	вызовом функции qsort(),  поэлементная обработка – вычисление десятичного
	логарифма log10().

	Задача 2. Разработать консольное приложение, с использованием класса Person,
	двусвязного списка (класс DblList<Person>)объектов класса Person. Примените
	функциональные try-блоки в конструкторах класса Person.
	Класс Personимеет поля:
		Табельный номер, целое число, уникальное в пределах приложения
		Фамилия и инициалы – динамическое поле, char *
		Оклад, вещественное число, double
		Год поступления на работу, int
		Количество рабочих дней в месяце, int
		Количество фактически отработанных дней в месяце, int
	Разработать конструкторы и деструктор, аксессоры, метод вычисления начислений
	– произведение оклада на отношение количества фактически отработанных дней к
	количеству рабочих дней в месяце.
	Начислено=Оклад∙ (Фактически отработано)/(Рабочих дней в месчце)
		Создать двусвязный список из объектов класса Person–не менее 12 элементов,
		показать работу конструкторов, методов, генерацию и обработку исключений.
		Разработать функцию, вычисляющую сумму начислений по двусвязному списку персон
		Добавить данные списка в бинарное дерево поиска, использовать табельный номер
		для записи в бинарное дерево поиска, вывести данные из бинарного дерева поиска
		в порядке возрастания табельных номеров
*/

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
public:

	// длина массива для заполнения 
	static const int SIZE_FILL_ARR = 12;

private:

	// объект Bubble
	Bubble bubble_;

	// объект Choice
	Choice choice_;

	// объект QSort
	QSort qSort_;

	// база табельных номеров класса Person
	BinaryTree<unsigned int> numberBase_;

	// двусвязный список из объектов класса Person
	DblList<Person> list_;

	// бинарное дерево поиска из объектов класса Person
	BinaryTree<Person> tree_;

	// список персон для списка 
	Person* personsByList_;

	// список персон для дерева
	Person* personsByTree_;

public:

	// конструктор по умолчанию
	App()
	{
		// границы значений для заполнения
		double minValue = 10.;
		double maxValue = 99.;

		const int SIZE_CONTAINER = 13;

		// иницилазация bubble_
		fillContainer(bubble_, minValue, maxValue, SIZE_CONTAINER);
		
		// иницилазация choice_
		fillContainer(choice_, minValue, maxValue, SIZE_CONTAINER);
		
		// иницилазация qSort_
		fillContainer(qSort_, minValue, maxValue, SIZE_CONTAINER);

		// 	Person(unsigned int number, const char* name, double salary, int year, int monthWorkDay, int completedWorkDay) try

		// список персон
		personsByList_ = new Person[SIZE_FILL_ARR]
		{
			Person(654878, "Бобров В.Б", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(987521, "Иванов Н.Г", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(345987, "Дьячков В.Ф", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(567442, "Тарасов Н.Х", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654574, "Шашков Г.Л", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(324957, "Лобанов И.С", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(687684, "Третьяков О.Х", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(795215, "Бирюков М.М", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(564957, "Игнатов Н.В", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654212, "Логинов А.Е", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(567541, "Ситников М.В", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(245621, "Кулаков Л.Я", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		};

		// список персон
		personsByTree_ = new Person[SIZE_FILL_ARR]
		{
			Person(579846, "Власов А.Ф", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(324987, "Данилов Г.Г", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654981, "Крылов Д.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(789165, "Авдеев В.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(645954, "Овчинников Р.Ф", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(989234, "Архипов А.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(651579, "Терентьев Т.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654621, "Емельянов Б.Г", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654653, "Александров В.Г", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(216577, "Игнатов А.П", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(654982, "Белов О.А", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
			Person(215440, "Пестов А.Д", getRand(10, 80) * 1000, getRand(1995, 2021), getRand(15, 20), getRand(1, 15)),
		};

	}

	// деструктор 
	~App() = default;


#pragma region Задание 1

	// Задание 1. Работа с массивами вещественных чисел (double)
	void task1();

	// инициалзиция конейнера 
	void fillContainer(Container<double>& container, double minValue, double maxValue, int n);

	// вывод шапки для таблицы 
	void showTable(const char* nameClass, const char* nameSort, const char* nameForeach, Container<double>& container);

	// вывод элементов
	void showElem(Container<double>& container);

	// Демонстрация функций Bubble
	void demoBubble();

	// Демонстрация функций Choice
	void demoChoice();

	// Демонстрация функций QSort
	void demoQSort();

#pragma endregion

#pragma region Задание 2

	// Задание 2
	void task2();

	// Заполнение списка рабочих
	void fillPersons();

	// Генерация исключений
	void genExceptionAddList();

	// Генерация исключений при создании объекта
	void genExceptionCreate();

	// Вывод двусвязого списка
	void printList();

	// Вывод бинарного дерева
	void printTree();

	// сумма начислений по двусвязному списку
	double accruedAll(DblList<Person> list);

	// добавление одного элемента в список
	void addPerson(Person& person, DblList<Person> list);

	// добавление одного элемента в дерево
	void addPerson(Person& person, BinaryTree<Person> tree);

	// добавление массива элементов в список
	void addAllPerson(Person* data, int n, DblList<Person> list);

	// добавление массива элементов в дерево
	void addAllPerson(Person* data, int n, BinaryTree<Person> tree);

	// добавление номера в базу номеров
	bool registrationNumber(unsigned int number);

	// обход узлов дерева для вывода в таблицу
	static void showElementPerson(BinaryTree<Person>::NodeTree<Person>* node, int& index);

	// вывод дерева в таблицу
	void showPerson(BinaryTree<Person> tree);

	// вывод списка в виде таблицы
	void showPerson(DblList<Person> list);

#pragma endregion

};

