#pragma once
#include "pch.h"
#include "Cylinder.h"
#include "Utils.h"

// Класс-контейнер, хранящий динамический массив цилиндров
class ArrayCylinders
{
	// приватные поля
    int length_;           // размер массива
    Cylinder *cylinders_;  // массив цилиндр


public:
    ArrayCylinders():length_(10), cylinders_()
    {
        createAndFill(10, 3., 10.);
    }


    ArrayCylinders(int length)
        : length_(length), cylinders_()
    {
        createAndFill(length_, -10., 10.);
    } // ArrayCylinders

    // создание и заполнение динамического массива цилиндров
    void createAndFill(int n, double lo, double hi)
    {
        // массив динамический - создание
        // Тип *имя = new  Тип[РазмерВЭлементах];
        cylinders_ = new Cylinder[n];

        // установить значения в поля цилиндров - элементов массива
        for (int i = 0; i < n; ++i) {
            cylinders_[i].setR(getRand(lo, hi));
            cylinders_[i].setH(getRand(lo, hi));
        } // for i
    } // createAndFill

    // вывод данных о цилиндрах в консоль, title - заголовок,
	// выводимый перед таблицей
    void show(const char *title)
    {
        cout<< title << fixed << setprecision(3)
            << "\t+———————+——————————+——————————+——————————+——————————+\n"
            << "\t| N п/п |     r    |     h    |  площадь |   объем  |\n"
            << "\t+———————+——————————+——————————+——————————+——————————+\n";
             
        for (int i = 0; i < length_; ++i) {
            cout<< "\t| " << setw(5) << i
                << cylinders_[i].toString()
                << " | " << setw(8) << cylinders_[i].area()
                << " | " << setw(8) << cylinders_[i].volume() << " |\n";
        } // for i
        cout<< "\t+———————+——————————+——————————+——————————+——————————+\n";
    } // showCylinders

    // Возвращает индекс цилиндра с минимальным объемом в массиве
    int findIndexMinVolume() const {
        int imin = 0;
        double minVolume = cylinders_[imin].volume();

    	// типовой алгоритм поиска минимального значения
        for (int i = 1; i < length_; ++i) {
        	// для ускорения работы - однократно вычисляем объем цилиндра
            double volume = cylinders_[i].volume();
            if (volume < minVolume) {
                imin = i;
                minVolume = volume;
            } // if
        } // for i

        return imin;
    } // findIndexMinVolume

    // два метода доступа к элеметам массива - традиционное решение
    Cylinder at(int index) const { return cylinders_[index]; }  // чтение
    void put(int index, const Cylinder &cylinder) {             // запись
        cylinders_[index] = cylinder;
    } // put


    // перегрузка операции индексирования
    Cylinder &operator[](int index)
    {
        // просто пример дополнительной обработки
        if (index < 0) index = 0;
        if (index >= length_) index = length_ - 1;

        return cylinders_[index];
    } // operator[]

    // перегрузка операции индексирования - как-бы словарь :) 
    const char *operator[](const char *word)
    {
        if (strcmp(word, "hello") == 0) return "привет!";    
        if (strcmp(word, "hi") == 0) return "здра!";    
        if (strcmp(word, "good morning") == 0) return "доброе утро!";

    	return "моя твоя не понимай";
    } // *operator[]

    // вернуть размер массива цилиндров
    int length() const { return  length_; }
};

