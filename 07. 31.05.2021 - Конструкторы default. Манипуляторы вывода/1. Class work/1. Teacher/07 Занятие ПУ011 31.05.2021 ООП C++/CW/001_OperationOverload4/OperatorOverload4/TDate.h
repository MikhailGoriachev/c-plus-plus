#pragma once

// —оздайте класс, описывающий дату: день, мес€ц, год. 
// –еализуйте конструкторы по умолчанию, с параметрами (день, мес€ц, год). 
// –азработайте геттеры и сеттеры.
// ѕерегрузите операции методами класса:
//     Х ќпераци€ Ц разность двух дат, возвращает количество дней между датами
//     Х ќпераци€ + добавление к дате заданного количества дней, возвращает дату
//     Х ќперации <, <=, ==, !=, >=, >
//     Х ќперации ++, -- возвращающие следующую и предыдущую даты соответственно
// ƒружественной функцией перегрузите операцию вывода <<
// ќбычной функцией перегрузите операцию ввода >> 

class TDate
{
    int day_;      // день
    int month_;    // мес€ц
    int year_;     // год

    // вспомогательные методы
    int toJulianDays() const;
    void ToGrigorian(int julianDays);
    bool DateValid(int day, int month, int year);

    int DaysInMonth(int month, int year);
    bool IsLeapYear(int year);

public:
    // ансамбль конструкторов
    TDate(): day_(1), month_(1), year_(1970) {}
    TDate(int day, int month, int year)    
    {
        SetDate(day, month, year);
    }

	// создание конструктора по умолчанию
	// !!! копирующий конструктор !!! имеют специальный синтаксис !!! изучаем позже !!!
	//                                прием константной или неконстантной ссылки 
    TDate(const TDate& date) = default;

    // создание деструктора по умолчанию
	~TDate() = default;

    // геттеры и сеттер
    int GetDay()   const { return day_;   }
    int GetMonth() const { return month_; }
    int GetYear()  const { return year_;  }

    void SetDate(int day, int month, int year);

    // перегруженные операторы
    // a = Date();
    // a = b = c = Date()
    // TDate &operator=(const TDate &date) = default;
    TDate &operator=(const TDate &date);

    TDate operator+(int days) const;
    int operator-(const TDate &date) const;

    TDate &operator++();     // префиксный оператор
    TDate operator++(int);   // постфиксный оператор - использует псевдопараметр 
    
    TDate &operator--();    // префиксный оператор
    TDate operator--(int);  // постфиксный оператор - использует псевдопараметр

    // ќперации <, <=, ==, !=, >=, >
    bool operator< (const TDate &date) const;
    bool operator<=(const TDate &date) const;
    bool operator==(const TDate &date) const;
    bool operator!=(const TDate &date) const;
    bool operator>=(const TDate &date) const;
    bool operator> (const TDate &date) const;

    friend ostream &operator<<(ostream &os, const TDate &date);
    friend TDate operator+(int days, const TDate &date);
};

istream &operator>>(istream &is, TDate &date);


