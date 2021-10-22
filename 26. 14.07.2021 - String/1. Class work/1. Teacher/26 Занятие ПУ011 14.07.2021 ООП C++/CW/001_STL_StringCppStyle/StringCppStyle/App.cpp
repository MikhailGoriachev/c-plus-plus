#include "pch.h"
#include "App.h"

// string - шаблонный класс из STL
//          динамическая строка, может изменяться
// конструкторы строк string, перегруженные операции со строками
void App::doDemoConstructors()
{
	// некоторые конструкторы строк
	string str1, str2(80, '—');
	string str3("Это строка в стиле C - const char *");  // из C-строки
	string str3a("Это строка в стиле C++ - string"s);  // из string
	string str4(str3);  // копирующий

	// операция вывода перегружена для string
	cout << "\""  << str1 << "\"\n" << str2 << "\n";
	cout << str3 << "\n" << str4 << "\n\n";

	// операции + +=  конкатенация строк, безопасная операция
	cout << "\n    Конкатенация строк. Операции += и +\n";
	str4 += str3;
	str3 = str2 + "\n" + str2 + "\n";
	cout << str3 << "\n" << str4 << "\n\n";

	// операция []
	cout << "    Операция []:\n";
	for (int i = 0; i < 10; ++i) str3[i] = 'ё';
	cout << str3;

	for (int i = 0; i < 10; ++i) cout << str3.at(i);
	cout << "\n";
	
	// Операции сравнение строк
	str1 = "Макеевка";
	str2 = "Горловка";
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
	
	cout<< "\n    Ввод строки (до пробела): ";
	cin >> str4; // ввод до первого разделителя
	cout << "    " << str4 << "\n";
	cin.ignore(cin.rdbuf()->in_avail(), '\n');
	
	cout<< "\n    Ввод строки с разделителями: ";

	// cin.getline()  - не работает с классом string, поэтому getline()
	getline(cin, str4);
	cout << "    " << str4 << "\n";

} // App::doDemoConstructors


// информационные методы строк 
void App::doDemoInfo()
{
	string str = "Это текст строки";
	cout<< str << "\n"
	    << "Длина строки  : " << str.size() << "\n" 
	    << "Длина строки  : " << str.length() << "\n"
	    << "max_size      : " << str.max_size() << "\n"
	    << "empty         : " << boolalpha << str.empty() << "\n"
	    << "Емкость строки: " << str.capacity() << "\n\n";
	
	for(int i = 0; i < 5; ++i) {
		str += ". Добавка к строке";
		cout<< str << "\n"
	        << "Длина строки  : " << str.size() << "\n" 
	        // << "Длина строки  : " << str.length() << "\n"
	        << "Емкость строки: " << str.capacity() << "\n\n";
	} // for i
	
} // App::doDemoInfo

// некоторые обрабатывающие методы строки
void App::doDemoMethods()
{
	string str = "кот ломом колол слона";
	string str1;

	cout << "\nassign()\n\n";
	// str1 = str;
	str1.assign(str);
	cout << "str1 = " << str1 << "\n";

	str1.assign("А роза упала на лапу Азора");
	cout << "str1 = " << str1 << "\n";

	// начиная с 10го символа...
	str1.assign(str, 10);
	cout << "str1 = \"" << str1 << "\"\n";
	
	// +=
	cout << "\n\nappend()\n";
	str1.append(", строка 1. ");          // литеал
	str1.append(str, 1, 10);   // часть строки
	str1.append(str, 10);            // от заданнй позиции до конца
	str1.append(str);                     // всю строку
	cout << "str1 = \"" << str1 << "\"\n";
	
	// insert()
	cout << "\n\ninsert()\n";
	string str2 = "пушистый гаденыш ";

	str.insert(4, "Вася ");
	cout << str << "\n";
	
	str.insert(0, "белый ");
	cout << str << "\n";
	
	//           смещение в исх. строке              строкаДляВставки   смещениеВстрокеДляВставки,  длинаВставки 
	str.insert("белый кот "s.size(), str2,         0,                    9);
	// str.insert("белый кот "s.size(), str2);  // вставить всю строку
	cout << str << "\n";


	cout << "\n\n==================================================================\n    replace()\n";
	str.replace(0, 3, "мутировавш");
	cout << str << "\n";
	
	str.replace(0, 13, str2);
	cout << str << "\n";
	
	// удаление
	// str.begin(), str.end() - прямые итераторы строки
	// str.begin() + смещение
	cout<< "\n\nerase()\n";
	str.erase(0, 9);      // !!!!! 2021 !!!!!
	// str.erase(str.begin(), str.begin()+9);
	cout << str << "\n";
	
	str.erase();
	// str.erase(str.begin(), str.end());
	cout << "\"" << str << "\"\n";

	str = "кот ломом колол слона";
	cout << "\n\nswap():\n";
	cout << "str  = " << str << "\n";
	cout << "str2 = " << str2 << "\n";
	str.swap(str2);
	cout << "str  = " << str << "\n";
	cout << "str2 = " << str2 << "\n";

	// получить С-константную строку
	const char *cstr = str2.c_str();
	cout << cstr << "\n";

	char *data = new char[str2.size() + 1];
	str2.copy(data, str2.size());  // без \n
	data[str2.size()] = 0;
	cout << data << "\n";
	delete[] data;

	// найти все вхождения строки "ло"
	cout << "\n\nfind()\n";
	int pos = 0;
	while(true) {
		pos = str2.find("ло", pos);

		// не нашли string::npos
		if (pos == string::npos) break;
		cout << pos << "\n";
		
		pos++;
	}

	// удалить все вхождения строки "ло"
	cout << "\n\nerase()\n";
	pos = 0;
	while(true) {
		pos = str2.find("ло", pos);
		if (pos == string::npos) break;
		str2.erase(pos, 2);
	}
	cout << str2 << "\n\n";

	// добавть символ в конец строки
	str2.push_back('!');
	cout << str2 << "\n";

	// удалить символ с конца строки
	str2.pop_back();
	cout << str2 << "\n";
} // App::doDemoMethods


// Запись строк в файлы, чтение строк из файлов
void App::doDemoFiles()
{
	fstream fs("1.txt", ios::out);
	string str = "Это пример строки";
	
	for (int i = 0; i < 5; i++) {
		fs << str << endl;
	}
	fs.close();

	// чтение из файла - getline()
	fs.open("1.txt", ios::in);

	while(!fs.eof()) {
		getline(fs, str);
		cout << str << endl;
	}
	fs.close();

	fs.open("1.bin", ios::out | ios::binary);
	
	str = "Это пример строки";

	// запись в бинарный файл - C-строка, получаемая через вызов c_str() 
	char* buf = new char[61];
    for (int i = 0; i < 5; i++) {
		// с чисткой буфера
		memset(buf, 0, 61);
	    strcpy(buf, str.c_str());
		fs.write(buf, 61);

		// простейший вариант без чистки
	    // fs.write(str.c_str(), 61);
	}
	fs.close();
	// delete[] buf;

	// чтение из бинарного файла - читаем в массив, формируем строку из массива 
	cout << "\n\nбинарный поток, чтение\n";
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

// Дополнительные методы поиска в строке
void App::doDemoFind()
{
	string str = "   кот   ломом  колол   слона   ";
	string s1 = "ло";
	string vowels = "аеёиоуыэюя";

	cout << "\n\n\n\n    \"" << str << "\"\n\n";
	int pos = str.rfind(s1);
	cout << "    rfind, ищем \"" << s1 << "\": " << pos << "\n";

	pos = str.find_first_of(vowels);
	cout << "    find_first_of, ищем первую гласную: " << pos << "\n";

	pos = str.find_last_of(vowels);
	cout << "    find_last_of, ищем последнюю гласную: " << pos << "\n\n";

	pos = str.find_first_not_of(" \n\t\r");
	cout << "    find_first_not_of, ищем первый непробельный символ: " << pos << "\n";

	pos = str.find_last_not_of(" \n\t\r");
	cout << "    find_last_not_of, ищем последний непробельный символ: " << pos << "\n";

	
} // App::doDemoFind