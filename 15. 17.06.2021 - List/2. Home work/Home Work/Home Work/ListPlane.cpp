#include "ListPlane.h"
#include "Utils.h"

#pragma region ������������� � ���������� 

// ����������� ����������������
ListPlane::ListPlane(int counter)
{
	// ���� �������� counter ������ ��� ����� ����
	if (counter <= 0)
		throw exception("ListPlane: �������� counter ��� �������� � �������������� ������ ���� ������ ����!");

	// ������ Plane 
	Plane plane;

	for (int i = 0; i < counter; i++)
	{
		add(plane);
	}
}

// ����������� ��������� ������ �� ���� ������� 
ListPlane::ListPlane(Plane* arr, int counter)
{
	// ���� �������� counter ������ ��� ����� ����
	if (counter <= 0)
		throw exception("ListPlane: �������� counter ��� �������� � �������������� ������ ���� ������ ����!");

	// ���� ��������� �� ������������ ������ ����� �������� nullptr
	if (arr == nullptr)
		throw exception("ListPlane: ������������� ������� �� ����������!");
	
	for (int i = 0; i < counter; i++)
	{
		add(arr[i]);
	}
}

// ����������� ����������
ListPlane::ListPlane(const ListPlane& listPlane)
{
	// ����������� ���� coutner_
	counter_ = listPlane.counter_;

	// ��������� �� ������ NodePlanec
	NodePlanec* node = listPlane.head_;

	while (node != nullptr)
	{
		add(node->getPayload());

		node = node->getNext();
	}
}

#pragma endregion

#pragma region ������

// ���������� ���� � ����� ������ 
void ListPlane::add(Plane plane)
{
	// ������ NodePlanec
	NodePlanec* newNode = new NodePlanec(plane);

	// ���� coutner_ ����� ����
	if (counter_ == 0)
	{
		// ��������� ��������� �� ������ ���� ������ 
		head_ = newNode;

		// ���������� ���������� ��������� ������ 
		counter_++;

		return;
	}

	// ��������� �� ������� ���� ������ NodePlanec
	NodePlanec* node = head_;

	// ����� ���������� ���� ������ 
	while (node->getNext() != nullptr)
	{
		node = node->getNext();
	}

	// ��������� ���� next_ � ��������� ���� ������ 
	node->setNext(newNode);

	// ���������� ���������� ��������� ������ 
	counter_++;
}

// ���������� ������� � ����� ������ 
void ListPlane::addAll(Plane* arrPlanes, int size)
{
	// ���� �������� counter ������ ��� ����� ����
	if (size <= 0)
		throw exception("ListPlane: �������� n ��� ���������� ������� � ����� ������ ������ ���� ������ ����!");

	// ���� ��������� �� ������������ ������ ����� �������� nullptr
	if (arrPlanes == nullptr)
		throw exception("ListPlane: ������������� ������� �� ����������!");

	for (int i = 0; i < size; i++)
	{
		add(arrPlanes[i]);
	}
}

// ������� ����� ��������� ��������
void ListPlane::insert(int position, Plane& plane)
{
	// ���� ������ ���� 
	if (counter_ == 0)
		throw exception("ListPlane: ������ ����!");

	// ���� ��������� ������� ������ ����
	if (position < 0)
		throw exception("ListPlane: ��������� ������� ������ ���� ������ ����!");

	// ���� ��������� ������� ������ ������������ ������� � ������ 
	if (position >= counter_)
		throw exception("ListPlane: ��������� ������� ������ ������������ ������� � ������!");


	// ������� �� ������� �������
	if (position == 0)
	{
		// ������ NodePlanec
		NodePlanec* newPlanec = new NodePlanec(plane, head_);

		// ��������� head_
		head_ = newPlanec;
	}

	else
	{
		// ������ NodePlanec
		NodePlanec* newPlanec = new NodePlanec(plane, (*this)[position]);

		(*this)[position - 1]->setNext(newPlanec);
	}

	counter_++;
}

// ������� ������� ����� ��������� �������� 
void ListPlane::insertAll(int position, Plane* arrPlanes, int size)
{
	// ���� �������� counter ������ ��� ����� ����
	if (size <= 0)
		throw exception("ListPlane: �������� n ��� ���������� ������� � ������ ������ ������ ���� ������ ����!");

	// ���� ��������� �� ������������ ������ ����� �������� nullptr
	if (arrPlanes == nullptr)
		throw exception("ListPlane: ������������� ������� �� ����������!");

	// ���������� ����� ������ 
	for (int i = 0, k = position; i < size; i++, k++)
	{
		insert(k, arrPlanes[i]);
	}
}

// ��������� �������� ���������� ���� 
void ListPlane::put(int position, Plane& plane)
{
	// ��������� ����������� ���� �� �������
	(*this)[position]->setPayload(plane);
}

// ��������� �������� ���������� ���� 
Plane ListPlane::get(int position) 
{
	return (*this)[position]->getPayload();
}

// �������� ���������� ���� �� ������ �� �������
void ListPlane::removeAtt(int position)
{
	// ���� ������ ���� 
	if (counter_ == 0)
		throw exception("ListPlane: ������ ����!");

	// ���� ��������� ������� ������ ����
	if (position < 0)
		throw exception("ListPlane: ��������� ������� ������ ���� ������ ����!");

	// ���� ��������� ������� ������ ������������ ������� � ������ 
	if (position >= counter_)
		throw exception("ListPlane: ��������� ������� ������ ������������ ������� � ������!");

	// ���� ������� 0
	if (position == 0)
	{
		// ��������� �� ������� ������ ������ 
		NodePlanec* node = head_;

		head_ = head_->getNext();

		delete node;
	}

	// ��������� �� ������� ������ ������ 
	NodePlanec* node = head_;

	// ����� ���� 
	for (int i = 0; i < position - 1; i++)
	{
		node = node->getNext();
	}

	// ��������� �� ��������� ������� 
	NodePlanec* delNode = node->getNext();

	// ��������� �������� ��������� �� ���� ��������� ����� ����������
	node->setNext(delNode->getNext());

	// �������� ������ �� ���������� ��������
	delete delNode;

	// ���������� �������� �����
	counter_--;
}

// �������� ������ 
void ListPlane::clear()
{
	// ���� ������ ���� 
	if (counter_ == 0) return;

	// ��������� �� ������� �������
	NodePlanec* node = head_;

	// ��������� �� ��������� �������
	NodePlanec* delNode;

	// �������� ���� ����� ����� 
	while (node != nullptr)
	{
		// �������� �� ��������� ������� �������� ������� ��������� 
		delNode = node;

		// ������� ������� �������� ���������� �� ��������� �������
		node = node->getNext();

		// �������� ��������
		delete delNode;
	}

	counter_ = 0;
	head_ = nullptr;
}

// ������ coutner_
// int ListPlane::getCounter() { return counter_; }

// ���������� �������� []
NodePlanec* ListPlane::operator[](int position)
{
	// ���� ������ ���� 
	if (counter_ == 0)
		throw exception("List: ������ ����!");

	// ���� ��������� ������� ������ ����
	if (position < 0)
		throw exception("List: ��������� ������� ������ ���� ������ ����!");

	// ���� ��������� ������� ������ ������������ ������� � ������ 
	if (position >= counter_)
		throw exception("List: ��������� ������� ������ ������������ ������� � ������!");

	NodePlanec* node = head_;

	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	return node;
}

// ���������� ������������ 
ListPlane& ListPlane::operator=(const ListPlane& listPlane)
{
	// �������� �������� ������ 
	clear();

	// ��������� �� ������� ���� ������ list
	NodePlanec* node = listPlane.head_;

	// ����������� �������� ���������
	while (node != nullptr)
	{
		// ���������� ���� ������ list � this ������
		add(node->getPayload());

		// ������� �� ��������� ���� ������ 
		node = node->getNext();
	}

	return *this;
}

#pragma endregion

// ���������� �������� ������ 
ostream& operator<<(ostream& os, const ListPlane& listPlane)
{
	os << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n"
		<< "|     ������    |  ��������. | ���������� | ����. �������� |     ���������     |  ��������� ����� |  ���������. ����� |\n"
		<< "|               |    ����    |            |     ��/�       |      �������     |      �������     |      �������     |\n"
		<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

	// ���� � �������� ��� ��������
	if (listPlane.counter_ == 0)
	{
		os << "|                                                    ��� ����˨���                                                     |\n"
			// ������ ������ 
			<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}
	
	NodePlanec* node = listPlane.head_;

	// ����� ��������
	for (int i = 0; i < listPlane.counter_; i++)
	{
		os << *node;

		// ������ ������ 
		os << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

		node = node->getNext();
	}

	return os;
}

// ����� � �����
void ListPlane::showListPlaneColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr)
{
	cout << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n"
		<< "|     ������    |  ��������. | ���������� | ����. �������� |     ���������     |  ��������� ����� |  ���������. ����� |\n"
		<< "|               |    ����    |            |     ��/�       |      �������     |      �������     |      �������     |\n"
		<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

	// ���� � �������� ��� ��������
	if (this->counter_ == 0)
	{
		cout << "|                                                    ��� ����˨���                                                     |\n"
			// ������ ������ 
			<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}

	NodePlanec* node = this->head_;

	// ���� �� ���������
	short cl = getColor();

	// ����� ��������
	for (int i = 0; i < this->counter_; i++)
	{
		cout << color(predicator(i, posArr, sizePosArr) ? GREEN_ON_BLACK : cl) << *node << color(cl);

		// ������ ������ 
		cout << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

		node = node->getNext();
	}
}

