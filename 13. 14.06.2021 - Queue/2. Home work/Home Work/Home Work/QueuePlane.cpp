#include "QueuePlane.h"

#pragma region ������������ � ���������� 

// ���������������� ����������� 
QueuePlane::QueuePlane(int size) : front_(), back_(), counter_()
{
	// ��������� ����� ������� 
	setSize(size);

	// ��������� ������ ��� ������ 
	data_ = new Plane[size_];
}

// ���������� �����������
QueuePlane::QueuePlane(const QueuePlane& queuePlane)
{
	// ���������� �������� �����
	front_ = queuePlane.front_;
	back_ = queuePlane.back_;
	size_ = queuePlane.size_;
	counter_ = queuePlane.counter_;

	// ��������� ������ 
	data_ = new Plane[size_];

	// ����������� ���������
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = queuePlane.data_[i];
	}
}

#pragma endregion

#pragma region ������� � �������

// ������ size_
void QueuePlane::setSize(int size)
{
	// ���� ����� ������ ��� ����� ����
	if (size <= 0)
		throw exception("QueuePlane: ������ ������� ������ ���� ������ ����!");

	// ���������� ��������
	size_ = size;
}

// ������ size_
int QueuePlane::getSize() const { return size_; }

// ������ counter_
int QueuePlane::getCounter() const { return counter_; }

#pragma endregion

#pragma region ������

// ���������� �������� ������������ 
QueuePlane& QueuePlane::operator=(const QueuePlane& queuePlane)
{
	// ����� ������ QueuePlane
	QueuePlane* newQueue = new QueuePlane(queuePlane);

	// ����������� ��������
	front_ = queuePlane.front_;
	back_ = queuePlane.back_;
	size_ = queuePlane.size_;
	counter_ = queuePlane.counter_;

	// ��������� ������
	data_ = new Plane[size_];

	// ����������� ��������
	memcpy(data_, queuePlane.data_, size_);

	return *newQueue;
}

// ���������� � ������� �������� 
void QueuePlane::enqueue(Plane plane) 
{
	// ���� ������� ����������� 
	if (isFull())
		throw exception("QueuePlane: ������� �����������!");

	// ���������� ��������
	data_[back_] = plane;

	// ���� ������ ����� ������� ����� �� ������� �������
	back_ + 1 == size_ ? back_ = 0 : back_++;

	// ���������� counter_
	counter_++;
}

// ���������� � ������� ������� 
void QueuePlane::enqueueAll(Plane* planeArr, int size)
{
	for (size_t i = 0; i < size && !isFull(); i++)
	{
		enqueue(planeArr[i]);
	}
}

// �������� ������ �������
Plane QueuePlane::front() const
{
	// ���� ������� ����������
	if (isEmpty())
		throw exception("QueuePlane: ������� �����!");

	return data_[front_];
}

// �������� ����� �������
/*Plane QueuePlane::back() const
{
	// ���� ������� ����� 
	if (isEmpty())
		throw exception("QueuePlane: ������� �����!");

	return data_[back_];
}
*/
// ������ �������� � ������ �������
Plane QueuePlane::dequeue()
{
	// ���� ������� ����� 
	if (isEmpty())
		throw exception("QueuePlane: ������� �����!");

	// ������ ���������� ��������
	int index = front_;

	// ���� ������ ������ ����� �������� ������ �� ������� �������
	front_ + 1 == size_ ? front_ = 0 : front_++;

	// ���������� counter_
	counter_--;

	return data_[index];
}

// �������� �������
void QueuePlane::clear() { front_ = back_ = 0; }

// ����������� �������
bool QueuePlane::isEmpty() const { return counter_ == 0; }

// ������������ �������
bool QueuePlane::isFull() const { return counter_ == size_; }

#pragma endregion

#pragma region ������������� �������

// ���������� ������ 
ostream& operator<<(ostream& os, QueuePlane& queuePlane)
{
	os << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n"
		<< "|     ������    |  ��������. | ���������� | ����. �������� |     ���������     |  ��������� ����� |  ���������. ����� |\n"
		<< "|               |    ����    |            |     ��/�       |      �������     |      �������     |      �������     |\n"
		<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";

	// ���� � �������� ��� ��������
	if (queuePlane.counter_ == 0)
	{
		os << "|                                                    ��� ����˨���                                                     |\n"
			// ������ ������ 
			<< "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}

	// ����� ��������
	for (int i = 0, k = queuePlane.front_; i < queuePlane.counter_; i++, k++)
	{
		// ���� k ��������� �� ������� ������� 
		if (k == queuePlane.size_) k = 0;

		os << queuePlane.data_[k];

		// ������ ������ 
		os << "+���������������+������������+������������+����������������+�������������������+�������������������+�������������������+\n";
	}

	return os;
}

#pragma endregion

