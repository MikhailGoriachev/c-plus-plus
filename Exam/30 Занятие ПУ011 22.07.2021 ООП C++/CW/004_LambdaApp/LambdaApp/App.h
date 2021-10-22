#pragma once
#include "pch.h"
#include "Bus.h"

// Обработка вектора целых чисел и вектора заявок на авиабилеты
class App
{
	static void showVectorPositive(const string &title, const vector<double> &v);
	static void showVectorNegative(const string& title, const vector<double>& v);
	
	static void saveVector(const string &fileName, vector<double> &v);
	static void loadVector(const string &fileName, vector<double>& v);

	// ----------------------------------------------------------------------------------

	// коллекция автобусов
	vector<Bus> buses_;

	// имя файла для коллекции автобусов
	string fileName_;

	void showBuses(const vector<Bus>& buses, const string& title);

	// загрузка коллекции автобусов из потока
	void loadFromStream();

	// сохранение коллекции автобусов в поток
	void saveToStream();

	// Начальное формирование коллекций автобусов
	void initialize();

	// проверка существования файла
	static bool fileExists(const string& fileName);

public:
	App():App("buses.txt") {}
	App(const string& fileName)
	{
		fileName_ = fileName;
	} // App
	
	// Обработка вектора при помощи анонимных функторов
	void demoVector();
	
	// Запись данных об автобусах в текстовый файл (форматированный поток вывода)
	void demoInitializeAndWrite();

	// Чтение данных об автобусах из текстового файла (форматированного потока ввода)
	void demoReadAndShow();

	// Вывод данных об автобусах при помощи алгоритма for_each() и лямбда-выражений
	void demoShowBuses();
	
	// Упорядочить коллекцию автобусов по регистрационным номерам, использовать sort()
	void demoOrderByRegNumber();
	
	// Упорядочить коллекцию автобусов по фамилии и инициалам водителя, использовать sort()
	void demoOrderByFullName();



	
};

