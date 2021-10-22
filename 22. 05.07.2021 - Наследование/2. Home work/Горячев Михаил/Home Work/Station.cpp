#include "Station.h"

// максимальный тариф за минуту разговора
const float Station::RATE_MAX = 100.;

// минимальный тариф за минуту разговора
const float Station::RATE_MIN = 0.;

// поиск по номеру
BinaryTree<Subscriber>::NodeTree<Subscriber>* Station::find(const char* number)
{
	// временный элемент для поиска
	Subscriber tmp;

	// установка номера
	tmp.setNumber(number);

	// поиск по номеру
	return subscribers_.find(tmp);
}

// вывод бинарного дерева с объектами Subscriber в цвете
void Station::printSubscriberColor()
{
	Subscriber::showHead();

	BinaryTree<Subscriber>::NodeTree<Subscriber>* node = subscribers_.getRoot();

	// если в дереве нет данных
	if (node == nullptr)
		Subscriber::showEmpty();

	else
	{
		// цвет по умолчанию
		short cl = getColor();

		// номер элемента
		int i = 1;

		// вывод дерева в цвете
		this->showColor(node, cl, i);
	}

	Subscriber::showLine();
}

// обход узлов дерева для вывода в цвете объектов Subscriber
void Station::showColor(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i)
{
	// если текущий узел является nullptr
	if (node == nullptr) return;

	// прохождение по левому поддереву
	showColor(node->getLeft(), cl, i);

	// вывода элемента  цвете
	node->getData().showElem(i++);

	// прохождение по правому поддереву
	showColor(node->getRight(), cl, i);
}

// вывод бинарного дерева с объектами Subscriber в цветеВ ОБРАТНОМ ПОРЯДКЕ
void Station::printSubscriberColorBack()
{
	Subscriber::showHead();

	BinaryTree<Subscriber>::NodeTree<Subscriber>* node = subscribers_.getRoot();

	// если в дереве нет данных
	if (node == nullptr)
		Subscriber::showEmpty();

	else
	{
		// цвет по умолчанию
		short cl = getColor();

		// номер элемента
		int i = 1;

		// вывод дерева в цвете
		this->showColorBack(node, cl, i);
	}

	Subscriber::showLine();
}

// обход узлов дерева для вывода в цвете объектов Subscriber В ОБРАТНОМ ПОРЯДКЕ
void Station::showColorBack(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i)
{
	// если текущий узел является nullptr
	if (node == nullptr) return;

	// прохождение по левому поддереву
	showColor(node->getRight(), cl, i);

	// вывода элемента  цвете
	node->getData().showElem(i++);

	// прохождение по правому поддереву
	showColor(node->getLeft(), cl, i);
}

// вывод бинарного дерева с объектами Subscriber в цвете с оплатой
void Station::showColorPrice(BinaryTree<Subscriber>::NodeTree<Subscriber>* node, short cl, int& i, float& rate)
{
	// если текущий узел является nullptr
	if (node == nullptr) return;

	// прохождение по левому поддереву
	showColorPrice(node->getLeft(), cl, i, rate);

	Subscriber tmp = node->getData();

	// вывода элемента  цвете
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

	// прохождение по правому поддереву
	showColorPrice(node->getRight(), cl, i, rate);
}

// вывод бинарного дерева с объектами Subscriber в цвете
// с суммой к оплате
void Station::printSubscriberColorPrice()
{

	cout << "\t+————+——————————————————————+————————————+——————————————————+————————————+\n"
			"\t| N  |       Владелец       |    Номер   | Время разговоров |    Сумма   |\n"
			"\t|    |                      |            |     (минута)     |    (руб)   |\n"
			"\t+————+——————————————————————+————————————+——————————————————+————————————+\n";


	BinaryTree<Subscriber>::NodeTree<Subscriber>* node = subscribers_.getRoot();

	// если в дереве нет данных
	if (node == nullptr)
		cputs("\t|                              НЕТ ДАННЫХ                                |\n", RED_ON_BLACK);

	else
	{
		// цвет по умолчанию
		short cl = getColor();

		// номер элемента
		int i = 1;

		// вывод дерева в цвете
		this->showColorPrice(node, cl, i, rate_);
	}

	cout << "\t+————+——————————————————————+————————————+——————————————————+————————————+\n";

}