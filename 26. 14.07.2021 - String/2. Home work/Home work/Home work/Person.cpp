#include "Person.h"

// ģąźńčģąėüķūé īźėąä 
const double Person::MAX_SALARY = 1'000'000.;

// ģčķčģąėüķūé īźėąä
const double Person::MIN_SALARY = 0.;

// āūāīä żėåģåķņą äė’ ņąįėčöū
// ļščķčģąåņ ķīģåš ā ńļčńźå
void Person::showElem(int i) 
{
	// ņåźółčé öāåņ 
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

// āūāīä ēąćīėīāźą ņąįėčöū
// void Person::showHead()
// {
// 	cout << " +++++++++\n"
// 		<< " | N  | Ņąįåėüķūé  |     Ōąģčėč’ č   |   Īźėąä    | Ćīä  |  Źīėč÷åńņāī šąįī÷čõ  | Źīėč÷åńņāī īņšąįīņąķ.|    Ķą÷čńėåķī |\n"
// 		<< " |    |   ķīģåš    |      čķčöčąėū   |            | ļīńņ.|     äķåé ā ģåń’öå    |     äķåé ā ģåń’öå    |              |\n"
// 		<< " +++++++++\n";
// }

// āūāīä ēąćīėīāźą ņąįėčöū
void Person::showHead()
{
	cout<< " ++++++++++\n"
		<< " | N  | Ņąįåėüķūé  |     Ōąģčėč’ č   |   Īźėąä    | Ćīä  |       Ćīšīä       | Źīėč÷. šąį.| Źīėč÷. īņš.|  Ķą÷čńėåķī   |\n"
		<< " |    |   ķīģåš    |      čķčöčąėū   |            | ļīńņ.|     ļšīęčāąķč’    |    äķåé    |    äķåé    |              |\n"
		<< " ++++++++++\n";
}


// āūāīä šąēäåėčņåė’-šąēäåėčņåė’ äė’ ņąįėčöū
void Person::showLine()
{
	cout << " ++++++++++\n";
}

// āūāīä ļóńņīćī żėåģåķņą 
void Person::showEmpty()
{
	cout << " |                                                   ĶÅŅ ÄĄĶĶŪÕ                                                       |\n"
		<< " ++++++++++\n";

}

// ēąļčńü ā įčķąšķūé ōąéė 
void Person::write(ofstream& ofs)
{

	// įóōåš äė’ ēąļčńč
	char* buf = new char[BUF_SIZE]{0};

	// ēąļčńü ļīėåé
	ofs.write((const char*)(&number_), sizeof(number_));

	// źīļčšīāąķčå ļīė’ name_ ā įóōåš äė’ ēąļčńč
	memcpy(buf, name_.c_str(), MAX_NAME_SIZE);
	ofs.write(buf,MAX_NAME_SIZE);

	// ÷čńņźą įóōåšą 
	memset(buf, 0, BUF_SIZE);

	// źīļčšīāąķčå ļīė’ city_ ā įóōåš äė’ ēąļčńč
	memcpy(buf, city_.c_str(), MAX_NAME_SIZE);
	ofs.write(buf, MAX_CITY_SIZE);

	// ēąļčńü ļīėåé
	ofs.write((const char*)(&salary_), sizeof(salary_));
	ofs.write((const char*)(&year_), sizeof(year_));
	ofs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ofs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));

	// īņ÷čńņźą ļąģ’ņč īņ įóōåšą 
	delete[] buf;
}

// ēąļčńü ā įčķąšķūé ōąéė 
void Person::write(fstream& fs)
{

	// įóōåš äė’ ēąļčńč
	char* buf = new char[BUF_SIZE] {0};

	// ēąļčńü ļīėåé
	fs.write((const char*)(&number_), sizeof(number_));

	// źīļčšīāąķčå ļīė’ name_ ā įóōåš äė’ ēąļčńč
	memcpy(buf, name_.c_str(), MAX_NAME_SIZE);
	fs.write(buf, MAX_NAME_SIZE);

	// ÷čńņźą įóōåšą 
	memset(buf, 0, BUF_SIZE);

	// źīļčšīāąķčå ļīė’ city_ ā įóōåš äė’ ēąļčńč
	memcpy(buf, city_.c_str(), MAX_NAME_SIZE);
	fs.write(buf, MAX_CITY_SIZE);

	// ēąļčńü ļīėåé
	fs.write((const char*)(&salary_), sizeof(salary_));
	fs.write((const char*)(&year_), sizeof(year_));
	fs.write((const char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	fs.write((const char*)(&completedWorkDay_), sizeof(completedWorkDay_));

	// īņ÷čńņźą ļąģ’ņč īņ įóōåšą 
	delete[] buf;
}

// ÷ņåķčå čē įčķąšķīćī ōąéėą 
void Person::read(ifstream& ifs)
{
	// įóōåš äė’ ÷ņåķč’ 
	char* buf = new char[BUF_SIZE];

	ifs.read((char*)(&number_), sizeof(number_));
	ifs.read(buf, MAX_NAME_SIZE);	// ÷ņåķčå ā įóōåš
	name_ = buf;					// ļščńāąčāąķčå ńņšīźč čē įóōåšą 
	ifs.read(buf, MAX_CITY_SIZE);	// ÷ņåķčå ā įóōåš
	city_ = buf;					// ļščńāąčāąķčå ńņšīźč čē įóōåšą 
	ifs.read((char*)(&salary_), sizeof(salary_));
	ifs.read((char*)(&year_), sizeof(year_));
	ifs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	ifs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// ÷ņåķčå čē įčķąšķīćī ōąéėą 
void Person::read(fstream& fs)
{
	// įóōåš äė’ ÷ņåķč’ 
	char* buf = new char[BUF_SIZE];

	fs.read((char*)(&number_), sizeof(number_));
	fs.read(buf, MAX_NAME_SIZE);	// ÷ņåķčå ā įóōåš
	name_ = buf;					// ļščńāąčāąķčå ńņšīźč čē įóōåšą 
	fs.read(buf, MAX_CITY_SIZE);	// ÷ņåķčå ā įóōåš
	city_ = buf;					// ļščńāąčāąķčå ńņšīźč čē įóōåšą 
	fs.read((char*)(&salary_), sizeof(salary_));
	fs.read((char*)(&year_), sizeof(year_));
	fs.read((char*)(&monthWorkDay_), sizeof(monthWorkDay_));
	fs.read((char*)(&completedWorkDay_), sizeof(completedWorkDay_));
}

// ÷ņåķčå čē ņåźńņīāīćī ōąéėą 
void Person::readText(ifstream& ifs)
{
	ifs >> number_;
	// ļšīļóńź ńčģāīėą ļåšķīńą ńņšīźč '\n'
	ifs.get();
	getline(ifs, name_);
	getline(ifs, city_);
	ifs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
}

// ÷ņåķčå čē ņåźńņīāīćī ōąéėą 
void Person::readText(fstream& fs)
{
	fs >> number_;
	// ļšīļóńź ńčģāīėą ļåšķīńą ńņšīźč '\n'
	fs.get();
	getline(fs, name_);
	getline(fs, city_);
	fs >> salary_ >> year_ >> monthWorkDay_ >> completedWorkDay_;
}

// ļåšåćšóēźą īļåšąöčč āūāīäą
ostream& operator<<(ostream& os, const Person& person)
{
	cout << "\tŅąįåėüķūé ķīģåš: " << person.number_
		<< "\n\tŌąģčėč’ č čķčöčąėū: " << person.name_
		<< "\n\tĆīšīä ļšīęčāąķč’: " << person.city_
		<< "\n\tĪźėąä: " << person.salary_
		<< "\n\tĆīä ļīńņóļėåķč’ ķą šąįīņó: " << person.year_
		<< "\n\tŹīėč÷åńņāī šąįī÷čõ äķåé ā ģåń’öå: " << person.monthWorkDay_
		<< "\n\tŹīėč÷åńņāī īņšąįīņąķķūõ äķåé ā ģåń’öå: " << person.completedWorkDay_ << "\n";

	return os;
}

// ļåšåćšóēźą īļåšąöčč āūāīäą ā ōąéė
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

// ļåšåćšóēźą īļåšąöčč āūāīäą ā ōąéė
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