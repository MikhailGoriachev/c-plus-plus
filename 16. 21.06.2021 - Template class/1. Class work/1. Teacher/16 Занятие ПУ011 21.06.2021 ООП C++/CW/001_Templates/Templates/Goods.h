#pragma once
class Goods
{
    int    code_;    // ��� ������
    char   *name_;   // ������������ ������ 
    double price_;   // ���� ������� ������
    int    amount_;  // ���������� ������

public:
    static const int MAX_NAME = 71;

	#pragma region ������������ � ����������
    // �� ���������
    Goods(): 
        code_(), name_(new char[MAX_NAME]), price_(), amount_()
    {
        memset(name_, 0, MAX_NAME);
    } // Goods

    // ������������, � �����������
    Goods(int code, const char *name, double price, int amount):
        name_(new char[MAX_NAME])
    {
        setCode(code);
        setName(name);
        setPrice(price);
        setAmount(amount);
    } // Goods

    // ���������� �����������
    Goods(const Goods &goods):
        code_(goods.code_), name_(new char[MAX_NAME]), 
        price_(goods.price_), amount_(goods.amount_)
    {
        memset(name_, 0, MAX_NAME);
        strcpy(name_, goods.name_);
    } // Goods

    // ����������
    ~Goods()
    {
        delete[] name_;    
    } // ~Goods
	#pragma endregion

	// ������� � �������
    int    getCode()   const { return code_; }
    char   *getName()  const { return name_; }
    double getPrice()  const { return price_; }
    int    getAmount() const { return amount_; }

    void setCode(int code) { code_ = code; }
    void setName(const char *name);
    void setPrice(double price);
    void setAmount(int amount);

    // ������ ���������� ��������� ������
    double summa() const { return amount_ * price_; }

    // ������������� ���������
    Goods &operator=(const Goods &goods);
    friend ostream &operator<<(ostream &os, const Goods &goods);
};



