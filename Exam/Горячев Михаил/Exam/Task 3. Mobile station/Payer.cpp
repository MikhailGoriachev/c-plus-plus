#include "Payer.h"

// минимальное значение DateTime
const DateTime Payer::V_MIN_DATE = DateTime(1, 1, 1970, 0, 0, 0);

#pragma region Конструкторы, деструктор и перегрузка операции присваивания 

	// конструктор инициализирующий 
	Payer::Payer(string namePayer, string phoneNumber, double rate, double discount, DateTime datePay) 
		: countBills_(), sumPay_()
	{
		// установка значений 
		setNamePayer(namePayer);
		setPhoneNumber(phoneNumber);
		setRate(rate);
		setDiscount(discount);
		setDatePay(datePay);
	}
	
#pragma endregion
	
#pragma region Сеттеры и геттеры 
	
	// сеттер namePayer_
	void Payer::setNamePayer(string namePayer)
	{
		// размер строки
		int size = (int)namePayer.size();

		// если данные некорректны
		if (size < N_MIN_NAME_PAYER or size > N_MAX_NAME_PAYER)
			throw exception("App: Некорректные данные!");

		// установка значения 
		namePayer_ = namePayer;
	}

	// геттер namePayer_
	const string& Payer::getNamePayer() const { return namePayer_; }

	// сеттер phoneNumber_ 
	void Payer::setPhoneNumber(string phoneNumber)
	{
		// размер строки
		int size = (int)phoneNumber.size();

		// если данные некорректны
		if (size != N_PHONE_NUMBER)
			throw exception("App: Некорректные данные!");

		// установка значения 
		phoneNumber_ = phoneNumber;
	}

	// геттер phoneNumber_
	const string& Payer::getPhoneNumber() const { return phoneNumber_; }

	// сеттер rate_
	void Payer::setRate(double rate)
	{
		// если данные некорректны
		if (rate < V_MIN_RATE or rate > V_MAX_RATE)
			throw exception("App: Некорректные данные!");

		// установка значения 
		rate_ = rate;
	}

	// геттер rate_
	double Payer::getRate() const { return rate_; }

	// сеттер discount_
	void Payer::setDiscount(double discount)
	{
		// если данные некорректны
		if (discount < V_MIN_DISCOUNT or discount > V_MAX_DISCOUNT)
			throw exception("App: Некорректные данные!");

		// установка значения 
		discount_ = discount;
	}

	// геттер discount_
	double Payer::getDiscount() const { return discount_; }

	// сеттер datePay_ 
	void Payer::setDatePay(DateTime datePay)
	{
		// если данные некорректны
		if (datePay > DateTime() or datePay < V_MIN_DATE)
			throw exception("App: Данные некорректны!");

		// установка значения 
		datePay_ = datePay;
	}

	// геттер datePay_
	const DateTime& Payer::getDatePay() { return datePay_; }

	// геттер sumPay_
	double Payer::getSumPay() { return sumPay_; }

	// сеттер bills_
	void Payer::setBills(vector<Bill> bills)
	{
		// копирование вектора 
		for (auto bill : bills)
			addBill(bill);

		// установка счётчика 
		countBills_ = (int)bills.size();
	}

	// геттер bills_
	const vector<Bill>& Payer::getBills() { return bills_; }

#pragma endregion 

#pragma region Методы 

	// добавление платежа 
	void Payer::addBill(Bill bill)
	{
		// если дата и время окончания звонка больше, чем дата платежа
		if (bill.getEndCall() > datePay_)
			throw exception("App: некорректные данные!");

		// добавление суммы текущего платежа к общей сумме 
		sumPay_ += bill.pay(rate_, discount_);

		// добавление объекта Bill в вектор с счетами
		bills_.push_back(bill);
	}

	// запись в бинарный файл 
	void Payer::write(fstream& fs)
	{
		// размер буфера
		const int SIZE_BUF = 400;

		// буфер строки для записи
		char* buf = new char[SIZE_BUF + 1]{ 0 };


		// фамилия и инициалы плательщика
		strcpy(buf,namePayer_.c_str());

		// запись в файл 
		fs.write(buf, Payer::N_MAX_NAME_PAYER);


		// отчистка буфера 
		memset(buf, 0, SIZE_BUF);


		// номер телефона
		strcpy(buf, phoneNumber_.c_str());

		// запись в файл 
		fs.write(buf, Payer::N_PHONE_NUMBER);


		// тариф за минуту разговора
		fs.write((const char*)&rate_, sizeof(rate_));

		// скидка(в процентах)
		fs.write((const char*)&discount_, sizeof(discount_));

		// количество счетов - требуется для записи и считывания с бинарного файла 
		fs.write((const char*)&countBills_, sizeof(countBills_));

		// дата платежа
		fs.write((char*)&datePay_, sizeof(datePay_));

		// сумма платежа
		fs.write((char*)&sumPay_, sizeof(sumPay_));

		// коллекция платежей(объекты класса Bill)
		for_each(bills_.begin(), bills_.end(), [&fs](Bill bill) { bill.write(fs); });

		// отчистка памяти 
		delete[] buf;
	}

	// чтение из бинарного файла 
	void Payer::read(fstream& fs)
	{
		// размер буфера
		const int SIZE_BUF = 400;

		// буфер строки для чтения
		char* buf = new char[SIZE_BUF + 1]{ 0 };


		// чтение из файла
		fs.read(buf, Payer::N_MAX_NAME_PAYER);

		// фамилия и инициалы плательщика
		namePayer_ = buf;


		// отчистка буфера 
		memset(buf, 0, SIZE_BUF);


		// чтение из файла
		fs.read(buf, Payer::N_PHONE_NUMBER);

		// номер телефона 
		phoneNumber_ = buf;

		// тариф за минуту разговора
		fs.read((char*)&rate_, sizeof(rate_));

		// скидка(в процентах)
		fs.read((char*)&discount_, sizeof(discount_));

		// количество счетов - требуется для записи и считывания с бинарного файла 
		fs.read((char*)&countBills_, sizeof(countBills_));

		// дата платежа
		fs.read((char*)&datePay_, sizeof(datePay_));

		// сумма платежа
		fs.read((char*)&sumPay_, sizeof(sumPay_));

		// объект Bill
		Bill tmp;

		// коллекция платежей(объекты класса Bill)
		for (int i = 0; i < countBills_; i++)
		{
			// считывание 
			tmp.read(fs);

			// добавление в вектор 
			bills_.push_back(tmp);
		}
		
		// отчистка памяти 
		delete[] buf;
	}

	// время разговоров в минутах
	time_t Payer::timeCall()
	{
		// количество минут 
		int countMinute = 0;

		// суммирование минут всех разговоров
		for_each(bills_.begin(), bills_.end(), [&countMinute](Bill bill) { countMinute += bill.callTime(); });

		return countMinute;
	}

	// вывод заголовка таблицы 
	void Payer::showHead()
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет 1
		short clOne = LTGREEN_ON_BLACK;

		// цвет 2
		short clTwo = LTYELLOW_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод разделительной черты
		showLine();

		cout << "     "
			<< color(clLine) << "| "
			<< color(clTwo) << " N  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  Фамилия и инициалы  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  Номер   "
			<< color(clLine) << " | "
			<< color(clTwo) << "Тариф "
			<< color(clLine) << " | "
			<< color(clTwo) << "Скидка"
			<< color(clLine) << " | "
			<< color(clTwo) << "Кол."
			<< color(clLine) << " | "
			<< color(clTwo) << "    Дата платежа    "
			<< color(clLine) << " | "
			<< color(clTwo) << " Сумма  "
			<< color(clLine) << " |\n";

		// вывод разделительной черты
		showLine();
	}

	// вывод заголовка таблицы с выводом времени разгоров
	void Payer::showHeadTime()
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет 1
		short clOne = LTGREEN_ON_BLACK;

		// цвет 2
		short clTwo = LTYELLOW_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод разделительной черты
		showLineTime();

		cout << " "
			<< color(clLine) << "| "
			<< color(clTwo) << " N  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  Фамилия и инициалы  "
			<< color(clLine) << " | "
			<< color(clTwo) << "  Номер   "
			<< color(clLine) << " | "
			<< color(clTwo) << "Тариф "
			<< color(clLine) << " | "
			<< color(clTwo) << "Скидка"
			<< color(clLine) << " | "
			<< color(clTwo) << "Кол."
			<< color(clLine) << " | "
			<< color(clTwo) << "    Дата платежа    "
			<< color(clLine) << " | "
			<< color(clTwo) << " Сумма  "
			<< color(clLine) << " | "
			<< color(clTwo) << "Время(мин) "
			<< color(clLine) << " |\n";

		// вывод разделительной черты
		showLineTime();

	}

	// вывод разделителя 
	void Payer::showLine()
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

	// вывод разделителя с выводом времени разгоров
	void Payer::showLineTime()
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод линии-разделителя
		cout << " " << color(clLine)
			//	   4				22				   10		  6		   6	  4		         20				  8	
			<< "+——————+————————————————————————+————————————+————————+————————+——————+——————————————————————+——————————+—————————————+\n"
			<< color(cl);
	}

	// вывод элемента для таблицы
	void Payer::showPayer(int index)
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет 1
		short clOne = LTGREEN_ON_BLACK;

		// цвет 2
		short clTwo = LTYELLOW_ON_BLACK;

		// цвет по умолчанию
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

	// вывод элемента для таблицы выводом времени разгоров
	void Payer::showPayerTime(int index)
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет 1
		short clOne = LTGREEN_ON_BLACK;

		// цвет 2
		short clTwo = LTYELLOW_ON_BLACK;

		// цвет по умолчанию
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

	// вывод платежей 
	void Payer::showBills()
	{
		Bill::showHead(getSumPay());

		int index = 1;

		double rate = rate_;
		double discount = discount_;

		for_each(bills_.begin(), bills_.end(), [index, rate, discount](Bill bill) mutable { bill.showElem(index++, rate, discount); });

		Bill::showLine();
	}

	// перегрузка операций сравнения
	
	// меньше 
	bool Payer::operator<(const Payer& payer) const {
		return namePayer_ < payer.namePayer_ and phoneNumber_ < payer.phoneNumber_ and
		rate_ < payer.rate_ and discount_ < payer.discount_ and countBills_ < payer.countBills_ 
		and datePay_ < payer.datePay_ and sumPay_ < payer.sumPay_ and bills_ < payer.bills_;
	}

	// меньше или равно
	bool Payer::operator<=(const Payer& payer) const {
		return namePayer_ <= payer.namePayer_ and phoneNumber_ <= payer.phoneNumber_ and
			rate_ <= payer.rate_ and discount_ <= payer.discount_ and countBills_ <= payer.countBills_ 
			and datePay_ <= payer.datePay_ and sumPay_ <= payer.sumPay_ and bills_ <= payer.bills_;
	}

	// равно
	bool Payer::operator==(const Payer& payer) const {
		return namePayer_ == payer.namePayer_ and phoneNumber_ == payer.phoneNumber_ and
			rate_ == payer.rate_ and discount_ == payer.discount_ and countBills_ == payer.countBills_ 
			and datePay_ == payer.datePay_ and sumPay_ == payer.sumPay_ and bills_ == payer.bills_;
	}

	// НЕ равно
	bool Payer::operator!=(const Payer& payer) const {
		return namePayer_ != payer.namePayer_ and phoneNumber_ != payer.phoneNumber_ and
			rate_ != payer.rate_ and discount_ != payer.discount_ and countBills_ != payer.countBills_ 
			and datePay_ != payer.datePay_ and sumPay_ != payer.sumPay_ and bills_ != payer.bills_;
	}

	// больше или равно
	bool Payer::operator>=(const Payer& payer) const {
		return namePayer_ >= payer.namePayer_ and phoneNumber_ >= payer.phoneNumber_ and
			rate_ >= payer.rate_ and discount_ >= payer.discount_ and countBills_ >= payer.countBills_ 
			and datePay_ >= payer.datePay_ and sumPay_ >= payer.sumPay_ and bills_ >= payer.bills_;
	}

	// больше 
	bool Payer::operator>(const Payer& payer) const {
		return namePayer_ > payer.namePayer_ and phoneNumber_ > payer.phoneNumber_ and
			rate_ > payer.rate_ and discount_ > payer.discount_ and countBills_ > payer.countBills_ 
			and datePay_ > payer.datePay_ and sumPay_ > payer.sumPay_ and bills_ > payer.bills_;
	}

#pragma endregion 
	
#pragma region Дружественные функции 
	
	// вывод в строку
	ostream& operator<<(ostream & os, const Payer& payer)
	{
		os << payer.namePayer_ << ";" << payer.phoneNumber_ << ";" 
			<< payer.rate_ << ";" << payer.discount_ << ";" 
			<< payer.countBills_ << ";" << payer.datePay_ << ";" << payer.sumPay_ << "\n";

		// вывод вектора 
		for_each(payer.bills_.begin(), payer.bills_.end(), [&os](Bill bill) { os << bill; });

		return os;
	}
	
#pragma endregion
	