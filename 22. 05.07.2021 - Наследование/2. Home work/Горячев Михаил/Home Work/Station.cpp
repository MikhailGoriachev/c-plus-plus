#include "Station.h"

// ������������ ����� �� ������ ���������
const float Station::RATE_MAX = 100.;

// ����������� ����� �� ������ ���������
const float Station::RATE_MIN = 0.;

// ����� �� ������
BinaryTree<Subscriber>::NodeTree<Subscriber>* Station::find(const char* number)
{
	// ��������� ������� ��� ������
	Subscriber tmp;

	// ��������� ������
	tmp.setNumber(number);

	// ����� �� ������
	return subscribers_.find(tmp);
}

// ����� ��������� ������ � ��������� Subscriber � �����
void Station::printSubscriberColor()
{
	Subscriber::showHead();

	BinaryTree<Subscriber>::NodeTree<Subscriber>* node = subscribers_.getRoot();

	// ���� � ������ ��� ������
	if (node == nullptr)
		Subscriber::showEmpty();

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		// ����� ������ � �����
		this->showColor(node, cl, i);
	}

	Subscriber::showLine();
}

// ����� ����� ������ ��� ������ � ����� �������� Subscriber
void Station::showColor(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i)
{
	// ���� ������� ���� �������� nullptr
	if (node == nullptr) return;

	// ����������� �� ������ ���������
	showColor(node->getLeft(), cl, i);

	// ������ ��������  �����
	node->getData().showElem(i++);

	// ����������� �� ������� ���������
	showColor(node->getRight(), cl, i);
}

// ����� ��������� ������ � ��������� Subscriber � ������ �������� �������
void Station::printSubscriberColorBack()
{
	Subscriber::showHead();

	BinaryTree<Subscriber>::NodeTree<Subscriber>* node = subscribers_.getRoot();

	// ���� � ������ ��� ������
	if (node == nullptr)
		Subscriber::showEmpty();

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		// ����� ������ � �����
		this->showColorBack(node, cl, i);
	}

	Subscriber::showLine();
}

// ����� ����� ������ ��� ������ � ����� �������� Subscriber � �������� �������
void Station::showColorBack(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i)
{
	// ���� ������� ���� �������� nullptr
	if (node == nullptr) return;

	// ����������� �� ������ ���������
	showColor(node->getRight(), cl, i);

	// ������ ��������  �����
	node->getData().showElem(i++);

	// ����������� �� ������� ���������
	showColor(node->getLeft(), cl, i);
}

// ����� ��������� ������ � ��������� Subscriber � ����� � �������
void Station::showColorPrice(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i, float& rate)
{
	// ���� ������� ���� �������� nullptr
	if (node == nullptr) return;

	// ����������� �� ������ ���������
	showColorPrice(node->getLeft(), cl, i, rate);

	Subscriber tmp = node->getData();

	// ������ ��������  �����
	cout << right << "\t| " << setw(2) << i++
		<< left << " | " << setw(Subscriber::OWNER_MAX_SIZE - 20)
		<< color(YELLOW_ON_BLACK) << tmp.getOwner()
		<< color(cl) << " | "
		<< setw(Subscriber::NUMBER_SIZE)
		<< color(YELLOW_ON_BLACK) << tmp.getNumber()
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << right << setw(16) << tmp.getMinute()
		<< color(cl) << " | "
		<< color(GREEN_ON_BLACK) << setw(10) << tmp.price(rate) << color(cl) << " |\n" << left;

	// ����������� �� ������� ���������
	showColorPrice(node->getRight(), cl, i, rate);
}

// ����� ��������� ������ � ��������� Subscriber � �����
// � ������ � ������
void Station::printSubscriberColorPrice()
{

	cout << "\t+����+����������������������+������������+������������������+������������+\n"
			"\t| N  |       ��������       |    �����   | ����� ���������� |    �����   |\n"
			"\t|    |                      |            |     (������)     |    (���)   |\n"
			"\t+����+����������������������+������������+������������������+������������+\n";


	BinaryTree<Subscriber>::NodeTree<Subscriber>* node = subscribers_.getRoot();

	// ���� � ������ ��� ������
	if (node == nullptr)
		cputs("\t|                              ��� ������                                |\n", RED_ON_BLACK);

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		// ����� ������ � �����
		this->showColorPrice(node, cl, i, rate_);
	}

	cout << "\t+����+����������������������+������������+������������������+������������+\n";

}