#include "Book.h"

#pragma region ������������, ���������� � ���������� �������� ������������

	// ����������� ���������������� ������������ ID
	Book::Book(string nameAuthor, string nameBook, int year, int countBook)
	{
		// ��������� �������������� �����
		setId(genId());
	
		// ��������� �������� 
		setNameAuthor(nameAuthor);
		setNameBook(nameBook);
		setYear(year);
		setCountBook(countBook);
	}

	// ����������� ���������������� ����������� ID
	Book::Book(string id, string nameAuthor, string nameBook, int year, int countBook)
	{
		// ��������� �������������� �����
		setId(id);

		// ��������� �������� 
		setNameAuthor(nameAuthor);
		setNameBook(nameBook);
		setYear(year);
		setCountBook(countBook);
	}

	// ����������� 
	Book::~Book()
	{
		// �������� �� ���� ID
		// baseID_.erase(id_);
	}

#pragma endregion

#pragma region ������� � �������

	// ������ id_
	void Book::setId(string id)
	{
		// ������ ���� ID
		int size = (int)id.size();

		// ���� id ���������� 
		if (size != N_ID)
			throw exception("App: ������������ ������");

		// ��������� ID
		id_ = id;
	}

	// ������ id_
	string Book::getId() { return id_; }
	
	// ������ nameAuthor_ 
	void Book::setNameAuthor(string nameAuthor)
	{
		// ������ �������
		int size = (int)nameAuthor.size();
	
		// ���� ������ ����������� 
		if (size < N_MIN_NAME_AUTHOR or size > N_MAX_NAME_AUTHOR)
			throw exception("App: ������������ ������");
	
		// ��������� �������� 
		nameAuthor_ = nameAuthor;
	}
	
	// ������ nameAuthor_
	string Book::getNameAuthor() { return nameAuthor_; }
	
	// ������ nameBook_
	void Book::setNameBook(string nameBook)
	{
		// ������ �������
		int size = (int)nameBook.size();
	
		// ���� ������ ����������� 
		if (size < N_MIN_NAME_BOOK or size > N_MAX_NAME_BOOK)
			throw exception("App: ������������ ������");
	
		// ��������� �������� 
		nameBook_ = nameBook;
	}
	
	// ������ nameBook_
	string Book::getNameBook() { return nameBook_; }

	// ������ year_
	void Book::setYear(int year)
	{
		time_t now = time(0);

		tm* date = localtime(&now);

		// ������� ���
		int currentYear = date->tm_year + 1900;

		// ���� ������ ����������� 
		if (year < V_MIN_YEAR or year > currentYear)
			throw exception("App: ������������ ������");

		// ��������� �������� 
		year_ = year;
	}

	// ������ year_
	int Book::getYear() { return year_; }
	
	// ������ countBook_
	void Book::setCountBook(int countBook)
	{
		// ���� ������ ����������� 
		if (countBook < V_MIN_COUNT_BOOK or countBook > V_MAX_COUNT_BOOK)
			throw exception("App: ������������ ������");
	
		// ��������� �������� 
		countBook_ = countBook;
	}
	
	// ������ countBook_
	int Book::getCountBook() { return countBook_; }

#pragma endregion

#pragma region ������ 
 
	// ��������� ��������������
	string Book::genId()
	{
		// ������ ��� ID
		string line;

		// ��������� ID

		for (int i = 0; i < N_ID; i++)
		{
			line += to_string(getRand(0, 9));
		}

		return line;
	}

#pragma endregion 

#pragma region ������������� ������� 

	// ���������� �������� ������ � ������� 
	ostream& operator<<(ostream& os, const Book& book)
	{
		os << book.id_ << ";" << book.nameAuthor_ << ";" << book.nameBook_ << ";" 
			<< book.year_ << ";" << book.countBook_ << "\n";

		return os;
	}
	
	// ���������� �������� ������ � ��������� ���� 
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

	// ���������� �������� ����� �� istream
	istream& operator>>(istream& is, Book& book)
	{
		// ����� ������
		string tmpStr;

		// ����� �����
		int tmpNum;

		// ����������� ������ �� ����� � ��������� �������� ��
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
	
	// ���������� �������� ����� �� ���������� �����
	ifstream& operator>>(ifstream& ifs, Book& book)
	{
		// ����� ������
		string tmpStr;

		// ����� �����
		int tmpNum;

		// ����������� ������ �� ����� � ��������� �������� ��
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
		// ����� ������
		string tmpStr;

		// ����� �����
		int tmpNum;

		// ����������� ������ �� ����� � ��������� �������� ��
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