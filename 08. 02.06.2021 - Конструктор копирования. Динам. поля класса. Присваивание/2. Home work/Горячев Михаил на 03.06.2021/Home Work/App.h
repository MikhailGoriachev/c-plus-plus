#pragma once
#include "pch.h"

/*???????? ?????????? ????????????? ?????????? ? ?????????????? ??? ?? ?????????? ???????.
 *	???????????? ????? Plane ? ?????? ??? ????????:
 *		?	????????????? ? ???? ???????? (????????: ??-76, Boeing 747, ?) ? char *
 *		?	?????????? ???????????? ???? (?? 0 ?? 1000)- int
 *		?	??????? ?????????? ?????????? (?? 0 ?? ?????????? ???????????? ????)- int
 *		?	??????? ???????? ?? ??? ?????? (???????????? ?????, ?? 0.1 ?? 28600 ??/?) - double
 *		?	?????????? ?????????? (?? 1 ?? 8)?int
 *		?	???????? ???????????? ? ????????? ? char *.
 *	? ??????Plane ???????????:
 *		?	????????????: ?? ?????????, ? ???????????, ??????????
 *		?	??????????
 *		?	??????? ? ??????? ??? ???? ????? ??????, ? ??????????????????? ?????????? ??? ???????????
 *			????????????? ????????
 *		?	?????, ??????????? ?????? ???????? ?? ??? ?????? ?? ???? ???????????? ????? (???????? ??????
 *			???????? ?? ??? ?? ?????????? ???????????? ????)
 *		?	?????????????? ???????? ???????? ??????:
 *			o	+ ?????????? ????????? ?????????? ??????????
 *			o	??????????? ?????????? ?????????? ?? ???????? ????????
 *			o	++??????????, ?????????? ??????? ???????? ?? 100 ??/?
 *			o	--??????????, ?????????? ??????? ???????? ?? 100 ??/?
 *			o	???????? ?????????: <<= == != >= > ??? ????????? ???? ???????? ?? ?????????? ??????????
 *	?? ???????????? ??????? ?????? Plane????????????????? ?????? ????????, ????????, ????????????? ????????
 *	??????????????? ???? ? ???????????? ??????????.
*/

class Plane;

// TODO: ?????????? ????? - ???????? ?????? ?????????? - ??????-?????? ??????????
class App
{
public:
	// ??????? 1
	void task1();

	// ????? ?????? Plane
	void printPlane(Plane& plane);

};

