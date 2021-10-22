#pragma once
#include "pch.h"

class Person
{
public:
    string name;    // имя
    int    age;     // возраст
    double salary;  // оклад

    Person(string name, int age, double salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    } // Person

    // для использования также в стандартном функторе plus
    Person operator+(const Person &p) const
    {
        Person result(name, age, salary + p.salary);
        return result;
    }

    // для использования также в стандартном функторе equal_to
    bool operator==(const Person &p) const
    {
        return name == p.name && age == p.age && salary == p.salary;
    }
};

