#include "DequeChar.h"

#pragma region Конструкторы и деструктор 

// конструктор инициализирующий
DequeChar::DequeChar(int size)
{
	// если передаваемый size меньше или равен нулю
	if (size <= 0)
		throw exception("DequeChar: Длина очереди должна быть больше нуля!");

	// установка back_ в начало
	back_ = 0;

	// присвоение size
	size_ = size;

	// выделение памяти для массива-контейнера и заполнение его нулями
	data_ = new char[size_] { 0 };
}

// конструтор на основе массива 
DequeChar::DequeChar(char* arr, int size)
{
	// если передаваемый size меньше или равен нулю
	if (size <= 0)
		throw exception("DequeChar: Длина передаваемого массива должна быть больше нуля!");

	// если указатель на массив arr имеет значение nullptr
	if (arr == nullptr)
		throw exception("DequeChar: Передаваемого массива не существует!");

	// установка back_ в начало
	back_ = 0;

	// присвоение size
	size_ = size;

	// выделение памяти под массив-контейнер 
	data_ = new char[size_];

	// копирование массива 
	for (int i = 0; i < size_; i++)
	{
		data_[i] = arr[i];
	}
}

// копирующий конструктор
DequeChar::DequeChar(const DequeChar& dequeChar)
{
	// копирование back_
	back_ = dequeChar.back_;

	// копирование size_
	size_ = dequeChar.size_;

	// выделение памяти под массив-контейнер
	data_ = new char[size_];

	// копирование элементов 
	for (int i = 0; i < size_; i++)
	{
		data_[i] = dequeChar.data_[i];
	}
}

// деструктор
DequeChar::~DequeChar()
{
	// отчистка памяти от массива-контейнера
	delete[] data_;
}

#pragma endregion

#pragma region Методы

#pragma region Операции с началом дека

// добавить в начало дека
void DequeChar::shift(char value)
{
	// если дек переполнен
	if (isFull())
		throw exception("DequeChar: Дек переполнен!");

	// сдвиг дека вправо
	for (int i = back_; i > 0; i--)
	{
		data_[i] = data_[i - 1];
	}

	// установка элемента в начало дека
	data_[0] = value;

	// увеличение back_
	back_++;
}

// добавление массива в начало дека
void DequeChar::shiftAll(char* arr, int size)
{
	// если передаваемый size меньше или равен нулю
	if (size <= 0)
		throw exception("DequeChar: Длина передаваемого массива должна быть больше нуля!");

	// если указатель на массив arr имеет значение nullptr
	if (arr == nullptr)
		throw exception("DequeChar: Передаваемого массива не существует!");

	// добавление элементов в начало дека 
	for (int i = 0; i < size && !isFull(); i++)
	{
		// добавление элемента в начало дека
		shift(arr[i]);
	}
}

// посмотреть начальный элемент дека
char DequeChar::front() const
{
	// если дек пуст
	if (isEmpty())
		throw exception("DequeChar: Дек пуст!");

	// возвращение начального элемента дека
	return data_[0];
}

// взять элемент с начала дека
char DequeChar::unshift()
{
	// если дек пуст
	if (isEmpty())
		throw exception("DequeChar: Дек пуст!");

	// сохранение значения элемента
	char tmp = data_[0];

	// уменьшение back_
	back_--;

	// перемещение элементов влево
	for (int i = 0; i < back_ - 1; i++)
	{
		data_[i] = data_[i + 1];
	}

	// возвращение сохранённого элемента
	return tmp;
}

#pragma endregion

// ------------------------------------------------------------------------------

#pragma region Операции с концом дека

// добавить в конец дека
void DequeChar::push(char value)
{
	// если дек переполнен
	if (isFull())
		throw exception("DequeChar: Дек переполнен!");

	// добавление элемента и увеличение back_
	data_[back_++] = value;
}

// добавление массива в конец дека 
void DequeChar::pushAll(char* arr, int size)
{
	// если длина массива меньше или равна нулю
	if (size <= 0)
		throw exception("DequeChar: Длина передаваемого массива должна быть больше нуля!");

	// если указатель на массив arr имеет значение nullptr
	if (arr == nullptr)
		throw exception("DequeChar: Передаваемого массива не существует!");

	// добавление элементов в конец дека
	for (int i = 0; i < size && !isFull(); i++)
	{
		push(arr[i]);
	}
}

// посмотреть последний элемент дека 
char DequeChar::back() const
{
	// если дек опустошён
	if (isEmpty())
		throw exception("DequeChar: Дек пуст!");

	// возвращение последнего элемента
	return data_[back_ - 1];
}

// взять элемент с конца дека 
char DequeChar::pop()
{
	// если дек пуст
	if (isEmpty())
		throw exception("DequeChar: Дек пуст!");

	// уменьшение back_ и возвращение последнего элемента
	return data_[--back_];
}

#pragma endregion

// отчистка дека
void DequeChar::clear()
{
	back_ = 0;
}

// опустошение дека 
bool DequeChar::isEmpty() const
{
	return back_ == 0;
}

// переполнение дека 
bool DequeChar::isFull() const
{
	return back_ == size_;
}

// длина дека 
int DequeChar::counter() const 
{
	return back_;
}

// размер дека
int DequeChar::size() const 
{ 
	return size_; 
}

// перегрузка операции присваивания
DequeChar& DequeChar::operator=(const DequeChar& dequeChar)
{
	// защита от самоприсваивания
	if (this == &dequeChar) return *this;

	// присвоение size_
	size_ = dequeChar.size_;

	// присвоение back_
	back_ = dequeChar.back_;

	// отчистка памяти от массива-контейнера 
	delete[] data_;

	// выделение памяти под массив-контейнер
	data_ = new char[size_];

	// копирование массива-контейнера 
	for (int i = 0; i < size_; i++)
	{
		data_[i] = dequeChar.data_[i];
	}

	// возвращение ссылки на наш объект
	return *this;
}

#pragma endregion

#pragma region Дружественные функции 

// вывод линии, n - количество элементов
ostream& showLine(ostream& os, int n)
{
	os << "\t+————————————————————+";

	// вывод линии для дальнейших элементов
	for (size_t i = 0; i < n; i++)
	{
		os << "————+";
	}

	os << "\n";

	return os;
}

// перегрузка операции вывода
ostream& operator<<(ostream& os, const DequeChar& dequeChar)
{
	// вывод шапки
	os << "\t+————————————————————+———————————————————+\n"
		<< "\t|   Макс. размер: " << setw(2) << dequeChar.size_ << " |   Тек. размер: " << setw(2) << dequeChar.back_ << " |\n";

	// вывод линии
	showLine(os, dequeChar.back_ < 4 ? 4 : dequeChar.back_);

	// если дек пуст
	if (dequeChar.back_ == 0)
		os << "\t|                                        |\n"
			<< "\t|                 ДЕК ПУСТ               |\n"
			<< "\t|                                        |\n"
			<< "\t+————————————————————+———————————————————+\n";

	// если стек заполнен
	else
	{
		// вывод индекса элемента
		os << "\t|  Индекс элемента:  |";
		for (int i = 0; i < dequeChar.back_; i++)
		{
			os << " " << setw(2) << i << " |";
		}

		os << "\n";

		// вывод линии
		showLine(os, dequeChar.back_);

		// вывод элементов
		os << "\t|      Значение:     |";
		for (int i = 0; i < dequeChar.back_; i++)
		{
			// элмент
			char tmp = dequeChar.data_[i];

			short clOld = getColor();

			// текущий цвет
			short cl = tmp >= 'a' && tmp <= 'z' ? BLUE_ON_BLACK : RED_ON_BLACK;

			// если буква латниская или русская;

			os << color(cl) << "  " << dequeChar.data_[i] << " " << color(clOld) << "|";
		}

		os << "\n";

		// вывод линии
		showLine(os, dequeChar.back_);

	}


	return os;
}

#pragma endregion
