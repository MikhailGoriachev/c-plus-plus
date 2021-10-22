#pragma once
#include "pch.h"

// ����� ������� � ������ ��� ��������:
//     � �������� �������, 
// 	   � �������� �������������,
//     � ���� ������� (� �), 
//     � ���������� ��������� (� �����: 3, 4, 5, ...), 
//     � ���� ������� (� ������, ��� ������),
//
class Toy
{
      
public:
    // !!!! �������� ������� ���������� !!!!
    // ������ � ������ ���������� ���� ������� ���, ���
    // ��������� �������������� ����� ���������� �����
    // ������
    const int N_NAME = 71, N_BRAND = 51;

private:
    // ������������ ���� ������ 
    char* name_;    // �������� �������
    char* brand_;   // �������� �������������

    double weight_; // ���� �������
    int age_;       // ���������� ���������
    int price_;     // ���� �������

public:
    // !!!! �������� ������� ���������� !!!!
    // ��� ���������� ���������� �������� � ���� �����,
    // ���������� ������ - ��� ���������, ������������ � ������
    // ������������� ������������� ������������ ����� ����������
    // ������ ������������� ������������  - �.�. ������ ���
    // ������ �� ����������, ������ � ������� (((
    // const int N_NAME = 71, N_BRAND = 51;

    Toy();
    Toy(const char *name, const char *brand, double weight, int age, int price);
	
	// ���������� �����������
	// ����� ������ ���������, ����� ������������ ������������ ���
    // �) ��� �������� ��������� �� ��������   void sell(Toy toy); 
    // �) ��� �������� ������� � return        Toy getToy() { return toy; }
    // �) ��� ������������� ��������           Toy toy1;    Toy toy2(toy1);
	// !!! ������� ����� !!!
    Toy(const Toy &toy); 

    ~Toy()
    {
        delete[] name_; 
        delete[] brand_; 
    }

    // ������� ��� ��������
    void setName(const char *value);  // �������� ������� 
    void setBrand(const char *value); // �������� �������������
    void setWeight(double value);     // ��� �������
    void setAge(int value);           // ���������� ���������
    void setPrice(int value);         // ���� �������

    // ������� ��� ���������
    char  *getName()   const {return name_;}    // �������� ������� 
    char  *getBrand()  const {return brand_;}   // �������� �������������
    double getWeight() const {return weight_;}  // ��� �������
    int    getAge()    const {return age_;}     // ���������� ���������
    int    getPrice()  const {return price_;}   // ���� �������

    // ������������� �������� ������������
    Toy &operator=(const Toy &toy);

    // ������������� �������� < ��� ����������� ������� � �����
    // �������� ��������� �������������
    bool operator<(const Toy &toy) const
    {
        return strlen(brand_) < strlen(toy.brand_);
    } // operator<

    // ������������� �������� ������
    friend ostream &operator<<(ostream &os, const Toy &toy);

    // ������ �� ���������� ����� � ������
    void get(FILE *f);

    // ������ ������� � ��������� ����
    void put(FILE *f) const;
};

