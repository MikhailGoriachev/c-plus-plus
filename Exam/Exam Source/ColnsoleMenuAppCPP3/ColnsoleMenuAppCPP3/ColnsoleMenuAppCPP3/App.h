#pragma once
#include "pch.h"
#include "Utils.h"

#include <algorithm>
#include <numeric>
#include <iterator>

#include <vector>

// TODO: прикладная часть - полезная работа приложения - бизнес-логика приложения
class App
{
	// Задание 1. Вектор
	vector<int> vec_;

	// Задание 1. Название бинарного файла для сохранения вектора
	string nameFileVector = "saveVector.bin";

public:

#pragma region Превью запуска приложения 

	// Превью запуска приложения
	static void preview();

	// заполнение заднего фона 
	static void fillBackground(int row, int col, short color, int time);
	
	// анимация вывода текста 
	static void outText(string message, int time, short color, int x, int y);

	// анимация полосы загрузки 
	static void loadingLine(int size, int time, int x, int y, short colorLoading = GREEN_ON_BLACK, short colorBackground = mainColor, short colorComplete = BLACK_ON_GREEN);

	// вывод рамки
	static void outFrame(int hight, int width, int x, int y, short colorFrame = mainColor, short colorBackground = infoColor);


#pragma endregion 

#pragma region Задания 

#pragma region Задание 1. Вектор

	// Задание 1. Вектор
	void task1();

	// 1. Заполнение вектора 
	void taskOneFillVector();

	// 2. Количество элементов вектора, равных 0
	void taskOneCountNull();

	// вывод элементов с подсветкой елементов со значением 0
	static void showElemVectorNull(vector<int> vec);

	// 3. Сумму элементов вектора, расположенных после минимального элемента
	void taskOneSummElem();

	// вывод элементов с подсветкой первого минимального элемента 
	static void showElemVectorMin(vector<int> vec);

	// 4. Удалить элементы, встречающиеся менее двух раз
	void taskOneDeleteDouble();

	// вывод элементов с подсветкой элементов встречающихся менее двух раз 
	static void showElemVectorRem(vector<int> vec);

	// 5. Упорядочить вектор по возрастанию модулей элементов
	void taskOneSortByModule();

	// 6. Продублировать отрицательные элементы вектора
	void taskOneDoubleNegative();

	// вывод элементов с подсветкой отрицательных елементов
	static void showElemVectorNegative(vector<int> vec);

	// 7. Сохранить вектор в бинарном файле при помощи потока вывода
	void taskOneSaveBinFile();

	// чтение вектора из файла
	void readVectorBinFile(string nameFile, vector<int>& vec);

	// сохраненеи вектора в файл
	void saveVectorBinFile(string nameFile, vector<int>& vec);

	// 8. Прочитать вектор из бинарного файла при помощи потока ввода
	void taskOneLoadBinFile();

#pragma region Общие методы 

	// вывод вектора 
	static void showVector(vector<int> vec, string messageName, string messageInfo, void showElemFunc(vector<int> vec) = showElemVector);

	// вывод шапки с информацией
	static void showHeadVector(vector<int> vec, string messageName, string messageInfo);

	// вывод элементов 
	static void showElemVector(vector<int> vec);

	// вывод разделительной линии
	static void showLineVector();

#pragma endregion

#pragma endregion 

#pragma region Задание 2. Библиотека

	// Задание 2. Библиотека
	void task2();

#pragma endregion

#pragma region Задание 3. Телефонная станция

	// Задание 3. Телефонная станция
	void task3();

#pragma endregion

#pragma endregion

};

