#pragma once

#include "pch.h"
#include "Plane.h"
// βϋβξδ ξδνξγξ ρΰμξλΈςΰ 
class showOnePlaneTable
{
	Plane plane_;

public:
	explicit showOnePlaneTable() = default;

	explicit showOnePlaneTable(Plane plane) :plane_(plane) {}

	~showOnePlaneTable() = default;

	friend ostream& operator<<(ostream& os, showOnePlaneTable show)
	{
		os << "++++++++\n"
			<< "|     Μξδελό    |  Οΰρρΰζθπ. | Οΰρρΰζθπξβ | Πΰρυ. γξπώχεγξ |     Ρςξθμξρςό     |  Δΰλόνξρςό οξλΈςΰ |  Πεγθρςπθρ. νξμεπ |\n"
			<< "|               |    μερς    |            |     κγ/χ       |      ρΰμξλΈςΰ     |      ρΰμξλΈςΰ     |      ρΰμξλΈςΰ     |\n"
			<< "++++++++\n"
			<< show.plane_
			<< "++++++++\n";

		return os;
	}
};
