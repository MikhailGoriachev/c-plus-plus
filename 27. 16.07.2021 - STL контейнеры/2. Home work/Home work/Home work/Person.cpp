#include "Person.h"

// максимальный оклад 
const double Person::MAX_SALARY = 1'000'000.;

// минимальный оклад
const double Person::MIN_SALARY = 0.;

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
		<< right << color(YELLOW_ON_BLACK) << setw(10) << salary_
		<< color(cl) << " | "
		<< color(YELLOW_ON_BLACK) << setw(4) << year_
		<< color(cl) << " | "
		<< left << color(YELLOW_ON_BLACK) << setw(17) << city_  << right
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(10) << monthWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(10) << completedWorkDay_
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(12) << accrued()
		<< color(cl) << " |\n";
}

// вывод заголовка таблицы
// void Person::showHead()
// {
// 	cout << " +————+————————————+—————————————————+————————————+——————+—————————————————————+——————————————————————+——————————————+\n"
// 		<< " | N  | Табельный  |     Фамилия и   |   Оклад    | Год  |  Количество рабочих  | Количество отработан.|    Начислено |\n"
// 		<< " |    |   номер    |      инициалы   |            | пост.|     дней в месяце    |     дней в месяце    |              |\n"
// 		<< " +————+————————————+—————————————————+————————————+——————+——————————————————————+——————————————————————+——————————————+\n";
// }

// вывод заголовка таблицы
void Person::showHead()
{
	cout<< " +————+————————————+—————————————————+————————————+——————+———————————————————+————————————+————————————+——————————————+\n"
		<< " | N  | Табельный  |     Фамилия и   |   Оклад    | Год  |       Город       | Колич. раб.| Колич. отр.|  Начислено   |\n"
		<< " |    |   номер    |      инициалы   |            | пост.|     проживания    |    дней    |    дней    |              |\n"
		<< " +————+————————————+—————————————————+————————————+——————+———————————————————+————————————+————————————+——————————————+\n";
}


// вывод разделителя-разделителя для таблицы
void Person::showLine()
{
	cout << " +————+————————————+—————————————————+————————————+——————+———————————————————+————————————+————————————+——————————————+\n";
}

// вывод пустого элемента 
void Person::showEmpty()
{
	cout << " |                                                   НЕТ ДАННЫХ                                                       |\n"
		<< " +————+————————————+—————————————————+————————————+——————+———————————————————+————————————+————————————+——————————————+\n";

}

// запись в бинарный файл 
void Person::write(ofstream& ofs)
{

	// буфер для записи
	char* buf = new char[BUF_SIZE]{0};

	// запись полей
	ofs.write((const char*)(&number_), sizeof(number_));

	// копирование поля name_ в буфер для записи
	memcpy(buf, name_.c_str(), MAX_NAME_SIZE);
	ofs.write(buf,MAX_NAME_SIZE);

	// чистка буфера 
	memset(buf, 0, BUF_SIZE);

	// копирование поля city_ в буфер для записи
	memcpy(buf, city_.c_str(), MAX_NAME_SIZE);
	ofs.write(buf, MAX_CITY_SIZE);

	// запись полей
	ofs.write((const char*)(&salary_), sizeof(salary_));
	ofs.write((const char*)(&year_), sizeof(year_));
	ofs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ofs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));

	// отчистка памяти от буфера 
	delete[] buf;
}

// запись в бинарный файл 
void Person::write(fstream& fs)
{

	// буфер для записи
	char* buf = new char[BUF_SIZE] {0};

	// запись полей
	fs.write((const char*)(&number_), sizeof(number_));

	// копирование поля name_ в буфер для записи
	memcpy(buf, name_.c_str(), MAX_NAME_SIZE);
	fs.write(buf, MAX_NAME_SIZE);

	// чистка буфера 
	memset(buf, 0, BUF_SIZE);

	// копирование поля city_ в буфер для записи
	memcpy(buf, city_.c_str(), MAX_NAME_SIZE);
	fs.write(buf, MAX_CITY_SIZE);

	// запись полей
	fs.write((const char*)(&salary_), sizeof(salary_));
	fs.write((const char*)(&year_), sizeof(year_));
	fs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	fs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));

	// отчистка памяти от буфера 
	delete[] buf;
}

// чтение из бинарного файла 
void Person::read(ifstream& ifs)
{
	// буфер для чтения 
	char* buf = new char[BUF_SIZE];

	ifs.read((char*)(&number_), sizeof(number_));
	ifs.read(buf, MAX_NAME_SIZE);	// чтение в буфер
	name_ = buf;					// присваивание строки из буфера 
	ifs.read(buf, MAX_CITY_SIZE);	// чтение в буфер
	city_ = buf;					// присваивание строки из буфера 
	ifs.read((char*)(&salary_), sizeof(salary_));
	ifs.read((char*)(&year_), sizeof(year_));
	ifs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ifs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// чтение из бинарного файла 
void Person::read(fstream& fs)
{
	// буфер для чтения 
	char* buf = new char[BUF_SIZE];

	fs.read((char*)(&number_), sizeof(number_));
	fs.read(buf, MAX_NAME_SIZE);	// чтение в буфер
	name_ = buf;					// присваивание строки из буфера 
	fs.read(buf, MAX_CITY_SIZE);	// чтение в буфер
	city_ = buf;					// присваивание строки из буфера 
	fs.read((char*)(&salary_), sizeof(salary_));
	fs.read((char*)(&year_), sizeof(year_));
	fs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	fs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// чтение из текстового файла 
void Person::readText(ifstream& ifs)
{
	ifs >> number_;
	// пропуск символа перноса строки '\n'
	ifs.get();
	getline(ifs, name_);
	getline(ifs, city_);
	ifs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
}

// чтение из текстового файла 
void Person::readText(fstream& fs)
{
	fs >> number_;
	// пропуск символа перноса строки '\n'
	fs.get();
	getline(fs, name_);
	getline(fs, city_);
	fs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
}

// перегрузка операции вывода
ostream& operator<<(ostream& os, const Person& person)
{
	cout << "\tТабельный номер: " << person.number_
		<< "\n\tФамилия и инициалы: " << person.name_
		<< "\n\tГород проживания: " << person.city_
		<< "\n\tОклад: " << person.salary_
		<< "\n\tГод поступления на работу: " << person.year_
		<< "\n\tКоличество рабочих дней в месяце: " << person.monthWorkDay_
		<< "\n\tКоличество отработанных дней в месяце: " << person.completedWorkDay_ << "\n";

	return os;
}

// перегрузка операции вывода в файл
ofstream& operator<<(ofstream& ofs, const Person& person)
{
	ofs << person.number_ << "\n" 
		<< person.name_ << "\n" 
		<< person.city_ << "\n"
		<< person.salary_ << " "
		<< person.year_ << " "
		<< person.monthWorkDay_ << " "
		<< person.completedWorkDay_ << "\n";

	return ofs;
}

// перегрузка операции вывода в файл
fstream& operator<<(fstream& fs, const Person& person)
{
	fs << person.number_ << "\n"
		<< person.name_ << "\n"
		<< person.city_ << "\n"
		<< person.salary_ << " "
		<< person.year_ << " "
		<< person.monthWorkDay_ << " "
		<< person.completedWorkDay_ << "\n";

	return fs;
}