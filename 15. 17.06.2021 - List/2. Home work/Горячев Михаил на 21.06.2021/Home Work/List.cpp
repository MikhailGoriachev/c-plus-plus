#include "List.h"
#include "Utils.h"

// ����������� ����������������
List::List(int counter) : head_()
{
	// ���� �������� counter ������ ��� ����� ����
	if (counter <= 0)
		throw exception("List: �������� counter ��� �������� � �������������� ������ ���� ������ ����!");

	// �������� ������ ������������ ������
	for (int i = 0; i < counter; i++)
	{
		add(0);
	}
}

// ����������� ��������� ������ �� ���� ������� 
List::List(int* arr, int counter)
{
	// ���� �������� counter ������ ��� ����� ����
	if (counter <= 0)
		throw exception("List: �������� counter ��� �������� � �������������� ������ ���� ������ ����!");

	// ���� ��������� �� ������������ ������ ����� �������� nullptr
	if (arr == nullptr)
		throw exception("List: ������������� ������� �� ����������!");

	// �������� ������ ������������ ������
	for (int i = 0; i < counter; i++)
	{
		add(arr[i]);
	}
}

// ����������� ����������
List::List(const List& list)
{
	// ����������� ���� counter_
	counter_ = list.counter_;

	// ��������� �� ������� ���� ������ list
	Node* node = list.head_;

	// ����������� �������� ���������
	while (node != nullptr)
	{
		// ���������� ���� ������ list � this ������
		add(node->getPayload());

		// ������� �� ��������� ���� ������ 
		node = node->getNext();
	}
}

// ���������� �������� ������������ 
List& List::operator=(const List& list)
{
	// �������� �������� ������ 
	clear();

	// ��������� �� ������� ���� ������ list
	Node* node = list.head_;

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

// ���������� ���� � ����� ������ 
void List::add(int value)
{
	// ����� ������ Node
	Node* newNode = new Node(value);

	// ���� ������ ����
	if (counter_ == 0)
	{
		// �������� ��������� �� ������ ���� ������ 
		head_ = newNode;

		// ����������� ������� ����� � ������
		counter_++;

		return;
	}

	// ������� �� ������� ������ ������ 
	Node* node = head_;

	// ���������� ���������� ���� � ������
	while (node->getNext() != nullptr)
	{
		node = node->getNext();
	}

	// ��������� ��������� � ���� next_ � ��������� ���� ������ 
	node->setNext(newNode);

	// ���������� �������� ����� � ������ 
	counter_++;
}

// ���������� ������� ����� � ����� ������ 
void List::addAll(int* data, int n)
{
	// ���� �������� counter ������ ��� ����� ����
	if (n <= 0)
		throw exception("List: �������� n ��� ���������� ������� � ����� ������ ������ ���� ������ ����!");

	// ���� ��������� �� ������������ ������ ����� �������� nullptr
	if (data == nullptr)
		throw exception("List: ������������� ������� �� ����������!");

	// ���������� ����� ������ 
	for (int i = 0; i < n; i++)
	{
		add(data[i]);
	}
}

// ������� ���� ����� ��������� ��������
void List::insert(int position, int value)
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

	// ��������� �� ������� ������
	if (position == 0)
	{
		Node* newNode = new Node(value, head_);
		head_ = newNode;
	}

	else
	{
		// ��������� �� ���� ������ 
		// Node* node = head_;

		// ����� ������� 
		// for (int i = 0; i < position - 1; i++)
		// {
		// 	node = node->getNext();
		// }

		Node* node = (*this)[position - 1];

		// �������� ������� Node � ���� next_ �������� ����� ���������� ��������� next_ �������� �������� 
		// ����� ��������� �� ����� ������� ����� �������� �������� ������� Node
		node->setNext(new Node(value, node->getNext()));
	}

	// ���������� �������� 
	counter_++;
}

// ������� ������� ����� ����� ��������� ��������
void List::insertAll(int position, int* data, int n)
{
	// ���� �������� counter ������ ��� ����� ����
	if (n <= 0)
		throw exception("List: �������� n ��� ���������� ������� � ������ ������ ������ ���� ������ ����!");

	// ���� ��������� �� ������������ ������ ����� �������� nullptr
	if (data == nullptr)
		throw exception("List: ������������� ������� �� ����������!");

	// ���������� ����� ������ 
	for (int i = 0, k = position; i < n; i++, k++)
	{
		insert(k, data[i]);
	}
}

// ������ �������� ���� ������ �� ��������� �������
int List::get(int position)
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

	// ��������� �� ������� ������ ������ 
	Node* node = head_;

	// ����� ���� 
	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	// ����������� ������� ���� �� ��������� �������
	return node->getPayload();
}

// �������� �������� ���� ������ �� ��������� ������� 
void List::put(int position, int value)
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

	// ��������� �� ������� ������ ������ 
	Node* node = head_;

	// ����� ���� 
	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	// ��������� �������� �� ��������� �������
	node->setPayload(value);
}

// �������� ���� �� ������ �� ��������� ������� 
void List::removeAt(int position)
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

	// ���� ������� 0
	if (position == 0)
	{
		// ��������� �� ������� ������ ������ 
		Node* node = head_;

		head_ = head_->getNext();

		delete node;
	}

	// ��������� �� ������� ������ ������ 
	Node* node = head_;

	// ����� ���� 
	for (int i = 0; i < position - 1; i++)
	{
		node = node->getNext();
	}

	// ��������� �� ��������� ������� 
	Node* delNode = node->getNext();

	// ��������� �������� ��������� �� ���� ��������� ����� ����������
	node->setNext(delNode->getNext());

	// �������� ������ �� ���������� ��������
	delete delNode;

	// ���������� �������� �����
	counter_--;
}

// �������� ������ 
void List::clear()
{
	// ���� ������ ���� 
	if (counter_ == 0)	return;

	// ��������� �� ������� �������
	Node* node = head_;

	// ��������� �� ��������� �������
	Node* delNode;

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

// ���������� �������� ������ 
ostream& operator<<(ostream& os, const List& list)
{
	// ����� �������������� ��������

	showCounter(os, list);

	// ���� ������� ����� 
	if (list.counter_ == 0)
	{
		os << "\t+��������������������������+\n"
			<< "\t|                          |\n"
			<< "\t|        ���� �����        |\n"
			<< "\t|                          |\n"
			<< "\t+��������������������������+\n";
	}

	else
	{
		showLine(os, list);

		showIndex(os, list);

		showLine(os, list);

		showElem(os, list);

		showLine(os, list);

	}

	return os;
}

// ����� �������������� �����
ostream& showLine(ostream& os, const List& list)
{
	int counter = list.counter_;

	// ����� �������������� ��������
	os << "\t+�����������������+";
	for (size_t i = 0; i < counter; i++)
	{
		os << "��������+";
	}

	os << "\n";

	return os;
}

// ����� ������� ���������
ostream& showIndex(ostream& os, const List& list)
{
	int counter = list.counter_;

	os << "\t|      ������     |";

	for (size_t i = 0; i < counter; i++)
	{
		os << "   " << setw(3) << i << "  |";
	}

	os << "\n";

	return os;
}

// ����� ���������
ostream& showElem(ostream& os, const List& list)
{
	int counter = list.counter_;

	os << "\t|    ����������   |";

	// ��������� �� ������� ����
	Node* node = list.head_;

	while (node != nullptr)
	{
		os << " " << setw(7) << node->getPayload() << "|";

		node = node->getNext();
	}

	os << "\n";

	return os;
}

// ����� ���������� ���������
ostream& showCounter(ostream& os, const List& list)
{
	os << "\t+��������������������������+\n"
		<< "\t| ���������� ���������: " << setw(2) << list.counter_ << " |\n";

	return os;
}

// ���������� �������� [] ��� ������� � ���� ������ �� �������
Node* List::operator[](int position)
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

	Node* node = head_;

	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	return node;
}

// ����� ��������� � �����
void List::showListColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr)
{
	stringstream os;

	showCounter(os, *this);

	// ���� ������� ����� 
	if (counter_ == 0)
	{
		os << "\t+��������������������������+\n"
			<< "\t|                          |\n"
			<< "\t|        ���� �����        |\n"
			<< "\t|                          |\n"
			<< "\t+��������������������������+\n";
	}

	else
	{
		showLine(os, *this);

		showIndex(os, *this);

		showLine(os, *this);

		cout << os.str();

		showElemColor(predicator, posArr, sizePosArr);

		os.str("");

		showLine(os, *this);

		cout << os.str() << "\n";
	}
}

// ����� ��������� � �����
void List::showElemColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr)
{
	int counter = counter_;

	cout << "\t|    ����������   |";

	// ��������� �� ������� ����
	Node* node = head_;

	// ���� �� ���������
	short cl = getColor();

	// ����� ��������� � �����
	for (int i = 0; node != nullptr; i++)
	{
		cout << color(predicator(i, posArr, sizePosArr) ? GREEN_ON_BLACK : cl) << " " << setw(6) << node->getPayload() << color(cl) << " |";

		node = node->getNext();
	}

	cout << "\n";
}

#pragma endregion