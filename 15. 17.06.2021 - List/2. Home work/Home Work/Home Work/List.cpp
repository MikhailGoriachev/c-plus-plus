#include "List.h"
#include "Utils.h"

// конструктор инициализирующий
List::List(int counter) : head_()
{
	// если значение counter меньше или равно нулю
	if (counter <= 0)
		throw exception("List: Значение counter при создании с инициализацией должно быть больше нуля!");

	// создание списка заполненного нулями
	for (int i = 0; i < counter; i++)
	{
		add(0);
	}
}

// конструктор создающий список на базе массива 
List::List(int* arr, int counter)
{
	// если значение counter меньше или равно нулю
	if (counter <= 0)
		throw exception("List: Значение counter при создании с инициализацией должно быть больше нуля!");

	// если указатель на передаваемый массив имеет значение nullptr
	if (arr == nullptr)
		throw exception("List: Передаваемого массива не существует!");

	// создание списка заполненного нулями
	for (int i = 0; i < counter; i++)
	{
		add(arr[i]);
	}
}

// конструктор копирующий
List::List(const List& list)
{
	// копирование поля counter_
	counter_ = list.counter_;

	// указатель на текущий узел списка list
	Node* node = list.head_;

	// копирование значений элементов
	while (node != nullptr)
	{
		// добавление узла списка list в this список
		add(node->getPayload());

		// переход на следующий узел списка 
		node = node->getNext();
	}
}

// перегрузка операции присваивания 
List& List::operator=(const List& list)
{
	// отчистка текущего списка 
	clear();

	// указатель на текущий узел списка list
	Node* node = list.head_;

	// копирование значений элементов
	while (node != nullptr)
	{
		// добавление узла списка list в this список
		add(node->getPayload());

		// переход на следующий узел списка 
		node = node->getNext();
	}

	return *this;
}

// добавление узла в конец списка 
void List::add(int value)
{
	// новый объект Node
	Node* newNode = new Node(value);

	// если список пуст
	if (counter_ == 0)
	{
		// изменяем указатель на первый узел списка 
		head_ = newNode;

		// увеличиваем счётчик узлов в списке
		counter_++;

		return;
	}

	// укатель на текущий объект списка 
	Node* node = head_;

	// нахождение последнего узла в списке
	while (node->getNext() != nullptr)
	{
		node = node->getNext();
	}

	// установка указателя в поле next_ в последнем узле списка 
	node->setNext(newNode);

	// увеличение счётчика узлов в списке 
	counter_++;
}

// добавление массива узлов в конец списка 
void List::addAll(int* data, int n)
{
	// если значение counter меньше или равно нулю
	if (n <= 0)
		throw exception("List: Значение n при добавлении массива в конец списка должно быть больше нуля!");

	// если указатель на передаваемый массив имеет значение nullptr
	if (data == nullptr)
		throw exception("List: Передаваемого массива не существует!");

	// добавление узлов списка 
	for (int i = 0; i < n; i++)
	{
		add(data[i]);
	}
}

// вставка узла перед указанной позицией
void List::insert(int position, int value)
{
	// если список пуст 
	if (counter_ == 0)
		throw exception("List: Список пуст!");

	// если указанная позиция меньше нуля
	if (position < 0)
		throw exception("List: Указанная позиция должна быть больше нуля!");

	// если указанная позиция больше максимальной позиции в списке 
	if (position >= counter_)
		throw exception("List: Указанная позиция больше максимальной позиции в списке!");

	// установка на нулевую поицию
	if (position == 0)
	{
		Node* newNode = new Node(value, head_);
		head_ = newNode;
	}

	else
	{
		// указатель на узел списка 
		// Node* node = head_;

		// поиск позиции 
		// for (int i = 0; i < position - 1; i++)
		// {
		// 	node = node->getNext();
		// }

		Node* node = (*this)[position - 1];

		// создание объекта Node в поле next_ которого будет скопирован указатель next_ текущего элемента 
		// затем указатель на новый элемент будет присвоен текущему объекту Node
		node->setNext(new Node(value, node->getNext()));
	}

	// увеличение счётчика 
	counter_++;
}

// вставка массива узлов перед указанной позицией
void List::insertAll(int position, int* data, int n)
{
	// если значение counter меньше или равно нулю
	if (n <= 0)
		throw exception("List: Значение n при добавлении массива в начало списка должно быть больше нуля!");

	// если указатель на передаваемый массив имеет значение nullptr
	if (data == nullptr)
		throw exception("List: Передаваемого массива не существует!");

	// добавление узлов списка 
	for (int i = 0, k = position; i < n; i++, k++)
	{
		insert(k, data[i]);
	}
}

// чтение значения узла списка по указанной позиции
int List::get(int position)
{
	// если список пуст 
	if (counter_ == 0)
		throw exception("List: Список пуст!");

	// если указанная позиция меньше нуля
	if (position < 0)
		throw exception("List: Указанная позиция должна быть больше нуля!");

	// если указанная позиция больше максимальной позиции в списке 
	if (position >= counter_)
		throw exception("List: Указанная позиция больше максимальной позиции в списке!");

	// указатель на текущий объект списка 
	Node* node = head_;

	// поиск узла 
	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	// возвращение значеня узла по указанной позиции
	return node->getPayload();
}

// изенение значения узла списка по указанной позиции 
void List::put(int position, int value)
{
	// если список пуст 
	if (counter_ == 0)
		throw exception("List: Список пуст!");

	// если указанная позиция меньше нуля
	if (position < 0)
		throw exception("List: Указанная позиция должна быть больше нуля!");

	// если указанная позиция больше максимальной позиции в списке 
	if (position >= counter_)
		throw exception("List: Указанная позиция больше максимальной позиции в списке!");

	// указатель на текущий объект списка 
	Node* node = head_;

	// поиск узла 
	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	// установка значения по указанной позиции
	node->setPayload(value);
}

// удаление узла из списка по указанной позиции 
void List::removeAt(int position)
{
	// если список пуст 
	if (counter_ == 0)
		throw exception("List: Список пуст!");

	// если указанная позиция меньше нуля
	if (position < 0)
		throw exception("List: Указанная позиция должна быть больше нуля!");

	// если указанная позиция больше максимальной позиции в списке 
	if (position >= counter_)
		throw exception("List: Указанная позиция больше максимальной позиции в списке!");

	// если позиция 0
	if (position == 0)
	{
		// указатель на текущий объект списка 
		Node* node = head_;

		head_ = head_->getNext();

		delete node;
	}

	// указатель на текущий объект списка 
	Node* node = head_;

	// поиск узла 
	for (int i = 0; i < position - 1; i++)
	{
		node = node->getNext();
	}

	// указатель на удаляемый элемент 
	Node* delNode = node->getNext();

	// установка значения указателя на узел следующий после следующего
	node->setNext(delNode->getNext());

	// отчистка памяти от удаляемого элемента
	delete delNode;

	// уменьшение счётчика узлов
	counter_--;
}

// отчистка списка 
void List::clear()
{
	// если список пуст 
	if (counter_ == 0)	return;

	// указатель на текущий элемент
	Node* node = head_;

	// указатель на удаляемый элемент
	Node* delNode;

	// удаление всех узлов списк 
	while (node != nullptr)
	{
		// укзатель на удаляемый элемент является текущим элементом 
		delNode = node;

		// текущий элемент является указателем на слелующий элемент
		node = node->getNext();

		// удаление элемента
		delete delNode;
	}

	counter_ = 0;
	head_ = nullptr;
}

// перегрузка операции вывода 
ostream& operator<<(ostream& os, const List& list)
{
	// ВЫВОД ГОРИЗОНТАЛЬНОЙ ТАБЛИЦЕЙ

	showCounter(os, list);

	// если очередь пуста 
	if (list.counter_ == 0)
	{
		os << "\t+——————————————————————————+\n"
			<< "\t|                          |\n"
			<< "\t|        ЛИСТ ПУСТА        |\n"
			<< "\t|                          |\n"
			<< "\t+——————————————————————————+\n";
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

// вывод горизонтальной линии
ostream& showLine(ostream& os, const List& list)
{
	int counter = list.counter_;

	// ВЫВОД ГОРИЗОНТАЛЬНОЙ ТАБЛИЦЕЙ
	os << "\t+—————————————————+";
	for (size_t i = 0; i < counter; i++)
	{
		os << "————————+";
	}

	os << "\n";

	return os;
}

// вывод индекса элементов
ostream& showIndex(ostream& os, const List& list)
{
	int counter = list.counter_;

	os << "\t|      Индекс     |";

	for (size_t i = 0; i < counter; i++)
	{
		os << "   " << setw(3) << i << "  |";
	}

	os << "\n";

	return os;
}

// вывод элементов
ostream& showElem(ostream& os, const List& list)
{
	int counter = list.counter_;

	os << "\t|    Содержание   |";

	// указатель на текущий узел
	Node* node = list.head_;

	while (node != nullptr)
	{
		os << " " << setw(7) << node->getPayload() << "|";

		node = node->getNext();
	}

	os << "\n";

	return os;
}

// вывод количества элементов
ostream& showCounter(ostream& os, const List& list)
{
	os << "\t+——————————————————————————+\n"
		<< "\t| Количество элементов: " << setw(2) << list.counter_ << " |\n";

	return os;
}

// перегрузка операции [] для доступа к узлу списка по индексу
Node* List::operator[](int position)
{
	// если список пуст 
	if (counter_ == 0)
		throw exception("List: Список пуст!");

	// если указанная позиция меньше нуля
	if (position < 0)
		throw exception("List: Указанная позиция должна быть больше нуля!");

	// если указанная позиция больше максимальной позиции в списке 
	if (position >= counter_)
		throw exception("List: Указанная позиция больше максимальной позиции в списке!");

	Node* node = head_;

	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	return node;
}

// вывод элементов в цвете
void List::showListColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr)
{
	stringstream os;

	showCounter(os, *this);

	// если очередь пуста 
	if (counter_ == 0)
	{
		os << "\t+——————————————————————————+\n"
			<< "\t|                          |\n"
			<< "\t|        ЛИСТ ПУСТА        |\n"
			<< "\t|                          |\n"
			<< "\t+——————————————————————————+\n";
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

// вывод элементов в цвете
void List::showElemColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr)
{
	int counter = counter_;

	cout << "\t|    Содержание   |";

	// указатель на текущий узел
	Node* node = head_;

	// цвет по умолчанию
	short cl = getColor();

	// вывод элементов в цвете
	for (int i = 0; node != nullptr; i++)
	{
		cout << color(predicator(i, posArr, sizePosArr) ? GREEN_ON_BLACK : cl) << " " << setw(6) << node->getPayload() << color(cl) << " |";

		node = node->getNext();
	}

	cout << "\n";
}

#pragma endregion