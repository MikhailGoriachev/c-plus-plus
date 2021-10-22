#pragma once
#include "pch.h"
#include "Utils.h"

//  ласс не завершен намеренно - просто подопытный кролик
// дл€ try-блока в списке инициализации
class ClassA
{
	int    size_;
	double *data_;

public:
	ClassA(): size_(10), data_(new double[size_]) {}

	// »м€ ласса(списокѕараметров) try: список»нициализации
	// {
	//    операторы конструктора
    // } 
	// catch (тип»сключени€1 им€1) { обработка1 }
	// catch (тип»сключени€2 им€2) { обработка2 }
	// ...
	// catch (тип»сключени€N им€N) { обработкаN }
	ClassA(const double *data, int size) try: 
		size_(size > 0?size:throw exception("Ќедопустимый размер контейнера")), 
		data_(new double[size_]) 
	{
		memcpy(data_, data, sizeof(double)*size_);
	} 
	catch (exception &ex) {
		cout << endlm(2) << "    " << ex.what() << endlm(2);
		// abort(); // не об€зательно
	    throw; // не об€зательно
	} // catch

};

