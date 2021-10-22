#include "pch.h"
#include "Figures.h"

// перегрузка операции присваивания
Figures &Figures::operator=(const Figures &figures)
{
    // delete[] triangles_;
    // triangles_ = new Triangle[figures.length_];
    // 
    // length_ = figures.length_;
    // for(int i = 0; i < figures.length_; ++i)
    //     triangles_[i] = figures.triangles_[i];
    setData(figures.triangles_, figures.length_);
    return *this;
} // Figures::operator=

// операция индексирования
Triangle &Figures::operator[](int index) const
{
    if (index < 0 || index >= length_)
        throw exception("Индекс выходит за пределы массива");

    return triangles_[index];
} // Figures::operator[]

// Перегруженная операция [] - индексирование по имени треугольника
// возвращает первый треугольник с заданным именем - игнорим проблему дубликатных имен
Triangle &Figures::operator[](char *name) const
{
    int index = -1;

    // поиск треугольника по имени
    for (int i = 0; i < length_; i++) {
        if (strcmp(triangles_[i].getName(), name) == 0) {
            index = i;
            break;
        } // if
    } // for i

    // реакция на не найденный элемент
    if (index < 0) {
        char buf[1024];
        sprintf(buf, "Не найден треугольлник с именем %s", name);
        throw exception(buf);
    } // if

    return triangles_[index];
} // Figures::operator[]


// Вставка элемента triangle в конец массива треугольников triangles_
Figures &Figures::operator&(const Triangle &triangle)
{
	/*
	// оптимизированный для класса Figures алгоритм, но не показывает
	// создание объекта копирующим конструктором
    // временный массив
    Triangle *temp = new Triangle[length_ + 1];

    // копируем все элементы из исходного массива во временный
    // и добавляем новый элемент в конец временного массива
    for (int i = 0; i < length_; i++)
        temp[i] = triangles_[i];
    temp[length_] = triangle;

    Figures* newFigures = new Figures(temp, length_ + 1);
    return *newFigures;
    */

    // создание копии объекта, с которой и будем работать
	Figures* result = new Figures(*this);

	// временный массив, с местом для добавляемого элемента
    Triangle* temp = new Triangle[length_ + 1];

    // копируем все элементы из исходного массива во временный
    // и добавляем новый элемент в конец временного массива
    for (int i = 0; i < length_; i++)
        temp[i] = triangles_[i];
    temp[length_] = triangle;

	// устанавливаем новый массив в качестве данных для объекта-результата
    // и освобождаем память, выделенную под временный массив
	result->setData(temp, length_ + 1);
    delete[] temp;

	// вернуть ссылку на объект-результат
    return *result;
} // Figures::operator&


// реверсирование массива треугольников
Figures Figures::operator!() const
{
    Figures newFigures(*this);

    // расчет количества обменов, меняем местами
    // 0 и length-1, затем 1 и length-2,... всего
    // выполняем n циклов обмена
    int n = length_ / 2;
    for (int i = 0, j = length_-1; i < n; ++i, --j) {
        newFigures.swap(i, j);
    } // for i

    return newFigures;
} // Figures::operator!

// обмен местами i-го и j-го элементов массива объектов
void Figures::swap(int i, int j) const
{
    Triangle temp(triangles_[i]); 
    // Triangle temp = triangles_[i];
    triangles_[i] = triangles_[j];
    triangles_[j] = temp;
} // Figures::swap

// сортировка массива треугольников по возрастанию площадей
// по семантике операции массив-операнд не меняется  
Figures Figures::operator~() const
{
	// создать новый массив - он менятся
    Figures newFigures(*this);
	
    newFigures.quickSort(0, newFigures.length_-1);  
    // newFigures.quickSort(0, newFigures.length_-1, compareByArea);  
    return newFigures;    
} // Figures::operator~

// сортировка массива треугольников по компаратору
Figures Figures::operator%(int compare(const Triangle& tr1, const Triangle& tr2))
{
    // создать новый массив - он менятся
    Figures newFigures(*this);

    newFigures.quickSort(0, newFigures.length_ - 1, compare);
    return newFigures;
} // Figures::operator%


// start - индекс начала части массива
// end   - индекс конца части массива
void Figures::quickSort(int start, int end) {
   	// условие завершения рекурсии
    if (start >= end) return;

	// начальные значения переменных на очередном вызове
    int i = start, j = end;                      // для работы алгоритма
    int baseElement = start + (end - start) / 2; // расчет начального индекса середины массива

	// проходим по обрабатываемой части массива, элементы
	// меньшие базового помещаем в первую половину массива 
	// (до базового элемента), элементы бОльшие базового 
	// помещаем во вторую половину массива (после базового)
    while (i < j) {
		// середина - значение элемента в середине интервала
		// (базовый элемент)
        Triangle value = triangles_[baseElement];  
       
    	// движение от начала к середине, пока не найдем элемент => середины 
    	// (бОльший базового)
        // while (i < baseElement && (array[i] <= value)) i++;
        while (i < baseElement && (compareByArea(triangles_[i], value) <= 0)) i++;
        
    	// движение от конца к середине, пока не найдем элемент <= середины
		// меньше базового
        // while (j > baseElement && (array[j] >= value)) j--;
        while (j > baseElement && (compareByArea(triangles_[j], value) >= 0)) j--;

		// если это возможно, меням местами найденные элементы
		// бОльший --- базовый --- меньший ###>  меньший --- базовый --- бОльший
        if (i < j) { 
			// меняем местами элементы в половинках массива
            this->swap(i, j);

            // стандартный алгоритм STL тоже работает, но требует соблюдения
        	// "правила трех" для обмениваемых объектов, может требовать
        	// реализации перемещающего присваивания и перемещающего конструктора
        	// (т.е. соблюдения "правила пяти")
        	// std::swap(triangles_[i], triangles_[j]);

            // если слева дошли до середины - нет элементов для обмена
            // отодвигаем середину вправо, чтобы продолжать движение
			// по массиву
            if (i == baseElement) baseElement = j;

            // если справа дошли до середины - нет элементов для обмена
            // отодвигаем середину влево для продолжения движения
            else if (j == baseElement)  baseElement = i;
        } // if
    } // while

    // рекурсивный вызов в новых границах поиска
    quickSort(start, baseElement);          // от начала массива до cur
    quickSort(baseElement + 1, end);      // от cur+1 до конца массива
} // quickSort


// start - индекс начала части массива
// end   - индекс конца части массива
void Figures::quickSort(int start, int end, int compare(const Triangle& tr1, const Triangle& tr2)) {
    // условие завершения рекурсии
    if (start >= end) return;

    // начальные значения переменных на очередном вызове
    int i = start, j = end;                      // для работы алгоритма
    int baseElement = start + (end - start) / 2; // расчет начального индекса середины массива

    // проходим по обрабатываемой части массива, элементы
    // меньшие базового помещаем в первую половину массива 
    // (до базового элемента), элементы бОльшие базового 
    // помещаем во вторую половину массива (после базового)
    while (i < j) {
        // середина - значение элемента в середине интервала
        // (базовый элемент)
        Triangle value = triangles_[baseElement];

        // движение от начала к середине, пока не найдем элемент => середины 
        // (бОльший базового)
        // while (i < baseElement && (array[i] <= value)) i++;
        while (i < baseElement && (compare(triangles_[i], value) <= 0)) i++;

        // движение от конца к середине, пока не найдем элемент <= середины
        // меньше базового
        // while (j > baseElement && (array[j] >= value)) j--;
        while (j > baseElement && (compare(triangles_[j], value) >= 0)) j--;

        // если это возможно, меням местами найденные элементы
        // бОльший --- базовый --- меньший ###>  меньший --- базовый --- бОльший
        if (i < j) {
            // меняем местами элементы в половинках массива
            this->swap(i, j);

            // стандартный алгоритм STL тоже работает, но требует соблюдения
            // "правила трех" для обмениваемых объектов, может требовать
            // реализации перемещающего присваивания и перемещающего конструктора
            // (т.е. соблюдения "правила пяти")
            // std::swap(triangles_[i], triangles_[j]);

            // если слева дошли до середины - нет элементов для обмена
            // отодвигаем середину вправо, чтобы продолжать движение
            // по массиву
            if (i == baseElement) baseElement = j;

            // если справа дошли до середины - нет элементов для обмена
            // отодвигаем середину влево для продолжения движения
            else if (j == baseElement)  baseElement = i;
        } // if
    } // while

    // рекурсивный вызов в новых границах поиска
    quickSort(start, baseElement, compare);          // от начала массива до cur
    quickSort(baseElement + 1, end, compare);      // от cur+1 до конца массива
} // quickSort


// компаратор для сортировки по заданию
// -1   tr1.area() <  tr2.area()
//  0   tr1.area() == tr2.area()
//  1   tr1.area() >  tr2.area()
int Figures::compareByArea(const Triangle &tr1, const Triangle &tr2)
{
    // int result = 0;

	// для ускорения доступа к 
	double area1 = tr1.area();
	double area2 = tr2.area();
	
    //     условие?вырTrue: вырFalse
    return area1 > area2 ? 1 : (area1 < area2 ? -1 : 0);
	
    // if (area1 > area2)
    //     result = 1;
    // else if (area1 < area2)
    //     result = -1;
    // 
    // return  result;
} // Figures::compareByArea


// операция вывода объекта класса Figures, каждый треугольник
// выводим в отдельной строке
ostream &operator<<(ostream &os, const Figures &figures)
{
    for (int i = 0; i < figures.length_; i++)
        os << figures[i] << endl;

    return os;
} // operator<<
