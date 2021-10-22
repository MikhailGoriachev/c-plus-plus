#include "QueueDbl.h"

// поля класса
/*
	// индекс начала
	int front_;

	// индекс конца
	int back_;

	// указатель на массив double
	double* data_;

	// счётчик элементов в очереди
	int counter_;

	// длина очереди
	int size_;

*/

#pragma region Конструкторы и деструктор

// конструктор инициализирующий
QueueDbl::QueueDbl(int size): front_(), back_(), counter_()
{
	// присвоение size 
	setSize(size);

	// выделение памяти под массив double
	data_ = new double[size_];
}

// копирующий конструктор 
QueueDbl::QueueDbl(const QueueDbl& queueDbl): front_(queueDbl.front_), back_(queueDbl.back_), 
											  counter_(queueDbl.counter_), size_(queueDbl.size_),
											  data_(new double[size_])
{
	// копирование массива data_
	memcpy(data_, queueDbl.data_, size_);
}

// дестркутор 
QueueDbl::~QueueDbl()
{
	// отчистка памяти от массива data_
	delete[] data_;
}

#pragma endregion

#pragma region Геттеры и сеттеры

// сеттер size_
void QueueDbl::setSize(int size)
{
	// если длина меньше или ровняется нулю
	if (size <= 0)
		throw exception("QueueDbl: Введённая длина должна быть больше нуля!");

	// присваивание значения
	size_ = size;
}

#pragma endregion

#pragma region Методы 

// перегрузка операции присвоения 
QueueDbl& QueueDbl::operator=(const QueueDbl& queueDbl)
{
	// копия объекта newQueue
	QueueDbl* newQueue = new QueueDbl(queueDbl);

	// копирование полей
	front_ = queueDbl.front_;
	back_ = queueDbl.back_;
	size_ = queueDbl.size_;
	counter_ = queueDbl.counter_;

	// отчистка памяти от массива data_
	delete[] data_;

	// выделение памяти под массивв data_
	data_ = new double[size_];

	// копирование элементов в массив data_
	memcpy(data_, queueDbl.data_, size_);

	return *newQueue;
}

// добавление элемента в очередь
void QueueDbl::enqueue(double value)
{
	// если очередь переполнена 
	if (isFull())
		throw exception("Queue: очередь переполнена!");

	// запись
	data_[back_] = value;

	// проверка позиции, если back_ выходит за рамки массива
	back_ + 1 == size_ ? back_ = 0 : back_++;

	// увеличение counter_
	counter_++;
}

// добавление массива в очередь
void QueueDbl::enqueueAll(double* arr, int size)
{
	// копирования массива в очередь
	for (size_t i = 0; i < size; i++)
	{
		// добавление текущего элемента массива в очередь
		enqueue(arr[i]);
	}
}

// просмотр элемента вершины очереди
double QueueDbl::front() const
{ 
	// если очередь опустошена
	if (isEmpty())
		throw exception("Queue: очередь пуста");

	return data_[front_]; 
}

// просмотр элемента конца очереди
/*double QueueDbl::back() const
{
	// если очередь опустошена
	if (isEmpty())
		throw exception("Queue: очередь пуста");

	// есди back_ равен нулю
	return back_ == 0 ? data_[size_ - 1] : data_[back_ - 1];
}*/

// взятие элемента из очереди
double QueueDbl::dequeue()
{
	// копия значение элемента
	double n = data_[front_++];

	// если индекс вершины больше или равен длине массива 
	if (front_ >= size_)
		front_ = 0;

	counter_--;

	return n;
}

// отчистка очереди
void QueueDbl::clear()
{
	// обнуление индексов
	back_ = front_ = 0;
}

// опустошение очереди
bool QueueDbl::isEmpty() const { return counter_ == 0; };

// переполнение очереди
bool QueueDbl::isFull() const { return counter_ == size_; };

#pragma endregion

#pragma region Дружественные функции

// перегрузка операции вывода 
ostream& operator<<(ostream& os, const QueueDbl& queueDbl)
{
	os << fixed;
	os.precision(2);

	// ВЫВОД ГОРИЗОНТАЛЬНОЙ ТАБЛИЦЕЙ
	showSize(os, queueDbl);

	showCounter(os, queueDbl);

	// если очередь пуста 
	if (queueDbl.counter_ == 0)
	{
		os  << "\t+——————————————————————————+\n"
			<< "\t|                          |\n"
			<< "\t|       ОЧЕРЕДЬ ПУСТА      |\n"
			<< "\t|                          |\n"
			<< "\t+——————————————————————————+\n";
	}

	else
	{
		showLine(os, queueDbl);

		showIndex(os, queueDbl);

		showLine(os, queueDbl);

		showElem(os, queueDbl);

		showLine(os, queueDbl);

	}

	return os;
		//<< "| Индекс элемента |";

	// ВЫВОД ВЕРТИКАЛЬНОЙ ТАБЛИЦЕЙ
	/*// шапка таблицы
	os  << "\t+—————————————————+—————————————————+\n"
		<< "\t| Индекс элемента |    Содержание   |\n"
		<< "\t+—————————————————+—————————————————+\n";
		
	// количество элементов в очереди
	int counter = queueDbl.counter_;

	// если количество элементов больше нуля
	if (counter > 0)
	{
		// вывод таблицей
		for (size_t i = 0, k = queueDbl.front_; i < queueDbl.counter_; i++, k++)
		{
			if (k == queueDbl.size_) k = 0;
			os << "\t|  " << setw(14) << i << " | " << setw(15) << queueDbl.data_[k] << " |\n"
				<< "\t+—————————————————+—————————————————+\n";
		}

		os  << "\t|" << " Всего элементов: " << setw(16) << queueDbl.counter_ << " |\n"
			<< "\t+———————————————————————————————————+\n"
			<< "\t|" << " Максимум элементов: " << setw(13) << queueDbl.size_<< " |\n"
			<< "\t+———————————————————————————————————+\n";

	}
	else
	{
		os	<< "\t|           ОЧЕРЕДЬ ПУСТА           |\n"
			<< "\t+—————————————————+—————————————————+\n";
	}
	return os;*/
}

// вывод горизонтальной линии
ostream& showLine(ostream& os, const QueueDbl& queueDbl)
{
	int counter = queueDbl.getCounter();

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
ostream& showIndex(ostream& os, const QueueDbl& queueDbl)
{
	int counter = queueDbl.counter_;

	int size = queueDbl.size_;

	os << "\t|      Индекс     |";

	for (size_t i = 0, k = queueDbl.front_; i < counter; i++, k++)
	{
		if (k == size) k = 0;
		os << "   " << setw(5) << i << "|";
	}
	
	os << "\n";

	return os;
}

// вывод элементов
ostream& showElem(ostream& os, const QueueDbl& queueDbl)
{
	int counter = queueDbl.getCounter();

	int size = queueDbl.getSize();

	os << "\t|    Содержание   |";

	for (size_t i = 0, k = queueDbl.front_; i < counter; i++, k++)
	{
		if (k == size) k = 0;
		os << " " << setw(7) << queueDbl.data_[k] << "|";
	}

	os << "\n";

	return os;
}

// вывод максимального размера
ostream& showSize(ostream& os, const QueueDbl& queueDbl)
{
	os << "\t+——————————————————————————+\n"
		<< "\t|   Максимум элементов: " << setw(2) << queueDbl.size_ << " |\n";
	return os;
}

// вывод количества элементов
ostream& showCounter(ostream& os, const QueueDbl& queueDbl)
{
	os  << "\t+——————————————————————————+\n"
		<< "\t| Количество элементов: " << setw(2) << queueDbl.counter_ << " |\n";
		
	return os;
}

#pragma endregion