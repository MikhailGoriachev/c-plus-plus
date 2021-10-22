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
	cout << fixed << setprecision(5) << boolalpha;

	setColor(GRAY_ON_LTBLACK);
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

// вывод сообщения text заданным цветом panelColor, после вывода цвет восстанавливается к basicColor
void outText(const char text[], short panelColor, short basicColor)
{
	setColor(panelColor);
	cout << text;
	setColor(basicColor);
} // outText

// вывод сообщения text заданным цветом panelColor, после вывода цвет восстанавливается к basicColor
// ожидается нажатие на клавишу, возвращается код этой клавиши
int outTextModal(const char text[], short panelColor, short basicColor)
{
	int key;
	setColor(panelColor);
	key = getKey(text);
	setColor(basicColor);

	return key;
} // outTextModal

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

/// вывод сообщение в верхнюю строку окна - строку навигации при исполнении задач
void showNavBarMessage(short hintColor, const char* message)
{
	// сохранить цвет консоли
	short oldColor = getColor();

	// новый цвет и позиция вывода сообщения
	setColor(hintColor);
	gotoXY(0, 0);

	// вывод сообщения с управлением выравниванием
	// 138 - ширина окна консоли
	cout << setw(121) << left << message << right;

	// восстановление цвета 
	setColor(oldColor);
} // showNavBarMessage

