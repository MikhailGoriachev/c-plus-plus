#pragma once
#include "pch.h"
#include "MenuItem.h"
#include "Utils.h"

// меню приложения
class  Menu
{
public:
    static const int MAX_LEN_TITLE = 71;

	// статический член класс, доступ ИмяКласса::имяЧлена
    static const int N_PALETTE = 4;
    static const int PAL_TITLE   = 0;
    static const int PAL_ORDINAL = 1;
    static const int PAL_CURRENT = 2;
    static const int PAL_CONSOLE = 3;

    // стандартные команды
    static const int CMD_QUIT = 100; 

private:
    char     *title;      // заголовок меню
    MenuItem *items;      // массив пунктов меню
    int      nItems;      // количество элементов массива
    short    *palette;    // палитра цветов меню
    COORD    position;    // стартовая позиция вывода меню
    int      currentItem; // индекс текущего элемента меню - для выполнения команды
    int      maxLengthItemText; // максимальная длина пункта - для формирования псевдокурсора

public:
    explicit Menu(): title(), items(), nItems(), palette(), position(COORD{0, 0}), currentItem() {  }
    explicit Menu(const char *title, MenuItem *items, int nItems, short *palette, COORD position):
       title(), items(), nItems(nItems), palette(), position(position), currentItem()
    {
        // задать заголовок меню
        this->title = new char[MAX_LEN_TITLE];
        strcpy(this->title, title);

        // задать пункты меню, определить длину самого длинного названия пункта меню
        // делаем цикл "божественным", оправдание одно - не меняем меню, поэтому
        // необходимости определять новый самый длинный пункт нет ни в одном
        // другом месте приложения
        this->items = new MenuItem[nItems];
        maxLengthItemText = -1;
        for(int i = 0; i < nItems; ++i) {
            this->items[i].command = items[i].command;
            this->items[i].current = items[i].current;

            this->items[i].text = new char[MenuItem::MAX_ITEM_TEXT];
            strcpy(this->items[i].text, items[i].text);

            int lenItem = strlen(items[i].text);
            if (lenItem > maxLengthItemText) maxLengthItemText = lenItem;
        } // for i

        // установить 0-й элемент текущим
        this->items[currentItem].current = true;

        // задать палитру меню
        this->palette = new short[N_PALETTE];
        memcpy(this->palette, palette, N_PALETTE * sizeof(short));
    } // Menu

    // вывод меню
    void Show();

    // навигация по меню, выбор команды
    int Navigate();
};
