#pragma once
#include "NodePlanec.h"


class ListPlane
{
	// начальный узел списка 
	NodePlanec* head_;

	// счётчик количества узлов списка 
	int counter_;

public:

#pragma region Конуструкторы и деструктор 

	// конструктор по умолчанию
	ListPlane() : head_(), counter_() {}

	// конструктор инициализирующий
	ListPlane(int counter);

	// конструктор создающий список на базе массива 
	ListPlane(Plane* arr, int counter);

	// конструктор копирующий
	ListPlane(const ListPlane& listPlane);

	// дестркутор 
	~ListPlane() { clear(); }

#pragma endregion

#pragma region Методы

	// добавление узла в конец списка 
	void add(Plane plane);

	// добавление массива в конец списка 
	void addAll(Plane* arrPlanes, int size);

	// вставка перед указанной позицией
	void insert(int position, Plane& plane);

	// вставка массива перед указанной позицией 
	void insertAll(int position, Plane* arrPlanes, int size);

	// изменение значения указанного узла 
	void put(int position, Plane& plane);

	// получение значения указанного узла 
	Plane get(int position);

	// удаление указанного узла из списка по позиции
	void removeAtt(int position);

	// отчистка списка 
	void clear();

	// геттер coutner_
	int getCounter() { return counter_; }

	// перегрузка операции []
	NodePlanec* operator[](int position);

	// перегрузка присваивания 
	ListPlane& operator=(const ListPlane& listPlane);

#pragma endregion

	// перегрузка операции вывода 
	friend ostream& operator<<(ostream& os, const ListPlane& listPlane);

	// вывод в цвете
	void showListPlaneColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr);

};

