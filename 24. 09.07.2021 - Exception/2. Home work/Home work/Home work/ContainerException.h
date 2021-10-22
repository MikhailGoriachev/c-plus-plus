#pragma once

#include "pch.h"

/*
	Разработайте собственный класс исключения, унаследованный от класса
	exception. Передавать в исключение: сообщении об ошибке, значение элемента
	массива, при обработке исключения сам элемент массива не менять.
*/

// Класс исключений на базе класса exception
template<typename T>
class ContainerException : public exception
{
public:

	// конструктор по умолчанию
	ContainerException() {}

	// конструктор инициализирующий
	ContainerException(const char* message) : exception(message) {}

	// копирующий конструктор 
	ContainerException(const ContainerException<T>& сontainerException) {};

	// перегрузка операции присваивания
	ContainerException& operator=(const ContainerException<T>& containerException) = default;

	// деструктор 
	virtual ~ContainerException() override = default;

	// перегрузка операции вывода
	friend ostream& operator<<(ostream& os, const ContainerException& containerException)
	{
		return os << containerException.what();
	}
};

