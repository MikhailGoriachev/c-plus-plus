#include "App.h"
#include "DblList.h"
#include "Palette.h"
#include "Utils.h"
#include "Person.h"
#include "Date.h"
#include "DblList.h"
#include "Applicant.h"
#include "Queue.h"
#include "ApplicantQueue.h"


/*
Реализуйте класс Person, представляющий данные о жителе некоторого города, поля класса фамилия, имя, отчество (все три поля типа char *), рост в сантиметрах (тип double), вес в килограммах (тип double), город проживания (тип char *).
Создайте список экземпляр класса двусвязного списка DblList<Person>, не менее 12 узлов. Закодируйте обработки (при помощи итератора):
	•	изменить вес каждого жителя на некоторое случайное значение (для каждого жителя значение свое, но не более 0.5% от веса жителя)
	•	скопировать в отдельный список DblList<Person> жителей заданного города, название города вводить с клавиатуры
*/
void App::task1()
{

	cout << "\n\tЗадача 1. Реализуйте класс Person, представляющий данные о жителе некоторого города, поля класса фамилия, имя, отчество (все три поля типа char *),"
		 << "\n\t          рост в сантиметрах (тип double), вес в килограммах (тип double), город проживания (тип char *)."
		 << "\n\t          Создайте список экземпляр класса двусвязного списка DblList<Person>, не менее 12 узлов.Закодируйте обработки(при помощи итератора) :"
		 << "\n\t          •	изменить вес каждого жителя на некоторое случайное значение(для каждого жителя значение свое, но не более 0.5 % от веса жителя)"
		 << "\n\t          •	скопировать в отдельный список DblList<Person> жителей заданного города, название города вводить с клавиатуры\n";


	const int N_ARR_SIZE = 12;
	//Person arr[N_ARR_SIZE];
	Person arr[N_ARR_SIZE]{
		Person("Петров","Иван","Сергеевич",175,80,"Донецк"),
		Person("Иванов","Петр","Алексеевич",185,80,"Шахтерск"),
		Person("Ветров","Николай","Андреевич",182,80,"Енакиево"),
		Person("Шпак","Инна","Тимофеевна",172,80,"Макеевка"),
		Person("Сударь","Артем","Тимофеевич",192,80,"Донецк"),
		Person("Кравец","Ксения","Викторовна",169,80,"Донецк"),
		Person("Самойлов","Виктор","Сергеевич",198,80,"Шахтерск"),
		Person("Дятлов","Иван","Иванович",183,80,"Горловка"),
		Person("Толстой","Лев","Николаевич",189,80,"Дебальцево"),
		Person("Золотов","Евгений","Львович",180,80,"Углегорск"),
		Person("Смирнов","Иван","Сергеевич",185,80,"Шахтерск"),
		Person("Васильева","Ксения","Викторовна",181,80,"Горловка"),


	};
	list_.clear();
	list_.addAll(arr, N_ARR_SIZE);

	cout << "\n\tЭкземпляр класса двусвязного списка : " << Person::showHeader<<list_<<Person::showFooter;
	

	DblList<Person>::Iterator<Person> iterator(list_);

	for (iterator.begin(); iterator != iterator.end(); ++iterator) {
		Person &p = iterator.get();
		double weight = p.getWeight();
		p.setWeight(weight + getRand(-0.5, 0.5)/100 * weight);
				
	}

	cout << "\n\tЭкземпляр класса двусвязного списка c изменением массы тела : " << Person::showHeader << list_ << Person::showFooter;

	char* searchCity = new char[Person::CURRENTCITY_SIZE];
	cout << "\n\tВведите название города для поиска : ";
	setCursorVisible(true);
	cin.getline(searchCity, Person::CURRENTCITY_SIZE);

	DblList<Person> cityList_;

	for (iterator.begin(); iterator != iterator.end(); ++iterator) {

		if (strcmp(iterator.get().getCurrentCity(), searchCity) == 0) {
			cityList_.add(*iterator);
		}

	}


	if (!cityList_.isEmpty())
		cout << "\n\tСписок жителей города " << searchCity << " : " << Person::showHeader << cityList_ << Person::showFooter;
	else
		cout << "\n\tТакого города нет в списке!";



}

void App::task2() {

	cout << "\n\tЗадача 2. С использованием шаблонного класса очереди с итератором реализовать очередь нуждающихся в улучшении жилищных условий."
		<< "\n\t          Заполняйте очереди из массивов, на менее 10 элементов в массиве."
		<< "\n\t          Элемент очереди должен хранить фамилию, имя и отчество претендента, количество членов семьи, площадь квартиры в м2,"
		<< "\n\t          количество комнат, дату постановки на учет(день, месяц, год – класс Date).Очередь имеет название,"
		<< "\n\t          хранит имя бинарного файла для данных."
		<< "\n\t          Реализовать дополнительно операции(при помощи итераторов) :"
		<< "\n\t          •	Скопировать в двусвязный список(шаблонный класс DblList<> из предыдущих занятий) все записи очереди нуждающихся в улучшении"
		<< "\n\t            жилищных условий с заданным количеством комнат.Количество комнат вводить с клавиатуры"
		<< "\n\t          •	Скопировать в другую очередь нуждающихся в улучшении жилищных условий записи исходной очереди с заданным диапазоном площади квартиры."
		<< "\n\t            Диапазон площадей вводить с клавиатуры";
		
	
	Applicant arr1[]{
		Applicant("Петров", "Иван", "Сергеевич",1,20.,1, Date::getRandDate()),
		Applicant("Иванов", " Петр", " Алексеевич",3,66.2,3, Date::getRandDate()),
		Applicant("Ветров", " Николай", " Андреевич",2,45.1,2, Date::getRandDate()),
		Applicant("Шпак", " Инна", " Тимофеевна",1,32.,1, Date::getRandDate()),
		Applicant("Сударь", " Артем", " Тимофеевич",4,85.9,3, Date::getRandDate()),
		Applicant("Кравец", " Ксения", " Викторовна",2,50.5,2, Date::getRandDate()),
		Applicant("Самойлов", " Виктор", " Сергеевич",1,20.,2, Date::getRandDate()),
		Applicant("Дятлов", " Иван", " Иванович",2,40.2,2, Date::getRandDate()),
		Applicant("Толстой", " Лев", " Николаевич",5,120.,4, Date::getRandDate()),
		Applicant("Золотов", " Евгений", " Львович",3,66.5,3, Date::getRandDate()),
	};

	DblList<Applicant> newList(arr1, 10);
	Queue<Applicant> newQueue(arr1,10);
	ApplicantQueue newApplicantQueue("fileName.bin", "Очередь1", newQueue);

	cout << newApplicantQueue;

	int colRooms;
	cout << "\n\tВведите количество комнат: ";
	setCursorVisible(true);
	cin >> colRooms;


	DblList<Applicant> newListFoRooms;

	DblList<Applicant>::Iterator<Applicant> iterator(newList);


	for (iterator.begin(); iterator != iterator.end(); ++iterator) {

		if (iterator.get().getRooms() == colRooms) {
			newListFoRooms.add(*iterator);
		}

	}

	if (!newListFoRooms.isEmpty())
		cout << "\n\tСписок претендентов на квартиру с " << colRooms << " комнатами : " << Applicant::showHeader << newListFoRooms << Applicant::showFooter;
	else
		cout << "\n\tПретендентов на квартиру с " << colRooms << " комнатами нет! \n";

	


	double minArea,maxArea;
	cout << "\n\tВведите дипазон площади(мин макс): ";
	setCursorVisible(true);
	cin >> minArea>> maxArea;

	newListFoRooms.clear();
	for (iterator.begin(); iterator != iterator.end(); ++iterator) {

		double area = iterator.get().getArea();


		if (area>=minArea&&area<=maxArea) {
			newListFoRooms.add(*iterator);
		}

	}

	if (!newListFoRooms.isEmpty()) {
		cout << "\n\tСписок претендентов на квартиру с " << colRooms << " комнатами : " << Applicant::showHeader << newListFoRooms << Applicant::showFooter;
		
		
		Queue<Applicant> newQueue(newListFoRooms);
		ApplicantQueue newApplicantQueue("fileName.bin", "Очередь2.По площади кваритры", newQueue);
		cout << newApplicantQueue;
	
	
	}		
	else
		cout << "\n\tПретендентов на квартиру с квартиру с площадью от " <<minArea << " до "<<maxArea<<" комнатами нет! \n";




}

// Демонстрация записи в бинарный файл/чтения из бинарного файла
void App::ReadWritePersons()
{

	cout << "\n\tДанные для записи в файл: " << Person::showHeader
		<< list_
		<< Person::showFooter;
	
	// запиь в бинарный файл
	const char* fileName = "people.bin";

	FILE *f = fopen(fileName, "wb");
	if (f == nullptr)
		throw exception("Не могу открыть файл для записи");

	DblList<Person>::Iterator<Person> iterator(list_);
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		(*iterator).write(f);
	}
	
	fclose(f);

	list_.clear();
	cout << "\n\tСписок очищен: " << Person::showHeader
		<< list_
		<< Person::showFooter;

	// чтение из бинарного файла
	f = fopen(fileName, "rb");
	if (f == nullptr)
		throw exception("Не могу открыть файл для чтения");

	Person p;
	/*
	while(true) {
		p.read(f);
		if (feof(f)) break;
		
		list_.add(p);
	}
	*/
	
	fseek(f, 0, SEEK_END);
	int fileSize = ftell(f);
	fseek(f, 0, SEEK_SET);
	int n = fileSize / Person::getRecordSize();

	for (int i = 0; i < n; ++i)
	{
		p.read(f);
		list_.add(p);
	}
	
	fclose(f);

	cout<< "\n\tПрочитано из файла: " << Person::showHeader
	    << list_
	    << Person::showFooter;
} // App::ReadWritePersons

