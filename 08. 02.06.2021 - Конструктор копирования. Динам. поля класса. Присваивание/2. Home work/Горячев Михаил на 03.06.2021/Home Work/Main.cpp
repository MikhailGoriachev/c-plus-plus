// Шаблон консольного приложения для начала курса "ООП на C++"
//

#include "App.h"
#include "pch.h"
#include "Utils.h"

int main()
{
    init(L"Заголовок окна консоли приложения");

	// для вывода в строку средствами C++
	ostringstream oss;

	// TODO: Ваше приложение
	App app;
	
	try {
		app.task1();
	} catch (exception &ex) {
		oss.str("");  // очистка строки - буфера вывода
		oss << "\n\t" << ex.what() << "\n";
		
		// вывод строки с сообщением об ошибке в цвете
		cputs(oss.str().c_str(), errColor);

		// что на самом деле происходит
		// string temp = oss.str();
		// cputs(temp.c_str(), errColor);
	} // try-catch

	getKey();
} // main
