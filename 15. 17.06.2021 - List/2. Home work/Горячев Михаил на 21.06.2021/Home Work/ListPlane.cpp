#include "ListPlane.h"
#include "Utils.h"

#pragma region Конуструкторы и деструктор 

// конструктор инициализирующий
ListPlane::ListPlane(int counter)
{
	// если значение counter меньше или равно нулю
	if (counter <= 0)
		throw exception("ListPlane: Значение counter при создании с инициализацией должно быть больше нуля!");

	// объект Plane 
	Plane plane;

	for (int i = 0; i < counter; i++)
	{
		add(plane);
	}
}

// конструктор создающий список на базе массива 
ListPlane::ListPlane(Plane* arr, int counter)
{
	// если значение counter меньше или равно нулю
	if (counter <= 0)
		throw exception("ListPlane: Значение counter при создании с инициализацией должно быть больше нуля!");

	// если указатель на передаваемый массив имеет значение nullptr
	if (arr == nullptr)
		throw exception("ListPlane: Передаваемого массива не существует!");
	
	for (int i = 0; i < counter; i++)
	{
		add(arr[i]);
	}
}

// конструктор копирующий
ListPlane::ListPlane(const ListPlane& listPlane)
{
	// копирование поля coutner_
	counter_ = listPlane.counter_;

	// указатель на объект NodePlanec
	NodePlanec* node = listPlane.head_;

	while (node != nullptr)
	{
		add(node->getPayload());

		node = node->getNext();
	}
}

#pragma endregion

#pragma region Методы

// добавление узла в конец списка 
void ListPlane::add(Plane plane)
{
	// объект NodePlanec
	NodePlanec* newNode = new NodePlanec(plane);

	// если coutner_ равен нулю
	if (counter_ == 0)
	{
		// изменение указателя на первый узел списка 
		head_ = newNode;

		// увеличение количества элементов списка 
		counter_++;

		return;
	}

	// указатель на текущий узел списка NodePlanec
	NodePlanec* node = head_;

	// поиск последнего узла списка 
	while (node->getNext() != nullptr)
	{
		node = node->getNext();
	}

	// изменение поля next_ в последнем узле списка 
	node->setNext(newNode);

	// увеличение количества элементов списка 
	counter_++;
}

// добавление массива в конец списка 
void ListPlane::addAll(Plane* arrPlanes, int size)
{
	// если значение counter меньше или равно нулю
	if (size <= 0)
		throw exception("ListPlane: Значение n при добавлении массива в конец списка должно быть больше нуля!");

	// если указатель на передаваемый массив имеет значение nullptr
	if (arrPlanes == nullptr)
		throw exception("ListPlane: Передаваемого массива не существует!");

	for (int i = 0; i < size; i++)
	{
		add(arrPlanes[i]);
	}
}

// вставка перед указанной позицией
void ListPlane::insert(int position, Plane& plane)
{
	// если список пуст 
	if (counter_ == 0)
		throw exception("ListPlane: Список пуст!");

	// если указанная позиция меньше нуля
	if (position < 0)
		throw exception("ListPlane: Указанная позиция должна быть больше нуля!");

	// если указанная позиция больше максимальной позиции в списке 
	if (position >= counter_)
		throw exception("ListPlane: Указанная позиция больше максимальной позиции в списке!");


	// вставка на нулевую позицию
	if (position == 0)
	{
		// объект NodePlanec
		NodePlanec* newPlanec = new NodePlanec(plane, head_);

		// изменение head_
		head_ = newPlanec;
	}

	else
	{
		// объект NodePlanec
		NodePlanec* newPlanec = new NodePlanec(plane, (*this)[position]);

		(*this)[position - 1]->setNext(newPlanec);
	}

	counter_++;
}

// вставка массива перед указанной позицией 
void ListPlane::insertAll(int position, Plane* arrPlanes, int size)
{
	// если значение counter меньше или равно нулю
	if (size <= 0)
		throw exception("ListPlane: Значение n при добавлении массива в начало списка должно быть больше нуля!");

	// если указатель на передаваемый массив имеет значение nullptr
	if (arrPlanes == nullptr)
		throw exception("ListPlane: Передаваемого массива не существует!");

	// добавление узлов списка 
	for (int i = 0, k = position; i < size; i++, k++)
	{
		insert(k, arrPlanes[i]);
	}
}

// изменение значения указанного узла 
void ListPlane::put(int position, Plane& plane)
{
	// изменение содержимого узла по позиции
	(*this)[position]->setPayload(plane);
}

// получение значения указанного узла 
Plane ListPlane::get(int position) 
{
	return (*this)[position]->getPayload();
}

// удаление указанного узла из списка по позиции
void ListPlane::removeAtt(int position)
{
	// если список пуст 
	if (counter_ == 0)
		throw exception("ListPlane: Список пуст!");

	// если указанная позиция меньше нуля
	if (position < 0)
		throw exception("ListPlane: Указанная позиция должна быть больше нуля!");

	// если указанная позиция больше максимальной позиции в списке 
	if (position >= counter_)
		throw exception("ListPlane: Указанная позиция больше максимальной позиции в списке!");

	// если позиция 0
	if (position == 0)
	{
		// указатель на текущий объект списка 
		NodePlanec* node = head_;

		head_ = head_->getNext();

		delete node;
	}

	// указатель на текущий объект списка 
	NodePlanec* node = head_;

	// поиск узла 
	for (int i = 0; i < position - 1; i++)
	{
		node = node->getNext();
	}

	// указатель на удаляемый элемент 
	NodePlanec* delNode = node->getNext();

	// установка значения указателя на узел следующий после следующего
	node->setNext(delNode->getNext());

	// отчистка памяти от удаляемого элемента
	delete delNode;

	// уменьшение счётчика узлов
	counter_--;
}

// отчистка списка 
void ListPlane::clear()
{
	// если список пуст 
	if (counter_ == 0) return;

	// указатель на текущий элемент
	NodePlanec* node = head_;

	// указатель на удаляемый элемент
	NodePlanec* delNode;

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

// геттер coutner_
// int ListPlane::getCounter() { return counter_; }

// перегрузка операции []
NodePlanec* ListPlane::operator[](int position)
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

	NodePlanec* node = head_;

	for (int i = 0; i < position; i++)
	{
		node = node->getNext();
	}

	return node;
}

// перегрузка присваивания 
ListPlane& ListPlane::operator=(const ListPlane& listPlane)
{
	// отчистка текущего списка 
	clear();

	// указатель на текущий узел списка list
	NodePlanec* node = listPlane.head_;

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

#pragma endregion

// перегрузка операции вывода 
ostream& operator<<(ostream& os, const ListPlane& listPlane)
{
	os << "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n"
		<< "|     Модель    |  Пассажир. | Пассажиров | Расх. горючего |     Стоимость     |  Дальность полёта |  Регистрис. номер |\n"
		<< "|               |    мест    |            |     кг/ч       |      самолёта     |      самолёта     |      самолёта     |\n"
		<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";

	// если в компании нет самолётов
	if (listPlane.counter_ == 0)
	{
		os << "|                                                    НЕТ САМОЛЁТОВ                                                     |\n"
			// нижняя строка 
			<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";
	}
	
	NodePlanec* node = listPlane.head_;

	// вывод самолётов
	for (int i = 0; i < listPlane.counter_; i++)
	{
		os << *node;

		// нижняя строка 
		os << "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";

		node = node->getNext();
	}

	return os;
}

// вывод в цвете
void ListPlane::showListPlaneColor(bool predicator(int currentPosition, int* posArr, int sizePosArr), int* posArr, int sizePosArr)
{
	cout << "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n"
		<< "|     Модель    |  Пассажир. | Пассажиров | Расх. горючего |     Стоимость     |  Дальность полёта |  Регистрис. номер |\n"
		<< "|               |    мест    |            |     кг/ч       |      самолёта     |      самолёта     |      самолёта     |\n"
		<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";

	// если в компании нет самолётов
	if (this->counter_ == 0)
	{
		cout << "|                                                    НЕТ САМОЛЁТОВ                                                     |\n"
			// нижняя строка 
			<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";
	}

	NodePlanec* node = this->head_;

	// цвет по умолчанию
	short cl = getColor();

	// вывод самолётов
	for (int i = 0; i < this->counter_; i++)
	{
		cout << color(predicator(i, posArr, sizePosArr) ? GREEN_ON_BLACK : cl) << *node << color(cl);

		// нижняя строка 
		cout << "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";

		node = node->getNext();
	}
}

