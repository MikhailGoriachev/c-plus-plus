#include "pch.h"
#include "Utils.h"
#include "App.h"
#include "Person.h"

#include <vector>      // ������� - ������ ����������� ��� ���������

#include <iterator>    // ���������
#include <functional>  // ����������� �������� 
#include <algorithm>   // ����������� ���������
#include <numeric>     // ��������� ���������, ��������������� ��� ��������� �������� ������

// ��������� ���������
void App::iteratorsDemo()
{
    // ��������� ������
    istringstream istr("23 4 5 42 -12 34 33 8");
    istream_iterator<int> it(istr);

	// ������ ��� �������� �����
    vector<int> v1;
    
	// ������ �� ������ ����� �� ���������
	while(it != istream_iterator<int>()) {  // istream_iterator<int>() ������ ��������
        v1.push_back(*it);  // ���������� ������ �� ������
        ++it;               // ����������� ���������
	} // while

	// ����� �������
    cout << "   ";
    for (auto v : v1)
        cout << setw(8) << v;
    cout << "\n";
    
	// ������ �� ����� ��� ������ ��������� ������ �����
    ifstream in("file.txt");
    istream_iterator<int> stream_it(in);

    cout << "\n    ������ �� �����:";
	// while(!in.eof()) {
	while(stream_it != istream_iterator<int>()) {
        int value = *stream_it;   // ����������� ������
        cout << setw(8) << value;
        ++stream_it;
	}
    in.close();
    cout << "\n\n";

	// ��������� �������� ������
    // ------------------------------------------
    //                                ����� ������, �������������� ������, ����������� ����� 
    //                                ������� ������
    ostream_iterator<int> os_stream(cout, " ��/�2 ");
	*os_stream = 40'000;  // �����
    ++os_stream;          // ����������� �� ������, �� ������������... �� ���������� ������������
    *os_stream = 42;
    ++os_stream;

    // ���������� ���������� ��������� � �����
    cout << "\n    ��������� �������� � �����:\n";
    for (int i = 0; i < 10; ++i, ++os_stream) 
        *os_stream = i;
    cout << endlm(3);
    
	// ��������� �������� ������ ��� ������
    ofstream ofs("output.txt");
    ostream_iterator<int> ofs_stream(ofs, "\n");
    for (auto v : v1) {
        *ofs_stream = v;  // ����� � ����� ������
        ++ofs_stream;     // ����������� �� ������
    } // for v
    ofs.close();
    cout << "\n   ���� �������\n";

} // App::iteratorsDemo

// �������������� ������� - ������ � ������� ���������� �������� ()
// ��������
// ����� �������� ��������� �� ������� ��� �������� ���������� 

// ��������� ������ ��������� � STL
// binary_function<������1, ������2, �������������> - ������ ������� � 2�� �����������
// binary_function<int, int, short>        short  foo(int, int);
// binary_function<int, int, int>          int    foo(int, int)
// binary_function<bool, int, double>      double foo(bool, int);
// 
// unary_function<������,  �������������> - ������ ������� � 1� ����������               
// unary_function<Person, bool>             bool foo(Person)
// unary_function<int, int>                 int  foo(int)

// ������ ��������-�����������
class person_less_salary: public binary_function<Person &, Person &, bool>
{
public:
	bool operator()(Person &p1, Person &p2)
	{
        return p1.salary < p2.salary;
	}
};

// �������������� ������� - ������������
void App::functionalObjectsDemo()
{
	// ��� ��������� �������
    Person p1("�����", 23, 125'000.);
    Person p2("���",   21, 17'000.);

	// �������� ���������� ����������� �� ���� ��������
    person_less_salary compare_by_salary;
    bool r = compare_by_salary(p1, p2);
    cout << boolalpha << setprecision(2) << "    ����� (" << p1.salary<<") " << p1.name << " ������ ������ ("
	     << p2.salary << ") " << p2.name << ": " << r << "\n";

	cout << boolalpha << setprecision(2) << "    ����� (" << p1.salary<<") " << p1.name << " ������ ������ ("
	     << p2.salary << ") " << p2.name << ": " << compare_by_salary(p1, p2) << "\n";

	// ��� ���������� �������� + � ������ Person - ������ ����������
    // !!! ��������� ���������������� �������� + � ������ Person !!!
    plus<Person> add;
    Person p3 = add(p1, p2);
    cout << "   plus: " << p3.name << ": " << p3.salary << "\n";

	// ��� ���������� �������� - � ������ Person - ������ ����������
    // !!! ��������� ���������������� �������� - � ������ Person !!!
    // minus<Person> sub;
    // p3 = sub(p1, p2);
    // cout << "   minus: " << p3.name << ": " << p3.salary << "\n";

	// ����������� ������� ��� �������� �� ��������� equal_to - ��������� binary_function
	// !!! ��������� ���������������� �������� == � ������ Person !!!
    equal_to<Person> predicate;
    cout << "\n    p1 == p2: " << predicate(p1, p2) << "\n\n";
} // App::functionalObjectsDemo

#pragma region ��������������� ������
// ������ �������, ��������
static const int N = 10;

// ������������ ���������� ����� ��� ��������� generate()
int get_rand() {return getRand(-10, 10); }

// ������� ��� ������������ ��������� �������/������� 
int square(int x) { return x * x;  }

// �������������� ������ ��� ���������� � ������� ������ �����
class Square: public unary_function<int, int>
{
public:
    int operator()(int x) const { return x * x; }
};

// �������������� ������ ��� ������ ��������� sort() - ����������
// �� ������� - ������������� �������
class NegativeFirst : binary_function<int, int, bool>
{
public:
    bool operator()(int x, int y) { return x < 0 && y >= 0; }
};

// ������� ��� ������������ ��������� �������/�������
void out(int x) { cout << setw(8) << x; }

// �������������� ������ ��� ��������� for_each()
class Output : unary_function<int, ostream&>
{
public:
    ostream& operator()(int x) const { cout << setw(6) << x; return cout; }
};

#pragma endregion

// ������������ ��������� ���������� STL
void App::algorithmsDemo()
{
    // �������������� ���������

	// ������� ��� generate() - ������� �� ��� 0
	// !! ����� ���������� ����� � ������� !!
	class Random
	{
        int lo_, hi_;
	
	public:
		Random():Random(-10, 10) {}
		Random(int lo, int hi):lo_(lo), hi_(hi) {}

		// !!! ��, ��� ���� � �������� ������� !!!
		int operator()() {
            int x;
            do x = getRand(lo_, hi_);  while (x == 0);
            return x;
		}
	};

    // generate()
	// ������� ������� ��� ������� ��� ����������
    vector<int> v1(N);
    generate(v1.begin(), v1.end(), get_rand);
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // Random() - �������� ���������� ��������������� �������, �.�.
    // ���������� ��������
    generate(v1.begin(), v1.end(), Random(-20, 30));
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";
    
    // random_shuffle() ���������� �������� �������, �������
    random_shuffle(v1.begin(), v1.end());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

	// ���������� ���������� � ��������
    int arr[N];
    generate(arr, arr + N, get_rand);
    cout << "    !!! ";
    for (auto v : arr) cout << setw(8) << v;
    cout << "\n\n";
	
    random_shuffle(arr, arr+N);
    cout << "    !!! ";
    for (auto v : arr) cout << setw(8) << v;
    cout << "\n\n";
	
    // transform() ��������� ���� ��������� �������/�������
    vector<int> v2(N);

	// ���������� �������� ������� v1 ���������� � ������ v2
	// ���������� ������� � ���������
	transform(v1.begin(), v1.end(), v2.begin(), square);
    cout << "    ";
    for (auto v : v2) cout << setw(8) << v;
    cout << "\n\n";

	// �������������� ������
    generate(v1.begin(), v1.end(), Random());
    cout << "    ���������������� v1: ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // ���������� �������� ������� v1 ���������� � ��� �� ������ v1
    // ���������� ������� � ���������
	transform(v1.begin(), v1.end(), v1.begin(), square);
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // ���������� �������� ������� v1 ���������� � ������ v2
	// ���������� �������� � ���������
    transform(v1.begin(), v1.end(), v2.begin(), Square());
    cout << "    ";
    for (auto v : v2) cout << setw(8) << v;
    cout << "\n\n";

    // ���������� �������� ������� v1 ���������� � ��� �� ������ v1
    // ���������� ������� � ���������
    transform(v1.begin(), v1.end(), v1.begin(), Square());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

  
    // sort(), ���������� ��� �������/��������, � ��������/���������
    sort(v1.begin(), v1.end());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

	// ���������� �� �������� ��� ������ ������������ �������� greater
	// !!! ��������� ������� ������������� �������� > � ���� !!!
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";
    
	// ��� ��� �������������� ������
    generate(v1.begin(), v1.end(), Random());
	
    // �� �������������� ���������
    // for_each()
    cout << "    ��������������� ������:\n    ";
    for_each(v1.begin(), v1.end(), out);
    cout << "\n\n";
	
    // ���������� ��� ������ ���������� ��������
    sort(v1.begin(), v1.end(), greater<int>());
    cout << "    ��������������� �� �������� ������:\n    ";
    for (auto v : v1) cout << setw(8) << v;
    cout << "\n\n";

    // �� �������������� ���������
    // for_each()
    cout << "    ��������������� ������:\n    ";
    for_each(v1.begin(), v1.end(), out);
    cout << "\n\n";

	// ���������� ������ � ����������� �� ������� "������������� �������"
	// ��� ������ ��������, ����� ������� - ���� ��� ������ ��������
    random_shuffle(v1.begin(), v1.end());
    cout << "    ������ ��� ���������:\n    ";
    for_each(v1.begin(), v1.end(), Output());
    cout << "\n";
	
    sort(v1.begin(), v1.end(), NegativeFirst());
	
    cout << "    ��������������� ������, \"������������� �������\":\n    ";
    for_each(v1.begin(), v1.end(), Output());
    cout << "\n\n";
  
} // App::algorithmsDemo