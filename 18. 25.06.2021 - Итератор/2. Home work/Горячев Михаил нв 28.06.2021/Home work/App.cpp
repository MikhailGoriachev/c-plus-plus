#include "App.h"
#include "DblList.h"
#include "Person.h"
#include "Queue.h"

//#include 

/*
		Задача 1.
	Разработайте двунаправленный итератор для двухсвязного списка – шаблонного класса 
	DblList из предыдущего задания. Продемонстрируйте работу итератора, на экземпляре 
	двусвязного списка, закрытого типом int.
	Операции итератора:
	•	begin()переход итератора на начало контейнера, возвращает 0
	•	end()переход итератора в конец контейнера, возвращает позицию, следующую за 
		последней доступной позицией
	•	*разыменование итератора, возвращает ссылку на значение, хранимое в элементе,
		на который указывает итератор
	•	++ только префиксный инкремент, переход к следующему элементу контейнера
	•	-- только префиксный декремент, переход к предыдущему элементу контейнера
	•	T get() получение значения, хранимого в элементе, на который указывает итератор,
		доступ по чтению
	•	void put(T value) запись нового значения в элемент контейнера, на который 
		указывает итератор, доступ по записи

		Задача 2.
	С использованием шаблонного класса стека с итератором проверить правильность 
	расстановки скобок в строке символов.
	Cтроки считывать из текстового файла, длина строки не превышает 80 символов 
	(не обрабатывать слишком длинные строки).В файле не менее 3х строк.
	Виды скобок: () [] {}
	Пример строк:
	( тут ( может { быть [](произвольный) текст { например }[ такой]})) - правильно
	расставлены скобки
	({)[()]} – неправильно расставлены скобки
	Выводить результаты в консоль – строка для обработки, ниже – строка с точками, 
	соответствующими символам, место обнаружения первой ошибки обозначать символом ^.

		Задача 3.
	С использованием шаблонного класса очереди с итератором реализовать очередь 
	нуждающихся в улучшении жилищных условий. Заполняйте очереди из массивов, на 
	менее 10 элементов в массиве.
	Элемент очереди должен хранить фамилию, имя и отчество претендента, количество
	членов семьи, площадь квартиры в м2, количество комнат, дату постановки на учет
	(день, месяц, год–класс Date). Очередь имеет название, хранит имя бинарного файла
	для данных.
	Реализовать дополнительно операции (при помощи итераторов):
	•	Поиск в очереди по фамилии – находим первую подходящую фамилию, остальных 
		однофамильцев игнорировать
	•	Объединение двух очередей в новую очередь. Очередников, находящихся в обеих
		очередях включать в итоговую очередь только один раз.Имя результирующей очереди
		должно быть:Объединение “очередь1” и “очередь2”.
*/


#pragma region Задача 1. Итератор

/*
	Задача 1.
	Разработайте двунаправленный итератор для двухсвязного списка – шаблонного класса
	DblList из предыдущего задания.Продемонстрируйте работу итератора, на экземпляре
	двусвязного списка, закрытого типом int.
	Операции итератора :
	•	begin()переход итератора на начало контейнера, возвращает 0
	•	end()переход итератора в конец контейнера, возвращает позицию, следующую за
	последней доступной позицией
	•* разыменование итератора, возвращает ссылку на значение, хранимое в элементе,
	на который указывает итератор
	•	++ только префиксный инкремент, переход к следующему элементу контейнера
	•	-- только префиксный декремент, переход к предыдущему элементу контейнера
	•	T get() получение значения, хранимого в элементе, на который указывает итератор,
	доступ по чтению
	•	void put(T value) запись нового значения в элемент контейнера, на который
	указывает итератор, доступ по записи
*/

// Задача 1. Итератор
void App::task1()
{
	showNavBarMessage(infoColor, "Задача 1. Итератор");

	// размер массива
	const int SIZE_ARRAY = 5;

	// заполенение списка массивом
	int arr[SIZE_ARRAY] = { 11,22,33,44,55 };

	// заполнение списка массивом
	list_.addAll(arr, SIZE_ARRAY);

	// итератор для списка list_
	DblList<int>::Iterator<int> iterator(list_);

	// текущий цвет
	short cl = getColor();

	// вывод списка
	cout << "\n         Вывод списка               : " << color(YELLOW_ON_BLACK) << list_ << "\n" 
		 << color(cl)
		 << "\n         Вывод списка через итератор: " << color(GREEN_ON_BLACK);

	// вывод списка через итератор
	printListIterator(iterator);

	// число для put()
	int n = 99;

	// проверка функций
	cout << color(cl)
		<< "\n         ++ инекремент              : " << color(GREEN_ON_BLACK) << *(++iterator) << color(cl);
	cout << "\n         -- декремент               : " << color(GREEN_ON_BLACK) << *(--iterator) << color(cl);
	cout << "\n         begin() возвращает индекс  : " << color(GREEN_ON_BLACK) << iterator.begin() << color(cl)
		 << "\n         end()   возвращает индекс  : " << color(GREEN_ON_BLACK) << iterator.end() << color(cl)
		 << "\n         * разименование            : " << color(GREEN_ON_BLACK) << *iterator << color(cl)
		 << "\n         get()                      : " << color(GREEN_ON_BLACK) << iterator.get() << color(cl)
		 << "\n         ставим значение через put(): значение " << color(YELLOW_ON_BLACK) << n << color(cl)
		 << "\n         список до put()            : " << color(GREEN_ON_BLACK) << list_ << color(cl);
	
	// put()
	iterator.put(n);

	cout << "\n         список после put()         : " << color(GREEN_ON_BLACK) << list_ << "\n\n\n" << color(cl);

	getKey();
}

// вывод списка через итератор
void App::printListIterator(DblList<int>::Iterator<int> iterator)
{
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		cout << *iterator << " ";
	}
}

#pragma endregion 

#pragma region Задача 2. Проверка строки на корректность

/*
			Задача 2.
	С использованием шаблонного класса стека с итератором проверить правильность 
	расстановки скобок в строке символов.
	Cтроки считывать из текстового файла, длина строки не превышает 80 символов 
	(не обрабатывать слишком длинные строки).В файле не менее 3х строк.
	Виды скобок: () [] {}
	Пример строк:
	( тут ( может { быть [](произвольный) текст { например }[ такой]})) - правильно
	расставлены скобки
	({)[()]} – неправильно расставлены скобки
	Выводить результаты в консоль – строка для обработки, ниже – строка с точками, 
	соответствующими символам, место обнаружения первой ошибки обозначать символом ^.
*/

// Задача 2. Проверка строки на корректность
void App::task2()
{
	cls();

	short cl = getColor();

	showNavBarMessage(infoColor, "Задача 2. Проверка строки на корректность");

	// имя файла
	char* fileName = new char[_MAX_FNAME + 1]{"test.txt"};

	// ввод имени файла 
	// cout << "\t|        Введите имя файла: ";
	// cin.ignore(cin.rdbuf()->in_avail());
	// cin.getline(fileName, _MAX_FNAME);

	stringstream oss;
	oss << "\n\t\t******  " << "Имя файла: " << fileName << "  ******" << "\n";

	cputs(oss.str().c_str(), CYAN_ON_BLACK);

	// открытие файла в режиме чтенея
	FILE* file = fopen(fileName, "r");

	// если файл открыт неудачно
	if (file == nullptr)
	{
		// строка
		stringstream oss;

		oss << "App: не удалось открыть файл" << fileName;

		throw exception(oss.str().c_str());
	}

	// считывание файла и проверка строк по условию
	scanFile(file);

	// отчистка памяти
	delete[] fileName;

	cout << "\n\n\n";

	getKey();
}

// открытие файла и считавание содержимого в массив
void App::scanFile(FILE* file)
{
	// размер буфера для строки
	const int BUFFER_SIZE = 401;

	// буфер для файла 
	char* buffer = new char[BUFFER_SIZE];

	// максимальная длина строки
	const int MAX_SIZE_STR = 80;

	// позиция ошибки в строке
	int errPosition;

	// текущий цвет консоли
	short cl = getColor();

	// номер строки 
	int numStr = 0;

	// проверка файла на пустоту
	
	// установка указателя в конец файла 
	fseek(file, 0, SEEK_END);

	// если длина файла равна нулю
	if (ftell(file) == 0)
		throw exception("ФАЙЛ ПУСТ!");

	// установка указателя в начало файла 
	fseek(file, 0, SEEK_SET);

	// считывание и проверка файла
	while (!feof(file))
	{
		numStr++;

		// отчистка буфера
		memset(buffer, 0, BUFFER_SIZE - 1);

		// считывание строки в буфер
		fgets(buffer, BUFFER_SIZE, file);

		// если длина строки больше 80
		if (strlen(buffer) > 80)
		{
			//cout << "\n" << buffer;

			cout << "\n" << setw(3) << color(RED_ON_BLACK) << numStr << " | " << buffer
				 << color(errColor) << (buffer[strlen(buffer) - 1] == '\n' ? "\t" : "\n\t")
				<< "App: Строка не обработана, так как длиннее 80 символов!" << color(cl);
			continue;
		}

		// анализация строки по условию задания
		errPosition = searchErrorStr(buffer, BUFFER_SIZE - 1);

		// вывод строки в цвете с подсветкой ошибок
		printStrColor(buffer, errPosition, numStr);
	}

	// закрытие файла
	fclose(file);

	// отчистка памяти
	delete[] buffer;
}

// анализация строки по условию задания
int App::searchErrorStr(char* buffer, int sizeStr)
{
	// стек для скобок и их индекса
	Stack<BracketPosition> stackBracket;

	// длина строки со скобками
	const int SIZE_BRACKET = 6;

	// строка со скобками 
	char cblBrackets[SIZE_BRACKET + 1] = { '(', ')', '[',']', '{', '}', '\0'};

	// новый элемент структуры 
	BracketPosition newPos;

	for (int i = 0; i < sizeStr; i++)
	{
		// текущий символ
		char tmp = buffer[i];

		// индекс скобки в массиве скобок
		int indexCymbol = strChrIndex(cblBrackets, tmp);

		// если это скобка
		if (indexCymbol != -1)
		{
			// если то закрывающая скобка то её индекс нечётный
			if ((indexCymbol & 1) == 1)
			{
				// если при этом стек со скобками пуст или если индекс скобки
				// лежащей в стеке не является на один меньше индекса закрывающей
				if ((stackBracket.isEmpty() || strChrIndex(cblBrackets, stackBracket.peek().bracket) != indexCymbol - 1))
				{
					return i;
				}

				// убираем скобку с вершины стека
				stackBracket.pop();
			}

			// если это открывающая скобка
			else
			{
				// установка значений
				newPos.bracket = tmp;
				newPos.position = i;

				stackBracket.push(newPos);
			}
		}
	}

	// если стек остался не пуст
	if (!stackBracket.isEmpty())
		return stackBracket.peek().position;

	// если ошибок не найдено 
	return -1;
}

// вывод строки в цвете с подсветкой ошибок
void App::printStrColor(char* str, int errorPosition, int numberStr)
{
	// длина строки со скобками
	const int SIZE_BRACKET = 6;

	// строка со скобками 
	char cblBrackets[SIZE_BRACKET] = { '(', ')', '[',']', '{', '}' };

	// поток ввода вывода
	// stringstream oss;

	// длина строки
	int size = strlen(str);

	// текущий цвет
	short cl = getColor();

	// вывод номера строки, если позиция ошибки -1, то голубым цветом, а иначе красным
	cout << "\n" << setw(3) << color(errorPosition == -1 ? CYAN_ON_BLACK : RED_ON_BLACK) << numberStr << " | " << color(cl);

	for (int i = 0; i < size; i++)
	{
		// если сивол является скобкой
		if (strChrIndex(cblBrackets, str[i]) != -1)
		{
			// если это скобка ошибки 
			if (i == errorPosition)
				cout << color(RED_ON_BLACK);
			else
				cout << color(GREEN_ON_BLACK);

			cout << str[i] << color(cl);

			continue;
		}

		cout << str[i];
	}

	// если последний символ строки не является символом переноса '\n'
	if (str[size - 1] != '\n')
		cout << "\n";

	// вывод символа '|', если позиция ошибки -1, то голубым цветом, а иначе красным
	cout << color(errorPosition == -1 ? CYAN_ON_BLACK : RED_ON_BLACK) << "    | " << color(cl);

	// вывод знака ^ под ошибочным местом
	for (int i = 0; i < size; i++)
	{
		// если сивол является скобкой
		if (strChrIndex(cblBrackets, str[i]) != -1)
		{
			// если это скобка ошибки 
			if (i == errorPosition)
				cout << color(RED_ON_BLACK) << "^";
			else
				cout << color(GREEN_ON_BLACK) << "*";

			cout << color(cl);

			continue;
		}

		cout << " ";

	}
}

// индекс найденного символа в строке
int App::strChrIndex(char* str, char value)
{
	// указатель на найденный символ в проверочной строке
	char* point = strchr(str, value);

	int size = strlen(str);

	// если символ не найден
	if (point == nullptr)
		return -1;

	// индекс символа в строке
	int indexBracket = point - str;

	// если индекс 
	return indexBracket == size ? -1 : indexBracket;
}
#pragma endregion

#pragma region Задача 3. Очередь нуждающихся в улучшении жилищных условий

/*
			Задача 3.
	С использованием шаблонного класса очереди с итератором реализовать очередь 
	нуждающихся в улучшении жилищных условий. Заполняйте очереди из массивов, не 
	менее 10 элементов в массиве.
	Элемент очереди должен хранить фамилию, имя и отчество претендента, количество
	членов семьи, площадь квартиры в м2, количество комнат, дату постановки на учет
	(день, месяц, год–класс Date). Очередь имеет название, хранит имя бинарного файла
	для данных.
	Реализовать дополнительно операции (при помощи итераторов):
	•	Поиск в очереди по фамилии – находим первую подходящую фамилию, остальных 
		однофамильцев игнорировать
	•	Объединение двух очередей в новую очередь. Очередников, находящихся в обеих
		очередях включать в итоговую очередь только один раз.Имя результирующей очереди
		должно быть:Объединение “очередь1” и “очередь2”.
*/

// Задача 3. Очередь нуждающихся в улучшении жилищных условий
void App::task3()
{
	showNavBarMessage(infoColor, "Задача 3. Очередь нуждающихся в улучшении жилищных условий");

	// длина массива
	const int size = 10;

	// массив для заполнения первой очереди
	Person personsOne[size]{
		Person("Крылов", "Владислав", "Даниилович", 3, getRand(68., 82.), 3, Date(15, 12, 2003)),
		Person("Евдокимов", "Августин", "Никитевич", 1, getRand(36., 42.), 2, Date(6, 4, 2010)),
		Person("Алексеев", "Дмитрий", "Денисович", 2, getRand(54., 62.), 3, Date(30, 5, 2012)),
		Person("Рябов", "Клемент", "Константинович", 3, getRand(68., 82.), 5, Date(28, 2, 2021)),
		Person("Лыткин", "Бронислав", "Аркадьевич", 2, getRand(54., 62.), 4, Date(29, 2, 2016)),
		Person("Григорьев", "Ираклий", "Натанович", 1, getRand(36., 42.), 1, Date(3, 1, 1999)),
		Person("Максимова", "Ева", "Максовна", 1, getRand(36., 42.), 3, Date(25, 6, 2001)),
		Person("Карпов", "Любомир", "Артёмович", 2, getRand(54., 62.), 4, Date(23, 7, 2006)),
		Person("Жданов", "Нисон", "Русланович", 1, getRand(36., 42.), 3, Date(18, 3, 2004)),
		Person("Доронина ", "Роза", "Аристарховна", 2, getRand(54., 62.), 2, Date(17, 5, 2002))
	};

	// массив для заполнения второй очереди
	Person personsTwo[size]{
		Person("Овчинникова", "Розалина", "Максимовна", 1, getRand(36., 42.), 3, Date(3, 7, 2005)),
		Person("Корнилов", "Панкратий", "Павлович", 3, getRand(68., 82.), 2, Date(7, 4, 2004)),
		Person("Сысоева", "Габи", "Ефимовна", 1, getRand(36., 42.), 3, Date(8, 1, 2000)),
		Person("Блинов", "Витольд", "Данилович", 2, getRand(54., 62.), 5, Date(11, 2, 2007)),
		Person("Белоусова", "Раиса", "Даниловна", 2, getRand(54., 62.), 4, Date(17, 12, 2009)),
		Person("Григорьев", "Ираклий", "Натанович", 2, getRand(54., 62.), 1, Date(1, 6, 2004)),
		Person("Тимофеева", "Магдалина", "Игнатьевна", 1, getRand(36., 42.), 3, Date(12, 6, 2007)),
		Person("Карпов", "Любомир", "Артёмович", 2, getRand(54., 62.), 4, Date(7, 1, 2003)),
		Person("Жданов", "Нисон", "Русланович", 1, getRand(36., 42.), 3, Date(5, 11, 2007)),
		Person("Доронина ", "Роза", "Аристарховна", 2, getRand(54., 62.), 2, Date(10, 12, 2009))
	};
	
	// итератор для первой очереди
	Queue<Person>::Iterator<Person> iteratorOne(queueOne);

	// итератор для второй очереди
	Queue<Person>::Iterator<Person> iteratorTwo(queueTwo);

	// итератор для результирующей очереди
	Queue<Person>::Iterator<Person> iteratorRes(queueResult);

	// инициализация первой очереди
	queueOne.enqueueAll(personsOne, size);
	
	// инициализация второй очереди
	queueTwo.enqueueAll(personsTwo, size);

	cputs("\n\t—————————————————————————————————————————————— ДО ПЕРЕМЕЩЕНИЯ ——————————————————————————————————————————————\n", YELLOW_ON_BLACK);
	
	// первая очередь
	cputs("\n\t\t\t\t\t\tПервая очередь: ДО ПЕРЕМЕЩЕНИЯ\n", GREEN_ON_BLACK);

	// вывод очереди
	printQueue(iteratorOne);

	cout << "\n\n\n";

	cputs("\t\t\t\t\t\tВторая очередь: ДО ПЕРЕМЕЩЕНИЯ\n", GREEN_ON_BLACK);

	// вывод очереди
	printQueue(iteratorTwo);

	cout << "\n\n\n";

	cputs("\t\t\t\t\tОбъединение “очередь1” и “очередь2”: ДО ПЕРЕМЕЩЕНИЯ\n", GREEN_ON_BLACK);

	// вывод очереди
	printQueue(iteratorRes);

	cputs("\n\t———————————————————————————————————————————— ПОСЛЕ ПЕРЕМЕЩЕНИЯ —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// перемещение дух очередей в одну через итератор
	insertQueue(queueOne, queueTwo, queueResult);

	// первая очередь
	cputs("\n\t\t\t\t\t\tПервая очередь: ПОСЛЕ ПЕРЕМЕЩЕНИЯ\n", GREEN_ON_BLACK);

	// вывод очереди
	printQueue(iteratorOne);

	cout << "\n\n\n";

	cputs("\t\t\t\t\t\tВторая очередь: ПОСЛЕ ПЕРЕМЕЩЕНИЯ\n", GREEN_ON_BLACK);

	// вывод очереди
	printQueue(iteratorTwo);

	cout << "\n\n\n";

	cputs("\t\t\t\t\tОбъединение “очередь1” и “очередь2”: ПОСЛЕ ПЕРЕМЕЩЕНИЯ\n", GREEN_ON_BLACK);

	// вывод очереди
	printQueue(iteratorRes);

	// -----------поиск в очереди по фамилии

	// фамилия для поиска
	char* surname = getSurname(queueResult);

	cputs("\n\t———————————————————————————————————————————— ПОИСК ПО ФАМИЛИИ ——————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// цвет по умолчанию
	short cl = getColor();

	// поиск заявки с нужной фамилией
	cout << color(CYAN_ON_BLACK) << "\n\tФамилия для поиска: " << color(GREEN_ON_BLACK) << surname
		<< color(CYAN_ON_BLACK) << "\n\n\t\tРезультат поиска\n\n" << color(GREEN_ON_BLACK)
		<< search(iteratorRes, surname) << "\n" << color(cl);

	// отчистка памяти
	delete[]surname;

	getKey();
}

// вывод очереди
void App::printQueue(Queue<Person>::Iterator<Person> iterator)
{
	// 		Person("Овчинникова", "Розалина", "Максимовна", 1, getRand(36., 42.), 3, Date(3, 7, 2005)),
	//       | Крылов               | Владислав            | Даниилович           |   3    | 71.64068 | 15.12.2003 |
	cout << "\t+————+——————————————————————+——————————————————————+——————————————————————+————————+——————————+————————————+\n"
		<< "\t|  N |        Фамилия       |         Имя          |       Отчество       |  Семья |  Площадь |    Дата    |\n"
		<< "\t|    |                      |                      |                      |   чел. |    м2    |   регистр. |\n"
		 << "\t+————+——————————————————————+——————————————————————+——————————————————————+————————+——————————+————————————+\n";
	if (iterator.end() == 0)
		cputs("\t|                                             ОЧЕРЕДЬ ПУСТА                                                |\n", RED_ON_BLACK);

	// номер элемента
	int i = 1;

	// вывод с помощью итератора
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		stringstream oss;

		oss << fixed;
		oss.precision(5);

		oss << "\t| " << setw(2) << i++
			<< left << " | " << setw(Person::SURNAME_MAX_SIZE-30) << (*iterator).getSurname() << " | "
			<< setw(Person::NAME_MAX_SIZE-20) << (*iterator).getName() << " | "
			<< setw(Person::PATRONYMIC_MAX_SIZE - 30) << (*iterator).getPatronymic() << " | " << right
			<< setw(6) << (*iterator).getCountFamily() << " | "
			<< setw(3) << (*iterator).getArea() << " | "
			<< setw(15) << (*iterator).getDate() << " |\n";

		cputs(oss.str().c_str(), CYAN_ON_BLACK);
	}

	cout << "\t+————+——————————————————————+——————————————————————+——————————————————————+————————+——————————+————————————+\n";
}

// перемещение дух очередей в одну через итератор
void App::insertQueue(Queue<Person>& queueOne, Queue<Person>& queueTwo, Queue<Person>& queueResult)
{
	// итератор для первой очереди
	Queue<Person>::Iterator<Person> iteratorOne(queueOne);

	// итератор для второй очереди
	Queue<Person>::Iterator<Person> iteratorTwo(queueTwo);

	// перемещение первой очереди
	for (iteratorOne.begin(); iteratorOne != iteratorOne.end(); ++iteratorOne)
	{
		// поиск текущего элемента в результирующей очереди
		if (checkQueue(queueResult, *iteratorOne))
			continue;

		// запись в результирующую очередь
		queueResult.enqueue(*iteratorOne);
	}

	// перемещение второй очереди
	for (iteratorTwo.begin(); iteratorTwo != iteratorTwo.end(); ++iteratorTwo)
	{
		// поиск текущего элемента в результирующей очереди
		if (checkQueue(queueResult, *iteratorTwo))
			continue;

		// запись в результирующую очередь
		queueResult.enqueue(*iteratorTwo);
	}

	// отчистка исходных очередей
	queueOne.clear();
	queueTwo.clear();
}

// проверка на наличие Person по ФИО в очереди
// true - элемент найден
// false - элемент НЕ найден
bool App::checkQueue(Queue<Person>& queue, Person& person)
{
	// итератор для очереди
	Queue<Person>::Iterator<Person> iterator(queue);

	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// текущий элемент
		Person select = *iterator;

		if (!strcmp(select.getSurname(), person.getSurname())
			&& !strcmp(select.getName(), person.getName())
			&& !strcmp(select.getPatronymic(), person.getPatronymic()))
			return true;
	}

	return false;
}

// случайная фамилия из результирующей очереди
char* App::getSurname(Queue<Person>::Iterator<Person> iterator)
{
	// строка для фамилии
	char* surname = new char[Person::SURNAME_MAX_SIZE + 1];

	// индекс случайного элемента
	int index = getRand(0, queueResult.getCounter() - 1);

	// установка итератора на нужную позицию
	for (iterator.begin(); iterator != index; ++iterator) {}

	// копирование строки фамилии
	strcpy(surname, (*iterator).getSurname());

	return surname;
}

// поиск в очереди по фамилии
Person App::search(Queue<Person>::Iterator<Person> iterator, char* surname)
{
	// поиск по фамилии в списке
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		// если фамилия в текущем объекте Person совпала с surname
		if (!strcmp(surname, (*iterator).getSurname()))
			return *iterator;
	}

	throw exception("App: Нет человека с такой фамилией!");
}

#pragma endregion