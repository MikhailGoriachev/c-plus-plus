#include "pch.h"
#include "Toy.h"


// ����������� �� ���������
Toy::Toy():name_(new char[N_NAME]), brand_(new char[N_BRAND]),
      weight_(), age_(), price_()
{
    memset(name_, 0, N_NAME);
    memset(brand_, 0, N_BRAND);
} // Toy::Toy

// ����������� � �����������
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

// ���������� �����������
Toy::Toy(const Toy &toy):name_(new char[N_NAME]), brand_(new char[N_BRAND]),
   weight_(toy.weight_), age_(toy.age_), price_(toy.price_)
{
    memcpy(name_, toy.name_, N_NAME);   
    memcpy(brand_, toy.brand_, N_BRAND);   
} // Toy::Toy

// ������ ��� �������� ������� 
void Toy::setName(const char *value)
{
    memset(name_, 0, N_NAME);
    strncpy(name_, value, N_NAME-1);
} // Toy::setName

// ������ ��� �������� ������������� 
void Toy::setBrand(const char *value)
{
    memset(brand_, 0, N_BRAND);
    strncpy(brand_, value, N_BRAND-1);
} // Toy::setBrand

// ������ ��� ���� � ��������� ������������
// ���������������� ��������, ��� � �������
void Toy::setWeight(double value)
{
    if (value < 0 || value > 5000) 
        throw exception("Toy: ������������ ���");
    
    weight_ = value;
} // Toy::setWeight

// ������ ��� �������� � ��������� ������������
// ���������������� ��������
void Toy::setAge(int value)
{
    if (value < 0) 
        throw exception("Toy: ������������ ���������� ���������");
    
    age_ = value;
} // Toy::setAge

// ������ ��� ���� � ��������� ������������
// ���������������� ��������
void Toy::setPrice(int value)
{
    if (value < 0) 
        throw exception("Toy: ������������ ����");
    
    price_ = value; 
} // Toy::setPrice

// ���������� �������� ������������
Toy &Toy::operator=(const Toy &toy)
{
	// ������ �� ����������������
    if (&toy == this) return *this;

	// ����������� �������� ������������ �����
    memcpy(name_, toy.name_, N_NAME);   
    memcpy(brand_, toy.brand_, N_BRAND);

	// ����������� �������� ����� ����������� �����
    weight_ = toy.weight_;
    age_ = toy.age_;
    price_ = toy.price_;

    return *this;
} // Toy::operator=

// ���������� �������� ������
ostream &operator<<(ostream &os, const Toy &toy)
{
    os << toy.name_ << ", " << toy.brand_ << ", " << toy.age_ << "+, "
       << fixed << setprecision(3) << toy.weight_ << " �., " << toy.price_ << " ���.";
    return os;    
} // operator<<

// ������ �� ���������� ����� � ������
void Toy::get(FILE *f)
{
    // ��� ���������� ����� ����� �� ������ ������
    if (feof(f)) return;

    // ��������� ������ ������ fgets()
    fgets(name_, N_NAME-1, f);
    name_[strlen(name_)-1] = 0;

    // ��������� ������ ������ fgets()
    fgets(brand_, N_BRAND-1, f);
    brand_[strlen(brand_)-1] = 0;

    // �������� ������ ��������� ��������� ������ � ���������
    // ������� ������ ����� ������ ���������� �����
    fscanf(f,"%lf %d %d\n", &weight_, &age_, &price_);
} // Toy::get

// ������ ������� � ��������� ����
void Toy::put(FILE *f) const
{
    // ������ ���� ������ ���������� � ��������� ������
    fprintf(f, "%s\n%s\n%lf\n%d\n%d\n", name_, brand_, weight_, age_, price_);
} // Toy::put