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

//  добавлено 30.05.2019 - перегруженная операция [] - индексирование по имени треугольника
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
    // временный массив
    Triangle *temp = new Triangle[length_ + 1];

    // копируем все элементы из исходного массива во временный
    // и добавляем новый элемент в конец временного массива
    for (int i = 0; i < length_; i++)
        temp[i] = triangles_[i];
    temp[length_] = triangle;

    // освободить память, занятую старым массивом, присвоить 
    // указателю данных класса Figures указателя на новый массив
    delete[] triangles_;
    triangles_ = temp;
    length_++;

    return *this;
} // Figures::operator&

// Удаление элемента из массива по индексу
Figures &Figures::operator|(int index)
{
    // защита от несуществующего индекса удаляемого элемента массива
    if (index < 0 || index > length_-1)
        throw exception("Недопустимый индекс элемента массива при удалении элемента");
    
    Triangle *temp = new Triangle[length_-1];

    for (int i = 0, k = 0; i < length_; i++) {
        // не копировать во вспомогательный массив удаляемый элемент
        if (index == i) continue;

        // копируем остальные элементы во вспомогательный массив
        temp[k++] = triangles_[i];
    } // for i

    delete[] triangles_;
    triangles_ = temp;
    --length_;
    return *this;
} // Figures::operator|

// Удаление элемента из массива по имени треугольника
Figures &Figures::operator|(char *name)
{
    // найти треугольник с заданным именем в массиве, получим
    // индекс треугольника
    // если нет такого треугольника - выбрасывать исключение
    int index = -1;
    for (int i = 0; i < length_; i++) {
        if (strcmp(triangles_[i].getName(), name) == 0) {
            index = i;
            break;
        } // if
    } // for i

    // реакция на отсутствие треугольника с заданным именем - выброс
    // исключения
    if (index == -1) {
        ostringstream oss;
        oss << "Не нейден треугольник с именем \"" << name << "\""; 
        throw exception(oss.str().c_str());
    } // if

    // Треугольник найден - применим операцию удаления по индексу
    *this | index;

    return *this;
} // Figures::operator|


Figures &Figures::operator()(int index, const Triangle &triangle)
{
    // временный массив
    Triangle *temp = new Triangle[length_ + 1];

    // копируем все элементы из исходного массива во временный
    // и добавляем новый элемент в заданную позицию временного 
    // массива
    for (int i = 0, k = 0; i < length_; i++) {
        // вставка элемента в заданную позицию
        if (i == index) temp[k++] = triangle;

        // копирование остальных элементов массива
        temp[k++] = triangles_[i];
    } // for i

    // освободить память, занятую старым массивом, присвоить 
    // указателю данных класса Figures указателя на новый массив
    delete[] triangles_;
    triangles_ = temp;
    length_++;

    return *this;
} // Figures::operator()

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
    // Triangle temp(triangles_[i]); 
    Triangle temp = triangles_[i];
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
    return newFigures;    
} // Figures::operator~


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

// компаратор для сортировки по заданию
// -1
//  0
//  1
int Figures::compareByArea(const Triangle &tr1, const Triangle &tr2)
{
    int result = 0;

	// для ускорения доступа к 
	double area1 = tr1.area();
	double area2 = tr2.area();
	
    if (area1 > area2)
        result = 1;
    else if (area1 < area2)
        result = -1;

    return  result;
} // Figures::compareByArea


// операция вывода объекта класса Figures, каждый треугольник
// выводим в отдельной строке
ostream &operator<<(ostream &os, const Figures &figures)
{
    for (int i = 0; i < figures.length_; i++)
        os << figures[i] << endl;

    return os;
} // operator<<
