#include "pch.h"
#include "Utils.h"
#include "Colors.h"

// локальная глобальная переменная - статическая переменная
// существуе в единственном экземпляре (синглтон - singleton),
// область видимости - данный файл исходного кода
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void init(const wchar_t title[])
{
	SetConsoleTitle(title);

	SetConsoleOutputCP(CODE_PAGE);
	SetConsoleCP(CODE_PAGE);
	srand(GetTickCount());
	cout << fixed << setprecision(5);

	setColor(mainColor);
	cls();
} // init

// получение кода нажатой клавиши
int getKey(const char* prompt)
{
	cout << prompt;

	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

	return key;
} // getKey

// генерация случайного числа
int getRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // getRand

// генерация случайного вещественного числа  
double getRand(double low, double high)
{
	double x = low + (high - low) * rand() / RAND_MAX;
	// для генерации 0
	// return abs(x) < 0.8?0:x;
	return x;
} // getRand

// задание цвета консоли
void setColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // setColor

// ввод целого числа, подсказка propmt[],
// диапазон допустимых значений from и to
int getInt(const char prompt[], int from, int to)
{
	int value;
	do {
		// собственно ввод
		cout << prompt;
		cin >> value;

		// Если ввели число, выход из цикла и из функции
		if (!cin.fail()) break;

		// Если это не число - сброс состояния ошибки,
		// очиска буфера ввода
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '\n');
	} while (value < from || value > to);

	return value;
} // getInt

// ввод вещественного числа, подсказка propmt[],
// диапазон допустимых значений from и to
double getDouble(const char* prompt, double from, double to)
{
	double value;
	do {
		// собственно ввод
		cout << prompt;
		cin >> value;

		// Если ввели не число - сброс состояния ошибки,
		// очистка буфера ввода 
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail(), '\n');
			value = from - 1; // чтобы остаться в цикле
		} // if
	} while (value < from || value > to);

	return value;
} // getDouble

/// вывод сообщение в верхнюю строку окна - строку навигации при исполнении задач
void showNavBarMessage(short hintColor, const char* message)
{
	// сохранить цвет консоли
	short oldColor = getColor();

	// новый цвет и позиция вывода сообщения
	setColor(hintColor);
	gotoXY(0, 0);

	// вывод сообщения с управлением выравниванием
	// 121 - ширина окна консоли
	cout << setw(121) << left << message << right;

	// восстановление цвета 
	setColor(oldColor);
} // showNavBarMessage


// Вывод сообщения "Функция в разработке"
void showUnderConstruction(short width, short infoColor)
{
	const char* msg[] = {
		" ", // тут символ с кодом 255, без него левая вертикальная граница не совсем верикальная...
		"    [Информация]",
		"    Функция в разработке",
		" ", // тут символ с кодом 255, без него левая вертикальная граница не совсем верикальная...
		"    Нажмите любую клавишу для продолжения...",
		" ", // тут символ с кодом 255, без него левая вертикальная граница не совсем верикальная...
		" ", // тут символ с кодом 255, без него левая вертикальная граница не совсем верикальная...
		nullptr // признак конца текста
	};
	showMessage(8, 4, width, msg, infoColor);
	gotoXY(8, 30);
} // showUnderConstruction



// вывод сообщения msg в область экрана, начиная с позиции x, y
// ширина поля вывода width, цвет выводимого текста - msgColor
// вывод строк до строки, равной nullptr
void showMessage(short x, short y, short width, const char* msg[], short msgColor)
{
	// сохранить текущий цвет консоли
	short oldColor = getColor();
	setColor(msgColor);

	// вывести строки сообщения в поле шириной width символов
	// вывыод выполняем до обнаружения строки, равной nullptr 
	// строки выравнены влево для автоматического заполнения прямоугольника вывода
	cout << left;
	for (short i = 0, row = y; msg[i] != nullptr; i++, row++) {
		cout << pos(x, row) << setw(width) << msg[i];
	} // for i

	// восстановить выравнивание вывода по умолчанию, цвет вывод а
	cout << right;
	setColor(oldColor);
} // showMessage

// вывод приглашения ко вводу, представления строки ввода, цвет переключается
// в заданный color
void showInputLine(const char* prompt, int n, short color)
{
	cout << prompt;
	setColor(color);

	// выводим строку выделенным цветом, возвращаем
	// курсор в начало строки, на 1 символ от начала
	for (int i = 0; i < n; ++i) cout << " ";
	for (int i = 0; i < n - 1; ++i) cout << "\b";
} // showInputLine

// c применением структур WinAPI -----------------------------------------

// позиционирование курсора в заданную позицию консоли
void gotoXY(short x, short y) {
	SetConsoleCursorPosition(h, COORD{ x, y });
} // gotoXY

// включение или выключение курсора консоли
// mode: true  - включить курсор
//       false - выключить курсор
void setCursorVisible(bool mode)
{
	// еще одна структура winAPI
	CONSOLE_CURSOR_INFO info;

	// получение данных в эту структуру
	GetConsoleCursorInfo(h, &info);

	info.bVisible = mode;
	SetConsoleCursorInfo(h, &info);
} // void setCursorVisible

// очистка экрана консоли
void cls()
{
	COORD coordScreen = { 0, 0 }; // исходная позиция для курсора
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	// Получим число символьных ячеек в текущем буфере.

	if (!GetConsoleScreenBufferInfo(h, &csbi)) return;

	// размер окна консоли в символах
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Заполним полностью экран пробелами - это и есть очистка
	// cCharsWritten - счетчик записанных символов
	if (!FillConsoleOutputCharacter(h, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten))
		return;

	// Установим соответствующие атрибуты буфера из текущих атрибутов.
	if (!FillConsoleOutputAttribute(h, csbi.wAttributes,
		dwConSize, coordScreen, &cCharsWritten))
		return;

	// Поместим курсор в начальную позицию после очистки экрана - верхний левый угол
	SetConsoleCursorPosition(h, coordScreen);
} // cls

// вывод строки в заданном цвете
void cputs(const char* str, short color)
{
	// сохранить текущий цвет вывода 
	short oldColor = getColor();

	// установить заданный цвет вывода и вывести строку
	setColor(color);
	cout << str;

	// восстановить цвет вывода
	setColor(oldColor);
} // cputs

// вывод строки в заданных координатах окна консоли заданным цветом
void writeXY(short x, short y, const char* str, short color)
{
	// установить заданный цвет вывода и вывести строку
	// в заданную позицию экрана
	gotoXY(x, y);
	cputs(str, color);
} // writeXY

// получить текущий цвет вывода в консоль
short getColor()
{
	// системная структура - информация о буфере консоли, в т.ч. цвет 
	// выводимого текста
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	// пытемся получить данные о консоли, если не получается - вернем
	// стандартное сочетание цветов (серый на черном)
	if (!GetConsoleScreenBufferInfo(h, &csbi)) return GRAY_ON_BLACK;

	// вернуть атрибут цвета, полученный из параметров буфера консоли
	return csbi.wAttributes;
} // getColor


// -------------------------------------------

// собственно реализация манипулятора без параметров
ostream& tab(ostream& os)
{
	os << "\t";
	return os;
} // tab

ostream& cls(ostream& os)
{
	cls();
	return os;
} // cls

// реализация манипулятора для выключения курсора
ostream& cursor_off(ostream& os)
{
	setCursorVisible(false);
	return os;
} // cursor_off

// реализация манипулятора для включения курсора
ostream& cursor_on(ostream& os)
{
	setCursorVisible(true);
	return os;
} // cursor_on

// собственно реализация манипулятора с параметром endlm(n)
ostream& operator<<(ostream& os, const endlm& object)
{
	for (int i = 0; i < object.n_; ++i)
		os << endl;
	return os;
} // operator<<

// собственно реализация манипулятора с параметром color(c)
ostream& operator<<(ostream& os, const color& color)
{
	setColor(color.color_);
	return os;
} // operator<<

ostream& operator<<(ostream& os, const pos& object)
{
	SetConsoleCursorPosition(h, COORD{ object.x_, object.y_ });
	return os;
}