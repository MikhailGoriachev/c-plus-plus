#include "pch.h"
#include "Utils.h"
#include "Palette.h"

#include "TCylinder.h"     // äëÿ èñïîëüçîâàíèÿ ñòğóêòóğû TCylinder
#include "TConoid.h"

// âûâîä ìàññèâà öèëèíäğîâ â òàáëè÷íîì ôîğìàòå, ãîğèçîíòàëüíàÿ ëèíèÿ:  Alt+0151
void showTable(const char* title, CYLINDER* cylinders, int n, int maxIndex)
{
	cout << title
		<< "\t    +++++\n"
		<< "\t    |  N  |    Ğàäèóñ, R    |    Âûñîòà, H   |   Ïëîùàäü, S   |    Îáúåì, V    |\n"
		<< "\t    +++++\n";

	// âûâîäèì ñòğîêè òàáëèöû öèëèíäğîâ, ñ âûäåëåíèåì öâåòîì
	// ñòğîêè ñ ìèíèìàëüíûì îáúåìîì, ïåğåä è ïîñëå ıòîé ñòğîêè
	// âûâîäèì öâåòîâûå "õâîñòèêè"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(cylinders[i].MathV() == cylinders[maxIndex].MathV() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +++++\n";
} // showTable

// âûâîä ìàññèâà öèëèíäğîâ â òàáëè÷íîì ôîğìàòå, ãîğèçîíòàëüíàÿ ëèíèÿ:  Alt+0151
void showTableConoids(const char* title, CONOID* cylinders, int n, int minIndex)
{
	cout << title
		<< "\t    +++++++\n"
		<< "\t    |  N  |    Ğàäèóñ, R    |    Ğàäèóñ, r   |    Âûñîòà, H   |   Ïëîùàäü, S   |    Îáúåì, V    |\n"
		<< "\t    +++++++\n";

	// âûâîäèì ñòğîêè òàáëèöû öèëèíäğîâ, ñ âûäåëåíèåì öâåòîì
	// ñòğîêè ñ ìèíèìàëüíûì îáúåìîì, ïåğåä è ïîñëå ıòîé ñòğîêè
	// âûâîäèì öâåòîâûå "õâîñòèêè"
	for (int i = 0; i < n; ++i) {
		cout << "\t";
		setColor(cylinders[i].MathS() == cylinders[minIndex].MathS() ? acctColor : mainColor);
		cout << "    ";
		cylinders[i].tableRow(i + 1);
		cout << "    ";
		setColor(mainColor);
		cout << "\n";
	} // for i
	cout << "\t    +++++++\n";
} // showTable