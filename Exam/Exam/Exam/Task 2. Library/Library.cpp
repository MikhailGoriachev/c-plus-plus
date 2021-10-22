#include "Library.h"

// Поле идентификации книг(учетных номеров)
// set<string> Library::baseID_ = set<string>();

#pragma region Конструкторы, деструктор, перегрузка операции присваивания 

	// конструктор инициализирующий 
	Library::Library(string address, string nameDirector, string fileName) : books_()
	{
		// установка значений
		setAddress(address);
		setNameDirector(nameDirector);
		setFileName(fileName);
	}
	
	// конструктор инициализирующий (загрузка из файла)
	Library::Library(string fileName) 
	{
		// установка файла для сохранения по умолчанию
		setFileName(fileName);

		// загрузка из файла 
		loadLibrary();
	}

	// конструктор инициализирующий (загрузка из массива Book)
	Library::Library(string address, string nameDirector, vector<Book>& books, string fileName)
	{
		// установка значений
		setAddress(address);
		setNameDirector(nameDirector);
		setFileName(fileName);

		books_ = books;
	}

#pragma endregion 

#pragma region Сеттеры и геттеры

	// сеттер address_
	void Library::setAddress(string address)
	{
		// длина строки
		int size = (int)address.size();

		// если данные некорректны
		if (size < N_MIN_ADDRESS or size > N_MAX_ADDRESS)
			throw exception("App: Данные некорректны");

		// установка значения
		address_ = address;
	}

	// геттер address_
	const string& Library::getAddress() { return address_; }

	// сеттер nameDirector_
	void Library::setNameDirector(string nameDirector)
	{
		// длина строки
		int size = (int)nameDirector.size();

		// если данные некорректны
		if (size < N_MIN_NAME_DIRECTOR or size > N_MAX_NAME_DIRECTOR)
			throw exception("App: Данные некорректны");

		// установка значения
		nameDirector_ = nameDirector;
	}

	// геттер nameDirector_
	const string& Library::getNameDirector() { return nameDirector_; }

	// геттер books_
	vector<Book>& Library::getBooks() { return books_; }

	// сеттер fileName_
	void Library::setFileName(string fileName)
	{
		// длина строки
		int size = (int)fileName.size();

		// если данные некорректны
		if (size < N_MIN_FILE_NAME or size > N_MAX_FILE_NAME)
			throw exception("App: Данные некорректны");

		// установка значения
		fileName_ = fileName;
	}

	// геттер fileName_
	const string& Library::getFileName() { return fileName_; }

#pragma endregion

#pragma region Методы 

	// проверка идентификатора на уникальность
	// true - ID уникален, false - ID НЕ уникален 
	bool Library::checkId(string id)
	{
		// размер переданной строки
		int size = (int)id.size();

		// если данные некорректные 
		if (size != Book::N_ID)
			throw exception("App: Некорректный идентификатор");

		// поиск в базе идентификаторов
		return baseID_.find(id) == baseID_.end();
	}

	// генерация идентификатора
	string Library::genId()
	{
		// строка для ID
		string line;

		// генерация ID
		do
		{
			line = Book::genId();
			
			// проверка идентификатора на уникальность
		} while (!checkId(line));

		return line;
	}

	// добавление книги в библиотеку 
	void Library::addBook(Book& book)
	{
		// ID книги
		string curID = book.getId();

		// проверка на уникальность ID книги
		if (!checkId(book.getId()))
			throw exception(("App: ID "s + curID + " не уникален!").c_str());

		// добавление книги 
		books_.push_back(book);

		// добавление ID книги в базу
		baseID_.insert(curID);
	}

	// добавление вектора книг в библиотеку
	void Library::addAllBook(vector<Book> books)
	{
		for_each(books.begin(), books.end(), [this](Book book) { this->addBook(book); });
	}

	// удаление книги из библиотеки
	void Library::removeBook(string id)
	{
		// поиск ID в базе
		if (checkId(id))
			throw exception(("App: книга с ID "s + id + " не найдена").c_str());
	
		// удаление книги
		books_.erase(find_if(books_.begin(), books_.end(), [id](Book book) { return book.getId() == id; }));

		// удаление ID книги из базы данных
		baseID_.erase(id);
	}

	// отчистка библиотеки от книг
	void Library::clear()
	{
		// отчистка вектора книг
		books_.clear();

		// отчистка базы ID
		baseID_.clear();
	}

	// получение книги по ID
	Book& Library::getBook(string id)
	{
		// поиск ID в базе
		if (checkId(id))
			throw exception(("App: книга с ID "s + id + " не найдена").c_str());

		// поиск книги книги
		return *find_if(books_.begin(), books_.end(), [id](Book book) { return book.getId() == id; });
	}

	// загрузка библиотеки из файла .csv - по умолачнию
	void Library::loadLibrary()
	{
		// проверка на отрытие файла 
		if (!checkFile(fileName_))
			throw exception(("App: Ошибка открытия файла "s + fileName_).c_str());

		// открытие потока чтения файла 
		ifstream ifs(fileName_);

		// загрузка данных из файла 
		ifs >> *this;

		// закрытие файла
		ifs.close();
	}

	// загрузка библиотеки из файла .csv - указанного файла 
	void Library::loadLibrary(string fileName)
	{
		// проверка на отрытие файла 
		if (!checkFile(fileName_))
			throw exception(("App: Ошибка открытия файла "s + fileName_).c_str());

		// открытие потока чтения файла 
		ifstream ifs(fileName_);

		// загрузка данных из файла 
		ifs >> *this;

		// закрытие файла
		ifs.close();
	}

	// сохранение библиотеки в файл .csv - по умолачнию
	void Library::saveLibrary()
	{
		// открытие потока чтения файла 
		ofstream ofs(fileName_);

		// если файл не удалось открыть
		if (!ofs.is_open())
			throw exception(("App: Не удалось создать/открыть файл "s + fileName_ + "!").c_str());

		// загрузка данных из файла 
		ofs << *this;

		// закрытие файла
		ofs.close();
	}

	// сохранение библиотеки в файл .csv - указанного файла 
	void Library::saveLibrary(string fileName)
	{
		// открытие потока чтения файла 
		ofstream ofs(fileName_);

		// если файл не удалось открыть
		if (!ofs.is_open())
			throw exception(("App: Не удалось создать/открыть файл "s + fileName_ + "!").c_str());

		// загрузка данных из файла 
		ofs << *this;

		// закрытие файла
		ofs.close();
	}

	// количество книг в библиотеке 
	int Library::countBooks() { return (int)books_.size(); }

	// вывод данных библиотеки и коллекции книг в консоль
	void Library::showLibrary(string nameLibrary, string info)
	{
		// вывод шапки таблицы 
		showHead(address_, nameDirector_, countBooks(), nameLibrary, info);

		// вывод книг
		showElem(books_, LTCYAN_ON_BLACK, LTYELLOW_ON_BLACK, LTGREEN_ON_BLACK);

		// вывод разделителя
		showLine();
	}

	// вывод шапки таблицы 
	void Library::showHead(int countElem, string nameLibrary, string infoLibrary)
	{
		// текущий цвет 
		short cl = getColor();

		// цвет линий 
		short lineColor = LTCYAN_ON_BLACK;

		// цвет главного текста
		short textMainColor = LTYELLOW_ON_BLACK;

		// цвет данных
		short textDataColor = LTGREEN_ON_BLACK;

		// вывод данных
		cout << "  " << color(lineColor)
			//        12                             39                                                  36
			<< "+——————————————+———————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
			<< color(cl) << "  " << color(lineColor)
			<< "| " << color(textMainColor) << left
			<< "Размер: " << color(textDataColor) << setw(4) << countElem
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Название: " << color(textDataColor) << setw(39) << nameLibrary
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Описание: " << color(textDataColor) << setw(36) << infoLibrary
			<< color(lineColor) << " |\n" << color(cl) << right
			<< "  " << color(lineColor)
			<< "+——————+———————+————+——————————————————————————————————————————————+————————————————————————————+——————+————————————+\n"
			<< "  " << color(lineColor)
			<< color(lineColor) << "| " << color(textMainColor)
			<< " N  "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "    ID    "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          Название                          "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          Автор           "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Год "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Количество"
			<< color(lineColor) << " |\n" << color(cl);

		// вывод линии
		showLine();
	}

	// вывод шапки таблицы с адресом и директором
	void Library::showHead(string address, string director, int countElem, string nameLibrary, string infoLibrary)
	{
		// текущий цвет 
		short cl = getColor();

		// цвет линий 
		short lineColor = LTCYAN_ON_BLACK;

		// цвет главного текста
		short textMainColor = LTYELLOW_ON_BLACK;

		// цвет данных
		short textDataColor = LTGREEN_ON_BLACK;

		// вывод данных
		cout << "  " << color(lineColor)
			//        12                             39                                                  36
			<< "+——————————————+———————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
			<< color(cl) << "  " << color(lineColor)
			<< "| " << color(textMainColor) << left
			<< "Размер: " << color(textDataColor) << setw(4) << countElem
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Название: " << color(textDataColor) << setw(39) << nameLibrary
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Описание: " << color(textDataColor) << setw(36) << infoLibrary
			<< color(lineColor) << " |\n" << color(cl) 
			<< "  " << color(lineColor)
			<< "+——————————————+———————————————————————————————————————————————————+————————————————————————————————————————————————+\n"
			<< color(cl) << "  " << color(lineColor)
			<< "| " << color(textMainColor) 
			<< "Адрес: " << color(textDataColor) << setw(57) << address
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Директор: " << color(textDataColor) << setw(36) << director
			<< color(lineColor) << " |\n" << color(cl) << right
			<< "  " << color(lineColor)
			<< "+——————+————————————+——————————————————————————————————————————————+————————————————————————————+——————+————————————+\n"
			<< "  " << color(lineColor)
			<< color(lineColor) << "| " << color(textMainColor)
			<< " N  "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "    ID    "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          Название                          "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "          Автор           "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Год "
			<< color(lineColor) << " | " << color(textMainColor)
			<< "Количество"
			<< color(lineColor) << " |\n" << color(cl);

		// вывод линии
		showLine();
	}

	// вывод коллекции книг
	void Library::showElem(vector<Book> books, short colorLine, short colorText1, short colorText2)
	{
		// текущий цвет 
		short cl = getColor();

		int i = 1;
		
		// вывод данных вектора 
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

	// вывод книги
	void Library::showElem(Book book, short colorLine, short colorText1, short colorText2)
	{
		// текущий цвет 
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

	// вывод разделителя 
	void Library::showLine(short colorLine)
	{
		// текущий цвет 
		short cl = getColor();
												
		cout << "  " << color(colorLine)
			//     4         10					    54                                    26                       4         10       
			<< "+——————+————————————+——————————————————————————————————————————————+————————————————————————————+——————+————————————+\n" 
			<< color(cl);
	}

	// перегрузка операции индексирования
	Book& Library::operator[](int index)
	{
		// если индекс некорректен 
		if (index < 0 or index >= books_.size())
			throw exception("App: Некорректный индекс");

		return books_[index];
	}

#pragma endregion

#pragma region Дружественные функции 

	// перегрузка операции вывода в строку вектора Book
	ostream& operator<<(ostream& os, const vector<Book>& books)
	{
		for_each(books.begin(), books.end(), [&os](Book book) { os << book; });

		return os;
	}

	// перегрузка операции вывода в сторку
	ostream& operator<<(ostream& os, const Library& library)
	{
		os << library.address_ << ";" << library.nameDirector_ << "\n" << library.books_;

		return os;
	}

	// перегрузка операции вывода в файл
	ofstream& operator<<(ofstream& ofs, const Library& library)
	{
		ofs << library.address_.c_str() << ";" << library.nameDirector_ << "\n" << library.books_;

		return ofs;
	}

	// перегузка операции ввода из строки
	istream& operator>>(istream& is, Library& library)
	{
		// буфер строки
		string tempLine;

		// считываение значений
		getline(is, tempLine, ';');
		library.setAddress(tempLine);

		getline(is, tempLine, '\n');
		library.setNameDirector(tempLine);

		// считывание книг в вектор

		// буфер Book
		Book temp;

		// считывание значений
		while (true)
		{
			is.peek();

			// если достигнут конец строки
			if (is.eof()) break;

			is >> temp;

			// текущий ID
			string curID = temp.getId();

			// проверка уникальности ID
			if (!library.checkId(curID))
				throw exception(("App: ID "s + curID + " не уникален!").c_str());

			// добавление в вектор
			library.books_.push_back(temp);

			// добавление ID в базу 
			library.baseID_.insert(curID);
		}

		return is;
	}

	// перегрузка операции ввода из файла 
	ifstream& operator>>(ifstream& ifs, Library& library)
	{
		// буфер строки
		string tempLine;

		// считываение значений
		getline(ifs, tempLine, ';');
		library.setAddress(tempLine);

		getline(ifs, tempLine, '\n');
		library.setNameDirector(tempLine);

		// считывание книг в вектор

		// буфер Book
		Book temp;

		// считывание значений
		while (true)
		{
			ifs.peek();

			// если достигнут конец файла
			if (ifs.eof()) break;

			ifs >> temp;

			// текущий ID
			string curID = temp.getId();

			// проверка уникальности ID
			if (!library.checkId(curID))
				throw exception(("App: ID "s + curID + " не уникален!").c_str());

			// добавление в вектор
			library.books_.push_back(temp);

			// добавление ID в базу 
			library.baseID_.insert(curID);
		}

		return ifs;
	}

#pragma endregion 

#pragma region Общие методы

	// проверка на открытие файла
	bool Library::checkFile(string fileName)
	{
		// открытие файла в режиме чтения/записи
		fstream file(fileName, ios::in | ios::out);

		// проверка на открытие файла 
		bool isOpen = file.is_open();

		// закрытие файла 
		file.close();

		return isOpen;
	}

#pragma endregion