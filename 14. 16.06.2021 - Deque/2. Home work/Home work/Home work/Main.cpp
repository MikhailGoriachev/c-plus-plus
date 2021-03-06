// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "Palette.h"

/*
	На основе класса Deque реализовать класс DequeChar – дек символов (тип char) на 
	динамическом массиве, размер массива задавать конструктором. По умолчанию размер – 15 символов.
		• Задание 1. Даны два непустых дека символов (char), деки заполнены русскими и латинскими буквами 
			нижнего регистра. Переместить все элементы из конца первого дека в начало второго.
		• Задание 2. Даны два непустых дека символов (char), деки заполнены русскими и латинскими буквами 
			нижнего регистра. Перемещать элементы из конца первого дека в конец второго, пока в конце
			первого дека не появится гласная буква латинского языка. Если в первом деке нет гласных 
			латинских букв, то переместить из первого дека во второй все элементы.
		• Задание 3. Дан непустой дек символов (char), дек заполнен русскими и латинскими буквами нижнего 
			регистра. Создать два новых дека, переместив с конца исходного дека в начало первого из
			них все гласные буквы, а в начало второго – все согласные.
*/

int main()
{
    init(L"Домашнее задание на 17.06.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	// константы для swith меню
	enum Commands {
		// Задание 1. Перемещение всех элементов из конца первого дека в начало второго
		CMD_TASK_ONE,
		// Задание 2. Перемещение из конца первой в конец второй очереди до гласной латинской буквы
		CMD_TASK_TWO,
		// Задание 3. Перемещение в две очереди: с гласными, с согласными
		CMD_TASK_THREE
	};

	// количество пунктов меню
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("Задание 1. Перемещение всех элементов из конца первого дека в начало второго", CMD_TASK_ONE),
		MenuItem("Задание 2. Перемещение из конца первого в конец второго дека до гласной латинской буквы", CMD_TASK_TWO),
		MenuItem("Задание 3. Перемещение в два дека: с гласными, с согласными", CMD_TASK_THREE),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Главное меню приложения", items, N_MENU, palette, COORD{ 5, 5 });
	
	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return 0;

			switch (cmd)
			{
				// Задание 1. Перемещение всех элементов из конца первого дека в начало второго
			case CMD_TASK_ONE:
				app.task1();
				break;
				// Задание 2. Перемещение из конца первого в конец второго дека до гласной латинской буквы
			case CMD_TASK_TWO:
				app.task2();
				break;
				// Задание 3. Перемещение в два дека: с гласными, с согласными
			case CMD_TASK_THREE:
				app.task3();
				break;
			}
		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			// что на самом деле происходит
			// string temp = oss.str();
			// cputs(temp.c_str(), errColor);
		} // try-catch
	}
} // main
