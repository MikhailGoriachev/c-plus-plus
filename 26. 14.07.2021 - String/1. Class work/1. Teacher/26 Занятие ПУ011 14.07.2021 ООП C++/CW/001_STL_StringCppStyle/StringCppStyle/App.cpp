#include "pch.h"
#include "App.h"

// string - ��������� ����� �� STL
//          ������������ ������, ����� ����������
// ������������ ����� string, ������������� �������� �� ��������
void App::doDemoConstructors()
{
	// ��������� ������������ �����
	string str1, str2(80, '�');
	string str3("��� ������ � ����� C - const char *");  // �� C-������
	string str3a("��� ������ � ����� C++ - string"s);  // �� string
	string str4(str3);  // ����������

	// �������� ������ ����������� ��� string
	cout << "\""  << str1 << "\"\n" << str2 << "\n";
	cout << str3 << "\n" << str4 << "\n\n";

	// �������� + +=  ������������ �����, ���������� ��������
	cout << "\n    ������������ �����. �������� += � +\n";
	str4 += str3;
	str3 = str2 + "\n" + str2 + "\n";
	cout << str3 << "\n" << str4 << "\n\n";

	// �������� []
	cout << "    �������� []:\n";
	for (int i = 0; i < 10; ++i) str3[i] = '�';
	cout << str3;

	for (int i = 0; i < 10; ++i) cout << str3.at(i);
	cout << "\n";
	
	// �������� ��������� �����
	str1 = "��������";
	str2 = "��������";
	bool r = str1 < str2;
	cout << boolalpha << str1 << " <  " << str2 << ": " << r << "\n";
	r = str1 <= str2;
	cout << str1 << " <= " << str2 << ": " << r << "\n";
	r = str1 == str2;
	cout << str1 << " == " << str2 << ": " << r << "\n";
	r = str1 != str2;
	cout << str1 << " != " << str2 << ": " << r << "\n";
	r = str1 >= str2;
	cout << str1 << " >= " << str2 << ": " << r << "\n";
	r = str1 > str2;
	cout << str1 << " >  " << str2 << ": " << r << "\n";
	
	cout<< "\n    ���� ������ (�� �������): ";
	cin >> str4; // ���� �� ������� �����������
	cout << "    " << str4 << "\n";
	cin.ignore(cin.rdbuf()->in_avail(), '\n');
	
	cout<< "\n    ���� ������ � �������������: ";

	// cin.getline()  - �� �������� � ������� string, ������� getline()
	getline(cin, str4);
	cout << "    " << str4 << "\n";

} // App::doDemoConstructors


// �������������� ������ ����� 
void App::doDemoInfo()
{
	string str = "��� ����� ������";
	cout<< str << "\n"
	    << "����� ������  : " << str.size() << "\n" 
	    << "����� ������  : " << str.length() << "\n"
	    << "max_size      : " << str.max_size() << "\n"
	    << "empty         : " << boolalpha << str.empty() << "\n"
	    << "������� ������: " << str.capacity() << "\n\n";
	
	for(int i = 0; i < 5; ++i) {
		str += ". ������� � ������";
		cout<< str << "\n"
	        << "����� ������  : " << str.size() << "\n" 
	        // << "����� ������  : " << str.length() << "\n"
	        << "������� ������: " << str.capacity() << "\n\n";
	} // for i
	
} // App::doDemoInfo

// ��������� �������������� ������ ������
void App::doDemoMethods()
{
	string str = "��� ����� ����� �����";
	string str1;

	cout << "\nassign()\n\n";
	// str1 = str;
	str1.assign(str);
	cout << "str1 = " << str1 << "\n";

	str1.assign("� ���� ����� �� ���� �����");
	cout << "str1 = " << str1 << "\n";

	// ������� � 10�� �������...
	str1.assign(str, 10);
	cout << "str1 = \"" << str1 << "\"\n";
	
	// +=
	cout << "\n\nappend()\n";
	str1.append(", ������ 1. ");          // ������
	str1.append(str, 1, 10);   // ����� ������
	str1.append(str, 10);            // �� ������� ������� �� �����
	str1.append(str);                     // ��� ������
	cout << "str1 = \"" << str1 << "\"\n";
	
	// insert()
	cout << "\n\ninsert()\n";
	string str2 = "�������� ������� ";

	str.insert(4, "���� ");
	cout << str << "\n";
	
	str.insert(0, "����� ");
	cout << str << "\n";
	
	//           �������� � ���. ������              ����������������   �������������������������,  ������������ 
	str.insert("����� ��� "s.size(), str2,         0,                    9);
	// str.insert("����� ��� "s.size(), str2);  // �������� ��� ������
	cout << str << "\n";


	cout << "\n\n==================================================================\n    replace()\n";
	str.replace(0, 3, "����������");
	cout << str << "\n";
	
	str.replace(0, 13, str2);
	cout << str << "\n";
	
	// ��������
	// str.begin(), str.end() - ������ ��������� ������
	// str.begin() + ��������
	cout<< "\n\nerase()\n";
	str.erase(0, 9);      // !!!!! 2021 !!!!!
	// str.erase(str.begin(), str.begin()+9);
	cout << str << "\n";
	
	str.erase();
	// str.erase(str.begin(), str.end());
	cout << "\"" << str << "\"\n";

	str = "��� ����� ����� �����";
	cout << "\n\nswap():\n";
	cout << "str  = " << str << "\n";
	cout << "str2 = " << str2 << "\n";
	str.swap(str2);
	cout << "str  = " << str << "\n";
	cout << "str2 = " << str2 << "\n";

	// �������� �-����������� ������
	const char *cstr = str2.c_str();
	cout << cstr << "\n";

	char *data = new char[str2.size() + 1];
	str2.copy(data, str2.size());  // ��� \n
	data[str2.size()] = 0;
	cout << data << "\n";
	delete[] data;

	// ����� ��� ��������� ������ "��"
	cout << "\n\nfind()\n";
	int pos = 0;
	while(true) {
		pos = str2.find("��", pos);

		// �� ����� string::npos
		if (pos == string::npos) break;
		cout << pos << "\n";
		
		pos++;
	}

	// ������� ��� ��������� ������ "��"
	cout << "\n\nerase()\n";
	pos = 0;
	while(true) {
		pos = str2.find("��", pos);
		if (pos == string::npos) break;
		str2.erase(pos, 2);
	}
	cout << str2 << "\n\n";

	// ������� ������ � ����� ������
	str2.push_back('!');
	cout << str2 << "\n";

	// ������� ������ � ����� ������
	str2.pop_back();
	cout << str2 << "\n";
} // App::doDemoMethods


// ������ ����� � �����, ������ ����� �� ������
void App::doDemoFiles()
{
	fstream fs("1.txt", ios::out);
	string str = "��� ������ ������";
	
	for (int i = 0; i < 5; i++) {
		fs << str << endl;
	}
	fs.close();

	// ������ �� ����� - getline()
	fs.open("1.txt", ios::in);

	while(!fs.eof()) {
		getline(fs, str);
		cout << str << endl;
	}
	fs.close();

	fs.open("1.bin", ios::out | ios::binary);
	
	str = "��� ������ ������";

	// ������ � �������� ���� - C-������, ���������� ����� ����� c_str() 
	char* buf = new char[61];
    for (int i = 0; i < 5; i++) {
		// � ������� ������
		memset(buf, 0, 61);
	    strcpy(buf, str.c_str());
		fs.write(buf, 61);

		// ���������� ������� ��� ������
	    // fs.write(str.c_str(), 61);
	}
	fs.close();
	// delete[] buf;

	// ������ �� ��������� ����� - ������ � ������, ��������� ������ �� ������� 
	cout << "\n\n�������� �����, ������\n";
	fs.open("1.bin", ios::in | ios::binary);

	// *buf = new char[61];
	while(true) {
		fs.read(buf, 61);
		if (fs.eof()) break;
		str = buf;
		cout << str << endl;
	}
	fs.close();
	delete[] buf;
} // App::doDemoFile

// �������������� ������ ������ � ������
void App::doDemoFind()
{
	string str = "   ���   �����  �����   �����   ";
	string s1 = "��";
	string vowels = "���������";

	cout << "\n\n\n\n    \"" << str << "\"\n\n";
	int pos = str.rfind(s1);
	cout << "    rfind, ���� \"" << s1 << "\": " << pos << "\n";

	pos = str.find_first_of(vowels);
	cout << "    find_first_of, ���� ������ �������: " << pos << "\n";

	pos = str.find_last_of(vowels);
	cout << "    find_last_of, ���� ��������� �������: " << pos << "\n\n";

	pos = str.find_first_not_of(" \n\t\r");
	cout << "    find_first_not_of, ���� ������ ������������ ������: " << pos << "\n";

	pos = str.find_last_not_of(" \n\t\r");
	cout << "    find_last_not_of, ���� ��������� ������������ ������: " << pos << "\n";

	
} // App::doDemoFind