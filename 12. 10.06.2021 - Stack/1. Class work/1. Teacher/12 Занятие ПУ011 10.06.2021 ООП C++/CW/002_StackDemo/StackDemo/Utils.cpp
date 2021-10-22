// набор полезных функций
#include "pch.h"
#include "Utils.h"
#include "Colors.h"
#include "Palette.h"

// статическая переменная - локально-глобальная переменная
// глобальная переменная, доступная только в текущем файле
// исходного кода - инкапсуляция переменной
// время жизни переменной == время жизни (работы) программы
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void init(const wchar_t *title)
{
	SetConsoleTitle(title);
	SetConsoleOutputCP(CODE_PAGE);
	SetConsoleCP(CODE_PAGE);
	srand(GetTickCount());
	cout << fixed << setprecision(5) << boolalpha;
	
	setColor(mainColor);
	cls();
} // init

// получение кода нажатой клавиши
int getKey(const char *message)
{
	cout << message;
	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

    return key;
} // getKey

// генерация случайного числа
int getRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // getRand

// модифицированный генератор, формирующий 0 
double getRand(double low, double high)
{
	double temp = low + (high - low) * rand() / RAND_MAX;
	return abs(temp) <= 1.5?0:temp;
} // getRand

// задание цвета консоли
void setColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // setColor


// вывод сообщение в верхнюю строку окна - строку навигации при исполнении задач
void showNavBarMessage(short hintColor, const char *message)
{
	// сохранить цвет консоли
	short oldColor = getColor();

	// новый цвет и позиция вывода сообщения
	setColor(hintColor);
	gotoXY(0, 0);
	
	// вывод сообщения с управлением выравниванием
	cout << setw(115) << left << message << right;
	
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
		gotoXY(x, row);
		cout << setw(width) << msg[i];
	} // for i

	// восстановить выравнивание вывода по умолчанию, цвет вывод а
	cout << right;
	setColor(oldColor);
} // showMessage

// вывод приглашения ко вводу, представления строки ввода, цвет переключается
// в заданный color
// n - ширина поля ввода
void showInputLine(const char *prompt, int n, short color)
{
	cout << prompt;
	setColor(color);

	// выводим строку выделенным цветом, возвращаем
	// курсор в начало строки, на 1 символ от начала
	for (int i = 0; i < n; ++i) cout << " ";
	for (int i = 0; i < n-1; ++i) cout << "\b";
} // showInputLine

// c применением структур WinAPI -----------------------------------------

// позиционирование курсора в заданную позицию консоли
void gotoXY(short x, short y) {
	// TODO: добавить валидацию параметров
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
// 
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
