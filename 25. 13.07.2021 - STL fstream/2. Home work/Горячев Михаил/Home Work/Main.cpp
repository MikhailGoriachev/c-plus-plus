// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"

#include "menu.h"
#include "MenuItem.h"

#include "Palette.h"

int main()
{
	init(L"Домашнее задание на 13.07.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Заполнение списка рабочих
		CMD_FILL,
		// Генерация исключений при добавлении в список
		CMD_ADD_EX,
		// Генерация исключений при создании объекта
		CMD_CREATE_EX,
		// Вывод двусвязого списка
		CMD_PRINT_LIST,
		// Сохранение двусвязного список в текстовый файл
		CMD_SAVE_TEXT,
		// Загрузка данных из текстового файла в двусвязный список
		CMD_LOADING_TEXT,
		// Сохранение двусвязного список в бинарный файл
		CMD_SAVE_BIN,
		// Загрузка данных из бинарного файла в двусвязный список
		CMD_LOADING_BIN
	};

	// количество пунктов меню
	const int N_MENU = 9;

	MenuItem items[N_MENU] = {
		MenuItem("Заполнение списка рабочих", CMD_FILL),
		MenuItem("Генерация исключений при добавлении в список", CMD_ADD_EX),
		MenuItem("Генерация исключений при создании объекта", CMD_CREATE_EX),
		MenuItem("Вывод двусвязого списка", CMD_PRINT_LIST),
		MenuItem("Сохранение двусвязного список в текстовый файл", CMD_SAVE_TEXT),
		MenuItem("Загрузка данных из текстового файла в двусвязный список", CMD_LOADING_TEXT),
		MenuItem("Сохранение двусвязного список в бинарный файл", CMD_SAVE_BIN),
		MenuItem("Загрузка данных из бинарного файла в двусвязный список", CMD_LOADING_BIN),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Главное меню", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return 0;

			switch (cmd)
			{
				// Заполнение списка рабочих
			case CMD_FILL:
				app.fillPersons();
				break;
				// Генерация исключений при добавлении в список
			case CMD_ADD_EX:
				app.genExceptionAddList();
				break;
				// Генерация исключений при создании объекта
			case CMD_CREATE_EX:
				app.genExceptionCreate();
				break;
				// Вывод двусвязого списка
			case CMD_PRINT_LIST:
				app.printList();
				break;
				// Сохранение двусвязного список в текстовый файл
			case CMD_SAVE_TEXT:
				app.saveText();
				break;
				// Загрузка данных из текстового файла в двусвязный список
			case CMD_LOADING_TEXT:
				app.loadText();
				break;
				// Сохранение двусвязного список в бинарный файл
			case CMD_SAVE_BIN:
				app.saveBin();
				break;
				// Загрузка данных из бинарного файла в двусвязный список
			case CMD_LOADING_BIN:
				app.loadBin();
				break;
			}
		}
		catch (exception& ex) {
			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();
		} // try-catch
	}
}