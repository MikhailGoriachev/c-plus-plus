// Контейнеры STL: ассоциативные контейнеры/ассоциативные массивы/отображения

// pair     - пара: ключ (key, first) - значение (value, second), first - second 
// map      - словарь - коллекция уникальных ключей, т.е. ключ не повторяется
// multimap - словарь - коллекция ключей с повторениями
// set      - множество - коллекция уникальных ключей (вторая часть пары не хранится)
// multiset - множество с повторением
// bitset   - битовое множество

#include "pch.h"
#include "App.h"

#include "Utils.h"
#include "Order.h"
#include <vector>
#include <map>
#include <set>

// вспомогательный класс - пара. На основе этого класса строим 
// ассоциативные контейнеры
void App::demoPair()
{
	pair<int, string> pair1(120, "текст для обработки");
	cout << "    pair1<int, string> = " << pair1.first << ": " << pair1.second << endl;	
	
	pair<string, string> pair2("a bad cold", "простуда");
	cout << "    pair2<string, string> = " << pair2.first << ": " << pair2.second << endl;	
	
	pair<int, Order> pair3(1001, Order("Моспино", "ДМ37383", "Романофф Н.А.", Date(5, 8, 2021)));
	cout << "    pair3<int, Order> = " << pair3.first << ": " << pair3.second << endl;

	auto pair4 = make_pair(1001, "Тестовое задание"s);
	cout << "    pair4 = " << pair4.first << ": " << pair4.second << endl;

	pair<Date, Order> pair5 = make_pair(Date(14, 7, 2021), Order("Сочи", "ALF4544", "Олег В.С.", Date(16, 8, 2021)));
	cout << "    pair5 = " << pair5.first << ": " << pair5.second << endlm(4);

	auto pair6 = make_pair(Date(14, 7, 2021), Order("Сочи", "ALF4544", "Олег В.С.", Date(16, 8, 2021)));
	cout << "    pair6 = " << pair5.first << ": " << pair5.second << endlm(4);
} // App::demoPair



// Словари, отображения, map
void App::demoMap()
{
	showNavBarMessage(hintColor, "  Класс map - словарь, отображение");
	cout << "\n\n\n\n";
	string sep = string(40, '—');

	/*
    //  тип ключа, тип значения
    map<int, string> map1;
	
	// добавление элемента в map [] по ключу
	// имяMap[ключ] = значение;
	map1[100] = "начало";
	//   ключ   значение
	//   вывод значения по ключу при помощи []
	cout << "    map: " << map1[100] << " | " << map1.size() << "\n";


	// вставка нового значения - место выбирает map
	map1.insert(make_pair(95, "продолжение"));
    map1[102] = "антракт";
	cout << "    map: " << map1[95] << " | " << map1.size() << "\n";
	cout << "    map: " << map1[102] << " | " << map1.size() << "\n";

	// вставка нового значения - место выбирает map, начиная с заданного итератора
	map1.insert(map1.begin(), map<int, string>::value_type(103, "далее"));
	cout << "    map: " << map1[103] << " | " << map1.size() << "\n";
	cout << "\n    " << sep << "\n\n";

    // вставка нового значения - место выбирает map 
	map1.insert(make_pair(90, "привет"));
	map1.insert(make_pair(80, "пока"));
    map1.insert(make_pair(91, "арбуз"));
    map1.insert(make_pair(81, "яблоко"));

	for(auto item:map1) 
		cout << "    " << item.first << " --> " << item.second << "\n";
	*/

	map<string, vector<Date>> map2;
	
	// создание вектора из массива
	Date dates1[3] = {
		Date(1, 1, 2021),
		Date(7, 1, 2021),
		Date(8, 3, 2021 )};
	vector<Date> v(dates1, dates1+3);
	map2.insert(make_pair("Выходные дни", v));
    cout<< "\n    " << sep << "\n";

	// пример добавления в second, если second - коллекция
	map2["Выходные дни"].push_back(Date(2, 5, 2021));
	
	for(auto item:map2) {
		cout << endl << "    " << item.first << ":\n";
		for(auto date:item.second)
			cout << "    " << date << "\n";
	} // for item

    // создание вектора из массива
	Date dates2[4] = {
		Date(12, 1, 2021),
		Date(17, 3, 2019), 
		Date(8, 3, 2019),
		Date(17, 7, 2019)
	};
    vector<Date> v1({Date(25, 7, 2021), Date(1, 8, 2021), Date(8, 8, 2021)});
	vector<Date> v2(dates2, dates2+4);
	// map2.insert(make_pair("Выходные дни", v1));
	map2.insert_or_assign("Выходные дни", v1);
	map2.insert_or_assign("Каникулы", v1);
	map2.insert(make_pair("Произвольные дни", v2));

	cout<< "\n" << sep << "\n";
	for(auto item:map2) {
		cout << endl << "    " << item.first << ":\n";
		for(auto date:item.second)
			cout << "    " << date << "\n";
	} // for item
	
	map2.erase("Каникулы");
	cout << "\n" << sep << "\n";
	for (auto item : map2) {
		cout << endl << "    " << item.first << ":\n";
		for (auto date : item.second)
			cout << "    " << date << "\n";
	} // for item

	auto it = map2.find("Выходные дни");
	if (it == map2.end())
		cout << "\n    НЕ найдено\n";
	else
		cout << "\n    найдено, первый выходной: " << it->second[0].toString() << "\n";
} // App::demoMap


// класс multimap
void App::demoMultimap()
{
	showNavBarMessage(hintColor, "  Класс multimap");
	cout << "\n\n\n\n";
	
	multimap<int, string> map1;

	// вставка нового значения - место выбирает map
	map1.insert(make_pair(101, "продолжение"));
	map1.insert(make_pair(101, "еще продолжение"));

	// вставка нового значения - место выбирает map, начиная с заданного итератора
	map1.insert(map1.begin(), map<int, string>::value_type(103, "далее"));
	map1.insert(map1.begin(), map<int, string>::value_type(103, "и еще далее"));
	map1.insert(map1.begin(), map<int, string>::value_type(103, "и еще далее далее"));
	map1.insert(make_pair(90, "привет"));
	map1.insert(make_pair(90, "калимерас"));
	map1.insert(make_pair(90, "hello"));
	map1.insert(make_pair(80, "пока"));
	map1.insert(make_pair(80, "bye"));

	// вывод multimap
	cout << "\n\n\n\n    Вывод объекта map1<int, string>:\n";
	for(auto item:map1) 
		cout << "    " << item.first << " --> " << item.second << "\n";
	
	// еще multimap - для класса Date
	multimap<string, vector<Date>> map2;

	Date dates1[3] = {
		Date(1, 1, 2020),
		Date(7, 1, 2020),
		Date(8, 3, 2020 )
	};
	vector<Date> v(dates1, dates1+3);
	map2.insert(make_pair("Выходные дни", v));

    // создание вектора из массива
	Date dates2[4] = {
		Date(12, 1, 2021),
		Date(17, 3, 2019), 
		Date(8, 3, 2019),
		Date(17, 7, 2019)};
	vector<Date> v1(dates1, dates1+3);
	vector<Date> v2(dates2, dates2+4);
	map2.insert(make_pair("Выходные дни", v1));
	map2.insert(make_pair("Произвольные дни", v2));
	map2.insert(make_pair("Произвольные дни", vector<Date>({Date(12, 5, 2021), Date(4, 7, 2021), Date(14, 7, 2021)})));

	cout<< "\n    multimap<string, vector<Date>>:\n";
	for(auto item:map2) {
		cout << endl << item.first << ":\n";
		for(auto date:item.second)
			cout << date <<"\n";
	} // for item
	
} // App::demoMultimap

// set - множество уникальных значений т.е. ключ генерируется автоматически
void App::demoSet()
{
	showNavBarMessage(hintColor, "  Класс set - множество уникальных значений");

	set<int> set1;
	
	set1.insert(100);
	// set1.insert(-5);
	// set1.insert(-5);
	set1.insert(-5);
	set1.insert(234);

	cout << "\n\n\n\n    set1: ";
	for(auto item:set1) 
		cout << setw(5) << item;
	cout<< endl;

	// добавление массива
	int arr[] = {2, 16, 8, 11};
	set1.insert(arr, arr+4);

	cout << "\n    set1: ";
	for(auto item:set1) 
		cout << setw(5) << item;
	cout<< endl;

	// доступ к элементам - через итератор
	cout<< "\n    Это элемент множества в позиции 1: " << color(hintColor)
	    << setw(4) << *(++set1.begin()) << "  "
	    << color(GRAY_ON_BLACK) << "\n\n";

	// для объекта требуется перегрузка операции == и <
	set<Date> set2;
	set2.insert(Date(17, 7, 2019));
	set2.insert(Date(12, 12, 2020));
	set2.insert(Date(31, 1, 2020));
	set2.insert(Date(12, 8, 2015));
	set2.insert(Date(31, 12, 2018));
	set2.insert(Date(31, 12, 2008));
	set2.insert(Date(31, 12, 2008));
	cout << "\n\n    set2:\n";
	for(auto item:set2) 
		cout << "    " << setw(20) << item << "\n";
	cout<< endl;
} // App::demoSet


// демо класса multiset
void App::demoMultiset()
{
	showNavBarMessage(hintColor, "  Класс multiset");

	multiset<int> set1;

	set1.insert(100);
	set1.insert(-5);
	set1.insert(-5);
	set1.insert(-5);
	set1.insert(234);

	cout << "\n\n\n\n    set1: ";
	for(auto item:set1) cout << setw(5) << item;
	cout<< endl;

	int arr[] = {12, -6, 8, 1, 8, 11, 8, 11};
	set1.insert(arr, arr+7);

	cout << "\n    set1: ";
	for(auto item:set1) cout << setw(5) << item;
	cout<< endl;

	// для объекта требуется перегрузка операции == и <
	multiset<Date> set2;
	set2.insert(Date(17, 7, 2019));
	set2.insert(Date(12, 8, 2015));
	set2.insert(Date(12, 8, 2015));
	set2.insert(Date(31, 12, 2018));
	set2.insert(Date(31, 12, 2008));
	set2.insert(Date(31, 12, 2008));

	cout << "\n\n    set2:\n";
	for(auto item:set2) 
		cout << "    " << setw(20) << item << "\n";
	cout<< endl;

	cout << "    " << set2.count(Date(12, 8, 2015)) << "\n";
} // App::demoMultiset