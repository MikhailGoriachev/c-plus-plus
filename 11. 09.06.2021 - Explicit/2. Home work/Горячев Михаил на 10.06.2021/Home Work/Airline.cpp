#include "Airline.h"

#pragma region ������������ � ����������

// ����������� ����������������
Airline::Airline(const char* nameCompany, int countPlane) : nameCompany_(new char[NAME_COMP_SIZE])
{
	// �������� ��������
	setNameCompany(nameCompany);

	// ���������� ��������
	setCountPlane(countPlane);

	// ���� ���������� �������� ������ ����
	if (countPlane_ != 0)
	{
		// ��������� ������ ��� ������� ��������
		planes_ = new Plane[countPlane_];
	}
}

// ����������� ����������������, ����������� ������ ��������
Airline::Airline(const char* nameCompany, Plane* planes, int countPlane) : nameCompany_(new char[NAME_COMP_SIZE])
{
	// �������� ��������
	setNameCompany(nameCompany);

	// ����������� ���������
	planes_ = planes;

	// ���������� ��������
	setCountPlane(countPlane);
}

#pragma endregion

#pragma region ������� � �������

// ������ nameCompany_
void Airline::setNameCompany(const char* nameCompany)
{
	// ���� ����� ������ ����� 0
	if (strlen(nameCompany) == 0)
	{
		throw exception("�������� �������� �� ������ ���� ������!");
	}

	memcpy(nameCompany_, nameCompany, NAME_COMP_SIZE - 1);
}

// ������ countPlane_
void Airline::setCountPlane(int countPlane)
{
	if (countPlane < 0)
	{
		throw exception("���������� ��������� ������ ��������� ��� ���� ������ ����");
	}

	countPlane_ = countPlane;
}

// ������ planes_
void Airline::setPlanes(Plane* planes)
{
	// ���� ��������� ��������� ����� nullptr
	if (planes == nullptr)
	{
		throw exception("��������� �� ������ �������� �������� nullptr");
	}

	// ���� ��������� planes_ �� ����� nullptr, ���� ���� ���������� �������� �� ����� ����
	if (planes_ == nullptr || countPlane_ == 0)
	{
		delete[] planes_;
	}

	// ����������� ���������
	planes_ = planes;
}

#pragma endregion

#pragma region ������

// ���������� ������� (� ����� �������)
Airline& Airline::operator&(Plane& newPlane)
{
	// ����� �������� ������� Airline
	Airline* newAir = new Airline(*this);

	// ����� ������ �������� � ����������� �������
	Plane* newPlanes = new Plane[countPlane_ + 1];

	// ����������� ������� ��������
	for (size_t i = 0; i < countPlane_; i++)
	{
		newPlanes[i] = planes_[i];
	}

	// ������� ������ ������� � ��������� ������� �������
	newPlanes[newAir->countPlane_++] = newPlane;

	// �������� ������� ������� ������ ������� Airplane
	delete[] newAir->planes_;

	// ����������� ��������� �� ����� ������ �������� � ����� ������ Airplane
	newAir->planes_ = newPlanes;

	return *newAir;
}

#pragma region ��������� ����������

// ���������� �������� [] ��� ������� � ��������� ������� ���������
Plane& Airline::operator[](int index)
{
	if (index < 0 || index >= countPlane_)
		throw exception("������������ ������");

	return planes_[index];
}

// ���������� �������� �������� * ��� ���������� ��������� ��������� �� �������� ����������� (�������������)
Airline& Airline::operator*(double coefficient)
{
	// ���� ����������� ������������� 
	if (coefficient < 0)
		throw exception("����������� ������ ���� �������������");

	Airline* temp = new Airline(*this);

	// ���� ��������� ��������� ������� ������� �� ����������� 
	for (size_t i = 0; i < countPlane_; i++)
	{
		temp->planes_[i].setPrice(int(planes_[i].getPrice() * coefficient));
	}

	return *temp;
}

// ���������� ��������� ������������
Airline& Airline::operator=(const Airline& air)
{
	// �������� ��������
	strcpy(nameCompany_, air.nameCompany_);

	// ������������ ������ ��������� � �������� ������ Plane
	planes_ = new Plane[air.countPlane_];

	for (size_t i = 0; i < air.countPlane_; i++)
	{
		planes_[i] = air.planes_[i];
	}

	// ���������� ��������� � �������
	countPlane_ = air.countPlane_;

	return *this;
}

// ����� ������ ������������ � ��������� ������� � ���������� �������� ������ <<
ostream& operator<<(ostream& os, Airline air)
{
	os << "\t\t\t\t\t" << air.nameCompany_ << "\n"
		<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n"
		<< "|     ������    |  ��������. | ���������� | ����. �������� |     ���������     |  ��������� ����� |  ���������. ����� |\n"
		<< "|               |    ����    |            |     ��/�       |      �������     |      �������     |      �������     |\n"
		<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

	// ���� � �������� ��� ��������
	if (air.countPlane_ == 0)
	{
		os << "|                                                    ��� ����˨���                                                     |\n"
			// ������ ������ 
			<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}

	// ����� ��������
	for (int i = 0; i < air.countPlane_; i++)
	{

		os << air[i];

		// ������ ������ 
		os << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}

	return os;
}

// ���������� ������� �������� � ��� ������ ������� �������� � ����������� ���������� ������
Plane& Airline::operator-()
{
	// ���� ��� ��������
	if (countPlane_ == 0)
	{
		throw exception("��� ��������!");
	}

	// ������� ����������� ��������� ������
	int minDist = planes_[0].getDistance();

	// ������ 
	int minIndex = 0;

	// ���������� ������� ������� � ����������� ����������
	for (int i = 1; i < countPlane_; i++)
	{
		// ��������� �������� �������
		int dist = planes_[i].getDistance();

		// ���� ������� ����������� ��������� ������, ��� ��������� �������� �������
		if (minDist > dist)
		{
			minDist = dist;
			minIndex = i;
		}
	}

	return planes_[minIndex];
}

// ���������� ������� �������� ! ��� ������ ������� �������� � ������������ ���������� ������
Plane& Airline::operator+()
{
	// ���� ��� ��������
	if (countPlane_ == 0)
	{
		throw exception("��� ��������!");
	}

	// ������� ������������ ��������� ������
	int maxDist = planes_[0].getDistance();

	// ������ 
	int maxIndex = 0;

	// ���������� ������� ������� � ������������ ����������
	for (int i = 1; i < countPlane_; i++)
	{
		// ��������� �������� �������
		int dist = planes_[i].getDistance();

		// ���� ������� ������������ ��������� ������, ��� ��������� �������� �������
		if (maxDist < dist)
		{
			maxDist = dist;
			maxIndex = i;
		}
	}

	return planes_[maxIndex];
}

// ������� ������ ����������� ������� ��������* ��� ���������� 
// ������� ��������� �� ��������� ����� �������
Airline& Airline::operator*()
{
	Airline* newAir = new Airline(*this);

	// ������� ���������� ������� 
	quickSort(newAir->getPlanes(), 0, newAir->getCountPlane() - 1);

	return *newAir;
}

// ���������� �������� �������� *
// ���������� �� �������� ���������� ����������
Airline Airline::operator*(int comparer(const Plane& plane1, const Plane& plane2))
{
	Airline* newAir = new Airline(*this);

	// ������� ���������� ������� �������� �� �����������
	quickSort(newAir->getPlanes(), 0, newAir->getCountPlane() - 1, comparer);

	return *newAir;
}

// ���������� ������� �������� ! ���  �������� ������� �������� �� �������(�������� � �������� 0)
Airline& Airline::operator!()
{
	// ���� ���������� �������� ����� ����
	if (countPlane_ <= 0) throw exception("�������� �� ����������!\n");

	// ����� ������ Airline 
	Airline* newAirline = new Airline(*this);

	// ���� ��������� ��������� ������ ������ Plane
	if (countPlane_ == 1) 	
	{
		// �������� ������� ������� � ����� ������� Airline
		delete[] newAirline->planes_;

		// ���������� ������ ������ 
		newAirline->planes_ = nullptr;

		// ���������� ���������� �������� � ����� ������� 
		newAirline->countPlane_--;

		return *newAirline;
	}

	// ����� ������ �������� Plane
	Plane* newPlanes = new Plane[countPlane_ - 1];

	// ����������� �������� 
	for (size_t i = 0, k = 0; i < countPlane_; i++)
	{
		if (i == 0) continue;

		newPlanes[k++] = planes_[i];
	}

	// �������� ������� ������� � ����� ������� Airline
	delete[] newAirline->planes_;

	// ���������� ������ ������ 
	newAirline->planes_ = newPlanes;

	// ���������� ���������� �������� � ����� ������� 
	newAirline->countPlane_--;

	return *newAirline;
}

// ���������� �������� �������� !! ��� �������� �������� �� ������� �� ��������� �������
Airline& Airline::operator||(int index)
{
	if (index >= countPlane_ || index < 0) throw exception("������� � ����� ������� �� ����������!\n");

	if (countPlane_ == 0) throw exception("�������� �� ����������!\n");

	// ����� ������ Airline 
	Airline* newAirline = new Airline(*this);

	// ���� ��������� ��������� ������ ������ Plane
	if (countPlane_ == 1)
	{
		// �������� ������� ������� � ����� ������� Airline
		delete[] newAirline->planes_;

		// ���������� ������ ������ 
		newAirline->planes_ = nullptr;

		// ���������� ���������� �������� � ����� ������� 
		newAirline->countPlane_--;

		return *newAirline;
	}

	// ����� ������ �������� Plane
	Plane* newPlanes = new Plane[countPlane_ - 1];

	// ����������� �������� 
	for (size_t i = 0, k = 0; i < countPlane_; i++)
	{
		if (i == index)
			continue;

		newPlanes[k++] = planes_[i];
	}

	// �������� ������� ������� � ����� ������� Airline
	delete[] newAirline->planes_;

	// ���������� ������ ������ 
	newAirline->planes_ = newPlanes;

	// ���������� ���������� �������� � ����� ������� 
	newAirline->countPlane_--;

	return *newAirline;

}

// ������� ������ ����������� �������� �������� !!��� �������� �������� �� ������� �� ���������������� ������
Airline& Airline::operator||(char* number)
{
	if (countPlane_ <= 0) throw exception("�������� �� ����������!\n");

	// ����� ������� �������� � ������ �������
	for (size_t i = 0; i < countPlane_; i++)
	{
		if (strcmp(number, planes_[i].getNumber()) == 0)
		{
			return *this || i;
		}
	}

	throw exception("������� � ����� ������� �� ����������!\n");
}

// ������� ������ ����������� ��������() ��� ������� �� ��������� ������� ��������(�������� ������
// �������� ������� ���������� � ����� �������)
Airline& Airline::operator()(int index, Plane& newPlane)
{
	//if (countPlane_ == 0 && index == 0) {}

	if ((index >= countPlane_ || index < 0) && index != 0) throw exception("������� � ����� ������� �� ����������!\n");

	// ����� ������ Airline 
	Airline* newAirline = new Airline(*this);

	// ����� ������ �������� Plane
	Plane* newPlanes = new Plane[countPlane_ + 1];

	if (countPlane_ == 0) newPlanes[0] = newPlane;

	else
	{
		// ����������� �������� 
		for (size_t i = 0, k = 0; i < countPlane_; i++)
		{
			if (i == index)
				newPlanes[k++] = newPlane;

			newPlanes[k++] = planes_[i];
		}

		// �������� ������� ������� � ����� ������� Airline
		delete[] newAirline->planes_;
	}
	// ���������� ������ ������ 
	newAirline->planes_ = newPlanes;

	// ���������� ���������� �������� � ����� ������� 
	newAirline->countPlane_++;

	return *newAirline;
}

#pragma endregion

#pragma endregion
// ������� ���������� ������� �������� �� �����������
void Airline::quickSort(Plane* planes, int start, int end, int compare(const Plane& pl1, const Plane& pl2)) {
	// ������� ���������� ��������
	if (start >= end) return;

	// ��������� �������� ���������� �� ��������� ������
	int i = start, j = end;                      // ��� ������ ���������
	int baseElement = start + (end - start) / 2; // ������ ���������� ������� �������� �������

	while (i < j) {

		Plane value = planes[baseElement];

		while (i < baseElement && (compare(planes[i], value) <= 0)) i++;

		while (j > baseElement && (compare(planes[j], value) >= 0)) j--;


		if (i < j) {
			// ������ ������� �������� � ���������� �������
			swap(planes[i], planes[j]);

			// �� �������
			if (i == baseElement) baseElement = j;

			else if (j == baseElement)  baseElement = i;
		} // if
	} // while

	// ����������� ����� � ����� �������� ������
	quickSort(planes, start, baseElement, compare);          // �� ������ ������� �� cur
	quickSort(planes, baseElement + 1, end, compare);      // �� cur+1 �� ����� �������
} // quickSort

// ������� ���������� ������� �������� �� ��������� ����� �������
void Airline::quickSort(Plane* planes, int start, int end) {
	// ������� ���������� ��������
	if (start >= end) return;

	// ��������� �������� ���������� �� ��������� ������
	int i = start, j = end;                      // ��� ������ ���������
	int baseElement = start + (end - start) / 2; // ������ ���������� ������� �������� �������

	while (i < j) {

		Plane value = planes[baseElement];

		while (i < baseElement && (planes[i].getDistance() <= value.getDistance())) i++;

		while (j > baseElement && (planes[j].getDistance() >= value.getDistance())) j--;


		if (i < j) {
			// ������ ������� �������� � ���������� �������
			swap(planes[i], planes[j]);

			// �� �������
			if (i == baseElement) baseElement = j;

			else if (j == baseElement)  baseElement = i;
		} // if
	} // while

	// ����������� ����� � ����� �������� ������
	quickSort(planes, start, baseElement);          // �� ������ ������� �� cur
	quickSort(planes, baseElement + 1, end);      // �� cur+1 �� ����� �������
} // quickSort
