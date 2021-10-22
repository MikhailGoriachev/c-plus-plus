#pragma once

#include "pch.h"
#include "Triangle.h"

// Разработайте класс Figures с приватными полями
//     • указателем на тип Triangle (из предыдущего задания) для хранения указателя 
//       на динамический массив объектов типа Triangle
//     • целочисленное поле – текущий размер динамического массива в элементах
// Разработайте ансамбль конструкторов:
//     • по умолчанию, создает пустой массив из 5 объектов Triangle, созданных 
//       конструктором по умолчанию
//     • конструктор с параметрами – статический массив объектов Triangle, размер 
//       этого массива
//     • копирующий конструктор
// Разработайте деструктор, геттер для длины массива и сеттер для установки нового 
// массива (у сеттера два параметра – массив и его длина, пересоздаем массив в классе, 
// копируем новые значения, длину). 
// Перегрузите операции: 
//     • << вывод массива треугольников, по одному в строку
//     • = присваивания
//     • ! для реверсирования массива треугольников – изменение порядка следования элементов 
//       на противоположный, операция возвращает копию измененного объекта Figures, не меняем 
//       текущий объект (в соответствии с семантикой операции) 
//     • ~ для сортировки элементов массива треугольников по возрастанию площадей, операция 
//       возвращает копию измененного объекта Figures, не меняем текущий объект (в соответствии 
//       с семантикой операции). Настоятельно рекомендуется метод быстрой сортировки, но допустимы 
//       пузырьковая сортировка, сортировка выбором или сортировка вставками
// ------------------------------------------------------------------------------------------------
// Операция & для вставки в конец массива
//     figures & Triangle(3, 6, 5, "ABG");
// 	   Figures &operator&(const Triangle &triangle);
// 	 
// Операция | для удаления элемента по индексу
//     figures | 0
// 	   Figures &operator|(int index);
// 	   Figures &operator|(char *name);  // в развитие
// 	
// Операция для вставки элемента в заданную позицию
// (со сдвигом элементов после вставленного)
//     figures(0, Triangle(3, "KLM"));
//     Figures &operator()(int index, const Triangle &triangle);	

class Figures
{
    static const int N_DEF = 5;
    
    int      length_;
    Triangle *triangles_;  

    // методы для сортировки
    void swap(int i, int j) const;
    void quickSort(int start, int end);
    int  compareByArea(const Triangle &tr1, const Triangle &tr2);

public:
    // по умолчанию создаем массив треугольников с параметрами по умолчанию
    Figures(): length_(N_DEF), triangles_(new Triangle[length_])
    {
        for (int i = 0; i < length_; i++)
            triangles_[i] = Triangle();
    } // Figures

    // Конструктор с параметрами - массивом треугольников
    Figures(Triangle *triangles, int length): 
        length_(length), triangles_(new Triangle[length_])
    {
        for (int i = 0; i < length_; i++)
            triangles_[i] = triangles[i];        
    } // Figures

    // Копирующий конструктор
    Figures(const Figures &figures):
        length_(figures.length_), triangles_(new Triangle[length_])
    {
        for (int i = 0; i < length_; i++)
            triangles_[i] = figures.triangles_[i];  
    } // Figures

    // для каждого объекта вызывается свой деструктор оператором delete
    ~Figures() { delete[] triangles_; }

    // геттеры и сеттеры
    int getLegth() const { return length_; }
    void setData(Triangle *triangles, int length)
    {  
        // новая длина массива треугольников
        // TODO: проверить длину на корректность: length > 1
        length_ = length;

        // освободить память, выделенную под массив, выделить
        // новый блок памяти
        delete[] triangles_;
        triangles_ = new Triangle[length_];

        // копировать данные из массива-источника в массив 
        // класса Figures
        for (int i = 0; i < length_; ++i)
            triangles_[i] = triangles[i];
    } // setData

    Figures &operator=(const Figures &figures);

    Triangle &operator[](int index) const;

    // добавлено 30.05.2019 - индексирование по имени треугольника
    // вернуть значение треугольника с первым 
    // найденным имененем - игнорим проблему дубликатных имен
    Triangle &operator[](char *name) const;


    // реверсирование массива треугольников - исходный 
    // массив не изменяем - реализация immutable
    Figures operator!() const;
    
    // сортировка массива треугольников по возрастанию площадей - исходный 
    // массив не изменяем - реализация immutable
    Figures operator~() const;

    // Операции, добавленные по заданию 30.05.2019
    Figures &operator&(const Triangle &triangle);
    Figures &operator|(int index);
    Figures &operator|(char *name);
    Figures &operator()(int index, const Triangle &triangle);

    friend ostream &operator<<(ostream &os, const Figures &figures);
};

