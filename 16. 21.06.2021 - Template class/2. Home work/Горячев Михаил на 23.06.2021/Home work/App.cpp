#include "App.h"
#include "MenuItem.h"
#include "menu.h"
#include "Deque.h"
#include "Goods.h"
#include "Queue.h"
#include "pch.h"
#include "List.h"

/*
	������ 1. ������������ ��������� ������ Deque � Queue(��� � ������� 
		��������������) �� ���� ���������� ������ List(����������� ������)
		.������������ ���������� ����������, � ������� ����������������� 
		�������� � ����� � �������� ��� ����� int, char, Goods(����� ��� 
		������������� �������, ���� ������ � ��� ������ � ������������ 
		������, ���� �� ������� ������, ���������� ���������� ������ ������.
		� ������ ������ ���� ����������� ������������ � ����������, ������ 
		������� � ����� ��� ��������� � ��������� ����������, � ����� ������
		���������� ����� ������ �� ����� � ������������ ���� �� ������� 
		������ � ���������� ���������� ������ ������.����������� �������� 
		������������, ������).

	������ 2. ��� ������ ���������� ������ Stack(� ������������ �� 
		������� ������ ������� �� 12 ���������) ��� ������������� ����� 
		��������, ������ ������ ������������� �������� ����������� � 
		��������, � ������� � ������������ �����.
	
		���������� ����� ��������� �� �������� ������ � ������ ����������� ������,
		���������� ����� ���������� � �������������� � ������ ������.�� ��������� 
		����� �������� ���������� � ������������ �������.��� ����� ������ � ������ 
		����������� ������ ������������ �� ���������� ������, �� ������, ������� 
		��������� �������.��� ������ �������� ����������� ������, ����� ������ � 
		���������� ������ ������������ �� �����������.
		������������ ����� Parking ��� ������� ������ ��������.� ������ Parking 
		���������� ������ ���������� ���������� �� ��������, ������� ������������� 
		���������� � ��������.
*/


#pragma region �������

#pragma region ������� 1. ������������ Deque � Queue

/*
	������ 1. ������������ ��������� ������ Deque � Queue(��� � �������
		��������������) �� ���� ���������� ������ List(����������� ������)
		.������������ ���������� ����������, � ������� �����������������
		�������� � ����� � �������� ��� ����� int, char, Goods(����� ���
		������������� �������, ���� ������ � ��� ������ � ������������
		������, ���� �� ������� ������, ���������� ���������� ������ ������.
		� ������ ������ ���� ����������� ������������ � ����������, ������
		������� � ����� ��� ��������� � ��������� ����������, � ����� ������
		���������� ����� ������ �� ����� � ������������ ���� �� �������
		������ � ���������� ���������� ������ ������.����������� ��������
		������������, ������).
*/

// ������� 1. ������������ Deque � Queue
void App::task1()
{
	init(L"�������� ������� �� 23.06.2021 | ������� 1. ������������ Deque � Queue");

	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ������������ Deque � Queue (int)
		CMD_DEMO_INT,
		// ������������ Deque � Queue (char)
		CMD_DEMO_CHAR,
		// ������������ Deque � Queue (Goods)
		CMD_DEMO_GOODS,
	};

	// ���������� ������� ����
	const int N_MENU = 4;

	MenuItem items[N_MENU] = {
		MenuItem("������������ Deque � Queue (int)", CMD_DEMO_INT),
		MenuItem("������������ Deque � Queue (char)", CMD_DEMO_CHAR),
		MenuItem("������������ Deque � Queue (Goods)", CMD_DEMO_GOODS),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� ���� ����������", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// ������������ Deque � Queue (int)
			case CMD_DEMO_INT:
				app.task1DemoIntDeq();
				app.task1DemoIntQue();
				break;
				// ������������ Deque � Queue (char)
			case CMD_DEMO_CHAR:
				app.task1DemoCharDeq();
				app.task1DemoCharQue();
				break;
				// ������������ Deque � Queue (Goods)
			case CMD_DEMO_GOODS:
				app.task1DemoGoodsDeq();
				app.task1DemoGoodsQue();
				break;
			}
		}
		catch (exception& ex) {

			oss.str("");  // ������� ������ - ������ ������
			oss << "\n\t" << ex.what() << "\n";

			// ����� ������ � ���������� �� ������ � �����
			cputs(oss.str().c_str(), errColor);

		} // try-catch
	}

}

#pragma region ������������ Deque � Queue (int)

// ����� �����, n - ���������� ���������
ostream& showLine(ostream& os, int n)
{
	os << "\t+��������������������+";

	// ����� ����� ��� ���������� ���������
	for (size_t i = 0; i < n; i++)
	{
		os << "����+";
	}

	os << "\n";

	return os;
}

// ����� Deque (int)
/*void DequeIntOut(const Deque<int>& Deque)
{
	stringstream os;

	// ����� �����
	os << "\t+��������������������+�������������������+\n"
		<< "\t|   ����. ������: " << setw(2) << Deque.size_ << " |   ���. ������: " << setw(2) << Deque.back_ << " |\n";

	// ����� �����
	showLine(os, Deque.back_ < 4 ? 4 : Deque.back_);

	// ���� ��� ����
	if (Deque.back_ == 0)
		os << "\t|                                        |\n"
		<< "\t|                 ��� ����               |\n"
		<< "\t|                                        |\n"
		<< "\t+��������������������+�������������������+\n";

	// ���� ���� ��������
	else
	{
		// ����� ������� ��������
		os << "\t|  ������ ��������:  |";
		for (int i = 0; i < Deque.back_; i++)
		{
			os << " " << setw(2) << i << " |";
		}

		os << "\n";

		// ����� �����
		showLine(os, Deque.back_);

		// ����� ���������
		os << "\t|      ��������:     |";
		for (int i = 0; i < Deque.back_; i++)
		{
			// ������
			int tmp = Deque.data_[i];

			short clOld = getColor();

			// ������� ����
			short cl = tmp >= 'a' && tmp <= 'z' ? BLUE_ON_BLACK : RED_ON_BLACK;

			// ���� ����� ��������� ��� �������;

			os << color(cl) << "  " << Deque.data_[i] << " " << color(clOld) << "|";
		}

		os << "\n";

		// ����� �����
		showLine(os, Deque.back_);

	}

	cout << os.str();
}*/


// ��������� �������� ������ ������� int 
void showArrInt(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

// ������������ Deque � Queue (int)
void App::task1DemoIntDeq()
{
	cls();

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\t\t������������ ������ ���������� Deque � ����� int\n";

	// ������ ���� 
	Deque<int> deq;

	int size = 3;

	// ������ 
	int* arr = new int[3]{ 1,2,3 };
	int* arr1 = new int[3]{ -10,-20,-30 };
	int* arr2 = new int[3]{ 100,200,300 };

	cout << "\n\t�������� ��� Deque      : " << deq
		 << "\n\n\t���������� ���� ��������: ";

	// ������������ ������� 
	showArrInt(arr, size);

	// ���������� ���� ��������
	deq.pushAll(arr, size);

	int n = 99;

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ������ Deque"
		<< "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� �������� � ������: " << n;

	// ���������� �������� � ������ 
	deq.shift(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		 << "\n\n\t������ �������� � ������";

	// ������ �������� � ������ 
	n = deq.unshift();
	cout << "\n\tDeque                       : " << deq
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ������ ������� : ";

	// ������������ ������� 
	showArrInt(arr1, size);
	
	// ���������� � ������ �������
	deq.shiftAll(arr1, size);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � ������"
		<< "\n\tDeque                       : " << deq;

	// �������� �������� � ������
	n = deq.front();

	cout << "\n\t������� � ������            : " << n;

	n = -999;

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ����� Deque"
		<< "\n\n\t���������� �������� � ����� : " << n;

	// ���������� �������� � �����
	deq.push(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � �����";
		 
	// ������ �������� � �����
	n = deq.pop();

	cout << "\n\tDeque                       : " << deq
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ����� �������  : ";

	// ������������ ������� 
	showArrInt(arr2, size);

	// ���������� � ����� �������
	deq.pushAll(arr2, size);

	n = 687;

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � �����"
		<< "\n\tDeque                       : " << deq;

	// �������� �������� � ������
	n = deq.back();

	cout << "\n\t������� � �����             : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n";

	getKey();
}

// ������������ Deque � Queue (int)
void App::task1DemoIntQue()
{
	cls();

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\t\t������������ ������ ���������� Deque � ����� int\n";

	// ������ ���� 
	Queue<int> que;

	int size = 3;

	// ������ 
	int* arr = new int[3]{ 1,2,3 };
	int* arr1 = new int[3]{ -10,-20,-30 };
	int* arr2 = new int[3]{ 100,200,300 };

	cout << "\n\t�������� ��� Deque      : " << que
		<< "\n\n\t���������� ���� ��������: ";

	// ������������ ������� 
	showArrInt(arr, size);

	// ���������� ������� ��������
	que.enqueueAll(arr, size);

	int n = 99;

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ������ Queue"
		<< "\n\tQueue                       : " << que
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� �������� � ������: " << n;

	// ���������� �������� � ������ 
	que.enqueue(n);

	cout << "\n\tQueue                       : " << que
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � ������";

	// ������ �������� � ������ 
	n = que.dequeue();
	cout << "\n\tQueue                       : " << que
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ������ ������� : ";

	// ������������ ������� 
	showArrInt(arr1, size);

	// ���������� � ������ �������
	que.enqueueAll(arr1, size);

	cout << "\n\tQueue                       : " << que
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � ������"
		<< "\n\tQueue                       : " << que;

	// �������� �������� � ������
	n = que.front();

	cout << "\n\t������� � ������            : " << n;

	cout << "\n\n������������������������������������������������������������������������������\n\n";

	getKey();
}

#pragma endregion 

#pragma region ������������ Deque � Queue (char)

// ����� Deque (char)
/*void DequeCharOut(const Deque<char>& Deque)
{
	stringstream os;

	// ����� �����
	os << "\t+��������������������+�������������������+\n"
		<< "\t|   ����. ������: " << setw(2) << Deque.size_ << " |   ���. ������: " << setw(2) << Deque.back_ << " |\n";

	// ����� �����
	showLine(os, Deque.back_ < 4 ? 4 : Deque.back_);

	// ���� ��� ����
	if (Deque.back_ == 0)
		os << "\t|                                        |\n"
		<< "\t|                 ��� ����               |\n"
		<< "\t|                                        |\n"
		<< "\t+��������������������+�������������������+\n";

	// ���� ���� ��������
	else
	{
		// ����� ������� ��������
		os << "\t|  ������ ��������:  |";
		for (int i = 0; i < Deque.back_; i++)
		{
			os << " " << setw(2) << i << " |";
		}

		os << "\n";

		// ����� �����
		showLine(os, Deque.back_);

		// ����� ���������
		os << "\t|      ��������:     |";
		for (int i = 0; i < Deque.back_; i++)
		{
			// ������
			char tmp = Deque.data_[i];

			short clOld = getColor();

			// ������� ����
			short cl = tmp >= 'a' && tmp <= 'z' ? BLUE_ON_BLACK : RED_ON_BLACK;

			// ���� ����� ��������� ��� �������;

			os << color(cl) << "  " << Deque.data_[i] << " " << color(clOld) << "|";
		}

		os << "\n";

		// ����� �����
		showLine(os, Deque.back_);

	}

	cout << os.str();
}*/

// ��������� �������� ������ ������� int 
void showArrChar(char* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

// ������������ Deque � Queue (char)
void App::task1DemoCharDeq()
{
	cls();

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\t\t������������ ������ ���������� Deque � ����� char\n";

	// ������ ���� 
	Deque<char> deq;

	int size = 3;

	// ������ 
	char* arr = new char[3]{ 'a','b','c' };
	char* arr1 = new char[3]{ 'd','f','g' };
	char* arr2 = new char[3]{ 'h','i','m' };

	cout << "\n\t�������� ��� Deque      : " << deq
		<< "\n\n\t���������� ���� ��������: ";

	// ������������ ������� 
	showArrChar(arr, size);

	// ���������� ���� ��������
	deq.pushAll(arr, size);

	char n = 'Q';

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ������ Deque"
		<< "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� �������� � ������: " << n;

	// ���������� �������� � ������ 
	deq.shift(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � ������";

	// ������ �������� � ������ 
	n = deq.unshift();
	cout << "\n\tDeque                       : " << deq
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ������ ������� : ";

	// ������������ ������� 
	showArrChar(arr1, size);

	// ���������� � ������ �������
	deq.shiftAll(arr1, size);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � ������"
		<< "\n\tDeque                       : " << deq;

	// �������� �������� � ������
	n = deq.front();

	cout << "\n\t������� � ������            : " << n;

	n = 'Z';

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ����� Deque"
		<< "\n\n\t���������� �������� � ����� : " << n;

	// ���������� �������� � �����
	deq.push(n);

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � �����";

	// ������ �������� � �����
	n = deq.pop();

	cout << "\n\tDeque                       : " << deq
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ����� �������  : ";

	// ������������ ������� 
	showArrChar(arr2, size);

	// ���������� � ����� �������
	deq.pushAll(arr2, size);

	n = 'K';

	cout << "\n\tDeque                       : " << deq
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � �����"
		<< "\n\tDeque                       : " << deq;

	// �������� �������� � ������
	n = deq.back();

	cout << "\n\t������� � �����             : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n";

	getKey();

}

// ������������ Deque � Queue (char)
void App::task1DemoCharQue()
{
	cls();

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\t\t������������ ������ ���������� Queue � ����� char\n";

	// ������ ���� 
	Queue<char> que;

	int size = 3;

	// ������ 
	char* arr = new char[3]{ 'a','b','c' };
	char* arr1 = new char[3]{ 'd','f','g' };
	char* arr2 = new char[3]{ 'h','i','m' };

	cout << "\n\t�������� ��� Queue      : " << que
		<< "\n\n\t���������� ���� ��������: ";

	// ������������ ������� 
	showArrChar(arr, size);

	// ���������� ���� ��������
	que.enqueueAll(arr, size);

	char n = 'Q';

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ������ Queue"
		<< "\n\tQueue                       : " << que
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� �������� � ������: " << n;

	// ���������� �������� � ������ 
	que.enqueue(n);

	cout << "\n\tQueue                       : " << que
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � ������";

	// ������ �������� � ������ 
	n = que.dequeue();
	cout << "\n\tQueue                       : " << que
		<< "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ������ ������� : ";

	// ������������ ������� 
	showArrChar(arr1, size);

	// ���������� � ������ �������
	que.enqueueAll(arr1, size);

	cout << "\n\tQueue                       : " << que
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � ������"
		<< "\n\tQueue                       : " << que;

	// �������� �������� � ������
	n = que.front();

	cout << "\n\t������� � ������            : " << n;

	n = 'Z';

	cout << "\n\n������������������������������������������������������������������������������\n\n";

	getKey();

}


#pragma endregion  

#pragma region ������������ Deque � Queue (Goods)

// ��� ������ � �����
bool pregicatorDemoGoods(int position, int positionMin, int positionMax)
{
	return position >= positionMin && position <= positionMax;
}

// ����� Deque (Goods) � �����
void DequeGoodsOut(Deque<Goods>& deque, int positionMin = -1, int positionMax = -1)
{
	int size = deque.counter();

	short cl = getColor();

	if (size == 0)
	{
		cout << "Deque ����\n";
		return;
	}

	List<Goods> list = deque.data_;

	for (size_t i = 0; i < size; i++)
	{
		Goods deq = list.get(i);

		cout << fixed << setprecision(2) << "\n\t\t\t\t\t"
			<< color(pregicatorDemoGoods(i, positionMin, positionMax) ? GREEN_ON_BLACK : cl)
			<< deq.code_ << "; " << deq.name_
			<< "; ���� ��. " << deq.price_
			<< "; ���������� " << deq.amount_;
	}

	setColor(cl);

	cout << "\n";
}

// ������������ Deque � Queue (Goods)
void App::task1DemoGoodsDeq()
{
	cls();

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\t\t������������ ������ ���������� Deque � ����� char\n";

	// ��������� ������ �������
	int posMin;

	// ��������� ������� �������
	int posMax;

	// ������ ���� 
	Deque<Goods> deq;

	// ����� ��������
	int size = 3;

	// Goods(int code, const char* name, double price, int amount)

	// ������ 
	Goods* arr = new Goods[3]{ 
		Goods(483124, "����", 15, 5),
		Goods(987321, "�������", 36, 3),
		Goods(134547, "�����", 13, 4)
	};
	Goods* arr1 = new Goods[3]{ 
		Goods(897683, "�����", 56, 1),
		Goods(987321, "Fanta", 47, 2),
		Goods(546747, "Coca-Cola", 63, 3) 
	};
	Goods* arr2 = new Goods[3]{
		Goods(582346, "Old Spice", 97, 5),
		Goods(324132, "���� ������", 42, 2),
		Goods(875364, "��������", 143, 2)
	};

	cout << "\n\t�������� ��� Deque      : ";

	DequeGoodsOut(deq);

	cout << "\n\n\t���������� ���� ��������: ";

	// ������������ ������� 
	DequeGoodsOut(deq);

	// ���������� ���� ��������
	deq.pushAll(arr, size);

	Goods n = Goods(734936, "�����", 26, 2);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ������ Deque"
		<< "\n\tDeque                       : ";

	DequeGoodsOut(deq, -1, -1);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� �������� � ������: " << n;

	// ���������� �������� � ������ 
	deq.shift(n);

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, 0, 0);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � ������";

	// ������ �������� � ������ 
	n = deq.unshift();

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, -1, -1);

	cout << "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ������ ������� : ";

	// ������������ ������� 
	//showArrChar(arr1, size);

	// ���������� � ������ �������
	deq.shiftAll(arr1, size);

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, 0, 2);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � ������"
		<< "\n\tDeque                       : ";

	DequeGoodsOut(deq, 0, 0);

	// �������� �������� � ������
	n = deq.front();

	cout << "\n\t������� � ������            : " << n;

	n = Goods(194638, "��������", 53, 4);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ����� Deque"
		<< "\n\n\t���������� �������� � ����� : " << n;

	// ���������� �������� � �����
	deq.push(n);

	cout << "\n\tDeque                       : ";

	DequeGoodsOut(deq, deq.counter() - 1, deq.counter() - 1);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � �����";

	// ������ �������� � �����
	n = deq.pop();

	cout << "\n\tDeque                       : ";
	DequeGoodsOut(deq);
	cout << "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ����� �������  : ";

	// ������������ ������� 
	//showArrChar(arr2, size);

	posMin = deq.counter() - 1;

	// ���������� � ����� �������
	deq.pushAll(arr2, size);

	n = Goods(546812, "����", 253, 1);

	cout << "\n\tDeque                       : ";
	DequeGoodsOut(deq, posMin, posMin + size);
	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � �����"
		<< "\n\tDeque                       : ";
	DequeGoodsOut(deq, deq.counter() - 1, deq.counter() - 1);

	// �������� �������� � ������
	n = deq.back();

	cout << "\n\t������� � �����             : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n";

	getKey();

}

// ����� Deque (Goods) � �����
void QueueGoodsOut(Queue<Goods>& queue, int positionMin = -1, int positionMax = -1)
{
	int size = queue.getCounter();

	short cl = getColor();

	if (size == 0)
	{
		cout << "Deque ����\n";
		return;
	}

	List<Goods> list = queue.data_;

	for (size_t i = 0; i < size; i++)
	{

		Goods goods = list.get(i);

		cout << fixed << setprecision(2) << "\n\t\t\t\t\t"
			<< color(pregicatorDemoGoods(i, positionMin, positionMax) ? GREEN_ON_BLACK : cl)
			<< goods.code_ << "; " << goods.name_
			<< "; ���� ��. " << goods.price_
			<< "; ���������� " << goods.amount_;
	}

	setColor(cl);

	cout << "\n";
}

// ������������ Deque � Queue (Goods)
void App::task1DemoGoodsQue()
{
	cls();

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\t\t������������ ������ ���������� Queue � ����� char\n";

	// ��������� ������ �������
	int posMin;

	// ��������� ������� �������
	int posMax;

	// ������ ���� 
	Queue<Goods> que;

	// ����� ��������
	int size = 3;

	// Goods(int code, const char* name, double price, int amount)

	// ������ 
	Goods* arr = new Goods[3]{
		Goods(483124, "����", 15, 5),
		Goods(987321, "�������", 36, 3),
		Goods(134547, "�����", 13, 4)
	};
	Goods* arr1 = new Goods[3]{
		Goods(897683, "�����", 56, 1),
		Goods(987321, "Fanta", 47, 2),
		Goods(546747, "Coca-Cola", 63, 3)
	};
	Goods* arr2 = new Goods[3]{
		Goods(582346, "Old Spice", 97, 5),
		Goods(324132, "���� ������", 42, 2),
		Goods(875364, "��������", 143, 2)
	};

	cout << "\n\t�������� ��� Queue      : ";

	QueueGoodsOut(que);

	cout << "\n\n\t���������� ���� ��������: ";

	// ������������ ������� 
	QueueGoodsOut(que);

	// ���������� ���� ��������
	que.enqueueAll(arr, size);

	Goods n = Goods(734936, "�����", 26, 2);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t����������� ������� ��� ������ Queue"
		<< "\n\tDeque                       : ";

	QueueGoodsOut(que, -1, -1);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� �������� � ������: " << n;

	// ���������� �������� � ������ 
	que.enqueue(n);

	cout << "\n\tDeque                       : ";

	QueueGoodsOut(que, 0, 0);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t������ �������� � ������";

	// ������ �������� � ������ 
	n = que.dequeue();

	cout << "\n\tDeque                       : ";

	QueueGoodsOut(que, -1, -1);

	cout << "\n\t������ �������              : " << n
		<< "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t���������� � ������ ������� : ";

	// ������������ ������� 
	//showArrChar(arr1, size);

	// ���������� � ������ �������
	que.enqueueAll(arr1, size);

	cout << "\n\tQueue                       : ";

	QueueGoodsOut(que, 0, 2);

	cout << "\n\n������������������������������������������������������������������������������\n\n"
		<< "\n\n\t�������� �������� � ������"
		<< "\n\tQueue                       : ";

	QueueGoodsOut(que, 0, 0);

	// �������� �������� � ������
	n = que.front();

	cout << "\n\t������� � ������            : " << n;

	n = Goods(194638, "��������", 53, 4);

	cout << "\n\n������������������������������������������������������������������������������\n\n";

	getKey();

}


#pragma endregion

#pragma endregion

#pragma region  ������ 2. ��������

/*
	������ 2. ��� ������ ���������� ������ Stack(� ������������ ��
		������� ������ ������� �� 12 ���������) ��� ������������� �����
		��������, ������ ������ ������������� �������� ����������� �
		��������, � ������� � ������������ �����.

		���������� ����� ��������� �� �������� ������ � ������ ����������� ������,
		���������� ����� ���������� � �������� ������ � ������ ������.�� ���������
		����� �������� ���������� � ������������ �������. ��� ����� ������ � ������
		����������� ������ ������������ �� ���������� ������, �� ������, �������
		��������� �������.��� ������ �������� ����������� ������, ����� ������ �
		���������� ������ ������������ �� �����������.
		������������ ����� Parking ��� ������� ������ ��������.� ������ Parking
		���������� ������ ���������� ���������� �� ��������, ������� �������������
		���������� � ��������.
*/

// ������ 2. ��������
void App::task2()
{
	init(L"�������� ������� �� 23.06.2021 | ������ 2. ��������");

	// ��� ������ � ������ ���������� C++
	ostringstream oss;

	// TODO: ���� ����������
	App app;

	// ��������� ��� swith ����
	enum Commands {
		// ������� ��������
		CMD_OUT_PARK,
		// �������� ����������
		CMD_ADD_CAR,
		// ������� ��������� ����������
		CMD_POP_CAR,
		// ������� ����� ���������� (��������)
		CMD_POP_ANY_CAR
	};

	// ���������� ������� ����
	const int N_MENU = 5;

	MenuItem items[N_MENU] = {
		MenuItem("������� ��������", CMD_OUT_PARK),
		MenuItem("�������� ����������", CMD_ADD_CAR),
		MenuItem("������� ��������� ����������", CMD_POP_CAR),
		MenuItem("������� ����� ���������� (��������)", CMD_POP_ANY_CAR),

		// ����� �� ���������
		MenuItem("�����",  Menu::CMD_QUIT)
	};

	// ���������� ������ 
	const int N_PALETTE = 5;

	// ������ ������
	short palette[N_PALETTE] = { WHITE_ON_BLACK, LTCYAN_ON_BLACK, BLACK_ON_LTCYAN, GRAY_ON_BLACK };

	// ������ ����
	Menu mainMenu("������� ���� ����������", items, N_MENU, palette, COORD{ 5, 5 });

	while (true)
	{
		try {
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			int cmd = mainMenu.Navigate();
			cout << color(palette[Menu::PAL_CONSOLE]) << cls;
			if (cmd == Menu::CMD_QUIT) return;

			switch (cmd)
			{
				// ������� ��������
			case CMD_OUT_PARK:
				app.showParking();
				break;
				// �������� ����������
			case CMD_ADD_CAR:
				app.addParking();
				break;
				// ������� ��������� ����������
			case CMD_POP_CAR:
				app.popParking();
				break;
				// ������� ����� ���������� (��������)
			case CMD_POP_ANY_CAR:
				app.popAnyParking();
				break;
			}
		}
		catch (exception& ex) {

			oss.str("");  // ������� ������ - ������ ������
			oss << "\n\t" << ex.what() << "\n";

			// ����� ������ � ���������� �� ������ � �����
			cputs(oss.str().c_str(), errColor);

			getKey();

		} // try-catch
	}
}

// ����� ��������
void App::showParking()
{
	cls();

	cout << "\n\t\t\t\t����� ��������\n";

	// ����� �������� � ����� � ���� �����
	park_.showColor();

	// ����� �������� � ���� �������
	cout << park_;

	getKey();
}

// ���������� ����������
void App::addParking()
{
	cls();

	cout << "\n\t\t���������� ����������\n";

	// ����� �������� � ����� � ���� �����
	park_.showColor();

	// ����� �������� � ���� �������
	cout << park_;

	Sleep(500);

	// ����� ����� ����������
	park_.push(genCar());

	cls();

	cout << "\n\t\t���������� ����������\n";

	// ����� �������� � ����� � ���� �����
	park_.showColor();

	// ����� �������� � ���� �������
	cout << park_;

	getKey();
}

// �������� ���������� ����������
void App::popParking()
{
	cls();

	cout << "\n\t\t�������� ���������� ����������\n";

	// ����� �������� � ����� � ���� �����
	park_.showColor();

	// ����� �������� � ���� �������
	cout << park_;

	Sleep(500);

	// ����� ����� ����������
	Car save = park_.pop();

	cls();

	cout << "\n\t\t�������� ���������� ����������\n";

	// ����� �������� � ����� � ���� �����
	park_.showColor();

	short cl = getColor();

	// ����� �������� � ���� �������
	cout << park_ << color(GREEN_ON_BLACK)
		<< "\t�������� ������: \n" << save << "\n\n\n" << color(cl);

	getKey();

}

// �������� ������ ���������� �� �������
void App::popAnyParking()
{
	cls();

	cout << "\n\t\t�������� ������ ���������� �� �������\n";

	// ����� �������� � ����� � ���� �����
	park_.showColor();

	// ����� �������� � ���� �������
	cout << park_;

	int counter = park_.getCounterPark();

	int n = getRand(0, counter != 0 ? counter : 1);

	short cl = getColor();

	cout << color(GREEN_ON_BLACK) << "\n\t\t������: " << n << "\n" << color(cl);

	Sleep(3000);

	Car save = park_.popAny(n);

	cls();

	cout << "\n\t\t�������� ���������� ����������\n";

	// ����� �������� � ����� � ���� �����
	park_.showColor();

	// ����� �������� � ���� �������
	cout << park_;

	cout << color(GREEN_ON_BLACK) << "\n\t\t������: " << n << "\n"
		<< save << "\n" << color(cl);

	getKey();

}

// ��������� ����������
Car App::genCar()
{
	char number[8] = "��1234\0";

	Car car;

	for (int i = 0; i < 7; i++)
	{
		if (number[i] >= '�' && number[i] <= '�')
			number[i] = getRand('�', '�');

		else if (number[i] >= '0' && number[i] <= '9')
			number[i] = getRand('0', '9');
	}

	car.setNumber(number);

	char** brand = new char* [5];

	for (int i = 0; i < 5; i++)
	{
		brand[i] = new char[10];
	}

	strcpy(brand[0], "BMW");
	strcpy(brand[1], "MERCEDES");
	strcpy(brand[2], "OPEL");
	strcpy(brand[3], "AUDI");
	strcpy(brand[4], "LADA");

	car.setBrand(brand[getRand(0, 4)]);

	struct Color
	{
		// �������� ����� 
		char name[15];

		// ��� �����
		short color;
	};

	const int size = 8;

	// ������ ������ �� ����������
	Color colors[size];

	// ������
	strcpy(colors[0].name, "Black");
	colors[0].color = WHITE_ON_BLACK;

	// �����
	strcpy(colors[1].name, "Blue");
	colors[1].color = BLACK_ON_BLUE;

	// ������
	strcpy(colors[2].name, "Green");
	colors[2].color = BLACK_ON_GREEN;

	// �������
	strcpy(colors[3].name, "Cyan");
	colors[3].color = BLACK_ON_CYAN;

	// �������
	strcpy(colors[4].name, "Red");
	colors[4].color = BLACK_ON_RED;

	// �������
	strcpy(colors[5].name, "Magenta");
	colors[5].color = BLACK_ON_MAGENTA;

	// �����
	strcpy(colors[6].name, "Yellow");
	colors[6].color = BLACK_ON_YELLOW;

	// ����� 
	strcpy(colors[7].name, "Gray");
	colors[7].color = BLACK_ON_GRAY;

	car.setColor(colors[getRand(0, 7)].name);

	return car;
}
#pragma endregion 

#pragma endregion
