#pragma once
#include "pch.h"
#include "Utils.h"
#include "Airline.h"
#include "Plane.h"
#include "App.h"
#include "ShowOnePlaneTable.h"

/*
	???????? ?????????? ??????????????????????? ? ?????????????? ??? ?? ?????????? ???????. ????????? 
	???? ?? ???????? ?????? ??? ??????????? ???????? ?????????? ????????????.
	???????????? ????? Plane ? ?????? ??? ????????:
	?	????????????? ? ???? ???????? (????????: ??-76, Boeing 747, ?)
	?	?????????? ???????????? ???? (?? 0 ?? 1000)
	?	??????? ?????????? ?????????? (?? 0 ?? ?????????? ???????????? ????)
	?	??????? ???????? ?? ??? ?????? (???????????? ?????, ?? 0.1 ?? 20000 ??/?)
	?	????????? ?????? ???????? (?? 1000 ?? 20000 ??)
	?	??????????????? ????? ???????? (????????: UR-DAD, UR-CCF, ?).
	? ??????Plane ???????????:
	?	????????????: ?? ?????????, ? ??????????? (explicit), ??????????, ??????????
	?	??????? ? ??????? ??? ???? ????? ??????, ? ??????????????????? ?????????? ??? 
	??????????? ????????????? ????????
	?	?????, ??????????? ?????? ???????? ?? ??? ?????? ?? ???? ???????????? ????? (???????? ?????? 
	???????? ?? ??? ?? ?????????? ???????????? ????)
	?	??????????? ???????? ?????? <<
	???????????? ????? Airline, ?????????????? ????????????. ???? ??????:
	?	???????? ????????
	?	???????????? ?????? ????????? ? ???????? ?????? Plane
	?	?????????? ????????? ? ???????
	?????????? ??? ?????? Airline:
	?	????????????? ??????? ?????????
	?	????? ?????? ???????????? ? ????????? ??????? ? ??????????? ???????? ?????? <<
	?	????? ?????? ???????????? ? ????????? ???? ? ?????????? ?????? ????????? ? ???????????? ? 
	??????????? ??????????? ??????
	?	??????? ?????? ??????????? ??????? ???????? * ??? ?????????? ??????? ????????? ?? ????????? ??????
	?	??????? ?????? ??????????? ???????? ???????? * ??? ?????????? ??????? ????????? ??? ?????? 
	??????????? (?????????? ??????
	Airline&operator*(intcomparer(constPlane&plane1, constPlane&plane2)); ????????????????? ?????????? 
	?? ???????? ?????????? ??????????, ?? ???????????????? ??????, ?? ???????? ??????? ????????
	?	??????? ?????? ??????????? ???????? ???????? &??? ?????????? ???????? ? ????? ???????, ???????? 
	?? ????????, ???????????? ?????? ?? ?????????? ??????
	?	??????? ?????? ??????????? ??????? ???????? !???  ???????? ??????? ???????? ?? ??????? (???????? ? ???????? 0)
	?	??????? ?????? ??????????? ???????? ???????? !!??? ???????? ???????? ?? ??????? ?? ????????? ???????
	?	??????? ?????? ??????????? ???????? ???????? !!??? ???????? ???????? ?? ??????? ?? ???????????????? ??????
	?	??????? ?????? ??????????? ???????? () ??? ??????? ?? ????????? ??????? ???????? (???????? ?????? 
	???????? ??????? ?????????? ? ????? ???????)
	????????????????? ?????? ????????????? ????????, ???????. ??????????????? ???? ? ???????????? ??????????.
*/

// TODO: ?????????? ????? - ???????? ?????? ?????????? - ??????-?????? ??????????
class App
{
	// ?????? ?????? Airline
	Airline air;

	// ?????????? ????????? ?? ???????? ?????????? ??????????
	static int compareByCount_passengers(const Plane& pl1, const Plane& pl2);

	/// ?????????? ????????? ?? ???????????????? ??????
	static int compareByNumber(const Plane& pl1, const Plane& pl2);

	/// ?????????? ????????? ?? ???????? ??????? ????????
	static int compareByFuel(const Plane& pl1, const Plane& pl2);

public:

#pragma region ???????????? ? ??????????
	// ??????????? ?? ????????? 
	explicit App();

	// ?????????? ???????????
	App(App& app) = default ;

	// ??????????
	~App() = default;

#pragma endregion

#pragma region ????? ?????????

	// ????? ????????
	void outPlanes();
	
	// ????? ???????? ?? ???????
	void outPlaneIndex();

	// ????? ?????? ???????????? ? ????????? ???? ? ?????????? ??????
	// ????????? ? ???????????? ? ??????????? ??????????? ??????
	void outTableColor();

#pragma endregion
		
#pragma region ?????????? ?????????

	// ?????????? ???????? ?? ???????? ?????????? ??????????
	void sortByCountPassangers();

	// ?????????? ???????? ?? ???????????????? ??????
	void sortByNumber();

	// ?????????? ???????? ?? ???????? ??????? ????????
	void sortByFuel();

	// ?????????? ???????? ?? ????????? ??????
	void sortByDistance();

#pragma endregion

#pragma region ????????? ??????? ?????????

	// ?????????? ???????? ? ??????
	void addPlane();

	// ??????? ?????? ??????????? ??????? ???????? !???  ???????? ??????? ???????? ?? ???????(???????? ? ???????? 0)
	void deleteFirstPlane();

	// ??????? ?????? ??????????? ???????? ???????? !!??? ???????? ???????? ?? ??????? ?? ????????? ???????
	void deletePlaneByIndex();

	// ??????? ?????? ??????????? ???????? ???????? !!??? ???????? ???????? ?? ??????? ?? ???????????????? ??????
	void deletePlaneByNumber();

	// ??????? ?????? ??????????? ????????() ??? ??????? ?? ????????? ??????? ????????(???????? ??????
	// ???????? ??????? ?????????? ? ????? ???????)
	void insertPlaneByIndex();

#pragma endregion

#pragma region ?????????? ????????

#pragma endregion

};

