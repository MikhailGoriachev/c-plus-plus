#pragma once
#include "pch.h"

class Person
{
public:
    string name;    // ���
    int    age;     // �������
    double salary;  // �����

    Person(string name, int age, double salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    } // Person

    // ��� ������������� ����� � ����������� �������� plus
    Person operator+(const Person &p) const
    {
        Person result(name, age, salary + p.salary);
        return result;
    }

    // ��� ������������� ����� � ����������� �������� equal_to
    bool operator==(const Person &p) const
    {
        return name == p.name && age == p.age && salary == p.salary;
    }
};

