#include "BinaryTree.h"
#include "Utils.h"
#include "Form.h"
#include "Station.h"

/*// ����� ��������� ������ � ��������� Form � �����
void printBinaryTreeFormColor(BinaryTree<Form>& binaryTree)
{
	cout << Form::showHead();

	// ���� � ������ ��� ������
	if (binaryTree.isEmpty())
		cputs("\t|                                               ��� ������                                                |\n", RED_ON_BLACK);

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		cout << fixed;
		cout.precision(2);

		// ����� ������ � �����
		binaryTree.showFormColor(binaryTree.root_, cl, i);
	}

	cout << Form::showLine();

}

// ����� ��������� ������ � ��������� Subscriber � �����
void printSubscriberColor(BinaryTree<Subscriber>& binaryTree)
{
	Subscriber::showHead();

	// ���� � ������ ��� ������
	if (binaryTree.isEmpty())
		Subscriber::showEmpty();

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		BinaryTree<Subscriber>* bin = &binaryTree;

		// ����� ������ � �����
		bin->showSubscriberColor(bin->root_, cl, i);
	}

	Subscriber::showLine();
}
*/
// ����� ��������� ������ � ��������� Subscriber � �����
// � ������ � ������
/*void printSubscriberColorPrice(BinaryTree<Subscriber>& binaryTree, Station& station)
{
	cout << "\t+������������+������������+\n"
		<< "\t|    �����   |    �����   |\n"
		<< "\t|            |    (���)   |\n"
		<< "\t+������������+������������+\n";

	// ���� � ������ ��� ������
	if (binaryTree.isEmpty())
		cputs("\t|       ��� ������      |\n", RED_ON_BLACK);

	else
	{
		// ���� �� ���������
		short cl = getColor();

		// ����� ��������
		int i = 1;

		BinaryTree<Subscriber>* bin = &binaryTree;

		// ����� ������ � �����
		bin->showSubscriberColorPrice(bin->root_, cl, i, station);
	}

}*/

