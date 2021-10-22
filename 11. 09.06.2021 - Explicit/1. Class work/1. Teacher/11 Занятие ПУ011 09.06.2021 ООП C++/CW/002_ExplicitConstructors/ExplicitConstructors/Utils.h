#pragma once
#include "Colors.h"

const int MAX_SECONDS = 24 * 60 * 60;

// коды функциональных клавиш
const int K_F1  = 59, K_F2  = 60, K_F3  = 61, K_F4  = 62;
const int K_F5  = 63, K_F6  = 64, K_F7  = 65, K_F8  = 66;
const int K_F9  = 67, K_F10 = 68;
const int K_UP  = 72, K_DOWN = 80, K_ENTER = 13, K_ESC = 27;

// процедура подготовки консоли к работе приложения
void Init(const wchar_t *title = L"Заголовок приложения");

// получение кода нажатой клавиши
int GetKey(const char *prompt = "\nНажмите любую клавишу для продолжения. . . ");

// генерация случайного числа
int    GetRand(int low, int high);
double GetRand(double low, double high);

// задание цвета консоли
void SetColor(short color);
void GotoXY(short x, short y);

// ввод целого числа
int GetInt(const char *prompt, int from, int to);

// ввод вещественного числа
double GetDouble(const char *prompt, double from = -DBL_MAX, double to = DBL_MAX);

// вывод сообщения в цветную панель
void OutText(const char *text, short panelColor = BLACK_ON_GRAY, short basicColor = GRAY_ON_LTBLACK);
int  OutTextModal(const char *text, short panelColor = BLACK_ON_GRAY, short basicColor = GRAY_ON_LTBLACK);

void CreateIntFile(const char *fileName, int n, int lo, int hi);
void ViewIntFile(const char *fileName, const char *title);

// ----------------------------------------------------------------
void SetCursorVisible(bool mode);

#pragma region Примеры создания манипуляторов
// Примеры создания манипуляторов
// манипулятор без параметров
// ostream &имяМанипулятора(ostream &os)
ostream &tab(ostream &os);
ostream &cls(ostream &os);
ostream &cursor_off(ostream &os);
ostream &cursor_on(ostream &os);

// манипулятор с параметром
// реализуем при помощи функтора 
// функтор - структура или класс с единственном конструктором
struct endlm
{
private:
	int n;

public: // TODO: проверка корректности параметров - валидация параметров
	// endlm(int n) {this->n = n;}
	endlm(int n): n(n) {}

    // при реализациии операции вывода объекта типа endlm 
    // выполняется действие манипулятора
	friend ostream &operator<<(ostream &os, const endlm &object);
};

struct color
{
private:
    short color_;

public:
    color(short color): color_(color) {}

    // при реализациии операции вывода объекта типа endlm 
    // выполняется действие манипулятора
    friend ostream &operator<<(ostream &os, const color &color);
};


struct pos {
private:
	short x;
	short y;

public:
	pos(short x, short y) : x(x), y(y) {}

	// при реализациии операции вывода объекта типа pos 
	// выполняется действие манипулятора
	friend ostream &operator<<(ostream &os, const pos &position);
};
#pragma endregion

void Cls();



