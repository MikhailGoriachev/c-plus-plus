#include "ListPayer.h"

// генератор номера для списка 
int ListPayer::numbersGen_ = 1;

#pragma region Конструкторы, деструктор и перегрузка операции присваивания 

	// конструктор по умолчанию
	ListPayer::ListPayer() : payers_(), dateCreate_(DateTime())
	{
		// установка идентификатора 
		number_ = numbersGen_++;
	}

#pragma endregion 

#pragma region Геттеры и сеттеры

	// сеттер payers_
	void ListPayer::setPayers(vector<Payer>& payers) 
	{
		// установка значений 
		payers_ = payers;
	}
	
	// геттер payers_
	vector<Payer>& ListPayer::getPayers() { return payers_; }

	// геттер dateCreate_
	const DateTime& ListPayer::getDateCreate() { return dateCreate_; }

#pragma endregion

#pragma region Методы

	// проверка номера на уникальность
	// true - номер найден, false - номер НЕ найден
	bool ListPayer::checkNumber(string& numberPayer)
	{
		// если данные некорректны
		if (numberPayer.size() != Payer::N_PHONE_NUMBER)
			throw exception(("App: Номер"s + numberPayer + " некорректен!").c_str());

		// поиск номера в базе номеров
		return find_if(payers_.begin(), payers_.end(), [&numberPayer](Payer payer)
			{ return payer.getPhoneNumber() == numberPayer; }) != payers_.end();
	}

	// добавление плательщика в список
	void ListPayer::addPayer(Payer& payer)
	{
		// номер телефона 
		string number = payer.getPhoneNumber();

		// если номер уже существует в списке
		if (checkNumber(number))
			throw exception(("App: Номер "s + number + " не уникален!").c_str());

		// добавление объекта в список
		payers_.push_back(payer);
	}

	// добавление плательщиков в список
	void ListPayer::addAllPayer(vector<Payer>& payers)
	{
		for (auto payer : payers) { addPayer(payer); }
	}

	// удаление плательщика из списка
	void ListPayer::delPayer(string& numberPayer)
	{
		// если номер уже существует в списке
		if (!checkNumber(numberPayer))
			throw exception(("App: Номер "s + numberPayer + " не найден!").c_str());

		// удаление элемента 
		payers_.erase(find_if(payers_.begin(), payers_.end(), [&numberPayer](Payer payer)
			{ return payer.getPhoneNumber() == numberPayer; }));
	}

	// поиск плательщика по номеру телефона, найденные записи помещаются в отдельную коллекцию,
	// сохраняются в бинарном потоке вывода
	vector<Payer> ListPayer::searchByNumber(string& numberPayer, string nameSaveFile)
	{
		// если номер уже существует в списке
		if (!checkNumber(numberPayer))
			throw exception(("App: Номер "s + numberPayer + " не найден!").c_str());

		// вектор с найденными элементами
		vector<Payer> result;

		// открытие файла 
		fstream fs = openFileWrite(nameSaveFile);

		// итератор для поиска
		auto it = payers_.begin();

		while (true)
		{
			// поиск элемента 
			it = find_if(it, payers_.end(), [&numberPayer](Payer payer)
				{ return payer.getPhoneNumber() == numberPayer; });

			// если элемент не найден
			if (it == payers_.end())
				break;

			// запись объекта в файл
			it->write(fs);

			// добавление элемента в результирующий вектор
			result.push_back(*it);

			// увеличение итератора 
			it++;
		}

		// закрытие файла 
		fs.close();

		return result;
	}
	
	// поиск плательщика по фамилии и инициалам, найденные записи помещаются в отдельную коллекцию,
	// сохраняются в бинарном потоке вывода
	vector<Payer> ListPayer::searchByName(string& namePayer, string nameSaveFile)
	{
		// открытие файла 
		fstream fs = openFileWrite(nameSaveFile);

		// вектор с найденными элементами
		vector<Payer> result;

		// итератор для поиска
		auto it = payers_.begin();

		while (true)
		{
			// поиск элемента 
			it = find_if(it, payers_.end(), [&namePayer](Payer payer)
				{ return payer.getNamePayer() == namePayer; });

			// если элемент не найден
			if (it == payers_.end())
				break;

			// запись объекта в файл
			it->write(fs);

			// добавление элемента в результирующий вектор
			result.push_back(*it);

			// увеличение итератора 
			it++;
		}

		// закрытие файла 
		fs.close();

		return result;
	}
	
	// поиск плательщиков по дате платежа, найденные записи помещаются в отдельную коллекцию,
	// сохраняются в бинарном потоке вывода
	vector<Payer> ListPayer::searchByDate(DateTime& dateTime, string nameSaveFile)
	{
		// открытие файла 
		fstream fs = openFileWrite(nameSaveFile);

		// вектор с найденными элементами
		vector<Payer> result;

		// итератор для поиска
		auto it = payers_.begin();

		while (true)
		{
			// текущая дата 
			DateTime curDate;

			// поиск элемента 
			it = find_if(it, payers_.end(), [&curDate, &dateTime](Payer payer)
				{ curDate = payer.getDatePay(); 
			return curDate.getDay() == dateTime.getDay() and
				curDate.getMonth() == dateTime.getMonth() and
				curDate.getYear() == dateTime.getYear(); });

			// если элемент не найден
			if (it == payers_.end())
				break;

			// запись объекта в файл
			it->write(fs);

			// добавление элемента в результирующий вектор
			result.push_back(*it);

			// увеличение итератора 
			it++;
		}

		// закрытие файла 
		fs.close();

		return result;
	}

	// вычисление полной стоимости платежей всего списка
	double ListPayer::payAll()
	{
		// сумма 
		double sum = 0;

		// подсчёт суммы
		for_each(payers_.begin(), payers_.end(), [&sum](Payer& payer) { sum += payer.getSumPay(); });

		return sum;
	}

	// вычисление полной стоимости платежей всего списка
	double ListPayer::payAll(vector<Payer> payers)
	{
		// сумма 
		double sum = 0;

		// подсчёт суммы
		for_each(payers.begin(), payers.end(), [&sum](Payer payer) { sum += payer.getSumPay(); });

		return sum;
	}

	// вычисление полного времени разговоров всего списка в минутах
	time_t ListPayer::timeAll()
	{
		// сумма 
		time_t sum = 0;

		// подсчёт суммы
		for_each(payers_.begin(), payers_.end(), [&sum](Payer& payer) { sum += payer.timeCall(); });

		return sum;
	}

	// количество элементов в списке 
	int ListPayer::countPayer() { return (int)payers_.size(); }

	// открытие файла для записи 
	fstream ListPayer::openFileWrite(string& nameFile)
	{
		// откркрытие файла для записи
		fstream fs(nameFile, ios::out | ios::binary | ios::trunc);

		// если файл не удалось открыть 
		if (!fs.is_open())
			throw exception(("App: Не удалось открыть файл "s + nameFile).c_str());

		return fs;
	}

	// открытие файла для чтения 
	fstream ListPayer::openFileRead(string& nameFile)
	{
		// откркрытие файла для записи
		fstream fs(nameFile, ios::in | ios::binary);

		// если файл не удалось открыть 
		if (!fs.is_open())
			throw exception(("App: Не удалось открыть файл "s + nameFile).c_str());

		return fs;
	}

	// открытие файла для дописи в файл
	fstream ListPayer::openFileWriteRead(string& nameFile)
	{
		// откркрытие файла для записи
		fstream fs(nameFile, ios::in | ios::out | ios::binary);

		// если файл не удалось открыть 
		if (!fs.is_open())
			throw exception(("App: Не удалось открыть файл "s + nameFile).c_str());

		return fs;
	}

	// вывод списка в виде таблицы
	void ListPayer::showTable(string nameList, string info)
	{
		// вывод заголовка 
		showHead(*this, nameList, info);

		// вывод элементов 
		showElem(payers_);
	}

	// вывод списка в виде таблицы с выводом времени разговоров
	void ListPayer::showTableTime(string nameList, string info)
	{
		// вывод заголовка 
		showHeadTime(*this, nameList, info);

		// вывод элементов 
		showElemTime(payers_);
	}

	// вывод шапки таблицы
	void ListPayer::showHead(ListPayer& listPayer, string nameList, string info)
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет 1
		short clOne = LTGREEN_ON_BLACK;

		// цвет 2
		short clTwo = LTYELLOW_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод шапки таблицы
		cout << "     "
			//										49													49
			<< color(clLine) << "+———————————————————————————————————————————————————+———————————————————————————————————————————————————+\n"
			<< color(cl) << "     "
			<< color(clLine) << "| "
			<< color(clTwo) << left << "Название: " << color(clOne) << setw(39) << nameList
			<< color(clLine) << " | "
			<< color(clTwo) << "Описание: " << color(clOne) << setw(39) << info << right
			<< color(clLine) << " |\n"
			<< color(cl) << "     "
			//						   14					  20							30					          28
			<< color(clLine) << "+————————————————+————————————————————————+—————————+——————————————————————————+————————————————————————+\n"
			<< color(cl) << "     "
			<< color(clLine) << "| "
			<< color(clTwo) << "Размер: " << color(clOne) << setw(6) << listPayer.payers_.size()
			<< color(clLine) << " | "
			<< color(clTwo) << "Номер списка: " << color(clOne) << setw(8) << listPayer.number_
			<< color(clLine) << " | "
			<< color(clTwo) << "Дата создания: " << color(clOne); listPayer.dateCreate_.showDateTime(clOne);
		cout << color(clLine) << " | "
			<< color(clTwo) << "Сумма: " << color(clOne) << setw(15) << listPayer.payAll()
			<< color(clLine) << " |\n"
			<< color(cl) << "     "
			<< color(clLine) << "+————————————————+————————————————————————+————————————————————————————————————+————————————————————————+\n";
	}

	// вывод шапки таблицы
	void ListPayer::showHeadTime(ListPayer& listPayer, string nameList, string info)
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет 1
		short clOne = LTGREEN_ON_BLACK;

		// цвет 2
		short clTwo = LTYELLOW_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод шапки таблицы
		cout << " "
			//										49													49
			<< color(clLine) << "+———————————————————————————————————————————————————+—————————————————————————————————————————————————————————————————+\n"
			<< color(cl) << " "
			<< color(clLine) << "| "
			<< color(clTwo) << left << "Название: " << color(clOne) << setw(39) << nameList
			<< color(clLine) << " | "
			<< color(clTwo) << "Описание: " << color(clOne) << setw(53) << info << right
			<< color(clLine) << " |\n"
			<< color(cl) << " "
			//						   14					  20							30					          28
			<< color(clLine) << "+————————————————+————————————————————————+—————————+——————————————————————————+————————————————————————+—————————————+\n"
			<< color(cl) << " "
			<< color(clLine) << "| "
			<< color(clTwo) << "Размер: " << color(clOne) << setw(6) << listPayer.payers_.size()
			<< color(clLine) << " | "
			<< color(clTwo) << "Номер списка: " << color(clOne) << setw(8) << listPayer.number_
			<< color(clLine) << " | "
			<< color(clTwo) << "Дата создания: " << color(clOne); listPayer.dateCreate_.showDateTime(clOne);
		cout << color(clLine) << " | "
			<< color(clTwo) << "Сумма: " << color(clOne) << setw(15) << listPayer.payAll()
			<< color(clLine) << " | "
			<< color(clTwo) << "Время: " << color(clOne) << setw(4) << listPayer.timeAll()
			<< color(clLine) << " |\n"
			<< color(cl) << " "
			<< color(clLine) << "+————————————————+————————————————————————+————————————————————————————————————+————————————————————————+—————————————+\n";

	}

	// вывод элементов 
	void ListPayer::showElem(vector<Payer> payers)
	{
		Payer::showHead();

		// если в векторе нет элементов 
		if (payers.size() == 0)
			showEmpty();

		// индекс 
		int i = 1;

		// вывод элементов 
		for_each(payers.begin(), payers.end(), [i](Payer payer) mutable { payer.showPayer(i++); });

		Payer::showLine();
	}

	// вывод элементов 
	void ListPayer::showElemTime(vector<Payer> payers)
	{
		Payer::showHeadTime();

		// если в векторе нет элементов 
		if (payers.size() == 0)
			showEmptyTime();

		// индекс 
		int i = 1;

		// вывод элементов 
		for_each(payers.begin(), payers.end(), [i](Payer payer) mutable { payer.showPayerTime(i++); });

		Payer::showLineTime();
	}

	// вывод разделителя 
	void ListPayer::showLine()
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод линии-разделителя
		cout << "     " << color(clLine) 
			//	   4				22				   10		  6		   6	  4		         20				  8	
			<< "+——————+————————————————————————+————————————+————————+————————+——————+——————————————————————+——————————+\n"
			<< color(cl);
	}

	// вывод сообщения об отсутствии данных
	void ListPayer::showEmpty()
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		short clText = LTRED_ON_BLACK;

		cout << "     " << color(clLine) << "|"
			<< color(clText) << "                                                НЕТ ДАННЫХ                                             "
			<< color(clLine) << "|\n" << color(cl);

	}

	// вывод сообщения об отсутствии данных с выводом времени разговоров
	void ListPayer::showEmptyTime()
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		short clText = LTRED_ON_BLACK;

		cout << "     " << color(clLine) << "|"
			<< color(clText) << "                                                     НЕТ ДАННЫХ                                                   "
			<< color(clLine) << "|\n" << color(cl);

	}
	
#pragma endregion

#pragma region Дружественные функции 

#pragma endregion
