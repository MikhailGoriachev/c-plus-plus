#include "List.h"

List::List(const List& list)
{
	
} // List::List

List& List::operator=(const List& list)
{
	return *this;
} // List::operator=


// CRUD - create read update delete
// C - create: добавление узла в список
// добавление в конец списка
void List::add(int value)
{
	// новый узел списка
	Node* newNode = new Node(value);
	
	// добавление в пустой список
	if (counter_ == 0) {
		head_ = newNode;  // настроили голову на новый узел
		counter_++;
		return;
	} // if
	
	// добавление в не пустой список
	// дойти до последнего узла в списке (у него next_ == nuulptr)
	Node* node = head_;
	while (node->getNext() != nullptr)
		node = node->getNext();

	// настроить последний узел - он будет указывать на новый узел
	node->setNext(newNode);
	counter_++;
} // List::add

// вставка перед заданной позицией
void List::insert(int position, int value)
{
	
} // List::insert

// R - read: чтение значения узла списка
int List::get(int position)
{
	if (counter_ == 0 || position > counter_)
		throw exception("Некорректная позиция");

	// переход в заданную позицию
	Node* node = head_;
	for (int i = 0; i < position; ++i) {
		node = node->getNext();
	}

	// вернуть значение из этой позиции
	return node->getPayload();
} // List::get

// U - update: запись значения в узел списка
void List::put(int position, int value)
{
	if (counter_ == 0 || position > counter_)
		throw exception("Некорректная позиция");

	// переход в заданную позицию
	Node* node = head_;
	for (int i = 0; i < position; ++i) {
		node = node->getNext();
	}

	// записать значение в позиции
	node->setPayload(value);
} // List::put

// D - delete: удаление узла списка
void List::removeAt(int position)
{
	if (counter_ == 0 || position > counter_)
		throw exception("Некорректная позиция");

	// переход в позицию, перед заданной
	Node* node = head_;
	for (int i = 0; i < position-1; ++i) {
		node = node->getNext();
	}

	// адрес удаляемого элемента
	Node* temp = node->getNext();

	// связь элемента перед удаляемым с элементом после
	// удаляемого
	node->setNext(temp->getNext());

	// удаление элемента в заданной позиции
	delete temp;
} // List::removeAt


// очистка списка
void List::clear()
{
	if (counter_ == 0) return;

	Node* node = head_;
	while (node != nullptr) {
		Node* next = node->getNext();
		delete node;
		node = next;
	} // while

	counter_ = 0;
	head_ = nullptr;
} // List::clear

// вывод списка
ostream& operator<<(ostream& os, const List& list)
{
	if (list.counter_ == 0)
		os << "список пуст";
	else {
		// выводим все узлы списка
		Node* node = list.head_;
		while (node != nullptr) {
			os << setw(3) << node->getPayload() << " --> ";
			node = node->getNext();
		} // while
		os << "X";
	} // if

	return os;
} // operator<<