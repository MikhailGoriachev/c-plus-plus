#include "Payer.h"

// ����������� �������� DateTime
const DateTime Payer::V_MIN_DATE = DateTime(1, 1, 1970, 0, 0, 0);

#pragma region ������������, ���������� � ���������� �������� ������������ 

	// ����������� ���������������� 
	Payer::Payer(string namePayer, string phoneNumber, double rate, double discount, DateTime datePay) 
		: countBills_(), sumPay_()
	{
		// ��������� �������� 
		setNamePayer(namePayer);
		setPhoneNumber(phoneNumber);
		setRate(rate);
		setDiscount(discount);
		setDatePay(datePay);
	}
	
#pragma endregion
	
#pragma region ������� � ������� 
	
	// ������ namePayer_
	void Payer::setNamePayer(string namePayer)
	{
		// ������ ������
		int size = (int)namePayer.size();

		// ���� ������ �����������
		if (size < N_MIN_NAME_PAYER or size > N_MAX_NAME_PAYER)
			throw exception("App: ������������ ������!");

		// ��������� �������� 
		namePayer_ = namePayer;
	}

	// ������ namePayer_
	const string& Payer::getNamePayer() const { return namePayer_; }

	// ������ phoneNumber_ 
	void Payer::setPhoneNumber(string phoneNumber)
	{
		// ������ ������
		int size = (int)phoneNumber.size();

		// ���� ������ �����������
		if (size != N_PHONE_NUMBER)
			throw exception("App: ������������ ������!");

		// ��������� �������� 
		phoneNumber_ = phoneNumber;
	}

	// ������ phoneNumber_
	const string& Payer::getPhoneNumber() const { return phoneNumber_; }

	// ������ rate_
	void Payer::setRate(double rate)
	{
		// ���� ������ �����������
		if (rate < V_MIN_RATE or rate > V_MAX_RATE)
			throw exception("App: ������������ ������!");

		// ��������� �������� 
		rate_ = rate;
	}

	// ������ rate_
	double Payer::getRate() const { return rate_; }

	// ������ discount_
	void Payer::setDiscount(double discount)
	{
		// ���� ������ �����������
		if (discount < V_MIN_DISCOUNT or discount > V_MAX_DISCOUNT)
			throw exception("App: ������������ ������!");

		// ��������� �������� 
		discount_ = discount;
	}

	// ������ discount_
	double Payer::getDiscount() const { return discount_; }

	// ������ datePay_ 
	void Payer::setDatePay(DateTime datePay)
	{
		// ���� ������ �����������
		if (datePay > DateTime() or datePay < V_MIN_DATE)
			throw exception("App: ������ �����������!");

		// ��������� �������� 
		datePay_ = datePay;
	}

	// ������ datePay_
	const DateTime& Payer::getDatePay() { return datePay_; }

	// ������ sumPay_
	double Payer::getSumPay() { return sumPay_; }

	// ������ bills_
	void Payer::setBills(vector<Bill> bills)
	{
		// ����������� ������� 
		for (auto bill : bills)
			addBill(bill);

		// ��������� �������� 
		countBills_ = (int)bills.size();
	}

	// ������ bills_
	const vector<Bill>& Payer::getBills() { return bills_; }

#pragma endregion 

#pragma region ������ 

	// ���������� ������� 
	void Payer::addBill(Bill bill)
	{
		// ���� ���� � ����� ��������� ������ ������, ��� ���� �������
		if (bill.getEndCall() > datePay_)
			throw exception("App: ������������ ������!");

		// ���������� ����� �������� ������� � ����� ����� 
		sumPay_ += bill.pay(rate_, discount_);

		// ���������� ������� Bill � ������ � �������
		bills_.push_back(bill);
	}

	// ������ � �������� ���� 
	void Payer::write(fstream& fs)
	{
		// ������ ������
		const int SIZE_BUF = 400;

		// ����� ������ ��� ������
		char* buf = new char[SIZE_BUF + 1]{ 0 };


		// ������� � �������� �����������
		strcpy(buf,namePayer_.c_str());

		// ������ � ���� 
		fs.write(buf, Payer::N_MAX_NAME_PAYER);


		// �������� ������ 
		memset(buf, 0, SIZE_BUF);


		// ����� ��������
		strcpy(buf, phoneNumber_.c_str());

		// ������ � ���� 
		fs.write(buf, Payer::N_PHONE_NUMBER);


		// ����� �� ������ ���������
		fs.write((const char*)&rate_, sizeof(rate_));

		// ������(� ���������)
		fs.write((const char*)&discount_, sizeof(discount_));

		// ���������� ������ - ��������� ��� ������ � ���������� � ��������� ����� 
		fs.write((const char*)&countBills_, sizeof(countBills_));

		// ���� �������
		fs.write((char*)&datePay_, sizeof(datePay_));

		// ����� �������
		fs.write((char*)&sumPay_, sizeof(sumPay_));

		// ��������� ��������(������� ������ Bill)
		for_each(bills_.begin(), bills_.end(), [&fs](Bill bill) { bill.write(fs); });

		// �������� ������ 
		delete[] buf;
	}

	// ������ �� ��������� ����� 
	void Payer::read(fstream& fs)
	{
		// ������ ������
		const int SIZE_BUF = 400;

		// ����� ������ ��� ������
		char* buf = new char[SIZE_BUF + 1]{ 0 };


		// ������ �� �����
		fs.read(buf, Payer::N_MAX_NAME_PAYER);

		// ������� � �������� �����������
		namePayer_ = buf;


		// �������� ������ 
		memset(buf, 0, SIZE_BUF);


		// ������ �� �����
		fs.read(buf, Payer::N_PHONE_NUMBER);

		// ����� �������� 
		phoneNumber_ = buf;

		// ����� �� ������ ���������
		fs.read((char*)&rate_, sizeof(rate_));

		// ������(� ���������)
		fs.read((char*)&discount_, sizeof(discount_));

		// ���������� ������ - ��������� ��� ������ � ���������� � ��������� ����� 
		fs.read((char*)&countBills_, sizeof(countBills_));

		// ���� �������
		fs.read((char*)&datePay_, sizeof(datePay_));

		// ����� �������
		fs.read((char*)&sumPay_, sizeof(sumPay_));

		// ������ Bill
		Bill tmp;

		// ��������� ��������(������� ������ Bill)
		for (int i = 0; i < countBills_; i++)
		{
			// ���������� 
			tmp.read(fs);

			// ���������� � ������ 
			bills_.push_back(tmp);
		}
		
		// �������� ������ 
		delete[] buf;
	}

	// ����� ���������� � �������
	time_t Payer::timeCall()
	{
		// ���������� ����� 
		int countMinute = 0;

		// ������������ ����� ���� ����������
		for_each(bills_.begin(), bills_.end(), [&countMinute](Bill bill) { countMinute += bill.callTime(); });

		return countMinute;
	}

	// ����� ��������� ������� 
	void Payer::showHead()
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� 1
		short clOne = LTGREEN_ON_BLACK;

		// ���� 2
		short clTwo = LTYELLOW_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� �������������� �����
		showLine();

		cout << "     "
			<< color(clLine) << "| "
			<< color(clTwo) << " N  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  ������� � ��������  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  �����   "
			<< color(clLine) << " | "
			<< color(clTwo) << "����� "
			<< color(clLine) << " | "
			<< color(clTwo) << "������"
			<< color(clLine) << " | "
			<< color(clTwo) << "���."
			<< color(clLine) << " | "
			<< color(clTwo) << "    ���� �������    "
			<< color(clLine) << " | "
			<< color(clTwo) << " �����  "
			<< color(clLine) << " |\n";

		// ����� �������������� �����
		showLine();
	}

	// ����� ��������� ������� � ������� ������� ��������
	void Payer::showHeadTime()
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� 1
		short clOne = LTGREEN_ON_BLACK;

		// ���� 2
		short clTwo = LTYELLOW_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� �������������� �����
		showLineTime();

		cout << " "
			<< color(clLine) << "| "
			<< color(clTwo) << " N  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  ������� � ��������  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  �����   "
			<< color(clLine) << " | "
			<< color(clTwo) << "����� "
			<< color(clLine) << " | "
			<< color(clTwo) << "������"
			<< color(clLine) << " | "
			<< color(clTwo) << "���."
			<< color(clLine) << " | "
			<< color(clTwo) << "    ���� �������    "
			<< color(clLine) << " | "
			<< color(clTwo) << " �����  "
			<< color(clLine) << " | "
			<< color(clTwo) << "�����(���) "
			<< color(clLine) << " |\n";

		// ����� �������������� �����
		showLineTime();

	}

	// ����� ����������� 
	void Payer::showLine()
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

	// ����� ����������� � ������� ������� ��������
	void Payer::showLineTime()
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� �����-�����������
		cout << " " << color(clLine)
			//	   4				22				   10		  6		   6	  4		         20				  8	
			<< "+������+������������������������+������������+��������+��������+������+����������������������+����������+�������������+\n"
			<< color(cl);
	}

	// ����� �������� ��� �������
	void Payer::showPayer(int index)
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� 1
		short clOne = LTGREEN_ON_BLACK;

		// ���� 2
		short clTwo = LTYELLOW_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		cout.precision(2);

		cout << "     "
			<< color(clLine) << "| "
			<< color(LTBLACK_ON_BLACK) << setw(4) << index
			<< color(clLine) << " | "
			<< color(clTwo) << left << setw(22) << namePayer_ << right
			<< color(clLine) << " | "
			<< color(clOne) << setw(10) << phoneNumber_
			<< color(clLine) << " | "
			<< color(clOne) << setw(6) << rate_
			<< color(clLine) << " | "
			<< color(clOne) << setw(5) << discount_ << "%"
			<< color(clLine) << " | "
			<< color(clTwo) << setw(4) << countBills_
			<< color(clLine) << " | ";
			datePay_.showDateTime(clOne);
		cout << color(clLine) << "  | "
			<< color(clTwo) << setw(8) << sumPay_
			<< color(clLine) << " |\n";
	}

	// ����� �������� ��� ������� ������� ������� ��������
	void Payer::showPayerTime(int index)
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� 1
		short clOne = LTGREEN_ON_BLACK;

		// ���� 2
		short clTwo = LTYELLOW_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		cout.precision(2);

		cout << " "
			<< color(clLine) << "| "
			<< color(LTBLACK_ON_BLACK) << setw(4) << index
			<< color(clLine) << " | "
			<< color(clTwo) << left << setw(22) << namePayer_ << right
			<< color(clLine) << " | "
			<< color(clOne) << setw(10) << phoneNumber_
			<< color(clLine) << " | "
			<< color(clOne) << setw(6) << rate_
			<< color(clLine) << " | "
			<< color(clOne) << setw(5) << discount_ << "%"
			<< color(clLine) << " | "
			<< color(clTwo) << setw(4) << countBills_
			<< color(clLine) << " | ";
		datePay_.showDateTime(clOne);
		cout << color(clLine) << "  | "
			<< color(clTwo) << setw(8) << sumPay_
			<< color(clLine) << " | "
			<< color(clOne) << setw(11) << timeCall()
			<< color(clLine) << " |\n";
	}

	// ����� �������� 
	void Payer::showBills()
	{
		Bill::showHead(getSumPay());

		int index = 1;

		double rate = rate_;
		double discount = discount_;

		for_each(bills_.begin(), bills_.end(), [index, rate, discount](Bill bill) mutable { bill.showElem(index++, rate, discount); });

		Bill::showLine();
	}

	// ���������� �������� ���������
	
	// ������ 
	bool Payer::operator<(const Payer& payer) const {
		return namePayer_ < payer.namePayer_ and phoneNumber_ < payer.phoneNumber_ and
		rate_ < payer.rate_ and discount_ < payer.discount_ and countBills_ < payer.countBills_ 
		and datePay_ < payer.datePay_ and sumPay_ < payer.sumPay_ and bills_ < payer.bills_;
	}

	// ������ ��� �����
	bool Payer::operator<=(const Payer& payer) const {
		return namePayer_ <= payer.namePayer_ and phoneNumber_ <= payer.phoneNumber_ and
			rate_ <= payer.rate_ and discount_ <= payer.discount_ and countBills_ <= payer.countBills_ 
			and datePay_ <= payer.datePay_ and sumPay_ <= payer.sumPay_ and bills_ <= payer.bills_;
	}

	// �����
	bool Payer::operator==(const Payer& payer) const {
		return namePayer_ == payer.namePayer_ and phoneNumber_ == payer.phoneNumber_ and
			rate_ == payer.rate_ and discount_ == payer.discount_ and countBills_ == payer.countBills_ 
			and datePay_ == payer.datePay_ and sumPay_ == payer.sumPay_ and bills_ == payer.bills_;
	}

	// �� �����
	bool Payer::operator!=(const Payer& payer) const {
		return namePayer_ != payer.namePayer_ and phoneNumber_ != payer.phoneNumber_ and
			rate_ != payer.rate_ and discount_ != payer.discount_ and countBills_ != payer.countBills_ 
			and datePay_ != payer.datePay_ and sumPay_ != payer.sumPay_ and bills_ != payer.bills_;
	}

	// ������ ��� �����
	bool Payer::operator>=(const Payer& payer) const {
		return namePayer_ >= payer.namePayer_ and phoneNumber_ >= payer.phoneNumber_ and
			rate_ >= payer.rate_ and discount_ >= payer.discount_ and countBills_ >= payer.countBills_ 
			and datePay_ >= payer.datePay_ and sumPay_ >= payer.sumPay_ and bills_ >= payer.bills_;
	}

	// ������ 
	bool Payer::operator>(const Payer& payer) const {
		return namePayer_ > payer.namePayer_ and phoneNumber_ > payer.phoneNumber_ and
			rate_ > payer.rate_ and discount_ > payer.discount_ and countBills_ > payer.countBills_ 
			and datePay_ > payer.datePay_ and sumPay_ > payer.sumPay_ and bills_ > payer.bills_;
	}

#pragma endregion 
	
#pragma region ������������� ������� 
	
	// ����� � ������
	ostream& operator<<(ostream & os, const Payer& payer)
	{
		os << payer.namePayer_ << ";" << payer.phoneNumber_ << ";" 
			<< payer.rate_ << ";" << payer.discount_ << ";" 
			<< payer.countBills_ << ";" << payer.datePay_ << ";" << payer.sumPay_ << "\n";

		// ����� ������� 
		for_each(payer.bills_.begin(), payer.bills_.end(), [&os](Bill bill) { os << bill; });

		return os;
	}
	
#pragma endregion
	