#include "pch.h"
#include "Goods.h"

// установка наименования товара
void Goods::setName(const char *name)
{
    memset(name_, 0, MAX_NAME);
    strncpy(name_, name, MAX_NAME-1);
} // setName


// установка цены товара
void Goods::setPrice(double price)
{
    if (price < 0)
        throw exception("Goods: недопустимая цена товара");

    price_ = price;
} // setPrice


// установка количества товара
void Goods::setAmount(int amount)
{
    if (amount < 0)
        throw exception("Goods: недопустимое количество товара");

    amount_ = amount;
} // setAmount


// перегруженные операторы
Goods &Goods::operator=(const Goods &goods)
{
    code_ = goods.code_;
    amount_ = goods.amount_;
    price_ = goods.price_;
    setName(goods.name_);

    return *this;
} // Goods::operator=


// перегруженный оператор вывода для Goods
ostream &operator<<(ostream &os, const Goods &goods)
{
    os << fixed << setprecision(2) 
       << goods.code_ << "; " << goods.name_ 
       << "; цена ед. " << goods.price_ 
       << "; количество " << goods.amount_;  
    return os;
} // operator<<
