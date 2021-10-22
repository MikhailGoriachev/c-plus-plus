#pragma once
#include "pch.h"

class MenuItem
{
public:
    static const int MAX_ITEM_TEXT = 90;
    
    char *text;       // текст пункта
    bool current;     // признак текущего пункта
    int  command;     // код команды, назначенной пункту меню

    explicit MenuItem():text(), current(), command() { }
    explicit MenuItem(const char *text, int command):
       text(), current(), command(command)
    {
        this->text = new char[MAX_ITEM_TEXT];
        strcpy(this->text, text);
    }    
    
    MenuItem(const MenuItem &menuItem):
       text(), current(menuItem.current), command(menuItem.command)
    {
        this->text = new char[MAX_ITEM_TEXT];
        strcpy(this->text, menuItem.text);
    }

    ~MenuItem() { delete[] text; }
};