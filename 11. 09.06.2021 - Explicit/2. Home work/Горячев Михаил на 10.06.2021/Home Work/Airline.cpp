#include "Airline.h"

#pragma region Конструкторы и деструктор

// констурктор инициализирующий
Airline::Airline(const char* nameCompany, int countPlane) : nameCompany_(new char[NAME_COMP_SIZE])
{
	// название компании
	setNameCompany(nameCompany);

	// количество самолётов
	setCountPlane(countPlane);

	// если количество самолётов больше нуля
	if (countPlane_ != 0)
	{
		// выделение памяти для массива самолётов
		planes_ = new Plane[countPlane_];
	}
}

// констурктор инициализирующий, принимающий массив самолётов
Airline::Airline(const char* nameCompany, Plane* planes, int countPlane) : nameCompany_(new char[NAME_COMP_SIZE])
{
	// название компании
	setNameCompany(nameCompany);

	// копирование указателя
	planes_ = planes;

	// количество самолётов
	setCountPlane(countPlane);
}

#pragma endregion

#pragma region Сеттеры и Геттеры

// сеттер nameCompany_
void Airline::setNameCompany(const char* nameCompany)
{
	// если длина строки равна 0
	if (strlen(nameCompany) == 0)
	{
		throw exception("Название компании не должно быть пустым!");
	}

	memcpy(nameCompany_, nameCompany, NAME_COMP_SIZE - 1);
}

// сеттер countPlane_
void Airline::setCountPlane(int countPlane)
{
	if (countPlane < 0)
	{
		throw exception("Количество самолетов должно равняться или быть больше нуля");
	}

	countPlane_ = countPlane;
}

// сеттер planes_
void Airline::setPlanes(Plane* planes)
{
	// если указатель параметра равен nullptr
	if (planes == nullptr)
	{
		throw exception("Указатель на массив самолётов является nullptr");
	}

	// если указатель planes_ НЕ равен nullptr, либо если количество самолётов НЕ равно нулю
	if (planes_ == nullptr || countPlane_ == 0)
	{
		delete[] planes_;
	}

	// копирование указателя
	planes_ = planes;
}

#pragma endregion

#pragma region Методы

// добавление самолёта (в конец массива)
Airline& Airline::operator&(Plane& newPlane)
{
	// копия текущего объекта Airline
	Airline* newAir = new Airline(*this);

	// новый массив самолётов с увеличинной длинной
	Plane* newPlanes = new Plane[countPlane_ + 1];

	// копирование массива самолётов
	for (size_t i = 0; i < countPlane_; i++)
	{
		newPlanes[i] = planes_[i];
	}

	// вставка нового масолёта в последний элемент массива
	newPlanes[newAir->countPlane_++] = newPlane;

	// удаление старого массива нового объекта Airplane
	delete[] newAir->planes_;

	// копирование указателя на новый массив самолётов в новый объект Airplane
	newAir->planes_ = newPlanes;

	return *newAir;
}

#pragma region Пергрузка операторов

// перегрузка операции [] для доступа к элементам массива самолетов
Plane& Airline::operator[](int index)
{
	if (index < 0 || index >= countPlane_)
		throw exception("Некорректный индекс");

	return planes_[index];
}

// перегрузка бинарной операции * для увеличения стоимости самолетов на заданный коэффициент (положительный)
Airline& Airline::operator*(double coefficient)
{
	// если коэффициент отрицательный 
	if (coefficient < 0)
		throw exception("Коэффициент должен быть положительным");

	Airline* temp = new Airline(*this);

	// цикл умножения стоимости каждого самолёта на коеффициент 
	for (size_t i = 0; i < countPlane_; i++)
	{
		temp->planes_[i].setPrice(int(planes_[i].getPrice() * coefficient));
	}

	return *temp;
}

// перегрузка оператора присваивания
Airline& Airline::operator=(const Airline& air)
{
	// название компании
	strcpy(nameCompany_, air.nameCompany_);

	// динамический массив самолетов – объектов класса Plane
	planes_ = new Plane[air.countPlane_];

	for (size_t i = 0; i < air.countPlane_; i++)
	{
		planes_[i] = air.planes_[i];
	}

	// количество самолетов в массиве
	countPlane_ = air.countPlane_;

	return *this;
}

// вывод данных авиакомпании в табличном формате – перегрузка операции вывода <<
ostream& operator<<(ostream& os, Airline air)
{
	os << "\t\t\t\t\t" << air.nameCompany_ << "\n"
		<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n"
		<< "|     Модель    |  Пассажир. | Пассажиров | Расх. горючего |     Стоимость     |  Дальность полёта |  Регистрис. номер |\n"
		<< "|               |    мест    |            |     кг/ч       |      самолёта     |      самолёта     |      самолёта     |\n"
		<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";

	// если в компании нет самолётов
	if (air.countPlane_ == 0)
	{
		os << "|                                                    НЕТ САМОЛЁТОВ                                                     |\n"
			// нижняя строка 
			<< "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";
	}

	// вывод самолётов
	for (int i = 0; i < air.countPlane_; i++)
	{

		os << air[i];

		// нижняя строка 
		os << "+———————————————+————————————+————————————+————————————————+———————————————————+———————————————————+———————————————————+\n";
	}

	return os;
}

// перегрузка унарной операции – для поиска первого самолета с минимальной дальностью полета
Plane& Airline::operator-()
{
	// если нет самолётов
	if (countPlane_ == 0)
	{
		throw exception("Нет самолётов!");
	}

	// текущая минимальная дальность полета
	int minDist = planes_[0].getDistance();

	// индекс 
	int minIndex = 0;

	// нахождение первого самолёта с минимальной стоимостью
	for (int i = 1; i < countPlane_; i++)
	{
		// стоимость текущего самолёта
		int dist = planes_[i].getDistance();

		// если текущая минимальная стоимость больше, чем стоимость текущего самолёта
		if (minDist > dist)
		{
			minDist = dist;
			minIndex = i;
		}
	}

	return planes_[minIndex];
}

// перегрузка унарной операции ! для поиска первого самолета с максимальной дальностью полета
Plane& Airline::operator+()
{
	// если нет самолётов
	if (countPlane_ == 0)
	{
		throw exception("Нет самолётов!");
	}

	// текущая максимальная дальность полета
	int maxDist = planes_[0].getDistance();

	// индекс 
	int maxIndex = 0;

	// нахождение первого самолёта с максимальной стоимостью
	for (int i = 1; i < countPlane_; i++)
	{
		// стоимость текущего самолёта
		int dist = planes_[i].getDistance();

		// если текущая максимальная стоимость меньше, чем стоимость текущего самолёта
		if (maxDist < dist)
		{
			maxDist = dist;
			maxIndex = i;
		}
	}

	return planes_[maxIndex];
}

// методом класса перегрузите унарную операцию* для сортировки 
// массива самолетов по дальности полёта самолёта
Airline& Airline::operator*()
{
	Airline* newAir = new Airline(*this);

	// быстрая сортировка массива 
	quickSort(newAir->getPlanes(), 0, newAir->getCountPlane() - 1);

	return *newAir;
}

// перегрузка бинарной операции *
// сортировка по текущему количеству пассажиров
Airline Airline::operator*(int comparer(const Plane& plane1, const Plane& plane2))
{
	Airline* newAir = new Airline(*this);

	// быстрая сортировка массива самолётов по компаратору
	quickSort(newAir->getPlanes(), 0, newAir->getCountPlane() - 1, comparer);

	return *newAir;
}

// перегрузка унарной операции ! для  удаления первого самолета из массива(элемента с индексом 0)
Airline& Airline::operator!()
{
	// если количество самолётов равно нулю
	if (countPlane_ <= 0) throw exception("Самолётов не существует!\n");

	// новый объект Airline 
	Airline* newAirline = new Airline(*this);

	// если удаляется последний объект класса Plane
	if (countPlane_ == 1) 	
	{
		// удаление старого массива в новом объекте Airline
		delete[] newAirline->planes_;

		// присвоение нового адреса 
		newAirline->planes_ = nullptr;

		// уменьшение количества самолётов в новом объекте 
		newAirline->countPlane_--;

		return *newAirline;
	}

	// новый массив объектов Plane
	Plane* newPlanes = new Plane[countPlane_ - 1];

	// копирование объектов 
	for (size_t i = 0, k = 0; i < countPlane_; i++)
	{
		if (i == 0) continue;

		newPlanes[k++] = planes_[i];
	}

	// удаление старого массива в новом объекте Airline
	delete[] newAirline->planes_;

	// присвоение нового адреса 
	newAirline->planes_ = newPlanes;

	// уменьшение количества самолётов в новом объекте 
	newAirline->countPlane_--;

	return *newAirline;
}

// перегрузка бинарной операции !! для удаления самолета из массива по числовому индексу
Airline& Airline::operator||(int index)
{
	if (index >= countPlane_ || index < 0) throw exception("Самолёта с таким номером не существует!\n");

	if (countPlane_ == 0) throw exception("Самолётов не существует!\n");

	// новый объект Airline 
	Airline* newAirline = new Airline(*this);

	// если удаляется последний объект класса Plane
	if (countPlane_ == 1)
	{
		// удаление старого массива в новом объекте Airline
		delete[] newAirline->planes_;

		// присвоение нового адреса 
		newAirline->planes_ = nullptr;

		// уменьшение количества самолётов в новом объекте 
		newAirline->countPlane_--;

		return *newAirline;
	}

	// новый массив объектов Plane
	Plane* newPlanes = new Plane[countPlane_ - 1];

	// копирование объектов 
	for (size_t i = 0, k = 0; i < countPlane_; i++)
	{
		if (i == index)
			continue;

		newPlanes[k++] = planes_[i];
	}

	// удаление старого массива в новом объекте Airline
	delete[] newAirline->planes_;

	// присвоение нового адреса 
	newAirline->planes_ = newPlanes;

	// уменьшение количества самолётов в новом объекте 
	newAirline->countPlane_--;

	return *newAirline;

}

// методом класса перегрузите бинарную операцию !!для удаления самолета из массива по регистрационному номеру
Airline& Airline::operator||(char* number)
{
	if (countPlane_ <= 0) throw exception("Самолётов не существует!\n");

	// поиск индекса элемента с нужным номером
	for (size_t i = 0; i < countPlane_; i++)
	{
		if (strcmp(number, planes_[i].getNumber()) == 0)
		{
			return *this || i;
		}
	}

	throw exception("Самолёта с таким номером не существует!\n");
}

// методом класса перегрузите операцию() для вставки по заданному индексу самолета(самолеты правее
// заданной позиции сдвигаются к концу массива)
Airline& Airline::operator()(int index, Plane& newPlane)
{
	//if (countPlane_ == 0 && index == 0) {}

	if ((index >= countPlane_ || index < 0) && index != 0) throw exception("Самолёта с таким номером не существует!\n");

	// новый объект Airline 
	Airline* newAirline = new Airline(*this);

	// новый массив объектов Plane
	Plane* newPlanes = new Plane[countPlane_ + 1];

	if (countPlane_ == 0) newPlanes[0] = newPlane;

	else
	{
		// копирование объектов 
		for (size_t i = 0, k = 0; i < countPlane_; i++)
		{
			if (i == index)
				newPlanes[k++] = newPlane;

			newPlanes[k++] = planes_[i];
		}

		// удаление старого массива в новом объекте Airline
		delete[] newAirline->planes_;
	}
	// присвоение нового адреса 
	newAirline->planes_ = newPlanes;

	// уменьшение количества самолётов в новом объекте 
	newAirline->countPlane_++;

	return *newAirline;
}

#pragma endregion

#pragma endregion
// быстрая сортировка массива самолётов по компаратору
void Airline::quickSort(Plane* planes, int start, int end, int compare(const Plane& pl1, const Plane& pl2)) {
	// условие завершения рекурсии
	if (start >= end) return;

	// начальные значения переменных на очередном вызове
	int i = start, j = end;                      // для работы алгоритма
	int baseElement = start + (end - start) / 2; // расчет начального индекса середины массива

	while (i < j) {

		Plane value = planes[baseElement];

		while (i < baseElement && (compare(planes[i], value) <= 0)) i++;

		while (j > baseElement && (compare(planes[j], value) >= 0)) j--;


		if (i < j) {
			// меняем местами элементы в половинках массива
			swap(planes[i], planes[j]);

			// по массиву
			if (i == baseElement) baseElement = j;

			else if (j == baseElement)  baseElement = i;
		} // if
	} // while

	// рекурсивный вызов в новых границах поиска
	quickSort(planes, start, baseElement, compare);          // от начала массива до cur
	quickSort(planes, baseElement + 1, end, compare);      // от cur+1 до конца массива
} // quickSort

// быстрая сортировка массива самолётов по дальности полёта самолёта
void Airline::quickSort(Plane* planes, int start, int end) {
	// условие завершения рекурсии
	if (start >= end) return;

	// начальные значения переменных на очередном вызове
	int i = start, j = end;                      // для работы алгоритма
	int baseElement = start + (end - start) / 2; // расчет начального индекса середины массива

	while (i < j) {

		Plane value = planes[baseElement];

		while (i < baseElement && (planes[i].getDistance() <= value.getDistance())) i++;

		while (j > baseElement && (planes[j].getDistance() >= value.getDistance())) j--;


		if (i < j) {
			// меняем местами элементы в половинках массива
			swap(planes[i], planes[j]);

			// по массиву
			if (i == baseElement) baseElement = j;

			else if (j == baseElement)  baseElement = i;
		} // if
	} // while

	// рекурсивный вызов в новых границах поиска
	quickSort(planes, start, baseElement);          // от начала массива до cur
	quickSort(planes, baseElement + 1, end);      // от cur+1 до конца массива
} // quickSort
