#pragma once
#include "Triad.h"

class Time : public Triad
{
protected:
	// a_, b_, c_ объявлены в базовом классе
	int &hours_   = a_;  // ссылочная переменная hours - это синоним для a
	int &minutes_ = b_;  // т.е. это 2 имени для ячейки памяти
	int &seconds_ = c_;

public:
	Time() = default;
	
	Time(int hours, int minutes, int seconds): 
	   Triad(hours, minutes, seconds)
	{
		// TODO: использовать сеттеры для установки правильных значений 
	}

	Time(const Time &time) = default;
	~Time() = default;

	// увеличить секунды на 1
	int incSeconds() {
		seconds_++;
		if (seconds_ > 59) {
			seconds_ = 0;
			incMinutes();
		} // if

		return seconds_;
	} // incSeconds

	// увеличить минуты на 1
	int incMinutes() {
		minutes_++;
		if (minutes_ > 59) {
			minutes_ = 0;
			incHours();  // 
		} // if

		return minutes_;
	} // incMinutes

	// увеличить часы на 1, без контроля - просто вызываем метод
	// базового класса, делегирование
	int incHours() { return incA(); } // incHours

	friend ostream &operator<<(ostream &os, const Time &time);

};

// реализация оператора вывода
inline ostream &operator<<(ostream &os, const Time &time)
{
	os << setfill('0') 
	   << setw(2) << time.hours_ << ":" 
	   << setw(2) << time.minutes_ << ":" 
	   << setw(2) << time.seconds_
	   << setfill(' ');
	return os;
} // operator<<
