#include "pch.h"
#include "TDate.h"

// пример определения метода структуры вне определения структуры
// типЗначения ТипСтруктуры::имяМетода(параметры) { тело метода }
//
// вывод структуры в 
void TDate::Output()
{
	cout<< setfill('0')
	    << setw(2) << Day << "/" << setw(2) << Month << "/" << setw(4) << Year
	    << setfill(' ');
} // TDate::Output


// пример определения метода структуры вне определения структуры
// определение 
bool TDate::LeapYear()
{
	if (Year % 4 != 0) return false;

	if (Year % 100 == 0 && Year % 400 != 0) return false;

	return true;
} // TDate::LeapYear


