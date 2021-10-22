#include "App.h"
#include "pch.h"

/*
	Задача 1.
	Реализуйте класс Television, представляющий данные о телевизоре в ремонтной 
	мастерской.Приватные поля класса:
		•	производитель телевизора – char *
		•	модель телевизора – char *
		•	диагональ экрана в дюймах – double
		•	строка с описанием дефекта – char *
		•	строка с фамилией и инициалами мастера – char *
		•	строка с фамилией и инициалами владельца – char *
		•	стоимость ремонта в рублях – int
	Для класса разработайте аксессоры (геттеры и сеттеры), конструкторы (в т.ч. explicit 
	инициирующий конструктор), перегрузите операции присваивания, ввода и вывода. 
	Конструктор по умолчанию формирует пустые поля – при разработке сеттеров считайте 
	нулевые значения допустимыми.
	Создайте очередь телевизоров, ожидающих ремонта – экземпляр класса Queue<Television>,
	инициируйте очередь не менее чем 12ю экземплярами телевизоров. Закодируйте обработки:
		•	выведите очередь в консоль, с использованием итератора сохраните очередь в 
			бинарный файл с именем televisions.bin, очистите очередь, без использования 
			итератора загрузите данные из бинарного файла televisions.bin в очередь, выведите
			очередь в консоль
		•	скопировать в отдельную очередь Queue<Television> телевизоры заданного мастера. 
			Фамилию и инициалы мастера вводите с клавиатуры. Сформированную очередь сохраните 
			в бинарный файл с именем selected.bin, выведите данные из этого файла в консоль
*/

// Сохранение и загрузка данных из бинарного файла
void App::saveOnRead()
{
	cls();

	showNavBarMessage(hintColor, "Сохранение и загрузка данных из бинарного файла");

	// название файла 
	const char* nameFile = "televisions.bin";

	cputs("\n    ————————————————————————————————————————————— ИСХОДНАЯ ОЧЕРЕДЬ —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод очереди
	printQueue(queTel_);

	// вывод имени файла
	cputs("    Файл для сохранения: ", GRAY_ON_BLACK);
	cputs(nameFile, GREEN_ON_BLACK);
	cout << "\n";

	// открытие файла в режиме бинарной записи
	FILE* file = fopen(nameFile, "wb");

	// если файл открыт успешно
	if (file != nullptr)
	{
		// запись в файл
		writeQue(file, queTel_);
	}
	// если файл открыт неуспешно 
	else throw exception("App: не удалось открыть файл");

	// закрытие файла
	fclose(file);

	cputs("    Файл сохранён\n", GREEN_ON_BLACK);

	// отчистка очереди
	queTel_.clear();

	cputs("\n    ————————————————————————————————————————————— ПОСЛЕ СОХРАНЕНИЯ —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод очереди
	printQueue(queTel_);

	// загрузка из файла
	cputs("\n    ———————————————————————————————————————————— ЗАГРУЗКА ИЗ ФАЙЛА —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// открытие файла в режиме бинарного чтения
	file = fopen(nameFile, "rb");

	// если файл открыт успешно
	if (file != nullptr)
	{
		// чтение из файла
		readQue(file, queTel_);
	}
	// если файл открыт неуспешно 
	else throw exception("App: не удалось открыть файл");

	// закрытие файла
	fclose(file);

	cputs("\n    —————————————————————————————————————————————— ПОСЛЕ ЗАГРУЗКИ ——————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод очереди
	printQueue(queTel_);

}

// Сохранение очереди для одного местера в отдельный файл
void App::saveRepairer()
{
	cls();

	showNavBarMessage(hintColor, "Сохранение очереди для одного местера в отдельный файл");

	cputs("\n    ————————————————————————————————————————————— ИСХОДНАЯ ОЧЕРЕДЬ —————————————————————————————————————————————\n", YELLOW_ON_BLACK);

	// вывод очереди
	printQueue(queTel_);

	// фамилия и инициалы мастера
	char* repairer = new char[Television::REPAIRER_MAX_SIZE + 1];

	// ввод фамилии и инициалов мастера
	cputs("\n\n    Введите фамилию и инициалы мастера: ", YELLOW_ON_BLACK);
	cin.ignore(cin.rdbuf()->in_avail());

	// включение курсора
	setCursorVisible(true);

	cin.getline(repairer, Television::REPAIRER_MAX_SIZE);

	// выключение курсора
	setCursorVisible(false);

	// название файла 
	char* nameFile = new char[Television::REPAIRER_MAX_SIZE + 5];

	strcpy(nameFile, repairer);
	strcat(nameFile, ".bin");

	// вывод имени файла
	cputs("    Файл для сохранения: ", YELLOW_ON_BLACK);
	cputs(nameFile, GREEN_ON_BLACK);
	cout << "\n";

	// открытие файла в режиме бинарной записи
	FILE* file = fopen(nameFile, "wb");

	// если файл открыт удачно
	if (file != nullptr)
	{
		// результирующая очередь
		Queue<Television> result;

		// инициализация результирующей очереди
		queByRepairer(repairer, result);

		// запись в файл
		writeQue(file, result);

		// отчистка списка
		result.clear();

		// закрытие файла
		fclose(file);

		cputs("\n    ————————————————————————————————————— РЕЗУЛЬТИРУЮЩАЯ ОЧЕРЕДЬ СОХРАНЕНА —————————————————————————————————————\n", YELLOW_ON_BLACK);

		// вывод очереди
		printQueue(result);

		// загрузка из файла
		cputs("\n    ————————————————————————————————————— РЕЗУЛЬТИРУЮЩАЯ ОЧЕРЕДЬ ИЗ ФАЙЛА ——————————————————————————————————————\n", YELLOW_ON_BLACK);

		// открытие файла в режиме бинарного чтения
		file = fopen(nameFile, "rb");

		// если файл открыт успешно
		if (file != nullptr)
		{
			// чтение из файла
			readQue(file, result);
		}
		// если файл открыт неуспешно 
		else throw exception("App: не удалось открыть файл");

		// закрытие файла
		fclose(file);

		// вывод очереди
		printQueue(result);

	}
	else throw exception("App: не удалось создать файл");
		
	fclose(file);
}

// вывод данных в цвете
void App::printQueue(Queue<Television>& queue)
{
	// длина очереди
	int size = queue.getCounter();

	// итератор 
	Queue<Television>::Iterator<Television> iter(queue);

	int i = 1;

	// текущий цвет
	short cl = getColor();

	// вывод заголовка
	showHead();

	// вывод очереди поэлементно 
	for (iter.begin(); iter != iter.end(); ++iter, ++i)
	{
		// текущий элемент 
		Television tmp = *iter;

		cout << left << color(cl) << "    |     | Производитель телевизора    |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getManufactures() << color(cl) << " |\n"
			 << color(cl) << "    |     | Модель телевизора           |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getModel() << color(cl) << " |\n"
			 << color(cl) << "    |     | Диагональ экрана (дюйм)     |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getDiagonal() << color(cl) << " |\n"
			 << color(cl) << "    |  " << setw(2) << i << " | Описанием дефекта           |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getDefect() << color(cl) << " |\n"
			 << color(cl) << "    |     | Мастер                      |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getRepairer() << color(cl) << " |\n"
			 << color(cl) << "    |     | Владелец                    |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getOwner() << color(cl) << " |\n"
			 << color(cl) << "    |     | Стоимость ремонта (руб)     |  " << setw(67) << color(GREEN_ON_BLACK) << tmp.getPrice() << color(cl) << " |\n";

		// вывод низа
		showTail();
	}

	// если очередь пуста
	if (queue.isEmpty())

	{
		cout<< color(RED_ON_BLACK)
			<< "    |                                                                                                          |\n"
			<< "    |                                               ОЧЕРЕДЬ ПУСТА                                              |\n"
			<< "    |                                                                                                          |\n"
			<< color(cl);

		// вывод низа
		showTail();
	}


}

// вывод заголовка для таблицы
void App::showHead()
{
	cout<< "    +—————+—————————————————————————————+——————————————————————————————————————————————————————————————————————+\n"
		<< "    |  N  |       Характеристика        |                              Содержание                              |\n"
		<< "    +—————+—————————————————————————————+——————————————————————————————————————————————————————————————————————+\n";
}

// вывод конца таблицы
void App::showTail()
{
	cout << "    +—————+—————————————————————————————+——————————————————————————————————————————————————————————————————————+\n";
}

// запись очереди в файл
void App::writeQue(FILE* file, Queue<Television>& queue)
{
	// итератор 
	Queue<Television>::Iterator<Television> iter(queue);

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		(*iter).write(file);
	}
}

// считывание очереди из файла
void App::readQue(FILE* file, Queue<Television>& queue)
{
	// временный элемент используемый в качестве буфера
	Television tmp;
	
	while (true)
	{
		// считываение
		tmp.read(file);

		// если мы достигли конца файла
		if (feof(file))
			break;

		queue.enqueue(tmp);
	}
}

// создание очереди из исходной по мастеру 
bool App::queByRepairer(const char* repairer, Queue<Television>& result)
{
	// итератор исходной очереди
	Queue<Television>::Iterator<Television> iter(queTel_);

	for (iter.begin(); iter != iter.end(); ++iter)
	{
		Television tel = *iter;

		if (strcmp(tel.getRepairer(), repairer) == 0)
			result.enqueue(tel);
	}

	return !result.isEmpty();
}
