#include "Bill.h"

// минимальное значение DateTime
const DateTime Bill::V_MIN_DATE = DateTime(1, 1, 1970, 0, 0, 0);

#pragma region Конструкторы, деструктор и перегрузка операции присваивания

	// конструктор инициализирующий
	Bill::Bill(DateTime startCall, DateTime endCall)
	{
		// установка значений 
		setTime(startCall, endCall);
	}

#pragma endregion

#pragma region Сеттеры и геттеры

	// сеттер времени платежа 
	void Bill::setTime(DateTime startCall, DateTime endCall)
	{
		// если данные некорректны 
		if (endCall > DateTime() or startCall < V_MIN_DATE or startCall > endCall)
			throw exception("App: Данные некорректны!");

		// установка значений 
		startCall_ = startCall;
		endCall_ = endCall;
	}

	// геттер startCall_
	DateTime& Bill::getStartCall() { return startCall_; }

	// геттер endCall_
	DateTime& Bill::getEndCall() { return endCall_; }

#pragma endregion

#pragma region Методы

	// вычисление суммы к оплате за разговор
	double Bill::pay(double rate, double discount)
	{
		// сумма к оплате
		double sumPay;

		// разница в секундах между началом и окончанием разговора
		time_t diffSec = DateTime::differenceTime(endCall_, startCall_);

		// разница в минутах с округлением до целой минуты между началом и окончанием разговора
		time_t diffMin = diffSec % 60 > 0 ? (diffSec / 60) + 1 : diffSec / 60;

		// сумма к оплате без скидки
		sumPay = diffMin * rate;

		// сумма со скидкой 
		sumPay -= sumPay / 100 * discount;

		return sumPay;
	}

	// запись в бинарный файл
	void Bill::write(fstream& fs)
	{
		// запись данных
		startCall_.write(fs);
		endCall_.write(fs);
	}

	// чтение из бинарного файла 
	void Bill::read(fstream& fs)
	{
		// чтение данных
		startCall_.read(fs);
		endCall_.read(fs);
	}

	// время разговора в минутах
	time_t Bill::callTime()
	{
		// разница в секундах между началом и окончанием разговора
		time_t diffSec = DateTime::differenceTime(endCall_, startCall_);

		// разница в минутах с округлением до целой минуты между началом и окончанием разговора
		return diffSec % 60 > 0 ? (diffSec / 60) + 1 : diffSec / 60;
	}

	// вывод шапки таблицы
	void Bill::showHead(double minutes)
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет 1
		short clOne = LTYELLOW_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод разделительной линии
		showLine();

		// вывод шапки таблицы
		cout << "     "
			<< color(clLine) << "| "
			<< color(clOne) << "  Number  "
			<< color(clLine) << " | "
			<< color(clOne) << "    Начало разговора     "
			<< color(clLine) << " | "
			<< color(clOne) << "  Окончание разговора    "
			<< color(clLine) << " | "
			<< color(clOne) << "    Минуты     "
			<< color(clLine) << " | "
			<< color(clOne) << "     Сумма     "
			<< color(clLine) << "|\n" << color(cl);

		// вывод разделительной линии
		showLine();
	}

	// вывод элемента таблицы
	void Bill::showElem(int index, double rate, double discount)
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
			<< color(LTBLACK_ON_BLACK) << setw(10) << index
			<< color(clLine) << " |    "; startCall_.showDateTime(clOne);
		cout << color(clLine) << "    |    "; endCall_.showDateTime(clOne);
		cout << color(clLine) << "    | "
			<< color(clTwo) << setw(15) << DateTime::differenceTime(endCall_, startCall_) / 60
			<< color(clLine) << " | "
			<< color(clTwo) << setw(14) << pay(rate, discount)
			<< color(clLine) << " |\n" << color(cl);
	}

	// вывод разделителя
	void Bill::showLine()
	{
		// цвет для линий 
		short clLine = LTCYAN_ON_BLACK;

		// цвет по умолчанию
		short cl = getColor();

		// вывод линии-разделителя
		cout << "     " << color(clLine)
			//	     10			         25				   	           25	  				  15               14
			<< "+————————————+———————————————————————————+———————————————————————————+—————————————————+————————————————+\n"
			<< color(cl);
	}

	// перегрузка операций сравнения

	// меньше 
	bool Bill::operator<(const Bill& bill) const {
		return startCall_ < bill.startCall_ and endCall_ < bill.endCall_;
	}

	// меньше или равно
	bool Bill::operator<=(const Bill& bill) const {
		return startCall_ <= bill.startCall_ and endCall_ <= bill.endCall_;
	}

	// равно
	bool Bill::operator==(const Bill& bill) const {
		return startCall_ == bill.startCall_ and endCall_ == bill.endCall_;
	}

	// НЕ равно
	bool Bill::operator!=(const Bill& bill) const {
		return startCall_ != bill.startCall_ and endCall_ != bill.endCall_ ;
	}

	// больше или равно
	bool Bill::operator>=(const Bill& bill) const {
		return startCall_ >= bill.startCall_ and endCall_ >= bill.endCall_;
	}

	// больше 
	bool Bill::operator>(const Bill& bill) const {
		return startCall_ > bill.startCall_ and endCall_ > bill.endCall_;
	}

#pragma endregion

#pragma region Дружественные фукнции

	// вывод в строку
	ostream& operator<<(ostream& os, const Bill& bill)
	{
		os << bill.startCall_ << ";" << bill.endCall_ << "\n";

		return os;
	}
	
#pragma endregion
