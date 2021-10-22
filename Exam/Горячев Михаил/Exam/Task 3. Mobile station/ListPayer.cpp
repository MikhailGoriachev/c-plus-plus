#include "ListPayer.h"

// ��������� ������ ��� ������ 
int ListPayer::numbersGen_ = 1;

#pragma region ������������, ���������� � ���������� �������� ������������ 

	// ����������� �� ���������
	ListPayer::ListPayer() : payers_(), dateCreate_(DateTime())
	{
		// ��������� �������������� 
		number_ = numbersGen_++;
	}

#pragma endregion 

#pragma region ������� � �������

	// ������ payers_
	void ListPayer::setPayers(vector<Payer>& payers) 
	{
		// ��������� �������� 
		payers_ = payers;
	}
	
	// ������ payers_
	vector<Payer>& ListPayer::getPayers() { return payers_; }

	// ������ dateCreate_
	const DateTime& ListPayer::getDateCreate() { return dateCreate_; }

#pragma endregion

#pragma region ������

	// �������� ������ �� ������������
	// true - ����� ������, false - ����� �� ������
	bool ListPayer::checkNumber(string& numberPayer)
	{
		// ���� ������ �����������
		if (numberPayer.size() != Payer::N_PHONE_NUMBER)
			throw exception(("App: �����"s + numberPayer + " �����������!").c_str());

		// ����� ������ � ���� �������
		return find_if(payers_.begin(), payers_.end(), [&numberPayer](Payer payer)
			{ return payer.getPhoneNumber() == numberPayer; }) != payers_.end();
	}

	// ���������� ����������� � ������
	void ListPayer::addPayer(Payer& payer)
	{
		// ����� �������� 
		string number = payer.getPhoneNumber();

		// ���� ����� ��� ���������� � ������
		if (checkNumber(number))
			throw exception(("App: ����� "s + number + " �� ��������!").c_str());

		// ���������� ������� � ������
		payers_.push_back(payer);
	}

	// ���������� ������������ � ������
	void ListPayer::addAllPayer(vector<Payer>& payers)
	{
		for (auto payer : payers) { addPayer(payer); }
	}

	// �������� ����������� �� ������
	void ListPayer::delPayer(string& numberPayer)
	{
		// ���� ����� ��� ���������� � ������
		if (!checkNumber(numberPayer))
			throw exception(("App: ����� "s + numberPayer + " �� ������!").c_str());

		// �������� �������� 
		payers_.erase(find_if(payers_.begin(), payers_.end(), [&numberPayer](Payer payer)
			{ return payer.getPhoneNumber() == numberPayer; }));
	}

	// ����� ����������� �� ������ ��������, ��������� ������ ���������� � ��������� ���������,
	// ����������� � �������� ������ ������
	vector<Payer> ListPayer::searchByNumber(string& numberPayer, string nameSaveFile)
	{
		// ���� ����� ��� ���������� � ������
		if (!checkNumber(numberPayer))
			throw exception(("App: ����� "s + numberPayer + " �� ������!").c_str());

		// ������ � ���������� ����������
		vector<Payer> result;

		// �������� ����� 
		fstream fs = openFileWrite(nameSaveFile);

		// �������� ��� ������
		auto it = payers_.begin();

		while (true)
		{
			// ����� �������� 
			it = find_if(it, payers_.end(), [&numberPayer](Payer payer)
				{ return payer.getPhoneNumber() == numberPayer; });

			// ���� ������� �� ������
			if (it == payers_.end())
				break;

			// ������ ������� � ����
			it->write(fs);

			// ���������� �������� � �������������� ������
			result.push_back(*it);

			// ���������� ��������� 
			it++;
		}

		// �������� ����� 
		fs.close();

		return result;
	}
	
	// ����� ����������� �� ������� � ���������, ��������� ������ ���������� � ��������� ���������,
	// ����������� � �������� ������ ������
	vector<Payer> ListPayer::searchByName(string& namePayer, string nameSaveFile)
	{
		// �������� ����� 
		fstream fs = openFileWrite(nameSaveFile);

		// ������ � ���������� ����������
		vector<Payer> result;

		// �������� ��� ������
		auto it = payers_.begin();

		while (true)
		{
			// ����� �������� 
			it = find_if(it, payers_.end(), [&namePayer](Payer payer)
				{ return payer.getNamePayer() == namePayer; });

			// ���� ������� �� ������
			if (it == payers_.end())
				break;

			// ������ ������� � ����
			it->write(fs);

			// ���������� �������� � �������������� ������
			result.push_back(*it);

			// ���������� ��������� 
			it++;
		}

		// �������� ����� 
		fs.close();

		return result;
	}
	
	// ����� ������������ �� ���� �������, ��������� ������ ���������� � ��������� ���������,
	// ����������� � �������� ������ ������
	vector<Payer> ListPayer::searchByDate(DateTime& dateTime, string nameSaveFile)
	{
		// �������� ����� 
		fstream fs = openFileWrite(nameSaveFile);

		// ������ � ���������� ����������
		vector<Payer> result;

		// �������� ��� ������
		auto it = payers_.begin();

		while (true)
		{
			// ������� ���� 
			DateTime curDate;

			// ����� �������� 
			it = find_if(it, payers_.end(), [&curDate, &dateTime](Payer payer)
				{ curDate = payer.getDatePay(); 
			return curDate.getDay() == dateTime.getDay() and
				curDate.getMonth() == dateTime.getMonth() and
				curDate.getYear() == dateTime.getYear(); });

			// ���� ������� �� ������
			if (it == payers_.end())
				break;

			// ������ ������� � ����
			it->write(fs);

			// ���������� �������� � �������������� ������
			result.push_back(*it);

			// ���������� ��������� 
			it++;
		}

		// �������� ����� 
		fs.close();

		return result;
	}

	// ���������� ������ ��������� �������� ����� ������
	double ListPayer::payAll()
	{
		// ����� 
		double sum = 0;

		// ������� �����
		for_each(payers_.begin(), payers_.end(), [&sum](Payer& payer) { sum += payer.getSumPay(); });

		return sum;
	}

	// ���������� ������ ��������� �������� ����� ������
	double ListPayer::payAll(vector<Payer> payers)
	{
		// ����� 
		double sum = 0;

		// ������� �����
		for_each(payers.begin(), payers.end(), [&sum](Payer payer) { sum += payer.getSumPay(); });

		return sum;
	}

	// ���������� ������� ������� ���������� ����� ������ � �������
	time_t ListPayer::timeAll()
	{
		// ����� 
		time_t sum = 0;

		// ������� �����
		for_each(payers_.begin(), payers_.end(), [&sum](Payer& payer) { sum += payer.timeCall(); });

		return sum;
	}

	// ���������� ��������� � ������ 
	int ListPayer::countPayer() { return (int)payers_.size(); }

	// �������� ����� ��� ������ 
	fstream ListPayer::openFileWrite(string& nameFile)
	{
		// ���������� ����� ��� ������
		fstream fs(nameFile, ios::out | ios::binary | ios::trunc);

		// ���� ���� �� ������� ������� 
		if (!fs.is_open())
			throw exception(("App: �� ������� ������� ���� "s + nameFile).c_str());

		return fs;
	}

	// �������� ����� ��� ������ 
	fstream ListPayer::openFileRead(string& nameFile)
	{
		// ���������� ����� ��� ������
		fstream fs(nameFile, ios::in | ios::binary);

		// ���� ���� �� ������� ������� 
		if (!fs.is_open())
			throw exception(("App: �� ������� ������� ���� "s + nameFile).c_str());

		return fs;
	}

	// �������� ����� ��� ������ � ����
	fstream ListPayer::openFileWriteRead(string& nameFile)
	{
		// ���������� ����� ��� ������
		fstream fs(nameFile, ios::in | ios::out | ios::binary);

		// ���� ���� �� ������� ������� 
		if (!fs.is_open())
			throw exception(("App: �� ������� ������� ���� "s + nameFile).c_str());

		return fs;
	}

	// ����� ������ � ���� �������
	void ListPayer::showTable(string nameList, string info)
	{
		// ����� ��������� 
		showHead(*this, nameList, info);

		// ����� ��������� 
		showElem(payers_);
	}

	// ����� ������ � ���� ������� � ������� ������� ����������
	void ListPayer::showTableTime(string nameList, string info)
	{
		// ����� ��������� 
		showHeadTime(*this, nameList, info);

		// ����� ��������� 
		showElemTime(payers_);
	}

	// ����� ����� �������
	void ListPayer::showHead(ListPayer& listPayer, string nameList, string info)
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� 1
		short clOne = LTGREEN_ON_BLACK;

		// ���� 2
		short clTwo = LTYELLOW_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� ����� �������
		cout << "     "
			//										49													49
			<< color(clLine) << "+���������������������������������������������������+���������������������������������������������������+\n"
			<< color(cl) << "     "
			<< color(clLine) << "| "
			<< color(clTwo) << left << "��������: " << color(clOne) << setw(39) << nameList
			<< color(clLine) << " | "
			<< color(clTwo) << "��������: " << color(clOne) << setw(39) << info << right
			<< color(clLine) << " |\n"
			<< color(cl) << "     "
			//						   14					  20							30					          28
			<< color(clLine) << "+����������������+������������������������+���������+��������������������������+������������������������+\n"
			<< color(cl) << "     "
			<< color(clLine) << "| "
			<< color(clTwo) << "������: " << color(clOne) << setw(6) << listPayer.payers_.size()
			<< color(clLine) << " | "
			<< color(clTwo) << "����� ������: " << color(clOne) << setw(8) << listPayer.number_
			<< color(clLine) << " | "
			<< color(clTwo) << "���� ��������: " << color(clOne); listPayer.dateCreate_.showDateTime(clOne);
		cout << color(clLine) << " | "
			<< color(clTwo) << "�����: " << color(clOne) << setw(15) << listPayer.payAll()
			<< color(clLine) << " |\n"
			<< color(cl) << "     "
			<< color(clLine) << "+����������������+������������������������+������������������������������������+������������������������+\n";
	}

	// ����� ����� �������
	void ListPayer::showHeadTime(ListPayer& listPayer, string nameList, string info)
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� 1
		short clOne = LTGREEN_ON_BLACK;

		// ���� 2
		short clTwo = LTYELLOW_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� ����� �������
		cout << " "
			//										49													49
			<< color(clLine) << "+���������������������������������������������������+�����������������������������������������������������������������+\n"
			<< color(cl) << " "
			<< color(clLine) << "| "
			<< color(clTwo) << left << "��������: " << color(clOne) << setw(39) << nameList
			<< color(clLine) << " | "
			<< color(clTwo) << "��������: " << color(clOne) << setw(53) << info << right
			<< color(clLine) << " |\n"
			<< color(cl) << " "
			//						   14					  20							30					          28
			<< color(clLine) << "+����������������+������������������������+���������+��������������������������+������������������������+�������������+\n"
			<< color(cl) << " "
			<< color(clLine) << "| "
			<< color(clTwo) << "������: " << color(clOne) << setw(6) << listPayer.payers_.size()
			<< color(clLine) << " | "
			<< color(clTwo) << "����� ������: " << color(clOne) << setw(8) << listPayer.number_
			<< color(clLine) << " | "
			<< color(clTwo) << "���� ��������: " << color(clOne); listPayer.dateCreate_.showDateTime(clOne);
		cout << color(clLine) << " | "
			<< color(clTwo) << "�����: " << color(clOne) << setw(15) << listPayer.payAll()
			<< color(clLine) << " | "
			<< color(clTwo) << "�����: " << color(clOne) << setw(4) << listPayer.timeAll()
			<< color(clLine) << " |\n"
			<< color(cl) << " "
			<< color(clLine) << "+����������������+������������������������+������������������������������������+������������������������+�������������+\n";

	}

	// ����� ��������� 
	void ListPayer::showElem(vector<Payer> payers)
	{
		Payer::showHead();

		// ���� � ������� ��� ��������� 
		if (payers.size() == 0)
			showEmpty();

		// ������ 
		int i = 1;

		// ����� ��������� 
		for_each(payers.begin(), payers.end(), [i](Payer payer) mutable { payer.showPayer(i++); });

		Payer::showLine();
	}

	// ����� ��������� 
	void ListPayer::showElemTime(vector<Payer> payers)
	{
		Payer::showHeadTime();

		// ���� � ������� ��� ��������� 
		if (payers.size() == 0)
			showEmptyTime();

		// ������ 
		int i = 1;

		// ����� ��������� 
		for_each(payers.begin(), payers.end(), [i](Payer payer) mutable { payer.showPayerTime(i++); });

		Payer::showLineTime();
	}

	// ����� ����������� 
	void ListPayer::showLine()
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� �����-�����������
		cout << "     " << color(clLine) 
			//	   4				22				   10		  6		   6	  4		         20				  8	
			<< "+������+������������������������+������������+��������+��������+������+����������������������+����������+\n"
			<< color(cl);
	}

	// ����� ��������� �� ���������� ������
	void ListPayer::showEmpty()
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		short clText = LTRED_ON_BLACK;

		cout << "     " << color(clLine) << "|"
			<< color(clText) << "                                                ��� ������                                             "
			<< color(clLine) << "|\n" << color(cl);

	}

	// ����� ��������� �� ���������� ������ � ������� ������� ����������
	void ListPayer::showEmptyTime()
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		short clText = LTRED_ON_BLACK;

		cout << "     " << color(clLine) << "|"
			<< color(clText) << "                                                     ��� ������                                                   "
			<< color(clLine) << "|\n" << color(cl);

	}
	
#pragma endregion

#pragma region ������������� ������� 

#pragma endregion
