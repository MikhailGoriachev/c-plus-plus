#include "pch.h"
#include "Utils.h"
#include "Colors.h"

// хэндл консоли - переменная для управления консолью 
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// Подготовка приложения к работе, начальная настройка окна консоли
void Init(const wchar_t *title)
{
	// Вывод заголовка консоли
	SetConsoleTitle(title);

	// Настройка кодовых страниц для вывода, ввода
	SetConsoleOutputCP(CODE_PAGE);
	SetConsoleCP(CODE_PAGE);

	// настройка генератора случайных чисел
	srand(GetTickCount());

	// настройка формата вывода для вещественных чисел
	cout << fixed << setprecision(5);

	// установка цвета консоли
	SetColor(GRAY_ON_LTBLACK);
	system(CLEAR);
} // Init

// получение кода нажатой клавиши
int GetKey(const char *prompt)
{
	cout << prompt;

	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

    return key;
} // GetKey

// генерация случайного числа
int GetRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // GetRand

// Модификация генератора случайных чисел так, чтобы при
// генерации числа, меньшего 0.9 по модулю возвращался 0
double GetRand(double low, double high)
{
	double value = low + (high - low) * rand() / RAND_MAX;
    // приводит к падению в сеттере веса
	// if (abs(value) < 0.9) value = 0.;
	return value;
} // GetRand

// задание цвета консоли
void SetColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // SetColor

// ввод целого числа, подсказка propmt[],
// диапазон допустимых значений from и to
int GetInt(const char *prompt, int from, int to)
{
	int value;
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
	} while(value < from || value > to);

	return value;
} // GetInt

// ввод вещественного числа, подсказка propmt[],
// диапазон допустимых значений from и to
double GetDouble(const char *prompt, double from, double to)
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
	} while(value < from || value > to);

	return value;
} // GetDouble

// вывод сообщения text заданным цветом panelColor, после вывода цвет восстанавливается к basicColor
void OutText(const char *text, short panelColor, short basicColor)
{
	cout << color(panelColor) << text << color(basicColor);
} // OutText

// вывод сообщения text заданным цветом panelColor, после вывода цвет восстанавливается к basicColor
// ожидается нажатие на клавишу, возвращается код этой клавиши
int OutTextModal(const char *text, short panelColor, short basicColor)
{
	SetColor(panelColor);
	int key = GetKey(text);
	SetColor(basicColor);

	return key;
} // OutTextModal

// позиционирование курсора в заданную позицию консоли
void GotoXY(short x, short y) {
	SetConsoleCursorPosition(h, COORD{ x, y });
} // GotoXY


void CreateIntFile(const char *fileName, int n, int lo, int hi)
{
    char str[1024];

    FILE *f = fopen(fileName, "wb");
	if (!f) {
		sprintf(str, "ошибка при открытии файла %s для записи",fileName);
		throw exception(str);
	} // if

	// запись случайных чисел в файл
	for (int i = 0; i < n; i++) {
		int x = GetRand(lo, hi);
		fwrite(&x, sizeof(x), 1, f);
	} // for i

	fclose(f);
} // CreateIntFile


void ViewIntFile(const char *fileName, const char *title)
{
    char str[1024];
    cout << title;
    
	FILE *f = fopen(fileName, "rb");
	if (!f) {
		sprintf(str, "ошибка при открытии файла %s для чтения",fileName);
		throw exception(str);
	} // if

    // Определение размера файла
	fseek(f, 0, SEEK_END);
	int byteSize = ftell(f);
    fseek(f, 0, SEEK_SET);

	// чтение записей постоянной длины из файла в прямом порядке
    //             размерФайла / размерОднойЗаписи
	int nRecords = byteSize    / sizeof(int);
	for (int i = 0; i < nRecords; i++) {
        int x;
		fread(&x, sizeof(int), 1, f);
		cout << setw(7) << x;

        if ((i+1) % 10 == 0) cout << "\n";
	} // for 
	if (nRecords % 10 != 0) cout << "\n";
    fclose(f);
}

// включение или выключение курсора консоли
// mode: true  - включить курсор
//       false - выключить курсор
void SetCursorVisible(bool mode)
{
	// еще одна структура winAPI
	CONSOLE_CURSOR_INFO info;

	// получение данных в эту структуру
	GetConsoleCursorInfo(h, &info);

	info.bVisible = mode;
	SetConsoleCursorInfo(h, &info);
} // void SetCursorVisible

// собственно реализация манипулятора без параметров
ostream &tab(ostream &os)
{
	os << "\t";
	return os;
} // tab

// реализация манипулятора для оочистки экрана
ostream &cls(ostream &os)
{
    Cls();
    return os;
} // cls

// реализация манипулятора для выключения курсора
ostream &cursor_off(ostream &os)
{
    SetCursorVisible(false);
    return os;
} // cursor_off

// реализация манипулятора для включения курсора
ostream &cursor_on(ostream &os)
{
    SetCursorVisible(true);
    return os;
} // cursor_on


// собственно реализация манипулятора с параметром endlm(n)
ostream &operator<<(ostream &os, const endlm &object)
{
	for (int i=0 ; i < object.n; ++i)
		os << endl;
	return os;
} // operator<<

// собственно реализация манипулятора с параметром color(c)
ostream &operator<<(ostream &os, const color &color)
{
    SetColor(color.color_);
    return os;
} // operator<<

// собственно реализация манипулятора с параметром pos(x, y)
ostream &operator<<(ostream &os, const pos &position) {
	GotoXY(position.x, position.y);
	return os;
} // operator<<

// очистка экрана консоли
void Cls()
{
	COORD coordScreen = { 0, 0 }; // исходная позиция для курсора
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;
	// Получим число символьных ячеек в текущем буфере.

    if( !GetConsoleScreenBufferInfo( h, &csbi )) return;

    // размер окна консоли в символах
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
   
	// Заполним полностью экран пробелами - это и есть очистка
	// cCharsWritten - счетчик записанных символов
    if ( !FillConsoleOutputCharacter( h, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten ))
       return;

    // Установим соответствующие атрибуты буфера из текущих атрибутов.
    if ( !FillConsoleOutputAttribute( h, csbi.wAttributes,
       dwConSize, coordScreen, &cCharsWritten ))
       return;
    
    // Поместим курсор в начальную позицию после очистки экрана - верхний левый угол
    SetConsoleCursorPosition( h, coordScreen );
} // Cls
