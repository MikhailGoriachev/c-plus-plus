// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"

int main()
{
	init(L"Домашнее задание на 02.06.2021");

	// для вывода в строку средствами C++
	ostringstream oss;

	App app;

	while (true)
	{
		try {
			app.task1();
		}
		catch (exception& ex) {
			cls();
			
			oss.str("");  // очистка строки - буфера вывода
			oss << "\n\t" << ex.what() << "\n";

			// вывод строки с сообщением об ошибке в цвете
			cputs(oss.str().c_str(), errColor);

			getKey();
			// что на самом деле происходит
			// string temp = oss.str();
			// cputs(temp.c_str(), errColor);
		} // try-catch
	}
} // main
