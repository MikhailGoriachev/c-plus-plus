#include "pch.h"
#include "MenuItem.h"
#include "menu.h"

// Вывод меню, для предотвращения мерцания не очищаем экран, каждый
// пункт выводим с использованием "псевдокурсора" равной ширины, но
// текущий пункт выделяем цветом - отсюда эффект перемещения
// псевдокурсора
void Menu::Show()
{
    // вывод заголовка с учетом левого выступа псевдокурсора в 4 позиции
    cout<< cursor_off 
        << pos(position.X + 4, position.Y) << color(palette[PAL_TITLE]) << title;
    ostringstream oss;

    for (int i = 0; i < nItems; ++i) {
        // форсирование псевдокурсора
        oss.str("");
        oss << "    " << left << setw(maxLengthItemText) << items[i].text << "    ";

        // вывод пункта меню, текущий пункт выделяем цветом
        cout<< pos(position.X, position.Y + i + 1) 
            << color(palette[items[i].current?PAL_CURRENT:PAL_ORDINAL])
            << oss.str();
    } // for i
    cout<<color(palette[PAL_CONSOLE]);
} // Menu::Show

// Навигация по меню - обработка нажатия клавиш, выбор команды
int Menu::Navigate()
{
    while(true) {
        // вывести меню
        Show();

        // ввести код клавиши
        int key = _getch();
        if (key == 0 || key == 224) key = _getch();

        // обработать клавишу
        switch (key)
        {
        case K_UP: // клавиша стрелка вверх
            items[currentItem].current = false;
            --currentItem;
            if (currentItem < 0) currentItem = nItems - 1;
            items[currentItem].current = true;
            break;

        case K_DOWN: // клавиша стрелка вниз
            items[currentItem].current = false;
            ++currentItem;
            if (currentItem >= nItems) currentItem = 0;
            items[currentItem].current = true;
            break;

        case K_ENTER: // возврат кода выбранной команды
            return items[currentItem].command; 

        case K_ESC: // возврат кода стандратной команды - выход
            return CMD_QUIT;
        } // switch
    } // while
} // Menu::Navigate
