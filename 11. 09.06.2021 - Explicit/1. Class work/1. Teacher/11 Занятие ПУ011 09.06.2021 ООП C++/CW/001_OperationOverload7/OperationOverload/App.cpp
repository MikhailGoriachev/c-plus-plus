#include "pch.h"
#include "App.h"
#include "Utils.h"


// Āūāīä ģąńńčāą ņšåóćīėüķčźīā ā ņąįėč÷ķīģ āčäå
void showTable(const Figures &figures, const char *title)
{
    cout<< endlm(2) << "    " << title
        << "    +++++++\n"
        << "    | NN | Čģ’   |  Ńņīšīķą 1 |  Ńņīšīķą 2 |  Ńņīšīķą 3 |    Ļėīłąäü |\n"
        << "    +++++++\n";

    int n = figures.getLegth();
    for (int i = 0; i < n; i++) {
        Triangle t = figures[i];
        cout<< "    | " << setw(2) << i 
            << " | " << left << setw(5) << t.getName() << right 
            << " | " << setw(10) << t.getA() 
            << " | " << setw(10) << t.getB() 
            << " | " << setw(10) << t.getC() 
            << " | " << setw(10) << t.area() << " |\n";  
    } // for i
    cout<< "    +++++++\n";
} // showTable

// Āūāīä ģąńńčāą ņšåóćīėüķčźīā ā ņąįėč÷ķīģ āčäå, ōīķīģ āūäåė’åģ żėåģåķņ
// ń ēąäąķķūģ čķäåźńīģ
void showTable(const Figures &figures, const char *title, int index)
{
    cout<< endlm(2) << "    " << title
        << "    +++++++\n"
        << "    | NN | Čģ’   |  Ńņīšīķą 1 |  Ńņīšīķą 2 |  Ńņīšīķą 3 |    Ļėīłąäü |\n"
        << "    +++++++\n";

    int n = figures.getLegth();
    for (int i = 0; i < n; i++) {
        Triangle t = figures[i];
        cout<< (i == index?color(BLUE_ON_GRAY):color(GRAY_ON_BLACK))
            << "    | " << setw(2) << i 
            << " | " << left << setw(5) << t.getName() << right 
            << " | " << setw(10) << t.getA() 
            << " | " << setw(10) << t.getB() 
            << " | " << setw(10) << t.getC() 
            << " | " << setw(10) << t.area() << " |    \n";  
    } // for i
    cout<< color(GRAY_ON_BLACK) 
        << "    +++++++\n";
} // showTable


void demoIndexByName(const Figures &figures)
{
    cout << cursor_on;
    char *name = new char[Triangle::NAME_LEN];

    while(true) try {
        showTable(figures, "\n    Ōčćóšū äė’ īįšąįīņźč:\n");

        cout<< "\n    Čģ’ ņšåóćīėüķčźą (" 
            << color(LTCYAN_ON_BLACK) << "quit" << color(GRAY_ON_BLACK) << " - āūõīä): ";
        cin.ignore(cin.rdbuf()->in_avail());
        cin.getline(name, Triangle::NAME_LEN-1);
        if (strcmp(name, "quit") == 0) break;

        cout << endlm(2) << "    " << figures[name] << endlm(2);
    } catch (exception ex) {
        cout<< endlm(3) << color(RED_ON_WHITE) << "    " << ex.what() << "    " 
            << color(GRAY_ON_BLACK) << endlm(3);
    } // try-catch

    delete[] name;
    cout << cursor_off; 
} // demoIndexByName

// ćåķåšąöč’ čģåķč ņšåóćīėüķčźą - ńėó÷ąéķūģ īįšąēīģ ōīšģčšóåģ
// ņšåņčé ńčģāīė čģåķč ņšåóćīėüķčźą
void generName(char name[Triangle::NAME_LEN])
{
    name[2] += getRand(0, 25);
} // generName

// äåģīķńņšąöč’ īļåšąöčč äīįąāėåķč’ żėåģåķņą ā źīķåö ģąńńčāą 
void demoAddItem(Figures &figures)
{
    char name[Triangle::NAME_LEN] = "XYA";
    generName(name);
     
    showTable(figures, "\n    Ņšåóćīėüķčźč äī äīįąāėåķč’ żėåģåķņą ā źīķåö ģąńńčāą:\n");

    // äīįąāėåķčå ā źīķåö ģąńńčāą
    figures & Triangle(getRand(5., 20.), name);

    showTable(figures, "\n    Ņšåóćīėüķčź äīįąāėåķ ā źīķåö ģąńńčāą:\n", figures.getLegth()-1);
} // demoAddItem

// äåģīķńņšąöč’ īļåšąöčé óäąėåķč’ żėåģåķņīā 
void demoDelItem(Figures &figures)
{
    ostringstream oss;

    // óäąėåķčå ļī čķäåźńó
    showTable(figures, "\n    Ņšåóćīėüķčźč äī óäąėåķč’ żėåģåķņą ļī čķäåźńó:\n");
    int index = getRand(0, figures.getLegth()-1);

	figures = figures | index;

	oss << "\n    Óäąėåķ ņšåóćīėüķčź ń čķäåźńīģ " << index << ":\n";
    showTable(figures, oss.str().c_str());

    // óäąėåķčå ļī čģåķč ņšåóćīėüķčźą
    char name[Triangle::NAME_LEN];
    strcpy(name, figures[figures.getLegth()-1].getName());

    // óäąėåķčå ļī čģåķč
    figures = figures | name;

    oss.str("");
    oss << "\n    Óäąėåķ ņšåóćīėüķčź ń čģåķåģ \"" << name << "\":\n";
    showTable(figures, oss.str().c_str());
} // demoDelItem

// äåģīķńņšąöč’ īļåšąöčč äīįąāėåķč’ żėåģåķņą ā ģąńńčā
void demoInsItem(Figures &figures)
{
     ostringstream oss;

    // āńņąāźą żėåģåķņą ļī čķäåźńó
    showTable(figures, "\n    Ņšåóćīėüķčźč äī āńņąāźč żėåģåķņą ā ķą÷ąėī:\n");
    int index = getRand(0, figures.getLegth()-1);
    char name[Triangle::NAME_LEN] = "INA";
    generName(name);

    // ńīįńņāåķķī āńņąāźą żėåģåķņą
    figures = figures(index, Triangle(getRand(5., 15.), name));
    
    oss << "\n    Ņšåóćīėüķčź \"" << name << "\" āńņąāėåķ ā ģąńńčā ļī čķäåźńó " << index << ":\n";
    showTable(figures, oss.str().c_str(), index);
} // demoInsItem