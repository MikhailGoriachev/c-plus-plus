#include "Book.h"

#pragma region Конструкторы, деструктор и перегрузка операции присваивания

	// конструктор инициализирующий генерирующий ID
	Book::Book(string nameAuthor, string nameBook, int year, int countBook)
	{
		// установка идентификатора книги
		setId(genId());
	
		// установка значений 
		setNameAuthor(nameAuthor);
		setNameBook(nameBook);
		setYear(year);
		setCountBook(countBook);
	}

	// конструктор инициализирующий принимающий ID
	Book::Book(string id, string nameAuthor, string nameBook, int year, int countBook)
	{
		// установка идентификатора книги
		setId(id);

		// установка значений 
		setNameAuthor(nameAuthor);
		setNameBook(nameBook);
		setYear(year);
		setCountBook(countBook);
	}

	// декструктор 
	Book::~Book()
	{
		// удалание из базы ID
		// baseID_.erase(id_);
	}

#pragma endregion

#pragma region Сеттеры и гетторы

	// сеттер id_
	void Book::setId(string id)
	{
		// размер поля ID
		int size = (int)id.size();

		// если id неуникален 
		if (size != N_ID)
			throw exception("App: Некорректные данные");

		// установка ID
		id_ = id;
	}

	// геттер id_
	string Book::getId() { return id_; }
	
	// сеттер nameAuthor_ 
	void Book::setNameAuthor(string nameAuthor)
	{
		// размер строкиы
		int size = (int)nameAuthor.size();
	
		// если данные некорректны 
		if (size < N_MIN_NAME_AUTHOR or size > N_MAX_NAME_AUTHOR)
			throw exception("App: некорректные данные");
	
		// установка значения 
		nameAuthor_ = nameAuthor;
	}
	
	// геттер nameAuthor_
	string Book::getNameAuthor() { return nameAuthor_; }
	
	// сеттер nameBook_
	void Book::setNameBook(string nameBook)
	{
		// размер строкиы
		int size = (int)nameBook.size();
	
		// если данные некорректны 
		if (size < N_MIN_NAME_BOOK or size > N_MAX_NAME_BOOK)
			throw exception("App: некорректные данные");
	
		// установка значения 
		nameBook_ = nameBook;
	}
	
	// геттер nameBook_
	string Book::getNameBook() { return nameBook_; }

	// сеттер year_
	void Book::setYear(int year)
	{
		time_t now = time(0);

		tm* date = localtime(&now);

		// текущий год
		int currentYear = date->tm_year + 1900;

		// если данные некорректны 
		if (year < V_MIN_YEAR or year > currentYear)
			throw exception("App: некорректные данные");

		// установка значения 
		year_ = year;
	}

	// геттер year_
	int Book::getYear() { return year_; }
	
	// сеттер countBook_
	void Book::setCountBook(int countBook)
	{
		// если данные некорректны 
		if (countBook < V_MIN_COUNT_BOOK or countBook > V_MAX_COUNT_BOOK)
			throw exception("App: некорректные данные");
	
		// установка значения 
		countBook_ = countBook;
	}
	
	// геттер countBook_
	int Book::getCountBook() { return countBook_; }

#pragma endregion

#pragma region Методы 
 
	// генерация идентификатора
	string Book::genId()
	{
		// строка для ID
		string line;

		// генерация ID

		for (int i = 0; i < N_ID; i++)
		{
			line += to_string(getRand(0, 9));
		}

		return line;
	}

#pragma endregion 

#pragma region Дружественные функции 

	// перегрузка операции вывода в консоль 
	ostream& operator<<(ostream& os, const Book& book)
	{
		os << book.id_ << ";" << book.nameAuthor_ << ";" << book.nameBook_ << ";" 
			<< book.year_ << ";" << book.countBook_ << "\n";

		return os;
	}
	
	// перегрузка операции вывода в текстовый файл 
	ofstream& operator<<(ofstream& ofs, const Book& book)
	{
		ofs << book.id_ << ";" << book.nameAuthor_ << ";" << book.nameBook_ << ";"
			<< book.year_ << ";" << book.countBook_ << "\n";

		return ofs;
	}
	
	fstream& operator<<(fstream& fs, const Book& book)
	{
		fs << book.id_ << ";" << book.nameAuthor_ << ";" << book.nameBook_ << ";"
			<< book.year_ << ";" << book.countBook_ << "\n";

		return fs;
	}

	// перегрузка операции ввода из istream
	istream& operator>>(istream& is, Book& book)
	{
		// буфер строки
		string tmpStr;

		// буфер числа
		int tmpNum;

		// считываение данных из файла и установка значений че
		getline(is, tmpStr, ';');
		book.setId(tmpStr);

		getline(is, tmpStr, ';');
		book.setNameAuthor(tmpStr);

		getline(is, tmpStr, ';');
		book.setNameBook(tmpStr);

		is >> tmpNum;
		is.ignore(1, ';');
		book.setYear(tmpNum);

		is >> tmpNum;
		is.ignore(1, '\n');
		book.setCountBook(tmpNum);

		return is;
	}
	
	// перегрузка операции ввода из текстового файла
	ifstream& operator>>(ifstream& ifs, Book& book)
	{
		// буфер строки
		string tmpStr;

		// буфер числа
		int tmpNum;

		// считываение данных из файла и установка значений че
		getline(ifs, tmpStr, ';');
		book.setId(tmpStr);

		getline(ifs, tmpStr, ';');
		book.setNameAuthor(tmpStr);

		getline(ifs, tmpStr, ';');
		book.setNameBook(tmpStr);

		ifs >> tmpNum;
		ifs.ignore(1, ';');
		book.setYear(tmpNum);

		ifs >> tmpNum;
		ifs.ignore(1, '\n');
		book.setCountBook(tmpNum);

		return ifs;
	}

	fstream& operator>>(fstream& fs, Book& book)
	{
		// буфер строки
		string tmpStr;

		// буфер числа
		int tmpNum;

		// считываение данных из файла и установка значений че
		getline(fs, tmpStr, ';');
		book.setId(tmpStr);

		getline(fs, tmpStr, ';');
		book.setNameAuthor(tmpStr);

		getline(fs, tmpStr, ';');
		book.setNameBook(tmpStr);

		fs >> tmpNum;
		fs.ignore(1, ';');
		book.setYear(tmpNum);

		fs >> tmpNum;
		fs.ignore(1, '\n');
		book.setCountBook(tmpNum);

		return fs;
	}


#pragma endregion

#pragma endregion