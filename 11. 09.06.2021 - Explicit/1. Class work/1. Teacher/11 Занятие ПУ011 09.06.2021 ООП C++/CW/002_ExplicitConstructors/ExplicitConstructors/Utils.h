#pragma once
#include "Colors.h"

const int MAX_SECONDS = 24 * 60 * 60;

// ���� �������������� ������
const int K_F1  = 59, K_F2  = 60, K_F3  = 61, K_F4  = 62;
const int K_F5  = 63, K_F6  = 64, K_F7  = 65, K_F8  = 66;
const int K_F9  = 67, K_F10 = 68;
const int K_UP  = 72, K_DOWN = 80, K_ENTER = 13, K_ESC = 27;

// ��������� ���������� ������� � ������ ����������
void Init(const wchar_t *title = L"��������� ����������");

// ��������� ���� ������� �������
int GetKey(const char *prompt = "\n������� ����� ������� ��� �����������. . . ");

// ��������� ���������� �����
int    GetRand(int low, int high);
double GetRand(double low, double high);

// ������� ����� �������
void SetColor(short color);
void GotoXY(short x, short y);

// ���� ������ �����
int GetInt(const char *prompt, int from, int to);

// ���� ������������� �����
double GetDouble(const char *prompt, double from = -DBL_MAX, double to = DBL_MAX);

// ����� ��������� � ������� ������
void OutText(const char *text, short panelColor = BLACK_ON_GRAY, short basicColor = GRAY_ON_LTBLACK);
int  OutTextModal(const char *text, short panelColor = BLACK_ON_GRAY, short basicColor = GRAY_ON_LTBLACK);

void CreateIntFile(const char *fileName, int n, int lo, int hi);
void ViewIntFile(const char *fileName, const char *title);

// ----------------------------------------------------------------
void SetCursorVisible(bool mode);

#pragma region ������� �������� �������������
// ������� �������� �������������
// ����������� ��� ����������
// ostream &���������������(ostream &os)
ostream &tab(ostream &os);
ostream &cls(ostream &os);
ostream &cursor_off(ostream &os);
ostream &cursor_on(ostream &os);

// ����������� � ����������
// ��������� ��� ������ �������� 
// ������� - ��������� ��� ����� � ������������ �������������
struct endlm
{
private:
	int n;

public: // TODO: �������� ������������ ���������� - ��������� ����������
	// endlm(int n) {this->n = n;}
	endlm(int n): n(n) {}

    // ��� ����������� �������� ������ ������� ���� endlm 
    // ����������� �������� ������������
	friend ostream &operator<<(ostream &os, const endlm &object);
};

struct color
{
private:
    short color_;

public:
    color(short color): color_(color) {}

    // ��� ����������� �������� ������ ������� ���� endlm 
    // ����������� �������� ������������
    friend ostream &operator<<(ostream &os, const color &color);
};


struct pos {
private:
	short x;
	short y;

public:
	pos(short x, short y) : x(x), y(y) {}

	// ��� ����������� �������� ������ ������� ���� pos 
	// ����������� �������� ������������
	friend ostream &operator<<(ostream &os, const pos &position);
};
#pragma endregion

void Cls();



