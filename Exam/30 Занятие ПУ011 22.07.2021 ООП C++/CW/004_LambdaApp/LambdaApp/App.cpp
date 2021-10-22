#include "pch.h"
#include "Utils.h"
#include "App.h"

// -------------------------------------------------------------------------

// Обработка вектора при помощи анонимных функторов
void App::demoVector()
{
	showNavBarMessage(hintColor, "  Обработка вектора при помощи анонимных функторов");

    // Сформировать вектор из случайных вещественных чисел, диапазон
    // генерации вводите с клавиатуры. 
	vector<double> v1(getRand(8, 12));

	// ввод диапазона значений с клавиатуры
	double lo, hi;
	setCursorVisible(true);
	showInputLine("\n\n\n\n    Диапазон значений вектора: ", 20, hintColor);
	cin >> lo >> hi;
	setCursorVisible(false);
	setColor(mainColor);

	// проверка правильности ввода
	if (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		throw exception("Введено не число");
	} // if

	if (lo >= hi)
		throw exception("Ошибка ввода диапазона значений вектора");

	// генерация вектора и вывод вектора в консоль
	generate(v1.begin(), v1.end(), [lo, hi]() { return getRand(lo, hi); });
	showVectorPositive("\n\n    Вектор для обработки:\n", v1);

	// Сохранить вектор в форматированном потоке вывода при помощи
	// потокового итератора
	string fileName = "dbl_vector.txt";
	saveVector(fileName, v1);
	cout << "\n\n    Файл " << fileName << " записан\n";

	v1.clear();

	// Прочитать вектор из форматированного потока ввода при помощи
    // потокового итератора.
	loadVector(fileName, v1);
    
    // Умножить все элементы вектора на 2.
	transform(v1.begin(), v1.end(), v1.begin(), [](double x) { return x + x; });
	showVectorPositive("\n\n    Вектор после удвоения элементов:\n", v1);

	// Сохранить вектор в форматированном потоке вывода при помощи
	// потокового итератора
	saveVector(fileName, v1);
	cout << "\n    Вектор с удвоенными элементами записан в файл " << fileName << "\n";
	v1.clear();
	
	// Прочитать вектор из форматированного потока ввода при помощи
    // потокового итератора.
	loadVector(fileName, v1);

	// Упорядочить вектор по правилу – положительные в начало вектора.
	sort(v1.begin(), v1.end(), [](double x, double y) { return x >= 0 && y < 0; });
	
	// Вывести вектор с цветовым выделением положительных элементов
	showVectorPositive("\n\n    Вектор упорядочен по правилу \"положительные в начало вектора\"\n", v1);

	// Прочитать вектор из форматированного потока ввода при помощи потокового
    // итератора.
	loadVector(fileName, v1);
	
	// Упорядочить вектор по убыванию.
	sort(v1.begin(), v1.end(), greater<double>());
	
	// Вывести вектор с цветовым выделением отрицательных элементов
	showVectorNegative("\n\n    Вектор упорядочен по убыванию\n", v1);
} // App::demoVector


// ----------------------------------------------------------------------------

// вывод вектора с выделением цветом положительных элементов
void App::showVectorPositive(const string& title, const vector<double>& v)
{
	cout << title << fixed << setprecision(2) << "    ";
	int w;  // ширина поля вывода
	int c;  // счетчик выведенных элементов
	int m;  // перевод строки после вывода заданного количества элементов
	
	auto outPositive = [w, c, m](double value) mutable
	{
		cout << color(value >= 0 ? hintColor : mainColor) << setw(w) << value << "  "
			<< color(mainColor) << " ";
		if (++c % m == 0) cout << "\n    ";
	};

	for_each(v.begin(), v.end(), outPositive);
} // App::showVectorPositive

// вывод вектора с выделением цветом отрицательных элементов
void App::showVectorNegative(const string& title, const vector<double>& v)
{
	cout << title << fixed << setprecision(2) << "    ";

	int w;  // ширина поля вывода
	int c;  // счетчик выведенных элементов
	int m;  // перевод строки после вывода заданного количества элементов

	auto outNegative = [w, c, m](double value) mutable
	{
		cout << color(value < 0 ? hintColor : mainColor) << setw(w) << value << "  "
			<< color(mainColor) << " ";
		if (++c % m == 0) cout << "\n    ";
	};

	for_each(v.begin(), v.end(), outNegative);
} // App::showVectorNegative


// сохранение вектора в форматированном потоке вывода
void App::saveVector(const string &fileName, vector<double> &v)
{
	// поток вывода
	ofstream ofs(fileName);
	if (!ofs.is_open())
		throw exception(("Не могу открыть файл " + fileName + " для записи").c_str());

	// итератор вывода
	ostream_iterator<double> ofs_stream(ofs, "\n");

	for (auto element : v) {
		*ofs_stream = element;   // вывод в поток
		++ofs_stream;            // продвижение по потоку

		// ;)
		// ofs << element << endl;
	} // for element
	
	ofs.close();
}

// загрузка вектора из форматированного потока ввода
void App::loadVector(const string& fileName, vector<double> &v)
{
	ifstream ifs(fileName);
	if (!ifs.is_open())
		throw exception(("Не могу открыть файл " + fileName + " для чтения").c_str());
	
	istream_iterator<double> itStream(ifs);

	// каждый раз требуется очищать вектор,чтобы не накапливать
	// информацию в нем
	v.clear();
	
	while (itStream != istream_iterator<double>()) {
		double value = *itStream;   // фактическое чтение
		v.push_back(value);
		++itStream;
	} // while
	
	ifs.close();
} //App::loadVector

// ----------------------------------------------------------------

// Запись данных об автобусах в текстовый файл (форматированный поток вывода)
void App::demoInitializeAndWrite()
{
	showNavBarMessage(hintColor, "  Запись данных об автобусах в текстовый файл (форматированный поток вывода)");

	// если коллекции еще нет - подготовить ее
	if (buses_.empty())
		initialize();

	// записать коллекцию в форматированный поток вывода
	saveToStream();

	// и для контроля прочитать коллекцию, вывести коллекцию в консоль
	loadFromStream();
	showBuses(buses_, "\n\n\n\n    Коллекция автобусов для обработки в приложении:\n");
} // App::demoInitialize



// Чтение данных об автобусах из текстового файла (форматированного потока ввода)
void App::demoReadAndShow()
{
	showNavBarMessage(hintColor, "  Чтение данных об автобусах из текстового файла "
		"(форматированного потока ввода)");

	// собственно чтение из форматированного потока ввода
	loadFromStream();

	showBuses(buses_, "\n\n\n\n    Коллекция автобусов для обработки в приложении:\n");
} // App::demoReadAndShow


// Вывод данных об автобусах при помощи алгоритма for_each() и анонимного функтора
void App::demoShowBuses()
{
	showNavBarMessage(hintColor, "  Вывод данных об автобусах при помощи алгоритма "
		"for_each() и анонимного функтора");

	// если коллекция еще не загружена - загрузить из файла, если
	// еще и файла данных нет - вот тогда выбрасывается исключение
	if (buses_.empty())
		loadFromStream();
	
	showBuses(buses_, "\n\n\n\n    Автобусы для обработки в приложении:\n");
} // App::demoShowBuses


// Упорядочить коллекцию автобусов по регистрационным номерам, использовать sort()
void App::demoOrderByRegNumber()
{
	showNavBarMessage(hintColor, "  Упорядочить коллекцию автобусов по регистрационным "
		"номерам, использовать sort() и анонимный функтор");

	// если коллекция еще не загружена - загрузить из файла, если
	// еще и файла данных нет - вот тогда выбрасывается исключение
	if (buses_.empty())
		loadFromStream();

	// лямбда-выражение для сортировки коллекции по регистрационынм номерам
	auto predicate = [](const Bus &bus1, const Bus &bus2)
	{
		return bus1.getRegNum() < bus2.getRegNum();
	};

	sort(buses_.begin(), buses_.end(), predicate);
	showBuses(buses_, "\n\n\n\n    Автобусы, упрядоченные по регистрационным номерам:\n");
} // App::demoOrderByRegNumber 

// Упорядочить коллекцию автобусов по фамилии и инициалам водителя, использовать sort()
void App::demoOrderByFullName()
{
	showNavBarMessage(hintColor, "  Упорядочить коллекцию автобусов по фамилии и "
		"инициалам водителя, использовать sort() и анонимный функтор");

	// если коллекция еще не загружена - загрузить из файла, если
	// еще и файла данных нет - вот тогда выбрасывается исключение
	if (buses_.empty())
		loadFromStream();

	// использование лямбда-выражения для сортировки коллекции по фамилии и инициалам водителя
	auto lambda = [](const Bus& bus1, const Bus& bus2)
	{
		return bus1.getFullName() < bus2.getFullName();
	};
	
	sort(buses_.begin(), buses_.end(), lambda);
	showBuses(buses_, "\n\n\n\n    Автобусы, упрядоченные по фамилии и инициалам водителя:\n");
} // App::demoOrderByFullName


// ----------------------------------------------------------------

#pragma region Вспомогательные методы и функторы для коллекции автобусов
void App::showBuses(const vector<Bus>& buses, const string& title)
{
	int row = 1;
	
	// функтор - локальный тип
	auto outBus = [row](const Bus &bus) mutable 
	{
		cout << "   " << bus.toTableRow(row++) << endl;
	};
	
	cout << title << Bus::header;
	for_each(buses_.begin(), buses_.end(), outBus);
	cout << Bus::footer;
} // App::showBuses

// загрузка коллекции автобусов из потока
void App::loadFromStream()
{
	// чтение из файла при помощи итератора потока ввода
	ifstream ifs(fileName_);
	if (!ifs.is_open())
		throw exception(("Не могу открыть файл " + fileName_ + " для чтения").c_str());

	// получить итератор для ввода из форматированного потока 
	istream_iterator<Bus> stream_it(ifs);

	// перед чтением чистим вектор объектов, т.к. не требуется
	// добавление к существующему вектору прочитанных записей,
	// просто формирование нового набора данных в векторе
	buses_.clear();
	while (stream_it != istream_iterator<Bus>()) {
		Bus bus = *stream_it;   // фактическое чтение
		++stream_it;
		
		buses_.push_back(bus);
	}
	ifs.close();
} // App::loadFromStream

// сохранение коллекции автобусов в поток
void App::saveToStream()
{
	// потоковый итератор вывода для файлов
	ofstream ofs(fileName_);
	if (!ofs.is_open())
		throw exception(("Не могу открыть файл " + fileName_ + " для записи").c_str());
	
	ostream_iterator<Bus> ofs_stream(ofs, "");
	for (auto bus : buses_) {
		*ofs_stream = bus;  // вывод в поток вывода
		++ofs_stream;       // продвижение по выводу
	} // for bus
	ofs.close();
} // App::saveToStream

// Начальное формирование коллекций автобусов
void App::initialize()
{
	// начальные данные для заполнения 
	buses_ = {
		Bus("ВР512А", "Кравченко П.Р.",      "13",     "0"),
		Bus("ВР511О", "Кравченко О.Р.",      "11",    "11"),
		Bus("ВО523К", "Кравченко Д.В.",      "12",   "42а"),
		Bus("КА506Р", "Тимченко Д.С.",       "42",    "42"),
		Bus("ОК514А", "Аскольдиков И.В.",   "85а",   "85а"),
		Bus("АЕ503С", "Котов К.С.",          "35",    "35"),
		Bus("ЕН501О", "Сурин В.Н.",         "76б",     "0"),
		Bus("НК121Т", "Ларавель Р.М.",      "121е", "121е"),
		Bus("РР012А", "Симфонический Р.Т.", "119р",    "0"),
		Bus("ОН001Р", "Миронов Н.С.",       "121е", "121е"),
		Bus()
	};
} // App::initialize

// проверка существования файла
bool App::fileExists(const string& fileName)
{
	// открываем файл для чтения, если удалось - значит, файл
	// существует и доступен
	ifstream ifs(fileName);
	bool exists = ifs.is_open();
	ifs.close();

	return exists;
} // App::fileExists