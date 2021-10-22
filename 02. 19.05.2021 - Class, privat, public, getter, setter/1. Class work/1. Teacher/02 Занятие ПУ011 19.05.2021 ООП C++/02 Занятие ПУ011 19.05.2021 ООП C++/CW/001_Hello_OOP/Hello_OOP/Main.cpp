#include "pch.h"
#include "Utils.h"
#include "Trapezium.h"
#include "Point.h"

void demoTrapezium();
void demoPoint();

int main()
{
	// настройка вывода в консоль
	init(L"Занятие 19.05.2021 - начало курса ООП");
    cout << "\nПривет, ПУ011! С первым классом Вас!\n";
	
    // demoPoint();
	
	demoTrapezium();

    getKey();
    return 0;
} // main


// -------------------------------------------------------------------------


// Вывод массива точек points, размер массива n элементов
// перед массивом выводим текст text
void showPoints(Point* points, int n, const char* text);

// Заполнение массива точек points вычисяемыми значениями,
// размер массива n элементов
void fillPoints(Point* points, int n);

// Пример использования класса Point
void demoPoint()
{
	cout << "\n\n";
	
	// Объявление - создание объектов
	Point point1;              // вызов конструктора по умолчанию
	Point point2(3., 7.);  // вызов инициирующего конструктора
	Point point3{ -1., -1. };  // вызов инициирующего конструктора

	// операция . - доступ к полям и методам для обычной переменной
	cout << "точка 1: "; point1.show();
	cout << "точка 2: "; point2.show();
	cout << "точка 3: "; point3.show();

	cout << "\n";

	cout<< "точка 1: " << point1.toString() << "\n"
	    << "точка 2: " << point2.toString() << "\n"
	    << "точка 3: " << point3.toString() << "\n";
	
	// вызов алгоритма swap() из STL (Standart template library) :)
	swap(point1, point3);
	cout << "\nПосле обмена:\nточка 1: " << point1.toString() << "\n";
	cout << "точка 3: " << point3.toString() << "\n";

	cout << "\n\n";

	cout << "point1.x = " << point1.getX()
		<< "; point1.y = " << point1.getY() << "\n";
	cout << "point3.x = " << point3.getX()
		<< "; point3.y = " << point3.getY() << "\n";

	point2.setX(-25.55);
	point2.setY(101.98);
	cout << "point2.x = " << point2.getX()
		<< "; point2.y = " << point2.getY() << "\n";

	// создание динамических объектов 
	Point* pPoint1 = new Point;
	Point* pPoint2 = new Point(-8., 5.03);
	Point* pPoint3 = new Point{ 11., -5.1 };

	cout << "\n";
	cout << "Размер в стеке статического объекта                       : " << sizeof(point1) << "\n"
		<< "Размер в стеке динамического объекта (указатель на объект): " << sizeof(pPoint1) << "\n"
		<< "Размер в куче динамического объекта  (поля объекта)       : " << sizeof(*pPoint1) << "\n";

	// операция -> доступ к полям, методам объекта через указатель
	pPoint1->setX(25.4);
	pPoint1->setY(9.28);
	cout << "Новые координаты " << pPoint1->toString() << "\n";

	// освобождение памяти - вызов деструктора при выполнении операции delete
	delete pPoint1;
	delete pPoint2;
	delete pPoint3;
	
	cout << "\n\n";

	// Массив объектов
	// а) статический
	const int N = 3;
	Point points1[N] = {
		Point(1., 6.),
		Point(5., 9.),
		Point(12., 3.)
	};
	showPoints(points1, N, "\nМассив точек:\n");
	
	Point points2[N];
	fillPoints(points2, N);
	showPoints(points2, N, "\nЕще массив точек:\n");
	
	// б) динамический
	Point* points3 = new Point[N]{
		Point(-1., 3.),
		Point(0., -10.),
		Point(5, 15.)
	};
	showPoints(points3, N, "\nДинамический массив точек:\n");
	
	
	Point* points4 = new Point[N];
	fillPoints(points4, N);
	showPoints(points4, N, "\nЕще динамический массив точек:\n");

	delete[] points3;
	delete[] points4;
	
	cout << "\n";
} // demoPoint


// Демо - передача массива объектов в метод
// Вывод массива точек points размером n элементов
// перед массивом выводим текст text
void showPoints(Point* points, int n, const char* text)
{
	cout << text;
	for (int i = 0; i < n; ++i) {
		// cout << (points + i)->toString() << "\n";
		cout << points[i].toString() << "\n";
	} // for i
} // showPoints


// Заполнение массива точек points размером n элементов
// вычисляемыми значениями
void fillPoints(Point* points, int n)
{
	for (int i = 0; i < n; ++i) {
		// так правильнее
		points[i] = Point(10. * i, -25 + i);

		// демонстрация доступа к методам объекта - элемента массива
		// points[i] = Point();
		// points[i].setX(10.*i);
		// points[i].setY(-25. + i);
	} // for i
} // fillPoints

 
// Пример использования объектов класса Trapezium
void demoTrapezium()
{
    try {
        // создание объекта при помощи конструктора по умолчанию
        Trapezium trapezium;
        cout << trapezium.getA() << ", " << trapezium.getB() << ", " << trapezium.getC() << "\n";

        // создание объектов при помощи конструкторов с параметрами        
        Trapezium trapezium1(4, -5, 6);
        // Trapezium trapezium1(4, 5, 6);
        Trapezium trapezium2(3, 5, 6);
        cout << trapezium1.getA() << ", " << trapezium1.getB() << ", " << trapezium1.getC() << "\n";
        cout << trapezium2.getA() << ", " << trapezium2.getB() << ", " << trapezium2.getC() << "\n";

        // поменяем стороны трапеции при помощи сеттеров
        trapezium.setA(3);
        trapezium.setB(3);
        trapezium.setC(5);
        cout << trapezium.getA() << ", " << trapezium.getB() << ", " << trapezium.getC() << "\n";
        
        // применение методов класса - не сеттеров
        double area = trapezium1.area();
        double perimeter = trapezium1.perimeter();
        cout << area << "   " << perimeter << "\n";

        cout << "\nРасчеты трапеций завершены\n";
    } catch (exception &ex) {
         cout << "\n\n" << ex.what() << "\n\n";
    } // try-catch

} // demoTrapezium
