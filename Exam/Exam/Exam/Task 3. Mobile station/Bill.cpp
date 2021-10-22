#include "Bill.h"

// ����������� �������� DateTime
const DateTime Bill::V_MIN_DATE = DateTime(1, 1, 1970, 0, 0, 0);

#pragma region ������������, ���������� � ���������� �������� ������������

	// ����������� ����������������
	Bill::Bill(DateTime startCall, DateTime endCall)
	{
		// ��������� �������� 
		setTime(startCall, endCall);
	}

#pragma endregion

#pragma region ������� � �������

	// ������ ������� ������� 
	void Bill::setTime(DateTime startCall, DateTime endCall)
	{
		// ���� ������ ����������� 
		if (endCall > DateTime() or startCall < V_MIN_DATE or startCall > endCall)
			throw exception("App: ������ �����������!");

		// ��������� �������� 
		startCall_ = startCall;
		endCall_ = endCall;
	}

	// ������ startCall_
	DateTime& Bill::getStartCall() { return startCall_; }

	// ������ endCall_
	DateTime& Bill::getEndCall() { return endCall_; }

#pragma endregion

#pragma region ������

	// ���������� ����� � ������ �� ��������
	double Bill::pay(double rate, double discount)
	{
		// ����� � ������
		double sumPay;

		// ������� � �������� ����� ������� � ���������� ���������
		time_t diffSec = DateTime::differenceTime(endCall_, startCall_);

		// ������� � ������� � ����������� �� ����� ������ ����� ������� � ���������� ���������
		time_t diffMin = diffSec % 60 > 0 ? (diffSec / 60) + 1 : diffSec / 60;

		// ����� � ������ ��� ������
		sumPay = diffMin * rate;

		// ����� �� ������� 
		sumPay -= sumPay / 100 * discount;

		return sumPay;
	}

	// ������ � �������� ����
	void Bill::write(fstream& fs)
	{
		// ������ ������
		startCall_.write(fs);
		endCall_.write(fs);
	}

	// ������ �� ��������� ����� 
	void Bill::read(fstream& fs)
	{
		// ������ ������
		startCall_.read(fs);
		endCall_.read(fs);
	}

	// ����� ��������� � �������
	time_t Bill::callTime()
	{
		// ������� � �������� ����� ������� � ���������� ���������
		time_t diffSec = DateTime::differenceTime(endCall_, startCall_);

		// ������� � ������� � ����������� �� ����� ������ ����� ������� � ���������� ���������
		return diffSec % 60 > 0 ? (diffSec / 60) + 1 : diffSec / 60;
	}

	// ����� ����� �������
	void Bill::showHead(double minutes)
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� 1
		short clOne = LTYELLOW_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� �������������� �����
		showLine();

		// ����� ����� �������
		cout << "     "
			<< color(clLine) << "| "
			<< color(clOne) << "  Number  "
			<< color(clLine) << " | "
			<< color(clOne) << "    ������ ���������     "
			<< color(clLine) << " | "
			<< color(clOne) << "  ��������� ���������    "
			<< color(clLine) << " | "
			<< color(clOne) << "    ������     "
			<< color(clLine) << " | "
			<< color(clOne) << "     �����     "
			<< color(clLine) << "|\n" << color(cl);

		// ����� �������������� �����
		showLine();
	}

	// ����� �������� �������
	void Bill::showElem(int index, double rate, double discount)
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
			<< color(LTBLACK_ON_BLACK) << setw(10) << index
			<< color(clLine) << " |    "; startCall_.showDateTime(clOne);
		cout << color(clLine) << "    |    "; endCall_.showDateTime(clOne);
		cout << color(clLine) << "    | "
			<< color(clTwo) << setw(15) << DateTime::differenceTime(endCall_, startCall_) / 60
			<< color(clLine) << " | "
			<< color(clTwo) << setw(14) << pay(rate, discount)
			<< color(clLine) << " |\n" << color(cl);
	}

	// ����� �����������
	void Bill::showLine()
	{
		// ���� ��� ����� 
		short clLine = LTCYAN_ON_BLACK;

		// ���� �� ���������
		short cl = getColor();

		// ����� �����-�����������
		cout << "     " << color(clLine)
			//	     10			         25				   	           25	  				  15               14
			<< "+������������+���������������������������+���������������������������+�����������������+����������������+\n"
			<< color(cl);
	}

	// ���������� �������� ���������

	// ������ 
	bool Bill::operator<(const Bill& bill) const {
		return startCall_ < bill.startCall_ and endCall_ < bill.endCall_;
	}

	// ������ ��� �����
	bool Bill::operator<=(const Bill& bill) const {
		return startCall_ <= bill.startCall_ and endCall_ <= bill.endCall_;
	}

	// �����
	bool Bill::operator==(const Bill& bill) const {
		return startCall_ == bill.startCall_ and endCall_ == bill.endCall_;
	}

	// �� �����
	bool Bill::operator!=(const Bill& bill) const {
		return startCall_ != bill.startCall_ and endCall_ != bill.endCall_ ;
	}

	// ������ ��� �����
	bool Bill::operator>=(const Bill& bill) const {
		return startCall_ >= bill.startCall_ and endCall_ >= bill.endCall_;
	}

	// ������ 
	bool Bill::operator>(const Bill& bill) const {
		return startCall_ > bill.startCall_ and endCall_ > bill.endCall_;
	}

#pragma endregion

#pragma region ������������� �������

	// ����� � ������
	ostream& operator<<(ostream& os, const Bill& bill)
	{
		os << bill.startCall_ << ";" << bill.endCall_ << "\n";

		return os;
	}
	
#pragma endregion
