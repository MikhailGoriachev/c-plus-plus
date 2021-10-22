// ���������� STL: ������������� ����������/������������� �������/�����������

// pair     - ����: ���� (key, first) - �������� (value, second), first - second 
// map      - ������� - ��������� ���������� ������, �.�. ���� �� �����������
// multimap - ������� - ��������� ������ � ������������
// set      - ��������� - ��������� ���������� ������ (������ ����� ���� �� ��������)
// multiset - ��������� � �����������
// bitset   - ������� ���������

#include "pch.h"
#include "App.h"

#include "Utils.h"
#include "Order.h"
#include <vector>
#include <map>
#include <set>

// ��������������� ����� - ����. �� ������ ����� ������ ������ 
// ������������� ����������
void App::demoPair()
{
	pair<int, string> pair1(120, "����� ��� ���������");
	cout << "    pair1<int, string> = " << pair1.first << ": " << pair1.second << endl;	
	
	pair<string, string> pair2("a bad cold", "��������");
	cout << "    pair2<string, string> = " << pair2.first << ": " << pair2.second << endl;	
	
	pair<int, Order> pair3(1001, Order("�������", "��37383", "�������� �.�.", Date(5, 8, 2021)));
	cout << "    pair3<int, Order> = " << pair3.first << ": " << pair3.second << endl;

	auto pair4 = make_pair(1001, "�������� �������"s);
	cout << "    pair4 = " << pair4.first << ": " << pair4.second << endl;

	pair<Date, Order> pair5 = make_pair(Date(14, 7, 2021), Order("����", "ALF4544", "���� �.�.", Date(16, 8, 2021)));
	cout << "    pair5 = " << pair5.first << ": " << pair5.second << endlm(4);

	auto pair6 = make_pair(Date(14, 7, 2021), Order("����", "ALF4544", "���� �.�.", Date(16, 8, 2021)));
	cout << "    pair6 = " << pair5.first << ": " << pair5.second << endlm(4);
} // App::demoPair



// �������, �����������, map
void App::demoMap()
{
	showNavBarMessage(hintColor, "  ����� map - �������, �����������");
	cout << "\n\n\n\n";
	string sep = string(40, '�');

	/*
    //  ��� �����, ��� ��������
    map<int, string> map1;
	
	// ���������� �������� � map [] �� �����
	// ���Map[����] = ��������;
	map1[100] = "������";
	//   ����   ��������
	//   ����� �������� �� ����� ��� ������ []
	cout << "    map: " << map1[100] << " | " << map1.size() << "\n";


	// ������� ������ �������� - ����� �������� map
	map1.insert(make_pair(95, "�����������"));
    map1[102] = "�������";
	cout << "    map: " << map1[95] << " | " << map1.size() << "\n";
	cout << "    map: " << map1[102] << " | " << map1.size() << "\n";

	// ������� ������ �������� - ����� �������� map, ������� � ��������� ���������
	map1.insert(map1.begin(), map<int, string>::value_type(103, "�����"));
	cout << "    map: " << map1[103] << " | " << map1.size() << "\n";
	cout << "\n    " << sep << "\n\n";

    // ������� ������ �������� - ����� �������� map 
	map1.insert(make_pair(90, "������"));
	map1.insert(make_pair(80, "����"));
    map1.insert(make_pair(91, "�����"));
    map1.insert(make_pair(81, "������"));

	for(auto item:map1) 
		cout << "    " << item.first << " --> " << item.second << "\n";
	*/

	map<string, vector<Date>> map2;
	
	// �������� ������� �� �������
	Date dates1[3] = {
		Date(1, 1, 2021),
		Date(7, 1, 2021),
		Date(8, 3, 2021 )};
	vector<Date> v(dates1, dates1+3);
	map2.insert(make_pair("�������� ���", v));
    cout<< "\n    " << sep << "\n";

	// ������ ���������� � second, ���� second - ���������
	map2["�������� ���"].push_back(Date(2, 5, 2021));
	
	for(auto item:map2) {
		cout << endl << "    " << item.first << ":\n";
		for(auto date:item.second)
			cout << "    " << date << "\n";
	} // for item

    // �������� ������� �� �������
	Date dates2[4] = {
		Date(12, 1, 2021),
		Date(17, 3, 2019), 
		Date(8, 3, 2019),
		Date(17, 7, 2019)
	};
    vector<Date> v1({Date(25, 7, 2021), Date(1, 8, 2021), Date(8, 8, 2021)});
	vector<Date> v2(dates2, dates2+4);
	// map2.insert(make_pair("�������� ���", v1));
	map2.insert_or_assign("�������� ���", v1);
	map2.insert_or_assign("��������", v1);
	map2.insert(make_pair("������������ ���", v2));

	cout<< "\n" << sep << "\n";
	for(auto item:map2) {
		cout << endl << "    " << item.first << ":\n";
		for(auto date:item.second)
			cout << "    " << date << "\n";
	} // for item
	
	map2.erase("��������");
	cout << "\n" << sep << "\n";
	for (auto item : map2) {
		cout << endl << "    " << item.first << ":\n";
		for (auto date : item.second)
			cout << "    " << date << "\n";
	} // for item

	auto it = map2.find("�������� ���");
	if (it == map2.end())
		cout << "\n    �� �������\n";
	else
		cout << "\n    �������, ������ ��������: " << it->second[0].toString() << "\n";
} // App::demoMap


// ����� multimap
void App::demoMultimap()
{
	showNavBarMessage(hintColor, "  ����� multimap");
	cout << "\n\n\n\n";
	
	multimap<int, string> map1;

	// ������� ������ �������� - ����� �������� map
	map1.insert(make_pair(101, "�����������"));
	map1.insert(make_pair(101, "��� �����������"));

	// ������� ������ �������� - ����� �������� map, ������� � ��������� ���������
	map1.insert(map1.begin(), map<int, string>::value_type(103, "�����"));
	map1.insert(map1.begin(), map<int, string>::value_type(103, "� ��� �����"));
	map1.insert(map1.begin(), map<int, string>::value_type(103, "� ��� ����� �����"));
	map1.insert(make_pair(90, "������"));
	map1.insert(make_pair(90, "���������"));
	map1.insert(make_pair(90, "hello"));
	map1.insert(make_pair(80, "����"));
	map1.insert(make_pair(80, "bye"));

	// ����� multimap
	cout << "\n\n\n\n    ����� ������� map1<int, string>:\n";
	for(auto item:map1) 
		cout << "    " << item.first << " --> " << item.second << "\n";
	
	// ��� multimap - ��� ������ Date
	multimap<string, vector<Date>> map2;

	Date dates1[3] = {
		Date(1, 1, 2020),
		Date(7, 1, 2020),
		Date(8, 3, 2020 )
	};
	vector<Date> v(dates1, dates1+3);
	map2.insert(make_pair("�������� ���", v));

    // �������� ������� �� �������
	Date dates2[4] = {
		Date(12, 1, 2021),
		Date(17, 3, 2019), 
		Date(8, 3, 2019),
		Date(17, 7, 2019)};
	vector<Date> v1(dates1, dates1+3);
	vector<Date> v2(dates2, dates2+4);
	map2.insert(make_pair("�������� ���", v1));
	map2.insert(make_pair("������������ ���", v2));
	map2.insert(make_pair("������������ ���", vector<Date>({Date(12, 5, 2021), Date(4, 7, 2021), Date(14, 7, 2021)})));

	cout<< "\n    multimap<string, vector<Date>>:\n";
	for(auto item:map2) {
		cout << endl << item.first << ":\n";
		for(auto date:item.second)
			cout << date <<"\n";
	} // for item
	
} // App::demoMultimap

// set - ��������� ���������� �������� �.�. ���� ������������ �������������
void App::demoSet()
{
	showNavBarMessage(hintColor, "  ����� set - ��������� ���������� ��������");

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

	// ���������� �������
	int arr[] = {2, 16, 8, 11};
	set1.insert(arr, arr+4);

	cout << "\n    set1: ";
	for(auto item:set1) 
		cout << setw(5) << item;
	cout<< endl;

	// ������ � ��������� - ����� ��������
	cout<< "\n    ��� ������� ��������� � ������� 1: " << color(hintColor)
	    << setw(4) << *(++set1.begin()) << "  "
	    << color(GRAY_ON_BLACK) << "\n\n";

	// ��� ������� ��������� ���������� �������� == � <
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


// ���� ������ multiset
void App::demoMultiset()
{
	showNavBarMessage(hintColor, "  ����� multiset");

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

	// ��� ������� ��������� ���������� �������� == � <
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