#include "pch.h"
#include "App.h"
#include "Utils.h"

#include <vector>    // ����������� ������ vector
#include <deque>     // ����������� ������ deque
#include <list>      // ���������� ������
#include <stack>     // ���������� ����
#include <queue>     // �������

// ������
void App::demoVector()
{
	try {
		// ������������ ��� ������ vector
		vector<int> vector1;

		// ������� ������ �� 5 ���������, ��������� ��������� -1
		vector<int> vector2(5, -1);

		// ���������� �����������
		vector<int> vector3(vector2);

		cout << "\nvector2: ";
		// ������������� ��������� ��� �������
		for(vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
			cout << setw(5) << *it;  // ������������ ��������
		cout << endl;

		// auto - �������������� ��������� ����
		// ������ ������������� ��������� �� ������
		for(auto it = vector2.begin(); it != vector2.end(); ++it)
			*it = getRand(-10, 10);  // ������������ ��������
		cout << endl;

		cout << "\nvector2: ";
		// ������������� ��������� ��� �������
		for(vector<int>::iterator it = vector2.begin(); it != vector2.end(); ++it)
			cout << setw(5) << *it;  // ������������ ��������
		cout << endl;
		
		// �������� = []
		vector1 = vector2;
		cout << "\nvector1: ";
		for(size_t i = 0; i != vector1.size(); ++i)
			cout << setw(5) << vector1[i];  
		cout << endl;

		// ���� "��� �������" for_each 
		cout << "\nvector1: ";
		for (auto datum:vector1) // �� ������
			cout << setw(5) << datum;  
		cout << endl;

		for (auto &datum : vector1) // �� ������
			datum += 42;

		cout << "\nvector1: ";
		for (auto datum : vector1) // �� ������
			cout << setw(5) << datum;
		cout << endl;

		// == !=
		bool r = vector1 == vector2;
		cout << boolalpha;
		cout << "\nvector1 == vector2: " << r << "\n";
		
		cout << "\nvector1: ";
		for(int i = 0; i < vector1.size(); ++i)
			cout << setw(5) << vector1[i];  
		cout << endl;

		cout << "\nvector2: ";
		for(int i = 0; i < vector2.size(); ++i)
			cout << setw(5) << vector2[i];  
		cout << endl;

		r = vector1 != vector2;
		cout << "\nvector1 !=  vector2: " << r << "\n";

		r = vector1 > vector2;
		cout << "\nvector1 >  vector2: " << r << "\n";

		r = vector1 < vector2;
		cout << "\nvector1 <  vector2: " << r << "\n";
		
		cout << "\n\n����������� �������:\npush_back()\n";
		for (int i = 0; i < 3; i++)
			vector3.push_back(getRand(-100, 100));

		cout << "\nvector3: ";
		for(auto var:vector3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;
		
		cout << "\n\ninsert()\n";
		vector3.insert(vector3.begin()+vector3.size()-1, getRand(-100, 100));
		cout << "\nvector3: ";
		for(auto var:vector3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;
		
		vector3.insert(vector3.begin()+vector3.size(), getRand(-100, 100));
		cout << "\n\nvector3: ";
		for(auto var:vector3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;
		
		vector3.insert(vector3.begin(), getRand(-100, 100));
		cout << "\nvector3: ";
		for(auto var:vector3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;

		vector1.clear();
		vector1.insert(vector1.begin(), getRand(-10, 10));
		cout << "\nvector1: ";
		for(auto var:vector1) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;
		
		// �������� ��������� �������
		cout <<"\n\nerase()\n";
		cout << "\nvector2: ";
		for(auto var:vector2) {
			cout << setw(5) << var; 
		} // for each

		vector2.erase(vector2.begin()+1);
		cout << "\nvector2: ";
		for(auto var:vector2) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;
		
		cout<< "\n\n���������� ������� �������\n";
		// ����������� ������ �������, ��� ���� ������ capacity
		for (size_t i = 0; i < 200'000; i++) vector2.push_back(getRand(-10, 10));
		cout << "capacity: " << setw(2) << vector2.capacity() << "; size: " << setw(2) << vector2.size() << "\n";

		// �������� ��������� � ������ ������� 
		for (size_t i = 0; i < 200'000; i++)vector2.pop_back();
		cout << "capacity: " << setw(2) << vector2.capacity() << "; size: " << setw(2) << vector2.size() << "\n";

		// ���������� ������� ������� ��� �������� ������
		vector2.shrink_to_fit();
		cout << "capacity: " << setw(2) << vector2.capacity() << "; size: " << setw(2) << vector2.size() << "\n";

		/*
		vector<App *> v = {new App(), new App(), new App(), new App() };
		v[0]->demoQueue();
		*/
	} catch (exception &ex) {
		cout << ex.what() << "\n";
	} // try-catch
} // demoVector


// ���
void App::demoDeque()
{
	
	try {
		// ������������ ��� ������ deque
		deque<int> deque1;

		// ������� ��� �� 5 ���������, ��������� ��������� -1
		deque<int> deque2(5, -1);

		// ���������� �����������
		deque<int> deque3(deque2);

		cout << "\ndeque2: ";
		// ������������� ��������� ��� ����
		for(deque<int>::iterator it = deque2.begin(); it != deque2.end(); ++it)
			cout << setw(5) << *it;  // ������������ ��������
		cout << endl;

		for(auto it = deque2.begin(); it != deque2.end(); ++it)
			*it = getRand(-10, 10);  // ������������ ��������
		cout << endl;

		cout << "\ndeque2: ";
		// ������������� ��������� ��� ����
		for(deque<int>::iterator it = deque2.begin(); it != deque2.end(); ++it)
			cout << setw(5) << *it;  // ������������ ��������
		cout << endl;

		// �������� = []
		deque1 = deque2;
		cout << "\ndeque1: ";
		for(int i = 0; i < deque1.size(); ++i)
			cout << setw(5) << deque1[i];  
		cout << endl;

		// == !=
	    deque1[0] *= 10; 
		bool r = deque1 == deque2;
		cout << boolalpha;
		cout << "\ndeque1 == deque2: " << r << "\n";
		
		cout << "\ndeque1: ";
		for(int i = 0; i < deque1.size(); ++i)
			cout << setw(5) << deque1[i];  
		cout << endl;

		cout << "\ndeque2: ";
		for(int i = 0; i < deque2.size(); ++i)
			cout << setw(5) << deque2[i];  
		cout << endl;

		r = deque1 != deque2;
		cout << "\ndeque1 >  deque2: " << r << "\n";

		cout << "\n����������� ����:\npush_back()\n";
		for (int i = 0; i < 3; i++)
			deque3.push_back(getRand(-100, 100));

		cout << "\ndeque3: ";
		for(auto var:deque3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;
		
		cout << "\ninsert()\n";
		deque3.insert(deque3.begin()+deque3.size()-1, getRand(-100, 100));
		cout << "\ndeque3: ";
		for(auto var:deque3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;

		deque3.insert(deque3.begin()+deque3.size(), getRand(-100, 100));
		cout << "\ndeque3: ";
		for(auto var:deque3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;

		deque3.insert(deque3.begin(), getRand(-100, 100));
		cout << "\ndeque3: ";
		for(auto var:deque3) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;

		deque1.clear();
		deque1.insert(deque1.begin(), getRand(-10, 10));
		cout << "\ndeque1: ";
		for(auto var:deque1) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;

	    cout << "\ndeque2: ";
		for(auto var:deque2) {
			cout << setw(5) << var; 
		} // for each
		
		cout <<"\n\nerase()\n";
		deque2.erase(deque2.begin()+1);
		cout << "\ndeque2: ";
		for(auto var:deque2) {
			cout << setw(5) << var; 
		} // for each
		cout << endl;
	} catch (exception &ex)	{
		cout << ex.what() << "\n";
	} // try-catch
	
} // demoDeque
