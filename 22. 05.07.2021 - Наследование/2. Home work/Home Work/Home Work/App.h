#pragma once
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "Palette.h"

#include "BinaryTree.h"
#include "Station.h"
#include "Subscriber.h"
#include "Date.h"
#include "Form.h"
#include "Stack.h"
#include "TRectangle.h"
#include "Queue.h"
#include "List.h"
#include "DblList.h"
#include "Triangle.h"

/*
	Задача 1.
	С использованием бинарного дерева поиска реализовать картотеку нуждающихся в 
	улучшении жилищных условий. Начальное заполнение картотеки – из массива.
	Элемент картотеки должен хранить фамилию, имя и отчество претендента, количество
	членов семьи, площадь квартиры в м2, количество комнат, дату постановки на учет 
	(день, месяц, год–класс Date). Добавление в картотеку выполняется по фамилии.
	Реализовать дополнительно операции:
		•	Поиск в картотеке по фамилии – находим первую подходящую фамилию, остальных 
			однофамильцев игнорировать
		•	Запись в бинарный файл всех элементов картотеки (в файле данные будут 
			упорядочены по алфавиту).
	Задача 2.
	Разработать класс для представления абонента телефонной станции с полями для 
	хранения:
		•	фамилии и инициалов
		•	телефонного номера
		•	времени разговоров (в минутах) за последний месяц.
	Разработать класс для представления телефонной станции с полями для хранения
	названия телефонной станции (код станции – три цифровых символа), текущий тариф
	за минуту разговора абонента, картотеки абонентов в виде бинарного дерева поиска.
	Ключом для узлов является телефонный номер абонента.
	Создать объект телефонной станции, заполнить картотеку из массива (не менее 10 
	записей), реализовать поиск по телефонному номеру, вывод сумм к оплате в порядке
	возрастания телефонных номеров.
*/

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
	// указатель на бинарное дерево нуждающихся в улучшении жилищных условий
	BinaryTree<Form> forms_;

	// телефонная станция
	Station station_;

	// стек с прямоугольниками
	Stack<TRectangle> stackRectangle_;

	// очередь с прямоугольниками
	Queue<TRectangle> queueRectangle_;

	// список треугольников 
	List<Triangle> listTriangle_;

	// двусвязный список с треугольниками
	DblList<Triangle> dblListTriangle_;


public:

	// конструктор по умолчанию
	App()
	{
		// массив нуждающихся в улучшении жилищных условий
		Form* form = new Form[10]{
			Form("Крылов", "Владислав", "Даниилович", 3, getRand(68., 82.), 3, Date(15, 12, 2003)),
			Form("Евдокимов", "Августин", "Никитевич", 1, getRand(36., 42.), 2, Date(6, 4, 2010)),
			Form("Алексеев", "Дмитрий", "Денисович", 2, getRand(54., 62.), 3, Date(30, 5, 2012)),
			Form("Рябов", "Клемент", "Константинович", 3, getRand(68., 82.), 5, Date(28, 2, 2021)),
			Form("Лыткин", "Бронислав", "Аркадьевич", 2, getRand(54., 62.), 4, Date(29, 2, 2016)),
			Form("Григорьев", "Ираклий", "Натанович", 1, getRand(36., 42.), 1, Date(3, 1, 1999)),
			Form("Максимова", "Ева", "Максовна", 1, getRand(36., 42.), 3, Date(25, 6, 2001)),
			Form("Карпов", "Любомир", "Артёмович", 2, getRand(54., 62.), 4, Date(23, 7, 2006)),
			Form("Жданов", "Нисон", "Русланович", 1, getRand(36., 42.), 3, Date(18, 3, 2004)),
			Form("Доронина ", "Роза", "Аристарховна", 2, getRand(54., 62.), 2, Date(17, 5, 2002))

		};

		// заполнение бинарного дерева
		forms_.addAll(form, 10);

		// отчистка памяти
		delete[] form;

		// массив телефонных абонентов
		Subscriber* subscribers = new Subscriber[10]
		{
			Subscriber("Крылов В.Д.",  		"0714567842", getRand(0, 600)),
			Subscriber("Евдокимов А.Н.",	"0717865486", getRand(0, 600)),
			Subscriber("Алексеев Д.Д.",		"0714213548", getRand(0, 600)),
			Subscriber("Рябов К.К.",  		"0719872145", getRand(0, 600)),
			Subscriber("Лыткин Б.А.",  		"0710974569", getRand(0, 600)),
			Subscriber("Григорьев И.Н.",  	"0717634765", getRand(0, 600)),
			Subscriber("Максимова Е.М.",	"0710347896", getRand(0, 600)),
			Subscriber("Карпов Л.А.",  		"0719374345", getRand(0, 600)),
			Subscriber("Жданов Н.Р.",  		"0713638462", getRand(0, 600)),
			Subscriber("Доронина Р.А.", 	"0717565384", getRand(0, 600))
		};

		// установка кода 
		station_.setName("071");

		// заполнение бинарного дерева массивом
		station_.setSubscribers(subscribers, 10);

		// установка тарифа
		station_.setRate((float)getRand(0.5, 5.5));

		// отчистка памяти
		delete[]subscribers;

		// массив примоугольников
		TRectangle* rectanglesByStack = new TRectangle[5]
		{
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
		};

		// заполнение стека с прямоугольниками
		stackRectangle_.pushAll(rectanglesByStack, 5);

		// массив прямоугольников
		TRectangle* rectanglesByQueue = new TRectangle[5]
		{
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
			TRectangle(getRand(5., 10.), getRand(1., 4.)),
		};

		// заполнение стека с прямоугольниками
		queueRectangle_.enqueueAll(rectanglesByQueue, 5);

		// массив треугольников 
		Triangle* trianglesList = new Triangle[5]
		{
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.))
		};

		listTriangle_.addAll(trianglesList, 5);

		// массив треугольников 
		Triangle* trianglesDblList = new Triangle[5]
		{
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.)),
			Triangle(getRand(1., 3.), getRand(2., 3.), getRand(2., 3.))
		};


		dblListTriangle_.addAll(trianglesDblList, 5);
	}

	// деструктор 
	~App() = default;

#pragma region Задания

#pragma region Задание 1. Прямоугольник

	// Задание 1. Прямоугольник
	void task1();

	// вывод прямоугольников стека, их периметров и площади в виде таблицы по итератору
	void showTableTRectangle(Stack<TRectangle>& stackTRectangle);

	// вывод прямоугольников очереди, их периметров и площади в виде таблицы по итератору
	void showTableTRectangle(Queue<TRectangle>& queueTRectangle);

#pragma endregion

#pragma region Задание 2. Треугольник

	// Задание 2. Треугольник
	void task2();

	// вывод прямоугольников, их периметров и площади в виде таблицы по итератору
	void showTableTriangle(List<Triangle>& listTriangle);

	// вывод прямоугольников, их периметров и площади в виде таблицы по итератору
	void showTableTriangle(DblList<Triangle>& dbllistTriangle);

#pragma endregion 

#pragma region Задание 3. Картотека нуждающихся в улучшении жилищных условий
	// Задание 3. Картотека нуждающихся в улучшении жилищных условий
	void task3();

	// Поиск в картотеке по фамилии
	void searchSurname();

	// запись в бинарный файл
	void writeFormBinFile();

	// вывод бинарного дерева с объектами Form в цвете
	void printBinaryTreeFormColorBack(BinaryTree<Form>::NodeTree<Form>* node);

	// вывод бинарного дерева с объектами Form в цвете
	void printBinaryTreeFormColor(BinaryTree<Form>::NodeTree<Form>* node);

	// обход узлов дерева для вывода в цвете объектов Form
	void showFormColor(BinaryTree<Form>::NodeTree<Form>* node, short cl, int& i);

	// обход узлов дерева для вывода в цвете объектов Form
	void showFormColorBack(BinaryTree<Form>::NodeTree<Form>* node, short cl, int& i);


#pragma endregion 

#pragma region Задание 4. Телефонная станция

	// Задание 4. Телефонная станция
	void task4();

	// поиск по телефонному номеру
	void searchNumber();

	// вывод сумм к оплате в порядке возрастания телефонных номеров
	void showPay();

	// вывод списка телефонных номеров в обратном порядке
	void showStation();

#pragma endregion

#pragma endregion

};

