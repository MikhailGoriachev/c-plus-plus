#include "App.h"

/*
	Задача 1.
		Реализуйте класс Person, представляющий данные о жителе некоторого города,
		поля класса фамилия, имя, отчество (все три поля типа char *), роств 
		сантиметрах (тип double), вес в килограммах (тип double), город проживания
		(тип char *).
		Создайте список экземпляр класса двусвязного списка DblList<Person>, не 
		менее 12 узлов. Закодируйте обработки (при помощи итератора):
		•	изменить вес каждого жителя на некоторое случайное значение (для каждого
			жителя значение свое, но не более 0.5% от веса жителя)
		•	скопировать в отдельный список DblList<Person> жителей заданного города,
			название города вводить с клавиатуры

	Задача 2.
		С использованием шаблонного класса очереди с итератором реализовать очередь
		нуждающихся в улучшении жилищных условий. Заполняйте очереди из массивов, на
		менее 10 элементов в массиве.
		Элемент очереди должен хранить фамилию, имя и отчество претендента, 
		количество членов семьи, площадь квартиры в м2, количество комнат, дату 
		постановки на учет (день, месяц, год–класс Date). Очередь имеет название, 
		хранит имя бинарного файла для данных.

		Реализовать дополнительно операции (при помощи итераторов):

		•	Скопировать в двусвязный список (шаблонный класс DblList<>из предыдущих 
			занятий) все записи очерединуждающихся в улучшении жилищных условий с 
			заданным количеством комнат. Количество комнат вводить с клавиатуры
		•	Скопировать в другую очередь нуждающихся в улучшении жилищных условий 
			записи исходной очереди с заданным диапазоном площади квартиры. Диапазон 
			площадей вводить с клавиатуры
*/

#pragma region Задача 1. Данные о жителе города

/*
	Задача 1.
		Реализуйте класс Person, представляющий данные о жителе некоторого города,
		поля класса фамилия, имя, отчество (все три поля типа char *), рост в
		сантиметрах (тип double), вес в килограммах (тип double), город проживания
		(тип char *).
		Создайте список экземпляр класса двусвязного списка DblList<Person>, не
		менее 12 узлов. Закодируйте обработки (при помощи итератора):
		•	изменить вес каждого жителя на некоторое случайное значение (для каждого
			жителя значение свое, но не более 0.5% от веса жителя)
		•	скопировать в отдельный список DblList<Person> жителей заданного города,
			название города вводить с клавиатуры
*/

// Задача 1. Данные о жителе города
void App::task1()
{
	init(L"Задача 1. Данные о жителе города");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Изменить вес каждого жителя на некоторое случайное значение
		CMD_ADD_WEIGHT,
		// Скопировать в отдельный список жителей заданного города
		CMD_COPY_CITY,
	};

	// количество пунктов меню
	const int N_MENU = 3;

	MenuItem items[N_MENU] = {
		MenuItem("Изменить вес каждого жителя на некоторое случайное значение", CMD_ADD_WEIGHT),
		MenuItem("Скопировать в отдельный список жителей заданного города", CMD_COPY_CITY),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задача 1. Данные о жителе города", items, N_MENU, palette, COORD{ 5, 5 });

	// конструктор инициализирующий
	// Person(const char* surname, const char* name, const char* patronymic, double height, double weight, const char* city)

	// инициализация списка с жителями 
	// Person persons[12]
	// {
	// 	Person("Крылов", "Владислав", "Даниилович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Донецк"),
	// 	Person("Евдокимов", "Августин", "Никитевич", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Днепр"),
	// 	Person("Алексеев", "Дмитрий", "Денисович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Николаев"),
	// 	Person("Рябов", "Клемент", "Константинович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Донецк"),
	// 	Person("Лыткин", "Бронислав", "Аркадьевич", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Днепр"),
	// 	Person("Григорьев", "Ираклий", "Натанович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Запорожье"),
	// 	Person("Максимова", "Ева", "Максовна", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Николаев"),
	// 	Person("Карпов", "Любомир", "Артёмович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Запорожье"),
	// 	Person("Жданов", "Нисон", "Русланович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Донецк"),
	// 	Person("Доронина ", "Роза", "Аристарховна", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Николаев"),
	// 	Person("Овчинникова", "Розалина", "Максимовна", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Донецк"),
	// 	Person("Корнилов", "Панкратий", "Павлович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Запорожье")
	// };

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Изменить вес каждого жителя на некоторое случайное значение
			case CMD_ADD_WEIGHT:
				app.taskOneAddWeight();
				break;
				// Скопировать в отдельный список жителей заданного города
			case CMD_COPY_CITY:
				app.taskOneCopyCity();
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


// Изменить вес каждого жителя на некоторое случайное значение
void App::taskOneAddWeight()
{
	cls();

	showNavBarMessage(hintColor, "Изменить вес каждого жителя на некоторое случайное значение");

	// итератор списка 
	DblList<Person>::Iterator<Person> iterat(listPerson_);

	cputs("\n    ——————————————————————————————————————————————— ДО ИЗМЕНЕНИЯ ———————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод до изменения веса
	printDblQueue(iterat);

	// изменение веса каждого жителя на случайное значение до 0,5% от его текущего веса
	for (iterat.begin(); iterat != iterat.end(); ++iterat)
	{
		// ссылка на текущий объект Person
		Person& tmp = *iterat;

		// текущий вес 
		double weight = tmp.getWeight();

		// изменение веса не более чем на 0,5%
		tmp.setWeight(weight + getRand(0., weight * 0.005));
	}

	cputs("\n    ————————————————————————————————————————————— ПОСЛЕ ИЗМЕНЕНИЯ ——————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод после изменения веса
	printDblQueue(iterat);

	getKey();
}


// Скопировать в отдельный список жителей заданного города
void App::taskOneCopyCity()
{
	cls();

	showNavBarMessage(hintColor, "Изменить вес каждого жителя на некоторое случайное значение");

	// итератор списка 
	DblList<Person>::Iterator<Person> iterat(listPerson_);

	// результирующий список
	DblList<Person> result;

	cputs("\n    —————————————————————————————————————————————— ИСХОДНЫЙ СПИСОК —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод списка
	printDblQueue(iterat);

	// название города для копирования
	char* city = new char[Person::CITY_MAX_SIZE + 1];

	// включение курсора
	setCursorVisible(true);

	// ввод названия города
	cout << color(CYAN_ON_BLACK) << "\n\n\tВведите название города: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(city, Person::CITY_MAX_SIZE);

	// выключение курсора
	setCursorVisible(false);

	cout << "\n\n\n";

	cputs("\n    ——————————————————————————————————————————— РЕЗУЛЬТИРУЮЩИЙ СПИСОК ——————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// созджание результирующего списка
	selectionTaskOne(city, iterat, result);

	// итератор результирующего списка 
	DblList<Person>::Iterator<Person> iteratRes(result);

	// вывод списка
	printDblQueue(iteratRes);

	getKey();
}


// создание результирующего списка по названию города
// если город не найден в списке, то будет возращего false
bool App::selectionTaskOne(char* city, DblList<Person>::Iterator<Person> iterat, DblList<Person>& result)
{
	bool flag = false;

	for (iterat.begin(); iterat != iterat.end(); ++iterat)
	{
		// текущий объект
		Person& tmp = *iterat;

		// если поле города соответствует нужному
		if (strcmp(city, tmp.getCity()) == 0)
		{
			flag = true;
			result.add(tmp);
		}
	}

	return flag;
}


// вывод очереди
void App::printDblQueue(DblList<Person>::Iterator<Person> iterator)
{
	// Person(const char* surname, const char* name, const char* patronymic, double height, double weight, const char* city)
	// 	Person("Крылов", "Владислав", "Даниилович", getRand(140., Person::HEIGHT_MAX), getRand(40., Person::WEIGHT_MAX - 100), "Донецк"),
	//        |  N | Крылов               | Владислав            | Даниилович           | 172.12 | 171.64 |        Донецк        |
	cout<< " +————+——————————————————————+——————————————————————+——————————————————————+—————————+—————————+————————————————————+\n"
		<< " |  N |        Фамилия       |         Имя          |       Отчество       |   Рост  |   Вес   |        Город       |\n"
		<< " |    |                      |                      |                      |    см   |    кг   |                    |\n"
		<< " +————+——————————————————————+——————————————————————+——————————————————————+—————————+—————————+————————————————————+\n";
	if (iterator.end() == 0)
		cputs(" |                                                   ОЧЕРЕДЬ ПУСТА                                                  |\n", RED_ON_BLACK);

	// номер элемента
	int i = 1;

	// цвет по умолчанию
	short cl = getColor();

	// количество знаков после точки
	cout << fixed;
	cout.precision(2);

	// вывод с помощью итератора
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		cout << " | " << color(CYAN_ON_BLACK) << setw(2) << i++
			<< left << color(cl) << " | "
			<< setw(Person::SURNAME_MAX_SIZE - 30) << color(YELLOW_ON_BLACK) << (*iterator).getSurname()
			<< color(cl) << " | "
			<< setw(Person::NAME_MAX_SIZE - 20) << color(YELLOW_ON_BLACK) << (*iterator).getName()
			<< color(cl) << " | "
			<< setw(Person::PATRONYMIC_MAX_SIZE - 30) << color(YELLOW_ON_BLACK) << (*iterator).getPatronymic()
			<< color(cl) << " | " << right
			<< setw(7) << color(GREEN_ON_BLACK) << (*iterator).getHeight()
			<< color(cl) << " | "
			<< setw(7) << color(GREEN_ON_BLACK) << (*iterator).getWeight()
			<< color(cl) << " | "
			<< setw(18) << color(GREEN_ON_BLACK) << (*iterator).getCity()
			<< color(cl) << " |\n";
	}

	cout << " +————+——————————————————————+——————————————————————+——————————————————————+—————————+—————————+————————————————————+\n";
}

#pragma endregion

#pragma region Задача 2. Очередь нуждающихся в улучшении жилищных условий

/*
	Задача 2.
		С использованием шаблонного класса очереди с итератором реализовать очередь
		нуждающихся в улучшении жилищных условий. Заполняйте очереди из массивов, на
		менее 10 элементов в массиве.
		Элемент очереди должен хранить фамилию, имя и отчество претендента,
		количество членов семьи, площадь квартиры в м2, количество комнат, дату
		постановки на учет (день, месяц, год–класс Date). Очередь имеет название,
		хранит имя бинарного файла для данных.

		Реализовать дополнительно операции (при помощи итераторов):

		•	Скопировать в двусвязный список (шаблонный класс DblList<>из предыдущих
			занятий) все записи очереди нуждающихся в улучшении жилищных условий с
			заданным количеством комнат. Количество комнат вводить с клавиатуры
		•	Скопировать в другую очередь нуждающихся в улучшении жилищных условий
			записи исходной очереди с заданным диапазоном площади квартиры. Диапазон
			площадей вводить с клавиатуры
*/

// Задача 2. Очередь нуждающихся в улучшении жилищных условий
void App::task2()
{
	init(L"Задача 2. Очередь нуждающихся в улучшении жилищных условий");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;

	// константы для swith меню
	enum Commands {
		// Скопировать в отдельный список по заданному количеству комнат
		CMD_COPY_ROOM,
		// Скопировать в отдельный список по заданному диапазону площади
		CMD_COPY_AREA,
	};

	// количество пунктов меню
	const int N_MENU = 3;

	MenuItem items[N_MENU] = {
		MenuItem("Скопировать в отдельный список по заданному количеству комнат", CMD_COPY_ROOM),
		MenuItem("Скопировать в отдельный список по заданному диапазону площади", CMD_COPY_AREA),

		// выход из программы
		MenuItem("Выход",  Menu::CMD_QUIT)
	};

	// количество цветов 
	const int N_PALETTE = 5;

	// массив цветов
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// объект меню
	Menu mainMenu("Задача 2. Очередь нуждающихся в улучшении жилищных условий", items, N_MENU, palette, COORD{ 5, 5 });


	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// Скопировать в отдельный список всех нуждающихся с заданным количеством комнат
			case CMD_COPY_ROOM:
				app.copyByRoom();
				break;
				// Скопировать в отдельный список по заданному диапазону площади
			case CMD_COPY_AREA:
				app.copyByArea();
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


// Скопировать в отдельную очередь всех нуждающихся с заданным количеством комнат
void App::copyByRoom()
{
	cls();

	showNavBarMessage(hintColor, "Скопировать в отдельный список всех нуждающихся с заданным количеством комнат");

	// итератор для исходной очереди
	Queue<Form>::Iterator<Form> iterSource(forms_);

	// результирующая очередь
	Queue<Form> result;

	// итератор для результирующей очереди
	Queue<Form>::Iterator<Form> iterResult(result);

	cputs("\n    ————————————————————————————————————————————— ИСХОДНАЯ ОЧЕРЕДЬ —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод исходной очереди
	printQueue(iterSource);

	// диапазон
	int min, max;

	// ввод диапазона
	cputs("\n\tВведите диапазон количества комнат (мин/макс): ", CYAN_ON_BLACK);
	setCursorVisible(true);
	min = getInt("");
	max = getInt("");
	setCursorVisible(false);

	// если диапазон отрицательный или минимум больше максимума
	if (min < 0 or max < 0 or min > max)
		throw exception("App: Некорректные значения границ диапазона!");

	// копирование всех анкет по подходящему количеству комнат
	copyResultByRoom(iterSource, result, min, max);

	cputs("\n    —————————————————————————————————————————— РЕЗУЛЬТИРУЮЩАЯ ОЧЕРЕДЬ ——————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод результирующей очереди
	printQueue(iterResult);

	cout << "\n\n\n";

	getKey();
}


// копирование в результирующую очередь по количеству комнат
// возвращает false если нет рузультата
bool App::copyResultByRoom(Queue<Form>::Iterator<Form> iter, Queue<Form>& result, int min, int max)
{
	// флаг нахождения хотя бы одного соответствующего объекта
	bool flag = false;

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		// текущий объект
		Form tmp = *iter;

		// текущее количество комнат
		int countRoom = tmp.getCountRoom();

		// если количество комнат входит в диапазон
		if (countRoom >= min and countRoom <= max)
		{
			result.enqueue(tmp);
			flag = true;
		}
	}

	return flag;
}


// Скопировать в отдельную очередь по заданному диапазону площади
void App::copyByArea()
{
	cls();

	showNavBarMessage(hintColor, "Скопировать в отдельную очередь по заданному диапазону площади");

	// итератор для исходной очереди
	Queue<Form>::Iterator<Form> iterSource(forms_);

	// результирующая очередь
	Queue<Form> result;

	// итератор для результирующей очереди
	Queue<Form>::Iterator<Form> iterResult(result);

	cputs("\n    ————————————————————————————————————————————— ИСХОДНАЯ ОЧЕРЕДЬ —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод исходной очереди
	printQueue(iterSource);

	// диапазон
	double min, max;

	// ввод диапазона
	cputs("\n\tВведите диапазон площади квартиры (мин/макс): ", CYAN_ON_BLACK);
	setCursorVisible(true);
	//cin >> min >> max;
	min = getInt("");
	max = getInt("");
	setCursorVisible(false);

	// если диапазон отрицательный или минимум больше максимума
	if (min < 0 or max < 0 or min > max)
		throw exception("App: Некорректные значения границ диапазона!");

	// копирование всех анкет по подходящему площади
	copyResultByArea(iterSource, result, min, max);

	cputs("\n    —————————————————————————————————————————— РЕЗУЛЬТИРУЮЩАЯ ОЧЕРЕДЬ ——————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод результирующей очереди
	printQueue(iterResult);

	cout << "\n\n\n";

	getKey();

}


// копирование в результирующую очередь по площади
// возвращает false если нет рузультата
bool App::copyResultByArea(Queue<Form>::Iterator<Form> iter, Queue<Form>& result, double min, double max)
{
	// флаг нахождения хотя бы одного соответствующего объекта
	bool flag = false;

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		// текущий объект
		Form tmp = *iter;

		// текущая площадь 
		int area = tmp.getArea();

		// если площадь входит в диапазон
		if (area >= min and area <= max)
		{
			result.enqueue(tmp);
			flag = true;
		}
	}

	return flag;
}


// вывод очереди
void App::printQueue(Queue<Form>::Iterator<Form> iterator)
{
	// 		Person("Овчинникова", "Розалина", "Максимовна", 1, getRand(36., 42.), 3, Date(3, 7, 2005)),
	//       | Крылов               | Владислав            | Даниилович           |   3    | 71.64068 | 15.12.2003 |
	cout << "\t+————+——————————————————————+——————————————————————+——————————————————————+————————+—————————+————————————+\n"
		<< "\t|  N |        Фамилия       |         Имя          |       Отчество       |  Семья | Площадь |    Дата    |\n"
		<< "\t|    |                      |                      |                      |   чел. |   м2    |   регистр. |\n"
		<< "\t+————+——————————————————————+——————————————————————+——————————————————————+————————+—————————+————————————+\n";
	if (iterator.end() == 0)
		cputs("\t|                                             ОЧЕРЕДЬ ПУСТА                                               |\n", RED_ON_BLACK);

	// цвет по умолчанию
	short cl = getColor();

	// номер элемента
	int i = 1;

	// вывод с помощью итератора
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{

		cout << fixed;
		cout.precision(2);

		cout << "\t| " << color(CYAN_ON_BLACK) << setw(2) << i++
			<< left << color(cl) << " | " << setw(Person::SURNAME_MAX_SIZE - 30) 
			<< color(YELLOW_ON_BLACK) << (*iterator).getSurname() 
			<< color(cl) << " | "
			<< setw(Person::NAME_MAX_SIZE - 20) 
			<< color(YELLOW_ON_BLACK) << (*iterator).getName()
			<< color(cl) << " | "
			<< setw(Person::PATRONYMIC_MAX_SIZE - 30) 
			<< color(YELLOW_ON_BLACK) << (*iterator).getPatronymic()
			<< color(cl) << " | " << right
			<< setw(6) 
			<< color(GREEN_ON_BLACK) << (*iterator).getCountFamily() 
			<< color(cl) << " |   "
			<< setw(4) 
			<< color(GREEN_ON_BLACK) << (*iterator).getArea()
			<< color(cl) << " | "
			<< setw(15) 
			<< color(GREEN_ON_BLACK) << (*iterator).getDate()
			<< color(cl) << " |\n";

		// cputs(oss.str().c_str(), CYAN_ON_BLACK);
	}

	cout << "\t+————+——————————————————————+——————————————————————+——————————————————————+————————+—————————+————————————+\n";
}


#pragma endregion
