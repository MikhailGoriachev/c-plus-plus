#pragma once
#include "pch.h"
#include "Date.h"


/*
 * Элемент очереди нуждающихся в улучшении жилищных условий. Хранит фамилию,
 * имя и отчество претендента, количество членов семьи, площадь квартиры в м2,
 * количество комнат, дату постановки на учет (день, месяц, год).
 */
class Applicant
{
public:
	// длины буферов строковых полей класса
	//               фамилия         имя          отчество
	static const int N_SURNAME = 61, N_NAME = 51, N_PATRONYMIC = 61;

private:
	char*  surname_;        // фамилию
	char*  name_;           // имя
	char*  patronymic_;     // отчество
	int    familyMembers_;  // количество членов семьи
	double area_;           // площадь квартиры в м2
	int    rooms_;          // количество комнат
	Date   acceptDate_;     // дата постановки на учет (день, месяц, год)

	static const int N_BUF = 1024;
	char* buf_;  // буфер вывода данных в строковом формате

public:
	Applicant():Applicant(
		"Иванов", "Иван", "Иванович", 
		4, 120.2, 3, 
			Date{1,1,2021})
	{  } // Applicant

	Applicant(const char* surname, const char* name, const char* patronymic, 
		int familyMembers, double area, int rooms, const Date& acceptDate)
		: surname_(new char[N_SURNAME] {0}),
		  name_(new char[N_NAME] {0}),
		  patronymic_(new char[N_PATRONYMIC]), buf_(new char[N_BUF] {0})
	{
		setSurname(surname);
		setName(name);
		setPatronymic(patronymic);
		setFamilyMembers(familyMembers);
		setArea(area);
		setRooms(rooms);
		setAcceptDate(acceptDate);
	} // Applicant

	// копирующий конструктор
	Applicant(const Applicant& applicant);

	// деструктор
	~Applicant()
	{
		delete[] surname_;
		delete[] name_;
		delete[] patronymic_;
		delete[] buf_;
	} // ~Applicant 

	// аксессоры для работы с полями класса
	char* getSurname() const { return surname_; }
	void  setSurname(const char* surname);
	
	char* getName() const { return name_; }
	void  setName(const char* name);

	char* getPatronymic() const { return patronymic_; }
	void  setPatronymic(const char* patronymic);

	int  getFamilyMembers() const { return familyMembers_; }
	void setFamilyMembers(const int familyMembers);

	double getArea() const { return area_; }
	void   setArea(const double area);

	int  getRooms() const { return rooms_; }
	void setRooms(const int rooms);

	Date getAcceptDate() const { return acceptDate_;  }
	void setAcceptDate(const Date& acceptDate);

	// вывод строкового представления
	const char* toString() const;


	// перегрузка операций

	bool operator==(const Applicant& applicant) const;

	// присваивание
	Applicant& operator=(const Applicant& applicant);

	

	static ostream& showHeader(ostream& os) {

		os  << "\n\t+——————————————————————————+—————————————————————————+—————————————————————————+—————————————+——————————+————————————+—————————————————+"
			<< "\n\t|Фамилия                   |Имя                      |Отчество                 | Кол. членов | Площадь  | Количество | Дата постановки |"//17
			<< "\n\t|                          |                         |                         |    семьи    | квартиры |   комнат   |     на учет     |"//17
			<< "\n\t+——————————————————————————+—————————————————————————+—————————————————————————+—————————————+——————————+————————————+—————————————————+";

		return os;

	}

	static ostream& showFooter(ostream& os) {

		os << "\n\t+——————————————————————————+—————————————————————————+—————————————————————————+—————————————+——————————+————————————+—————————————————+\n";

		return os;




	}

	friend ostream& operator<<(ostream& os, const Applicant& applicant)
	{

		os << endl << "\t| " << left << setw(25) << applicant.surname_
			<< "|" << setw(25) << applicant.name_
			<< "|" << setw(25) << applicant.patronymic_

			<< "|" << right << setprecision(2) << setw(13) << applicant.familyMembers_
			<< "|" << setw(10) << applicant.area_
			<< "|" << setw(12) << applicant.rooms_
			<< "|" << setw(17) << applicant.acceptDate_ << "|";

		return os;
	} // operator<<
};

