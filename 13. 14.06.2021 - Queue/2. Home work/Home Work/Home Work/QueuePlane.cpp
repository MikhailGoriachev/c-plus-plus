#include "QueuePlane.h"

#pragma region Конструкторы и деструктор 

// инициализирующий конструктор 
QueuePlane::QueuePlane(int size) : front_(), back_(), counter_()
{
	// установка длины массива 
	setSize(size);

	// выделение памяти под массив 
	data_ = new Plane[size_];
}

// копирующий конструктор
QueuePlane::QueuePlane(const QueuePlane& queuePlane)
{
	// присвоение значений полей
	front_ = queuePlane.front_;
	back_ = queuePlane.back_;
	size_ = queuePlane.size_;
	counter_ = queuePlane.counter_;

	// выделение памяти 
	data_ = new Plane[size_];

	// копирование элементов
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = queuePlane.data_[i];
	}
}

#pragma endregion

#pragma region Сеттеры и геттеры

// сеттер size_
void QueuePlane::setSize(int size)
{
	// если длина меньше или равна нулю
	if (size <= 0)
		throw exception("QueuePlane: Размер очереди должен быть больше нуля!");

	// присвоение значения
	size_ = size;
}

// геттер size_
int QueuePlane::getSize() const { return size_; }

// геттер counter_
int QueuePlane::getCounter() const { return counter_; }

#pragma endregion

#pragma region Методы

// перегрузка операции присваивания 
QueuePlane& QueuePlane::operator=(const QueuePlane& queuePlane)
{
	// новый объект QueuePlane
	QueuePlane* newQueue = new QueuePlane(queuePlane);

	// копирование значений
	front_ = queuePlane.front_;
	back_ = queuePlane.back_;
	size_ = queuePlane.size_;
	counter_ = queuePlane.counter_;

	// выделение памяти
	data_ = new Plane[size_];

	// копирование значений
	memcpy(data_, queuePlane.data_, size_);

	return *newQueue;
}

// добавление в очередь элемента 
void QueuePlane::enqueue(Plane plane) 
{
	// если очередь переполнена 
	if (isFull())
		throw exception("QueuePlane: Очередь переполнена!");

	// присвоение элемента
	data_[back_] = plane;

	// если индекс конца очереди вышел за границы массива
	back_ + 1 == size_ ? back_ = 0 : back_++;

	// увеличение counter_
	counter_++;
}

// добавление в очередь массива 
void QueuePlane::enqueueAll(Plane* planeArr, int size)
{
	for (size_t i = 0; i < size && !isFull(); i++)
	{
		enqueue(planeArr[i]);
	}
}

// просмотр начала очереди
Plane QueuePlane::front() const
{
	// если очередь опустошена
	if (isEmpty())
		throw exception("QueuePlane: Очередь пуста!");

	return data_[front_];
}

// просмотр конца очереди
/*Plane QueuePlane::back() const
{
	// если очередь пуста 
	if (isEmpty())
		throw exception("QueuePlane: Очередь пуста!");

	return data_[back_];
}
*/
// взятие элемента с начала очереди
Plane QueuePlane::dequeue()
{
	// если очередь пуста 
	if (isEmpty())
		throw exception("QueuePlane: Очередь пуста!");

	// индекс начального элемента
	int index = front_;

	// если индекс начала после смещения выйдет за груницы массива
	front_ + 1 == size_ ? front_ = 0 : front_++;

	// уменьшение counter_
	counter_--;

	return data_[index];
}

// отчистка очереди
void QueuePlane::clear() { front_ = back_ = 0; }

// опустошение очереди
bool QueuePlane::isEmpty() const { return counter_ == 0; }

// переполнение очереди
bool QueuePlane::isFull() const { return counter_ == size_; }

#pragma endregion

#pragma region Дружественные функции

// перегрузка вывода 
ostream& operator<<(ostream& os, QueuePlane& queuePlane)
{
	os << "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n"
		<< "|     Модель    |  Пассажир. | Пассажиров | Расх. горючего |     Стоимость     |  Дальность полёта |  Регистрис. номер |\n"
		<< "|               |    мест    |            |     кг/ч       |      самолёта     |      самолёта     |      самолёта     |\n"
		<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";

	// если в компании нет самолётов
	if (queuePlane.counter_ == 0)
	{
		os << "|                                                    НЕТ САМОЛЁТОВ                                                     |\n"
			// нижняя строка 
			<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";
	}

	// вывод самолётов
	for (int i = 0, k = queuePlane.front_; i < queuePlane.counter_; i++, k++)
	{
		// если k указывает за границы массива 
		if (k == queuePlane.size_) k = 0;

		os << queuePlane.data_[k];

		// нижняя строка 
		os << "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";
	}

	return os;
}

#pragma endregion

