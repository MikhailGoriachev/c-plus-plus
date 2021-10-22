#pragma once
#include "pch.h"

/*

Стандартные исключения C++

exception                 - базовый класс исключений 
    logic_error           - ошибки в логике программы (семантические ошибки)
        domain_error      - общая ошибка
		invalid_argument  - недопустимые параметры
		length_error      - неправильная длина (размер)
		out_of_range      - выход за пределы
	runtime_error         - ошибка времени исполнения
	    range_error       - выход за пределы
		overflow_error    - переполнение при вычислениях
		underflow_error   - утрата значимости
	Следующие 5 классов - формируются run-time системой
	bad_alloc     - ошибка выделения памяти new, new[]
	bad_cast      - ошибка приведения типа,
	                ошибка  RTTI - Run-Time Type Identification
	bad_typeid    - ошибка RTTI
	bad_exception - нет подходящего обработчика исключения
	ios::failure  - ошибка ввода-вывода

    Большинство этих типов определено в заголовочном файле stdexcept, 
	за исключением класса bad_alloc, который определн в файле new, и 
	класса bad_cast, который определен в файле type_info.

 */
class MegaException :	public exception
{
public:
	MegaException(const char *msg):exception(msg) {  }
	// string - тип из STL (Standart Template Library)
	MegaException(const string &msg):exception(msg.c_str()) {  }
};

