#include "pch.h"
#include "Utils.h"

int main()
{
	// настройка вывода в консоль
	init(L"31.05.2021 - собственные манипуляторы вывода: реализация перегрузкой операции вывода");

    cout << cls << tab << "Привет, мир!" << endl;
	
    
    cout << endlm(5) << tab << color(BLUE_ON_WHITE) << "   Это строка для вывода   "
         << tab << tab << color(GRAY_ON_WHITE)   << "  продолжение  "
         << pos(0, 24)  << color(GRAY_ON_LTBLACK);

    
    cout<< color(LTCYAN_ON_LTBLACK) << tab << "Это строка для вывода " 
	    << tab << tab << color(LTGREEN_ON_BLACK) << "  продолжение  " << endlm(4)
	    << color(GRAY_ON_LTBLACK) << endlm(2);
    Sleep(5000);
	
	cout<< cls << color (GRAY_ON_BLACK) << pos(20, 10) 
		<< pos(20, 11) << setw(52) << " "
		<< pos(20, 12) << setw(52) << " "
	    << color(BLACK_ON_GREEN)
	    << pos(20, 13) << setw(52) << " "
		<< pos(20, 14) << "    " << left << setw(48) << "Конец работы приложения" << right
		<< pos(20, 15) << setw(52) << " "
	    << color(GRAY_ON_BLACK)
	    << pos(20, 16) << setw(52) << " "
        << pos(20, 17) << setw(52) << " "
        << color(GRAY_ON_LTBLACK) 
        << pos(0, 24);
    
    getKey();
	return 0;
} // main