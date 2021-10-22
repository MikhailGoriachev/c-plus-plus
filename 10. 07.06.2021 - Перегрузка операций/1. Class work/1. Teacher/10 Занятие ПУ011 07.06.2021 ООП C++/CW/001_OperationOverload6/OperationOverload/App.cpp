#include "pch.h"
#include "App.h"
#include "Utils.h"


// ����� ������� ������������� � ��������� ����
void showTable(const Figures &figures, const char *title)
{
    cout<< endlm(2) << "    " << title
        << "    +����+�������+������������+������������+������������+������������+\n"
        << "    | NN | ���   |  ������� 1 |  ������� 2 |  ������� 3 |    ������� |\n"
        << "    +����+�������+������������+������������+������������+������������+\n";

    int n = figures.getLegth();
    for (int i = 0; i < n; i++) {
        Triangle t = figures[i];
        cout<< "    | " << setw(2) << i+1 
            << " | " << left << setw(5) << t.getName() << right 
            << " | " << setw(10) << t.getA() 
            << " | " << setw(10) << t.getB() 
            << " | " << setw(10) << t.getC() 
            << " | " << setw(10) << t.area() << " |\n";  
    } // for i
    cout<< "    +����+�������+������������+������������+������������+������������+\n";
} // showTable

// ����� ������� ������������� � ��������� ����, ����� �������� �������
// � �������� ��������
void showTable(const Figures &figures, const char *title, int index)
{
    cout<< endlm(2) << "    " << title
        << "    +����+�������+������������+������������+������������+������������+\n"
        << "    | NN | ���   |  ������� 1 |  ������� 2 |  ������� 3 |    ������� |\n"
        << "    +����+�������+������������+������������+������������+������������+\n";

    int n = figures.getLegth();
    for (int i = 0; i < n; i++) {
        Triangle t = figures[i];
        cout<< color(i == index?BLUE_ON_GRAY:GRAY_ON_BLACK)
            << "    | " << setw(2) << i+1 
            << " | " << left << setw(5) << t.getName() << right 
            << " | " << setw(10) << t.getA() 
            << " | " << setw(10) << t.getB() 
            << " | " << setw(10) << t.getC() 
            << " | " << setw(10) << t.area() << " |    " << color(GRAY_ON_BLACK)
    	    << "\n";
    } // for i
    cout<< "    +����+�������+������������+������������+������������+������������+\n";
} // showTable


void demoIndexByName(const Figures &figures)
{
    cout << cursor_on;
    char *name = new char[Triangle::NAME_LEN];

    while(true) try {
        showTable(figures, "\n    ������ ��� ���������:\n");

        cout<< "\n    ��� ������������ (" 
            << color(LTCYAN_ON_BLACK) << "quit" << color(GRAY_ON_BLACK) << " - �����): ";
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

// ��������� ����� ������������ - ��������� ������� ���������
// ������ ������ ����� ������������
void generName(char name[Triangle::NAME_LEN])
{
    name[2] += getRand(0, 25);
} // generName

// ������������ �������� ���������� �������� � ����� ������� 
void demoAddItem(Figures &figures)
{
    char name[Triangle::NAME_LEN] = "XYA";
    generName(name);
     
    showTable(figures, "\n    ������������ �� ���������� �������� � ����� �������:\n");

    // ���������� � ����� �������
    figures = figures & Triangle(getRand(5., 20.), name);

    showTable(figures, "\n    ����������� �������� � ����� �������:\n", figures.getLegth()-1);
} // demoAddItem
