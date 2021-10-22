#include "pch.h"
#include "App.h"
#include "Utils.h"


// Âûâîä ìàññèâà òğåóãîëüíèêîâ â òàáëè÷íîì âèäå
void showTable(const Figures &figures, const char *title)
{
    cout<< endlm(2) << "    " << title
        << "    +————+———————+————————————+————————————+————————————+————————————+\n"
        << "    | NN | Èìÿ   |  Ñòîğîíà 1 |  Ñòîğîíà 2 |  Ñòîğîíà 3 |    Ïëîùàäü |\n"
        << "    +————+———————+————————————+————————————+————————————+————————————+\n";

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
    cout<< "    +————+———————+————————————+————————————+————————————+————————————+\n";
} // showTable

// Âûâîä ìàññèâà òğåóãîëüíèêîâ â òàáëè÷íîì âèäå, ôîíîì âûäåëÿåì ıëåìåíò
// ñ çàäàííûì èíäåêñîì
void showTable(const Figures &figures, const char *title, int index)
{
    cout<< endlm(2) << "    " << title
        << "    +————+———————+————————————+————————————+————————————+————————————+\n"
        << "    | NN | Èìÿ   |  Ñòîğîíà 1 |  Ñòîğîíà 2 |  Ñòîğîíà 3 |    Ïëîùàäü |\n"
        << "    +————+———————+————————————+————————————+————————————+————————————+\n";

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
        << "    +————+———————+————————————+————————————+————————————+————————————+\n";
} // showTable


void demoIndexByName(const Figures &figures)
{
    cout << cursor_on;
    char *name = new char[Triangle::NAME_LEN];

    while(true) try {
        showTable(figures, "\n    Ôèãóğû äëÿ îáğàáîòêè:\n");

        cout<< "\n    Èìÿ òğåóãîëüíèêà (" 
            << color(LTCYAN_ON_BLACK) << "quit" << color(GRAY_ON_BLACK) << " - âûõîä): ";
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

// ãåíåğàöèÿ èìåíè òğåóãîëüíèêà - ñëó÷àéíûì îáğàçîì ôîğìèğóåì
// òğåòèé ñèìâîë èìåíè òğåóãîëüíèêà
void generName(char name[Triangle::NAME_LEN])
{
    name[2] += getRand(0, 25);
} // generName

