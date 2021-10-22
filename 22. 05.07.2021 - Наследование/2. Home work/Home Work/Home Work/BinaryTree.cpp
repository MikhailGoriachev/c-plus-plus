#include "BinaryTree.h"
#include "Utils.h"
#include "Form.h"
#include "Station.h"

/*// вывод бинарного дерева с объектами Form в цвете
void printBinaryTreeFormColor(BinaryTree<Form>& binaryTree)
{
	cout << Form::showHead();

	// если в дереве нет данных
	if (binaryTree.isEmpty())
		cputs("\t|                                               НЕТ ДАННЫХ                                                |\n", RED_ON_BLACK);

	else
	{
		// цвет по умолчанию
		short cl = getColor();

		// номер элемента
		int i = 1;

		cout << fixed;
		cout.precision(2);

		// вывод дерева в цвете
		binaryTree.showFormColor(binaryTree.root_, cl, i);
	}

	cout << Form::showLine();

}

// вывод бинарного дерева с объектами Subscriber в цвете
void printSubscriberColor(BinaryTree<Subscriber>& binaryTree)
{
	Subscriber::showHead();

	// если в дереве нет данных
	if (binaryTree.isEmpty())
		Subscriber::showEmpty();

	else
	{
		// цвет по умолчанию
		short cl = getColor();

		// номер элемента
		int i = 1;

		BinaryTree<Subscriber>* bin = &binaryTree;

		// вывод дерева в цвете
		bin->showSubscriberColor(bin->root_, cl, i);
	}

	Subscriber::showLine();
}
*/
// вывод бинарного дерева с объектами Subscriber в цвете
// с суммой к оплате
/*void printSubscriberColorPrice(BinaryTree<Subscriber>& binaryTree, Station& station)
{
	cout << "\t+————————————+————————————+\n"
		<< "\t|    Номер   |    Сумма   |\n"
		<< "\t|            |    (руб)   |\n"
		<< "\t+————————————+————————————+\n";

	// если в дереве нет данных
	if (binaryTree.isEmpty())
		cputs("\t|       НЕТ ДАННЫХ      |\n", RED_ON_BLACK);

	else
	{
		// цвет по умолчанию
		short cl = getColor();

		// номер элемента
		int i = 1;

		BinaryTree<Subscriber>* bin = &binaryTree;

		// вывод дерева в цвете
		bin->showSubscriberColorPrice(bin->root_, cl, i, station);
	}

}*/

