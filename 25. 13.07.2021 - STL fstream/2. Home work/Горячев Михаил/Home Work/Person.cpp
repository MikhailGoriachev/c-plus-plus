#include "Person.h"

// максимальный оклад 
const double Person::MAX_SALARY = 1'000'000.;

// минимальный оклад
const double Person::MIN_SALARY = 0.;

/*
	// Табельный номер, целое число, уникальное в пределах приложения unsigned int
	unsigned int number_;

	// Фамилия и инициалы – динамическое поле, char*
	char* name_;

	// Оклад, вещественное число, double
	double salary_;

	// Год поступления на работу, int
	int year_;

	// Количество рабочих дней в месяце, int
	int monthWorkDay_;

	// Количество фактически отработанных дней в месяце, int
	int completedWorkDay_;

*/

// вывод элемента для таблицы
// принимает номер в списке
void Person::showElem(int i) 
{
	// текущий цвет 
	short cl = getColor();

	cout << fixed;

	cout.precision(2);

	cout << " | "
		<< setw(2) << i
		<< " | "
		<< right << color(YELLOW_ON_BLACK) << setw(10) << number_
		<< color(cl) << " | "
		<< left << color(YELLOW_ON_BLACK) << setw(15) << name_
		<< color(cl) << " | "
		<< right<< color(YELLOW_ON_BLACK) << setw(10) << salary_
		<< color(cl) << " | "
		<< color(YELLOW_ON_BLACK) << setw(4) << year_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(20) << monthWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(20) << completedWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(12) << accrued()
		<< color(cl) << " |\n";
}

// вывод заголовка таблицы
void Person::showHead()
{
	cout << " +————+————————————+—————————————————+————————————+——————+——————————————————————+——————————————————————+——————————————+\n"
		<< " | N  | Табельный  |     Фамилия и   |   Оклад    | Год  |  Количество рабочих  | Количество отработан.|    Начислено |\n"
		<< " |    |   номер    |      инициалы   |            | пост.|     дней в месяце    |     дней в месяце    |              |\n"
		<< " +————+————————————+—————————————————+————————————+——————+——————————————————————+——————————————————————+——————————————+\n";
}

// вывод разделителя-разделителя для таблицы
void Person::showLine()
{
	cout << " +————+————————————+—————————————————+————————————+——————+——————————————————————+——————————————————————+——————————————+\n";
}

// вывод пустого элемента 
void Person::showEmpty()
{
	cout << " |                                                   НЕТ ДАННЫХ                                                       |\n"
		<< " +————————————————————————————————————————————————————————————————————————————————————————————————————————————————————+\n";

}

// запись в бинарный файл 
void Person::write(ofstream& ofs)
{
	ofs.write((const char*)(&number_), sizeof(number_));
	ofs.write(name_,MAX_NAME_SIZE);
	ofs.write((const char*)(&salary_), sizeof(salary_));
	ofs.write((const char*)(&year_), sizeof(year_));
	ofs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ofs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// чтение из бинарного файла 
void Person::read(ifstream& ifs)
{
	ifs.read((char*)(&number_), sizeof(number_));
	ifs.read(name_, MAX_NAME_SIZE);
	ifs.read((char*)(&salary_), sizeof(salary_));
	ifs.read((char*)(&year_), sizeof(year_));
	ifs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ifs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// чтение из текстового файла 
void Person::readText(ifstream& ifs)
{
	ifs >> number_;
	// пропуск символа перноса строки '\n'
	ifs.get();
	ifs.getline(name_, Person::MAX_NAME_SIZE);
	ifs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
}

// перегрузка операции вывода
ostream& operator<<(ostream& os, const Person& person)
{
	cout << "\tТабельный номер: " << person.number_
		<< "\n\tФамилия и инициалы: " << person.name_
		<< "\n\tОклад: " << person.salary_
		<< "\n\tГод поступления на работу: " << person.year_
		<< "\n\tКоличество рабочих дней в месяце: " << person.monthWorkDay_
		<< "\n\tКоличество отработанных дней в месяце: " << person.completedWorkDay_ << "\n";

	return os;
}

// перегрузка операции вывода в файл
/*ofstream& operator<<(ofstream& ofs, const Person& person)
{
	ofs << "Табельный номер: " << person.number_
		<< "\nФамилия и инициалы: " << person.name_
		<< "\nОклад: " << person.salary_
		<< " Год поступления на работу: " << person.year_
		<< " Количество рабочих дней в месяце: " << person.monthWorkDay_
		<< " Количество отработанных дней в месяце: " << person.completedWorkDay_ << "\n\n";

	return ofs;
}*/

// перегрузка операции вывода в файл
ofstream& operator<<(ofstream& ofs, const Person& person)
{
	ofs << person.number_
		<< "\n" << person.name_
		<< "\n" << person.salary_ << "\n"
		<< person.year_ << " "
		<< person.monthWorkDay_ << " "
		<< person.completedWorkDay_ << "\n";

	return ofs;
}