#pragma once
class Goods
{
    int    code_;    // код товара
    char   *name_;   // наименование товара 
    double price_;   // цена единицы товара
    int    amount_;  // количество товара

public:
    static const int MAX_NAME = 71;

	#pragma region Конструкторы и деструктор
    // по умолчанию
    Goods(): 
        code_(), name_(new char[MAX_NAME]), price_(), amount_()
    {
        memset(name_, 0, MAX_NAME);
    } // Goods

    // инициирующий, с параметрами
    Goods(int code, const char *name, double price, int amount):
        name_(new char[MAX_NAME])
    {
        setCode(code);
        setName(name);
        setPrice(price);
        setAmount(amount);
    } // Goods

    // копирующий конструктор
    Goods(const Goods &goods):
        code_(goods.code_), name_(new char[MAX_NAME]), 
        price_(goods.price_), amount_(goods.amount_)
    {
        memset(name_, 0, MAX_NAME);
        strcpy(name_, goods.name_);
    } // Goods

    // деструктор
    ~Goods()
    {
        delete[] name_;    
    } // ~Goods
	#pragma endregion

	// геттеры и сеттеры
    int    getCode()   const { return code_; }
    char   *getName()  const { return name_; }
    double getPrice()  const { return price_; }
    int    getAmount() const { return amount_; }

    void setCode(int code) { code_ = code; }
    void setName(const char *name);
    void setPrice(double price);
    void setAmount(int amount);

    // методы вычисления стоимости товара
    double summa() const { return amount_ * price_; }

    // перегруженные операторы
    Goods &operator=(const Goods &goods);
    friend ostream &operator<<(ostream &os, const Goods &goods);
};



