#include "QueueDbl.h"

// ���� ������
/*
	// ������ ������
	int front_;

	// ������ �����
	int back_;

	// ��������� �� ������ double
	double* data_;

	// ������� ��������� � �������
	int counter_;

	// ����� �������
	int size_;

*/

#pragma region ������������ � ����������

// ����������� ����������������
QueueDbl::QueueDbl(int size): front_(), back_(), counter_()
{
	// ���������� size 
	setSize(size);

	// ��������� ������ ��� ������ double
	data_ = new double[size_];
}

// ���������� ����������� 
QueueDbl::QueueDbl(const QueueDbl& queueDbl): front_(queueDbl.front_), back_(queueDbl.back_), 
											  counter_(queueDbl.counter_), size_(queueDbl.size_),
											  data_(new double[size_])
{
	// ����������� ������� data_
	memcpy(data_, queueDbl.data_, size_);
}

// ���������� 
QueueDbl::~QueueDbl()
{
	// �������� ������ �� ������� data_
	delete[] data_;
}

#pragma endregion

#pragma region ������� � �������

// ������ size_
void QueueDbl::setSize(int size)
{
	// ���� ����� ������ ��� ��������� ����
	if (size <= 0)
		throw exception("QueueDbl: �������� ����� ������ ���� ������ ����!");

	// ������������ ��������
	size_ = size;
}

#pragma endregion

#pragma region ������ 

// ���������� �������� ���������� 
QueueDbl& QueueDbl::operator=(const QueueDbl& queueDbl)
{
	// ����� ������� newQueue
	QueueDbl* newQueue = new QueueDbl(queueDbl);

	// ����������� �����
	front_ = queueDbl.front_;
	back_ = queueDbl.back_;
	size_ = queueDbl.size_;
	counter_ = queueDbl.counter_;

	// �������� ������ �� ������� data_
	delete[] data_;

	// ��������� ������ ��� ������� data_
	data_ = new double[size_];

	// ����������� ��������� � ������ data_
	memcpy(data_, queueDbl.data_, size_);

	return *newQueue;
}

// ���������� �������� � �������
void QueueDbl::enqueue(double value)
{
	// ���� ������� ����������� 
	if (isFull())
		throw exception("Queue: ������� �����������!");

	// ������
	data_[back_] = value;

	// �������� �������, ���� back_ ������� �� ����� �������
	back_ + 1 == size_ ? back_ = 0 : back_++;

	// ���������� counter_
	counter_++;
}

// ���������� ������� � �������
void QueueDbl::enqueueAll(double* arr, int size)
{
	// ����������� ������� � �������
	for (size_t i = 0; i < size; i++)
	{
		// ���������� �������� �������� ������� � �������
		enqueue(arr[i]);
	}
}

// �������� �������� ������� �������
double QueueDbl::front() const
{ 
	// ���� ������� ����������
	if (isEmpty())
		throw exception("Queue: ������� �����");

	return data_[front_]; 
}

// �������� �������� ����� �������
/*double QueueDbl::back() const
{
	// ���� ������� ����������
	if (isEmpty())
		throw exception("Queue: ������� �����");

	// ���� back_ ����� ����
	return back_ == 0 ? data_[size_ - 1] : data_[back_ - 1];
}*/

// ������ �������� �� �������
double QueueDbl::dequeue()
{
	// ����� �������� ��������
	double n = data_[front_++];

	// ���� ������ ������� ������ ��� ����� ����� ������� 
	if (front_ >= size_)
		front_ = 0;

	counter_--;

	return n;
}

// �������� �������
void QueueDbl::clear()
{
	// ��������� ��������
	back_ = front_ = 0;
}

// ����������� �������
bool QueueDbl::isEmpty() const { return counter_ == 0; };

// ������������ �������
bool QueueDbl::isFull() const { return counter_ == size_; };

#pragma endregion

#pragma region ������������� �������

// ���������� �������� ������ 
ostream& operator<<(ostream& os, const QueueDbl& queueDbl)
{
	os << fixed;
	os.precision(2);

	// ����� �������������� ��������
	showSize(os, queueDbl);

	showCounter(os, queueDbl);

	// ���� ������� ����� 
	if (queueDbl.counter_ == 0)
	{
		os  << "\t+��������������������������+\n"
			<< "\t|                          |\n"
			<< "\t|       ������� �����      |\n"
			<< "\t|                          |\n"
			<< "\t+��������������������������+\n";
	}

	else
	{
		showLine(os, queueDbl);

		showIndex(os, queueDbl);

		showLine(os, queueDbl);

		showElem(os, queueDbl);

		showLine(os, queueDbl);

	}

	return os;
		//<< "| ������ �������� |";

	// ����� ������������ ��������
	/*// ����� �������
	os  << "\t+�����������������+�����������������+\n"
		<< "\t| ������ �������� |    ����������   |\n"
		<< "\t+�����������������+�����������������+\n";
		
	// ���������� ��������� � �������
	int counter = queueDbl.counter_;

	// ���� ���������� ��������� ������ ����
	if (counter > 0)
	{
		// ����� ��������
		for (size_t i = 0, k = queueDbl.front_; i < queueDbl.counter_; i++, k++)
		{
			if (k == queueDbl.size_) k = 0;
			os << "\t|  " << setw(14) << i << " | " << setw(15) << queueDbl.data_[k] << " |\n"
				<< "\t+�����������������+�����������������+\n";
		}

		os  << "\t|" << " ����� ���������: " << setw(16) << queueDbl.counter_ << " |\n"
			<< "\t+�����������������������������������+\n"
			<< "\t|" << " �������� ���������: " << setw(13) << queueDbl.size_<< " |\n"
			<< "\t+�����������������������������������+\n";

	}
	else
	{
		os	<< "\t|           ������� �����           |\n"
			<< "\t+�����������������+�����������������+\n";
	}
	return os;*/
}

// ����� �������������� �����
ostream& showLine(ostream& os, const QueueDbl& queueDbl)
{
	int counter = queueDbl.getCounter();

	// ����� �������������� ��������
	os << "\t+�����������������+";
	for (size_t i = 0; i < counter; i++)
	{
		os << "��������+";
	}

	os << "\n";

	return os;
}

// ����� ������� ���������
ostream& showIndex(ostream& os, const QueueDbl& queueDbl)
{
	int counter = queueDbl.counter_;

	int size = queueDbl.size_;

	os << "\t|      ������     |";

	for (size_t i = 0, k = queueDbl.front_; i < counter; i++, k++)
	{
		if (k == size) k = 0;
		os << "   " << setw(5) << i << "|";
	}
	
	os << "\n";

	return os;
}

// ����� ���������
ostream& showElem(ostream& os, const QueueDbl& queueDbl)
{
	int counter = queueDbl.getCounter();

	int size = queueDbl.getSize();

	os << "\t|    ����������   |";

	for (size_t i = 0, k = queueDbl.front_; i < counter; i++, k++)
	{
		if (k == size) k = 0;
		os << " " << setw(7) << queueDbl.data_[k] << "|";
	}

	os << "\n";

	return os;
}

// ����� ������������� �������
ostream& showSize(ostream& os, const QueueDbl& queueDbl)
{
	os << "\t+��������������������������+\n"
		<< "\t|   �������� ���������: " << setw(2) << queueDbl.size_ << " |\n";
	return os;
}

// ����� ���������� ���������
ostream& showCounter(ostream& os, const QueueDbl& queueDbl)
{
	os  << "\t+��������������������������+\n"
		<< "\t| ���������� ���������: " << setw(2) << queueDbl.counter_ << " |\n";
		
	return os;
}

#pragma endregion