#pragma once
#include "pch.h"

//  ласс »грушка с пол€ми дл€ хранени€:
//     Х названи€ игрушки, 
// 	   Х названи€ производител€,
//     Х веса игрушки (в г), 
//     Х возрастной категории (в годах: 3, 4, 5, ...), 
//     Х цены игрушки (в рубл€х, без копеек),
//
class Toy
{
      
public:
    // !!!! ѕричиниа падени€ приложени€ !!!!
    // ошибка в работе приложени€ была вызвана тем, что
    // константы инициировались ѕќ—Ћ≈ объ€влени€ полей
    // класса
    const int N_NAME = 71, N_BRAND = 51;

private:
    // динамические пол€ класса 
    char* name_;    // названи€ игрушки
    char* brand_;   // названи€ производител€

    double weight_; // веса игрушки
    int age_;       // возрастной категории
    int price_;     // цены игрушки

public:
    // !!!! ѕричиниа падени€ приложени€ !!!!
    // при размещении объ€влени€ констант в этом месте,
    // приложение падает - эти константы, используемые в списке
    // инициализации конструкторов инициируютс€ ѕќ—Ћ≈ выполнени€
    // списка инициализации конструктора  - т.е. пам€ть под
    // строки не выдел€лась, отсюда и падение (((
    // const int N_NAME = 71, N_BRAND = 51;

    Toy();
    Toy(const char *name, const char *brand, double weight, int age, int price);
	
	// копирующий конструктор
	// имеет особый синтаксис, вызов генерируетс€ компил€тором при
    // а) при передаче параметра по значению   void sell(Toy toy); 
    // б) при возврате объекта в return        Toy getToy() { return toy; }
    // в) при инициализации объектом           Toy toy1;    Toy toy2(toy1);
	// !!! не€вный вызов !!!
    Toy(const Toy &toy); 

    ~Toy()
    {
        delete[] name_; 
        delete[] brand_; 
    }

    // сеттеры или мутаторы
    void setName(const char *value);  // название игрушки 
    void setBrand(const char *value); // название производител€
    void setWeight(double value);     // вес игрушки
    void setAge(int value);           // возрастна€ категори€
    void setPrice(int value);         // цена игрушки

    // геттеры илм аксессоры
    char  *getName()   const {return name_;}    // название игрушки 
    char  *getBrand()  const {return brand_;}   // название производител€
    double getWeight() const {return weight_;}  // вес игрушки
    int    getAge()    const {return age_;}     // возрастна€ категори€
    int    getPrice()  const {return price_;}   // цена игрушки

    // перегруженный оператор присваивани€
    Toy &operator=(const Toy &toy);

    // перегруженна€ операци€ < дл€ определени€ игрушки с самым
    // коротким названием производител€
    bool operator<(const Toy &toy) const
    {
        return strlen(brand_) < strlen(toy.brand_);
    } // operator<

    // перегруженна€ операци€ вывода
    friend ostream &operator<<(ostream &os, const Toy &toy);

    // чтение из текстового файла в объект
    void get(FILE *f);

    // запись объекта в текстовый файл
    void put(FILE *f) const;
};

