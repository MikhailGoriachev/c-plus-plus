// Структруры в языке C: это новый тип данных. 
// Это тип данных, определяемый пользователем
//
// Составной тип данных, каждая ячейка которого может иметь
// собственный тип, собственное имя.
// Доступ к таким ячейкам (полям) по имени
// Объявление структуры (не занимает памяти!!! не генерируется машинный код!!):
// struct ИМЯ_ТИПА_ТЭГ {
//     тип1 имя1;
//     тип2 имя2;
//     ...
//     типN имяN;
// };
//
// Определение структурной переменной или константы приводит к выделению
// памяти
// ИМЯ_ТИПА_ТЕГ имяПеременной1, ..., имяПеременнойN; 
#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "head.h"

int main()
{
    init(L"Домашнее задание на 19.05.2021");
	
    // структуры в WinAPI
    setColor(MAGENTA_ON_WHITE);
    cls();                           // очистка экрана
    setCursorVisible(false);    // отключение курсора

	// gotoXY() - позиционирование курсора по окну консоли
    setColor(WHITE_ON_MAGENTA);
    gotoXY(50, 11); cout << setw(20) << " ";
    gotoXY(50, 12); cout << "     Home Work      ";
    gotoXY(50, 13); cout << setw(20) << " ";
    Sleep(5000);

    gotoXY(0, 23);
    setCursorVisible(true);
    
    setColor(GRAY_ON_LTBLACK);
    cls();

	cout << "\n\n";

    while (true)
    {
        try
        {
            menu();

            return 0;
        }
        catch (const exception& ex)
        {
            cls();

            setColor(errColor);

            cout << ex.what() << endl;

            setColor(mainColor);
            getKey();

            continue;
        }
    }
} // main