#pragma once
#include "Figures.h"

void firstMin(const Figures &figures);
void lastMax(const Figures &figures);

void showTable(const Figures &figures, const char *title);
void showTable(const Figures &figures, const char *title, int index);

void demoIndexByName(const Figures &figures);
void demoAddItem(Figures &figures);
void demoDelItem(Figures &figures);
void demoInsItem(Figures &figures);
