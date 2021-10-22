#include "Library.h"

// ���� ������������� ����(������� �������)
// set<string> Library::baseID_ = set<string>();

#pragma region ������������, ����������, ���������� �������� ������������ 

	// ����������� ���������������� 
	Library::Library(string address, string nameDirector, string fileName) : books_()
	{
		// ��������� ��������
		setAddress(address);
		setNameDirector(nameDirector);
		setFileName(fileName);
	}
	
	// ����������� ���������������� (�������� �� �����)
	Library::Library(string fileName) 
	{
		// ��������� ����� ��� ���������� �� ���������
		setFileName(fileName);

		// �������� �� ����� 
		loadLibrary();
	}

	// ����������� ���������������� (�������� �� ������� Book)
	Library::Library(string address, string nameDirector, vector<Book>& books, string fileName)
	{
		// ��������� ��������
		setAddress(address);
		setNameDirector(nameDirector);
		setFileName(fileName);

		books_ = books;
	}

#pragma endregion 

#pragma region ������� � �������

	// ������ address_
	void Library::setAddress(string address)
	{
		// ����� ������
		int size = (int)address.size();

		// ���� ������ �����������
		if (size < N_MIN_ADDRESS or size > N_MAX_ADDRESS)
			throw exception("App: ������ �����������");

		// ��������� ��������
		address_ = address;
	}

	// ������ address_
	const string& Library::getAddress() { return address_; }

	// ������ nameDirector_
	void Library::setNameDirector(string nameDirector)
	{
		// ����� ������
		int size = (int)nameDirector.size();

		// ���� ������ �����������
		if (size < N_MIN_NAME_DIRECTOR or size > N_MAX_NAME_DIRECTOR)
			throw exception("App: ������ �����������");

		// ��������� ��������
		nameDirector_ = nameDirector;
	}

	// ������ nameDirector_
	const string& Library::getNameDirector() { return nameDirector_; }

	// ������ books_
	vector<Book>& Library::getBooks() { return books_; }

	// ������ fileName_
	void Library::setFileName(string fileName)
	{
		// ����� ������
		int size = (int)fileName.size();

		// ���� ������ �����������
		if (size < N_MIN_FILE_NAME or size > N_MAX_FILE_NAME)
			throw exception("App: ������ �����������");

		// ��������� ��������
		fileName_ = fileName;
	}

	// ������ fileName_
	const string& Library::getFileName() { return fileName_; }

#pragma endregion

#pragma region ������ 

	// �������� �������������� �� ������������
	// true - ID ��������, false - ID �� �������� 
	bool Library::checkId(string id)
	{
		// ������ ���������� ������
		int size = (int)id.size();

		// ���� ������ ������������ 
		if (size != Book::N_ID)
			throw exception("App: ������������ �������������");

		// ����� � ���� ���������������
		return baseID_.find(id) == baseID_.end();
	}

	// ��������� ��������������
	string Library::genId()
	{
		// ������ ��� ID
		string line;

		// ��������� ID
		do
		{
			line = Book::genId();
			
			// �������� �������������� �� ������������
		} while (!checkId(line));

		return line;
	}

	// ���������� ����� � ���������� 
	void Library::addBook(Book& book)
	{
		// ID �����
		string curID = book.getId();

		// �������� �� ������������ ID �����
		if (!checkId(book.getId()))
			throw exception(("App: ID "s + curID + " �� ��������!").c_str());

		// ���������� ����� 
		books_.push_back(book);

		// ���������� ID ����� � ����
		baseID_.insert(curID);
	}

	// ���������� ������� ���� � ����������
	void Library::addAllBook(vector<Book> books)
	{
		for_each(books.begin(), books.end(), [this](Book book) { this->addBook(book); });
	}

	// �������� ����� �� ����������
	void Library::removeBook(string id)
	{
		// ����� ID � ����
		if (checkId(id))
			throw exception(("App: ����� � ID "s + id + " �� �������").c_str());
	
		// �������� �����
		books_.erase(find_if(books_.begin(), books_.end(), [id](Book book) { return book.getId() == id; }));

		// �������� ID ����� �� ���� ������
		baseID_.erase(id);
	}

	// �������� ���������� �� ����
	void Library::clear()
	{
		// �������� ������� ����
		books_.clear();

		// �������� ���� ID
		baseID_.clear();
	}

	// ��������� ����� �� ID
	Book& Library::getBook(string id)
	{
		// ����� ID � ����
		if (checkId(id))
			throw exception(("App: ����� � ID "s + id + " �� �������").c_str());

		// ����� ����� �����
		return *find_if(books_.begin(), books_.end(), [id](Book book) { return book.getId() == id; });
	}

	// �������� ���������� �� ����� .csv - �� ���������
	void Library::loadLibrary()
	{
		// �������� �� ������� ����� 
		if (!checkFile(fileName_))
			throw exception(("App: ������ �������� ����� "s + fileName_).c_str());

		// �������� ������ ������ ����� 
		ifstream ifs(fileName_);

		// �������� ������ �� ����� 
		ifs >> *this;

		// �������� �����
		ifs.close();
	}

	// �������� ���������� �� ����� .csv - ���������� ����� 
	void Library::loadLibrary(string fileName)
	{
		// �������� �� ������� ����� 
		if (!checkFile(fileName_))
			throw exception(("App: ������ �������� ����� "s + fileName_).c_str());

		// �������� ������ ������ ����� 
		ifstream ifs(fileName_);

		// �������� ������ �� ����� 
		ifs >> *this;

		// �������� �����
		ifs.close();
	}

	// ���������� ���������� � ���� .csv - �� ���������
	void Library::saveLibrary()
	{
		// �������� ������ ������ ����� 
		ofstream ofs(fileName_);

		// ���� ���� �� ������� �������
		if (!ofs.is_open())
			throw exception(("App: �� ������� �������/������� ���� "s + fileName_ + "!").c_str());

		// �������� ������ �� ����� 
		ofs << *this;

		// �������� �����
		ofs.close();
	}

	// ���������� ���������� � ���� .csv - ���������� ����� 
	void Library::saveLibrary(string fileName)
	{
		// �������� ������ ������ ����� 
		ofstream ofs(fileName_);

		// ���� ���� �� ������� �������
		if (!ofs.is_open())
			throw exception(("App: �� ������� �������/������� ���� "s + fileName_ + "!").c_str());

		// �������� ������ �� ����� 
		ofs << *this;

		// �������� �����
		ofs.close();
	}

	// ���������� ���� � ���������� 
	int Library::countBooks() { return (int)books_.size(); }

	// ����� ������ ���������� � ��������� ���� � �������
	void Library::showLibrary(string nameLibrary, string info)
	{
		// ����� ����� ������� 
		showHead(address_, nameDirector_, countBooks(), nameLibrary, info);

		// ����� ����
		showElem(books_, LTCYAN_ON_BLACK, LTYELLOW_ON_BLACK, LTGREEN_ON_BLACK);

		// ����� �����������
		showLine();
	}

	// ����� ����� ������� 
	void Library::showHead(int countElem, string nameLibrary, string infoLibrary)
	{
		// ������� ���� 
		short cl = getColor();

		// ���� ����� 
		short lineColor = LTCYAN_ON_BLACK;

		// ���� �������� ������
		short textMainColor = LTYELLOW_ON_BLACK;

		// ���� ������
		short textDataColor = LTGREEN_ON_BLACK;

		// ����� ������
		cout << "  " << color(lineColor)
			//        12                             39                                                  36
			<< "+��������������+���������������������������������������������������+������������������������������������������������+\n"
			<< color(cl) << "  " << color(lineColor)
			<< "| " << color(textMainColor) << left
			<< "������: " << color(textDataColor) << setw(4) << countElem
			<< color(lineColor) << " | " << color(textMainColor)
			<< "��������: " << color(textDataColor) << setw(39) << nameLibrary
			<< color(lineColor) << " | " << color(textMainColor)
			<< "��������: " << color(textDataColor) << setw(36) << infoLibrary
			<< color(lineColor) << " |\n" << color(cl) << right
			<< "  " << color(lineColor)
			<< "+������+�������+����+����������������������������������������������+����������������������������+������+������������+\n"
			<< "  " << color(lineColor)
			<< color(lineColor) << "| " << color(textMainColor)
			<< " N  "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "    ID    "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          ��������                          "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          �����           "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "��� "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "����������"
			<< color(lineColor) << " |\n" << color(cl);

		// ����� �����
		showLine();
	}

	// ����� ����� ������� � ������� � ����������
	void Library::showHead(string address, string director, int countElem, string nameLibrary, string infoLibrary)
	{
		// ������� ���� 
		short cl = getColor();

		// ���� ����� 
		short lineColor = LTCYAN_ON_BLACK;

		// ���� �������� ������
		short textMainColor = LTYELLOW_ON_BLACK;

		// ���� ������
		short textDataColor = LTGREEN_ON_BLACK;

		// ����� ������
		cout << "  " << color(lineColor)
			//        12                             39                                                  36
			<< "+��������������+���������������������������������������������������+������������������������������������������������+\n"
			<< color(cl) << "  " << color(lineColor)
			<< "| " << color(textMainColor) << left
			<< "������: " << color(textDataColor) << setw(4) << countElem
			<< color(lineColor) << " | " << color(textMainColor)
			<< "��������: " << color(textDataColor) << setw(39) << nameLibrary
			<< color(lineColor) << " | " << color(textMainColor)
			<< "��������: " << color(textDataColor) << setw(36) << infoLibrary
			<< color(lineColor) << " |\n" << color(cl) 
			<< "  " << color(lineColor)
			<< "+��������������+���������������������������������������������������+������������������������������������������������+\n"
			<< color(cl) << "  " << color(lineColor)
			<< "| " << color(textMainColor) 
			<< "�����: " << color(textDataColor) << setw(57) << address
			<< color(lineColor) << " | " << color(textMainColor)
			<< "��������: " << color(textDataColor) << setw(36) << director
			<< color(lineColor) << " |\n" << color(cl) << right
			<< "  " << color(lineColor)
			<< "+������+������������+����������������������������������������������+����������������������������+������+������������+\n"
			<< "  " << color(lineColor)
			<< color(lineColor) << "| " << color(textMainColor)
			<< " N  "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "    ID    "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          ��������                          "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          �����           "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "��� "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "����������"
			<< color(lineColor) << " |\n" << color(cl);

		// ����� �����
		showLine();
	}

	// ����� ��������� ����
	void Library::showElem(vector<Book> books, short colorLine, short colorText1, short colorText2)
	{
		// ������� ���� 
		short cl = getColor();

		int i = 1;
		
		// ����� ������ ������� 
		for_each(books.begin(), books.end(), [cl, colorLine, colorText1, colorText2, i](Book book) mutable
		{
				cout << "  " << color(colorLine)
					<< "| " << color(cl) << setw(4) << i++ << color(colorLine)
					<< " | " << color(colorText2) << setw(10) << book.getId() << color(colorLine) << left
					<< " | " << color(colorText1) << setw(44) << book.getNameBook() << color(colorLine)
					<< " | " << color(colorText1) << setw(26) << book.getNameAuthor() << color(colorLine) << right
					<< " | " << color(colorText2) << setw(4) << book.getYear() << color(colorLine)
					<< " | " << color(colorText2) << setw(10) << book.getCountBook() << color(colorLine) 
					<< " |\n" << color(cl);
		});
	}

	// ����� �����
	void Library::showElem(Book book, short colorLine, short colorText1, short colorText2)
	{
		// ������� ���� 
		short cl = getColor();

		cout << "  " << color(colorLine)
			<< "| " << color(cl) << setw(4) << 1 << color(colorLine) << left
			<< " | " << color(colorText2) << setw(10) << book.getId() << color(colorLine)
			<< " | " << color(colorText1) << setw(44) << book.getNameBook() << color(colorLine)
			<< " | " << color(colorText1) << setw(26) << book.getNameAuthor() << color(colorLine) << right
			<< " | " << color(colorText2) << setw(4) << book.getYear() << color(colorLine)
			<< " | " << color(colorText2) << setw(10) << book.getCountBook() << color(colorLine)
			<< " |\n" << color(cl);
	}

	// ����� ����������� 
	void Library::showLine(short colorLine)
	{
		// ������� ���� 
		short cl = getColor();
												
		cout << "  " << color(colorLine)
			//     4         10					    54                                    26                       4         10       
			<< "+������+������������+����������������������������������������������+����������������������������+������+������������+\n" 
			<< color(cl);
	}

	// ���������� �������� ��������������
	Book& Library::operator[](int index)
	{
		// ���� ������ ����������� 
		if (index < 0 or index >= books_.size())
			throw exception("App: ������������ ������");

		return books_[index];
	}

#pragma endregion

#pragma region ������������� ������� 

	// ���������� �������� ������ � ������ ������� Book
	ostream& operator<<(ostream& os, const vector<Book>& books)
	{
		for_each(books.begin(), books.end(), [&os](Book book) { os << book; });

		return os;
	}

	// ���������� �������� ������ � ������
	ostream& operator<<(ostream& os, const Library& library)
	{
		os << library.address_ << ";" << library.nameDirector_ << "\n" << library.books_;

		return os;
	}

	// ���������� �������� ������ � ����
	ofstream& operator<<(ofstream& ofs, const Library& library)
	{
		ofs << library.address_.c_str() << ";" << library.nameDirector_ << "\n" << library.books_;

		return ofs;
	}

	// ��������� �������� ����� �� ������
	istream& operator>>(istream& is, Library& library)
	{
		// ����� ������
		string tempLine;

		// ����������� ��������
		getline(is, tempLine, ';');
		library.setAddress(tempLine);

		getline(is, tempLine, '\n');
		library.setNameDirector(tempLine);

		// ���������� ���� � ������

		// ����� Book
		Book temp;

		// ���������� ��������
		while (true)
		{
			is.peek();

			// ���� ��������� ����� ������
			if (is.eof()) break;

			is >> temp;

			// ������� ID
			string curID = temp.getId();

			// �������� ������������ ID
			if (!library.checkId(curID))
				throw exception(("App: ID "s + curID + " �� ��������!").c_str());

			// ���������� � ������
			library.books_.push_back(temp);

			// ���������� ID � ���� 
			library.baseID_.insert(curID);
		}

		return is;
	}

	// ���������� �������� ����� �� ����� 
	ifstream& operator>>(ifstream& ifs, Library& library)
	{
		// ����� ������
		string tempLine;

		// ����������� ��������
		getline(ifs, tempLine, ';');
		library.setAddress(tempLine);

		getline(ifs, tempLine, '\n');
		library.setNameDirector(tempLine);

		// ���������� ���� � ������

		// ����� Book
		Book temp;

		// ���������� ��������
		while (true)
		{
			ifs.peek();

			// ���� ��������� ����� �����
			if (ifs.eof()) break;

			ifs >> temp;

			// ������� ID
			string curID = temp.getId();

			// �������� ������������ ID
			if (!library.checkId(curID))
				throw exception(("App: ID "s + curID + " �� ��������!").c_str());

			// ���������� � ������
			library.books_.push_back(temp);

			// ���������� ID � ���� 
			library.baseID_.insert(curID);
		}

		return ifs;
	}

#pragma endregion 

#pragma region ����� ������

	// �������� �� �������� �����
	bool Library::checkFile(string fileName)
	{
		// �������� ����� � ������ ������/������
		fstream file(fileName, ios::in | ios::out);

		// �������� �� �������� ����� 
		bool isOpen = file.is_open();

		// �������� ����� 
		file.close();

		return isOpen;
	}

#pragma endregion