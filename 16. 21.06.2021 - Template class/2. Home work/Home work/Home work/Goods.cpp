#include "pch.h"
#include "Goods.h"

// ��������� ������������ ������
void Goods::setName(const char *name)
{
    memset(name_, 0, MAX_NAME);
    strncpy(name_, name, MAX_NAME-1);
} // setName


// ��������� ���� ������
void Goods::setPrice(double price)
{
    if (price < 0)
        throw exception("Goods: ������������ ���� ������");

    price_ = price;
} // setPrice


// ��������� ���������� ������
void Goods::setAmount(int amount)
{
    if (amount < 0)
        throw exception("Goods: ������������ ���������� ������");

    amount_ = amount;
} // setAmount


// ������������� ���������
Goods &Goods::operator=(const Goods &goods)
{
    code_ = goods.code_;
    amount_ = goods.amount_;
    price_ = goods.price_;
    setName(goods.name_);

    return *this;
} // Goods::operator=


// ������������� �������� ������ ��� Goods
ostream &operator<<(ostream &os, const Goods &goods)
{
    os << fixed << setprecision(2) 
       << goods.code_ << "; " << goods.name_ 
       << "; ���� ��. " << goods.price_ 
       << "; ���������� " << goods.amount_;  
    return os;
} // operator<<
