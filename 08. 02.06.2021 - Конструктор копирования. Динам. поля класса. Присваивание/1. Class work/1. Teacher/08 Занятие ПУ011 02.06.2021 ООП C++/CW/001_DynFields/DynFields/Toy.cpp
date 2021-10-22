#include "pch.h"
#include "Toy.h"


// конструктор по умолчанию
Toy::Toy():name_(new char[N_NAME]), brand_(new char[N_BRAND]),
      weight_(), age_(), price_()
{
    memset(name_, 0, N_NAME);
    memset(brand_, 0, N_BRAND);
} // Toy::Toy

// конструктор с параметрами
Toy::Toy(const char *name, const char *brand, double weight, int age, int price)
    : name_(new char[N_NAME] {0}), brand_(new char[N_BRAND] {0})
{
    // memset(name_, 0, N_NAME);
    strncpy(name_, name, N_NAME - 1);

    // memset(brand_, 0, N_BRAND);
    strncpy(brand_, brand, N_BRAND - 1);

    setWeight(weight);
    setAge(age);
    setPrice(price);
} // Toy::Toy

// копирующий конструктор
Toy::Toy(const Toy &toy):name_(new char[N_NAME]), brand_(new char[N_BRAND]),
   weight_(toy.weight_), age_(toy.age_), price_(toy.price_)
{
    memcpy(name_, toy.name_, N_NAME);   
    memcpy(brand_, toy.brand_, N_BRAND);   
} // Toy::Toy

// сеттер для названия игрушки 
void Toy::setName(const char *value)
{
    memset(name_, 0, N_NAME);
    strncpy(name_, value, N_NAME-1);
} // Toy::setName

// сеттер для названия производителя 
void Toy::setBrand(const char *value)
{
    memset(brand_, 0, N_BRAND);
    strncpy(brand_, value, N_BRAND-1);
} // Toy::setBrand

// сеттер для веса с контролем допустимости
// устанавливаемого значения, вес в граммах
void Toy::setWeight(double value)
{
    if (value < 0 || value > 5000) 
        throw exception("Toy: Недопустимый вес");
    
    weight_ = value;
} // Toy::setWeight

// сеттер для возраста с контролем допустимости
// устанавливаемого значения
void Toy::setAge(int value)
{
    if (value < 0) 
        throw exception("Toy: Недопустимая возрастная категория");
    
    age_ = value;
} // Toy::setAge

// сеттер для цены с контролем допустимости
// устанавливаемого значения
void Toy::setPrice(int value)
{
    if (value < 0) 
        throw exception("Toy: Недопустимая цена");
    
    price_ = value; 
} // Toy::setPrice

// Перегрузка операции присваивания
Toy &Toy::operator=(const Toy &toy)
{
	// защита от самоприсваивания
    if (&toy == this) return *this;

	// копирование значений динамических полей
    memcpy(name_, toy.name_, N_NAME);   
    memcpy(brand_, toy.brand_, N_BRAND);

	// копирование значений полей примитивных типов
    weight_ = toy.weight_;
    age_ = toy.age_;
    price_ = toy.price_;

    return *this;
} // Toy::operator=

// Перегрузка операции вывода
ostream &operator<<(ostream &os, const Toy &toy)
{
    os << toy.name_ << ", " << toy.brand_ << ", " << toy.age_ << "+, "
       << fixed << setprecision(3) << toy.weight_ << " г., " << toy.price_ << " руб.";
    return os;    
} // operator<<

// чтение из текстового файла в объект
void Toy::get(FILE *f)
{
    // при достижении конце файла не читаем данные
    if (feof(f)) return;

    // строковые данные читаем fgets()
    fgets(name_, N_NAME-1, f);
    name_[strlen(name_)-1] = 0;

    // строковые данные читаем fgets()
    fgets(brand_, N_BRAND-1, f);
    brand_[strlen(brand_)-1] = 0;

    // числовые данные считываем форматным вводом и учитываем
    // перевод строки после чтения последнего числа
    fscanf(f,"%lf %d %d\n", &weight_, &age_, &price_);
} // Toy::get

// запись объекта в текстовый файл
void Toy::put(FILE *f) const
{
    // каждое поле класса записываем в отдельную строку
    fprintf(f, "%s\n%s\n%lf\n%d\n%d\n", name_, brand_, weight_, age_, price_);
} // Toy::put