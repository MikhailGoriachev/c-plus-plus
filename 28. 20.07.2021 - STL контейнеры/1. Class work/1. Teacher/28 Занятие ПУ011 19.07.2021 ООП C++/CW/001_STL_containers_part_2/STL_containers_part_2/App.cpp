#include "pch.h"
#include "App.h"
#include "Utils.h"

#include <list>      // двусвязный список
#include <stack>     // двусвязный стек
#include <queue>     // очередь



// классы slist, list
// slist - односвязный список
// list  - двусвязный список
void App::demoSlistList()
{
	try {
		list<int> intList;
		for (size_t i = 0; i < 5; i++) {
			intList.push_back(1);
		}
		
		intList.push_back(-1);
		intList.push_back(5);

		for(auto item:intList) cout << setw(5) << item; cout << endl;
		
        // поиск значения в списке и удаление найденного элемента
        cout << "\nfind(,,-1) + erase(-1):\n";
		auto iterator = find(intList.begin(), intList.end(), -1);
		intList.erase(iterator);
		for(auto it:intList) cout << setw(5) << it; cout << endl;

        // удалить все вхождения элемента
        cout << "\nremove(1) - удаление всех элементов, равных 1:\n";
		intList.remove(1);
		for(auto it:intList) cout << setw(5) << it; cout << endl;
		
		cout << endlm(2);
		for (size_t i = 0; i < 5; i++) {
			intList.push_back(getRand(-10, 10));
		}
		for(auto it:intList) cout << setw(5) << it; cout << endl;
		
		intList.sort();
		for(auto it:intList) cout << setw(5) << it; cout << endl;

		intList.reverse();
		for(auto it:intList) cout << setw(5) << it; cout << endl;

		intList.reverse();
		for(auto it:intList) cout << setw(5) << it; cout << endl;
		
		// оставить уникальные элементы в списке
		cout << endlm(2) << "Уникальные в intList: ";
		intList.unique();
		for(auto it:intList) cout << setw(5) << it; cout << endl;

		
		list<int> intListB;
		cout << endlm(2) << "listB:\n";
		for (size_t i = 0; i < 5; i++) {
			intListB.push_back(getRand(-10, 10));
		}
		for(auto it:intListB) cout << setw(5) << it; cout << endl;

		// merge - слияние упорядоченных списков
		intList.sort();
		intListB.sort();
		cout << "list : ";  for (auto it : intList) cout << setw(5) << it; cout << endl;
		cout << "listB: ";  for (auto it:intListB) cout << setw(5) << it; cout << endl;

        cout << "\n\nmerge intListC.merge(intListB)\n";
		list<int> intListC = intList;

	    intListC.merge(intListB);
		cout << endlm(2) << "merge выполнен, listC:\n";
		for (auto it : intListC) cout << setw(5) << it; cout << endl;
		
		// TODO: посмотреть... https://it.wikireading.ru/35986
		// Только удаление intListB :(
		cout << "\n\nsplice:\n";
		intListC.splice(intListC.begin(), intListC);
		cout << "intListC: "; for (auto it : intListC) cout << setw(5) << it; cout << endl;
		cout << "intListB: "; for (auto it : intListB) cout << setw(5) << it; cout << endl;

	} catch (exception &ex)	{
		cout << ex.what() << "\n";
	} // try-catch
} // demoSlistList


// класс stack - адаптер для реализации доступа LIFO
// Last In First Out
void App::demoStack()
{
	try {
		stack<int> intStack;
        int n = getRand(5, 10);

		for (size_t i = 0; i < n; i++) {
			intStack.push(getRand(-10, 10));
		}

        // вывод стека в консоль - искусстовенное действие
		stack<int> intStack1 = intStack;  // копия стека
		while(!intStack1.empty()) {       // уничтожение копии выводом в консоль
			// !!! прочитать и убрать элемент
			// int t = intStack1.top();
			// intStack1.pop();
			cout << setw(5) << intStack1.top();
			intStack1.pop();
		} // while
        cout << endl;

        // пример на swap - меняются два стека
        cout << "    Размер intStack " << intStack.size() << ". Размер intStack1 = "
             << intStack1.size() << "\n\n";

        intStack.swap(intStack1);

        cout << "    Размер intStack " << intStack.size() << ". Размер intStack1 = "
             << intStack1.size() << "\n\n";

	} catch (exception &ex)	{
		cout << ex.what() << "\n";
	} // try-catch
} // demoStack


// класс queue - адаптер для реализации доступа FIFO
// First Input First Out
void App::demoQueue()
{
	try {
		queue<int> intQueue;
        int n = getRand(5, 10);

		for (size_t i = 0; i < n; i++) {
			intQueue.push(getRand(-10, 10));
		}

		queue<int> intQueue1 = intQueue;
		while(!intQueue1.empty()) {
			cout << setw(5) << intQueue1.front();
			intQueue1.pop();
		} // while

        cout << "\n\n    Первый: " << intQueue.front() << ", последний: " << intQueue.back()
             << "\n\n";

        // пример на swap - меняются две очереди
        cout << "   Размер intQueue " << intQueue.size() << ". Размер intQueue1 = "
             << intQueue1.size() << "\n\n";

        intQueue.swap(intQueue1);

        cout << "   Размер intQueue " << intQueue.size() << ". Размер intQueue1 = "
             << intQueue1.size() << "\n\n";
	} catch (exception &ex)	{
		cout << ex.what() << "\n";
	} // try-catch	
} // demoQueue