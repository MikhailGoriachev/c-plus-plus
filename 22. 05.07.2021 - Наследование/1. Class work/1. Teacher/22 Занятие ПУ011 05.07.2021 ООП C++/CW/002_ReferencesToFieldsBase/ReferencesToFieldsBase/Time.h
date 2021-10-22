#pragma once
#include "Triad.h"

class Time : public Triad
{
protected:
	// a_, b_, c_ ��������� � ������� ������
	int &hours_   = a_;  // ��������� ���������� hours - ��� ������� ��� a
	int &minutes_ = b_;  // �.�. ��� 2 ����� ��� ������ ������
	int &seconds_ = c_;

public:
	Time() = default;
	
	Time(int hours, int minutes, int seconds): 
	   Triad(hours, minutes, seconds)
	{
		// TODO: ������������ ������� ��� ��������� ���������� �������� 
	}

	Time(const Time &time) = default;
	~Time() = default;

	// ��������� ������� �� 1
	int incSeconds() {
		seconds_++;
		if (seconds_ > 59) {
			seconds_ = 0;
			incMinutes();
		} // if

		return seconds_;
	} // incSeconds

	// ��������� ������ �� 1
	int incMinutes() {
		minutes_++;
		if (minutes_ > 59) {
			minutes_ = 0;
			incHours();  // 
		} // if

		return minutes_;
	} // incMinutes

	// ��������� ���� �� 1, ��� �������� - ������ �������� �����
	// �������� ������, �������������
	int incHours() { return incA(); } // incHours

	friend ostream &operator<<(ostream &os, const Time &time);

};

// ���������� ��������� ������
inline ostream &operator<<(ostream &os, const Time &time)
{
	os << setfill('0') 
	   << setw(2) << time.hours_ << ":" 
	   << setw(2) << time.minutes_ << ":" 
	   << setw(2) << time.seconds_
	   << setfill(' ');
	return os;
} // operator<<
