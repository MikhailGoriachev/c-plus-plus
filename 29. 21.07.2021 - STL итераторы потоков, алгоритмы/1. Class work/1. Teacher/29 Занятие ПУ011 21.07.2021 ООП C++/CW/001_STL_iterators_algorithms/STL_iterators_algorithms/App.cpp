#include "pch.h"
#include "Utils.h"
#include "App.h"
#include "Person.h"

#include <vector>      // векторы - пример контейнеров для обработки

#include <iterator>    // итераторы
#include <functional>  // стандартные функторы 
#include <algorithm>   // стандартные алгоритмы
#include <numeric>     // некоторые алгоритмы, предназначенные для обработки числовых данных

// потоковые итераторы
void App::iteratorsDemo()
{
    // потоковые строки
    istringstream istr("23 4 5 42 -12 34 33 8");
    istream_iterator<int> it(istr);

	// вектор для вводимых чисел
    vector<int> v1;
    
	// чтение из потока ввода по итератору
	while(it != istream_iterator<int>()) {  // istream_iterator<int>() пустой итератор
        v1.push_back(*it);  // собственно чтение из потока
        ++it;               // продвижение итератора
	} // while

	// вывод вектора
    cout << "   ";
    for (auto v : v1)
        cout << setw(8) << v;
    cout << "\n";
    
	// чтение из файла при помощи итератора потока ввода
    ifstream in("file.txt");
    istream_iterator<int> stream_it(in);

    cout << "\n    чтение из файла:";
	// while(!in.eof()) {
	while(stream_it != istream_iterator<int>()) {
        int value = *stream_it;   // фактическое чтение
        cout << setw(8) << value;
        ++stream_it;
	}
    in.close();
    cout << "\n\n";

	// потоковый итератор вывода
    // ------------------------------------------
    //                                поток вывода, необязательная строка, добавляемая после 
    //                                каждого вывода
    ostream_iterator<int> os_stream(cout, " кг/м2 ");
	*os_stream = 40'000;  // вывод
    ++os_stream;          // продвижение по выводу, не обязательное... но рекомендую использовать
    *os_stream = 42;
    ++os_stream;

    // применение потокового итератора в цикле
    cout << "\n    Потоковый итератор в цикле:\n";
    for (int i = 0; i < 10; ++i, ++os_stream) 
        *os_stream = i;
    cout << endlm(3);
    
	// потоковый итератор вывода для файлов
    ofstream ofs("output.txt");
    ostream_iterator<int> ofs_stream(ofs, "\n");
    for (auto v : v1) {
        *ofs_stream = v;  // вывод в поток вывода
        ++ofs_stream;     // продвижение по выводу
    } // for v
    ofs.close();
    cout << "\n   Файл записан\n";

} // App::iteratorsDemo

// функциональные объекты - классы у которых определена операция ()
// функторы
// могут заменить указатели на функции при передаче параметров 

// шаблонные классы функторов в STL
// binary_function<типАрг1, типАрг2, типРезультата> - шаблон функции с 2мя аргументами
// binary_function<int, int, short>        short  foo(int, int);
// binary_function<int, int, int>          int    foo(int, int)
// binary_function<bool, int, double>      double foo(bool, int);
// 
// unary_function<типАрг,  типРезультата> - шаблон функции с 1м аргументом               
// unary_function<Person, bool>             bool foo(Person)
// unary_function<int, int>                 int  foo(int)

// пример функтора-компаратора
class person_less_salary: public binary_function<Person &, Person &, bool>
{
public:
	bool operator()(Person &p1, Person &p2)
	{
        return p1.salary < p2.salary;
	}
};

// Функциональные объекты - демонстрация
void App::functionalObjectsDemo()
{
	// два подопытых объекта
    Person p1("Алиса", 23, 125'000.);
    Person p2("Боб",   21, 17'000.);

	// создание экземпляра компаратора на базе функтора
    person_less_salary compare_by_salary;
    bool r = compare_by_salary(p1, p2);
    cout << boolalpha << setprecision(2) << "    Оклад (" << p1.salary<<") " << p1.name << " меньше оклада ("
	     << p2.salary << ") " << p2.name << ": " << r << "\n";

	cout << boolalpha << setprecision(2) << "    Оклад (" << p1.salary<<") " << p1.name << " меньше оклада ("
	     << p2.salary << ") " << p2.name << ": " << compare_by_salary(p1, p2) << "\n";

	// при отсутствии операции + в классе Person - ошибка компиляции
    // !!! требуется переопределенная операция + в классе Person !!!
    plus<Person> add;
    Person p3 = add(p1, p2);
    cout << "   plus: " << p3.name << ": " << p3.salary << "\n";

	// при отсутствии операции - в классе Person - ошибка компиляции
    // !!! требуется переопределенная операция - в классе Person !!!
    // minus<Person> sub;
    // p3 = sub(p1, p2);
    // cout << "   minus: " << p3.name << ": " << p3.salary << "\n";

	// стандартный функтор для проверки на равенство equal_to - наследник binary_function
	// !!! требуется переопределенная операция == в классе Person !!!
    equal_to<Person> predicate;
    cout << "\n    p1 == p2: " << predicate(p1, p2) << "\n\n";
} // App::functionalObjectsDemo

#pragma region Вспомогательная секция
// размер массива, векторов
static const int N = 10;

// формирование случайного числа для алгоритма generate()
int get_rand() {return getRand(-10, 10); }

// функция для поэлементной обработки массива/вектора 
int square(int x) { return x * x;  }

// функциональный объект для возведения в квадрат целого числа
class Square: public unary_function<int, int>
{
public:
    int operator()(int x) const { return x * x; }
};

// функциональный объект для работы алгоритма sort() - сортировка
// по правилу - отрицательные впереди
class NegativeFirst : binary_function<int, int, bool>
{
public:
    bool operator()(int x, int y) { return x < 0 && y >= 0; }
};

// функция для поэлементной обработки массива/вектора
void out(int x) { cout << setw(8) << x; }

// функциональный объект для алгоритма for_each()
class Output : unary_function<int, ostream&>
{
public:
    ostream& operator()(int x) const { cout << setw(6) << x; return cout; }
};

#pragma endregion

// демонстрация некоторых алгоритмов STL
void App::algorithmsDemo()
{
    // модифицирующие алгоритмы

	// функтор для generate() - генерит СЧ без 0
	// !! можем определять класс в функции !!
	class Random
	{
        int lo_, hi_;
	
	public:
		Random():Random(-10, 10) {}
		Random(int lo, int hi):lo_(lo), hi_(hi) {}

		// !!! то, для чего и делается функтор !!!
		int operator()() {
            int x;
            do x = getRand(lo_, hi_);  while (x == 0);
            return x;
		}
	};

    // generate()
	// ожидает функцию или функтор без аргументов
    vector<int> v1(N);
    generate(v1.begin(), v1.end(), get_rand);
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // Random() - создание анонимного функционального объекта, т.е.
    // анонимного функтора
    generate(v1.begin(), v1.end(), Random(-20, 30));
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";
    
    // random_shuffle() перемешать элементы вектора, массива
    random_shuffle(v1.begin(), v1.end());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

	// применение алгоритмов к массивам
    int arr[N];
    generate(arr, arr + N, get_rand);
    cout << "    !!! ";
    for (auto v : arr) cout << setw(8) << v;
    cout << "\n\n";
	
    random_shuffle(arr, arr+N);
    cout << "    !!! ";
    for (auto v : arr) cout << setw(8) << v;
    cout << "\n\n";
	
    // transform() изменение всех элементов вектора/массива
    vector<int> v2(N);

	// измененные элементы вектора v1 записываем в вектор v2
	// применение функции в алгоритме
	transform(v1.begin(), v1.end(), v2.begin(), square);
    cout << "    ";
    for (auto v : v2) cout << setw(8) << v;
    cout << "\n\n";

	// перегенерируем вектор
    generate(v1.begin(), v1.end(), Random());
    cout << "    Перегенерировали v1: ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // измененные элементы вектора v1 записываем в тот же вектор v1
    // применение функции в алгоритме
	transform(v1.begin(), v1.end(), v1.begin(), square);
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // измененные элементы вектора v1 записываем в вектор v2
	// применение функтора в алгоритме
    transform(v1.begin(), v1.end(), v2.begin(), Square());
    cout << "    ";
    for (auto v : v2) cout << setw(8) << v;
    cout << "\n\n";

    // измененные элементы вектора v1 записываем в тот же вектор v1
    // применение функции в алгоритме
    transform(v1.begin(), v1.end(), v1.begin(), Square());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

  
    // sort(), сортировка без функции/функтора, с функцией/функтором
    sort(v1.begin(), v1.end());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

	// сортировка по убыванию при помощи стандартного функтора greater
	// !!! требуется наличие перегруженной операции > в типе !!!
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";
    
	// еще раз перегенерируем вектор
    generate(v1.begin(), v1.end(), Random());
	
    // не модифицирующие алгоритмы
    // for_each()
    cout << "    Отсортированный массив:\n    ";
    for_each(v1.begin(), v1.end(), out);
    cout << "\n\n";
	
    // сортировка при помощи анонимного функтора
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "    Отсортированный по убыванию вектор:\n    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // не модифицирующие алгоритмы
    // for_each()
    cout << "    Отсортированный вектор:\n    ";
    for_each(v1.begin(), v1.end(), out);
    cout << "\n\n";

	// перемешаем вектор и отсортируем по правилу "Отрицательные впереди"
	// при помощи функтора, вывод вектора - тоже при помощи функтора
    random_shuffle(v1.begin(), v1.end());
    cout << "    Вектор для обработки:\n    ";
    for_each(v1.begin(), v1.end(), Output());
    cout << "\n";
	
    sort(v1.begin(), v1.end(), NegativeFirst());
	
    cout << "    Отсортированный вектор, \"отрицательные впереди\":\n    ";
    for_each(v1.begin(), v1.end(), Output());
    cout << "\n\n";
  
} // App::algorithmsDemo