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
���������� ����� Person, �������������� ������ � ������ ���������� ������, ���� ������ �������, ���, �������� (��� ��� ���� ���� char *), ���� � ����������� (��� double), ��� � ����������� (��� double), ����� ���������� (��� char *).
�������� ������ ��������� ������ ����������� ������ DblList<Person>, �� ����� 12 �����. ����������� ��������� (��� ������ ���������):
	�	�������� ��� ������� ������ �� ��������� ��������� �������� (��� ������� ������ �������� ����, �� �� ����� 0.5% �� ���� ������)
	�	����������� � ��������� ������ DblList<Person> ������� ��������� ������, �������� ������ ������� � ����������
*/
void App::task1()
{

	cout << "\n\t������ 1. ���������� ����� Person, �������������� ������ � ������ ���������� ������, ���� ������ �������, ���, �������� (��� ��� ���� ���� char *),"
		 << "\n\t          ���� � ����������� (��� double), ��� � ����������� (��� double), ����� ���������� (��� char *)."
		 << "\n\t          �������� ������ ��������� ������ ����������� ������ DblList<Person>, �� ����� 12 �����.����������� ���������(��� ������ ���������) :"
		 << "\n\t          �	�������� ��� ������� ������ �� ��������� ��������� ��������(��� ������� ������ �������� ����, �� �� ����� 0.5 % �� ���� ������)"
		 << "\n\t          �	����������� � ��������� ������ DblList<Person> ������� ��������� ������, �������� ������ ������� � ����������\n";


	const int N_ARR_SIZE = 12;
	//Person arr[N_ARR_SIZE];
	Person arr[N_ARR_SIZE]{
		Person("������","����","���������",175,80,"������"),
		Person("������","����","����������",185,80,"��������"),
		Person("������","�������","���������",182,80,"��������"),
		Person("����","����","����������",172,80,"��������"),
		Person("������","�����","����������",192,80,"������"),
		Person("������","������","����������",169,80,"������"),
		Person("��������","������","���������",198,80,"��������"),
		Person("������","����","��������",183,80,"��������"),
		Person("�������","���","����������",189,80,"����������"),
		Person("�������","�������","�������",180,80,"���������"),
		Person("�������","����","���������",185,80,"��������"),
		Person("���������","������","����������",181,80,"��������"),


	};
	list_.clear();
	list_.addAll(arr, N_ARR_SIZE);

	cout << "\n\t��������� ������ ����������� ������ : " << Person::showHeader<<list_<<Person::showFooter;
	

	DblList<Person>::Iterator<Person> iterator(list_);

	for (iterator.begin(); iterator != iterator.end(); ++iterator) {
		Person &p = iterator.get();
		double weight = p.getWeight();
		p.setWeight(weight + getRand(-0.5, 0.5)/100 * weight);
				
	}

	cout << "\n\t��������� ������ ����������� ������ c ���������� ����� ���� : " << Person::showHeader << list_ << Person::showFooter;

	char* searchCity = new char[Person::CURRENTCITY_SIZE];
	cout << "\n\t������� �������� ������ ��� ������ : ";
	setCursorVisible(true);
	cin.getline(searchCity, Person::CURRENTCITY_SIZE);

	DblList<Person> cityList_;

	for (iterator.begin(); iterator != iterator.end(); ++iterator) {

		if (strcmp(iterator.get().getCurrentCity(), searchCity) == 0) {
			cityList_.add(*iterator);
		}

	}


	if (!cityList_.isEmpty())
		cout << "\n\t������ ������� ������ " << searchCity << " : " << Person::showHeader << cityList_ << Person::showFooter;
	else
		cout << "\n\t������ ������ ��� � ������!";



}

void App::task2() {

	cout << "\n\t������ 2. � �������������� ���������� ������ ������� � ���������� ����������� ������� ����������� � ��������� �������� �������."
		<< "\n\t          ���������� ������� �� ��������, �� ����� 10 ��������� � �������."
		<< "\n\t          ������� ������� ������ ������� �������, ��� � �������� �����������, ���������� ������ �����, ������� �������� � �2,"
		<< "\n\t          ���������� ������, ���� ���������� �� ����(����, �����, ��� � ����� Date).������� ����� ��������,"
		<< "\n\t          ������ ��� ��������� ����� ��� ������."
		<< "\n\t          ����������� ������������� ��������(��� ������ ����������) :"
		<< "\n\t          �	����������� � ���������� ������(��������� ����� DblList<> �� ���������� �������) ��� ������ ������� ����������� � ���������"
		<< "\n\t            �������� ������� � �������� ����������� ������.���������� ������ ������� � ����������"
		<< "\n\t          �	����������� � ������ ������� ����������� � ��������� �������� ������� ������ �������� ������� � �������� ���������� ������� ��������."
		<< "\n\t            �������� �������� ������� � ����������";
		
	
	Applicant arr1[]{
		Applicant("������", "����", "���������",1,20.,1, Date::getRandDate()),
		Applicant("������", " ����", " ����������",3,66.2,3, Date::getRandDate()),
		Applicant("������", " �������", " ���������",2,45.1,2, Date::getRandDate()),
		Applicant("����", " ����", " ����������",1,32.,1, Date::getRandDate()),
		Applicant("������", " �����", " ����������",4,85.9,3, Date::getRandDate()),
		Applicant("������", " ������", " ����������",2,50.5,2, Date::getRandDate()),
		Applicant("��������", " ������", " ���������",1,20.,2, Date::getRandDate()),
		Applicant("������", " ����", " ��������",2,40.2,2, Date::getRandDate()),
		Applicant("�������", " ���", " ����������",5,120.,4, Date::getRandDate()),
		Applicant("�������", " �������", " �������",3,66.5,3, Date::getRandDate()),
	};

	DblList<Applicant> newList(arr1, 10);
	Queue<Applicant> newQueue(arr1,10);
	ApplicantQueue newApplicantQueue("fileName.bin", "�������1", newQueue);

	cout << newApplicantQueue;

	int colRooms;
	cout << "\n\t������� ���������� ������: ";
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
		cout << "\n\t������ ������������ �� �������� � " << colRooms << " ��������� : " << Applicant::showHeader << newListFoRooms << Applicant::showFooter;
	else
		cout << "\n\t������������ �� �������� � " << colRooms << " ��������� ���! \n";

	


	double minArea,maxArea;
	cout << "\n\t������� ������� �������(��� ����): ";
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
		cout << "\n\t������ ������������ �� �������� � " << colRooms << " ��������� : " << Applicant::showHeader << newListFoRooms << Applicant::showFooter;
		
		
		Queue<Applicant> newQueue(newListFoRooms);
		ApplicantQueue newApplicantQueue("fileName.bin", "�������2.�� ������� ��������", newQueue);
		cout << newApplicantQueue;
	
	
	}		
	else
		cout << "\n\t������������ �� �������� � �������� � �������� �� " <<minArea << " �� "<<maxArea<<" ��������� ���! \n";




}

// ������������ ������ � �������� ����/������ �� ��������� �����
void App::ReadWritePersons()
{

	cout << "\n\t������ ��� ������ � ����: " << Person::showHeader
		<< list_
		<< Person::showFooter;
	
	// ����� � �������� ����
	const char* fileName = "people.bin";

	FILE *f = fopen(fileName, "wb");
	if (f == nullptr)
		throw exception("�� ���� ������� ���� ��� ������");

	DblList<Person>::Iterator<Person> iterator(list_);
	for (iterator.begin(); iterator != iterator.end(); ++iterator)
	{
		(*iterator).write(f);
	}
	
	fclose(f);

	list_.clear();
	cout << "\n\t������ ������: " << Person::showHeader
		<< list_
		<< Person::showFooter;

	// ������ �� ��������� �����
	f = fopen(fileName, "rb");
	if (f == nullptr)
		throw exception("�� ���� ������� ���� ��� ������");

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

	cout<< "\n\t��������� �� �����: " << Person::showHeader
	    << list_
	    << Person::showFooter;
} // App::ReadWritePersons

