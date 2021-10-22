#pragma once

#include "pch.h"
#include "Utils.h"
#include "BinaryTree.h"
#include "Subscriber.h"


// бинарное дерево
// template <typename T>
// class BinaryTree;

// Класс телефонного абонента
// class Subscriber;


// Разработать класс для представления телефонной станции с полями для хранения
// названия телефонной станции(код станции – три цифровых символа), текущий тариф
// за минуту разговора абонента, картотеки абонентов в виде бинарного дерева поиска.
// Ключом для узлов является телефонный номер абонента.
// 

// Класс телефонной станции 
class Station
{
public:


	// размер поля названия телефонной станции
	static const int NAME_SIZE = 3;

	// максимальный тариф за минуту разговора
	static const float RATE_MAX;

	// минимальный тариф за минуту разговора
	static const float RATE_MIN;

private:

	// название телефонной станции (код станции – три цифровых символа)
	char* name_;

	// текущий тариф за минуту разговора абонента
	float rate_;

	// картотека абонентов в виде бинарного дерева поиска
	BinaryTree<Subscriber> subscribers_;

public:

#pragma region Конструкторы, деструктор, перегрузка операции присваивания

	// конструктор по умолчанию
	Station() : Station("000", 0, nullptr, 0) {}

	// инициализирующий конструктор
	Station(const char* name, float rate, Subscriber* arr, int n) :
		name_(new char[NAME_SIZE + 1]{ 0 })
	{
		setName(name);
		setRate(rate);

		subscribers_.addAll(arr, n);
	}

	// копирующий конструктор
	// !!! НЕПРАВИЛЬНОЕ РЕШЕНИЕ, ТАК КАК ЕЩЕ НЕ ГОТОВ КОПИРУЮЩИЙ КОНСТРУКТОР 
	// БИНАРНОГО ДЕРЕВА - ПРАВИЛЬНОЕ КОПИРОВАНИЕ НЕВОЗМОЖНО !!!
	Station(const Station& station) = default;

	// деструктор
	~Station()
	{
		delete[]name_;
	}

	// перегрузка операции присваивани
	// !!! НЕПРАВИЛЬНОЕ РЕШЕНИЕ, ТАК КАК ЕЩЕ НЕ ГОТОВА ОПЕРАЦИЯ ПРИСВАИВАНИЯ
	// БИНАРНОГО ДЕРЕВА - ПРАВИЛЬНОЕ ПРИСВАИВАНИЕ НЕВОЗМОЖНО !!!
	Station& operator=(const Station& station) = default;

#pragma endregion

#pragma region Сеттеры и геттеры

	// сеттер name_;
	void setName(const char* name)
	{
		int size = strlen(name);

		// если данные некорректны
		if (size != NAME_SIZE)
			throw exception("Station: Данные некорректны!");
		
		// проверка на то, что в строке только цифры
		for (int i = 0; i < NAME_SIZE; i++)
		{
			if (name[i] < '0' and name[i] > '9')
				throw exception("Station: Данные некорректны!");
		}

		// установка значения
		strncpy(name_, name, NAME_SIZE);
	}

	// геттер name_
	const char* getName() { return name_; }

	// сеттер rate_
	void setRate(float rate)
	{
		// если данные некорректны
		if (rate < RATE_MIN and rate < RATE_MAX)
			throw exception("Station: Данные некорректны!");

		rate_ = rate;
	}

	// геттер rate_
	float getRate() { return rate_; }

	// сеттер subscribers_
	void setSubscribers(Subscriber* arr, int n)
	{
		subscribers_.addAll(arr, n);
	}

#pragma endregion

#pragma region Методы

	// поиск по номеру
	BinaryTree<Subscriber>::NodeTree<Subscriber>* find(const char* number);

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream os, Station& station)
	{
		os << "Код станции: " << station.name_
			<< "\nТариф: " << station.rate_
			<< "\nАбоненты:\n" << station.subscribers_ << "\n";
	}

	// вывод в виде таблицы в цвете
	void showTable()
	{
		// текущий цвет по умолчанию
		short cl = getColor();

		
		cout << fixed;
		cout.precision(1);
		
		cout<< "\t+——————————————————————+\n"
			<< "\t|    Код станции: " << color(GREEN_ON_BLACK) << right << setw(4) << name_
			<< color(cl) << " |\n"
			<< "\t+——————————————————————+\n"
			<< "\t| Тариф(руб/мин): " << color(GREEN_ON_BLACK) << setw(4) << rate_
			<< color(cl) << " |\n" << left;

		// вывод элементов 
		printSubscriberColor();

	}

	// вывод в виде таблицы в цвете В ОБРАТНОМ ПОРЯДКЕ
	void showTableBack()
	{
		// текущий цвет по умолчанию
		short cl = getColor();


		cout << fixed;
		cout.precision(1);

		cout << "\t+——————————————————————+\n"
			<< "\t|    Код станции: " << color(GREEN_ON_BLACK) << right << setw(4) << name_
			<< color(cl) << " |\n"
			<< "\t+——————————————————————+\n"
			<< "\t| Тариф(руб/мин): " << color(GREEN_ON_BLACK) << setw(4) << rate_
			<< color(cl) << " |\n" << left;

		// вывод элементов 
		printSubscriberColorBack();

	}


	// вывод в виде таблицы в цвете + сумма к оплате
	void showTablePrice()
	{
		// текущий цвет по умолчанию
		short cl = getColor();


		cout << fixed;
		cout.precision(1);

		cout << "\t+——————————————————————+\n"
			<< "\t|    Код станции: " << color(GREEN_ON_BLACK) << right << setw(4) << name_
			<< color(cl) << " |\n"
			<< "\t+——————————————————————+\n"
			<< "\t| Тариф(руб/мин): " << color(GREEN_ON_BLACK) << setw(4) << rate_
			<< color(cl) << " |\n" << left;

		// вывод элементов 
		printSubscriberColorPrice();

	}


	// вывод бинарного дерева с объектами Subscriber в цвете
	void printSubscriberColor();

	// обход узлов дерева для вывода в цвете объектов Subscriber
	void showColor(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i);


	// вывод бинарного дерева с объектами Subscriber в цвете В ОБРАТНОМ ПОРЯДКЕ
	void printSubscriberColorBack();

	// обход узлов дерева для вывода в цвете объектов Subscriber В ОБРАТНОМ ПОРЯДКЕ
	void showColorBack(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i);



	// вывод бинарного дерева с объектами Subscriber в цвете
	// с суммой к оплате
	void printSubscriberColorPrice();

	// обход узлов дерева для вывода в цвете сумм к оплате объектов Subscriber
	void showColorPrice(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i, float& rate);


#pragma endregion

};

